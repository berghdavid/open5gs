
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "add_location_context.h"

OpenAPI_add_location_context_t *OpenAPI_add_location_context_create(
    OpenAPI_location_qo_s_t *location_qo_s,
    OpenAPI_ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    OpenAPI_periodic_event_info_t *periodic_event_info,
    OpenAPI_area_event_info_t *area_event_info,
    OpenAPI_motion_event_info_t *motion_event_info,
    OpenAPI_event_report_message_t *event_report_message,
    OpenAPI_event_reporting_status_t *event_reporting_status,
    OpenAPI_ue_location_info_t *ue_location_info,
    char *scheduled_loc_time,
    OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind,
    OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind,
    OpenAPI_up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    bool is_lcs_upp_exist_ind,
    int lcs_upp_exist_ind
)
{
    OpenAPI_add_location_context_t *add_location_context_local_var = ogs_malloc(sizeof(OpenAPI_add_location_context_t));
    ogs_assert(add_location_context_local_var);

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
    add_location_context_local_var->is_lcs_upp_exist_ind = is_lcs_upp_exist_ind;
    add_location_context_local_var->lcs_upp_exist_ind = lcs_upp_exist_ind;

    return add_location_context_local_var;
}

void OpenAPI_add_location_context_free(OpenAPI_add_location_context_t *add_location_context)
{
    if (NULL == add_location_context) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_location_qo_s_free(add_location_context->location_qo_s);
    OpenAPI_ldr_type_free(add_location_context->ldr_type);
    ogs_free(add_location_context->hgmlc_call_back_uri);
    ogs_free(add_location_context->ldr_reference);
    OpenAPI_periodic_event_info_free(add_location_context->periodic_event_info);
    OpenAPI_area_event_info_free(add_location_context->area_event_info);
    OpenAPI_motion_event_info_free(add_location_context->motion_event_info);
    OpenAPI_event_report_message_free(add_location_context->event_report_message);
    OpenAPI_event_reporting_status_free(add_location_context->event_reporting_status);
    OpenAPI_ue_location_info_free(add_location_context->ue_location_info);
    ogs_free(add_location_context->scheduled_loc_time);
    OpenAPI_indoor_outdoor_ind_free(add_location_context->indoor_outdoor_ind);
    OpenAPI_los_nlos_measure_ind_free(add_location_context->los_nlos_measure_ind);
    OpenAPI_up_cum_evt_rpt_criteria_free(add_location_context->up_cum_evt_rpt_criteria);
    ogs_free(add_location_context);
}

