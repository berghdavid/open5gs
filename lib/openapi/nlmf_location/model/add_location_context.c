#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "add_location_context.h"



static add_location_context_t *add_location_context_create_internal(
    location_qo_s_t *location_qo_s,
    ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    periodic_event_info_t *periodic_event_info,
    area_event_info_t *area_event_info,
    motion_event_info_t *motion_event_info,
    event_report_message_t *event_report_message,
    event_reporting_status_t *event_reporting_status,
    ue_location_info_t *ue_location_info,
    char *scheduled_loc_time,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    int *lcs_upp_exist_ind
    ) {
    add_location_context_t *add_location_context_local_var = malloc(sizeof(add_location_context_t));
    if (!add_location_context_local_var) {
        return NULL;
    }
    memset(add_location_context_local_var, 0, sizeof(add_location_context_t));
    add_location_context_local_var->_library_owned = 1;
    add_location_context_local_var->location_qo_s = location_qo_s;
    add_location_context_local_var->ldr_type = ldr_type;
    add_location_context_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
    add_location_context_local_var->ldr_reference = ldr_reference;
    add_location_context_local_var->periodic_event_info = periodic_event_info;
    add_location_context_local_var->area_event_info = area_event_info;
    add_location_context_local_var->motion_event_info = motion_event_info;
    add_location_context_local_var->event_report_message = event_report_message;
    add_location_context_local_var->event_reporting_status = event_reporting_status;
    add_location_context_local_var->ue_location_info = ue_location_info;
    add_location_context_local_var->scheduled_loc_time = scheduled_loc_time;
    add_location_context_local_var->indoor_outdoor_ind = indoor_outdoor_ind;
    add_location_context_local_var->los_nlos_measure_ind = los_nlos_measure_ind;
    add_location_context_local_var->up_cum_evt_rpt_criteria = up_cum_evt_rpt_criteria;
    add_location_context_local_var->lcs_upp_exist_ind = lcs_upp_exist_ind;
    return add_location_context_local_var;
}

__attribute__((deprecated)) add_location_context_t *add_location_context_create(
    location_qo_s_t *location_qo_s,
    ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    periodic_event_info_t *periodic_event_info,
    area_event_info_t *area_event_info,
    motion_event_info_t *motion_event_info,
    event_report_message_t *event_report_message,
    event_reporting_status_t *event_reporting_status,
    ue_location_info_t *ue_location_info,
    char *scheduled_loc_time,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    int *lcs_upp_exist_ind
    ) {
    int *lcs_upp_exist_ind_copy = NULL;
    if (lcs_upp_exist_ind) {
        lcs_upp_exist_ind_copy = malloc(sizeof(int));
        if (lcs_upp_exist_ind_copy) *lcs_upp_exist_ind_copy = *lcs_upp_exist_ind;
    }
    add_location_context_t *result = add_location_context_create_internal (
        location_qo_s,
        ldr_type,
        hgmlc_call_back_uri,
        ldr_reference,
        periodic_event_info,
        area_event_info,
        motion_event_info,
        event_report_message,
        event_reporting_status,
        ue_location_info,
        scheduled_loc_time,
        indoor_outdoor_ind,
        los_nlos_measure_ind,
        up_cum_evt_rpt_criteria,
        lcs_upp_exist_ind_copy
        );
    if (!result) {
        free(lcs_upp_exist_ind_copy);
    }
    return result;
}

