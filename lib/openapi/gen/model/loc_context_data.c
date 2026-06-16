
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_context_data.h"

OpenAPI_loc_context_data_t *OpenAPI_loc_context_data_create(
    char *amf_id,
    OpenAPI_location_qo_s_t *location_qo_s,
    OpenAPI_list_t *supported_gad_shapes,
    char *supi,
    char *gpsi,
    OpenAPI_list_t *add_loc_context_list,
    OpenAPI_ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    OpenAPI_periodic_event_info_t *periodic_event_info,
    OpenAPI_area_event_info_t *area_event_info,
    OpenAPI_motion_event_info_t *motion_event_info,
    OpenAPI_event_report_message_t *event_report_message,
    OpenAPI_event_reporting_status_t *event_reporting_status,
    OpenAPI_ue_location_info_t *ue_location_info,
    bool is_c_io_t5_gs_optimisation,
    int c_io_t5_gs_optimisation,
    OpenAPI_ecgi_t *ecgi,
    OpenAPI_ncgi_t *ncgi,
    OpenAPI_guami_t *guami,
    char *supported_features,
    char ue_positioning_cap,
    OpenAPI_list_t *ue_up_pos_caps,
    char *scheduled_loc_time,
    OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind,
    OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind,
    OpenAPI_up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    bool is_lcs_upp_exist_ind,
    int lcs_upp_exist_ind,
    char *src_lmf_routing_info,
    bool is_extended_facility_ind,
    int extended_facility_ind
)
{
    OpenAPI_loc_context_data_t *loc_context_data_local_var = ogs_malloc(sizeof(OpenAPI_loc_context_data_t));
    ogs_assert(loc_context_data_local_var);

    loc_context_data_local_var->amf_id = amf_id;
    loc_context_data_local_var->location_qo_s = location_qo_s;
    loc_context_data_local_var->supported_gad_shapes = supported_gad_shapes;
    loc_context_data_local_var->supi = supi;
    loc_context_data_local_var->gpsi = gpsi;
    loc_context_data_local_var->add_loc_context_list = add_loc_context_list;
    loc_context_data_local_var->ldr_type = ldr_type;
    loc_context_data_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
    loc_context_data_local_var->ldr_reference = ldr_reference;
    loc_context_data_local_var->periodic_event_info = periodic_event_info;
    loc_context_data_local_var->area_event_info = area_event_info;
    loc_context_data_local_var->motion_event_info = motion_event_info;
    loc_context_data_local_var->event_report_message = event_report_message;
    loc_context_data_local_var->event_reporting_status = event_reporting_status;
    loc_context_data_local_var->ue_location_info = ue_location_info;
    loc_context_data_local_var->is_c_io_t5_gs_optimisation = is_c_io_t5_gs_optimisation;
    loc_context_data_local_var->c_io_t5_gs_optimisation = c_io_t5_gs_optimisation;
    loc_context_data_local_var->ecgi = ecgi;
    loc_context_data_local_var->ncgi = ncgi;
    loc_context_data_local_var->guami = guami;
    loc_context_data_local_var->supported_features = supported_features;
    loc_context_data_local_var->ue_positioning_cap = ue_positioning_cap;
    loc_context_data_local_var->ue_up_pos_caps = ue_up_pos_caps;
    loc_context_data_local_var->scheduled_loc_time = scheduled_loc_time;
    loc_context_data_local_var->indoor_outdoor_ind = indoor_outdoor_ind;
    loc_context_data_local_var->los_nlos_measure_ind = los_nlos_measure_ind;
    loc_context_data_local_var->up_cum_evt_rpt_criteria = up_cum_evt_rpt_criteria;
    loc_context_data_local_var->is_lcs_upp_exist_ind = is_lcs_upp_exist_ind;
    loc_context_data_local_var->lcs_upp_exist_ind = lcs_upp_exist_ind;
    loc_context_data_local_var->src_lmf_routing_info = src_lmf_routing_info;
    loc_context_data_local_var->is_extended_facility_ind = is_extended_facility_ind;
    loc_context_data_local_var->extended_facility_ind = extended_facility_ind;

    return loc_context_data_local_var;
}

