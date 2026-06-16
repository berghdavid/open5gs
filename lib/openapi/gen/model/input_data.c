
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_data.h"

OpenAPI_input_data_t *OpenAPI_input_data_create(
    OpenAPI_external_client_type_t *external_client_type,
    char *correlation_id,
    char *amf_id,
    OpenAPI_location_qo_s_t *location_qo_s,
    OpenAPI_list_t *supported_gad_shapes,
    char *supi,
    char *pei,
    char *gpsi,
    OpenAPI_list_t *requested_ranging_sl_result,
    OpenAPI_list_t *related_ues,
    OpenAPI_ecgi_t *ecgi,
    OpenAPI_ecgi_t *ecgi_on_second_node,
    OpenAPI_ncgi_t *ncgi,
    OpenAPI_ncgi_t *ncgi_on_second_node,
    OpenAPI_lcs_priority_t *priority,
    OpenAPI_velocity_requested_t *velocity_requested,
    OpenAPI_ue_lcs_capability_t *ue_lcs_cap,
    bool is_lcs_service_type,
    int lcs_service_type,
    OpenAPI_ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *lir_gmlc_call_back_uri,
    char *vgmlc_address,
    char *ldr_reference,
    char *lir_reference,
    OpenAPI_periodic_event_info_t *periodic_event_info,
    OpenAPI_area_event_info_t *area_event_info,
    OpenAPI_motion_event_info_t *motion_event_info,
    OpenAPI_list_t *reporting_access_types,
    OpenAPI_ue_connectivity_state_t *ue_connectivity_states,
    OpenAPI_ue_location_service_ind_t *ue_location_service_ind,
    OpenAPI_lcs_broadcast_assistance_types_data_t *mo_assistance_data_types,
    OpenAPI_ref_to_binary_data_t *lpp_message,
    OpenAPI_list_t *lpp_message_ext,
    char *supported_features,
    char ue_positioning_cap,
    OpenAPI_tnap_id_t *tnap_id,
    OpenAPI_twap_id_t *twap_id,
    bool is_ue_country_det_ind,
    int ue_country_det_ind,
    char *scheduled_loc_time,
    bool is_reliable_loc_req,
    int reliable_loc_req,
    OpenAPI_list_t *evt_rpt_allowed_areas,
    bool is_ue_unaware_ind,
    int ue_unaware_ind,
    bool is_intermediate_location_ind,
    int intermediate_location_ind,
    bool is_max_resp_time,
    int max_resp_time,
    OpenAPI_lp_hap_type_t *lp_hap_type,
    OpenAPI_list_t *ue_up_pos_caps,
    OpenAPI_reporting_ind_t *reporting_ind,
    OpenAPI_mbsr_info_t *mbsr_info,
    bool is_mwab_support_ind,
    int mwab_support_ind,
    OpenAPI_integrity_requirements_t *integrity_requirements,
    OpenAPI_up_loc_rep_addr_af_t *up_loc_rep_addr_af,
    OpenAPI_up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    OpenAPI_mapped_location_qo_s_eps_t *mapped_qo_s_eps,
    OpenAPI_additional_ue_info_t *additional_ue_info,
    bool is_coordinate_id,
    int coordinate_id,
    char ranging_sl_capability,
    OpenAPI_list_t *sl_positioning_capabilities,
    bool is_extended_facility_ind,
    int extended_facility_ind
)
{
    OpenAPI_input_data_t *input_data_local_var = ogs_malloc(sizeof(OpenAPI_input_data_t));
    ogs_assert(input_data_local_var);

    input_data_local_var->external_client_type = external_client_type;
    input_data_local_var->correlation_id = correlation_id;
    input_data_local_var->amf_id = amf_id;
    input_data_local_var->location_qo_s = location_qo_s;
    input_data_local_var->supported_gad_shapes = supported_gad_shapes;
    input_data_local_var->supi = supi;
    input_data_local_var->pei = pei;
    input_data_local_var->gpsi = gpsi;
    input_data_local_var->requested_ranging_sl_result = requested_ranging_sl_result;
    input_data_local_var->related_ues = related_ues;
    input_data_local_var->ecgi = ecgi;
    input_data_local_var->ecgi_on_second_node = ecgi_on_second_node;
    input_data_local_var->ncgi = ncgi;
    input_data_local_var->ncgi_on_second_node = ncgi_on_second_node;
    input_data_local_var->priority = priority;
    input_data_local_var->velocity_requested = velocity_requested;
    input_data_local_var->ue_lcs_cap = ue_lcs_cap;
    input_data_local_var->is_lcs_service_type = is_lcs_service_type;
    input_data_local_var->lcs_service_type = lcs_service_type;
    input_data_local_var->ldr_type = ldr_type;
    input_data_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
    input_data_local_var->lir_gmlc_call_back_uri = lir_gmlc_call_back_uri;
    input_data_local_var->vgmlc_address = vgmlc_address;
    input_data_local_var->ldr_reference = ldr_reference;
    input_data_local_var->lir_reference = lir_reference;
    input_data_local_var->periodic_event_info = periodic_event_info;
    input_data_local_var->area_event_info = area_event_info;
    input_data_local_var->motion_event_info = motion_event_info;
    input_data_local_var->reporting_access_types = reporting_access_types;
    input_data_local_var->ue_connectivity_states = ue_connectivity_states;
    input_data_local_var->ue_location_service_ind = ue_location_service_ind;
    input_data_local_var->mo_assistance_data_types = mo_assistance_data_types;
    input_data_local_var->lpp_message = lpp_message;
    input_data_local_var->lpp_message_ext = lpp_message_ext;
    input_data_local_var->supported_features = supported_features;
    input_data_local_var->ue_positioning_cap = ue_positioning_cap;
    input_data_local_var->tnap_id = tnap_id;
    input_data_local_var->twap_id = twap_id;
    input_data_local_var->is_ue_country_det_ind = is_ue_country_det_ind;
    input_data_local_var->ue_country_det_ind = ue_country_det_ind;
    input_data_local_var->scheduled_loc_time = scheduled_loc_time;
    input_data_local_var->is_reliable_loc_req = is_reliable_loc_req;
    input_data_local_var->reliable_loc_req = reliable_loc_req;
    input_data_local_var->evt_rpt_allowed_areas = evt_rpt_allowed_areas;
    input_data_local_var->is_ue_unaware_ind = is_ue_unaware_ind;
    input_data_local_var->ue_unaware_ind = ue_unaware_ind;
    input_data_local_var->is_intermediate_location_ind = is_intermediate_location_ind;
    input_data_local_var->intermediate_location_ind = intermediate_location_ind;
    input_data_local_var->is_max_resp_time = is_max_resp_time;
    input_data_local_var->max_resp_time = max_resp_time;
    input_data_local_var->lp_hap_type = lp_hap_type;
    input_data_local_var->ue_up_pos_caps = ue_up_pos_caps;
    input_data_local_var->reporting_ind = reporting_ind;
    input_data_local_var->mbsr_info = mbsr_info;
    input_data_local_var->is_mwab_support_ind = is_mwab_support_ind;
    input_data_local_var->mwab_support_ind = mwab_support_ind;
    input_data_local_var->integrity_requirements = integrity_requirements;
    input_data_local_var->up_loc_rep_addr_af = up_loc_rep_addr_af;
    input_data_local_var->up_cum_evt_rpt_criteria = up_cum_evt_rpt_criteria;
    input_data_local_var->mapped_qo_s_eps = mapped_qo_s_eps;
    input_data_local_var->additional_ue_info = additional_ue_info;
    input_data_local_var->is_coordinate_id = is_coordinate_id;
    input_data_local_var->coordinate_id = coordinate_id;
    input_data_local_var->ranging_sl_capability = ranging_sl_capability;
    input_data_local_var->sl_positioning_capabilities = sl_positioning_capabilities;
    input_data_local_var->is_extended_facility_ind = is_extended_facility_ind;
    input_data_local_var->extended_facility_ind = extended_facility_ind;

    return input_data_local_var;
}