void add_location_context_free(add_location_context_t *add_location_context) {
    if(NULL == add_location_context){
        return ;
    }
    if(add_location_context->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "add_location_context_free");
        return ;
    }
    listEntry_t *listEntry;
    if (add_location_context->location_qo_s) {
        location_qo_s_free(add_location_context->location_qo_s);
        add_location_context->location_qo_s = NULL;
    }
    if (add_location_context->ldr_type) {
        ldr_type_free(add_location_context->ldr_type);
        add_location_context->ldr_type = NULL;
    }
    if (add_location_context->hgmlc_call_back_uri) {
        free(add_location_context->hgmlc_call_back_uri);
        add_location_context->hgmlc_call_back_uri = NULL;
    }
    if (add_location_context->ldr_reference) {
        free(add_location_context->ldr_reference);
        add_location_context->ldr_reference = NULL;
    }
    if (add_location_context->periodic_event_info) {
        periodic_event_info_free(add_location_context->periodic_event_info);
        add_location_context->periodic_event_info = NULL;
    }
    if (add_location_context->area_event_info) {
        area_event_info_free(add_location_context->area_event_info);
        add_location_context->area_event_info = NULL;
    }
    if (add_location_context->motion_event_info) {
        motion_event_info_free(add_location_context->motion_event_info);
        add_location_context->motion_event_info = NULL;
    }
    if (add_location_context->event_report_message) {
        event_report_message_free(add_location_context->event_report_message);
        add_location_context->event_report_message = NULL;
    }
    if (add_location_context->event_reporting_status) {
        event_reporting_status_free(add_location_context->event_reporting_status);
        add_location_context->event_reporting_status = NULL;
    }
    if (add_location_context->ue_location_info) {
        ue_location_info_free(add_location_context->ue_location_info);
        add_location_context->ue_location_info = NULL;
    }
    if (add_location_context->scheduled_loc_time) {
        free(add_location_context->scheduled_loc_time);
        add_location_context->scheduled_loc_time = NULL;
    }
    if (add_location_context->indoor_outdoor_ind) {
        indoor_outdoor_ind_free(add_location_context->indoor_outdoor_ind);
        add_location_context->indoor_outdoor_ind = NULL;
    }
    if (add_location_context->los_nlos_measure_ind) {
        los_nlos_measure_ind_free(add_location_context->los_nlos_measure_ind);
        add_location_context->los_nlos_measure_ind = NULL;
    }
    if (add_location_context->up_cum_evt_rpt_criteria) {
        up_cum_evt_rpt_criteria_free(add_location_context->up_cum_evt_rpt_criteria);
        add_location_context->up_cum_evt_rpt_criteria = NULL;
    }
    if (add_location_context->lcs_upp_exist_ind) {
        free(add_location_context->lcs_upp_exist_ind);
        add_location_context->lcs_upp_exist_ind = NULL;
    }
    free(add_location_context);
}