void OpenAPI_loc_context_data_free(OpenAPI_loc_context_data_t *loc_context_data)
{
    if (NULL == loc_context_data) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(loc_context_data->amf_id);
    OpenAPI_location_qo_s_free(loc_context_data->location_qo_s);
    OpenAPI_list_for_each(loc_context_data->supported_gad_shapes, node) {
        OpenAPI_supported_gad_shapes_free(node->data);
    }
    OpenAPI_list_free(loc_context_data->supported_gad_shapes);
    ogs_free(loc_context_data->supi);
    ogs_free(loc_context_data->gpsi);
    OpenAPI_list_for_each(loc_context_data->add_loc_context_list, node) {
        OpenAPI_add_location_context_free(node->data);
    }
    OpenAPI_list_free(loc_context_data->add_loc_context_list);
    OpenAPI_ldr_type_free(loc_context_data->ldr_type);
    ogs_free(loc_context_data->hgmlc_call_back_uri);
    ogs_free(loc_context_data->ldr_reference);
    OpenAPI_periodic_event_info_free(loc_context_data->periodic_event_info);
    OpenAPI_area_event_info_free(loc_context_data->area_event_info);
    OpenAPI_motion_event_info_free(loc_context_data->motion_event_info);
    OpenAPI_event_report_message_free(loc_context_data->event_report_message);
    OpenAPI_event_reporting_status_free(loc_context_data->event_reporting_status);
    OpenAPI_ue_location_info_free(loc_context_data->ue_location_info);
    OpenAPI_ecgi_free(loc_context_data->ecgi);
    OpenAPI_ncgi_free(loc_context_data->ncgi);
    OpenAPI_guami_free(loc_context_data->guami);
    ogs_free(loc_context_data->supported_features);
    OpenAPI_list_for_each(loc_context_data->ue_up_pos_caps, node) {
        OpenAPI_ue_up_positioning_capabilities_free(node->data);
    }
    OpenAPI_list_free(loc_context_data->ue_up_pos_caps);
    ogs_free(loc_context_data->scheduled_loc_time);
    OpenAPI_indoor_outdoor_ind_free(loc_context_data->indoor_outdoor_ind);
    OpenAPI_los_nlos_measure_ind_free(loc_context_data->los_nlos_measure_ind);
    OpenAPI_up_cum_evt_rpt_criteria_free(loc_context_data->up_cum_evt_rpt_criteria);
    ogs_free(loc_context_data->src_lmf_routing_info);
    ogs_free(loc_context_data);
}

