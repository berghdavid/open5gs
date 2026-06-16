#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_data.h"



static input_data_t *input_data_create_internal(
    external_client_type_t *external_client_type,
    char *correlation_id,
    char *amf_id,
    location_qo_s_t *location_qo_s,
    list_t *supported_gad_shapes,
    char *supi,
    char *pei,
    char *gpsi,
    list_t *requested_ranging_sl_result,
    list_t *related_ues,
    ecgi_t *ecgi,
    ecgi_t *ecgi_on_second_node,
    ncgi_t *ncgi,
    ncgi_t *ncgi_on_second_node,
    lcs_priority_t *priority,
    velocity_requested_t *velocity_requested,
    ue_lcs_capability_t *ue_lcs_cap,
    int *lcs_service_type,
    ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *lir_gmlc_call_back_uri,
    char *vgmlc_address,
    char *ldr_reference,
    char *lir_reference,
    periodic_event_info_t *periodic_event_info,
    area_event_info_t *area_event_info,
    motion_event_info_t *motion_event_info,
    list_t *reporting_access_types,
    ue_connectivity_state_t *ue_connectivity_states,
    ue_location_service_ind_t *ue_location_service_ind,
    lcs_broadcast_assistance_types_data_t *mo_assistance_data_types,
    ref_to_binary_data_t *lpp_message,
    list_t *lpp_message_ext,
    char *supported_features,
    char *ue_positioning_cap,
    tnap_id_t *tnap_id,
    twap_id_t *twap_id,
    int *ue_country_det_ind,
    char *scheduled_loc_time,
    int *reliable_loc_req,
    list_t *evt_rpt_allowed_areas,
    int *ue_unaware_ind,
    int *intermediate_location_ind,
    int *max_resp_time,
    lp_hap_type_t *lp_hap_type,
    list_t *ue_up_pos_caps,
    reporting_ind_t *reporting_ind,
    mbsr_info_t *mbsr_info,
    int *mwab_support_ind,
    integrity_requirements_t *integrity_requirements,
    up_loc_rep_addr_af_t *up_loc_rep_addr_af,
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    mapped_location_qo_s_eps_t *mapped_qo_s_eps,
    additional_ue_info_t *additional_ue_info,
    int *coordinate_id,
    char *ranging_sl_capability,
    list_t *sl_positioning_capabilities,
    int *extended_facility_ind
    ) {
    input_data_t *input_data_local_var = malloc(sizeof(input_data_t));
    if (!input_data_local_var) {
        return NULL;
    }
    memset(input_data_local_var, 0, sizeof(input_data_t));
    input_data_local_var->_library_owned = 1;
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
    input_data_local_var->ue_country_det_ind = ue_country_det_ind;
    input_data_local_var->scheduled_loc_time = scheduled_loc_time;
    input_data_local_var->reliable_loc_req = reliable_loc_req;
    input_data_local_var->evt_rpt_allowed_areas = evt_rpt_allowed_areas;
    input_data_local_var->ue_unaware_ind = ue_unaware_ind;
    input_data_local_var->intermediate_location_ind = intermediate_location_ind;
    input_data_local_var->max_resp_time = max_resp_time;
    input_data_local_var->lp_hap_type = lp_hap_type;
    input_data_local_var->ue_up_pos_caps = ue_up_pos_caps;
    input_data_local_var->reporting_ind = reporting_ind;
    input_data_local_var->mbsr_info = mbsr_info;
    input_data_local_var->mwab_support_ind = mwab_support_ind;
    input_data_local_var->integrity_requirements = integrity_requirements;
    input_data_local_var->up_loc_rep_addr_af = up_loc_rep_addr_af;
    input_data_local_var->up_cum_evt_rpt_criteria = up_cum_evt_rpt_criteria;
    input_data_local_var->mapped_qo_s_eps = mapped_qo_s_eps;
    input_data_local_var->additional_ue_info = additional_ue_info;
    input_data_local_var->coordinate_id = coordinate_id;
    input_data_local_var->ranging_sl_capability = ranging_sl_capability;
    input_data_local_var->sl_positioning_capabilities = sl_positioning_capabilities;
    input_data_local_var->extended_facility_ind = extended_facility_ind;
    return input_data_local_var;
}

__attribute__((deprecated)) input_data_t *input_data_create(
    external_client_type_t *external_client_type,
    char *correlation_id,
    char *amf_id,
    location_qo_s_t *location_qo_s,
    list_t *supported_gad_shapes,
    char *supi,
    char *pei,
    char *gpsi,
    list_t *requested_ranging_sl_result,
    list_t *related_ues,
    ecgi_t *ecgi,
    ecgi_t *ecgi_on_second_node,
    ncgi_t *ncgi,
    ncgi_t *ncgi_on_second_node,
    lcs_priority_t *priority,
    velocity_requested_t *velocity_requested,
    ue_lcs_capability_t *ue_lcs_cap,
    int *lcs_service_type,
    ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *lir_gmlc_call_back_uri,
    char *vgmlc_address,
    char *ldr_reference,
    char *lir_reference,
    periodic_event_info_t *periodic_event_info,
    area_event_info_t *area_event_info,
    motion_event_info_t *motion_event_info,
    list_t *reporting_access_types,
    ue_connectivity_state_t *ue_connectivity_states,
    ue_location_service_ind_t *ue_location_service_ind,
    lcs_broadcast_assistance_types_data_t *mo_assistance_data_types,
    ref_to_binary_data_t *lpp_message,
    list_t *lpp_message_ext,
    char *supported_features,
    char *ue_positioning_cap,
    tnap_id_t *tnap_id,
    twap_id_t *twap_id,
    int *ue_country_det_ind,
    char *scheduled_loc_time,
    int *reliable_loc_req,
    list_t *evt_rpt_allowed_areas,
    int *ue_unaware_ind,
    int *intermediate_location_ind,
    int *max_resp_time,
    lp_hap_type_t *lp_hap_type,
    list_t *ue_up_pos_caps,
    reporting_ind_t *reporting_ind,
    mbsr_info_t *mbsr_info,
    int *mwab_support_ind,
    integrity_requirements_t *integrity_requirements,
    up_loc_rep_addr_af_t *up_loc_rep_addr_af,
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    mapped_location_qo_s_eps_t *mapped_qo_s_eps,
    additional_ue_info_t *additional_ue_info,
    int *coordinate_id,
    char *ranging_sl_capability,
    list_t *sl_positioning_capabilities,
    int *extended_facility_ind
    ) {
    int *lcs_service_type_copy = NULL;
    if (lcs_service_type) {
        lcs_service_type_copy = malloc(sizeof(int));
        if (lcs_service_type_copy) *lcs_service_type_copy = *lcs_service_type;
    }
    int *ue_country_det_ind_copy = NULL;
    if (ue_country_det_ind) {
        ue_country_det_ind_copy = malloc(sizeof(int));
        if (ue_country_det_ind_copy) *ue_country_det_ind_copy = *ue_country_det_ind;
    }
    int *reliable_loc_req_copy = NULL;
    if (reliable_loc_req) {
        reliable_loc_req_copy = malloc(sizeof(int));
        if (reliable_loc_req_copy) *reliable_loc_req_copy = *reliable_loc_req;
    }
    int *ue_unaware_ind_copy = NULL;
    if (ue_unaware_ind) {
        ue_unaware_ind_copy = malloc(sizeof(int));
        if (ue_unaware_ind_copy) *ue_unaware_ind_copy = *ue_unaware_ind;
    }
    int *intermediate_location_ind_copy = NULL;
    if (intermediate_location_ind) {
        intermediate_location_ind_copy = malloc(sizeof(int));
        if (intermediate_location_ind_copy) *intermediate_location_ind_copy = *intermediate_location_ind;
    }
    int *max_resp_time_copy = NULL;
    if (max_resp_time) {
        max_resp_time_copy = malloc(sizeof(int));
        if (max_resp_time_copy) *max_resp_time_copy = *max_resp_time;
    }
    int *mwab_support_ind_copy = NULL;
    if (mwab_support_ind) {
        mwab_support_ind_copy = malloc(sizeof(int));
        if (mwab_support_ind_copy) *mwab_support_ind_copy = *mwab_support_ind;
    }
    int *coordinate_id_copy = NULL;
    if (coordinate_id) {
        coordinate_id_copy = malloc(sizeof(int));
        if (coordinate_id_copy) *coordinate_id_copy = *coordinate_id;
    }
    int *extended_facility_ind_copy = NULL;
    if (extended_facility_ind) {
        extended_facility_ind_copy = malloc(sizeof(int));
        if (extended_facility_ind_copy) *extended_facility_ind_copy = *extended_facility_ind;
    }
    input_data_t *result = input_data_create_internal (
        external_client_type,
        correlation_id,
        amf_id,
        location_qo_s,
        supported_gad_shapes,
        supi,
        pei,
        gpsi,
        requested_ranging_sl_result,
        related_ues,
        ecgi,
        ecgi_on_second_node,
        ncgi,
        ncgi_on_second_node,
        priority,
        velocity_requested,
        ue_lcs_cap,
        lcs_service_type_copy,
        ldr_type,
        hgmlc_call_back_uri,
        lir_gmlc_call_back_uri,
        vgmlc_address,
        ldr_reference,
        lir_reference,
        periodic_event_info,
        area_event_info,
        motion_event_info,
        reporting_access_types,
        ue_connectivity_states,
        ue_location_service_ind,
        mo_assistance_data_types,
        lpp_message,
        lpp_message_ext,
        supported_features,
        ue_positioning_cap,
        tnap_id,
        twap_id,
        ue_country_det_ind_copy,
        scheduled_loc_time,
        reliable_loc_req_copy,
        evt_rpt_allowed_areas,
        ue_unaware_ind_copy,
        intermediate_location_ind_copy,
        max_resp_time_copy,
        lp_hap_type,
        ue_up_pos_caps,
        reporting_ind,
        mbsr_info,
        mwab_support_ind_copy,
        integrity_requirements,
        up_loc_rep_addr_af,
        up_cum_evt_rpt_criteria,
        mapped_qo_s_eps,
        additional_ue_info,
        coordinate_id_copy,
        ranging_sl_capability,
        sl_positioning_capabilities,
        extended_facility_ind_copy
        );
    if (!result) {
        free(lcs_service_type_copy);
        free(ue_country_det_ind_copy);
        free(reliable_loc_req_copy);
        free(ue_unaware_ind_copy);
        free(intermediate_location_ind_copy);
        free(max_resp_time_copy);
        free(mwab_support_ind_copy);
        free(coordinate_id_copy);
        free(extended_facility_ind_copy);
    }
    return result;
}