cJSON *add_location_context_convertToJSON(add_location_context_t *add_location_context) {
    cJSON *item = cJSON_CreateObject();

    // add_location_context->location_qo_s
    if(add_location_context->location_qo_s) {
    cJSON *location_qo_s_local_JSON = location_qo_s_convertToJSON(add_location_context->location_qo_s);
    if(location_qo_s_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "locationQoS", location_qo_s_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->ldr_type
    if (!add_location_context->ldr_type) {
        goto fail;
    }
    cJSON *ldr_type_local_JSON = ldr_type_convertToJSON(add_location_context->ldr_type);
    if(ldr_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ldrType", ldr_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // add_location_context->hgmlc_call_back_uri
    if (!add_location_context->hgmlc_call_back_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hgmlcCallBackURI", add_location_context->hgmlc_call_back_uri) == NULL) {
    goto fail; //String
    }


    // add_location_context->ldr_reference
    if (!add_location_context->ldr_reference) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ldrReference", add_location_context->ldr_reference) == NULL) {
    goto fail; //String
    }


    // add_location_context->periodic_event_info
    if(add_location_context->periodic_event_info) {
    cJSON *periodic_event_info_local_JSON = periodic_event_info_convertToJSON(add_location_context->periodic_event_info);
    if(periodic_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "periodicEventInfo", periodic_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->area_event_info
    if(add_location_context->area_event_info) {
    cJSON *area_event_info_local_JSON = area_event_info_convertToJSON(add_location_context->area_event_info);
    if(area_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "areaEventInfo", area_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->motion_event_info
    if(add_location_context->motion_event_info) {
    cJSON *motion_event_info_local_JSON = motion_event_info_convertToJSON(add_location_context->motion_event_info);
    if(motion_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "motionEventInfo", motion_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->event_report_message
    if(add_location_context->event_report_message) {
    cJSON *event_report_message_local_JSON = event_report_message_convertToJSON(add_location_context->event_report_message);
    if(event_report_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "eventReportMessage", event_report_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->event_reporting_status
    if(add_location_context->event_reporting_status) {
    cJSON *event_reporting_status_local_JSON = event_reporting_status_convertToJSON(add_location_context->event_reporting_status);
    if(event_reporting_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "eventReportingStatus", event_reporting_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->ue_location_info
    if(add_location_context->ue_location_info) {
    cJSON *ue_location_info_local_JSON = ue_location_info_convertToJSON(add_location_context->ue_location_info);
    if(ue_location_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ueLocationInfo", ue_location_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->scheduled_loc_time
    if(add_location_context->scheduled_loc_time) {
    if(cJSON_AddStringToObject(item, "scheduledLocTime", add_location_context->scheduled_loc_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // add_location_context->indoor_outdoor_ind
    if(add_location_context->indoor_outdoor_ind) {
    cJSON *indoor_outdoor_ind_local_JSON = indoor_outdoor_ind_convertToJSON(add_location_context->indoor_outdoor_ind);
    if(indoor_outdoor_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "indoorOutdoorInd", indoor_outdoor_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->los_nlos_measure_ind
    if(add_location_context->los_nlos_measure_ind) {
    cJSON *los_nlos_measure_ind_local_JSON = los_nlos_measure_ind_convertToJSON(add_location_context->los_nlos_measure_ind);
    if(los_nlos_measure_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "losNlosMeasureInd", los_nlos_measure_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->up_cum_evt_rpt_criteria
    if(add_location_context->up_cum_evt_rpt_criteria) {
    cJSON *up_cum_evt_rpt_criteria_local_JSON = up_cum_evt_rpt_criteria_convertToJSON(add_location_context->up_cum_evt_rpt_criteria);
    if(up_cum_evt_rpt_criteria_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "upCumEvtRptCriteria", up_cum_evt_rpt_criteria_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // add_location_context->lcs_upp_exist_ind
    if(add_location_context->lcs_upp_exist_ind) {
    if(cJSON_AddBoolToObject(item, "lcsUppExistInd", *add_location_context->lcs_upp_exist_ind) == NULL) {
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

add_location_context_t *add_location_context_parseFromJSON(cJSON *add_location_contextJSON){

    add_location_context_t *add_location_context_local_var = NULL;

    // define the local variable for add_location_context->location_qo_s
    location_qo_s_t *location_qo_s_local_nonprim = NULL;

    // define the local variable for add_location_context->ldr_type
    ldr_type_t *ldr_type_local_nonprim = NULL;

    char *hgmlc_call_back_uri_local_str = NULL;

    char *ldr_reference_local_str = NULL;

    // define the local variable for add_location_context->periodic_event_info
    periodic_event_info_t *periodic_event_info_local_nonprim = NULL;

    // define the local variable for add_location_context->area_event_info
    area_event_info_t *area_event_info_local_nonprim = NULL;

    // define the local variable for add_location_context->motion_event_info
    motion_event_info_t *motion_event_info_local_nonprim = NULL;

    // define the local variable for add_location_context->event_report_message
    event_report_message_t *event_report_message_local_nonprim = NULL;

    // define the local variable for add_location_context->event_reporting_status
    event_reporting_status_t *event_reporting_status_local_nonprim = NULL;

    // define the local variable for add_location_context->ue_location_info
    ue_location_info_t *ue_location_info_local_nonprim = NULL;

    char *scheduled_loc_time_local_str = NULL;

    // define the local variable for add_location_context->indoor_outdoor_ind
    indoor_outdoor_ind_t *indoor_outdoor_ind_local_nonprim = NULL;

    // define the local variable for add_location_context->los_nlos_measure_ind
    los_nlos_measure_ind_t *los_nlos_measure_ind_local_nonprim = NULL;

    // define the local variable for add_location_context->up_cum_evt_rpt_criteria
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_nonprim = NULL;

    // define the local variable for add_location_context->lcs_upp_exist_ind
    int *lcs_upp_exist_ind_local_var = NULL;

    // add_location_context->location_qo_s
    cJSON *location_qo_s = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "locationQoS");
    if (cJSON_IsNull(location_qo_s)) {
        location_qo_s = NULL;
    }
    if (location_qo_s) { 
    location_qo_s_local_nonprim = location_qo_s_parseFromJSON(location_qo_s); //nonprimitive
    }

    // add_location_context->ldr_type
    cJSON *ldr_type = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "ldrType");
    if (cJSON_IsNull(ldr_type)) {
        ldr_type = NULL;
    }
    if (!ldr_type) {
        goto end;
    }

    
    ldr_type_local_nonprim = ldr_type_parseFromJSON(ldr_type); //nonprimitive

    // add_location_context->hgmlc_call_back_uri
    cJSON *hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "hgmlcCallBackURI");
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

    // add_location_context->ldr_reference
    cJSON *ldr_reference = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "ldrReference");
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

    // add_location_context->periodic_event_info
    cJSON *periodic_event_info = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "periodicEventInfo");
    if (cJSON_IsNull(periodic_event_info)) {
        periodic_event_info = NULL;
    }
    if (periodic_event_info) { 
    periodic_event_info_local_nonprim = periodic_event_info_parseFromJSON(periodic_event_info); //nonprimitive
    }

    // add_location_context->area_event_info
    cJSON *area_event_info = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "areaEventInfo");
    if (cJSON_IsNull(area_event_info)) {
        area_event_info = NULL;
    }
    if (area_event_info) { 
    area_event_info_local_nonprim = area_event_info_parseFromJSON(area_event_info); //nonprimitive
    }

    // add_location_context->motion_event_info
    cJSON *motion_event_info = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "motionEventInfo");
    if (cJSON_IsNull(motion_event_info)) {
        motion_event_info = NULL;
    }
    if (motion_event_info) { 
    motion_event_info_local_nonprim = motion_event_info_parseFromJSON(motion_event_info); //nonprimitive
    }

    // add_location_context->event_report_message
    cJSON *event_report_message = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "eventReportMessage");
    if (cJSON_IsNull(event_report_message)) {
        event_report_message = NULL;
    }
    if (event_report_message) { 
    event_report_message_local_nonprim = event_report_message_parseFromJSON(event_report_message); //nonprimitive
    }

    // add_location_context->event_reporting_status
    cJSON *event_reporting_status = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "eventReportingStatus");
    if (cJSON_IsNull(event_reporting_status)) {
        event_reporting_status = NULL;
    }
    if (event_reporting_status) { 
    event_reporting_status_local_nonprim = event_reporting_status_parseFromJSON(event_reporting_status); //nonprimitive
    }

    // add_location_context->ue_location_info
    cJSON *ue_location_info = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "ueLocationInfo");
    if (cJSON_IsNull(ue_location_info)) {
        ue_location_info = NULL;
    }
    if (ue_location_info) { 
    ue_location_info_local_nonprim = ue_location_info_parseFromJSON(ue_location_info); //nonprimitive
    }

    // add_location_context->scheduled_loc_time
    cJSON *scheduled_loc_time = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "scheduledLocTime");
    if (cJSON_IsNull(scheduled_loc_time)) {
        scheduled_loc_time = NULL;
    }
    if (scheduled_loc_time) { 
    if(!cJSON_IsString(scheduled_loc_time) && !cJSON_IsNull(scheduled_loc_time))
    {
    goto end; //DateTime
    }
    }

    // add_location_context->indoor_outdoor_ind
    cJSON *indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "indoorOutdoorInd");
    if (cJSON_IsNull(indoor_outdoor_ind)) {
        indoor_outdoor_ind = NULL;
    }
    if (indoor_outdoor_ind) { 
    indoor_outdoor_ind_local_nonprim = indoor_outdoor_ind_parseFromJSON(indoor_outdoor_ind); //nonprimitive
    }

    // add_location_context->los_nlos_measure_ind
    cJSON *los_nlos_measure_ind = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "losNlosMeasureInd");
    if (cJSON_IsNull(los_nlos_measure_ind)) {
        los_nlos_measure_ind = NULL;
    }
    if (los_nlos_measure_ind) { 
    los_nlos_measure_ind_local_nonprim = los_nlos_measure_ind_parseFromJSON(los_nlos_measure_ind); //nonprimitive
    }

    // add_location_context->up_cum_evt_rpt_criteria
    cJSON *up_cum_evt_rpt_criteria = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "upCumEvtRptCriteria");
    if (cJSON_IsNull(up_cum_evt_rpt_criteria)) {
        up_cum_evt_rpt_criteria = NULL;
    }
    if (up_cum_evt_rpt_criteria) { 
    up_cum_evt_rpt_criteria_local_nonprim = up_cum_evt_rpt_criteria_parseFromJSON(up_cum_evt_rpt_criteria); //nonprimitive
    }

    // add_location_context->lcs_upp_exist_ind
    cJSON *lcs_upp_exist_ind = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "lcsUppExistInd");
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


    if (hgmlc_call_back_uri && !cJSON_IsNull(hgmlc_call_back_uri)) hgmlc_call_back_uri_local_str = strdup(hgmlc_call_back_uri->valuestring);
    if (ldr_reference && !cJSON_IsNull(ldr_reference)) ldr_reference_local_str = strdup(ldr_reference->valuestring);
    if (scheduled_loc_time && !cJSON_IsNull(scheduled_loc_time)) scheduled_loc_time_local_str = strdup(scheduled_loc_time->valuestring);

    add_location_context_local_var = add_location_context_create_internal (
        location_qo_s ? location_qo_s_local_nonprim : NULL,
        ldr_type_local_nonprim,
        hgmlc_call_back_uri_local_str,
        ldr_reference_local_str,
        periodic_event_info ? periodic_event_info_local_nonprim : NULL,
        area_event_info ? area_event_info_local_nonprim : NULL,
        motion_event_info ? motion_event_info_local_nonprim : NULL,
        event_report_message ? event_report_message_local_nonprim : NULL,
        event_reporting_status ? event_reporting_status_local_nonprim : NULL,
        ue_location_info ? ue_location_info_local_nonprim : NULL,
        scheduled_loc_time_local_str,
        indoor_outdoor_ind ? indoor_outdoor_ind_local_nonprim : NULL,
        los_nlos_measure_ind ? los_nlos_measure_ind_local_nonprim : NULL,
        up_cum_evt_rpt_criteria ? up_cum_evt_rpt_criteria_local_nonprim : NULL,
        lcs_upp_exist_ind_local_var
        );

    if (!add_location_context_local_var) {
        goto end;
    }

    return add_location_context_local_var;
end:
    if (location_qo_s_local_nonprim) {
        location_qo_s_free(location_qo_s_local_nonprim);
        location_qo_s_local_nonprim = NULL;
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
    return NULL;

}