void OpenAPI_input_data_free(OpenAPI_input_data_t *input_data)
{
    if (NULL == input_data) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_external_client_type_free(input_data->external_client_type);
    ogs_free(input_data->correlation_id);
    ogs_free(input_data->amf_id);
    OpenAPI_location_qo_s_free(input_data->location_qo_s);
    OpenAPI_list_for_each(input_data->supported_gad_shapes, node) {
        OpenAPI_supported_gad_shapes_free(node->data);
    }
    OpenAPI_list_free(input_data->supported_gad_shapes);
    ogs_free(input_data->supi);
    ogs_free(input_data->pei);
    ogs_free(input_data->gpsi);
    OpenAPI_list_for_each(input_data->requested_ranging_sl_result, node) {
        OpenAPI_ranging_sl_result_free(node->data);
    }
    OpenAPI_list_free(input_data->requested_ranging_sl_result);
    OpenAPI_list_for_each(input_data->related_ues, node) {
        OpenAPI_related_ue_free(node->data);
    }
    OpenAPI_list_free(input_data->related_ues);
    OpenAPI_ecgi_free(input_data->ecgi);
    OpenAPI_ecgi_free(input_data->ecgi_on_second_node);
    OpenAPI_ncgi_free(input_data->ncgi);
    OpenAPI_ncgi_free(input_data->ncgi_on_second_node);
    OpenAPI_lcs_priority_free(input_data->priority);
    OpenAPI_velocity_requested_free(input_data->velocity_requested);
    OpenAPI_ue_lcs_capability_free(input_data->ue_lcs_cap);
    OpenAPI_ldr_type_free(input_data->ldr_type);
    ogs_free(input_data->hgmlc_call_back_uri);
    ogs_free(input_data->lir_gmlc_call_back_uri);
    ogs_free(input_data->vgmlc_address);
    ogs_free(input_data->ldr_reference);
    ogs_free(input_data->lir_reference);
    OpenAPI_periodic_event_info_free(input_data->periodic_event_info);
    OpenAPI_area_event_info_free(input_data->area_event_info);
    OpenAPI_motion_event_info_free(input_data->motion_event_info);
    OpenAPI_list_for_each(input_data->reporting_access_types, node) {
        OpenAPI_reporting_access_type_free(node->data);
    }
    OpenAPI_list_free(input_data->reporting_access_types);
    OpenAPI_ue_connectivity_state_free(input_data->ue_connectivity_states);
    OpenAPI_ue_location_service_ind_free(input_data->ue_location_service_ind);
    OpenAPI_lcs_broadcast_assistance_types_data_free(input_data->mo_assistance_data_types);
    OpenAPI_ref_to_binary_data_free(input_data->lpp_message);
    OpenAPI_list_for_each(input_data->lpp_message_ext, node) {
        OpenAPI_ref_to_binary_data_free(node->data);
    }
    OpenAPI_list_free(input_data->lpp_message_ext);
    ogs_free(input_data->supported_features);
    OpenAPI_tnap_id_free(input_data->tnap_id);
    OpenAPI_twap_id_free(input_data->twap_id);
    ogs_free(input_data->scheduled_loc_time);
    OpenAPI_list_for_each(input_data->evt_rpt_allowed_areas, node) {
        OpenAPI_reporting_area_free(node->data);
    }
    OpenAPI_list_free(input_data->evt_rpt_allowed_areas);
    OpenAPI_lp_hap_type_free(input_data->lp_hap_type);
    OpenAPI_list_for_each(input_data->ue_up_pos_caps, node) {
        OpenAPI_ue_up_positioning_capabilities_free(node->data);
    }
    OpenAPI_list_free(input_data->ue_up_pos_caps);
    OpenAPI_reporting_ind_free(input_data->reporting_ind);
    OpenAPI_mbsr_info_free(input_data->mbsr_info);
    OpenAPI_integrity_requirements_free(input_data->integrity_requirements);
    OpenAPI_up_loc_rep_addr_af_free(input_data->up_loc_rep_addr_af);
    OpenAPI_up_cum_evt_rpt_criteria_free(input_data->up_cum_evt_rpt_criteria);
    OpenAPI_mapped_location_qo_s_eps_free(input_data->mapped_qo_s_eps);
    OpenAPI_additional_ue_info_free(input_data->additional_ue_info);
    OpenAPI_list_for_each(input_data->sl_positioning_capabilities, node) {
        OpenAPI_sl_positioning_capability_free(node->data);
    }
    OpenAPI_list_free(input_data->sl_positioning_capabilities);
    ogs_free(input_data);
}

