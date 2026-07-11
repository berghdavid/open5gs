/*
 * Copyright (C) 2025 by Juraj Elias <juraj.elias@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "location-determination.h"
#include "namf-path.h"
#include "nrppa-types.h"
#include "cell-database.h"
#include "nlmf-handler.h"
#include "sbi-path.h"
#include <math.h>
#include "openapi/model/ncgi.h"
#include "E-CIDMeasurementInitiationResponse.h"
#include "ProtocolIE-Container.h"
#include "ProtocolIE-Single-Container.h"
#include "ProtocolIE-Field.h"
#include "NG-RAN-CGI.h"
#include "NG-RANCell.h"
#include "MeasuredResults.h"
#include "MeasuredResultsValue.h"
#include "ResultRSRP-EUTRA.h"
#include "ResultRSRP-EUTRA-Item.h"
#include "CGI-EUTRA.h"
#include "ProtocolExtensionContainer.h"
#include "ProtocolExtensionField.h"
#include "ResultSS-RSRP-Item.h"
#include "nrppa-parse.h"

static void set_plmn_id(ogs_plmn_id_t *ogs_plmn, PLMN_Identity_t *plmn_id)
{
    log_assert(ogs_plmn != NULL);
    log_assert(plmn_id != NULL);
    log_assert(5 <= plmn_id->size);
    log_assert(plmn_id->size <= 6);

    ogs_plmn->mcc1 = plmn_id->buf[0];
    ogs_plmn->mcc2 = plmn_id->buf[1];
    ogs_plmn->mcc3 = plmn_id->buf[2];
    if (plmn_id->size == 6) {
        ogs_plmn->mnc1 = plmn_id->buf[3];
        ogs_plmn->mnc2 = plmn_id->buf[4];
        ogs_plmn->mnc3 = plmn_id->buf[5];
    } else {
        ogs_plmn->mnc1 = 0xf;
        ogs_plmn->mnc2 = plmn_id->buf[3];
        ogs_plmn->mnc3 = plmn_id->buf[4];
    }
}

int lmf_location_determine(lmf_location_request_t *location_request)
{
    int rv;

    log_assert(location_request);

    log_assert(location_request->positioning_method);

    /* Route based on positioning method */
    if (strcmp(location_request->positioning_method, "CELLID") == 0) {
        /* Check if we need to query AMF for Cell ID */
        OpenAPI_input_data_t *input_data = location_request->input_message->InputData;
        if (!input_data || (!input_data->ncgi && !input_data->ecgi)) {
            /* No cell info provided - request from AMF via async API */
            log_info("[%s] Starting location determination (CELLID) - requesting Cell ID from AMF",
                    location_request->supi ? location_request->supi : "Unknown");
            
            /* Send async request to AMF for location info */
            rv = lmf_amf_send_location_info_request(location_request);
            if (rv != OGS_OK) {
                log_error("[%s] lmf_amf_send_location_info_request() failed",
                        location_request->supi);
                
                /* Send error response to client */
                ogs_sbi_stream_t *stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
                if (stream) {
                    ogs_sbi_server_send_error(stream,
                            OGS_SBI_HTTP_STATUS_SERVICE_UNAVAILABLE,
                            NULL, "AMF communication failed",
                            "Unable to request Cell ID from AMF", NULL);
                }
                
                lmf_location_request_remove(location_request);
                return rv;
            }
            
            /* Response will be handled asynchronously in lmf_namf_handler_location_info_response */
            return OGS_OK;
        } else {
            /* Cell info provided - proceed directly */
            log_info("[%s] Starting location determination (CELLID) - using provided cell info",
                    location_request->supi ? location_request->supi : "Unknown");
            
            rv = lmf_location_determine_cellid(location_request);
            if (rv != OGS_OK) {
                log_error("[%s] lmf_location_determine_cellid() failed", location_request->supi);
                /* Error response already sent by lmf_location_determine_cellid() */
                return rv;
            }
            
            return OGS_OK;
        }
        
    } else if (strcmp(location_request->positioning_method, "ECID") == 0) {
        /* For ECID, we need to request NRPPa measurement from AMF */
        log_info("[%s] Starting location determination (ECID)",
                location_request->supi ? location_request->supi : "Unknown");

        /* Send NRPPa measurement request to AMF with all supported measurements */
        rv = lmf_amf_send_nrppa_measurement_request(location_request);
        if (rv != OGS_OK) {
            log_error("[%s] lmf_amf_send_nrppa_measurement_request() failed",
                    location_request->supi);
            
            /* Send error response to client */
            ogs_sbi_stream_t *stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
            if (stream) {
                ogs_sbi_server_send_error(stream,
                        OGS_SBI_HTTP_STATUS_SERVICE_UNAVAILABLE,
                        NULL, "AMF communication failed",
                        "Unable to send NRPPa measurement request to AMF", NULL);
            } else {
                log_error("[%s] Stream ID=%d not found for error response",
                        location_request->supi, location_request->stream_id);
            }
            
            lmf_location_request_remove(location_request);
            return rv;
        }

        return OGS_OK;
    } else {
        log_error("[%s] Unsupported positioning method: %s",
                location_request->supi,
                location_request->positioning_method);
        
        /* Send error response to client */
        ogs_sbi_stream_t *stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
        if (stream) {
            ogs_sbi_server_send_error(stream,
                    OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                    NULL, "Unsupported positioning method",
                    location_request->positioning_method, NULL);
        } else {
            log_error("[%s] Stream ID=%d not found for error response",
                    location_request->supi, location_request->stream_id);
        }
        
        lmf_location_request_remove(location_request);
        return OGS_ERROR;
    }
}

/*
 * Convert RSRP (0.1 dBm units) to linear power (mW) for weighting
 */
static double rsrp_to_linear_power(int16_t rsrp_dbm_01)
{
    double rsrp_dbm = rsrp_dbm_01 / 10.0;
    /* Convert dBm to mW: P_mW = 10^(P_dBm / 10) */
    return pow(10.0, rsrp_dbm / 10.0);
}

/*
 * Calculate distance from Timing Advance
 * TA is in 16 Ts units, where Ts = 1/(48000 * 2048) seconds
 * Distance = c * TA * 16 * Ts / 2 (one-way)
 */