cJSON *OpenAPI_loc_context_data_convertToJSON(OpenAPI_loc_context_data_t *loc_context_data)
{
    cJSON *item = NULL;

    if (loc_context_data == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [LocContextData]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddStringToObject(item, "amfId", loc_context_data->amf_id) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [amf_id]");
        goto end;
    }

    if (loc_context_data->location_qo_s) {
    cJSON *location_qo_s_local_JSON = OpenAPI_location_qo_s_convertToJSON(loc_context_data->location_qo_s);
    if (location_qo_s_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [location_qo_s]");
        goto end;
    }
    cJSON_AddItemToObject(item, "locationQoS", location_qo_s_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [location_qo_s]");
        goto end;
    }
    }

    if (loc_context_data->supported_gad_shapes) {
    cJSON *supported_gad_shapesList = cJSON_AddArrayToObject(item, "supportedGADShapes");
    if (supported_gad_shapesList == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [supported_gad_shapes]");
        goto end;
    }

    OpenAPI_lnode_t *supported_gad_shapes_node;
    if (loc_context_data->supported_gad_shapes) {
        OpenAPI_list_for_each(loc_context_data->supported_gad_shapes, supported_gad_shapes_node) {
            cJSON *itemLocal = OpenAPI_supported_gad_shapes_convertToJSON(supported_gad_shapes_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [supported_gad_shapes]");
                goto end;
            }
            cJSON_AddItemToArray(supported_gad_shapesList, itemLocal);
        }
    }
    }

    if (loc_context_data->supi) {
    if (cJSON_AddStringToObject(item, "supi", loc_context_data->supi) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [supi]");
        goto end;
    }
    }

    if (loc_context_data->gpsi) {
    if (cJSON_AddStringToObject(item, "gpsi", loc_context_data->gpsi) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [gpsi]");
        goto end;
    }
    }

    if (loc_context_data->add_loc_context_list) {
    cJSON *add_loc_context_listList = cJSON_AddArrayToObject(item, "addLocContextList");
    if (add_loc_context_listList == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [add_loc_context_list]");
        goto end;
    }

    OpenAPI_lnode_t *add_loc_context_list_node;
    if (loc_context_data->add_loc_context_list) {
        OpenAPI_list_for_each(loc_context_data->add_loc_context_list, add_loc_context_list_node) {
            cJSON *itemLocal = OpenAPI_add_location_context_convertToJSON(add_loc_context_list_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [add_loc_context_list]");
                goto end;
            }
            cJSON_AddItemToArray(add_loc_context_listList, itemLocal);
        }
    }
    }

    cJSON *ldr_type_local_JSON = OpenAPI_ldr_type_convertToJSON(loc_context_data->ldr_type);
    if (ldr_type_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ldr_type]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ldrType", ldr_type_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ldr_type]");
        goto end;
    }

    if (cJSON_AddStringToObject(item, "hgmlcCallBackURI", loc_context_data->hgmlc_call_back_uri) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [hgmlc_call_back_uri]");
        goto end;
    }

    if (cJSON_AddStringToObject(item, "ldrReference", loc_context_data->ldr_reference) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ldr_reference]");
        goto end;
    }

    if (loc_context_data->periodic_event_info) {
    cJSON *periodic_event_info_local_JSON = OpenAPI_periodic_event_info_convertToJSON(loc_context_data->periodic_event_info);
    if (periodic_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [periodic_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "periodicEventInfo", periodic_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [periodic_event_info]");
        goto end;
    }
    }

    if (loc_context_data->area_event_info) {
    cJSON *area_event_info_local_JSON = OpenAPI_area_event_info_convertToJSON(loc_context_data->area_event_info);
    if (area_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [area_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "areaEventInfo", area_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [area_event_info]");
        goto end;
    }
    }

    if (loc_context_data->motion_event_info) {
    cJSON *motion_event_info_local_JSON = OpenAPI_motion_event_info_convertToJSON(loc_context_data->motion_event_info);
    if (motion_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [motion_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "motionEventInfo", motion_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [motion_event_info]");
        goto end;
    }
    }

    cJSON *event_report_message_local_JSON = OpenAPI_event_report_message_convertToJSON(loc_context_data->event_report_message);
    if (event_report_message_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [event_report_message]");
        goto end;
    }
    cJSON_AddItemToObject(item, "eventReportMessage", event_report_message_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [event_report_message]");
        goto end;
    }

    if (loc_context_data->event_reporting_status) {
    cJSON *event_reporting_status_local_JSON = OpenAPI_event_reporting_status_convertToJSON(loc_context_data->event_reporting_status);
    if (event_reporting_status_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [event_reporting_status]");
        goto end;
    }
    cJSON_AddItemToObject(item, "eventReportingStatus", event_reporting_status_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [event_reporting_status]");
        goto end;
    }
    }

    if (loc_context_data->ue_location_info) {
    cJSON *ue_location_info_local_JSON = OpenAPI_ue_location_info_convertToJSON(loc_context_data->ue_location_info);
    if (ue_location_info_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ue_location_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ueLocationInfo", ue_location_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ue_location_info]");
        goto end;
    }
    }

    if (loc_context_data->is_c_io_t5_gs_optimisation) {
    if (cJSON_AddBoolToObject(item, "cIoT5GSOptimisation", loc_context_data->c_io_t5_gs_optimisation) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [c_io_t5_gs_optimisation]");
        goto end;
    }
    }

    if (loc_context_data->ecgi) {
    cJSON *ecgi_local_JSON = OpenAPI_ecgi_convertToJSON(loc_context_data->ecgi);
    if (ecgi_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ecgi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ecgi]");
        goto end;
    }
    }

    if (loc_context_data->ncgi) {
    cJSON *ncgi_local_JSON = OpenAPI_ncgi_convertToJSON(loc_context_data->ncgi);
    if (ncgi_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ncgi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ncgi]");
        goto end;
    }
    }

    if (loc_context_data->guami) {
    cJSON *guami_local_JSON = OpenAPI_guami_convertToJSON(loc_context_data->guami);
    if (guami_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [guami]");
        goto end;
    }
    cJSON_AddItemToObject(item, "guami", guami_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [guami]");
        goto end;
    }
    }

    if (loc_context_data->supported_features) {
    if (cJSON_AddStringToObject(item, "supportedFeatures", loc_context_data->supported_features) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [supported_features]");
        goto end;
    }
    }

    if (loc_context_data->ue_positioning_cap) {
    if (cJSON_AddNumberToObject(item, "uePositioningCap", loc_context_data->ue_positioning_cap) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ue_positioning_cap]");
        goto end;
    }
    }

    if (loc_context_data->ue_up_pos_caps) {
    cJSON *ue_up_pos_capsList = cJSON_AddArrayToObject(item, "ueUpPosCaps");
    if (ue_up_pos_capsList == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ue_up_pos_caps]");
        goto end;
    }

    OpenAPI_lnode_t *ue_up_pos_caps_node;
    if (loc_context_data->ue_up_pos_caps) {
        OpenAPI_list_for_each(loc_context_data->ue_up_pos_caps, ue_up_pos_caps_node) {
            cJSON *itemLocal = OpenAPI_ue_up_positioning_capabilities_convertToJSON(ue_up_pos_caps_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [ue_up_pos_caps]");
                goto end;
            }
            cJSON_AddItemToArray(ue_up_pos_capsList, itemLocal);
        }
    }
    }

    if (loc_context_data->scheduled_loc_time) {
    if (cJSON_AddStringToObject(item, "scheduledLocTime", loc_context_data->scheduled_loc_time) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [scheduled_loc_time]");
        goto end;
    }
    }

    if (loc_context_data->indoor_outdoor_ind) {
    cJSON *indoor_outdoor_ind_local_JSON = OpenAPI_indoor_outdoor_ind_convertToJSON(loc_context_data->indoor_outdoor_ind);
    if (indoor_outdoor_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [indoor_outdoor_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "indoorOutdoorInd", indoor_outdoor_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [indoor_outdoor_ind]");
        goto end;
    }
    }

    if (loc_context_data->los_nlos_measure_ind) {
    cJSON *los_nlos_measure_ind_local_JSON = OpenAPI_los_nlos_measure_ind_convertToJSON(loc_context_data->los_nlos_measure_ind);
    if (los_nlos_measure_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [los_nlos_measure_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "losNlosMeasureInd", los_nlos_measure_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [los_nlos_measure_ind]");
        goto end;
    }
    }

    if (loc_context_data->up_cum_evt_rpt_criteria) {
    cJSON *up_cum_evt_rpt_criteria_local_JSON = OpenAPI_up_cum_evt_rpt_criteria_convertToJSON(loc_context_data->up_cum_evt_rpt_criteria);
    if (up_cum_evt_rpt_criteria_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [up_cum_evt_rpt_criteria]");
        goto end;
    }
    cJSON_AddItemToObject(item, "upCumEvtRptCriteria", up_cum_evt_rpt_criteria_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [up_cum_evt_rpt_criteria]");
        goto end;
    }
    }

    if (loc_context_data->is_lcs_upp_exist_ind) {
    if (cJSON_AddBoolToObject(item, "lcsUppExistInd", loc_context_data->lcs_upp_exist_ind) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [lcs_upp_exist_ind]");
        goto end;
    }
    }

    if (loc_context_data->src_lmf_routing_info) {
    if (cJSON_AddStringToObject(item, "srcLmfRoutingInfo", loc_context_data->src_lmf_routing_info) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [src_lmf_routing_info]");
        goto end;
    }
    }

    if (loc_context_data->is_extended_facility_ind) {
    if (cJSON_AddBoolToObject(item, "extendedFacilityInd", loc_context_data->extended_facility_ind) == NULL) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed [extended_facility_ind]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_loc_context_data_t *OpenAPI_loc_context_data_parseFromJSON(cJSON *loc_context_dataJSON)
{
    OpenAPI_loc_context_data_t *loc_context_data_local_var = NULL;
    cJSON *amf_id = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "amfId");
    if (!amf_id) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [amf_id]");
        goto end;
    }

    if (!cJSON_IsString(amf_id)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [amf_id]");
        goto end;
    }

    cJSON *location_qo_s = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "locationQoS");

    OpenAPI_location_qo_s_t *location_qo_s_local_nonprim = NULL;
    if (location_qo_s) {
    location_qo_s_local_nonprim = OpenAPI_location_qo_s_parseFromJSON(location_qo_s);
    }

    cJSON *supported_gad_shapes = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "supportedGADShapes");

    OpenAPI_list_t *supported_gad_shapesList;
    if (supported_gad_shapes) {
    cJSON *supported_gad_shapes_local_nonprimitive;
    if (!cJSON_IsArray(supported_gad_shapes)){
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [supported_gad_shapes]");
        goto end;
    }

    supported_gad_shapesList = OpenAPI_list_create();

    cJSON_ArrayForEach(supported_gad_shapes_local_nonprimitive, supported_gad_shapes ) {
        if (!cJSON_IsObject(supported_gad_shapes_local_nonprimitive)) {
            ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [supported_gad_shapes]");
            goto end;
        }
        OpenAPI_supported_gad_shapes_t *supported_gad_shapesItem = OpenAPI_supported_gad_shapes_parseFromJSON(supported_gad_shapes_local_nonprimitive);

        if (!supported_gad_shapesItem) {
            ogs_error("No supported_gad_shapesItem");
            OpenAPI_list_free(supported_gad_shapesList);
            goto end;
        }

        OpenAPI_list_add(supported_gad_shapesList, supported_gad_shapesItem);
    }
    }

    cJSON *supi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "supi");

    if (supi) {
    if (!cJSON_IsString(supi)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [supi]");
        goto end;
    }
    }

    cJSON *gpsi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "gpsi");

    if (gpsi) {
    if (!cJSON_IsString(gpsi)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [gpsi]");
        goto end;
    }
    }

    cJSON *add_loc_context_list = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "addLocContextList");

    OpenAPI_list_t *add_loc_context_listList;
    if (add_loc_context_list) {
    cJSON *add_loc_context_list_local_nonprimitive;
    if (!cJSON_IsArray(add_loc_context_list)){
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [add_loc_context_list]");
        goto end;
    }

    add_loc_context_listList = OpenAPI_list_create();

    cJSON_ArrayForEach(add_loc_context_list_local_nonprimitive, add_loc_context_list ) {
        if (!cJSON_IsObject(add_loc_context_list_local_nonprimitive)) {
            ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [add_loc_context_list]");
            goto end;
        }
        OpenAPI_add_location_context_t *add_loc_context_listItem = OpenAPI_add_location_context_parseFromJSON(add_loc_context_list_local_nonprimitive);

        if (!add_loc_context_listItem) {
            ogs_error("No add_loc_context_listItem");
            OpenAPI_list_free(add_loc_context_listList);
            goto end;
        }

        OpenAPI_list_add(add_loc_context_listList, add_loc_context_listItem);
    }
    }

    cJSON *ldr_type = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ldrType");
    if (!ldr_type) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [ldr_type]");
        goto end;
    }

    OpenAPI_ldr_type_t *ldr_type_local_nonprim = NULL;
    ldr_type_local_nonprim = OpenAPI_ldr_type_parseFromJSON(ldr_type);

    cJSON *hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "hgmlcCallBackURI");
    if (!hgmlc_call_back_uri) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [hgmlc_call_back_uri]");
        goto end;
    }

    if (!cJSON_IsString(hgmlc_call_back_uri)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [hgmlc_call_back_uri]");
        goto end;
    }

    cJSON *ldr_reference = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ldrReference");
    if (!ldr_reference) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [ldr_reference]");
        goto end;
    }

    if (!cJSON_IsString(ldr_reference)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [ldr_reference]");
        goto end;
    }

    cJSON *periodic_event_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "periodicEventInfo");

    OpenAPI_periodic_event_info_t *periodic_event_info_local_nonprim = NULL;
    if (periodic_event_info) {
    periodic_event_info_local_nonprim = OpenAPI_periodic_event_info_parseFromJSON(periodic_event_info);
    }

    cJSON *area_event_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "areaEventInfo");

    OpenAPI_area_event_info_t *area_event_info_local_nonprim = NULL;
    if (area_event_info) {
    area_event_info_local_nonprim = OpenAPI_area_event_info_parseFromJSON(area_event_info);
    }

    cJSON *motion_event_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "motionEventInfo");

    OpenAPI_motion_event_info_t *motion_event_info_local_nonprim = NULL;
    if (motion_event_info) {
    motion_event_info_local_nonprim = OpenAPI_motion_event_info_parseFromJSON(motion_event_info);
    }

    cJSON *event_report_message = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "eventReportMessage");
    if (!event_report_message) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [event_report_message]");
        goto end;
    }

    OpenAPI_event_report_message_t *event_report_message_local_nonprim = NULL;
    event_report_message_local_nonprim = OpenAPI_event_report_message_parseFromJSON(event_report_message);

    cJSON *event_reporting_status = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "eventReportingStatus");

    OpenAPI_event_reporting_status_t *event_reporting_status_local_nonprim = NULL;
    if (event_reporting_status) {
    event_reporting_status_local_nonprim = OpenAPI_event_reporting_status_parseFromJSON(event_reporting_status);
    }

    cJSON *ue_location_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ueLocationInfo");

    OpenAPI_ue_location_info_t *ue_location_info_local_nonprim = NULL;
    if (ue_location_info) {
    ue_location_info_local_nonprim = OpenAPI_ue_location_info_parseFromJSON(ue_location_info);
    }

    cJSON *c_io_t5_gs_optimisation = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "cIoT5GSOptimisation");

    if (c_io_t5_gs_optimisation) {
    if (!cJSON_IsBool(c_io_t5_gs_optimisation)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [c_io_t5_gs_optimisation]");
        goto end;
    }
    }

    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ecgi");

    OpenAPI_ecgi_t *ecgi_local_nonprim = NULL;
    if (ecgi) {
    ecgi_local_nonprim = OpenAPI_ecgi_parseFromJSON(ecgi);
    }

    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ncgi");

    OpenAPI_ncgi_t *ncgi_local_nonprim = NULL;
    if (ncgi) {
    ncgi_local_nonprim = OpenAPI_ncgi_parseFromJSON(ncgi);
    }

    cJSON *guami = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "guami");

    OpenAPI_guami_t *guami_local_nonprim = NULL;
    if (guami) {
    guami_local_nonprim = OpenAPI_guami_parseFromJSON(guami);
    }

    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "supportedFeatures");

    if (supported_features) {
    if (!cJSON_IsString(supported_features)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [supported_features]");
        goto end;
    }
    }

    cJSON *ue_positioning_cap = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "uePositioningCap");

    if (ue_positioning_cap) {
    if (!cJSON_IsNumber(ue_positioning_cap)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [ue_positioning_cap]");
        goto end;
    }
    }

    cJSON *ue_up_pos_caps = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ueUpPosCaps");

    OpenAPI_list_t *ue_up_pos_capsList;
    if (ue_up_pos_caps) {
    cJSON *ue_up_pos_caps_local_nonprimitive;
    if (!cJSON_IsArray(ue_up_pos_caps)){
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [ue_up_pos_caps]");
        goto end;
    }

    ue_up_pos_capsList = OpenAPI_list_create();

    cJSON_ArrayForEach(ue_up_pos_caps_local_nonprimitive, ue_up_pos_caps ) {
        if (!cJSON_IsObject(ue_up_pos_caps_local_nonprimitive)) {
            ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [ue_up_pos_caps]");
            goto end;
        }
        OpenAPI_ue_up_positioning_capabilities_t *ue_up_pos_capsItem = OpenAPI_ue_up_positioning_capabilities_parseFromJSON(ue_up_pos_caps_local_nonprimitive);

        if (!ue_up_pos_capsItem) {
            ogs_error("No ue_up_pos_capsItem");
            OpenAPI_list_free(ue_up_pos_capsList);
            goto end;
        }

        OpenAPI_list_add(ue_up_pos_capsList, ue_up_pos_capsItem);
    }
    }

    cJSON *scheduled_loc_time = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "scheduledLocTime");

    if (scheduled_loc_time) {
    if (!cJSON_IsString(scheduled_loc_time)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [scheduled_loc_time]");
        goto end;
    }
    }

    cJSON *indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "indoorOutdoorInd");

    OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind_local_nonprim = NULL;
    if (indoor_outdoor_ind) {
    indoor_outdoor_ind_local_nonprim = OpenAPI_indoor_outdoor_ind_parseFromJSON(indoor_outdoor_ind);
    }

    cJSON *los_nlos_measure_ind = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "losNlosMeasureInd");

    OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind_local_nonprim = NULL;
    if (los_nlos_measure_ind) {
    los_nlos_measure_ind_local_nonprim = OpenAPI_los_nlos_measure_ind_parseFromJSON(los_nlos_measure_ind);
    }

    cJSON *up_cum_evt_rpt_criteria = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "upCumEvtRptCriteria");

    OpenAPI_up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_nonprim = NULL;
    if (up_cum_evt_rpt_criteria) {
    up_cum_evt_rpt_criteria_local_nonprim = OpenAPI_up_cum_evt_rpt_criteria_parseFromJSON(up_cum_evt_rpt_criteria);
    }

    cJSON *lcs_upp_exist_ind = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "lcsUppExistInd");

    if (lcs_upp_exist_ind) {
    if (!cJSON_IsBool(lcs_upp_exist_ind)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [lcs_upp_exist_ind]");
        goto end;
    }
    }

    cJSON *src_lmf_routing_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "srcLmfRoutingInfo");

    if (src_lmf_routing_info) {
    if (!cJSON_IsString(src_lmf_routing_info)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [src_lmf_routing_info]");
        goto end;
    }
    }

    cJSON *extended_facility_ind = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "extendedFacilityInd");

    if (extended_facility_ind) {
    if (!cJSON_IsBool(extended_facility_ind)) {
        ogs_error("OpenAPI_loc_context_data_parseFromJSON() failed [extended_facility_ind]");
        goto end;
    }
    }

    loc_context_data_local_var = OpenAPI_loc_context_data_create (
        ogs_strdup(amf_id->valuestring),
        location_qo_s ? location_qo_s_local_nonprim : NULL,
        supported_gad_shapes ? supported_gad_shapesList : NULL,
        supi ? ogs_strdup(supi->valuestring) : NULL,
        gpsi ? ogs_strdup(gpsi->valuestring) : NULL,
        add_loc_context_list ? add_loc_context_listList : NULL,
        ldr_type_local_nonprim,
        ogs_strdup(hgmlc_call_back_uri->valuestring),
        ogs_strdup(ldr_reference->valuestring),
        periodic_event_info ? periodic_event_info_local_nonprim : NULL,
        area_event_info ? area_event_info_local_nonprim : NULL,
        motion_event_info ? motion_event_info_local_nonprim : NULL,
        event_report_message_local_nonprim,
        event_reporting_status ? event_reporting_status_local_nonprim : NULL,
        ue_location_info ? ue_location_info_local_nonprim : NULL,
        c_io_t5_gs_optimisation ? true : false,
        c_io_t5_gs_optimisation ? c_io_t5_gs_optimisation->valueint : 0,
        ecgi ? ecgi_local_nonprim : NULL,
        ncgi ? ncgi_local_nonprim : NULL,
        guami ? guami_local_nonprim : NULL,
        supported_features ? ogs_strdup(supported_features->valuestring) : NULL,
        ue_positioning_cap ? ue_positioning_cap->valueint : 0,
        ue_up_pos_caps ? ue_up_pos_capsList : NULL,
        scheduled_loc_time ? ogs_strdup(scheduled_loc_time->valuestring) : NULL,
        indoor_outdoor_ind ? indoor_outdoor_ind_local_nonprim : NULL,
        los_nlos_measure_ind ? los_nlos_measure_ind_local_nonprim : NULL,
        up_cum_evt_rpt_criteria ? up_cum_evt_rpt_criteria_local_nonprim : NULL,
        lcs_upp_exist_ind ? true : false,
        lcs_upp_exist_ind ? lcs_upp_exist_ind->valueint : 0,
        src_lmf_routing_info ? ogs_strdup(src_lmf_routing_info->valuestring) : NULL,
        extended_facility_ind ? true : false,
        extended_facility_ind ? extended_facility_ind->valueint : 0
    );

    return loc_context_data_local_var;
end:
    return NULL;
}

OpenAPI_loc_context_data_t *OpenAPI_loc_context_data_copy(OpenAPI_loc_context_data_t *dst, OpenAPI_loc_context_data_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_loc_context_data_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_loc_context_data_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_loc_context_data_free(dst);
    dst = OpenAPI_loc_context_data_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