cJSON *OpenAPI_add_location_context_convertToJSON(OpenAPI_add_location_context_t *add_location_context)
{
    cJSON *item = NULL;

    if (add_location_context == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [AddLocationContext]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (add_location_context->location_qo_s) {
    cJSON *location_qo_s_local_JSON = OpenAPI_location_qo_s_convertToJSON(add_location_context->location_qo_s);
    if (location_qo_s_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [location_qo_s]");
        goto end;
    }
    cJSON_AddItemToObject(item, "locationQoS", location_qo_s_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [location_qo_s]");
        goto end;
    }
    }

    cJSON *ldr_type_local_JSON = OpenAPI_ldr_type_convertToJSON(add_location_context->ldr_type);
    if (ldr_type_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [ldr_type]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ldrType", ldr_type_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [ldr_type]");
        goto end;
    }

    if (cJSON_AddStringToObject(item, "hgmlcCallBackURI", add_location_context->hgmlc_call_back_uri) == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [hgmlc_call_back_uri]");
        goto end;
    }

    if (cJSON_AddStringToObject(item, "ldrReference", add_location_context->ldr_reference) == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [ldr_reference]");
        goto end;
    }

    if (add_location_context->periodic_event_info) {
    cJSON *periodic_event_info_local_JSON = OpenAPI_periodic_event_info_convertToJSON(add_location_context->periodic_event_info);
    if (periodic_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [periodic_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "periodicEventInfo", periodic_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [periodic_event_info]");
        goto end;
    }
    }

    if (add_location_context->area_event_info) {
    cJSON *area_event_info_local_JSON = OpenAPI_area_event_info_convertToJSON(add_location_context->area_event_info);
    if (area_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [area_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "areaEventInfo", area_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [area_event_info]");
        goto end;
    }
    }

    if (add_location_context->motion_event_info) {
    cJSON *motion_event_info_local_JSON = OpenAPI_motion_event_info_convertToJSON(add_location_context->motion_event_info);
    if (motion_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [motion_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "motionEventInfo", motion_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [motion_event_info]");
        goto end;
    }
    }

    if (add_location_context->event_report_message) {
    cJSON *event_report_message_local_JSON = OpenAPI_event_report_message_convertToJSON(add_location_context->event_report_message);
    if (event_report_message_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [event_report_message]");
        goto end;
    }
    cJSON_AddItemToObject(item, "eventReportMessage", event_report_message_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [event_report_message]");
        goto end;
    }
    }

    if (add_location_context->event_reporting_status) {
    cJSON *event_reporting_status_local_JSON = OpenAPI_event_reporting_status_convertToJSON(add_location_context->event_reporting_status);
    if (event_reporting_status_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [event_reporting_status]");
        goto end;
    }
    cJSON_AddItemToObject(item, "eventReportingStatus", event_reporting_status_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [event_reporting_status]");
        goto end;
    }
    }

    if (add_location_context->ue_location_info) {
    cJSON *ue_location_info_local_JSON = OpenAPI_ue_location_info_convertToJSON(add_location_context->ue_location_info);
    if (ue_location_info_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [ue_location_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ueLocationInfo", ue_location_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [ue_location_info]");
        goto end;
    }
    }

    if (add_location_context->scheduled_loc_time) {
    if (cJSON_AddStringToObject(item, "scheduledLocTime", add_location_context->scheduled_loc_time) == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [scheduled_loc_time]");
        goto end;
    }
    }

    if (add_location_context->indoor_outdoor_ind) {
    cJSON *indoor_outdoor_ind_local_JSON = OpenAPI_indoor_outdoor_ind_convertToJSON(add_location_context->indoor_outdoor_ind);
    if (indoor_outdoor_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [indoor_outdoor_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "indoorOutdoorInd", indoor_outdoor_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [indoor_outdoor_ind]");
        goto end;
    }
    }

    if (add_location_context->los_nlos_measure_ind) {
    cJSON *los_nlos_measure_ind_local_JSON = OpenAPI_los_nlos_measure_ind_convertToJSON(add_location_context->los_nlos_measure_ind);
    if (los_nlos_measure_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [los_nlos_measure_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "losNlosMeasureInd", los_nlos_measure_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [los_nlos_measure_ind]");
        goto end;
    }
    }

    if (add_location_context->up_cum_evt_rpt_criteria) {
    cJSON *up_cum_evt_rpt_criteria_local_JSON = OpenAPI_up_cum_evt_rpt_criteria_convertToJSON(add_location_context->up_cum_evt_rpt_criteria);
    if (up_cum_evt_rpt_criteria_local_JSON == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [up_cum_evt_rpt_criteria]");
        goto end;
    }
    cJSON_AddItemToObject(item, "upCumEvtRptCriteria", up_cum_evt_rpt_criteria_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [up_cum_evt_rpt_criteria]");
        goto end;
    }
    }

    if (add_location_context->is_lcs_upp_exist_ind) {
    if (cJSON_AddBoolToObject(item, "lcsUppExistInd", add_location_context->lcs_upp_exist_ind) == NULL) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed [lcs_upp_exist_ind]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_add_location_context_t *OpenAPI_add_location_context_parseFromJSON(cJSON *add_location_contextJSON)
{
    OpenAPI_add_location_context_t *add_location_context_local_var = NULL;
    cJSON *location_qo_s = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "locationQoS");

    OpenAPI_location_qo_s_t *location_qo_s_local_nonprim = NULL;
    if (location_qo_s) {
    location_qo_s_local_nonprim = OpenAPI_location_qo_s_parseFromJSON(location_qo_s);
    }

    cJSON *ldr_type = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "ldrType");
    if (!ldr_type) {
        ogs_error("OpenAPI_add_location_context_parseFromJSON() failed [ldr_type]");
        goto end;
    }

    OpenAPI_ldr_type_t *ldr_type_local_nonprim = NULL;
    ldr_type_local_nonprim = OpenAPI_ldr_type_parseFromJSON(ldr_type);

    cJSON *hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "hgmlcCallBackURI");
    if (!hgmlc_call_back_uri) {
        ogs_error("OpenAPI_add_location_context_parseFromJSON() failed [hgmlc_call_back_uri]");
        goto end;
    }

    if (!cJSON_IsString(hgmlc_call_back_uri)) {
        ogs_error("OpenAPI_add_location_context_parseFromJSON() failed [hgmlc_call_back_uri]");
        goto end;
    }

    cJSON *ldr_reference = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "ldrReference");
    if (!ldr_reference) {
        ogs_error("OpenAPI_add_location_context_parseFromJSON() failed [ldr_reference]");
        goto end;
    }

    if (!cJSON_IsString(ldr_reference)) {
        ogs_error("OpenAPI_add_location_context_parseFromJSON() failed [ldr_reference]");
        goto end;
    }

    cJSON *periodic_event_info = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "periodicEventInfo");

    OpenAPI_periodic_event_info_t *periodic_event_info_local_nonprim = NULL;
    if (periodic_event_info) {
    periodic_event_info_local_nonprim = OpenAPI_periodic_event_info_parseFromJSON(periodic_event_info);
    }

    cJSON *area_event_info = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "areaEventInfo");

    OpenAPI_area_event_info_t *area_event_info_local_nonprim = NULL;
    if (area_event_info) {
    area_event_info_local_nonprim = OpenAPI_area_event_info_parseFromJSON(area_event_info);
    }

    cJSON *motion_event_info = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "motionEventInfo");

    OpenAPI_motion_event_info_t *motion_event_info_local_nonprim = NULL;
    if (motion_event_info) {
    motion_event_info_local_nonprim = OpenAPI_motion_event_info_parseFromJSON(motion_event_info);
    }

    cJSON *event_report_message = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "eventReportMessage");

    OpenAPI_event_report_message_t *event_report_message_local_nonprim = NULL;
    if (event_report_message) {
    event_report_message_local_nonprim = OpenAPI_event_report_message_parseFromJSON(event_report_message);
    }

    cJSON *event_reporting_status = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "eventReportingStatus");

    OpenAPI_event_reporting_status_t *event_reporting_status_local_nonprim = NULL;
    if (event_reporting_status) {
    event_reporting_status_local_nonprim = OpenAPI_event_reporting_status_parseFromJSON(event_reporting_status);
    }

    cJSON *ue_location_info = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "ueLocationInfo");

    OpenAPI_ue_location_info_t *ue_location_info_local_nonprim = NULL;
    if (ue_location_info) {
    ue_location_info_local_nonprim = OpenAPI_ue_location_info_parseFromJSON(ue_location_info);
    }

    cJSON *scheduled_loc_time = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "scheduledLocTime");

    if (scheduled_loc_time) {
    if (!cJSON_IsString(scheduled_loc_time)) {
        ogs_error("OpenAPI_add_location_context_parseFromJSON() failed [scheduled_loc_time]");
        goto end;
    }
    }

    cJSON *indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "indoorOutdoorInd");

    OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind_local_nonprim = NULL;
    if (indoor_outdoor_ind) {
    indoor_outdoor_ind_local_nonprim = OpenAPI_indoor_outdoor_ind_parseFromJSON(indoor_outdoor_ind);
    }

    cJSON *los_nlos_measure_ind = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "losNlosMeasureInd");

    OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind_local_nonprim = NULL;
    if (los_nlos_measure_ind) {
    los_nlos_measure_ind_local_nonprim = OpenAPI_los_nlos_measure_ind_parseFromJSON(los_nlos_measure_ind);
    }

    cJSON *up_cum_evt_rpt_criteria = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "upCumEvtRptCriteria");

    OpenAPI_up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_nonprim = NULL;
    if (up_cum_evt_rpt_criteria) {
    up_cum_evt_rpt_criteria_local_nonprim = OpenAPI_up_cum_evt_rpt_criteria_parseFromJSON(up_cum_evt_rpt_criteria);
    }

    cJSON *lcs_upp_exist_ind = cJSON_GetObjectItemCaseSensitive(add_location_contextJSON, "lcsUppExistInd");

    if (lcs_upp_exist_ind) {
    if (!cJSON_IsBool(lcs_upp_exist_ind)) {
        ogs_error("OpenAPI_add_location_context_parseFromJSON() failed [lcs_upp_exist_ind]");
        goto end;
    }
    }

    add_location_context_local_var = OpenAPI_add_location_context_create (
        location_qo_s ? location_qo_s_local_nonprim : NULL,
        ldr_type_local_nonprim,
        ogs_strdup(hgmlc_call_back_uri->valuestring),
        ogs_strdup(ldr_reference->valuestring),
        periodic_event_info ? periodic_event_info_local_nonprim : NULL,
        area_event_info ? area_event_info_local_nonprim : NULL,
        motion_event_info ? motion_event_info_local_nonprim : NULL,
        event_report_message ? event_report_message_local_nonprim : NULL,
        event_reporting_status ? event_reporting_status_local_nonprim : NULL,
        ue_location_info ? ue_location_info_local_nonprim : NULL,
        scheduled_loc_time ? ogs_strdup(scheduled_loc_time->valuestring) : NULL,
        indoor_outdoor_ind ? indoor_outdoor_ind_local_nonprim : NULL,
        los_nlos_measure_ind ? los_nlos_measure_ind_local_nonprim : NULL,
        up_cum_evt_rpt_criteria ? up_cum_evt_rpt_criteria_local_nonprim : NULL,
        lcs_upp_exist_ind ? true : false,
        lcs_upp_exist_ind ? lcs_upp_exist_ind->valueint : 0
    );

    return add_location_context_local_var;
end:
    return NULL;
}

OpenAPI_add_location_context_t *OpenAPI_add_location_context_copy(OpenAPI_add_location_context_t *dst, OpenAPI_add_location_context_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_add_location_context_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_add_location_context_convertToJSON() failed");
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

    OpenAPI_add_location_context_free(dst);
    dst = OpenAPI_add_location_context_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