static double ta_to_distance_meters(uint16_t ta)
{
    const double c = 299792458.0;  /* Speed of light in m/s */
    const double ts = 1.0 / (48000.0 * 2048.0);  /* Sampling period */
    const double ta_seconds = ta * 16.0 * ts;
    return (c * ta_seconds) / 2.0;  /* One-way distance */
}

int lmf_location_determine_ecid(
        lmf_location_request_t *location_request,
        E_CIDMeasurementInitiationResponse_t *ecid_response_ie)
{
    int rv;
    ogs_sbi_stream_t *stream = NULL;
    ogs_sbi_message_t message;
    ogs_sbi_response_t *response = NULL;
    lmf_cell_info_t *serving_cell_info = NULL;
    lmf_nrppa_ecid_cell_measurement_t serving_cell;
    ogs_nr_cgi_t serving_ncgi;
    double final_lat = 0.0, final_lon = 0.0, final_alt = 0.0;
    double total_weight = 0.0;
    double uncertainty_radius = 0.0;
    int i;
    OpenAPI_location_data_t *location_data = NULL;
    OpenAPI_geographic_area_t *geographic_area = NULL;
    OpenAPI_geographical_coordinates_t *coordinates = NULL;
    OpenAPI_supported_gad_shapes_t *shape = NULL;
    OpenAPI_ncgi_t *ncgi_openapi = NULL;
    OpenAPI_plmn_id_t *plmn_id_openapi = NULL;

    log_assert(location_request);
    log_assert(ecid_response_ie);

    log_info("[%s] ECID location determination from measurements",
            location_request->supi ? location_request->supi : "Unknown");

    /* Read provided IEs from E-CID Response */
    E_CID_MeasurementResult_t *ecid_measurement_result_ie = NULL;
    long *measurement_id = NULL;

    ProtocolIE_Container_97P1_t *ecid_ies = (ProtocolIE_Container_97P1_t*)ecid_response_ie->protocolIEs;
    E_CIDMeasurementInitiationResponse_IEs_t *ie;
    for (i = 0; i < ecid_ies->list.count; i++) {
        ie = ecid_ies->list.array[i];
        switch (ie->value.present) {
            case E_CIDMeasurementInitiationResponse_IEs__value_PR_NOTHING:
                log_warn("[%s] Undefined E-CID measurement IE",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            case E_CIDMeasurementInitiationResponse_IEs__value_PR_UE_Measurement_ID:
                measurement_id = ie->value.choice.UE_Measurement_ID;
                break;
            case E_CIDMeasurementInitiationResponse_IEs__value_PR_UE_Measurement_ID_1:
                log_debug("[%s] E-CID measurement: UE Measurement ID-1 unused",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            case E_CIDMeasurementInitiationResponse_IEs__value_PR_E_CID_MeasurementResult:
                ecid_measurement_result_ie = ie->value.choice.E_CID_MeasurementResult;
                break;
            case E_CIDMeasurementInitiationResponse_IEs__value_PR_CriticalityDiagnostics:
                log_debug("[%s] E-CID measurement: Criticality Diagnostics unused",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            case E_CIDMeasurementInitiationResponse_IEs__value_PR_Cell_Portion_ID:
                log_debug("[%s] E-CID measurement: Cell Portion ID unused",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            case E_CIDMeasurementInitiationResponse_IEs__value_PR_OtherRATMeasurementResult:
                log_debug("[%s] E-CID measurement: Other RAT Measurement Result unused",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            case E_CIDMeasurementInitiationResponse_IEs__value_PR_WLANMeasurementResult:
                log_debug("[%s] E-CID measurement: WLAN Measurement Result unused",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            default:
                log_error("[%s] Unrecognized E-CID measurement type [%d]",
                    location_request->supi ? location_request->supi : "Unknown", ie->value.present);
                break;
        }
    }

    if (!ecid_measurement_result_ie) {
        log_error("[%s] No E-CID Measurement Result IE provided, cannot position",
                    location_request->supi ? location_request->supi : "Unknown");
        return OGS_ERROR;
    }

    if (!measurement_id) {
        log_error("[%s] No E-CID Measurement ID provided",
                    location_request->supi ? location_request->supi : "Unknown");
        return OGS_ERROR;
    }

    /* Read E-CID measurements */
    ProtocolIE_Single_Container_100P11_t *ext = NULL;
    
    MeasuredResults_t *results = ecid_measurement_result_ie->measuredResults;
    MeasuredResultsValue_t *measured_result_val = NULL;
    for (i = 0; i < results->list.count; i++) {
        measured_result_val = results->list.array[i];
        switch (measured_result_val->present) {
            case MeasuredResultsValue_PR_NOTHING:
                log_warn("[%s] Undefined E-CID measurement IE",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            case MeasuredResultsValue_PR_valueAngleOfArrival_EUTRA:
                serving_cell.angle_of_arrival = measured_result_val->choice.valueAngleOfArrival_EUTRA;
                break;
            case MeasuredResultsValue_PR_valueTimingAdvanceType1_EUTRA:
                serving_cell.timing_advance = measured_result_val->choice.valueTimingAdvanceType1_EUTRA;
                break;
            case MeasuredResultsValue_PR_valueTimingAdvanceType2_EUTRA:
                log_warn("[%s] Unsupported E-CID measurement TA-2 (EUTRA)",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            case MeasuredResultsValue_PR_resultRSRP_EUTRA:
                log_warn("[%s] Unsupported E-CID measurement RSRP (EUTRA)",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            case MeasuredResultsValue_PR_resultRSRQ_EUTRA:
                log_warn("[%s] Unsupported E-CID measurement RSRQ (EUTRA)",
                    location_request->supi ? location_request->supi : "Unknown");
                break;
            case MeasuredResultsValue_PR_choice_Extension:
                ext = (ProtocolIE_Single_Container_100P11_t*)measured_result_val->choice.choice_Extension;
                break;
            default:
                log_error("[%s] Unrecognized E-CID measurement result value [%d]",
                    location_request->supi ? location_request->supi : "Unknown",
                    measured_result_val->present);
                break;
        }
    }

    if (!ext) {
        log_error("[%s] No external IEs provided",
            location_request->supi ? location_request->supi : "Unknown");
        return OGS_ERROR;
    }

    ResultSS_RSRP_t *ss_rsrp = NULL;
    switch (ext->value.present) {
        case MeasuredResultsValue_ExtensionIE__value_PR_NOTHING:
            log_error("[%s] E-CID measured results extension value: Undefined [0]",
                    location_request->supi ? location_request->supi : "Unknown");
            break;
        case MeasuredResultsValue_ExtensionIE__value_PR_ResultSS_RSRP:
            ss_rsrp = ext->value.choice.ResultSS_RSRP;
            break;
        case MeasuredResultsValue_ExtensionIE__value_PR_ResultSS_RSRQ:
            log_warn("[%s] Unsupported E-CID measured results extension value SS-RSRQ",
                    location_request->supi ? location_request->supi : "Unknown");
            break;
        case MeasuredResultsValue_ExtensionIE__value_PR_ResultCSI_RSRP:
            log_warn("[%s] Unsupported E-CID measured results extension value CSI-RSRP",
                    location_request->supi ? location_request->supi : "Unknown");
            break;
        case MeasuredResultsValue_ExtensionIE__value_PR_ResultCSI_RSRQ:
            log_warn("[%s] Unsupported E-CID measured results extension value CSI-RSRQ",
                    location_request->supi ? location_request->supi : "Unknown");
            break;
        case MeasuredResultsValue_ExtensionIE__value_PR_UL_AoA:
            log_warn("[%s] Unsupported E-CID measured results extension value UL-AoA",
                    location_request->supi ? location_request->supi : "Unknown");
            break;
        case MeasuredResultsValue_ExtensionIE__value_PR_NR_TADV:
            log_warn("[%s] Unsupported E-CID measured results extension value NR-TADV",
                    location_request->supi ? location_request->supi : "Unknown");
            break;
        case MeasuredResultsValue_ExtensionIE__value_PR_UE_Rx_Tx_Time_Diff:
            log_warn("[%s] Unsupported E-CID measured results extension value UE Rx-Tx Time Diff",
                    location_request->supi ? location_request->supi : "Unknown");
            break;
        case MeasuredResultsValue_ExtensionIE__value_PR_E_CID_AoA_NR_per_TRP:
            log_warn("[%s] Unsupported E-CID measured results extension value AoA NR per TRP",
                    location_request->supi ? location_request->supi : "Unknown");
            break;
        default:
            log_error("[%s] Unrecognized E-CID measured results extension value [%d]",
                    location_request->supi ? location_request->supi : "Unknown", ext->value.present);
            break;
    }

    if (!ss_rsrp) {
        log_error("[%s] No SS-RSRP provided, cannot provide positioning",
                    location_request->supi ? location_request->supi : "Unknown");
        return OGS_ERROR;
    }

    /* Build serving cell NCGI from ECID response */
    memset(&serving_ncgi, 0, sizeof(serving_ncgi));

    // Set NR-CGI

    NG_RAN_CGI_t *serving_ie = ecid_measurement_result_ie->servingCell_ID;
	NG_RANCell_t *serving_id_ie = serving_ie->nG_RANcell;

    // TODO: This only supports NR, add support for LTE and others
    log_assert(serving_id_ie->present == NG_RANCell_PR_nR_CellID);
    serving_ncgi.cell_id = get_cell_id(&serving_id_ie->choice.nR_CellID);

    set_plmn_id(&serving_ncgi.plmn_id, &serving_ie->pLMN_Identity);

    serving_cell.ncgi = serving_ncgi.cell_id;

    /* Calculate weighted position from serving cell and neighbors */
    /* Weight by RSRP (higher RSRP = stronger signal = closer = higher weight) */
    ValueRSRP_NR_t serving_rsrp = 0;
    lmf_nrppa_ecid_cell_measurement_t neighbor_cells[NRPPA_MAX_NEIGHBOR_CELLS];
    ResultSS_RSRP_Item_t *rsrp_item = NULL;
    for (i = 0; i < ss_rsrp->list.count; i++) {
        rsrp_item = ss_rsrp->list.array[i];
        if (rsrp_item->valueSS_RSRP_Cell && 
            rsrp_item->cGI_NR && 
            rsrp_item->cGI_NR->pLMN_Identity.size != serving_ie->pLMN_Identity.size &&
            !strcmp((const char *)rsrp_item->cGI_NR->pLMN_Identity.buf, (const char *)serving_ie->pLMN_Identity.buf)
        ) {
            // Found serving cell =)
            serving_rsrp = *rsrp_item->valueSS_RSRP_Cell;
            continue;
        }

        neighbor_cells[i].rsrp = *rsrp_item->valueSS_RSRP_Cell;
        
        ogs_nr_cgi_t neighbor_ncgi;
        lmf_cell_info_t *neighbor_cell_info = NULL;
        double neighbor_weight;

        memset(&neighbor_ncgi, 0, sizeof(neighbor_ncgi));
        neighbor_ncgi.cell_id = neighbor_cells[i].ncgi;
        set_plmn_id(&neighbor_ncgi.plmn_id, &rsrp_item->cGI_NR->pLMN_Identity);

        neighbor_cell_info = lmf_cell_database_find_by_ncgi(&neighbor_ncgi);
        if (!neighbor_cell_info) {
            neighbor_cell_info = lmf_cell_database_find_by_cell_id(
                    neighbor_cells[i].ncgi);
        }

        if (neighbor_cell_info) {
            /* Weight by RSRP */
            neighbor_weight = 1.0;
            if (neighbor_cells[i].rsrp != 0) {
                neighbor_weight = rsrp_to_linear_power(
                        neighbor_cells[i].rsrp);
            }

            final_lat += neighbor_cell_info->latitude * neighbor_weight;
            final_lon += neighbor_cell_info->longitude * neighbor_weight;
            final_alt += neighbor_cell_info->altitude * neighbor_weight;
            total_weight += neighbor_weight;

            log_debug("[%s] Neighbor[%d]: NCGI=%llx, RSRP=%d, weight=%.3e",
                    location_request->supi ? location_request->supi : "Unknown", i,
                    (unsigned long long)neighbor_cells[i].ncgi,
                    neighbor_cells[i].rsrp,
                    neighbor_weight);
        }
    }
    
    /* Serving cell weight */
    double serving_weight = 1.0;  /* Default weight */
    if (serving_rsrp != 0) {
        serving_weight = rsrp_to_linear_power(serving_rsrp);
        final_lat += serving_cell_info->latitude * serving_weight;
        final_lon += serving_cell_info->longitude * serving_weight;
        final_alt += serving_cell_info->altitude * serving_weight;
    }
    
    total_weight += serving_weight;

    log_info("[%s] Serving cell: RSRP=%ld (%.1f dBm), weight=%.3e",
            location_request->supi ? location_request->supi : "Unknown",
            serving_rsrp,
            serving_rsrp / 10.0,
            serving_weight);

    /* Lookup serving cell in database */
    serving_cell_info = lmf_cell_database_find_by_ncgi(&serving_ncgi);
    if (!serving_cell_info) {
        log_error("[%s] Serving cell NCGI=%ld not found in database",
                    location_request->supi ? location_request->supi : "Unknown", serving_ncgi.cell_id);
        
        /* Try to find by cell_id only */
        serving_cell_info = lmf_cell_database_find_by_cell_id(serving_ncgi.cell_id);
    }

    if (!serving_cell_info) {
        log_error("[%s] Cannot calculate location: serving cell not in database",
                    location_request->supi ? location_request->supi : "Unknown");
        
        /* Send error response */
        stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
        if (stream) {
            ogs_sbi_server_send_error(stream,
                    OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR,
                    NULL, "Serving cell not found in database",
                    "The serving cell is not configured in LMF cell database", NULL);
        }
        return OGS_ERROR;
    }

    log_info("[%s] Serving cell found: lat=%.6f, lon=%.6f, alt=%.1f",
                    location_request->supi ? location_request->supi : "Unknown",
            serving_cell_info->latitude,
            serving_cell_info->longitude,
            serving_cell_info->altitude);

    /* Normalize weighted position */
    if (total_weight > 0.0) {
        final_lat /= total_weight;
        final_lon /= total_weight;
        final_alt /= total_weight;
    } else {
        /* Fallback: use serving cell position */
        final_lat = serving_cell_info->latitude;
        final_lon = serving_cell_info->longitude;
        final_alt = serving_cell_info->altitude;
    }

    /* Calculate uncertainty radius */
    /* Start with cell radius */
    uncertainty_radius = serving_cell_info->cell_radius;

    /* Add timing advance distance uncertainty */
    if (serving_cell.timing_advance > 0) {
        double ta_distance = ta_to_distance_meters(serving_cell.timing_advance);
        /* Use TA distance as minimum uncertainty */
        if (ta_distance > uncertainty_radius) {
            uncertainty_radius = ta_distance;
        }
        log_debug("[%s] Timing Advance: TA=%u, distance=%.1f m",
                    location_request->supi ? location_request->supi : "Unknown",
                serving_cell.timing_advance,
                ta_distance);
    }

    /* Add some margin for measurement inaccuracy (20% of radius) */
    uncertainty_radius *= 1.2;

    /* Minimum uncertainty: 50 meters */
    if (uncertainty_radius < 50.0) {
        uncertainty_radius = 50.0;
    }

    log_info("[%s] Calculated location: lat=%.6f, lon=%.6f, alt=%.1f, "
            "uncertainty=%.0f m",
                    location_request->supi ? location_request->supi : "Unknown",
            final_lat, final_lon, final_alt, uncertainty_radius);

    /* Build LocationData response */
    memset(&message, 0, sizeof(message));
    
    /* Create NCGI for response */
    ncgi_openapi = ogs_calloc(1, sizeof(OpenAPI_ncgi_t));
    log_assert(ncgi_openapi);
    
    plmn_id_openapi = ogs_calloc(1, sizeof(OpenAPI_plmn_id_t));
    log_assert(plmn_id_openapi);
    
    /* Convert PLMN ID */
    plmn_id_openapi->mcc = ogs_plmn_id_mcc_string(&serving_ncgi.plmn_id);
    plmn_id_openapi->mnc = ogs_plmn_id_mnc_string(&serving_ncgi.plmn_id);
    
    ncgi_openapi->plmn_id = plmn_id_openapi;
    ncgi_openapi->nr_cell_id = ogs_msprintf("%llx",
            (unsigned long long)serving_cell.ncgi);
    
    /* Create geographic area with all parameters */
    shape = OpenAPI_supported_gad_shapes_create();
    log_assert(shape);
    
    coordinates = OpenAPI_geographical_coordinates_create(final_lon, final_lat);
    log_assert(coordinates);
    
    geographic_area = OpenAPI_geographic_area_create(
        shape,                      /* shape */
        coordinates,                /* point */
        (float)uncertainty_radius,  /* uncertainty */
        NULL,                       /* uncertainty_ellipse */
        0,                          /* confidence */
        NULL,                       /* point_list */
        final_alt,                  /* altitude */
        10.0f,                      /* uncertainty_altitude */
        0,                          /* inner_radius */
        0.0f,                       /* uncertainty_radius */
        0,                          /* offset_angle */
        0                           /* included_angle */
    );
    log_assert(geographic_area);
    
    /* Create LocationData */
    location_data = OpenAPI_location_data_create(
            geographic_area,
            NULL,  /* accuracy_fulfilment_indicator */
            0,     /* is_age_of_location_estimate */
            0,     /* age_of_location_estimate */
            NULL,  /* timestamp_of_location_estimate */
            NULL,  /* velocity_estimate */
            NULL,  /* civic_address */
            NULL,  /* local_location_estimate */
            NULL,  /* positioning_data_list */
            NULL,  /* gnss_positioning_data_list */
            NULL,  /* ecgi */
            ncgi_openapi,
            1,     /* is_altitude */
            final_alt,
            0,     /* is_barometric_pressure */
            0,     /* barometric_pressure */
            NULL,  /* serving_lmf_identification */
            NULL,  /* ue_positioning_cap */
            NULL,  /* ue_area_ind */
            NULL,  /* supported_features */
            NULL   /* achieved_qos */
    );
    log_assert(location_data);

    message.h.method = (char *)OGS_SBI_HTTP_METHOD_POST;
    message.h.service.name = (char *)OGS_SBI_SERVICE_NAME_NLMF_LOC;
    message.h.api.version = (char *)OGS_SBI_API_V1;
    message.h.resource.component[0] = (char *)"determine-location";
    message.LocationData = location_data;

    log_info("[%s] LocationData prepared: lat=%.6f, lon=%.6f, uncertainty=%.0f",
                    location_request->supi ? location_request->supi : "Unknown", final_lat, final_lon, uncertainty_radius);
    log_info("  NCGI: plmn=%s/%s, cell=%s",
            plmn_id_openapi->mcc, plmn_id_openapi->mnc, ncgi_openapi->nr_cell_id);

    /* Build comprehensive JSON response with all location data */
    cJSON *root = cJSON_CreateObject();
    log_assert(root);
    
    cJSON *location_obj = cJSON_CreateObject();
    
    /* UE Identity (SUPI/IMSI) */
    if (location_request->supi) {
        cJSON_AddStringToObject(location_obj, "supi", location_request->supi);
    }
    
    /* Geographic coordinates (calculated position from ECID measurements) */
    cJSON_AddNumberToObject(location_obj, "latitude", final_lat);
    cJSON_AddNumberToObject(location_obj, "longitude", final_lon);
    cJSON_AddNumberToObject(location_obj, "altitude", final_alt);
    
    /* Uncertainty (critical for positioning accuracy assessment) */
    cJSON_AddNumberToObject(location_obj, "uncertaintyRadius", uncertainty_radius);
    cJSON_AddNumberToObject(location_obj, "uncertaintyAltitude", 10.0);
    cJSON_AddNumberToObject(location_obj, "confidence", 68);  /* ~68% confidence circle */
    
    /* Serving cell information */
    cJSON *ncgi_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(ncgi_obj, "mcc", plmn_id_openapi->mcc);
    cJSON_AddStringToObject(ncgi_obj, "mnc", plmn_id_openapi->mnc);
    cJSON_AddStringToObject(ncgi_obj, "nrCellId", ncgi_openapi->nr_cell_id);
    cJSON_AddItemToObject(location_obj, "ncgi", ncgi_obj);
    
    /* Cell ID as separate field for convenience (derived from NCGI) */
    cJSON_AddStringToObject(location_obj, "cellId", ncgi_openapi->nr_cell_id);
    
    /* Positioning method and quality */
    cJSON_AddStringToObject(location_obj, "positioningMethod", "ECID");
    
    /* RSRP measurement (always present) */
    cJSON_AddNumberToObject(location_obj, "rsrp", serving_rsrp / 10.0);  /* dBm */
    
    /* Timing Advance measurement (always include, 0 is valid) */
    cJSON_AddNumberToObject(location_obj, "timingAdvance", serving_cell.timing_advance);
    /* Add approximate distance based on TA (TA × 156 meters) */
    uint32_t distance_m = (uint32_t)serving_cell.timing_advance * 156;
    cJSON_AddNumberToObject(location_obj, "timingAdvanceDistance", distance_m);
    
    /* Angle of Arrival measurement (if present) */
    if (serving_cell.angle_of_arrival != 0) {
        /* Convert from degrees*2 to degrees */
        double azimuth_degrees = serving_cell.angle_of_arrival / 2.0;
        cJSON_AddNumberToObject(location_obj, "azimuthAngleOfArrival", azimuth_degrees);
    }
    
    cJSON_AddNumberToObject(location_obj, "timestamp", (double)ogs_time_now() / 1000);
    
    cJSON_AddItemToObject(root, "locationData", location_obj);
    
    /* Optional debug/diagnostic information (3GPP-compliant optional field) */
    cJSON *debug_obj = cJSON_CreateObject();
    if (debug_obj) {
        cJSON_AddNumberToObject(debug_obj, "measurementId", (double)*measurement_id);
        cJSON_AddNumberToObject(debug_obj, "numNeighborCells", (double)ss_rsrp->list.count);
        cJSON_AddNumberToObject(debug_obj, "totalWeight", total_weight);
        cJSON_AddNumberToObject(debug_obj, "servingCellWeight", serving_weight);
        cJSON_AddNumberToObject(debug_obj, "cellRadius", serving_cell_info->cell_radius);
        
        /* Cell database lookup status */
        cJSON_AddBoolToObject(debug_obj, "servingCellFound", serving_cell_info != NULL);
        if (serving_cell_info) {
            cJSON_AddNumberToObject(debug_obj, "servingCellLatitude", serving_cell_info->latitude);
            cJSON_AddNumberToObject(debug_obj, "servingCellLongitude", serving_cell_info->longitude);
        }
        
        /* Timing advance info */
        if (serving_cell.timing_advance > 0) {
            double ta_distance = ta_to_distance_meters(serving_cell.timing_advance);
            cJSON_AddNumberToObject(debug_obj, "timingAdvanceDistanceMeters", ta_distance);
        }
        
        /* Angle of arrival info */
        if (serving_cell.angle_of_arrival != 0) {
            double azimuth_degrees = serving_cell.angle_of_arrival / 2.0;
            cJSON_AddNumberToObject(debug_obj, "azimuthAngleOfArrivalDegrees", azimuth_degrees);
        }
        
        /* Calculation method */
        if (total_weight > 0.0) {
            cJSON_AddStringToObject(debug_obj, "calculationMethod", "weighted_average");
        } else {
            cJSON_AddStringToObject(debug_obj, "calculationMethod", "cell_center");
        }
        
        /* Add to root - AFTER locationData */
        cJSON_AddItemToObject(root, "debug", debug_obj);
    }
    
    /* Use unformatted JSON for consistency with Open5GS and better jq compatibility */
    char *json_str = cJSON_PrintUnformatted(root);
    cJSON_Delete(root);
    
    if (!json_str) {
        log_error("[%s] cJSON_PrintUnformatted failed",
                    location_request->supi ? location_request->supi : "Unknown");
        ogs_sbi_message_free(&message);
        return OGS_ERROR;
    }
    
    log_info("[%s] LocationData JSON: %s",
                    location_request->supi ? location_request->supi : "Unknown", json_str);
    
    /* Build HTTP response */
    response = ogs_sbi_response_new();
    log_assert(response);
    response->status = OGS_SBI_HTTP_STATUS_OK;
    response->http.content = json_str;
    response->http.content_length = strlen(json_str);
    ogs_sbi_header_set(response->http.headers, "Content-Type", "application/json");

    /* Free LocationData explicitly before freeing message */
    if (message.LocationData) {
        OpenAPI_location_data_free(message.LocationData);
        message.LocationData = NULL;
    }
    /* Free message - response has copied the data */
    ogs_sbi_message_free(&message);

    /* Find stream for async response */
    stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
    if (!stream) {
        log_error("[%s] Stream ID=%d not found for async response",
                    location_request->supi ? location_request->supi : "Unknown", location_request->stream_id);
        ogs_sbi_response_free(response);
        return OGS_ERROR;
    }

    /* Send async response */
    rv = ogs_sbi_server_send_response(stream, response);
    if (!rv) {
        log_error("[%s] ogs_sbi_server_send_response() failed",
                    location_request->supi ? location_request->supi : "Unknown");
        ogs_sbi_response_free(response);
        return OGS_ERROR;
    }

    log_info("[%s] Location response sent successfully",
                    location_request->supi ? location_request->supi : "Unknown");

    /* Clean up location request */
    lmf_location_request_remove(location_request);

    return OGS_OK;
}

int lmf_location_determine_cellid(lmf_location_request_t *location_request)
{
    int rv;
    ogs_sbi_stream_t *stream = NULL;
    ogs_sbi_message_t message;
    ogs_sbi_response_t *response = NULL;
    lmf_cell_info_t *cell_info = NULL;
    ogs_nr_cgi_t ncgi;
    OpenAPI_input_data_t *input_data = NULL;
    OpenAPI_ncgi_t *ncgi_openapi_input = NULL;
    OpenAPI_ecgi_t *ecgi_openapi_input = NULL;
    OpenAPI_location_data_t *location_data = NULL;
    OpenAPI_geographic_area_t *geographic_area = NULL;
    OpenAPI_geographical_coordinates_t *coordinates = NULL;
    OpenAPI_supported_gad_shapes_t *shape = NULL;
    OpenAPI_ncgi_t *ncgi_openapi = NULL;
    OpenAPI_plmn_id_t *plmn_id_openapi = NULL;
    double final_lat = 0.0, final_lon = 0.0, final_alt = 0.0;
    double uncertainty_radius = 0.0;
    uint64_t cell_id = 0;
    uint16_t mcc = 0, mnc = 0;
    uint16_t mnc_len = 2;
    bool is_ncgi = false;

    log_assert(location_request);
    log_assert(location_request->input_message);

    log_info("[%s] CELLID location determination from provided cell information",
            location_request->supi ? location_request->supi : "Unknown");

    /* Extract InputData from stored message */
    input_data = location_request->input_message->InputData;
    if (!input_data) {
        log_error("[%s] No InputData in stored message",
                location_request->supi);
        stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
        if (stream) {
            ogs_sbi_server_send_error(stream,
                    OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR,
                    NULL, "Internal server error",
                    "InputData not available", NULL);
            /* Free InputData explicitly before freeing message */
            if (location_request->input_message->InputData) {
                OpenAPI_input_data_free(location_request->input_message->InputData);
                location_request->input_message->InputData = NULL;
            }
            ogs_sbi_message_free(location_request->input_message);
            ogs_free(location_request->input_message);
            location_request->input_message = NULL;
        }
        return OGS_ERROR;
    }

    /* Extract NCGI or ECGI from InputData */
    ncgi_openapi_input = input_data->ncgi;
    ecgi_openapi_input = input_data->ecgi;

    if (!ncgi_openapi_input && !ecgi_openapi_input) {
        /* Check if we already have NCGI from AMF (from async response) */
        if (location_request->ncgi_from_amf) {
            /* Use NCGI retrieved from AMF */
            ncgi_openapi_input = location_request->ncgi_from_amf;
            log_info("[%s] Using NCGI retrieved from AMF: PLMN=%s/%s, CellID=%s",
                    location_request->supi,
                    ncgi_openapi_input->plmn_id ?
                        (ncgi_openapi_input->plmn_id->mcc ? ncgi_openapi_input->plmn_id->mcc : "N/A") : "N/A",
                    ncgi_openapi_input->plmn_id ?
                        (ncgi_openapi_input->plmn_id->mnc ? ncgi_openapi_input->plmn_id->mnc : "N/A") : "N/A",
                    ncgi_openapi_input->nr_cell_id ? ncgi_openapi_input->nr_cell_id : "N/A");
            /* Note: ncgi_from_amf will be freed in location_request cleanup */
        } else {
            /* No NCGI from AMF yet - should not happen, this function is called after async response */
            log_error("[%s] No NCGI/ECGI provided and no NCGI from AMF available",
                    location_request->supi);
            stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
            if (stream) {
                ogs_sbi_server_send_error(stream,
                        OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR,
                        NULL, "Internal server error",
                        "Cell information not available", NULL);
            }
            ogs_sbi_message_free(location_request->input_message);
            ogs_free(location_request->input_message);
            location_request->input_message = NULL;
            return OGS_ERROR;
        }
    }

    /* Process NCGI (5G NR) or ECGI (4G LTE) */
    memset(&ncgi, 0, sizeof(ncgi));
    
    if (ncgi_openapi_input) {
        is_ncgi = true;
        log_info("[%s] Using NCGI for CELLID positioning",
                location_request->supi);

        /* Extract PLMN ID from NCGI */
        if (ncgi_openapi_input->plmn_id) {
            if (ncgi_openapi_input->plmn_id->mcc) {
                mcc = atoi(ncgi_openapi_input->plmn_id->mcc);
            }
            if (ncgi_openapi_input->plmn_id->mnc) {
                mnc = atoi(ncgi_openapi_input->plmn_id->mnc);
                mnc_len = strlen(ncgi_openapi_input->plmn_id->mnc);
            }
        }

        /* Extract cell ID from NCGI (hex string without 0x prefix) */
        if (ncgi_openapi_input->nr_cell_id) {
            cell_id = strtoull(ncgi_openapi_input->nr_cell_id, NULL, 16);
            log_info("[%s] NCGI cell_id=%llx (from string: %s)",
                    location_request->supi,
                    (unsigned long long)cell_id,
                    ncgi_openapi_input->nr_cell_id);
        } else {
            log_error("[%s] NCGI missing nr_cell_id",
                    location_request->supi);
            stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
            if (stream) {
                ogs_sbi_server_send_error(stream,
                        OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                        NULL, "Invalid NCGI",
                        "NCGI missing nr_cell_id", NULL);
                /* Don't clean up here - let the handler do it to avoid use-after-free */
                ogs_sbi_message_free(location_request->input_message);
                ogs_free(location_request->input_message);
                location_request->input_message = NULL;
            }
            return OGS_ERROR;
        }
    } else if (ecgi_openapi_input) {
        is_ncgi = false;
        log_info("[%s] Using ECGI for CELLID positioning (LTE)",
                location_request->supi);

        /* Extract PLMN ID from ECGI */
        if (ecgi_openapi_input->plmn_id) {
            if (ecgi_openapi_input->plmn_id->mcc) {
                mcc = atoi(ecgi_openapi_input->plmn_id->mcc);
            }
            if (ecgi_openapi_input->plmn_id->mnc) {
                mnc = atoi(ecgi_openapi_input->plmn_id->mnc);
                mnc_len = strlen(ecgi_openapi_input->plmn_id->mnc);
            }
        }

        /* Extract cell ID from ECGI (hex string without 0x prefix) */
        if (ecgi_openapi_input->eutra_cell_id) {
            cell_id = strtoull(ecgi_openapi_input->eutra_cell_id, NULL, 16);
            log_info("[%s] ECGI cell_id=%llx (from string: %s)",
                    location_request->supi,
                    (unsigned long long)cell_id,
                    ecgi_openapi_input->eutra_cell_id);
        } else {
            log_error("[%s] ECGI missing eutra_cell_id",
                    location_request->supi);
            stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
            if (stream) {
                ogs_sbi_server_send_error(stream,
                        OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                        NULL, "Invalid ECGI",
                        "ECGI missing eutra_cell_id", NULL);
                /* Don't clean up here - let the handler do it to avoid use-after-free */
                ogs_sbi_message_free(location_request->input_message);
                ogs_free(location_request->input_message);
                location_request->input_message = NULL;
            }
            return OGS_ERROR;
        }
    }

    /* Build internal NCGI structure */
    ncgi.cell_id = cell_id;
    if (mcc > 0 && mnc > 0) {
        ogs_plmn_id_build(&ncgi.plmn_id, mcc, mnc, mnc_len);
    } else {
        /* Use default PLMN if not specified */
        log_warn("[%s] PLMN not specified, using default 999/70",
                location_request->supi);
        ogs_plmn_id_build(&ncgi.plmn_id, 999, 70, 2);
    }

    /* Lookup cell in database */
    cell_info = lmf_cell_database_find_by_ncgi(&ncgi);
    if (!cell_info) {
        /* Try fallback: lookup by cell_id only (if PLMN doesn't match) */
        log_debug("[%s] Cell not found by NCGI, trying cell_id-only lookup",
                location_request->supi);
        cell_info = lmf_cell_database_find_by_cell_id(cell_id);
    }

    if (!cell_info) {
        log_error("[%s] Cell not found in database: NCGI=%llx [PLMN:%06x,CELL:%llx]",
                location_request->supi,
                (unsigned long long)cell_id,
                ogs_plmn_id_hexdump(&ncgi.plmn_id),
                (unsigned long long)ncgi.cell_id);

        stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
        if (stream) {
            ogs_sbi_server_send_error(stream,
                    OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR,
                    NULL, "Cell not found in database",
                    "The specified cell is not configured in LMF cell database", NULL);
            /* Don't clean up here - let the handler do it to avoid use-after-free */
            ogs_sbi_message_free(location_request->input_message);
            ogs_free(location_request->input_message);
            location_request->input_message = NULL;
        }
        return OGS_ERROR;
    }

    log_info("[%s] Cell found in database: lat=%.6f, lon=%.6f, alt=%.1f, radius=%um",
            location_request->supi,
            cell_info->latitude,
            cell_info->longitude,
            cell_info->altitude,
            cell_info->cell_radius);

    /* Use cell position directly (CELLID positioning uses cell center) */
    final_lat = cell_info->latitude;
    final_lon = cell_info->longitude;
    final_alt = cell_info->altitude;
    uncertainty_radius = (double)cell_info->cell_radius;

    /* Minimum uncertainty: 50 meters */
    if (uncertainty_radius < 50.0) {
        uncertainty_radius = 50.0;
    }

    log_info("[%s] Calculated location (CELLID): lat=%.6f, lon=%.6f, alt=%.1f, "
            "uncertainty=%.0f m",
            location_request->supi,
            final_lat, final_lon, final_alt, uncertainty_radius);

    /* Build LocationData response */
    memset(&message, 0, sizeof(message));
    
    /* Create NCGI for response */
    ncgi_openapi = ogs_calloc(1, sizeof(OpenAPI_ncgi_t));
    log_assert(ncgi_openapi);
    
    plmn_id_openapi = ogs_calloc(1, sizeof(OpenAPI_plmn_id_t));
    log_assert(plmn_id_openapi);
    
    /* Convert PLMN ID */
    plmn_id_openapi->mcc = ogs_plmn_id_mcc_string(&ncgi.plmn_id);
    plmn_id_openapi->mnc = ogs_plmn_id_mnc_string(&ncgi.plmn_id);
    
    ncgi_openapi->plmn_id = plmn_id_openapi;
    ncgi_openapi->nr_cell_id = ogs_msprintf("%llx",
            (unsigned long long)ncgi.cell_id);
    
    /* Create geographic area */
    shape = OpenAPI_supported_gad_shapes_create();
    log_assert(shape);
    
    coordinates = OpenAPI_geographical_coordinates_create(final_lon, final_lat);
    log_assert(coordinates);
    
    geographic_area = OpenAPI_geographic_area_create(
        shape,                      /* shape */
        coordinates,                /* point */
        (float)uncertainty_radius,  /* uncertainty */
        NULL,                       /* uncertainty_ellipse */
        0,                          /* confidence */
        NULL,                       /* point_list */
        final_alt,                  /* altitude */
        10.0f,                      /* uncertainty_altitude */
        0,                          /* inner_radius */
        0.0f,                       /* uncertainty_radius */
        0,                          /* offset_angle */
        0                           /* included_angle */
    );
    log_assert(geographic_area);
    
    /* Create LocationData */
    location_data = OpenAPI_location_data_create(
            geographic_area,
            NULL,  /* accuracy_fulfilment_indicator */
            0,     /* is_age_of_location_estimate */
            0,     /* age_of_location_estimate */
            NULL,  /* timestamp_of_location_estimate */
            NULL,  /* velocity_estimate */
            NULL,  /* civic_address */
            NULL,  /* local_location_estimate */
            NULL,  /* positioning_data_list */
            NULL,  /* gnss_positioning_data_list */
            NULL,  /* ecgi */
            ncgi_openapi,
            1,     /* is_altitude */
            final_alt,
            0,     /* is_barometric_pressure */
            0,     /* barometric_pressure */
            NULL,  /* serving_lmf_identification */
            NULL,  /* ue_positioning_cap */
            NULL,  /* ue_area_ind */
            NULL,  /* supported_features */
            NULL   /* achieved_qos */
    );
    log_assert(location_data);

    message.h.method = (char *)OGS_SBI_HTTP_METHOD_POST;
    message.h.service.name = (char *)OGS_SBI_SERVICE_NAME_NLMF_LOC;
    message.h.api.version = (char *)OGS_SBI_API_V1;
    message.h.resource.component[0] = (char *)"determine-location";
    message.LocationData = location_data;

    log_info("[%s] LocationData prepared: lat=%.6f, lon=%.6f, uncertainty=%.0f",
            location_request->supi, final_lat, final_lon, uncertainty_radius);
    log_info("  NCGI: plmn=%s/%s, cell=%s",
            plmn_id_openapi->mcc, plmn_id_openapi->mnc, ncgi_openapi->nr_cell_id);

    /* Build JSON response */
    cJSON *root = cJSON_CreateObject();
    log_assert(root);
    
    cJSON *location_obj = cJSON_CreateObject();
    
    /* UE Identity (SUPI/IMSI) */
    if (location_request->supi) {
        cJSON_AddStringToObject(location_obj, "supi", location_request->supi);
    }
    
    /* Geographic coordinates (cell center position) */
    cJSON_AddNumberToObject(location_obj, "latitude", final_lat);
    cJSON_AddNumberToObject(location_obj, "longitude", final_lon);
    cJSON_AddNumberToObject(location_obj, "altitude", final_alt);
    
    /* Uncertainty (cell radius) */
    cJSON_AddNumberToObject(location_obj, "uncertaintyRadius", uncertainty_radius);
    cJSON_AddNumberToObject(location_obj, "uncertaintyAltitude", 10.0);
    cJSON_AddNumberToObject(location_obj, "confidence", 68);  /* ~68% confidence circle */
    
    /* Serving cell information */
    cJSON *ncgi_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(ncgi_obj, "mcc", plmn_id_openapi->mcc);
    cJSON_AddStringToObject(ncgi_obj, "mnc", plmn_id_openapi->mnc);
    cJSON_AddStringToObject(ncgi_obj, "nrCellId", ncgi_openapi->nr_cell_id);
    cJSON_AddItemToObject(location_obj, "ncgi", ncgi_obj);
    
    /* Cell ID as separate field for convenience */
    cJSON_AddStringToObject(location_obj, "cellId", ncgi_openapi->nr_cell_id);
    
    /* Positioning method */
    cJSON_AddStringToObject(location_obj, "positioningMethod", "CELLID");
    
    /* Timestamp (current time in milliseconds) */
    uint64_t timestamp = ogs_time_now() / 1000;  /* Convert microseconds to milliseconds */
    cJSON_AddNumberToObject(location_obj, "timestamp", (double)timestamp);
    
    cJSON_AddItemToObject(root, "locationData", location_obj);
    
    /* Optional debug information */
    cJSON *debug_obj = cJSON_CreateObject();
    if (debug_obj) {
        cJSON_AddBoolToObject(debug_obj, "servingCellFound", cell_info != NULL);
        if (cell_info) {
            cJSON_AddNumberToObject(debug_obj, "cellRadius", cell_info->cell_radius);
            cJSON_AddNumberToObject(debug_obj, "cellLatitude", cell_info->latitude);
            cJSON_AddNumberToObject(debug_obj, "cellLongitude", cell_info->longitude);
        }
        cJSON_AddStringToObject(debug_obj, "calculationMethod", "cell_center");
        cJSON_AddStringToObject(debug_obj, "cellType", is_ncgi ? "NCGI" : "ECGI");
        cJSON_AddItemToObject(root, "debug", debug_obj);
    }
    
    /* Use unformatted JSON for consistency with Open5GS and better jq compatibility */
    char *json_str = cJSON_PrintUnformatted(root);
    cJSON_Delete(root);
    
    if (!json_str) {
        log_error("[%s] cJSON_PrintUnformatted failed", location_request->supi);
        ogs_sbi_message_free(&message);
        return OGS_ERROR;
    }
    
    log_info("[%s] LocationData JSON: %s", location_request->supi, json_str);
    
    /* Build HTTP response */
    response = ogs_sbi_response_new();
    log_assert(response);
    response->status = OGS_SBI_HTTP_STATUS_OK;
    response->http.content = json_str;
    response->http.content_length = strlen(json_str);
    ogs_sbi_header_set(response->http.headers, "Content-Type", "application/json");

    /* Free LocationData explicitly before freeing message */
    if (message.LocationData) {
        OpenAPI_location_data_free(message.LocationData);
        message.LocationData = NULL;
    }
    /* Free message - response has copied the data */
    ogs_sbi_message_free(&message);

    /* Find stream for async response */
    stream = ogs_sbi_stream_find_by_id(location_request->stream_id);
    if (!stream) {
        log_error("[%s] Stream ID=%d not found for async response",
                location_request->supi, location_request->stream_id);
        ogs_sbi_response_free(response);
        return OGS_ERROR;
    }

    /* Send async response */
    rv = ogs_sbi_server_send_response(stream, response);
    if (!rv) {
        log_error("[%s] ogs_sbi_server_send_response() failed",
                location_request->supi);
        ogs_sbi_response_free(response);
        return OGS_ERROR;
    }

    log_info("[%s] Location response sent successfully (CELLID)",
            location_request->supi);

    /* Clean up location request */
    lmf_location_request_remove(location_request);

    return OGS_OK;
}