cJSON *OpenAPI_input_data_convertToJSON(OpenAPI_input_data_t *input_data)
{
    cJSON *item = NULL;

    if (input_data == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [InputData]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (input_data->external_client_type) {
    cJSON *external_client_type_local_JSON = OpenAPI_external_client_type_convertToJSON(input_data->external_client_type);
    if (external_client_type_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [external_client_type]");
        goto end;
    }
    cJSON_AddItemToObject(item, "externalClientType", external_client_type_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [external_client_type]");
        goto end;
    }
    }

    if (input_data->correlation_id) {
    if (cJSON_AddStringToObject(item, "correlationID", input_data->correlation_id) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [correlation_id]");
        goto end;
    }
    }

    if (input_data->amf_id) {
    if (cJSON_AddStringToObject(item, "amfId", input_data->amf_id) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [amf_id]");
        goto end;
    }
    }

    if (input_data->location_qo_s) {
    cJSON *location_qo_s_local_JSON = OpenAPI_location_qo_s_convertToJSON(input_data->location_qo_s);
    if (location_qo_s_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [location_qo_s]");
        goto end;
    }
    cJSON_AddItemToObject(item, "locationQoS", location_qo_s_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [location_qo_s]");
        goto end;
    }
    }

    if (input_data->supported_gad_shapes) {
    cJSON *supported_gad_shapesList = cJSON_AddArrayToObject(item, "supportedGADShapes");
    if (supported_gad_shapesList == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [supported_gad_shapes]");
        goto end;
    }

    OpenAPI_lnode_t *supported_gad_shapes_node;
    if (input_data->supported_gad_shapes) {
        OpenAPI_list_for_each(input_data->supported_gad_shapes, supported_gad_shapes_node) {
            cJSON *itemLocal = OpenAPI_supported_gad_shapes_convertToJSON(supported_gad_shapes_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_input_data_convertToJSON() failed [supported_gad_shapes]");
                goto end;
            }
            cJSON_AddItemToArray(supported_gad_shapesList, itemLocal);
        }
    }
    }

    if (input_data->supi) {
    if (cJSON_AddStringToObject(item, "supi", input_data->supi) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [supi]");
        goto end;
    }
    }

    if (input_data->pei) {
    if (cJSON_AddStringToObject(item, "pei", input_data->pei) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [pei]");
        goto end;
    }
    }

    if (input_data->gpsi) {
    if (cJSON_AddStringToObject(item, "gpsi", input_data->gpsi) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [gpsi]");
        goto end;
    }
    }

    if (input_data->requested_ranging_sl_result) {
    cJSON *requested_ranging_sl_resultList = cJSON_AddArrayToObject(item, "requestedRangingSlResult");
    if (requested_ranging_sl_resultList == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [requested_ranging_sl_result]");
        goto end;
    }

    OpenAPI_lnode_t *requested_ranging_sl_result_node;
    if (input_data->requested_ranging_sl_result) {
        OpenAPI_list_for_each(input_data->requested_ranging_sl_result, requested_ranging_sl_result_node) {
            cJSON *itemLocal = OpenAPI_ranging_sl_result_convertToJSON(requested_ranging_sl_result_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_input_data_convertToJSON() failed [requested_ranging_sl_result]");
                goto end;
            }
            cJSON_AddItemToArray(requested_ranging_sl_resultList, itemLocal);
        }
    }
    }

    if (input_data->related_ues) {
    cJSON *related_uesList = cJSON_AddArrayToObject(item, "relatedUes");
    if (related_uesList == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [related_ues]");
        goto end;
    }

    OpenAPI_lnode_t *related_ues_node;
    if (input_data->related_ues) {
        OpenAPI_list_for_each(input_data->related_ues, related_ues_node) {
            cJSON *itemLocal = OpenAPI_related_ue_convertToJSON(related_ues_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_input_data_convertToJSON() failed [related_ues]");
                goto end;
            }
            cJSON_AddItemToArray(related_uesList, itemLocal);
        }
    }
    }

    if (input_data->ecgi) {
    cJSON *ecgi_local_JSON = OpenAPI_ecgi_convertToJSON(input_data->ecgi);
    if (ecgi_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ecgi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ecgi]");
        goto end;
    }
    }

    if (input_data->ecgi_on_second_node) {
    cJSON *ecgi_on_second_node_local_JSON = OpenAPI_ecgi_convertToJSON(input_data->ecgi_on_second_node);
    if (ecgi_on_second_node_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ecgi_on_second_node]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ecgiOnSecondNode", ecgi_on_second_node_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ecgi_on_second_node]");
        goto end;
    }
    }

    if (input_data->ncgi) {
    cJSON *ncgi_local_JSON = OpenAPI_ncgi_convertToJSON(input_data->ncgi);
    if (ncgi_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ncgi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ncgi]");
        goto end;
    }
    }

    if (input_data->ncgi_on_second_node) {
    cJSON *ncgi_on_second_node_local_JSON = OpenAPI_ncgi_convertToJSON(input_data->ncgi_on_second_node);
    if (ncgi_on_second_node_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ncgi_on_second_node]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ncgiOnSecondNode", ncgi_on_second_node_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ncgi_on_second_node]");
        goto end;
    }
    }

    if (input_data->priority) {
    cJSON *priority_local_JSON = OpenAPI_lcs_priority_convertToJSON(input_data->priority);
    if (priority_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [priority]");
        goto end;
    }
    cJSON_AddItemToObject(item, "priority", priority_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [priority]");
        goto end;
    }
    }

    if (input_data->velocity_requested) {
    cJSON *velocity_requested_local_JSON = OpenAPI_velocity_requested_convertToJSON(input_data->velocity_requested);
    if (velocity_requested_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [velocity_requested]");
        goto end;
    }
    cJSON_AddItemToObject(item, "velocityRequested", velocity_requested_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [velocity_requested]");
        goto end;
    }
    }

    if (input_data->ue_lcs_cap) {
    cJSON *ue_lcs_cap_local_JSON = OpenAPI_ue_lcs_capability_convertToJSON(input_data->ue_lcs_cap);
    if (ue_lcs_cap_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_lcs_cap]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ueLcsCap", ue_lcs_cap_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_lcs_cap]");
        goto end;
    }
    }

    if (input_data->is_lcs_service_type) {
    if (cJSON_AddNumberToObject(item, "lcsServiceType", input_data->lcs_service_type) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [lcs_service_type]");
        goto end;
    }
    }

    if (input_data->ldr_type) {
    cJSON *ldr_type_local_JSON = OpenAPI_ldr_type_convertToJSON(input_data->ldr_type);
    if (ldr_type_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ldr_type]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ldrType", ldr_type_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ldr_type]");
        goto end;
    }
    }

    if (input_data->hgmlc_call_back_uri) {
    if (cJSON_AddStringToObject(item, "hgmlcCallBackURI", input_data->hgmlc_call_back_uri) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [hgmlc_call_back_uri]");
        goto end;
    }
    }

    if (input_data->lir_gmlc_call_back_uri) {
    if (cJSON_AddStringToObject(item, "lirGmlcCallBackUri", input_data->lir_gmlc_call_back_uri) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [lir_gmlc_call_back_uri]");
        goto end;
    }
    }

    if (input_data->vgmlc_address) {
    if (cJSON_AddStringToObject(item, "vgmlcAddress", input_data->vgmlc_address) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [vgmlc_address]");
        goto end;
    }
    }

    if (input_data->ldr_reference) {
    if (cJSON_AddStringToObject(item, "ldrReference", input_data->ldr_reference) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ldr_reference]");
        goto end;
    }
    }

    if (input_data->lir_reference) {
    if (cJSON_AddStringToObject(item, "lirReference", input_data->lir_reference) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [lir_reference]");
        goto end;
    }
    }

    if (input_data->periodic_event_info) {
    cJSON *periodic_event_info_local_JSON = OpenAPI_periodic_event_info_convertToJSON(input_data->periodic_event_info);
    if (periodic_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [periodic_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "periodicEventInfo", periodic_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [periodic_event_info]");
        goto end;
    }
    }

    if (input_data->area_event_info) {
    cJSON *area_event_info_local_JSON = OpenAPI_area_event_info_convertToJSON(input_data->area_event_info);
    if (area_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [area_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "areaEventInfo", area_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [area_event_info]");
        goto end;
    }
    }

    if (input_data->motion_event_info) {
    cJSON *motion_event_info_local_JSON = OpenAPI_motion_event_info_convertToJSON(input_data->motion_event_info);
    if (motion_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [motion_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "motionEventInfo", motion_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [motion_event_info]");
        goto end;
    }
    }

    if (input_data->reporting_access_types) {
    cJSON *reporting_access_typesList = cJSON_AddArrayToObject(item, "reportingAccessTypes");
    if (reporting_access_typesList == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [reporting_access_types]");
        goto end;
    }

    OpenAPI_lnode_t *reporting_access_types_node;
    if (input_data->reporting_access_types) {
        OpenAPI_list_for_each(input_data->reporting_access_types, reporting_access_types_node) {
            cJSON *itemLocal = OpenAPI_reporting_access_type_convertToJSON(reporting_access_types_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_input_data_convertToJSON() failed [reporting_access_types]");
                goto end;
            }
            cJSON_AddItemToArray(reporting_access_typesList, itemLocal);
        }
    }
    }

    if (input_data->ue_connectivity_states) {
    cJSON *ue_connectivity_states_local_JSON = OpenAPI_ue_connectivity_state_convertToJSON(input_data->ue_connectivity_states);
    if (ue_connectivity_states_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_connectivity_states]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ueConnectivityStates", ue_connectivity_states_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_connectivity_states]");
        goto end;
    }
    }

    if (input_data->ue_location_service_ind) {
    cJSON *ue_location_service_ind_local_JSON = OpenAPI_ue_location_service_ind_convertToJSON(input_data->ue_location_service_ind);
    if (ue_location_service_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_location_service_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ueLocationServiceInd", ue_location_service_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_location_service_ind]");
        goto end;
    }
    }

    if (input_data->mo_assistance_data_types) {
    cJSON *mo_assistance_data_types_local_JSON = OpenAPI_lcs_broadcast_assistance_types_data_convertToJSON(input_data->mo_assistance_data_types);
    if (mo_assistance_data_types_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [mo_assistance_data_types]");
        goto end;
    }
    cJSON_AddItemToObject(item, "moAssistanceDataTypes", mo_assistance_data_types_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [mo_assistance_data_types]");
        goto end;
    }
    }

    if (input_data->lpp_message) {
    cJSON *lpp_message_local_JSON = OpenAPI_ref_to_binary_data_convertToJSON(input_data->lpp_message);
    if (lpp_message_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [lpp_message]");
        goto end;
    }
    cJSON_AddItemToObject(item, "lppMessage", lpp_message_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [lpp_message]");
        goto end;
    }
    }

    if (input_data->lpp_message_ext) {
    cJSON *lpp_message_extList = cJSON_AddArrayToObject(item, "lppMessageExt");
    if (lpp_message_extList == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [lpp_message_ext]");
        goto end;
    }

    OpenAPI_lnode_t *lpp_message_ext_node;
    if (input_data->lpp_message_ext) {
        OpenAPI_list_for_each(input_data->lpp_message_ext, lpp_message_ext_node) {
            cJSON *itemLocal = OpenAPI_ref_to_binary_data_convertToJSON(lpp_message_ext_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_input_data_convertToJSON() failed [lpp_message_ext]");
                goto end;
            }
            cJSON_AddItemToArray(lpp_message_extList, itemLocal);
        }
    }
    }

    if (input_data->supported_features) {
    if (cJSON_AddStringToObject(item, "supportedFeatures", input_data->supported_features) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [supported_features]");
        goto end;
    }
    }

    if (input_data->ue_positioning_cap) {
    if (cJSON_AddNumberToObject(item, "uePositioningCap", input_data->ue_positioning_cap) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_positioning_cap]");
        goto end;
    }
    }

    if (input_data->tnap_id) {
    cJSON *tnap_id_local_JSON = OpenAPI_tnap_id_convertToJSON(input_data->tnap_id);
    if (tnap_id_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [tnap_id]");
        goto end;
    }
    cJSON_AddItemToObject(item, "tnapId", tnap_id_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [tnap_id]");
        goto end;
    }
    }

    if (input_data->twap_id) {
    cJSON *twap_id_local_JSON = OpenAPI_twap_id_convertToJSON(input_data->twap_id);
    if (twap_id_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [twap_id]");
        goto end;
    }
    cJSON_AddItemToObject(item, "twapId", twap_id_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [twap_id]");
        goto end;
    }
    }

    if (input_data->is_ue_country_det_ind) {
    if (cJSON_AddBoolToObject(item, "ueCountryDetInd", input_data->ue_country_det_ind) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_country_det_ind]");
        goto end;
    }
    }

    if (input_data->scheduled_loc_time) {
    if (cJSON_AddStringToObject(item, "scheduledLocTime", input_data->scheduled_loc_time) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [scheduled_loc_time]");
        goto end;
    }
    }

    if (input_data->is_reliable_loc_req) {
    if (cJSON_AddBoolToObject(item, "reliableLocReq", input_data->reliable_loc_req) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [reliable_loc_req]");
        goto end;
    }
    }

    if (input_data->evt_rpt_allowed_areas) {
    cJSON *evt_rpt_allowed_areasList = cJSON_AddArrayToObject(item, "evtRptAllowedAreas");
    if (evt_rpt_allowed_areasList == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [evt_rpt_allowed_areas]");
        goto end;
    }

    OpenAPI_lnode_t *evt_rpt_allowed_areas_node;
    if (input_data->evt_rpt_allowed_areas) {
        OpenAPI_list_for_each(input_data->evt_rpt_allowed_areas, evt_rpt_allowed_areas_node) {
            cJSON *itemLocal = OpenAPI_reporting_area_convertToJSON(evt_rpt_allowed_areas_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_input_data_convertToJSON() failed [evt_rpt_allowed_areas]");
                goto end;
            }
            cJSON_AddItemToArray(evt_rpt_allowed_areasList, itemLocal);
        }
    }
    }

    if (input_data->is_ue_unaware_ind) {
    if (cJSON_AddBoolToObject(item, "ueUnawareInd", input_data->ue_unaware_ind) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_unaware_ind]");
        goto end;
    }
    }

    if (input_data->is_intermediate_location_ind) {
    if (cJSON_AddBoolToObject(item, "intermediateLocationInd", input_data->intermediate_location_ind) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [intermediate_location_ind]");
        goto end;
    }
    }

    if (input_data->is_max_resp_time) {
    if (cJSON_AddNumberToObject(item, "maxRespTime", input_data->max_resp_time) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [max_resp_time]");
        goto end;
    }
    }

    if (input_data->lp_hap_type) {
    cJSON *lp_hap_type_local_JSON = OpenAPI_lp_hap_type_convertToJSON(input_data->lp_hap_type);
    if (lp_hap_type_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [lp_hap_type]");
        goto end;
    }
    cJSON_AddItemToObject(item, "lpHapType", lp_hap_type_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [lp_hap_type]");
        goto end;
    }
    }

    if (input_data->ue_up_pos_caps) {
    cJSON *ue_up_pos_capsList = cJSON_AddArrayToObject(item, "ueUpPosCaps");
    if (ue_up_pos_capsList == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_up_pos_caps]");
        goto end;
    }

    OpenAPI_lnode_t *ue_up_pos_caps_node;
    if (input_data->ue_up_pos_caps) {
        OpenAPI_list_for_each(input_data->ue_up_pos_caps, ue_up_pos_caps_node) {
            cJSON *itemLocal = OpenAPI_ue_up_positioning_capabilities_convertToJSON(ue_up_pos_caps_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_input_data_convertToJSON() failed [ue_up_pos_caps]");
                goto end;
            }
            cJSON_AddItemToArray(ue_up_pos_capsList, itemLocal);
        }
    }
    }

    if (input_data->reporting_ind) {
    cJSON *reporting_ind_local_JSON = OpenAPI_reporting_ind_convertToJSON(input_data->reporting_ind);
    if (reporting_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [reporting_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "reportingInd", reporting_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [reporting_ind]");
        goto end;
    }
    }

    if (input_data->mbsr_info) {
    cJSON *mbsr_info_local_JSON = OpenAPI_mbsr_info_convertToJSON(input_data->mbsr_info);
    if (mbsr_info_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [mbsr_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "mbsrInfo", mbsr_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [mbsr_info]");
        goto end;
    }
    }

    if (input_data->is_mwab_support_ind) {
    if (cJSON_AddBoolToObject(item, "mwabSupportInd", input_data->mwab_support_ind) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [mwab_support_ind]");
        goto end;
    }
    }

    if (input_data->integrity_requirements) {
    cJSON *integrity_requirements_local_JSON = OpenAPI_integrity_requirements_convertToJSON(input_data->integrity_requirements);
    if (integrity_requirements_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [integrity_requirements]");
        goto end;
    }
    cJSON_AddItemToObject(item, "integrityRequirements", integrity_requirements_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [integrity_requirements]");
        goto end;
    }
    }

    if (input_data->up_loc_rep_addr_af) {
    cJSON *up_loc_rep_addr_af_local_JSON = OpenAPI_up_loc_rep_addr_af_convertToJSON(input_data->up_loc_rep_addr_af);
    if (up_loc_rep_addr_af_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [up_loc_rep_addr_af]");
        goto end;
    }
    cJSON_AddItemToObject(item, "upLocRepAddrAf", up_loc_rep_addr_af_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [up_loc_rep_addr_af]");
        goto end;
    }
    }

    if (input_data->up_cum_evt_rpt_criteria) {
    cJSON *up_cum_evt_rpt_criteria_local_JSON = OpenAPI_up_cum_evt_rpt_criteria_convertToJSON(input_data->up_cum_evt_rpt_criteria);
    if (up_cum_evt_rpt_criteria_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [up_cum_evt_rpt_criteria]");
        goto end;
    }
    cJSON_AddItemToObject(item, "upCumEvtRptCriteria", up_cum_evt_rpt_criteria_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [up_cum_evt_rpt_criteria]");
        goto end;
    }
    }

    if (input_data->mapped_qo_s_eps) {
    cJSON *mapped_qo_s_eps_local_JSON = OpenAPI_mapped_location_qo_s_eps_convertToJSON(input_data->mapped_qo_s_eps);
    if (mapped_qo_s_eps_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [mapped_qo_s_eps]");
        goto end;
    }
    cJSON_AddItemToObject(item, "mappedQoSEps", mapped_qo_s_eps_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [mapped_qo_s_eps]");
        goto end;
    }
    }

    if (input_data->additional_ue_info) {
    cJSON *additional_ue_info_local_JSON = OpenAPI_additional_ue_info_convertToJSON(input_data->additional_ue_info);
    if (additional_ue_info_local_JSON == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [additional_ue_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "additionalUeInfo", additional_ue_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [additional_ue_info]");
        goto end;
    }
    }

    if (input_data->is_coordinate_id) {
    if (cJSON_AddNumberToObject(item, "coordinateID", input_data->coordinate_id) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [coordinate_id]");
        goto end;
    }
    }

    if (input_data->ranging_sl_capability) {
    if (cJSON_AddNumberToObject(item, "rangingSlCapability", input_data->ranging_sl_capability) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [ranging_sl_capability]");
        goto end;
    }
    }

    if (input_data->sl_positioning_capabilities) {
    cJSON *sl_positioning_capabilitiesList = cJSON_AddArrayToObject(item, "slPositioningCapabilities");
    if (sl_positioning_capabilitiesList == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [sl_positioning_capabilities]");
        goto end;
    }

    OpenAPI_lnode_t *sl_positioning_capabilities_node;
    if (input_data->sl_positioning_capabilities) {
        OpenAPI_list_for_each(input_data->sl_positioning_capabilities, sl_positioning_capabilities_node) {
            cJSON *itemLocal = OpenAPI_sl_positioning_capability_convertToJSON(sl_positioning_capabilities_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_input_data_convertToJSON() failed [sl_positioning_capabilities]");
                goto end;
            }
            cJSON_AddItemToArray(sl_positioning_capabilitiesList, itemLocal);
        }
    }
    }

    if (input_data->is_extended_facility_ind) {
    if (cJSON_AddBoolToObject(item, "extendedFacilityInd", input_data->extended_facility_ind) == NULL) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed [extended_facility_ind]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_input_data_t *OpenAPI_input_data_parseFromJSON(cJSON *input_dataJSON)
{
    OpenAPI_input_data_t *input_data_local_var = NULL;
    cJSON *external_client_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "externalClientType");

    OpenAPI_external_client_type_t *external_client_type_local_nonprim = NULL;
    if (external_client_type) {
    external_client_type_local_nonprim = OpenAPI_external_client_type_parseFromJSON(external_client_type);
    }

    cJSON *correlation_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "correlationID");

    if (correlation_id) {
    if (!cJSON_IsString(correlation_id)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [correlation_id]");
        goto end;
    }
    }

    cJSON *amf_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "amfId");

    if (amf_id) {
    if (!cJSON_IsString(amf_id)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [amf_id]");
        goto end;
    }
    }

    cJSON *location_qo_s = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "locationQoS");

    OpenAPI_location_qo_s_t *location_qo_s_local_nonprim = NULL;
    if (location_qo_s) {
    location_qo_s_local_nonprim = OpenAPI_location_qo_s_parseFromJSON(location_qo_s);
    }

    cJSON *supported_gad_shapes = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "supportedGADShapes");

    OpenAPI_list_t *supported_gad_shapesList;
    if (supported_gad_shapes) {
    cJSON *supported_gad_shapes_local_nonprimitive;
    if (!cJSON_IsArray(supported_gad_shapes)){
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [supported_gad_shapes]");
        goto end;
    }

    supported_gad_shapesList = OpenAPI_list_create();

    cJSON_ArrayForEach(supported_gad_shapes_local_nonprimitive, supported_gad_shapes ) {
        if (!cJSON_IsObject(supported_gad_shapes_local_nonprimitive)) {
            ogs_error("OpenAPI_input_data_parseFromJSON() failed [supported_gad_shapes]");
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

    cJSON *supi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "supi");

    if (supi) {
    if (!cJSON_IsString(supi)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [supi]");
        goto end;
    }
    }

    cJSON *pei = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "pei");

    if (pei) {
    if (!cJSON_IsString(pei)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [pei]");
        goto end;
    }
    }

    cJSON *gpsi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "gpsi");

    if (gpsi) {
    if (!cJSON_IsString(gpsi)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [gpsi]");
        goto end;
    }
    }

    cJSON *requested_ranging_sl_result = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "requestedRangingSlResult");

    OpenAPI_list_t *requested_ranging_sl_resultList;
    if (requested_ranging_sl_result) {
    cJSON *requested_ranging_sl_result_local_nonprimitive;
    if (!cJSON_IsArray(requested_ranging_sl_result)){
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [requested_ranging_sl_result]");
        goto end;
    }

    requested_ranging_sl_resultList = OpenAPI_list_create();

    cJSON_ArrayForEach(requested_ranging_sl_result_local_nonprimitive, requested_ranging_sl_result ) {
        if (!cJSON_IsObject(requested_ranging_sl_result_local_nonprimitive)) {
            ogs_error("OpenAPI_input_data_parseFromJSON() failed [requested_ranging_sl_result]");
            goto end;
        }
        OpenAPI_ranging_sl_result_t *requested_ranging_sl_resultItem = OpenAPI_ranging_sl_result_parseFromJSON(requested_ranging_sl_result_local_nonprimitive);

        if (!requested_ranging_sl_resultItem) {
            ogs_error("No requested_ranging_sl_resultItem");
            OpenAPI_list_free(requested_ranging_sl_resultList);
            goto end;
        }

        OpenAPI_list_add(requested_ranging_sl_resultList, requested_ranging_sl_resultItem);
    }
    }

    cJSON *related_ues = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "relatedUes");

    OpenAPI_list_t *related_uesList;
    if (related_ues) {
    cJSON *related_ues_local_nonprimitive;
    if (!cJSON_IsArray(related_ues)){
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [related_ues]");
        goto end;
    }

    related_uesList = OpenAPI_list_create();

    cJSON_ArrayForEach(related_ues_local_nonprimitive, related_ues ) {
        if (!cJSON_IsObject(related_ues_local_nonprimitive)) {
            ogs_error("OpenAPI_input_data_parseFromJSON() failed [related_ues]");
            goto end;
        }
        OpenAPI_related_ue_t *related_uesItem = OpenAPI_related_ue_parseFromJSON(related_ues_local_nonprimitive);

        if (!related_uesItem) {
            ogs_error("No related_uesItem");
            OpenAPI_list_free(related_uesList);
            goto end;
        }

        OpenAPI_list_add(related_uesList, related_uesItem);
    }
    }

    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ecgi");

    OpenAPI_ecgi_t *ecgi_local_nonprim = NULL;
    if (ecgi) {
    ecgi_local_nonprim = OpenAPI_ecgi_parseFromJSON(ecgi);
    }

    cJSON *ecgi_on_second_node = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ecgiOnSecondNode");

    OpenAPI_ecgi_t *ecgi_on_second_node_local_nonprim = NULL;
    if (ecgi_on_second_node) {
    ecgi_on_second_node_local_nonprim = OpenAPI_ecgi_parseFromJSON(ecgi_on_second_node);
    }

    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ncgi");

    OpenAPI_ncgi_t *ncgi_local_nonprim = NULL;
    if (ncgi) {
    ncgi_local_nonprim = OpenAPI_ncgi_parseFromJSON(ncgi);
    }

    cJSON *ncgi_on_second_node = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ncgiOnSecondNode");

    OpenAPI_ncgi_t *ncgi_on_second_node_local_nonprim = NULL;
    if (ncgi_on_second_node) {
    ncgi_on_second_node_local_nonprim = OpenAPI_ncgi_parseFromJSON(ncgi_on_second_node);
    }

    cJSON *priority = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "priority");

    OpenAPI_lcs_priority_t *priority_local_nonprim = NULL;
    if (priority) {
    priority_local_nonprim = OpenAPI_lcs_priority_parseFromJSON(priority);
    }

    cJSON *velocity_requested = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "velocityRequested");

    OpenAPI_velocity_requested_t *velocity_requested_local_nonprim = NULL;
    if (velocity_requested) {
    velocity_requested_local_nonprim = OpenAPI_velocity_requested_parseFromJSON(velocity_requested);
    }

    cJSON *ue_lcs_cap = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueLcsCap");

    OpenAPI_ue_lcs_capability_t *ue_lcs_cap_local_nonprim = NULL;
    if (ue_lcs_cap) {
    ue_lcs_cap_local_nonprim = OpenAPI_ue_lcs_capability_parseFromJSON(ue_lcs_cap);
    }

    cJSON *lcs_service_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lcsServiceType");

    if (lcs_service_type) {
    if (!cJSON_IsNumber(lcs_service_type)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [lcs_service_type]");
        goto end;
    }
    }

    cJSON *ldr_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ldrType");

    OpenAPI_ldr_type_t *ldr_type_local_nonprim = NULL;
    if (ldr_type) {
    ldr_type_local_nonprim = OpenAPI_ldr_type_parseFromJSON(ldr_type);
    }

    cJSON *hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "hgmlcCallBackURI");

    if (hgmlc_call_back_uri) {
    if (!cJSON_IsString(hgmlc_call_back_uri)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [hgmlc_call_back_uri]");
        goto end;
    }
    }

    cJSON *lir_gmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lirGmlcCallBackUri");

    if (lir_gmlc_call_back_uri) {
    if (!cJSON_IsString(lir_gmlc_call_back_uri)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [lir_gmlc_call_back_uri]");
        goto end;
    }
    }

    cJSON *vgmlc_address = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "vgmlcAddress");

    if (vgmlc_address) {
    if (!cJSON_IsString(vgmlc_address)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [vgmlc_address]");
        goto end;
    }
    }

    cJSON *ldr_reference = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ldrReference");

    if (ldr_reference) {
    if (!cJSON_IsString(ldr_reference)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [ldr_reference]");
        goto end;
    }
    }

    cJSON *lir_reference = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lirReference");

    if (lir_reference) {
    if (!cJSON_IsString(lir_reference)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [lir_reference]");
        goto end;
    }
    }

    cJSON *periodic_event_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "periodicEventInfo");

    OpenAPI_periodic_event_info_t *periodic_event_info_local_nonprim = NULL;
    if (periodic_event_info) {
    periodic_event_info_local_nonprim = OpenAPI_periodic_event_info_parseFromJSON(periodic_event_info);
    }

    cJSON *area_event_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "areaEventInfo");

    OpenAPI_area_event_info_t *area_event_info_local_nonprim = NULL;
    if (area_event_info) {
    area_event_info_local_nonprim = OpenAPI_area_event_info_parseFromJSON(area_event_info);
    }

    cJSON *motion_event_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "motionEventInfo");

    OpenAPI_motion_event_info_t *motion_event_info_local_nonprim = NULL;
    if (motion_event_info) {
    motion_event_info_local_nonprim = OpenAPI_motion_event_info_parseFromJSON(motion_event_info);
    }

    cJSON *reporting_access_types = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "reportingAccessTypes");

    OpenAPI_list_t *reporting_access_typesList;
    if (reporting_access_types) {
    cJSON *reporting_access_types_local_nonprimitive;
    if (!cJSON_IsArray(reporting_access_types)){
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [reporting_access_types]");
        goto end;
    }

    reporting_access_typesList = OpenAPI_list_create();

    cJSON_ArrayForEach(reporting_access_types_local_nonprimitive, reporting_access_types ) {
        if (!cJSON_IsObject(reporting_access_types_local_nonprimitive)) {
            ogs_error("OpenAPI_input_data_parseFromJSON() failed [reporting_access_types]");
            goto end;
        }
        OpenAPI_reporting_access_type_t *reporting_access_typesItem = OpenAPI_reporting_access_type_parseFromJSON(reporting_access_types_local_nonprimitive);

        if (!reporting_access_typesItem) {
            ogs_error("No reporting_access_typesItem");
            OpenAPI_list_free(reporting_access_typesList);
            goto end;
        }

        OpenAPI_list_add(reporting_access_typesList, reporting_access_typesItem);
    }
    }

    cJSON *ue_connectivity_states = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueConnectivityStates");

    OpenAPI_ue_connectivity_state_t *ue_connectivity_states_local_nonprim = NULL;
    if (ue_connectivity_states) {
    ue_connectivity_states_local_nonprim = OpenAPI_ue_connectivity_state_parseFromJSON(ue_connectivity_states);
    }

    cJSON *ue_location_service_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueLocationServiceInd");

    OpenAPI_ue_location_service_ind_t *ue_location_service_ind_local_nonprim = NULL;
    if (ue_location_service_ind) {
    ue_location_service_ind_local_nonprim = OpenAPI_ue_location_service_ind_parseFromJSON(ue_location_service_ind);
    }

    cJSON *mo_assistance_data_types = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "moAssistanceDataTypes");

    OpenAPI_lcs_broadcast_assistance_types_data_t *mo_assistance_data_types_local_nonprim = NULL;
    if (mo_assistance_data_types) {
    mo_assistance_data_types_local_nonprim = OpenAPI_lcs_broadcast_assistance_types_data_parseFromJSON(mo_assistance_data_types);
    }

    cJSON *lpp_message = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lppMessage");

    OpenAPI_ref_to_binary_data_t *lpp_message_local_nonprim = NULL;
    if (lpp_message) {
    lpp_message_local_nonprim = OpenAPI_ref_to_binary_data_parseFromJSON(lpp_message);
    }

    cJSON *lpp_message_ext = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lppMessageExt");

    OpenAPI_list_t *lpp_message_extList;
    if (lpp_message_ext) {
    cJSON *lpp_message_ext_local_nonprimitive;
    if (!cJSON_IsArray(lpp_message_ext)){
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [lpp_message_ext]");
        goto end;
    }

    lpp_message_extList = OpenAPI_list_create();

    cJSON_ArrayForEach(lpp_message_ext_local_nonprimitive, lpp_message_ext ) {
        if (!cJSON_IsObject(lpp_message_ext_local_nonprimitive)) {
            ogs_error("OpenAPI_input_data_parseFromJSON() failed [lpp_message_ext]");
            goto end;
        }
        OpenAPI_ref_to_binary_data_t *lpp_message_extItem = OpenAPI_ref_to_binary_data_parseFromJSON(lpp_message_ext_local_nonprimitive);

        if (!lpp_message_extItem) {
            ogs_error("No lpp_message_extItem");
            OpenAPI_list_free(lpp_message_extList);
            goto end;
        }

        OpenAPI_list_add(lpp_message_extList, lpp_message_extItem);
    }
    }

    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "supportedFeatures");

    if (supported_features) {
    if (!cJSON_IsString(supported_features)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [supported_features]");
        goto end;
    }
    }

    cJSON *ue_positioning_cap = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "uePositioningCap");

    if (ue_positioning_cap) {
    if (!cJSON_IsNumber(ue_positioning_cap)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [ue_positioning_cap]");
        goto end;
    }
    }

    cJSON *tnap_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "tnapId");

    OpenAPI_tnap_id_t *tnap_id_local_nonprim = NULL;
    if (tnap_id) {
    tnap_id_local_nonprim = OpenAPI_tnap_id_parseFromJSON(tnap_id);
    }

    cJSON *twap_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "twapId");

    OpenAPI_twap_id_t *twap_id_local_nonprim = NULL;
    if (twap_id) {
    twap_id_local_nonprim = OpenAPI_twap_id_parseFromJSON(twap_id);
    }

    cJSON *ue_country_det_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueCountryDetInd");

    if (ue_country_det_ind) {
    if (!cJSON_IsBool(ue_country_det_ind)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [ue_country_det_ind]");
        goto end;
    }
    }

    cJSON *scheduled_loc_time = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "scheduledLocTime");

    if (scheduled_loc_time) {
    if (!cJSON_IsString(scheduled_loc_time)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [scheduled_loc_time]");
        goto end;
    }
    }

    cJSON *reliable_loc_req = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "reliableLocReq");

    if (reliable_loc_req) {
    if (!cJSON_IsBool(reliable_loc_req)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [reliable_loc_req]");
        goto end;
    }
    }

    cJSON *evt_rpt_allowed_areas = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "evtRptAllowedAreas");

    OpenAPI_list_t *evt_rpt_allowed_areasList;
    if (evt_rpt_allowed_areas) {
    cJSON *evt_rpt_allowed_areas_local_nonprimitive;
    if (!cJSON_IsArray(evt_rpt_allowed_areas)){
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [evt_rpt_allowed_areas]");
        goto end;
    }

    evt_rpt_allowed_areasList = OpenAPI_list_create();

    cJSON_ArrayForEach(evt_rpt_allowed_areas_local_nonprimitive, evt_rpt_allowed_areas ) {
        if (!cJSON_IsObject(evt_rpt_allowed_areas_local_nonprimitive)) {
            ogs_error("OpenAPI_input_data_parseFromJSON() failed [evt_rpt_allowed_areas]");
            goto end;
        }
        OpenAPI_reporting_area_t *evt_rpt_allowed_areasItem = OpenAPI_reporting_area_parseFromJSON(evt_rpt_allowed_areas_local_nonprimitive);

        if (!evt_rpt_allowed_areasItem) {
            ogs_error("No evt_rpt_allowed_areasItem");
            OpenAPI_list_free(evt_rpt_allowed_areasList);
            goto end;
        }

        OpenAPI_list_add(evt_rpt_allowed_areasList, evt_rpt_allowed_areasItem);
    }
    }

    cJSON *ue_unaware_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueUnawareInd");

    if (ue_unaware_ind) {
    if (!cJSON_IsBool(ue_unaware_ind)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [ue_unaware_ind]");
        goto end;
    }
    }

    cJSON *intermediate_location_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "intermediateLocationInd");

    if (intermediate_location_ind) {
    if (!cJSON_IsBool(intermediate_location_ind)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [intermediate_location_ind]");
        goto end;
    }
    }

    cJSON *max_resp_time = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "maxRespTime");

    if (max_resp_time) {
    if (!cJSON_IsNumber(max_resp_time)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [max_resp_time]");
        goto end;
    }
    }

    cJSON *lp_hap_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lpHapType");

    OpenAPI_lp_hap_type_t *lp_hap_type_local_nonprim = NULL;
    if (lp_hap_type) {
    lp_hap_type_local_nonprim = OpenAPI_lp_hap_type_parseFromJSON(lp_hap_type);
    }

    cJSON *ue_up_pos_caps = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueUpPosCaps");

    OpenAPI_list_t *ue_up_pos_capsList;
    if (ue_up_pos_caps) {
    cJSON *ue_up_pos_caps_local_nonprimitive;
    if (!cJSON_IsArray(ue_up_pos_caps)){
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [ue_up_pos_caps]");
        goto end;
    }

    ue_up_pos_capsList = OpenAPI_list_create();

    cJSON_ArrayForEach(ue_up_pos_caps_local_nonprimitive, ue_up_pos_caps ) {
        if (!cJSON_IsObject(ue_up_pos_caps_local_nonprimitive)) {
            ogs_error("OpenAPI_input_data_parseFromJSON() failed [ue_up_pos_caps]");
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

    cJSON *reporting_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "reportingInd");

    OpenAPI_reporting_ind_t *reporting_ind_local_nonprim = NULL;
    if (reporting_ind) {
    reporting_ind_local_nonprim = OpenAPI_reporting_ind_parseFromJSON(reporting_ind);
    }

    cJSON *mbsr_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "mbsrInfo");

    OpenAPI_mbsr_info_t *mbsr_info_local_nonprim = NULL;
    if (mbsr_info) {
    mbsr_info_local_nonprim = OpenAPI_mbsr_info_parseFromJSON(mbsr_info);
    }

    cJSON *mwab_support_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "mwabSupportInd");

    if (mwab_support_ind) {
    if (!cJSON_IsBool(mwab_support_ind)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [mwab_support_ind]");
        goto end;
    }
    }

    cJSON *integrity_requirements = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "integrityRequirements");

    OpenAPI_integrity_requirements_t *integrity_requirements_local_nonprim = NULL;
    if (integrity_requirements) {
    integrity_requirements_local_nonprim = OpenAPI_integrity_requirements_parseFromJSON(integrity_requirements);
    }

    cJSON *up_loc_rep_addr_af = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "upLocRepAddrAf");

    OpenAPI_up_loc_rep_addr_af_t *up_loc_rep_addr_af_local_nonprim = NULL;
    if (up_loc_rep_addr_af) {
    up_loc_rep_addr_af_local_nonprim = OpenAPI_up_loc_rep_addr_af_parseFromJSON(up_loc_rep_addr_af);
    }

    cJSON *up_cum_evt_rpt_criteria = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "upCumEvtRptCriteria");

    OpenAPI_up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_nonprim = NULL;
    if (up_cum_evt_rpt_criteria) {
    up_cum_evt_rpt_criteria_local_nonprim = OpenAPI_up_cum_evt_rpt_criteria_parseFromJSON(up_cum_evt_rpt_criteria);
    }

    cJSON *mapped_qo_s_eps = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "mappedQoSEps");

    OpenAPI_mapped_location_qo_s_eps_t *mapped_qo_s_eps_local_nonprim = NULL;
    if (mapped_qo_s_eps) {
    mapped_qo_s_eps_local_nonprim = OpenAPI_mapped_location_qo_s_eps_parseFromJSON(mapped_qo_s_eps);
    }

    cJSON *additional_ue_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "additionalUeInfo");

    OpenAPI_additional_ue_info_t *additional_ue_info_local_nonprim = NULL;
    if (additional_ue_info) {
    additional_ue_info_local_nonprim = OpenAPI_additional_ue_info_parseFromJSON(additional_ue_info);
    }

    cJSON *coordinate_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "coordinateID");

    if (coordinate_id) {
    if (!cJSON_IsNumber(coordinate_id)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [coordinate_id]");
        goto end;
    }
    }

    cJSON *ranging_sl_capability = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "rangingSlCapability");

    if (ranging_sl_capability) {
    if (!cJSON_IsNumber(ranging_sl_capability)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [ranging_sl_capability]");
        goto end;
    }
    }

    cJSON *sl_positioning_capabilities = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "slPositioningCapabilities");

    OpenAPI_list_t *sl_positioning_capabilitiesList;
    if (sl_positioning_capabilities) {
    cJSON *sl_positioning_capabilities_local_nonprimitive;
    if (!cJSON_IsArray(sl_positioning_capabilities)){
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [sl_positioning_capabilities]");
        goto end;
    }

    sl_positioning_capabilitiesList = OpenAPI_list_create();

    cJSON_ArrayForEach(sl_positioning_capabilities_local_nonprimitive, sl_positioning_capabilities ) {
        if (!cJSON_IsObject(sl_positioning_capabilities_local_nonprimitive)) {
            ogs_error("OpenAPI_input_data_parseFromJSON() failed [sl_positioning_capabilities]");
            goto end;
        }
        OpenAPI_sl_positioning_capability_t *sl_positioning_capabilitiesItem = OpenAPI_sl_positioning_capability_parseFromJSON(sl_positioning_capabilities_local_nonprimitive);

        if (!sl_positioning_capabilitiesItem) {
            ogs_error("No sl_positioning_capabilitiesItem");
            OpenAPI_list_free(sl_positioning_capabilitiesList);
            goto end;
        }

        OpenAPI_list_add(sl_positioning_capabilitiesList, sl_positioning_capabilitiesItem);
    }
    }

    cJSON *extended_facility_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "extendedFacilityInd");

    if (extended_facility_ind) {
    if (!cJSON_IsBool(extended_facility_ind)) {
        ogs_error("OpenAPI_input_data_parseFromJSON() failed [extended_facility_ind]");
        goto end;
    }
    }

    input_data_local_var = OpenAPI_input_data_create (
        external_client_type ? external_client_type_local_nonprim : NULL,
        correlation_id ? ogs_strdup(correlation_id->valuestring) : NULL,
        amf_id ? ogs_strdup(amf_id->valuestring) : NULL,
        location_qo_s ? location_qo_s_local_nonprim : NULL,
        supported_gad_shapes ? supported_gad_shapesList : NULL,
        supi ? ogs_strdup(supi->valuestring) : NULL,
        pei ? ogs_strdup(pei->valuestring) : NULL,
        gpsi ? ogs_strdup(gpsi->valuestring) : NULL,
        requested_ranging_sl_result ? requested_ranging_sl_resultList : NULL,
        related_ues ? related_uesList : NULL,
        ecgi ? ecgi_local_nonprim : NULL,
        ecgi_on_second_node ? ecgi_on_second_node_local_nonprim : NULL,
        ncgi ? ncgi_local_nonprim : NULL,
        ncgi_on_second_node ? ncgi_on_second_node_local_nonprim : NULL,
        priority ? priority_local_nonprim : NULL,
        velocity_requested ? velocity_requested_local_nonprim : NULL,
        ue_lcs_cap ? ue_lcs_cap_local_nonprim : NULL,
        lcs_service_type ? true : false,
        lcs_service_type ? lcs_service_type->valuedouble : 0,
        ldr_type ? ldr_type_local_nonprim : NULL,
        hgmlc_call_back_uri ? ogs_strdup(hgmlc_call_back_uri->valuestring) : NULL,
        lir_gmlc_call_back_uri ? ogs_strdup(lir_gmlc_call_back_uri->valuestring) : NULL,
        vgmlc_address ? ogs_strdup(vgmlc_address->valuestring) : NULL,
        ldr_reference ? ogs_strdup(ldr_reference->valuestring) : NULL,
        lir_reference ? ogs_strdup(lir_reference->valuestring) : NULL,
        periodic_event_info ? periodic_event_info_local_nonprim : NULL,
        area_event_info ? area_event_info_local_nonprim : NULL,
        motion_event_info ? motion_event_info_local_nonprim : NULL,
        reporting_access_types ? reporting_access_typesList : NULL,
        ue_connectivity_states ? ue_connectivity_states_local_nonprim : NULL,
        ue_location_service_ind ? ue_location_service_ind_local_nonprim : NULL,
        mo_assistance_data_types ? mo_assistance_data_types_local_nonprim : NULL,
        lpp_message ? lpp_message_local_nonprim : NULL,
        lpp_message_ext ? lpp_message_extList : NULL,
        supported_features ? ogs_strdup(supported_features->valuestring) : NULL,
        ue_positioning_cap ? ue_positioning_cap->valueint : 0,
        tnap_id ? tnap_id_local_nonprim : NULL,
        twap_id ? twap_id_local_nonprim : NULL,
        ue_country_det_ind ? true : false,
        ue_country_det_ind ? ue_country_det_ind->valueint : 0,
        scheduled_loc_time ? ogs_strdup(scheduled_loc_time->valuestring) : NULL,
        reliable_loc_req ? true : false,
        reliable_loc_req ? reliable_loc_req->valueint : 0,
        evt_rpt_allowed_areas ? evt_rpt_allowed_areasList : NULL,
        ue_unaware_ind ? true : false,
        ue_unaware_ind ? ue_unaware_ind->valueint : 0,
        intermediate_location_ind ? true : false,
        intermediate_location_ind ? intermediate_location_ind->valueint : 0,
        max_resp_time ? true : false,
        max_resp_time ? max_resp_time->valuedouble : 0,
        lp_hap_type ? lp_hap_type_local_nonprim : NULL,
        ue_up_pos_caps ? ue_up_pos_capsList : NULL,
        reporting_ind ? reporting_ind_local_nonprim : NULL,
        mbsr_info ? mbsr_info_local_nonprim : NULL,
        mwab_support_ind ? true : false,
        mwab_support_ind ? mwab_support_ind->valueint : 0,
        integrity_requirements ? integrity_requirements_local_nonprim : NULL,
        up_loc_rep_addr_af ? up_loc_rep_addr_af_local_nonprim : NULL,
        up_cum_evt_rpt_criteria ? up_cum_evt_rpt_criteria_local_nonprim : NULL,
        mapped_qo_s_eps ? mapped_qo_s_eps_local_nonprim : NULL,
        additional_ue_info ? additional_ue_info_local_nonprim : NULL,
        coordinate_id ? true : false,
        coordinate_id ? coordinate_id->valuedouble : 0,
        ranging_sl_capability ? ranging_sl_capability->valueint : 0,
        sl_positioning_capabilities ? sl_positioning_capabilitiesList : NULL,
        extended_facility_ind ? true : false,
        extended_facility_ind ? extended_facility_ind->valueint : 0
    );

    return input_data_local_var;
end:
    return NULL;
}

OpenAPI_input_data_t *OpenAPI_input_data_copy(OpenAPI_input_data_t *dst, OpenAPI_input_data_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_input_data_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_input_data_convertToJSON() failed");
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

    OpenAPI_input_data_free(dst);
    dst = OpenAPI_input_data_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

