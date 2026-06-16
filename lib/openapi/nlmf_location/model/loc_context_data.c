#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_context_data.h"



static loc_context_data_t *loc_context_data_create_internal(
    char *amf_id,
    location_qo_s_t *location_qo_s,
    list_t *supported_gad_shapes,
    char *supi,
    char *gpsi,
    list_t *add_loc_context_list,
    ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    periodic_event_info_t *periodic_event_info,
    area_event_info_t *area_event_info,
    motion_event_info_t *motion_event_info,
    event_report_message_t *event_report_message,
    event_reporting_status_t *event_reporting_status,
    ue_location_info_t *ue_location_info,
    int *c_io_t5_gs_optimisation,
    ecgi_t *ecgi,
    ncgi_t *ncgi,
    guami_t *guami,
    char *supported_features,
    char *ue_positioning_cap,
    list_t *ue_up_pos_caps,
    char *scheduled_loc_time,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    int *lcs_upp_exist_ind,
    char *src_lmf_routing_info,
    int *extended_facility_ind
    ) {
    loc_context_data_t *loc_context_data_local_var = malloc(sizeof(loc_context_data_t));
    if (!loc_context_data_local_var) {
        return NULL;
    }
    memset(loc_context_data_local_var, 0, sizeof(loc_context_data_t));
    loc_context_data_local_var->_library_owned = 1;
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
    loc_context_data_local_var->lcs_upp_exist_ind = lcs_upp_exist_ind;
    loc_context_data_local_var->src_lmf_routing_info = src_lmf_routing_info;
    loc_context_data_local_var->extended_facility_ind = extended_facility_ind;
    return loc_context_data_local_var;
}

__attribute__((deprecated)) loc_context_data_t *loc_context_data_create(
    char *amf_id,
    location_qo_s_t *location_qo_s,
    list_t *supported_gad_shapes,
    char *supi,
    char *gpsi,
    list_t *add_loc_context_list,
    ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    periodic_event_info_t *periodic_event_info,
    area_event_info_t *area_event_info,
    motion_event_info_t *motion_event_info,
    event_report_message_t *event_report_message,
    event_reporting_status_t *event_reporting_status,
    ue_location_info_t *ue_location_info,
    int *c_io_t5_gs_optimisation,
    ecgi_t *ecgi,
    ncgi_t *ncgi,
    guami_t *guami,
    char *supported_features,
    char *ue_positioning_cap,
    list_t *ue_up_pos_caps,
    char *scheduled_loc_time,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    int *lcs_upp_exist_ind,
    char *src_lmf_routing_info,
    int *extended_facility_ind
    ) {
    int *c_io_t5_gs_optimisation_copy = NULL;
    if (c_io_t5_gs_optimisation) {
        c_io_t5_gs_optimisation_copy = malloc(sizeof(int));
        if (c_io_t5_gs_optimisation_copy) *c_io_t5_gs_optimisation_copy = *c_io_t5_gs_optimisation;
    }
    int *lcs_upp_exist_ind_copy = NULL;
    if (lcs_upp_exist_ind) {
        lcs_upp_exist_ind_copy = malloc(sizeof(int));
        if (lcs_upp_exist_ind_copy) *lcs_upp_exist_ind_copy = *lcs_upp_exist_ind;
    }
    int *extended_facility_ind_copy = NULL;
    if (extended_facility_ind) {
        extended_facility_ind_copy = malloc(sizeof(int));
        if (extended_facility_ind_copy) *extended_facility_ind_copy = *extended_facility_ind;
    }
    loc_context_data_t *result = loc_context_data_create_internal (
        amf_id,
        location_qo_s,
        supported_gad_shapes,
        supi,
        gpsi,
        add_loc_context_list,
        ldr_type,
        hgmlc_call_back_uri,
        ldr_reference,
        periodic_event_info,
        area_event_info,
        motion_event_info,
        event_report_message,
        event_reporting_status,
        ue_location_info,
        c_io_t5_gs_optimisation_copy,
        ecgi,
        ncgi,
        guami,
        supported_features,
        ue_positioning_cap,
        ue_up_pos_caps,
        scheduled_loc_time,
        indoor_outdoor_ind,
        los_nlos_measure_ind,
        up_cum_evt_rpt_criteria,
        lcs_upp_exist_ind_copy,
        src_lmf_routing_info,
        extended_facility_ind_copy
        );
    if (!result) {
        free(c_io_t5_gs_optimisation_copy);
        free(lcs_upp_exist_ind_copy);
        free(extended_facility_ind_copy);
    }
    return result;
}

