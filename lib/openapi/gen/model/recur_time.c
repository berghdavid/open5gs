
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recur_time.h"

OpenAPI_recur_time_t *OpenAPI_recur_time_create(
    OpenAPI_valid_time_period_t *recur_time_window,
    OpenAPI_recur_type_t *recur_type,
    OpenAPI_list_t *recur_month,
    OpenAPI_list_t *recur_week,
    OpenAPI_list_t *recur_day,
    OpenAPI_list_t *recur_date,
    char *recur_end_time
)
{
    OpenAPI_recur_time_t *recur_time_local_var = ogs_malloc(sizeof(OpenAPI_recur_time_t));
    ogs_assert(recur_time_local_var);

    recur_time_local_var->recur_time_window = recur_time_window;
    recur_time_local_var->recur_type = recur_type;
    recur_time_local_var->recur_month = recur_month;
    recur_time_local_var->recur_week = recur_week;
    recur_time_local_var->recur_day = recur_day;
    recur_time_local_var->recur_date = recur_date;
    recur_time_local_var->recur_end_time = recur_end_time;

    return recur_time_local_var;
}

void OpenAPI_recur_time_free(OpenAPI_recur_time_t *recur_time)
{
    if (NULL == recur_time) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_valid_time_period_free(recur_time->recur_time_window);
    OpenAPI_recur_type_free(recur_time->recur_type);
    OpenAPI_list_for_each(recur_time->recur_month, node) {
        ogs_free(node->data);
    }
    OpenAPI_list_free(recur_time->recur_month);
    OpenAPI_list_for_each(recur_time->recur_week, node) {
        ogs_free(node->data);
    }
    OpenAPI_list_free(recur_time->recur_week);
    OpenAPI_list_for_each(recur_time->recur_day, node) {
        ogs_free(node->data);
    }
    OpenAPI_list_free(recur_time->recur_day);
    OpenAPI_list_for_each(recur_time->recur_date, node) {
        ogs_free(node->data);
    }
    OpenAPI_list_free(recur_time->recur_date);
    ogs_free(recur_time->recur_end_time);
    ogs_free(recur_time);
}