void input_data_free(input_data_t *input_data) {
    if(NULL == input_data){
        return ;
    }
    if(input_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_data->external_client_type) {
        external_client_type_free(input_data->external_client_type);
        input_data->external_client_type = NULL;
    }
    if (input_data->correlation_id) {
        free(input_data->correlation_id);
        input_data->correlation_id = NULL;
    }
    if (input_data->amf_id) {
        free(input_data->amf_id);
        input_data->amf_id = NULL;
    }
    if (input_data->location_qo_s) {
        location_qo_s_free(input_data->location_qo_s);
        input_data->location_qo_s = NULL;
    }
    if (input_data->supported_gad_shapes) {
        list_ForEach(listEntry, input_data->supported_gad_shapes) {
            supported_gad_shapes_free(listEntry->data);
        }
        list_freeList(input_data->supported_gad_shapes);
        input_data->supported_gad_shapes = NULL;
    }
    if (input_data->supi) {
        free(input_data->supi);
        input_data->supi = NULL;
    }
    if (input_data->pei) {
        free(input_data->pei);
        input_data->pei = NULL;
    }
    if (input_data->gpsi) {
        free(input_data->gpsi);
        input_data->gpsi = NULL;
    }
    if (input_data->requested_ranging_sl_result) {
        list_ForEach(listEntry, input_data->requested_ranging_sl_result) {
            ranging_sl_result_free(listEntry->data);
        }
        list_freeList(input_data->requested_ranging_sl_result);
        input_data->requested_ranging_sl_result = NULL;
    }
    if (input_data->related_ues) {
        list_ForEach(listEntry, input_data->related_ues) {
            related_ue_free(listEntry->data);
        }
        list_freeList(input_data->related_ues);
        input_data->related_ues = NULL;
    }
    if (input_data->ecgi) {
        ecgi_free(input_data->ecgi);
        input_data->ecgi = NULL;
    }
    if (input_data->ecgi_on_second_node) {
        ecgi_free(input_data->ecgi_on_second_node);
        input_data->ecgi_on_second_node = NULL;
    }
    if (input_data->ncgi) {
        ncgi_free(input_data->ncgi);
        input_data->ncgi = NULL;
    }
    if (input_data->ncgi_on_second_node) {
        ncgi_free(input_data->ncgi_on_second_node);
        input_data->ncgi_on_second_node = NULL;
    }
    if (input_data->priority) {
        lcs_priority_free(input_data->priority);
        input_data->priority = NULL;
    }
    if (input_data->velocity_requested) {
        velocity_requested_free(input_data->velocity_requested);
        input_data->velocity_requested = NULL;
    }
    if (input_data->ue_lcs_cap) {
        ue_lcs_capability_free(input_data->ue_lcs_cap);
        input_data->ue_lcs_cap = NULL;
    }
    if (input_data->lcs_service_type) {
        free(input_data->lcs_service_type);
        input_data->lcs_service_type = NULL;
    }
    if (input_data->ldr_type) {
        ldr_type_free(input_data->ldr_type);
        input_data->ldr_type = NULL;
    }
    if (input_data->hgmlc_call_back_uri) {
        free(input_data->hgmlc_call_back_uri);
        input_data->hgmlc_call_back_uri = NULL;
    }
    if (input_data->lir_gmlc_call_back_uri) {
        free(input_data->lir_gmlc_call_back_uri);
        input_data->lir_gmlc_call_back_uri = NULL;
    }
    if (input_data->vgmlc_address) {
        free(input_data->vgmlc_address);
        input_data->vgmlc_address = NULL;
    }
    if (input_data->ldr_reference) {
        free(input_data->ldr_reference);
        input_data->ldr_reference = NULL;
    }
    if (input_data->lir_reference) {
        free(input_data->lir_reference);
        input_data->lir_reference = NULL;
    }
    if (input_data->periodic_event_info) {
        periodic_event_info_free(input_data->periodic_event_info);
        input_data->periodic_event_info = NULL;
    }
    if (input_data->area_event_info) {
        area_event_info_free(input_data->area_event_info);
        input_data->area_event_info = NULL;
    }
    if (input_data->motion_event_info) {
        motion_event_info_free(input_data->motion_event_info);
        input_data->motion_event_info = NULL;
    }
    if (input_data->reporting_access_types) {
        list_ForEach(listEntry, input_data->reporting_access_types) {
            reporting_access_type_free(listEntry->data);
        }
        list_freeList(input_data->reporting_access_types);
        input_data->reporting_access_types = NULL;
    }
    if (input_data->ue_connectivity_states) {
        ue_connectivity_state_free(input_data->ue_connectivity_states);
        input_data->ue_connectivity_states = NULL;
    }
    if (input_data->ue_location_service_ind) {
        ue_location_service_ind_free(input_data->ue_location_service_ind);
        input_data->ue_location_service_ind = NULL;
    }
    if (input_data->mo_assistance_data_types) {
        lcs_broadcast_assistance_types_data_free(input_data->mo_assistance_data_types);
        input_data->mo_assistance_data_types = NULL;
    }
    if (input_data->lpp_message) {
        ref_to_binary_data_free(input_data->lpp_message);
        input_data->lpp_message = NULL;
    }
    if (input_data->lpp_message_ext) {
        list_ForEach(listEntry, input_data->lpp_message_ext) {
            ref_to_binary_data_free(listEntry->data);
        }
        list_freeList(input_data->lpp_message_ext);
        input_data->lpp_message_ext = NULL;
    }
    if (input_data->supported_features) {
        free(input_data->supported_features);
        input_data->supported_features = NULL;
    }
    if (input_data->ue_positioning_cap) {
        free(input_data->ue_positioning_cap);
        input_data->ue_positioning_cap = NULL;
    }
    if (input_data->tnap_id) {
        tnap_id_free(input_data->tnap_id);
        input_data->tnap_id = NULL;
    }
    if (input_data->twap_id) {
        twap_id_free(input_data->twap_id);
        input_data->twap_id = NULL;
    }
    if (input_data->ue_country_det_ind) {
        free(input_data->ue_country_det_ind);
        input_data->ue_country_det_ind = NULL;
    }
    if (input_data->scheduled_loc_time) {
        free(input_data->scheduled_loc_time);
        input_data->scheduled_loc_time = NULL;
    }
    if (input_data->reliable_loc_req) {
        free(input_data->reliable_loc_req);
        input_data->reliable_loc_req = NULL;
    }
    if (input_data->evt_rpt_allowed_areas) {
        list_ForEach(listEntry, input_data->evt_rpt_allowed_areas) {
            reporting_area_free(listEntry->data);
        }
        list_freeList(input_data->evt_rpt_allowed_areas);
        input_data->evt_rpt_allowed_areas = NULL;
    }
    if (input_data->ue_unaware_ind) {
        free(input_data->ue_unaware_ind);
        input_data->ue_unaware_ind = NULL;
    }
    if (input_data->intermediate_location_ind) {
        free(input_data->intermediate_location_ind);
        input_data->intermediate_location_ind = NULL;
    }
    if (input_data->max_resp_time) {
        free(input_data->max_resp_time);
        input_data->max_resp_time = NULL;
    }
    if (input_data->lp_hap_type) {
        lp_hap_type_free(input_data->lp_hap_type);
        input_data->lp_hap_type = NULL;
    }
    if (input_data->ue_up_pos_caps) {
        list_ForEach(listEntry, input_data->ue_up_pos_caps) {
            ue_up_positioning_capabilities_free(listEntry->data);
        }
        list_freeList(input_data->ue_up_pos_caps);
        input_data->ue_up_pos_caps = NULL;
    }
    if (input_data->reporting_ind) {
        reporting_ind_free(input_data->reporting_ind);
        input_data->reporting_ind = NULL;
    }
    if (input_data->mbsr_info) {
        mbsr_info_free(input_data->mbsr_info);
        input_data->mbsr_info = NULL;
    }
    if (input_data->mwab_support_ind) {
        free(input_data->mwab_support_ind);
        input_data->mwab_support_ind = NULL;
    }
    if (input_data->integrity_requirements) {
        integrity_requirements_free(input_data->integrity_requirements);
        input_data->integrity_requirements = NULL;
    }
    if (input_data->up_loc_rep_addr_af) {
        up_loc_rep_addr_af_free(input_data->up_loc_rep_addr_af);
        input_data->up_loc_rep_addr_af = NULL;
    }
    if (input_data->up_cum_evt_rpt_criteria) {
        up_cum_evt_rpt_criteria_free(input_data->up_cum_evt_rpt_criteria);
        input_data->up_cum_evt_rpt_criteria = NULL;
    }
    if (input_data->mapped_qo_s_eps) {
        mapped_location_qo_s_eps_free(input_data->mapped_qo_s_eps);
        input_data->mapped_qo_s_eps = NULL;
    }
    if (input_data->additional_ue_info) {
        additional_ue_info_free(input_data->additional_ue_info);
        input_data->additional_ue_info = NULL;
    }
    if (input_data->coordinate_id) {
        free(input_data->coordinate_id);
        input_data->coordinate_id = NULL;
    }
    if (input_data->ranging_sl_capability) {
        free(input_data->ranging_sl_capability);
        input_data->ranging_sl_capability = NULL;
    }
    if (input_data->sl_positioning_capabilities) {
        list_ForEach(listEntry, input_data->sl_positioning_capabilities) {
            sl_positioning_capability_free(listEntry->data);
        }
        list_freeList(input_data->sl_positioning_capabilities);
        input_data->sl_positioning_capabilities = NULL;
    }
    if (input_data->extended_facility_ind) {
        free(input_data->extended_facility_ind);
        input_data->extended_facility_ind = NULL;
    }
    free(input_data);
}