void loc_context_data_free(loc_context_data_t *loc_context_data) {
    if(NULL == loc_context_data){
        return ;
    }
    if(loc_context_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "loc_context_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (loc_context_data->amf_id) {
        free(loc_context_data->amf_id);
        loc_context_data->amf_id = NULL;
    }
    if (loc_context_data->location_qo_s) {
        location_qo_s_free(loc_context_data->location_qo_s);
        loc_context_data->location_qo_s = NULL;
    }
    if (loc_context_data->supported_gad_shapes) {
        list_ForEach(listEntry, loc_context_data->supported_gad_shapes) {
            supported_gad_shapes_free(listEntry->data);
        }
        list_freeList(loc_context_data->supported_gad_shapes);
        loc_context_data->supported_gad_shapes = NULL;
    }
    if (loc_context_data->supi) {
        free(loc_context_data->supi);
        loc_context_data->supi = NULL;
    }
    if (loc_context_data->gpsi) {
        free(loc_context_data->gpsi);
        loc_context_data->gpsi = NULL;
    }
    if (loc_context_data->add_loc_context_list) {
        list_ForEach(listEntry, loc_context_data->add_loc_context_list) {
            add_location_context_free(listEntry->data);
        }
        list_freeList(loc_context_data->add_loc_context_list);
        loc_context_data->add_loc_context_list = NULL;
    }
    if (loc_context_data->ldr_type) {
        ldr_type_free(loc_context_data->ldr_type);
        loc_context_data->ldr_type = NULL;
    }
    if (loc_context_data->hgmlc_call_back_uri) {
        free(loc_context_data->hgmlc_call_back_uri);
        loc_context_data->hgmlc_call_back_uri = NULL;
    }
    if (loc_context_data->ldr_reference) {
        free(loc_context_data->ldr_reference);
        loc_context_data->ldr_reference = NULL;
    }
    if (loc_context_data->periodic_event_info) {
        periodic_event_info_free(loc_context_data->periodic_event_info);
        loc_context_data->periodic_event_info = NULL;
    }
    if (loc_context_data->area_event_info) {
        area_event_info_free(loc_context_data->area_event_info);
        loc_context_data->area_event_info = NULL;
    }
    if (loc_context_data->motion_event_info) {
        motion_event_info_free(loc_context_data->motion_event_info);
        loc_context_data->motion_event_info = NULL;
    }
    if (loc_context_data->event_report_message) {
        event_report_message_free(loc_context_data->event_report_message);
        loc_context_data->event_report_message = NULL;
    }
    if (loc_context_data->event_reporting_status) {
        event_reporting_status_free(loc_context_data->event_reporting_status);
        loc_context_data->event_reporting_status = NULL;
    }
    if (loc_context_data->ue_location_info) {
        ue_location_info_free(loc_context_data->ue_location_info);
        loc_context_data->ue_location_info = NULL;
    }
    if (loc_context_data->c_io_t5_gs_optimisation) {
        free(loc_context_data->c_io_t5_gs_optimisation);
        loc_context_data->c_io_t5_gs_optimisation = NULL;
    }
    if (loc_context_data->ecgi) {
        ecgi_free(loc_context_data->ecgi);
        loc_context_data->ecgi = NULL;
    }
    if (loc_context_data->ncgi) {
        ncgi_free(loc_context_data->ncgi);
        loc_context_data->ncgi = NULL;
    }
    if (loc_context_data->guami) {
        guami_free(loc_context_data->guami);
        loc_context_data->guami = NULL;
    }
    if (loc_context_data->supported_features) {
        free(loc_context_data->supported_features);
        loc_context_data->supported_features = NULL;
    }
    if (loc_context_data->ue_positioning_cap) {
        free(loc_context_data->ue_positioning_cap);
        loc_context_data->ue_positioning_cap = NULL;
    }
    if (loc_context_data->ue_up_pos_caps) {
        list_ForEach(listEntry, loc_context_data->ue_up_pos_caps) {
            ue_up_positioning_capabilities_free(listEntry->data);
        }
        list_freeList(loc_context_data->ue_up_pos_caps);
        loc_context_data->ue_up_pos_caps = NULL;
    }
    if (loc_context_data->scheduled_loc_time) {
        free(loc_context_data->scheduled_loc_time);
        loc_context_data->scheduled_loc_time = NULL;
    }
    if (loc_context_data->indoor_outdoor_ind) {
        indoor_outdoor_ind_free(loc_context_data->indoor_outdoor_ind);
        loc_context_data->indoor_outdoor_ind = NULL;
    }
    if (loc_context_data->los_nlos_measure_ind) {
        los_nlos_measure_ind_free(loc_context_data->los_nlos_measure_ind);
        loc_context_data->los_nlos_measure_ind = NULL;
    }
    if (loc_context_data->up_cum_evt_rpt_criteria) {
        up_cum_evt_rpt_criteria_free(loc_context_data->up_cum_evt_rpt_criteria);
        loc_context_data->up_cum_evt_rpt_criteria = NULL;
    }
    if (loc_context_data->lcs_upp_exist_ind) {
        free(loc_context_data->lcs_upp_exist_ind);
        loc_context_data->lcs_upp_exist_ind = NULL;
    }
    if (loc_context_data->src_lmf_routing_info) {
        free(loc_context_data->src_lmf_routing_info);
        loc_context_data->src_lmf_routing_info = NULL;
    }
    if (loc_context_data->extended_facility_ind) {
        free(loc_context_data->extended_facility_ind);
        loc_context_data->extended_facility_ind = NULL;
    }
    free(loc_context_data);
}