cJSON *OpenAPI_recur_time_convertToJSON(OpenAPI_recur_time_t *recur_time)
{
    cJSON *item = NULL;

    if (recur_time == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [RecurTime]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (recur_time->recur_time_window) {
    cJSON *recur_time_window_local_JSON = OpenAPI_valid_time_period_convertToJSON(recur_time->recur_time_window);
    if (recur_time_window_local_JSON == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_time_window]");
        goto end;
    }
    cJSON_AddItemToObject(item, "recurTimeWindow", recur_time_window_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_time_window]");
        goto end;
    }
    }

    if (recur_time->recur_type) {
    cJSON *recur_type_local_JSON = OpenAPI_recur_type_convertToJSON(recur_time->recur_type);
    if (recur_type_local_JSON == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_type]");
        goto end;
    }
    cJSON_AddItemToObject(item, "recurType", recur_type_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_type]");
        goto end;
    }
    }

    if (recur_time->recur_month) {
    cJSON *recur_month = cJSON_AddArrayToObject(item, "recurMonth");
    if (recur_month == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_month]");
        goto end;
    }

    OpenAPI_lnode_t *recur_month_node;
    OpenAPI_list_for_each(recur_time->recur_month, recur_month_node)  {
    if (cJSON_AddNumberToObject(recur_month, "", *(double *)recur_month_node->data) == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_month]");
        goto end;
    }
                    }
    }

    if (recur_time->recur_week) {
    cJSON *recur_week = cJSON_AddArrayToObject(item, "recurWeek");
    if (recur_week == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_week]");
        goto end;
    }

    OpenAPI_lnode_t *recur_week_node;
    OpenAPI_list_for_each(recur_time->recur_week, recur_week_node)  {
    if (cJSON_AddNumberToObject(recur_week, "", *(double *)recur_week_node->data) == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_week]");
        goto end;
    }
                    }
    }

    if (recur_time->recur_day) {
    cJSON *recur_day = cJSON_AddArrayToObject(item, "recurDay");
    if (recur_day == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_day]");
        goto end;
    }

    OpenAPI_lnode_t *recur_day_node;
    OpenAPI_list_for_each(recur_time->recur_day, recur_day_node)  {
    if (cJSON_AddNumberToObject(recur_day, "", *(double *)recur_day_node->data) == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_day]");
        goto end;
    }
                    }
    }

    if (recur_time->recur_date) {
    cJSON *recur_date = cJSON_AddArrayToObject(item, "recurDate");
    if (recur_date == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_date]");
        goto end;
    }

    OpenAPI_lnode_t *recur_date_node;
    OpenAPI_list_for_each(recur_time->recur_date, recur_date_node)  {
                    }
    }

    if (recur_time->recur_end_time) {
    if (cJSON_AddStringToObject(item, "recurEndTime", recur_time->recur_end_time) == NULL) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed [recur_end_time]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_recur_time_t *OpenAPI_recur_time_parseFromJSON(cJSON *recur_timeJSON)
{
    OpenAPI_recur_time_t *recur_time_local_var = NULL;
    cJSON *recur_time_window = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurTimeWindow");

    OpenAPI_valid_time_period_t *recur_time_window_local_nonprim = NULL;
    if (recur_time_window) {
    recur_time_window_local_nonprim = OpenAPI_valid_time_period_parseFromJSON(recur_time_window);
    }

    cJSON *recur_type = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurType");

    OpenAPI_recur_type_t *recur_type_local_nonprim = NULL;
    if (recur_type) {
    recur_type_local_nonprim = OpenAPI_recur_type_parseFromJSON(recur_type);
    }

    cJSON *recur_month = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurMonth");

    OpenAPI_list_t *recur_monthList;
    if (recur_month) {
    cJSON *recur_month_local;
    if (!cJSON_IsArray(recur_month)) {
        ogs_error("OpenAPI_recur_time_parseFromJSON() failed [recur_month]");
        goto end;
    }
    recur_monthList = OpenAPI_list_create();

    cJSON_ArrayForEach(recur_month_local, recur_month) {
    if (!cJSON_IsNumber(recur_month_local)) {
        ogs_error("OpenAPI_recur_time_parseFromJSON() failed [recur_month]");
        goto end;
    }
    OpenAPI_list_add(recur_monthList, &recur_month_local->valuedouble);
    }
    }

    cJSON *recur_week = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurWeek");

    OpenAPI_list_t *recur_weekList;
    if (recur_week) {
    cJSON *recur_week_local;
    if (!cJSON_IsArray(recur_week)) {
        ogs_error("OpenAPI_recur_time_parseFromJSON() failed [recur_week]");
        goto end;
    }
    recur_weekList = OpenAPI_list_create();

    cJSON_ArrayForEach(recur_week_local, recur_week) {
    if (!cJSON_IsNumber(recur_week_local)) {
        ogs_error("OpenAPI_recur_time_parseFromJSON() failed [recur_week]");
        goto end;
    }
    OpenAPI_list_add(recur_weekList, &recur_week_local->valuedouble);
    }
    }

    cJSON *recur_day = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurDay");

    OpenAPI_list_t *recur_dayList;
    if (recur_day) {
    cJSON *recur_day_local;
    if (!cJSON_IsArray(recur_day)) {
        ogs_error("OpenAPI_recur_time_parseFromJSON() failed [recur_day]");
        goto end;
    }
    recur_dayList = OpenAPI_list_create();

    cJSON_ArrayForEach(recur_day_local, recur_day) {
    if (!cJSON_IsNumber(recur_day_local)) {
        ogs_error("OpenAPI_recur_time_parseFromJSON() failed [recur_day]");
        goto end;
    }
    OpenAPI_list_add(recur_dayList, &recur_day_local->valuedouble);
    }
    }

    cJSON *recur_date = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurDate");

    OpenAPI_list_t *recur_dateList;
    if (recur_date) {
    cJSON *recur_date_local;
    if (!cJSON_IsArray(recur_date)) {
        ogs_error("OpenAPI_recur_time_parseFromJSON() failed [recur_date]");
        goto end;
    }
    recur_dateList = OpenAPI_list_create();

    cJSON_ArrayForEach(recur_date_local, recur_date) {
    }
    }

    cJSON *recur_end_time = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurEndTime");

    if (recur_end_time) {
    if (!cJSON_IsString(recur_end_time)) {
        ogs_error("OpenAPI_recur_time_parseFromJSON() failed [recur_end_time]");
        goto end;
    }
    }

    recur_time_local_var = OpenAPI_recur_time_create (
        recur_time_window ? recur_time_window_local_nonprim : NULL,
        recur_type ? recur_type_local_nonprim : NULL,
        recur_month ? recur_monthList : NULL,
        recur_week ? recur_weekList : NULL,
        recur_day ? recur_dayList : NULL,
        recur_date ? recur_dateList : NULL,
        recur_end_time ? ogs_strdup(recur_end_time->valuestring) : NULL
    );

    return recur_time_local_var;
end:
    return NULL;
}

OpenAPI_recur_time_t *OpenAPI_recur_time_copy(OpenAPI_recur_time_t *dst, OpenAPI_recur_time_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_recur_time_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_recur_time_convertToJSON() failed");
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

    OpenAPI_recur_time_free(dst);
    dst = OpenAPI_recur_time_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