cJSON *input_data_convertToJSON(input_data_t *input_data) {
    cJSON *item = cJSON_CreateObject();

    // input_data->external_client_type
    if(input_data->external_client_type) {
    cJSON *external_client_type_local_JSON = external_client_type_convertToJSON(input_data->external_client_type);
    if(external_client_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "externalClientType", external_client_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->correlation_id
    if(input_data->correlation_id) {
    if(cJSON_AddStringToObject(item, "correlationID", input_data->correlation_id) == NULL) {
    goto fail; //String
    }
    }


    // input_data->amf_id
    if(input_data->amf_id) {
    if(cJSON_AddStringToObject(item, "amfId", input_data->amf_id) == NULL) {
    goto fail; //String
    }
    }


    // input_data->location_qo_s
    if(input_data->location_qo_s) {
    cJSON *location_qo_s_local_JSON = location_qo_s_convertToJSON(input_data->location_qo_s);
    if(location_qo_s_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "locationQoS", location_qo_s_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->supported_gad_shapes
    if(input_data->supported_gad_shapes) {
    cJSON *supported_gad_shapes = cJSON_AddArrayToObject(item, "supportedGADShapes");
    if(supported_gad_shapes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *supported_gad_shapesListEntry;
    if (input_data->supported_gad_shapes) {
    list_ForEach(supported_gad_shapesListEntry, input_data->supported_gad_shapes) {
    cJSON *itemLocal = supported_gad_shapes_convertToJSON(supported_gad_shapesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(supported_gad_shapes, itemLocal);
    }
    }
    }


    // input_data->supi
    if(input_data->supi) {
    if(cJSON_AddStringToObject(item, "supi", input_data->supi) == NULL) {
    goto fail; //String
    }
    }


    // input_data->pei
    if(input_data->pei) {
    if(cJSON_AddStringToObject(item, "pei", input_data->pei) == NULL) {
    goto fail; //String
    }
    }


    // input_data->gpsi
    if(input_data->gpsi) {
    if(cJSON_AddStringToObject(item, "gpsi", input_data->gpsi) == NULL) {
    goto fail; //String
    }
    }


    // input_data->requested_ranging_sl_result
    if(input_data->requested_ranging_sl_result) {
    cJSON *requested_ranging_sl_result = cJSON_AddArrayToObject(item, "requestedRangingSlResult");
    if(requested_ranging_sl_result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *requested_ranging_sl_resultListEntry;
    if (input_data->requested_ranging_sl_result) {
    list_ForEach(requested_ranging_sl_resultListEntry, input_data->requested_ranging_sl_result) {
    cJSON *itemLocal = ranging_sl_result_convertToJSON(requested_ranging_sl_resultListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(requested_ranging_sl_result, itemLocal);
    }
    }
    }


    // input_data->related_ues
    if(input_data->related_ues) {
    cJSON *related_ues = cJSON_AddArrayToObject(item, "relatedUes");
    if(related_ues == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *related_uesListEntry;
    if (input_data->related_ues) {
    list_ForEach(related_uesListEntry, input_data->related_ues) {
    cJSON *itemLocal = related_ue_convertToJSON(related_uesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(related_ues, itemLocal);
    }
    }
    }


    // input_data->ecgi
    if(input_data->ecgi) {
    cJSON *ecgi_local_JSON = ecgi_convertToJSON(input_data->ecgi);
    if(ecgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->ecgi_on_second_node
    if(input_data->ecgi_on_second_node) {
    cJSON *ecgi_on_second_node_local_JSON = ecgi_convertToJSON(input_data->ecgi_on_second_node);
    if(ecgi_on_second_node_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ecgiOnSecondNode", ecgi_on_second_node_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->ncgi
    if(input_data->ncgi) {
    cJSON *ncgi_local_JSON = ncgi_convertToJSON(input_data->ncgi);
    if(ncgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->ncgi_on_second_node
    if(input_data->ncgi_on_second_node) {
    cJSON *ncgi_on_second_node_local_JSON = ncgi_convertToJSON(input_data->ncgi_on_second_node);
    if(ncgi_on_second_node_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ncgiOnSecondNode", ncgi_on_second_node_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->priority
    if(input_data->priority) {
    cJSON *priority_local_JSON = lcs_priority_convertToJSON(input_data->priority);
    if(priority_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "priority", priority_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->velocity_requested
    if(input_data->velocity_requested) {
    cJSON *velocity_requested_local_JSON = velocity_requested_convertToJSON(input_data->velocity_requested);
    if(velocity_requested_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "velocityRequested", velocity_requested_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->ue_lcs_cap
    if(input_data->ue_lcs_cap) {
    cJSON *ue_lcs_cap_local_JSON = ue_lcs_capability_convertToJSON(input_data->ue_lcs_cap);
    if(ue_lcs_cap_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ueLcsCap", ue_lcs_cap_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->lcs_service_type
    if(input_data->lcs_service_type) {
    if(cJSON_AddNumberToObject(item, "lcsServiceType", *input_data->lcs_service_type) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_data->ldr_type
    if(input_data->ldr_type) {
    cJSON *ldr_type_local_JSON = ldr_type_convertToJSON(input_data->ldr_type);
    if(ldr_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ldrType", ldr_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->hgmlc_call_back_uri
    if(input_data->hgmlc_call_back_uri) {
    if(cJSON_AddStringToObject(item, "hgmlcCallBackURI", input_data->hgmlc_call_back_uri) == NULL) {
    goto fail; //String
    }
    }


    // input_data->lir_gmlc_call_back_uri
    if(input_data->lir_gmlc_call_back_uri) {
    if(cJSON_AddStringToObject(item, "lirGmlcCallBackUri", input_data->lir_gmlc_call_back_uri) == NULL) {
    goto fail; //String
    }
    }


    // input_data->vgmlc_address
    if(input_data->vgmlc_address) {
    if(cJSON_AddStringToObject(item, "vgmlcAddress", input_data->vgmlc_address) == NULL) {
    goto fail; //String
    }
    }


    // input_data->ldr_reference
    if(input_data->ldr_reference) {
    if(cJSON_AddStringToObject(item, "ldrReference", input_data->ldr_reference) == NULL) {
    goto fail; //String
    }
    }


    // input_data->lir_reference
    if(input_data->lir_reference) {
    if(cJSON_AddStringToObject(item, "lirReference", input_data->lir_reference) == NULL) {
    goto fail; //String
    }
    }


    // input_data->periodic_event_info
    if(input_data->periodic_event_info) {
    cJSON *periodic_event_info_local_JSON = periodic_event_info_convertToJSON(input_data->periodic_event_info);
    if(periodic_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "periodicEventInfo", periodic_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->area_event_info
    if(input_data->area_event_info) {
    cJSON *area_event_info_local_JSON = area_event_info_convertToJSON(input_data->area_event_info);
    if(area_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "areaEventInfo", area_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->motion_event_info
    if(input_data->motion_event_info) {
    cJSON *motion_event_info_local_JSON = motion_event_info_convertToJSON(input_data->motion_event_info);
    if(motion_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "motionEventInfo", motion_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->reporting_access_types
    if(input_data->reporting_access_types) {
    cJSON *reporting_access_types = cJSON_AddArrayToObject(item, "reportingAccessTypes");
    if(reporting_access_types == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *reporting_access_typesListEntry;
    if (input_data->reporting_access_types) {
    list_ForEach(reporting_access_typesListEntry, input_data->reporting_access_types) {
    cJSON *itemLocal = reporting_access_type_convertToJSON(reporting_access_typesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(reporting_access_types, itemLocal);
    }
    }
    }


    // input_data->ue_connectivity_states
    if(input_data->ue_connectivity_states) {
    cJSON *ue_connectivity_states_local_JSON = ue_connectivity_state_convertToJSON(input_data->ue_connectivity_states);
    if(ue_connectivity_states_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ueConnectivityStates", ue_connectivity_states_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->ue_location_service_ind
    if(input_data->ue_location_service_ind) {
    cJSON *ue_location_service_ind_local_JSON = ue_location_service_ind_convertToJSON(input_data->ue_location_service_ind);
    if(ue_location_service_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ueLocationServiceInd", ue_location_service_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->mo_assistance_data_types
    if(input_data->mo_assistance_data_types) {
    cJSON *mo_assistance_data_types_local_JSON = lcs_broadcast_assistance_types_data_convertToJSON(input_data->mo_assistance_data_types);
    if(mo_assistance_data_types_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "moAssistanceDataTypes", mo_assistance_data_types_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->lpp_message
    if(input_data->lpp_message) {
    cJSON *lpp_message_local_JSON = ref_to_binary_data_convertToJSON(input_data->lpp_message);
    if(lpp_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lppMessage", lpp_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->lpp_message_ext
    if(input_data->lpp_message_ext) {
    cJSON *lpp_message_ext = cJSON_AddArrayToObject(item, "lppMessageExt");
    if(lpp_message_ext == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *lpp_message_extListEntry;
    if (input_data->lpp_message_ext) {
    list_ForEach(lpp_message_extListEntry, input_data->lpp_message_ext) {
    cJSON *itemLocal = ref_to_binary_data_convertToJSON(lpp_message_extListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(lpp_message_ext, itemLocal);
    }
    }
    }


    // input_data->supported_features
    if(input_data->supported_features) {
    if(cJSON_AddStringToObject(item, "supportedFeatures", input_data->supported_features) == NULL) {
    goto fail; //String
    }
    }


    // input_data->ue_positioning_cap
    if(input_data->ue_positioning_cap) {
    if(cJSON_AddStringToObject(item, "uePositioningCap", input_data->ue_positioning_cap) == NULL) {
    goto fail; //ByteArray
    }
    }


    // input_data->tnap_id
    if(input_data->tnap_id) {
    cJSON *tnap_id_local_JSON = tnap_id_convertToJSON(input_data->tnap_id);
    if(tnap_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "tnapId", tnap_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->twap_id
    if(input_data->twap_id) {
    cJSON *twap_id_local_JSON = twap_id_convertToJSON(input_data->twap_id);
    if(twap_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "twapId", twap_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->ue_country_det_ind
    if(input_data->ue_country_det_ind) {
    if(cJSON_AddBoolToObject(item, "ueCountryDetInd", *input_data->ue_country_det_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // input_data->scheduled_loc_time
    if(input_data->scheduled_loc_time) {
    if(cJSON_AddStringToObject(item, "scheduledLocTime", input_data->scheduled_loc_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // input_data->reliable_loc_req
    if(input_data->reliable_loc_req) {
    if(cJSON_AddBoolToObject(item, "reliableLocReq", *input_data->reliable_loc_req) == NULL) {
    goto fail; //Bool
    }
    }


    // input_data->evt_rpt_allowed_areas
    if(input_data->evt_rpt_allowed_areas) {
    cJSON *evt_rpt_allowed_areas = cJSON_AddArrayToObject(item, "evtRptAllowedAreas");
    if(evt_rpt_allowed_areas == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *evt_rpt_allowed_areasListEntry;
    if (input_data->evt_rpt_allowed_areas) {
    list_ForEach(evt_rpt_allowed_areasListEntry, input_data->evt_rpt_allowed_areas) {
    cJSON *itemLocal = reporting_area_convertToJSON(evt_rpt_allowed_areasListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(evt_rpt_allowed_areas, itemLocal);
    }
    }
    }


    // input_data->ue_unaware_ind
    if(input_data->ue_unaware_ind) {
    if(cJSON_AddBoolToObject(item, "ueUnawareInd", *input_data->ue_unaware_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // input_data->intermediate_location_ind
    if(input_data->intermediate_location_ind) {
    if(cJSON_AddBoolToObject(item, "intermediateLocationInd", *input_data->intermediate_location_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // input_data->max_resp_time
    if(input_data->max_resp_time) {
    if(cJSON_AddNumberToObject(item, "maxRespTime", *input_data->max_resp_time) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_data->lp_hap_type
    if(input_data->lp_hap_type) {
    cJSON *lp_hap_type_local_JSON = lp_hap_type_convertToJSON(input_data->lp_hap_type);
    if(lp_hap_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lpHapType", lp_hap_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->ue_up_pos_caps
    if(input_data->ue_up_pos_caps) {
    cJSON *ue_up_pos_caps = cJSON_AddArrayToObject(item, "ueUpPosCaps");
    if(ue_up_pos_caps == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ue_up_pos_capsListEntry;
    if (input_data->ue_up_pos_caps) {
    list_ForEach(ue_up_pos_capsListEntry, input_data->ue_up_pos_caps) {
    cJSON *itemLocal = ue_up_positioning_capabilities_convertToJSON(ue_up_pos_capsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ue_up_pos_caps, itemLocal);
    }
    }
    }


    // input_data->reporting_ind
    if(input_data->reporting_ind) {
    cJSON *reporting_ind_local_JSON = reporting_ind_convertToJSON(input_data->reporting_ind);
    if(reporting_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reportingInd", reporting_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->mbsr_info
    if(input_data->mbsr_info) {
    cJSON *mbsr_info_local_JSON = mbsr_info_convertToJSON(input_data->mbsr_info);
    if(mbsr_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "mbsrInfo", mbsr_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->mwab_support_ind
    if(input_data->mwab_support_ind) {
    if(cJSON_AddBoolToObject(item, "mwabSupportInd", *input_data->mwab_support_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // input_data->integrity_requirements
    if(input_data->integrity_requirements) {
    cJSON *integrity_requirements_local_JSON = integrity_requirements_convertToJSON(input_data->integrity_requirements);
    if(integrity_requirements_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "integrityRequirements", integrity_requirements_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->up_loc_rep_addr_af
    if(input_data->up_loc_rep_addr_af) {
    cJSON *up_loc_rep_addr_af_local_JSON = up_loc_rep_addr_af_convertToJSON(input_data->up_loc_rep_addr_af);
    if(up_loc_rep_addr_af_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "upLocRepAddrAf", up_loc_rep_addr_af_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->up_cum_evt_rpt_criteria
    if(input_data->up_cum_evt_rpt_criteria) {
    cJSON *up_cum_evt_rpt_criteria_local_JSON = up_cum_evt_rpt_criteria_convertToJSON(input_data->up_cum_evt_rpt_criteria);
    if(up_cum_evt_rpt_criteria_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "upCumEvtRptCriteria", up_cum_evt_rpt_criteria_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->mapped_qo_s_eps
    if(input_data->mapped_qo_s_eps) {
    cJSON *mapped_qo_s_eps_local_JSON = mapped_location_qo_s_eps_convertToJSON(input_data->mapped_qo_s_eps);
    if(mapped_qo_s_eps_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "mappedQoSEps", mapped_qo_s_eps_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->additional_ue_info
    if(input_data->additional_ue_info) {
    cJSON *additional_ue_info_local_JSON = additional_ue_info_convertToJSON(input_data->additional_ue_info);
    if(additional_ue_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "additionalUeInfo", additional_ue_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_data->coordinate_id
    if(input_data->coordinate_id) {
    if(cJSON_AddNumberToObject(item, "coordinateID", *input_data->coordinate_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_data->ranging_sl_capability
    if(input_data->ranging_sl_capability) {
    if(cJSON_AddStringToObject(item, "rangingSlCapability", input_data->ranging_sl_capability) == NULL) {
    goto fail; //ByteArray
    }
    }


    // input_data->sl_positioning_capabilities
    if(input_data->sl_positioning_capabilities) {
    cJSON *sl_positioning_capabilities = cJSON_AddArrayToObject(item, "slPositioningCapabilities");
    if(sl_positioning_capabilities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *sl_positioning_capabilitiesListEntry;
    if (input_data->sl_positioning_capabilities) {
    list_ForEach(sl_positioning_capabilitiesListEntry, input_data->sl_positioning_capabilities) {
    cJSON *itemLocal = sl_positioning_capability_convertToJSON(sl_positioning_capabilitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(sl_positioning_capabilities, itemLocal);
    }
    }
    }


    // input_data->extended_facility_ind
    if(input_data->extended_facility_ind) {
    if(cJSON_AddBoolToObject(item, "extendedFacilityInd", *input_data->extended_facility_ind) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_data_t *input_data_parseFromJSON(cJSON *input_dataJSON){

    input_data_t *input_data_local_var = NULL;

    // define the local variable for input_data->external_client_type
    external_client_type_t *external_client_type_local_nonprim = NULL;

    char *correlation_id_local_str = NULL;

    char *amf_id_local_str = NULL;

    // define the local variable for input_data->location_qo_s
    location_qo_s_t *location_qo_s_local_nonprim = NULL;

    // define the local list for input_data->supported_gad_shapes
    list_t *supported_gad_shapesList = NULL;

    char *supi_local_str = NULL;

    char *pei_local_str = NULL;

    char *gpsi_local_str = NULL;

    // define the local list for input_data->requested_ranging_sl_result
    list_t *requested_ranging_sl_resultList = NULL;

    // define the local list for input_data->related_ues
    list_t *related_uesList = NULL;

    // define the local variable for input_data->ecgi
    ecgi_t *ecgi_local_nonprim = NULL;

    // define the local variable for input_data->ecgi_on_second_node
    ecgi_t *ecgi_on_second_node_local_nonprim = NULL;

    // define the local variable for input_data->ncgi
    ncgi_t *ncgi_local_nonprim = NULL;

    // define the local variable for input_data->ncgi_on_second_node
    ncgi_t *ncgi_on_second_node_local_nonprim = NULL;

    // define the local variable for input_data->priority
    lcs_priority_t *priority_local_nonprim = NULL;

    // define the local variable for input_data->velocity_requested
    velocity_requested_t *velocity_requested_local_nonprim = NULL;

    // define the local variable for input_data->ue_lcs_cap
    ue_lcs_capability_t *ue_lcs_cap_local_nonprim = NULL;

    // define the local variable for input_data->lcs_service_type
    int *lcs_service_type_local_var = NULL;

    // define the local variable for input_data->ldr_type
    ldr_type_t *ldr_type_local_nonprim = NULL;

    char *hgmlc_call_back_uri_local_str = NULL;

    char *lir_gmlc_call_back_uri_local_str = NULL;

    char *vgmlc_address_local_str = NULL;

    char *ldr_reference_local_str = NULL;

    char *lir_reference_local_str = NULL;

    // define the local variable for input_data->periodic_event_info
    periodic_event_info_t *periodic_event_info_local_nonprim = NULL;

    // define the local variable for input_data->area_event_info
    area_event_info_t *area_event_info_local_nonprim = NULL;

    // define the local variable for input_data->motion_event_info
    motion_event_info_t *motion_event_info_local_nonprim = NULL;

    // define the local list for input_data->reporting_access_types
    list_t *reporting_access_typesList = NULL;

    // define the local variable for input_data->ue_connectivity_states
    ue_connectivity_state_t *ue_connectivity_states_local_nonprim = NULL;

    // define the local variable for input_data->ue_location_service_ind
    ue_location_service_ind_t *ue_location_service_ind_local_nonprim = NULL;

    // define the local variable for input_data->mo_assistance_data_types
    lcs_broadcast_assistance_types_data_t *mo_assistance_data_types_local_nonprim = NULL;

    // define the local variable for input_data->lpp_message
    ref_to_binary_data_t *lpp_message_local_nonprim = NULL;

    // define the local list for input_data->lpp_message_ext
    list_t *lpp_message_extList = NULL;

    char *supported_features_local_str = NULL;

    char *ue_positioning_cap_local_str = NULL;

    // define the local variable for input_data->tnap_id
    tnap_id_t *tnap_id_local_nonprim = NULL;

    // define the local variable for input_data->twap_id
    twap_id_t *twap_id_local_nonprim = NULL;

    // define the local variable for input_data->ue_country_det_ind
    int *ue_country_det_ind_local_var = NULL;

    char *scheduled_loc_time_local_str = NULL;

    // define the local variable for input_data->reliable_loc_req
    int *reliable_loc_req_local_var = NULL;

    // define the local list for input_data->evt_rpt_allowed_areas
    list_t *evt_rpt_allowed_areasList = NULL;

    // define the local variable for input_data->ue_unaware_ind
    int *ue_unaware_ind_local_var = NULL;

    // define the local variable for input_data->intermediate_location_ind
    int *intermediate_location_ind_local_var = NULL;

    // define the local variable for input_data->max_resp_time
    int *max_resp_time_local_var = NULL;

    // define the local variable for input_data->lp_hap_type
    lp_hap_type_t *lp_hap_type_local_nonprim = NULL;

    // define the local list for input_data->ue_up_pos_caps
    list_t *ue_up_pos_capsList = NULL;

    // define the local variable for input_data->reporting_ind
    reporting_ind_t *reporting_ind_local_nonprim = NULL;

    // define the local variable for input_data->mbsr_info
    mbsr_info_t *mbsr_info_local_nonprim = NULL;

    // define the local variable for input_data->mwab_support_ind
    int *mwab_support_ind_local_var = NULL;

    // define the local variable for input_data->integrity_requirements
    integrity_requirements_t *integrity_requirements_local_nonprim = NULL;

    // define the local variable for input_data->up_loc_rep_addr_af
    up_loc_rep_addr_af_t *up_loc_rep_addr_af_local_nonprim = NULL;

    // define the local variable for input_data->up_cum_evt_rpt_criteria
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_nonprim = NULL;

    // define the local variable for input_data->mapped_qo_s_eps
    mapped_location_qo_s_eps_t *mapped_qo_s_eps_local_nonprim = NULL;

    // define the local variable for input_data->additional_ue_info
    additional_ue_info_t *additional_ue_info_local_nonprim = NULL;

    // define the local variable for input_data->coordinate_id
    int *coordinate_id_local_var = NULL;

    char *ranging_sl_capability_local_str = NULL;

    // define the local list for input_data->sl_positioning_capabilities
    list_t *sl_positioning_capabilitiesList = NULL;

    // define the local variable for input_data->extended_facility_ind
    int *extended_facility_ind_local_var = NULL;

    // input_data->external_client_type
    cJSON *external_client_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "externalClientType");
    if (cJSON_IsNull(external_client_type)) {
        external_client_type = NULL;
    }
    if (external_client_type) { 
    external_client_type_local_nonprim = external_client_type_parseFromJSON(external_client_type); //nonprimitive
    }

    // input_data->correlation_id
    cJSON *correlation_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "correlationID");
    if (cJSON_IsNull(correlation_id)) {
        correlation_id = NULL;
    }
    if (correlation_id) { 
    if(!cJSON_IsString(correlation_id) && !cJSON_IsNull(correlation_id))
    {
    goto end; //String
    }
    }

    // input_data->amf_id
    cJSON *amf_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "amfId");
    if (cJSON_IsNull(amf_id)) {
        amf_id = NULL;
    }
    if (amf_id) { 
    if(!cJSON_IsString(amf_id) && !cJSON_IsNull(amf_id))
    {
    goto end; //String
    }
    }

    // input_data->location_qo_s
    cJSON *location_qo_s = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "locationQoS");
    if (cJSON_IsNull(location_qo_s)) {
        location_qo_s = NULL;
    }
    if (location_qo_s) { 
    location_qo_s_local_nonprim = location_qo_s_parseFromJSON(location_qo_s); //nonprimitive
    }

    // input_data->supported_gad_shapes
    cJSON *supported_gad_shapes = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "supportedGADShapes");
    if (cJSON_IsNull(supported_gad_shapes)) {
        supported_gad_shapes = NULL;
    }
    if (supported_gad_shapes) { 
    cJSON *supported_gad_shapes_local_nonprimitive = NULL;
    if(!cJSON_IsArray(supported_gad_shapes)){
        goto end; //nonprimitive container
    }

    supported_gad_shapesList = list_createList();

    cJSON_ArrayForEach(supported_gad_shapes_local_nonprimitive,supported_gad_shapes )
    {
        if(!cJSON_IsObject(supported_gad_shapes_local_nonprimitive)){
            goto end;
        }
        supported_gad_shapes_t *supported_gad_shapesItem = supported_gad_shapes_parseFromJSON(supported_gad_shapes_local_nonprimitive);

        list_addElement(supported_gad_shapesList, supported_gad_shapesItem);
    }
    }

    // input_data->supi
    cJSON *supi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "supi");
    if (cJSON_IsNull(supi)) {
        supi = NULL;
    }
    if (supi) { 
    if(!cJSON_IsString(supi) && !cJSON_IsNull(supi))
    {
    goto end; //String
    }
    }

    // input_data->pei
    cJSON *pei = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "pei");
    if (cJSON_IsNull(pei)) {
        pei = NULL;
    }
    if (pei) { 
    if(!cJSON_IsString(pei) && !cJSON_IsNull(pei))
    {
    goto end; //String
    }
    }

    // input_data->gpsi
    cJSON *gpsi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "gpsi");
    if (cJSON_IsNull(gpsi)) {
        gpsi = NULL;
    }
    if (gpsi) { 
    if(!cJSON_IsString(gpsi) && !cJSON_IsNull(gpsi))
    {
    goto end; //String
    }
    }

    // input_data->requested_ranging_sl_result
    cJSON *requested_ranging_sl_result = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "requestedRangingSlResult");
    if (cJSON_IsNull(requested_ranging_sl_result)) {
        requested_ranging_sl_result = NULL;
    }
    if (requested_ranging_sl_result) { 
    cJSON *requested_ranging_sl_result_local_nonprimitive = NULL;
    if(!cJSON_IsArray(requested_ranging_sl_result)){
        goto end; //nonprimitive container
    }

    requested_ranging_sl_resultList = list_createList();

    cJSON_ArrayForEach(requested_ranging_sl_result_local_nonprimitive,requested_ranging_sl_result )
    {
        if(!cJSON_IsObject(requested_ranging_sl_result_local_nonprimitive)){
            goto end;
        }
        ranging_sl_result_t *requested_ranging_sl_resultItem = ranging_sl_result_parseFromJSON(requested_ranging_sl_result_local_nonprimitive);

        list_addElement(requested_ranging_sl_resultList, requested_ranging_sl_resultItem);
    }
    }

    // input_data->related_ues
    cJSON *related_ues = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "relatedUes");
    if (cJSON_IsNull(related_ues)) {
        related_ues = NULL;
    }
    if (related_ues) { 
    cJSON *related_ues_local_nonprimitive = NULL;
    if(!cJSON_IsArray(related_ues)){
        goto end; //nonprimitive container
    }

    related_uesList = list_createList();

    cJSON_ArrayForEach(related_ues_local_nonprimitive,related_ues )
    {
        if(!cJSON_IsObject(related_ues_local_nonprimitive)){
            goto end;
        }
        related_ue_t *related_uesItem = related_ue_parseFromJSON(related_ues_local_nonprimitive);

        list_addElement(related_uesList, related_uesItem);
    }
    }

    // input_data->ecgi
    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ecgi");
    if (cJSON_IsNull(ecgi)) {
        ecgi = NULL;
    }
    if (ecgi) { 
    ecgi_local_nonprim = ecgi_parseFromJSON(ecgi); //nonprimitive
    }

    // input_data->ecgi_on_second_node
    cJSON *ecgi_on_second_node = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ecgiOnSecondNode");
    if (cJSON_IsNull(ecgi_on_second_node)) {
        ecgi_on_second_node = NULL;
    }
    if (ecgi_on_second_node) { 
    ecgi_on_second_node_local_nonprim = ecgi_parseFromJSON(ecgi_on_second_node); //nonprimitive
    }

    // input_data->ncgi
    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ncgi");
    if (cJSON_IsNull(ncgi)) {
        ncgi = NULL;
    }
    if (ncgi) { 
    ncgi_local_nonprim = ncgi_parseFromJSON(ncgi); //nonprimitive
    }

    // input_data->ncgi_on_second_node
    cJSON *ncgi_on_second_node = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ncgiOnSecondNode");
    if (cJSON_IsNull(ncgi_on_second_node)) {
        ncgi_on_second_node = NULL;
    }
    if (ncgi_on_second_node) { 
    ncgi_on_second_node_local_nonprim = ncgi_parseFromJSON(ncgi_on_second_node); //nonprimitive
    }

    // input_data->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "priority");
    if (cJSON_IsNull(priority)) {
        priority = NULL;
    }
    if (priority) { 
    priority_local_nonprim = lcs_priority_parseFromJSON(priority); //nonprimitive
    }

    // input_data->velocity_requested
    cJSON *velocity_requested = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "velocityRequested");
    if (cJSON_IsNull(velocity_requested)) {
        velocity_requested = NULL;
    }
    if (velocity_requested) { 
    velocity_requested_local_nonprim = velocity_requested_parseFromJSON(velocity_requested); //nonprimitive
    }

    // input_data->ue_lcs_cap
    cJSON *ue_lcs_cap = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueLcsCap");
    if (cJSON_IsNull(ue_lcs_cap)) {
        ue_lcs_cap = NULL;
    }
    if (ue_lcs_cap) { 
    ue_lcs_cap_local_nonprim = ue_lcs_capability_parseFromJSON(ue_lcs_cap); //nonprimitive
    }

    // input_data->lcs_service_type
    cJSON *lcs_service_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lcsServiceType");
    if (cJSON_IsNull(lcs_service_type)) {
        lcs_service_type = NULL;
    }
    if (lcs_service_type) { 
    if(!cJSON_IsNumber(lcs_service_type))
    {
    goto end; //Numeric
    }
    lcs_service_type_local_var = malloc(sizeof(int));
    if(!lcs_service_type_local_var)
    {
        goto end;
    }
    *lcs_service_type_local_var = lcs_service_type->valuedouble;
    }

    // input_data->ldr_type
    cJSON *ldr_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ldrType");
    if (cJSON_IsNull(ldr_type)) {
        ldr_type = NULL;
    }
    if (ldr_type) { 
    ldr_type_local_nonprim = ldr_type_parseFromJSON(ldr_type); //nonprimitive
    }

    // input_data->hgmlc_call_back_uri
    cJSON *hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "hgmlcCallBackURI");
    if (cJSON_IsNull(hgmlc_call_back_uri)) {
        hgmlc_call_back_uri = NULL;
    }
    if (hgmlc_call_back_uri) { 
    if(!cJSON_IsString(hgmlc_call_back_uri) && !cJSON_IsNull(hgmlc_call_back_uri))
    {
    goto end; //String
    }
    }

    // input_data->lir_gmlc_call_back_uri
    cJSON *lir_gmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lirGmlcCallBackUri");
    if (cJSON_IsNull(lir_gmlc_call_back_uri)) {
        lir_gmlc_call_back_uri = NULL;
    }
    if (lir_gmlc_call_back_uri) { 
    if(!cJSON_IsString(lir_gmlc_call_back_uri) && !cJSON_IsNull(lir_gmlc_call_back_uri))
    {
    goto end; //String
    }
    }

    // input_data->vgmlc_address
    cJSON *vgmlc_address = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "vgmlcAddress");
    if (cJSON_IsNull(vgmlc_address)) {
        vgmlc_address = NULL;
    }
    if (vgmlc_address) { 
    if(!cJSON_IsString(vgmlc_address) && !cJSON_IsNull(vgmlc_address))
    {
    goto end; //String
    }
    }

    // input_data->ldr_reference
    cJSON *ldr_reference = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ldrReference");
    if (cJSON_IsNull(ldr_reference)) {
        ldr_reference = NULL;
    }
    if (ldr_reference) { 
    if(!cJSON_IsString(ldr_reference) && !cJSON_IsNull(ldr_reference))
    {
    goto end; //String
    }
    }

    // input_data->lir_reference
    cJSON *lir_reference = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lirReference");
    if (cJSON_IsNull(lir_reference)) {
        lir_reference = NULL;
    }
    if (lir_reference) { 
    if(!cJSON_IsString(lir_reference) && !cJSON_IsNull(lir_reference))
    {
    goto end; //String
    }
    }

    // input_data->periodic_event_info
    cJSON *periodic_event_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "periodicEventInfo");
    if (cJSON_IsNull(periodic_event_info)) {
        periodic_event_info = NULL;
    }
    if (periodic_event_info) { 
    periodic_event_info_local_nonprim = periodic_event_info_parseFromJSON(periodic_event_info); //nonprimitive
    }

    // input_data->area_event_info
    cJSON *area_event_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "areaEventInfo");
    if (cJSON_IsNull(area_event_info)) {
        area_event_info = NULL;
    }
    if (area_event_info) { 
    area_event_info_local_nonprim = area_event_info_parseFromJSON(area_event_info); //nonprimitive
    }

    // input_data->motion_event_info
    cJSON *motion_event_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "motionEventInfo");
    if (cJSON_IsNull(motion_event_info)) {
        motion_event_info = NULL;
    }
    if (motion_event_info) { 
    motion_event_info_local_nonprim = motion_event_info_parseFromJSON(motion_event_info); //nonprimitive
    }

    // input_data->reporting_access_types
    cJSON *reporting_access_types = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "reportingAccessTypes");
    if (cJSON_IsNull(reporting_access_types)) {
        reporting_access_types = NULL;
    }
    if (reporting_access_types) { 
    cJSON *reporting_access_types_local_nonprimitive = NULL;
    if(!cJSON_IsArray(reporting_access_types)){
        goto end; //nonprimitive container
    }

    reporting_access_typesList = list_createList();

    cJSON_ArrayForEach(reporting_access_types_local_nonprimitive,reporting_access_types )
    {
        if(!cJSON_IsObject(reporting_access_types_local_nonprimitive)){
            goto end;
        }
        reporting_access_type_t *reporting_access_typesItem = reporting_access_type_parseFromJSON(reporting_access_types_local_nonprimitive);

        list_addElement(reporting_access_typesList, reporting_access_typesItem);
    }
    }

    // input_data->ue_connectivity_states
    cJSON *ue_connectivity_states = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueConnectivityStates");
    if (cJSON_IsNull(ue_connectivity_states)) {
        ue_connectivity_states = NULL;
    }
    if (ue_connectivity_states) { 
    ue_connectivity_states_local_nonprim = ue_connectivity_state_parseFromJSON(ue_connectivity_states); //nonprimitive
    }

    // input_data->ue_location_service_ind
    cJSON *ue_location_service_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueLocationServiceInd");
    if (cJSON_IsNull(ue_location_service_ind)) {
        ue_location_service_ind = NULL;
    }
    if (ue_location_service_ind) { 
    ue_location_service_ind_local_nonprim = ue_location_service_ind_parseFromJSON(ue_location_service_ind); //nonprimitive
    }

    // input_data->mo_assistance_data_types
    cJSON *mo_assistance_data_types = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "moAssistanceDataTypes");
    if (cJSON_IsNull(mo_assistance_data_types)) {
        mo_assistance_data_types = NULL;
    }
    if (mo_assistance_data_types) { 
    mo_assistance_data_types_local_nonprim = lcs_broadcast_assistance_types_data_parseFromJSON(mo_assistance_data_types); //nonprimitive
    }

    // input_data->lpp_message
    cJSON *lpp_message = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lppMessage");
    if (cJSON_IsNull(lpp_message)) {
        lpp_message = NULL;
    }
    if (lpp_message) { 
    lpp_message_local_nonprim = ref_to_binary_data_parseFromJSON(lpp_message); //nonprimitive
    }

    // input_data->lpp_message_ext
    cJSON *lpp_message_ext = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lppMessageExt");
    if (cJSON_IsNull(lpp_message_ext)) {
        lpp_message_ext = NULL;
    }
    if (lpp_message_ext) { 
    cJSON *lpp_message_ext_local_nonprimitive = NULL;
    if(!cJSON_IsArray(lpp_message_ext)){
        goto end; //nonprimitive container
    }

    lpp_message_extList = list_createList();

    cJSON_ArrayForEach(lpp_message_ext_local_nonprimitive,lpp_message_ext )
    {
        if(!cJSON_IsObject(lpp_message_ext_local_nonprimitive)){
            goto end;
        }
        ref_to_binary_data_t *lpp_message_extItem = ref_to_binary_data_parseFromJSON(lpp_message_ext_local_nonprimitive);

        list_addElement(lpp_message_extList, lpp_message_extItem);
    }
    }

    // input_data->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "supportedFeatures");
    if (cJSON_IsNull(supported_features)) {
        supported_features = NULL;
    }
    if (supported_features) { 
    if(!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features))
    {
    goto end; //String
    }
    }

    // input_data->ue_positioning_cap
    cJSON *ue_positioning_cap = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "uePositioningCap");
    if (cJSON_IsNull(ue_positioning_cap)) {
        ue_positioning_cap = NULL;
    }
    if (ue_positioning_cap) { 
    if(!cJSON_IsString(ue_positioning_cap))
    {
    goto end; //ByteArray
    }
    }

    // input_data->tnap_id
    cJSON *tnap_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "tnapId");
    if (cJSON_IsNull(tnap_id)) {
        tnap_id = NULL;
    }
    if (tnap_id) { 
    tnap_id_local_nonprim = tnap_id_parseFromJSON(tnap_id); //nonprimitive
    }

    // input_data->twap_id
    cJSON *twap_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "twapId");
    if (cJSON_IsNull(twap_id)) {
        twap_id = NULL;
    }
    if (twap_id) { 
    twap_id_local_nonprim = twap_id_parseFromJSON(twap_id); //nonprimitive
    }

    // input_data->ue_country_det_ind
    cJSON *ue_country_det_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueCountryDetInd");
    if (cJSON_IsNull(ue_country_det_ind)) {
        ue_country_det_ind = NULL;
    }
    if (ue_country_det_ind) { 
    if(!cJSON_IsBool(ue_country_det_ind))
    {
    goto end; //Bool
    }
    ue_country_det_ind_local_var = malloc(sizeof(int));
    if(!ue_country_det_ind_local_var)
    {
        goto end;
    }
    *ue_country_det_ind_local_var = ue_country_det_ind->valueint;
    }

    // input_data->scheduled_loc_time
    cJSON *scheduled_loc_time = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "scheduledLocTime");
    if (cJSON_IsNull(scheduled_loc_time)) {
        scheduled_loc_time = NULL;
    }
    if (scheduled_loc_time) { 
    if(!cJSON_IsString(scheduled_loc_time) && !cJSON_IsNull(scheduled_loc_time))
    {
    goto end; //DateTime
    }
    }

    // input_data->reliable_loc_req
    cJSON *reliable_loc_req = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "reliableLocReq");
    if (cJSON_IsNull(reliable_loc_req)) {
        reliable_loc_req = NULL;
    }
    if (reliable_loc_req) { 
    if(!cJSON_IsBool(reliable_loc_req))
    {
    goto end; //Bool
    }
    reliable_loc_req_local_var = malloc(sizeof(int));
    if(!reliable_loc_req_local_var)
    {
        goto end;
    }
    *reliable_loc_req_local_var = reliable_loc_req->valueint;
    }

    // input_data->evt_rpt_allowed_areas
    cJSON *evt_rpt_allowed_areas = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "evtRptAllowedAreas");
    if (cJSON_IsNull(evt_rpt_allowed_areas)) {
        evt_rpt_allowed_areas = NULL;
    }
    if (evt_rpt_allowed_areas) { 
    cJSON *evt_rpt_allowed_areas_local_nonprimitive = NULL;
    if(!cJSON_IsArray(evt_rpt_allowed_areas)){
        goto end; //nonprimitive container
    }

    evt_rpt_allowed_areasList = list_createList();

    cJSON_ArrayForEach(evt_rpt_allowed_areas_local_nonprimitive,evt_rpt_allowed_areas )
    {
        if(!cJSON_IsObject(evt_rpt_allowed_areas_local_nonprimitive)){
            goto end;
        }
        reporting_area_t *evt_rpt_allowed_areasItem = reporting_area_parseFromJSON(evt_rpt_allowed_areas_local_nonprimitive);

        list_addElement(evt_rpt_allowed_areasList, evt_rpt_allowed_areasItem);
    }
    }

    // input_data->ue_unaware_ind
    cJSON *ue_unaware_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueUnawareInd");
    if (cJSON_IsNull(ue_unaware_ind)) {
        ue_unaware_ind = NULL;
    }
    if (ue_unaware_ind) { 
    if(!cJSON_IsBool(ue_unaware_ind))
    {
    goto end; //Bool
    }
    ue_unaware_ind_local_var = malloc(sizeof(int));
    if(!ue_unaware_ind_local_var)
    {
        goto end;
    }
    *ue_unaware_ind_local_var = ue_unaware_ind->valueint;
    }

    // input_data->intermediate_location_ind
    cJSON *intermediate_location_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "intermediateLocationInd");
    if (cJSON_IsNull(intermediate_location_ind)) {
        intermediate_location_ind = NULL;
    }
    if (intermediate_location_ind) { 
    if(!cJSON_IsBool(intermediate_location_ind))
    {
    goto end; //Bool
    }
    intermediate_location_ind_local_var = malloc(sizeof(int));
    if(!intermediate_location_ind_local_var)
    {
        goto end;
    }
    *intermediate_location_ind_local_var = intermediate_location_ind->valueint;
    }

    // input_data->max_resp_time
    cJSON *max_resp_time = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "maxRespTime");
    if (cJSON_IsNull(max_resp_time)) {
        max_resp_time = NULL;
    }
    if (max_resp_time) { 
    if(!cJSON_IsNumber(max_resp_time))
    {
    goto end; //Numeric
    }
    max_resp_time_local_var = malloc(sizeof(int));
    if(!max_resp_time_local_var)
    {
        goto end;
    }
    *max_resp_time_local_var = max_resp_time->valuedouble;
    }

    // input_data->lp_hap_type
    cJSON *lp_hap_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "lpHapType");
    if (cJSON_IsNull(lp_hap_type)) {
        lp_hap_type = NULL;
    }
    if (lp_hap_type) { 
    lp_hap_type_local_nonprim = lp_hap_type_parseFromJSON(lp_hap_type); //nonprimitive
    }

    // input_data->ue_up_pos_caps
    cJSON *ue_up_pos_caps = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueUpPosCaps");
    if (cJSON_IsNull(ue_up_pos_caps)) {
        ue_up_pos_caps = NULL;
    }
    if (ue_up_pos_caps) { 
    cJSON *ue_up_pos_caps_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ue_up_pos_caps)){
        goto end; //nonprimitive container
    }

    ue_up_pos_capsList = list_createList();

    cJSON_ArrayForEach(ue_up_pos_caps_local_nonprimitive,ue_up_pos_caps )
    {
        if(!cJSON_IsObject(ue_up_pos_caps_local_nonprimitive)){
            goto end;
        }
        ue_up_positioning_capabilities_t *ue_up_pos_capsItem = ue_up_positioning_capabilities_parseFromJSON(ue_up_pos_caps_local_nonprimitive);

        list_addElement(ue_up_pos_capsList, ue_up_pos_capsItem);
    }
    }

    // input_data->reporting_ind
    cJSON *reporting_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "reportingInd");
    if (cJSON_IsNull(reporting_ind)) {
        reporting_ind = NULL;
    }
    if (reporting_ind) { 
    reporting_ind_local_nonprim = reporting_ind_parseFromJSON(reporting_ind); //nonprimitive
    }

    // input_data->mbsr_info
    cJSON *mbsr_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "mbsrInfo");
    if (cJSON_IsNull(mbsr_info)) {
        mbsr_info = NULL;
    }
    if (mbsr_info) { 
    mbsr_info_local_nonprim = mbsr_info_parseFromJSON(mbsr_info); //nonprimitive
    }

    // input_data->mwab_support_ind
    cJSON *mwab_support_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "mwabSupportInd");
    if (cJSON_IsNull(mwab_support_ind)) {
        mwab_support_ind = NULL;
    }
    if (mwab_support_ind) { 
    if(!cJSON_IsBool(mwab_support_ind))
    {
    goto end; //Bool
    }
    mwab_support_ind_local_var = malloc(sizeof(int));
    if(!mwab_support_ind_local_var)
    {
        goto end;
    }
    *mwab_support_ind_local_var = mwab_support_ind->valueint;
    }

    // input_data->integrity_requirements
    cJSON *integrity_requirements = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "integrityRequirements");
    if (cJSON_IsNull(integrity_requirements)) {
        integrity_requirements = NULL;
    }
    if (integrity_requirements) { 
    integrity_requirements_local_nonprim = integrity_requirements_parseFromJSON(integrity_requirements); //nonprimitive
    }

    // input_data->up_loc_rep_addr_af
    cJSON *up_loc_rep_addr_af = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "upLocRepAddrAf");
    if (cJSON_IsNull(up_loc_rep_addr_af)) {
        up_loc_rep_addr_af = NULL;
    }
    if (up_loc_rep_addr_af) { 
    up_loc_rep_addr_af_local_nonprim = up_loc_rep_addr_af_parseFromJSON(up_loc_rep_addr_af); //nonprimitive
    }

    // input_data->up_cum_evt_rpt_criteria
    cJSON *up_cum_evt_rpt_criteria = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "upCumEvtRptCriteria");
    if (cJSON_IsNull(up_cum_evt_rpt_criteria)) {
        up_cum_evt_rpt_criteria = NULL;
    }
    if (up_cum_evt_rpt_criteria) { 
    up_cum_evt_rpt_criteria_local_nonprim = up_cum_evt_rpt_criteria_parseFromJSON(up_cum_evt_rpt_criteria); //nonprimitive
    }

    // input_data->mapped_qo_s_eps
    cJSON *mapped_qo_s_eps = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "mappedQoSEps");
    if (cJSON_IsNull(mapped_qo_s_eps)) {
        mapped_qo_s_eps = NULL;
    }
    if (mapped_qo_s_eps) { 
    mapped_qo_s_eps_local_nonprim = mapped_location_qo_s_eps_parseFromJSON(mapped_qo_s_eps); //nonprimitive
    }

    // input_data->additional_ue_info
    cJSON *additional_ue_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "additionalUeInfo");
    if (cJSON_IsNull(additional_ue_info)) {
        additional_ue_info = NULL;
    }
    if (additional_ue_info) { 
    additional_ue_info_local_nonprim = additional_ue_info_parseFromJSON(additional_ue_info); //nonprimitive
    }

    // input_data->coordinate_id
    cJSON *coordinate_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "coordinateID");
    if (cJSON_IsNull(coordinate_id)) {
        coordinate_id = NULL;
    }
    if (coordinate_id) { 
    if(!cJSON_IsNumber(coordinate_id))
    {
    goto end; //Numeric
    }
    coordinate_id_local_var = malloc(sizeof(int));
    if(!coordinate_id_local_var)
    {
        goto end;
    }
    *coordinate_id_local_var = coordinate_id->valuedouble;
    }

    // input_data->ranging_sl_capability
    cJSON *ranging_sl_capability = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "rangingSlCapability");
    if (cJSON_IsNull(ranging_sl_capability)) {
        ranging_sl_capability = NULL;
    }
    if (ranging_sl_capability) { 
    if(!cJSON_IsString(ranging_sl_capability))
    {
    goto end; //ByteArray
    }
    }

    // input_data->sl_positioning_capabilities
    cJSON *sl_positioning_capabilities = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "slPositioningCapabilities");
    if (cJSON_IsNull(sl_positioning_capabilities)) {
        sl_positioning_capabilities = NULL;
    }
    if (sl_positioning_capabilities) { 
    cJSON *sl_positioning_capabilities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(sl_positioning_capabilities)){
        goto end; //nonprimitive container
    }

    sl_positioning_capabilitiesList = list_createList();

    cJSON_ArrayForEach(sl_positioning_capabilities_local_nonprimitive,sl_positioning_capabilities )
    {
        if(!cJSON_IsObject(sl_positioning_capabilities_local_nonprimitive)){
            goto end;
        }
        sl_positioning_capability_t *sl_positioning_capabilitiesItem = sl_positioning_capability_parseFromJSON(sl_positioning_capabilities_local_nonprimitive);

        list_addElement(sl_positioning_capabilitiesList, sl_positioning_capabilitiesItem);
    }
    }

    // input_data->extended_facility_ind
    cJSON *extended_facility_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "extendedFacilityInd");
    if (cJSON_IsNull(extended_facility_ind)) {
        extended_facility_ind = NULL;
    }
    if (extended_facility_ind) { 
    if(!cJSON_IsBool(extended_facility_ind))
    {
    goto end; //Bool
    }
    extended_facility_ind_local_var = malloc(sizeof(int));
    if(!extended_facility_ind_local_var)
    {
        goto end;
    }
    *extended_facility_ind_local_var = extended_facility_ind->valueint;
    }


    if (correlation_id && !cJSON_IsNull(correlation_id)) correlation_id_local_str = strdup(correlation_id->valuestring);
    if (amf_id && !cJSON_IsNull(amf_id)) amf_id_local_str = strdup(amf_id->valuestring);
    if (supi && !cJSON_IsNull(supi)) supi_local_str = strdup(supi->valuestring);
    if (pei && !cJSON_IsNull(pei)) pei_local_str = strdup(pei->valuestring);
    if (gpsi && !cJSON_IsNull(gpsi)) gpsi_local_str = strdup(gpsi->valuestring);
    if (hgmlc_call_back_uri && !cJSON_IsNull(hgmlc_call_back_uri)) hgmlc_call_back_uri_local_str = strdup(hgmlc_call_back_uri->valuestring);
    if (lir_gmlc_call_back_uri && !cJSON_IsNull(lir_gmlc_call_back_uri)) lir_gmlc_call_back_uri_local_str = strdup(lir_gmlc_call_back_uri->valuestring);
    if (vgmlc_address && !cJSON_IsNull(vgmlc_address)) vgmlc_address_local_str = strdup(vgmlc_address->valuestring);
    if (ldr_reference && !cJSON_IsNull(ldr_reference)) ldr_reference_local_str = strdup(ldr_reference->valuestring);
    if (lir_reference && !cJSON_IsNull(lir_reference)) lir_reference_local_str = strdup(lir_reference->valuestring);
    if (supported_features && !cJSON_IsNull(supported_features)) supported_features_local_str = strdup(supported_features->valuestring);
    if (ue_positioning_cap) ue_positioning_cap_local_str = strdup(ue_positioning_cap->valuestring);
    if (scheduled_loc_time && !cJSON_IsNull(scheduled_loc_time)) scheduled_loc_time_local_str = strdup(scheduled_loc_time->valuestring);
    if (ranging_sl_capability) ranging_sl_capability_local_str = strdup(ranging_sl_capability->valuestring);

    input_data_local_var = input_data_create_internal (
        external_client_type ? external_client_type_local_nonprim : NULL,
        correlation_id_local_str,
        amf_id_local_str,
        location_qo_s ? location_qo_s_local_nonprim : NULL,
        supported_gad_shapes ? supported_gad_shapesList : NULL,
        supi_local_str,
        pei_local_str,
        gpsi_local_str,
        requested_ranging_sl_result ? requested_ranging_sl_resultList : NULL,
        related_ues ? related_uesList : NULL,
        ecgi ? ecgi_local_nonprim : NULL,
        ecgi_on_second_node ? ecgi_on_second_node_local_nonprim : NULL,
        ncgi ? ncgi_local_nonprim : NULL,
        ncgi_on_second_node ? ncgi_on_second_node_local_nonprim : NULL,
        priority ? priority_local_nonprim : NULL,
        velocity_requested ? velocity_requested_local_nonprim : NULL,
        ue_lcs_cap ? ue_lcs_cap_local_nonprim : NULL,
        lcs_service_type_local_var,
        ldr_type ? ldr_type_local_nonprim : NULL,
        hgmlc_call_back_uri_local_str,
        lir_gmlc_call_back_uri_local_str,
        vgmlc_address_local_str,
        ldr_reference_local_str,
        lir_reference_local_str,
        periodic_event_info ? periodic_event_info_local_nonprim : NULL,
        area_event_info ? area_event_info_local_nonprim : NULL,
        motion_event_info ? motion_event_info_local_nonprim : NULL,
        reporting_access_types ? reporting_access_typesList : NULL,
        ue_connectivity_states ? ue_connectivity_states_local_nonprim : NULL,
        ue_location_service_ind ? ue_location_service_ind_local_nonprim : NULL,
        mo_assistance_data_types ? mo_assistance_data_types_local_nonprim : NULL,
        lpp_message ? lpp_message_local_nonprim : NULL,
        lpp_message_ext ? lpp_message_extList : NULL,
        supported_features_local_str,
        ue_positioning_cap_local_str,
        tnap_id ? tnap_id_local_nonprim : NULL,
        twap_id ? twap_id_local_nonprim : NULL,
        ue_country_det_ind_local_var,
        scheduled_loc_time_local_str,
        reliable_loc_req_local_var,
        evt_rpt_allowed_areas ? evt_rpt_allowed_areasList : NULL,
        ue_unaware_ind_local_var,
        intermediate_location_ind_local_var,
        max_resp_time_local_var,
        lp_hap_type ? lp_hap_type_local_nonprim : NULL,
        ue_up_pos_caps ? ue_up_pos_capsList : NULL,
        reporting_ind ? reporting_ind_local_nonprim : NULL,
        mbsr_info ? mbsr_info_local_nonprim : NULL,
        mwab_support_ind_local_var,
        integrity_requirements ? integrity_requirements_local_nonprim : NULL,
        up_loc_rep_addr_af ? up_loc_rep_addr_af_local_nonprim : NULL,
        up_cum_evt_rpt_criteria ? up_cum_evt_rpt_criteria_local_nonprim : NULL,
        mapped_qo_s_eps ? mapped_qo_s_eps_local_nonprim : NULL,
        additional_ue_info ? additional_ue_info_local_nonprim : NULL,
        coordinate_id_local_var,
        ranging_sl_capability_local_str,
        sl_positioning_capabilities ? sl_positioning_capabilitiesList : NULL,
        extended_facility_ind_local_var
        );

    if (!input_data_local_var) {
        goto end;
    }

    return input_data_local_var;
end:
    if (external_client_type_local_nonprim) {
        external_client_type_free(external_client_type_local_nonprim);
        external_client_type_local_nonprim = NULL;
    }
    if (correlation_id_local_str) {
        free(correlation_id_local_str);
        correlation_id_local_str = NULL;
    }
    if (amf_id_local_str) {
        free(amf_id_local_str);
        amf_id_local_str = NULL;
    }
    if (location_qo_s_local_nonprim) {
        location_qo_s_free(location_qo_s_local_nonprim);
        location_qo_s_local_nonprim = NULL;
    }
    if (supported_gad_shapesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, supported_gad_shapesList) {
            supported_gad_shapes_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(supported_gad_shapesList);
        supported_gad_shapesList = NULL;
    }
    if (supi_local_str) {
        free(supi_local_str);
        supi_local_str = NULL;
    }
    if (pei_local_str) {
        free(pei_local_str);
        pei_local_str = NULL;
    }
    if (gpsi_local_str) {
        free(gpsi_local_str);
        gpsi_local_str = NULL;
    }
    if (requested_ranging_sl_resultList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requested_ranging_sl_resultList) {
            ranging_sl_result_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requested_ranging_sl_resultList);
        requested_ranging_sl_resultList = NULL;
    }
    if (related_uesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, related_uesList) {
            related_ue_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(related_uesList);
        related_uesList = NULL;
    }
    if (ecgi_local_nonprim) {
        ecgi_free(ecgi_local_nonprim);
        ecgi_local_nonprim = NULL;
    }
    if (ecgi_on_second_node_local_nonprim) {
        ecgi_free(ecgi_on_second_node_local_nonprim);
        ecgi_on_second_node_local_nonprim = NULL;
    }
    if (ncgi_local_nonprim) {
        ncgi_free(ncgi_local_nonprim);
        ncgi_local_nonprim = NULL;
    }
    if (ncgi_on_second_node_local_nonprim) {
        ncgi_free(ncgi_on_second_node_local_nonprim);
        ncgi_on_second_node_local_nonprim = NULL;
    }
    if (priority_local_nonprim) {
        lcs_priority_free(priority_local_nonprim);
        priority_local_nonprim = NULL;
    }
    if (velocity_requested_local_nonprim) {
        velocity_requested_free(velocity_requested_local_nonprim);
        velocity_requested_local_nonprim = NULL;
    }
    if (ue_lcs_cap_local_nonprim) {
        ue_lcs_capability_free(ue_lcs_cap_local_nonprim);
        ue_lcs_cap_local_nonprim = NULL;
    }
    if (lcs_service_type_local_var) {
        free(lcs_service_type_local_var);
        lcs_service_type_local_var = NULL;
    }
    if (ldr_type_local_nonprim) {
        ldr_type_free(ldr_type_local_nonprim);
        ldr_type_local_nonprim = NULL;
    }
    if (hgmlc_call_back_uri_local_str) {
        free(hgmlc_call_back_uri_local_str);
        hgmlc_call_back_uri_local_str = NULL;
    }
    if (lir_gmlc_call_back_uri_local_str) {
        free(lir_gmlc_call_back_uri_local_str);
        lir_gmlc_call_back_uri_local_str = NULL;
    }
    if (vgmlc_address_local_str) {
        free(vgmlc_address_local_str);
        vgmlc_address_local_str = NULL;
    }
    if (ldr_reference_local_str) {
        free(ldr_reference_local_str);
        ldr_reference_local_str = NULL;
    }
    if (lir_reference_local_str) {
        free(lir_reference_local_str);
        lir_reference_local_str = NULL;
    }
    if (periodic_event_info_local_nonprim) {
        periodic_event_info_free(periodic_event_info_local_nonprim);
        periodic_event_info_local_nonprim = NULL;
    }
    if (area_event_info_local_nonprim) {
        area_event_info_free(area_event_info_local_nonprim);
        area_event_info_local_nonprim = NULL;
    }
    if (motion_event_info_local_nonprim) {
        motion_event_info_free(motion_event_info_local_nonprim);
        motion_event_info_local_nonprim = NULL;
    }
    if (reporting_access_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, reporting_access_typesList) {
            reporting_access_type_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(reporting_access_typesList);
        reporting_access_typesList = NULL;
    }
    if (ue_connectivity_states_local_nonprim) {
        ue_connectivity_state_free(ue_connectivity_states_local_nonprim);
        ue_connectivity_states_local_nonprim = NULL;
    }
    if (ue_location_service_ind_local_nonprim) {
        ue_location_service_ind_free(ue_location_service_ind_local_nonprim);
        ue_location_service_ind_local_nonprim = NULL;
    }
    if (mo_assistance_data_types_local_nonprim) {
        lcs_broadcast_assistance_types_data_free(mo_assistance_data_types_local_nonprim);
        mo_assistance_data_types_local_nonprim = NULL;
    }
    if (lpp_message_local_nonprim) {
        ref_to_binary_data_free(lpp_message_local_nonprim);
        lpp_message_local_nonprim = NULL;
    }
    if (lpp_message_extList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, lpp_message_extList) {
            ref_to_binary_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(lpp_message_extList);
        lpp_message_extList = NULL;
    }
    if (supported_features_local_str) {
        free(supported_features_local_str);
        supported_features_local_str = NULL;
    }
    if (ue_positioning_cap_local_str) {
        free(ue_positioning_cap_local_str);
        ue_positioning_cap_local_str = NULL;
    }
    if (tnap_id_local_nonprim) {
        tnap_id_free(tnap_id_local_nonprim);
        tnap_id_local_nonprim = NULL;
    }
    if (twap_id_local_nonprim) {
        twap_id_free(twap_id_local_nonprim);
        twap_id_local_nonprim = NULL;
    }
    if (ue_country_det_ind_local_var) {
        free(ue_country_det_ind_local_var);
        ue_country_det_ind_local_var = NULL;
    }
    if (scheduled_loc_time_local_str) {
        free(scheduled_loc_time_local_str);
        scheduled_loc_time_local_str = NULL;
    }
    if (reliable_loc_req_local_var) {
        free(reliable_loc_req_local_var);
        reliable_loc_req_local_var = NULL;
    }
    if (evt_rpt_allowed_areasList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, evt_rpt_allowed_areasList) {
            reporting_area_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(evt_rpt_allowed_areasList);
        evt_rpt_allowed_areasList = NULL;
    }
    if (ue_unaware_ind_local_var) {
        free(ue_unaware_ind_local_var);
        ue_unaware_ind_local_var = NULL;
    }
    if (intermediate_location_ind_local_var) {
        free(intermediate_location_ind_local_var);
        intermediate_location_ind_local_var = NULL;
    }
    if (max_resp_time_local_var) {
        free(max_resp_time_local_var);
        max_resp_time_local_var = NULL;
    }
    if (lp_hap_type_local_nonprim) {
        lp_hap_type_free(lp_hap_type_local_nonprim);
        lp_hap_type_local_nonprim = NULL;
    }
    if (ue_up_pos_capsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ue_up_pos_capsList) {
            ue_up_positioning_capabilities_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ue_up_pos_capsList);
        ue_up_pos_capsList = NULL;
    }
    if (reporting_ind_local_nonprim) {
        reporting_ind_free(reporting_ind_local_nonprim);
        reporting_ind_local_nonprim = NULL;
    }
    if (mbsr_info_local_nonprim) {
        mbsr_info_free(mbsr_info_local_nonprim);
        mbsr_info_local_nonprim = NULL;
    }
    if (mwab_support_ind_local_var) {
        free(mwab_support_ind_local_var);
        mwab_support_ind_local_var = NULL;
    }
    if (integrity_requirements_local_nonprim) {
        integrity_requirements_free(integrity_requirements_local_nonprim);
        integrity_requirements_local_nonprim = NULL;
    }
    if (up_loc_rep_addr_af_local_nonprim) {
        up_loc_rep_addr_af_free(up_loc_rep_addr_af_local_nonprim);
        up_loc_rep_addr_af_local_nonprim = NULL;
    }
    if (up_cum_evt_rpt_criteria_local_nonprim) {
        up_cum_evt_rpt_criteria_free(up_cum_evt_rpt_criteria_local_nonprim);
        up_cum_evt_rpt_criteria_local_nonprim = NULL;
    }
    if (mapped_qo_s_eps_local_nonprim) {
        mapped_location_qo_s_eps_free(mapped_qo_s_eps_local_nonprim);
        mapped_qo_s_eps_local_nonprim = NULL;
    }
    if (additional_ue_info_local_nonprim) {
        additional_ue_info_free(additional_ue_info_local_nonprim);
        additional_ue_info_local_nonprim = NULL;
    }
    if (coordinate_id_local_var) {
        free(coordinate_id_local_var);
        coordinate_id_local_var = NULL;
    }
    if (ranging_sl_capability_local_str) {
        free(ranging_sl_capability_local_str);
        ranging_sl_capability_local_str = NULL;
    }
    if (sl_positioning_capabilitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, sl_positioning_capabilitiesList) {
            sl_positioning_capability_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(sl_positioning_capabilitiesList);
        sl_positioning_capabilitiesList = NULL;
    }
    if (extended_facility_ind_local_var) {
        free(extended_facility_ind_local_var);
        extended_facility_ind_local_var = NULL;
    }
    return NULL;

}