cJSON *loc_context_data_convertToJSON(loc_context_data_t *loc_context_data) {
    cJSON *item = cJSON_CreateObject();

    // loc_context_data->amf_id
    if (!loc_context_data->amf_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amfId", loc_context_data->amf_id) == NULL) {
    goto fail; //String
    }


    // loc_context_data->location_qo_s
    if(loc_context_data->location_qo_s) {
    cJSON *location_qo_s_local_JSON = location_qo_s_convertToJSON(loc_context_data->location_qo_s);
    if(location_qo_s_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "locationQoS", location_qo_s_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->supported_gad_shapes
    if(loc_context_data->supported_gad_shapes) {
    cJSON *supported_gad_shapes = cJSON_AddArrayToObject(item, "supportedGADShapes");
    if(supported_gad_shapes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *supported_gad_shapesListEntry;
    if (loc_context_data->supported_gad_shapes) {
    list_ForEach(supported_gad_shapesListEntry, loc_context_data->supported_gad_shapes) {
    cJSON *itemLocal = supported_gad_shapes_convertToJSON(supported_gad_shapesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(supported_gad_shapes, itemLocal);
    }
    }
    }


    // loc_context_data->supi
    if(loc_context_data->supi) {
    if(cJSON_AddStringToObject(item, "supi", loc_context_data->supi) == NULL) {
    goto fail; //String
    }
    }


    // loc_context_data->gpsi
    if(loc_context_data->gpsi) {
    if(cJSON_AddStringToObject(item, "gpsi", loc_context_data->gpsi) == NULL) {
    goto fail; //String
    }
    }


    // loc_context_data->add_loc_context_list
    if(loc_context_data->add_loc_context_list) {
    cJSON *add_loc_context_list = cJSON_AddArrayToObject(item, "addLocContextList");
    if(add_loc_context_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *add_loc_context_listListEntry;
    if (loc_context_data->add_loc_context_list) {
    list_ForEach(add_loc_context_listListEntry, loc_context_data->add_loc_context_list) {
    cJSON *itemLocal = add_location_context_convertToJSON(add_loc_context_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(add_loc_context_list, itemLocal);
    }
    }
    }


    // loc_context_data->ldr_type
    if (!loc_context_data->ldr_type) {
        goto fail;
    }
    cJSON *ldr_type_local_JSON = ldr_type_convertToJSON(loc_context_data->ldr_type);
    if(ldr_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ldrType", ldr_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // loc_context_data->hgmlc_call_back_uri
    if (!loc_context_data->hgmlc_call_back_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hgmlcCallBackURI", loc_context_data->hgmlc_call_back_uri) == NULL) {
    goto fail; //String
    }


    // loc_context_data->ldr_reference
    if (!loc_context_data->ldr_reference) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ldrReference", loc_context_data->ldr_reference) == NULL) {
    goto fail; //String
    }


    // loc_context_data->periodic_event_info
    if(loc_context_data->periodic_event_info) {
    cJSON *periodic_event_info_local_JSON = periodic_event_info_convertToJSON(loc_context_data->periodic_event_info);
    if(periodic_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "periodicEventInfo", periodic_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->area_event_info
    if(loc_context_data->area_event_info) {
    cJSON *area_event_info_local_JSON = area_event_info_convertToJSON(loc_context_data->area_event_info);
    if(area_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "areaEventInfo", area_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->motion_event_info
    if(loc_context_data->motion_event_info) {
    cJSON *motion_event_info_local_JSON = motion_event_info_convertToJSON(loc_context_data->motion_event_info);
    if(motion_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "motionEventInfo", motion_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->event_report_message
    if (!loc_context_data->event_report_message) {
        goto fail;
    }
    cJSON *event_report_message_local_JSON = event_report_message_convertToJSON(loc_context_data->event_report_message);
    if(event_report_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "eventReportMessage", event_report_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // loc_context_data->event_reporting_status
    if(loc_context_data->event_reporting_status) {
    cJSON *event_reporting_status_local_JSON = event_reporting_status_convertToJSON(loc_context_data->event_reporting_status);
    if(event_reporting_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "eventReportingStatus", event_reporting_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->ue_location_info
    if(loc_context_data->ue_location_info) {
    cJSON *ue_location_info_local_JSON = ue_location_info_convertToJSON(loc_context_data->ue_location_info);
    if(ue_location_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ueLocationInfo", ue_location_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->c_io_t5_gs_optimisation
    if(loc_context_data->c_io_t5_gs_optimisation) {
    if(cJSON_AddBoolToObject(item, "cIoT5GSOptimisation", *loc_context_data->c_io_t5_gs_optimisation) == NULL) {
    goto fail; //Bool
    }
    }


    // loc_context_data->ecgi
    if(loc_context_data->ecgi) {
    cJSON *ecgi_local_JSON = ecgi_convertToJSON(loc_context_data->ecgi);
    if(ecgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->ncgi
    if(loc_context_data->ncgi) {
    cJSON *ncgi_local_JSON = ncgi_convertToJSON(loc_context_data->ncgi);
    if(ncgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->guami
    if(loc_context_data->guami) {
    cJSON *guami_local_JSON = guami_convertToJSON(loc_context_data->guami);
    if(guami_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "guami", guami_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->supported_features
    if(loc_context_data->supported_features) {
    if(cJSON_AddStringToObject(item, "supportedFeatures", loc_context_data->supported_features) == NULL) {
    goto fail; //String
    }
    }


    // loc_context_data->ue_positioning_cap
    if(loc_context_data->ue_positioning_cap) {
    if(cJSON_AddStringToObject(item, "uePositioningCap", loc_context_data->ue_positioning_cap) == NULL) {
    goto fail; //ByteArray
    }
    }


    // loc_context_data->ue_up_pos_caps
    if(loc_context_data->ue_up_pos_caps) {
    cJSON *ue_up_pos_caps = cJSON_AddArrayToObject(item, "ueUpPosCaps");
    if(ue_up_pos_caps == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ue_up_pos_capsListEntry;
    if (loc_context_data->ue_up_pos_caps) {
    list_ForEach(ue_up_pos_capsListEntry, loc_context_data->ue_up_pos_caps) {
    cJSON *itemLocal = ue_up_positioning_capabilities_convertToJSON(ue_up_pos_capsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ue_up_pos_caps, itemLocal);
    }
    }
    }


    // loc_context_data->scheduled_loc_time
    if(loc_context_data->scheduled_loc_time) {
    if(cJSON_AddStringToObject(item, "scheduledLocTime", loc_context_data->scheduled_loc_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // loc_context_data->indoor_outdoor_ind
    if(loc_context_data->indoor_outdoor_ind) {
    cJSON *indoor_outdoor_ind_local_JSON = indoor_outdoor_ind_convertToJSON(loc_context_data->indoor_outdoor_ind);
    if(indoor_outdoor_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "indoorOutdoorInd", indoor_outdoor_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->los_nlos_measure_ind
    if(loc_context_data->los_nlos_measure_ind) {
    cJSON *los_nlos_measure_ind_local_JSON = los_nlos_measure_ind_convertToJSON(loc_context_data->los_nlos_measure_ind);
    if(los_nlos_measure_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "losNlosMeasureInd", los_nlos_measure_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->up_cum_evt_rpt_criteria
    if(loc_context_data->up_cum_evt_rpt_criteria) {
    cJSON *up_cum_evt_rpt_criteria_local_JSON = up_cum_evt_rpt_criteria_convertToJSON(loc_context_data->up_cum_evt_rpt_criteria);
    if(up_cum_evt_rpt_criteria_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "upCumEvtRptCriteria", up_cum_evt_rpt_criteria_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_context_data->lcs_upp_exist_ind
    if(loc_context_data->lcs_upp_exist_ind) {
    if(cJSON_AddBoolToObject(item, "lcsUppExistInd", *loc_context_data->lcs_upp_exist_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // loc_context_data->src_lmf_routing_info
    if(loc_context_data->src_lmf_routing_info) {
    if(cJSON_AddStringToObject(item, "srcLmfRoutingInfo", loc_context_data->src_lmf_routing_info) == NULL) {
    goto fail; //String
    }
    }


    // loc_context_data->extended_facility_ind
    if(loc_context_data->extended_facility_ind) {
    if(cJSON_AddBoolToObject(item, "extendedFacilityInd", *loc_context_data->extended_facility_ind) == NULL) {
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

loc_context_data_t *loc_context_data_parseFromJSON(cJSON *loc_context_dataJSON){

    loc_context_data_t *loc_context_data_local_var = NULL;

    char *amf_id_local_str = NULL;

    // define the local variable for loc_context_data->location_qo_s
    location_qo_s_t *location_qo_s_local_nonprim = NULL;

    // define the local list for loc_context_data->supported_gad_shapes
    list_t *supported_gad_shapesList = NULL;

    char *supi_local_str = NULL;

    char *gpsi_local_str = NULL;

    // define the local list for loc_context_data->add_loc_context_list
    list_t *add_loc_context_listList = NULL;

    // define the local variable for loc_context_data->ldr_type
    ldr_type_t *ldr_type_local_nonprim = NULL;

    char *hgmlc_call_back_uri_local_str = NULL;

    char *ldr_reference_local_str = NULL;

    // define the local variable for loc_context_data->periodic_event_info
    periodic_event_info_t *periodic_event_info_local_nonprim = NULL;

    // define the local variable for loc_context_data->area_event_info
    area_event_info_t *area_event_info_local_nonprim = NULL;

    // define the local variable for loc_context_data->motion_event_info
    motion_event_info_t *motion_event_info_local_nonprim = NULL;

    // define the local variable for loc_context_data->event_report_message
    event_report_message_t *event_report_message_local_nonprim = NULL;

    // define the local variable for loc_context_data->event_reporting_status
    event_reporting_status_t *event_reporting_status_local_nonprim = NULL;

    // define the local variable for loc_context_data->ue_location_info
    ue_location_info_t *ue_location_info_local_nonprim = NULL;

    // define the local variable for loc_context_data->c_io_t5_gs_optimisation
    int *c_io_t5_gs_optimisation_local_var = NULL;

    // define the local variable for loc_context_data->ecgi
    ecgi_t *ecgi_local_nonprim = NULL;

    // define the local variable for loc_context_data->ncgi
    ncgi_t *ncgi_local_nonprim = NULL;

    // define the local variable for loc_context_data->guami
    guami_t *guami_local_nonprim = NULL;

    char *supported_features_local_str = NULL;

    char *ue_positioning_cap_local_str = NULL;

    // define the local list for loc_context_data->ue_up_pos_caps
    list_t *ue_up_pos_capsList = NULL;

    char *scheduled_loc_time_local_str = NULL;

    // define the local variable for loc_context_data->indoor_outdoor_ind
    indoor_outdoor_ind_t *indoor_outdoor_ind_local_nonprim = NULL;

    // define the local variable for loc_context_data->los_nlos_measure_ind
    los_nlos_measure_ind_t *los_nlos_measure_ind_local_nonprim = NULL;

    // define the local variable for loc_context_data->up_cum_evt_rpt_criteria
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_nonprim = NULL;

    // define the local variable for loc_context_data->lcs_upp_exist_ind
    int *lcs_upp_exist_ind_local_var = NULL;

    char *src_lmf_routing_info_local_str = NULL;

    // define the local variable for loc_context_data->extended_facility_ind
    int *extended_facility_ind_local_var = NULL;

    // loc_context_data->amf_id
    cJSON *amf_id = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "amfId");
    if (cJSON_IsNull(amf_id)) {
        amf_id = NULL;
    }
    if (!amf_id) {
        goto end;
    }

    
    if(!cJSON_IsString(amf_id))
    {
    goto end; //String
    }

    // loc_context_data->location_qo_s
    cJSON *location_qo_s = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "locationQoS");
    if (cJSON_IsNull(location_qo_s)) {
        location_qo_s = NULL;
    }
    if (location_qo_s) { 
    location_qo_s_local_nonprim = location_qo_s_parseFromJSON(location_qo_s); //nonprimitive
    }

    // loc_context_data->supported_gad_shapes
    cJSON *supported_gad_shapes = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "supportedGADShapes");
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

    // loc_context_data->supi
    cJSON *supi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "supi");
    if (cJSON_IsNull(supi)) {
        supi = NULL;
    }
    if (supi) { 
    if(!cJSON_IsString(supi) && !cJSON_IsNull(supi))
    {
    goto end; //String
    }
    }

    // loc_context_data->gpsi
    cJSON *gpsi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "gpsi");
    if (cJSON_IsNull(gpsi)) {
        gpsi = NULL;
    }
    if (gpsi) { 
    if(!cJSON_IsString(gpsi) && !cJSON_IsNull(gpsi))
    {
    goto end; //String
    }
    }

    // loc_context_data->add_loc_context_list
    cJSON *add_loc_context_list = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "addLocContextList");
    if (cJSON_IsNull(add_loc_context_list)) {
        add_loc_context_list = NULL;
    }
    if (add_loc_context_list) { 
    cJSON *add_loc_context_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(add_loc_context_list)){
        goto end; //nonprimitive container
    }

    add_loc_context_listList = list_createList();

    cJSON_ArrayForEach(add_loc_context_list_local_nonprimitive,add_loc_context_list )
    {
        if(!cJSON_IsObject(add_loc_context_list_local_nonprimitive)){
            goto end;
        }
        add_location_context_t *add_loc_context_listItem = add_location_context_parseFromJSON(add_loc_context_list_local_nonprimitive);

        list_addElement(add_loc_context_listList, add_loc_context_listItem);
    }
    }

    // loc_context_data->ldr_type
    cJSON *ldr_type = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ldrType");
    if (cJSON_IsNull(ldr_type)) {
        ldr_type = NULL;
    }
    if (!ldr_type) {
        goto end;
    }

    
    ldr_type_local_nonprim = ldr_type_parseFromJSON(ldr_type); //nonprimitive

    // loc_context_data->hgmlc_call_back_uri
    cJSON *hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "hgmlcCallBackURI");
    if (cJSON_IsNull(hgmlc_call_back_uri)) {
        hgmlc_call_back_uri = NULL;
    }
    if (!hgmlc_call_back_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(hgmlc_call_back_uri))
    {
    goto end; //String
    }

    // loc_context_data->ldr_reference
    cJSON *ldr_reference = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ldrReference");
    if (cJSON_IsNull(ldr_reference)) {
        ldr_reference = NULL;
    }
    if (!ldr_reference) {
        goto end;
    }

    
    if(!cJSON_IsString(ldr_reference))
    {
    goto end; //String
    }

    // loc_context_data->periodic_event_info
    cJSON *periodic_event_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "periodicEventInfo");
    if (cJSON_IsNull(periodic_event_info)) {
        periodic_event_info = NULL;
    }
    if (periodic_event_info) { 
    periodic_event_info_local_nonprim = periodic_event_info_parseFromJSON(periodic_event_info); //nonprimitive
    }

    // loc_context_data->area_event_info
    cJSON *area_event_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "areaEventInfo");
    if (cJSON_IsNull(area_event_info)) {
        area_event_info = NULL;
    }
    if (area_event_info) { 
    area_event_info_local_nonprim = area_event_info_parseFromJSON(area_event_info); //nonprimitive
    }

    // loc_context_data->motion_event_info
    cJSON *motion_event_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "motionEventInfo");
    if (cJSON_IsNull(motion_event_info)) {
        motion_event_info = NULL;
    }
    if (motion_event_info) { 
    motion_event_info_local_nonprim = motion_event_info_parseFromJSON(motion_event_info); //nonprimitive
    }

    // loc_context_data->event_report_message
    cJSON *event_report_message = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "eventReportMessage");
    if (cJSON_IsNull(event_report_message)) {
        event_report_message = NULL;
    }
    if (!event_report_message) {
        goto end;
    }

    
    event_report_message_local_nonprim = event_report_message_parseFromJSON(event_report_message); //nonprimitive

    // loc_context_data->event_reporting_status
    cJSON *event_reporting_status = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "eventReportingStatus");
    if (cJSON_IsNull(event_reporting_status)) {
        event_reporting_status = NULL;
    }
    if (event_reporting_status) { 
    event_reporting_status_local_nonprim = event_reporting_status_parseFromJSON(event_reporting_status); //nonprimitive
    }

    // loc_context_data->ue_location_info
    cJSON *ue_location_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ueLocationInfo");
    if (cJSON_IsNull(ue_location_info)) {
        ue_location_info = NULL;
    }
    if (ue_location_info) { 
    ue_location_info_local_nonprim = ue_location_info_parseFromJSON(ue_location_info); //nonprimitive
    }

    // loc_context_data->c_io_t5_gs_optimisation
    cJSON *c_io_t5_gs_optimisation = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "cIoT5GSOptimisation");
    if (cJSON_IsNull(c_io_t5_gs_optimisation)) {
        c_io_t5_gs_optimisation = NULL;
    }
    if (c_io_t5_gs_optimisation) { 
    if(!cJSON_IsBool(c_io_t5_gs_optimisation))
    {
    goto end; //Bool
    }
    c_io_t5_gs_optimisation_local_var = malloc(sizeof(int));
    if(!c_io_t5_gs_optimisation_local_var)
    {
        goto end;
    }
    *c_io_t5_gs_optimisation_local_var = c_io_t5_gs_optimisation->valueint;
    }

    // loc_context_data->ecgi
    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ecgi");
    if (cJSON_IsNull(ecgi)) {
        ecgi = NULL;
    }
    if (ecgi) { 
    ecgi_local_nonprim = ecgi_parseFromJSON(ecgi); //nonprimitive
    }

    // loc_context_data->ncgi
    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ncgi");
    if (cJSON_IsNull(ncgi)) {
        ncgi = NULL;
    }
    if (ncgi) { 
    ncgi_local_nonprim = ncgi_parseFromJSON(ncgi); //nonprimitive
    }

    // loc_context_data->guami
    cJSON *guami = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "guami");
    if (cJSON_IsNull(guami)) {
        guami = NULL;
    }
    if (guami) { 
    guami_local_nonprim = guami_parseFromJSON(guami); //nonprimitive
    }

    // loc_context_data->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "supportedFeatures");
    if (cJSON_IsNull(supported_features)) {
        supported_features = NULL;
    }
    if (supported_features) { 
    if(!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features))
    {
    goto end; //String
    }
    }

    // loc_context_data->ue_positioning_cap
    cJSON *ue_positioning_cap = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "uePositioningCap");
    if (cJSON_IsNull(ue_positioning_cap)) {
        ue_positioning_cap = NULL;
    }
    if (ue_positioning_cap) { 
    if(!cJSON_IsString(ue_positioning_cap))
    {
    goto end; //ByteArray
    }
    }

    // loc_context_data->ue_up_pos_caps
    cJSON *ue_up_pos_caps = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ueUpPosCaps");
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

    // loc_context_data->scheduled_loc_time
    cJSON *scheduled_loc_time = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "scheduledLocTime");
    if (cJSON_IsNull(scheduled_loc_time)) {
        scheduled_loc_time = NULL;
    }
    if (scheduled_loc_time) { 
    if(!cJSON_IsString(scheduled_loc_time) && !cJSON_IsNull(scheduled_loc_time))
    {
    goto end; //DateTime
    }
    }

    // loc_context_data->indoor_outdoor_ind
    cJSON *indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "indoorOutdoorInd");
    if (cJSON_IsNull(indoor_outdoor_ind)) {
        indoor_outdoor_ind = NULL;
    }
    if (indoor_outdoor_ind) { 
    indoor_outdoor_ind_local_nonprim = indoor_outdoor_ind_parseFromJSON(indoor_outdoor_ind); //nonprimitive
    }

    // loc_context_data->los_nlos_measure_ind
    cJSON *los_nlos_measure_ind = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "losNlosMeasureInd");
    if (cJSON_IsNull(los_nlos_measure_ind)) {
        los_nlos_measure_ind = NULL;
    }
    if (los_nlos_measure_ind) { 
    los_nlos_measure_ind_local_nonprim = los_nlos_measure_ind_parseFromJSON(los_nlos_measure_ind); //nonprimitive
    }

    // loc_context_data->up_cum_evt_rpt_criteria
    cJSON *up_cum_evt_rpt_criteria = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "upCumEvtRptCriteria");
    if (cJSON_IsNull(up_cum_evt_rpt_criteria)) {
        up_cum_evt_rpt_criteria = NULL;
    }
    if (up_cum_evt_rpt_criteria) { 
    up_cum_evt_rpt_criteria_local_nonprim = up_cum_evt_rpt_criteria_parseFromJSON(up_cum_evt_rpt_criteria); //nonprimitive
    }

    // loc_context_data->lcs_upp_exist_ind
    cJSON *lcs_upp_exist_ind = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "lcsUppExistInd");
    if (cJSON_IsNull(lcs_upp_exist_ind)) {
        lcs_upp_exist_ind = NULL;
    }
    if (lcs_upp_exist_ind) { 
    if(!cJSON_IsBool(lcs_upp_exist_ind))
    {
    goto end; //Bool
    }
    lcs_upp_exist_ind_local_var = malloc(sizeof(int));
    if(!lcs_upp_exist_ind_local_var)
    {
        goto end;
    }
    *lcs_upp_exist_ind_local_var = lcs_upp_exist_ind->valueint;
    }

    // loc_context_data->src_lmf_routing_info
    cJSON *src_lmf_routing_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "srcLmfRoutingInfo");
    if (cJSON_IsNull(src_lmf_routing_info)) {
        src_lmf_routing_info = NULL;
    }
    if (src_lmf_routing_info) { 
    if(!cJSON_IsString(src_lmf_routing_info) && !cJSON_IsNull(src_lmf_routing_info))
    {
    goto end; //String
    }
    }

    // loc_context_data->extended_facility_ind
    cJSON *extended_facility_ind = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "extendedFacilityInd");
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


    if (amf_id && !cJSON_IsNull(amf_id)) amf_id_local_str = strdup(amf_id->valuestring);
    if (supi && !cJSON_IsNull(supi)) supi_local_str = strdup(supi->valuestring);
    if (gpsi && !cJSON_IsNull(gpsi)) gpsi_local_str = strdup(gpsi->valuestring);
    if (hgmlc_call_back_uri && !cJSON_IsNull(hgmlc_call_back_uri)) hgmlc_call_back_uri_local_str = strdup(hgmlc_call_back_uri->valuestring);
    if (ldr_reference && !cJSON_IsNull(ldr_reference)) ldr_reference_local_str = strdup(ldr_reference->valuestring);
    if (supported_features && !cJSON_IsNull(supported_features)) supported_features_local_str = strdup(supported_features->valuestring);
    if (ue_positioning_cap) ue_positioning_cap_local_str = strdup(ue_positioning_cap->valuestring);
    if (scheduled_loc_time && !cJSON_IsNull(scheduled_loc_time)) scheduled_loc_time_local_str = strdup(scheduled_loc_time->valuestring);
    if (src_lmf_routing_info && !cJSON_IsNull(src_lmf_routing_info)) src_lmf_routing_info_local_str = strdup(src_lmf_routing_info->valuestring);

    loc_context_data_local_var = loc_context_data_create_internal (
        amf_id_local_str,
        location_qo_s ? location_qo_s_local_nonprim : NULL,
        supported_gad_shapes ? supported_gad_shapesList : NULL,
        supi_local_str,
        gpsi_local_str,
        add_loc_context_list ? add_loc_context_listList : NULL,
        ldr_type_local_nonprim,
        hgmlc_call_back_uri_local_str,
        ldr_reference_local_str,
        periodic_event_info ? periodic_event_info_local_nonprim : NULL,
        area_event_info ? area_event_info_local_nonprim : NULL,
        motion_event_info ? motion_event_info_local_nonprim : NULL,
        event_report_message_local_nonprim,
        event_reporting_status ? event_reporting_status_local_nonprim : NULL,
        ue_location_info ? ue_location_info_local_nonprim : NULL,
        c_io_t5_gs_optimisation_local_var,
        ecgi ? ecgi_local_nonprim : NULL,
        ncgi ? ncgi_local_nonprim : NULL,
        guami ? guami_local_nonprim : NULL,
        supported_features_local_str,
        ue_positioning_cap_local_str,
        ue_up_pos_caps ? ue_up_pos_capsList : NULL,
        scheduled_loc_time_local_str,
        indoor_outdoor_ind ? indoor_outdoor_ind_local_nonprim : NULL,
        los_nlos_measure_ind ? los_nlos_measure_ind_local_nonprim : NULL,
        up_cum_evt_rpt_criteria ? up_cum_evt_rpt_criteria_local_nonprim : NULL,
        lcs_upp_exist_ind_local_var,
        src_lmf_routing_info_local_str,
        extended_facility_ind_local_var
        );

    if (!loc_context_data_local_var) {
        goto end;
    }

    return loc_context_data_local_var;
end:
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
    if (gpsi_local_str) {
        free(gpsi_local_str);
        gpsi_local_str = NULL;
    }
    if (add_loc_context_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, add_loc_context_listList) {
            add_location_context_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(add_loc_context_listList);
        add_loc_context_listList = NULL;
    }
    if (ldr_type_local_nonprim) {
        ldr_type_free(ldr_type_local_nonprim);
        ldr_type_local_nonprim = NULL;
    }
    if (hgmlc_call_back_uri_local_str) {
        free(hgmlc_call_back_uri_local_str);
        hgmlc_call_back_uri_local_str = NULL;
    }
    if (ldr_reference_local_str) {
        free(ldr_reference_local_str);
        ldr_reference_local_str = NULL;
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
    if (event_report_message_local_nonprim) {
        event_report_message_free(event_report_message_local_nonprim);
        event_report_message_local_nonprim = NULL;
    }
    if (event_reporting_status_local_nonprim) {
        event_reporting_status_free(event_reporting_status_local_nonprim);
        event_reporting_status_local_nonprim = NULL;
    }
    if (ue_location_info_local_nonprim) {
        ue_location_info_free(ue_location_info_local_nonprim);
        ue_location_info_local_nonprim = NULL;
    }
    if (c_io_t5_gs_optimisation_local_var) {
        free(c_io_t5_gs_optimisation_local_var);
        c_io_t5_gs_optimisation_local_var = NULL;
    }
    if (ecgi_local_nonprim) {
        ecgi_free(ecgi_local_nonprim);
        ecgi_local_nonprim = NULL;
    }
    if (ncgi_local_nonprim) {
        ncgi_free(ncgi_local_nonprim);
        ncgi_local_nonprim = NULL;
    }
    if (guami_local_nonprim) {
        guami_free(guami_local_nonprim);
        guami_local_nonprim = NULL;
    }
    if (supported_features_local_str) {
        free(supported_features_local_str);
        supported_features_local_str = NULL;
    }
    if (ue_positioning_cap_local_str) {
        free(ue_positioning_cap_local_str);
        ue_positioning_cap_local_str = NULL;
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
    if (scheduled_loc_time_local_str) {
        free(scheduled_loc_time_local_str);
        scheduled_loc_time_local_str = NULL;
    }
    if (indoor_outdoor_ind_local_nonprim) {
        indoor_outdoor_ind_free(indoor_outdoor_ind_local_nonprim);
        indoor_outdoor_ind_local_nonprim = NULL;
    }
    if (los_nlos_measure_ind_local_nonprim) {
        los_nlos_measure_ind_free(los_nlos_measure_ind_local_nonprim);
        los_nlos_measure_ind_local_nonprim = NULL;
    }
    if (up_cum_evt_rpt_criteria_local_nonprim) {
        up_cum_evt_rpt_criteria_free(up_cum_evt_rpt_criteria_local_nonprim);
        up_cum_evt_rpt_criteria_local_nonprim = NULL;
    }
    if (lcs_upp_exist_ind_local_var) {
        free(lcs_upp_exist_ind_local_var);
        lcs_upp_exist_ind_local_var = NULL;
    }
    if (src_lmf_routing_info_local_str) {
        free(src_lmf_routing_info_local_str);
        src_lmf_routing_info_local_str = NULL;
    }
    if (extended_facility_ind_local_var) {
        free(extended_facility_ind_local_var);
        extended_facility_ind_local_var = NULL;
    }
    return NULL;

}
