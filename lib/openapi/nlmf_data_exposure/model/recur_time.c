#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recur_time.h"



static recur_time_t *recur_time_create_internal(
    valid_time_period_t *recur_time_window,
    recur_type_t *recur_type,
    list_t *recur_month,
    list_t *recur_week,
    list_t *recur_day,
    list_t *recur_date,
    char *recur_end_time
    ) {
    recur_time_t *recur_time_local_var = malloc(sizeof(recur_time_t));
    if (!recur_time_local_var) {
        return NULL;
    }
    memset(recur_time_local_var, 0, sizeof(recur_time_t));
    recur_time_local_var->_library_owned = 1;
    recur_time_local_var->recur_time_window = recur_time_window;
    recur_time_local_var->recur_type = recur_type;
    recur_time_local_var->recur_month = recur_month;
    recur_time_local_var->recur_week = recur_week;
    recur_time_local_var->recur_day = recur_day;
    recur_time_local_var->recur_date = recur_date;
    recur_time_local_var->recur_end_time = recur_end_time;
    return recur_time_local_var;
}

__attribute__((deprecated)) recur_time_t *recur_time_create(
    valid_time_period_t *recur_time_window,
    recur_type_t *recur_type,
    list_t *recur_month,
    list_t *recur_week,
    list_t *recur_day,
    list_t *recur_date,
    char *recur_end_time
    ) {
    recur_time_t *result = recur_time_create_internal (
        recur_time_window,
        recur_type,
        recur_month,
        recur_week,
        recur_day,
        recur_date,
        recur_end_time
        );
    if (!result) {
    }
    return result;
}

void recur_time_free(recur_time_t *recur_time) {
    if(NULL == recur_time){
        return ;
    }
    if(recur_time->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "recur_time_free");
        return ;
    }
    listEntry_t *listEntry;
    if (recur_time->recur_time_window) {
        valid_time_period_free(recur_time->recur_time_window);
        recur_time->recur_time_window = NULL;
    }
    if (recur_time->recur_type) {
        recur_type_free(recur_time->recur_type);
        recur_time->recur_type = NULL;
    }
    if (recur_time->recur_month) {
        list_ForEach(listEntry, recur_time->recur_month) {
            free(listEntry->data);
        }
        list_freeList(recur_time->recur_month);
        recur_time->recur_month = NULL;
    }
    if (recur_time->recur_week) {
        list_ForEach(listEntry, recur_time->recur_week) {
            free(listEntry->data);
        }
        list_freeList(recur_time->recur_week);
        recur_time->recur_week = NULL;
    }
    if (recur_time->recur_day) {
        list_ForEach(listEntry, recur_time->recur_day) {
            free(listEntry->data);
        }
        list_freeList(recur_time->recur_day);
        recur_time->recur_day = NULL;
    }
    if (recur_time->recur_date) {
        list_ForEach(listEntry, recur_time->recur_date) {
            free(listEntry->data);
        }
        list_freeList(recur_time->recur_date);
        recur_time->recur_date = NULL;
    }
    if (recur_time->recur_end_time) {
        free(recur_time->recur_end_time);
        recur_time->recur_end_time = NULL;
    }
    free(recur_time);
}

cJSON *recur_time_convertToJSON(recur_time_t *recur_time) {
    cJSON *item = cJSON_CreateObject();

    // recur_time->recur_time_window
    if(recur_time->recur_time_window) {
    cJSON *recur_time_window_local_JSON = valid_time_period_convertToJSON(recur_time->recur_time_window);
    if(recur_time_window_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "recurTimeWindow", recur_time_window_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // recur_time->recur_type
    if(recur_time->recur_type) {
    cJSON *recur_type_local_JSON = recur_type_convertToJSON(recur_time->recur_type);
    if(recur_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "recurType", recur_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // recur_time->recur_month
    if(recur_time->recur_month) {
    cJSON *recur_month = cJSON_AddArrayToObject(item, "recurMonth");
    if(recur_month == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *recur_monthListEntry;
    list_ForEach(recur_monthListEntry, recur_time->recur_month) {
    if(cJSON_AddNumberToObject(recur_month, "", *(double *)recur_monthListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // recur_time->recur_week
    if(recur_time->recur_week) {
    cJSON *recur_week = cJSON_AddArrayToObject(item, "recurWeek");
    if(recur_week == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *recur_weekListEntry;
    list_ForEach(recur_weekListEntry, recur_time->recur_week) {
    if(cJSON_AddNumberToObject(recur_week, "", *(double *)recur_weekListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // recur_time->recur_day
    if(recur_time->recur_day) {
    cJSON *recur_day = cJSON_AddArrayToObject(item, "recurDay");
    if(recur_day == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *recur_dayListEntry;
    list_ForEach(recur_dayListEntry, recur_time->recur_day) {
    if(cJSON_AddNumberToObject(recur_day, "", *(double *)recur_dayListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // recur_time->recur_date
    if(recur_time->recur_date) {
    cJSON *recur_date = cJSON_AddArrayToObject(item, "recurDate");
    if(recur_date == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *recur_dateListEntry;
    list_ForEach(recur_dateListEntry, recur_time->recur_date) {
    }
    }


    // recur_time->recur_end_time
    if(recur_time->recur_end_time) {
    if(cJSON_AddStringToObject(item, "recurEndTime", recur_time->recur_end_time) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

recur_time_t *recur_time_parseFromJSON(cJSON *recur_timeJSON){

    recur_time_t *recur_time_local_var = NULL;

    // define the local variable for recur_time->recur_time_window
    valid_time_period_t *recur_time_window_local_nonprim = NULL;

    // define the local variable for recur_time->recur_type
    recur_type_t *recur_type_local_nonprim = NULL;

    // define the local list for recur_time->recur_month
    list_t *recur_monthList = NULL;

    // define the local list for recur_time->recur_week
    list_t *recur_weekList = NULL;

    // define the local list for recur_time->recur_day
    list_t *recur_dayList = NULL;

    // define the local list for recur_time->recur_date
    list_t *recur_dateList = NULL;

    char *recur_end_time_local_str = NULL;

    // recur_time->recur_time_window
    cJSON *recur_time_window = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurTimeWindow");
    if (cJSON_IsNull(recur_time_window)) {
        recur_time_window = NULL;
    }
    if (recur_time_window) { 
    recur_time_window_local_nonprim = valid_time_period_parseFromJSON(recur_time_window); //nonprimitive
    }

    // recur_time->recur_type
    cJSON *recur_type = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurType");
    if (cJSON_IsNull(recur_type)) {
        recur_type = NULL;
    }
    if (recur_type) { 
    recur_type_local_nonprim = recur_type_parseFromJSON(recur_type); //nonprimitive
    }

    // recur_time->recur_month
    cJSON *recur_month = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurMonth");
    if (cJSON_IsNull(recur_month)) {
        recur_month = NULL;
    }
    if (recur_month) { 
    cJSON *recur_month_local = NULL;
    if(!cJSON_IsArray(recur_month)) {
        goto end;//primitive container
    }
    recur_monthList = list_createList();

    cJSON_ArrayForEach(recur_month_local, recur_month)
    {
        if(!cJSON_IsNumber(recur_month_local))
        {
            goto end;
        }
        double *recur_month_local_value = calloc(1, sizeof(double));
        if(!recur_month_local_value)
        {
            goto end;
        }
        *recur_month_local_value = recur_month_local->valuedouble;
        list_addElement(recur_monthList , recur_month_local_value);
    }
    }

    // recur_time->recur_week
    cJSON *recur_week = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurWeek");
    if (cJSON_IsNull(recur_week)) {
        recur_week = NULL;
    }
    if (recur_week) { 
    cJSON *recur_week_local = NULL;
    if(!cJSON_IsArray(recur_week)) {
        goto end;//primitive container
    }
    recur_weekList = list_createList();

    cJSON_ArrayForEach(recur_week_local, recur_week)
    {
        if(!cJSON_IsNumber(recur_week_local))
        {
            goto end;
        }
        double *recur_week_local_value = calloc(1, sizeof(double));
        if(!recur_week_local_value)
        {
            goto end;
        }
        *recur_week_local_value = recur_week_local->valuedouble;
        list_addElement(recur_weekList , recur_week_local_value);
    }
    }

    // recur_time->recur_day
    cJSON *recur_day = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurDay");
    if (cJSON_IsNull(recur_day)) {
        recur_day = NULL;
    }
    if (recur_day) { 
    cJSON *recur_day_local = NULL;
    if(!cJSON_IsArray(recur_day)) {
        goto end;//primitive container
    }
    recur_dayList = list_createList();

    cJSON_ArrayForEach(recur_day_local, recur_day)
    {
        if(!cJSON_IsNumber(recur_day_local))
        {
            goto end;
        }
        double *recur_day_local_value = calloc(1, sizeof(double));
        if(!recur_day_local_value)
        {
            goto end;
        }
        *recur_day_local_value = recur_day_local->valuedouble;
        list_addElement(recur_dayList , recur_day_local_value);
    }
    }

    // recur_time->recur_date
    cJSON *recur_date = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurDate");
    if (cJSON_IsNull(recur_date)) {
        recur_date = NULL;
    }
    if (recur_date) { 
    cJSON *recur_date_local = NULL;
    if(!cJSON_IsArray(recur_date)) {
        goto end;//primitive container
    }
    recur_dateList = list_createList();

    cJSON_ArrayForEach(recur_date_local, recur_date)
    {
    }
    }

    // recur_time->recur_end_time
    cJSON *recur_end_time = cJSON_GetObjectItemCaseSensitive(recur_timeJSON, "recurEndTime");
    if (cJSON_IsNull(recur_end_time)) {
        recur_end_time = NULL;
    }
    if (recur_end_time) { 
    if(!cJSON_IsString(recur_end_time) && !cJSON_IsNull(recur_end_time))
    {
    goto end; //DateTime
    }
    }


    if (recur_end_time && !cJSON_IsNull(recur_end_time)) recur_end_time_local_str = strdup(recur_end_time->valuestring);

    recur_time_local_var = recur_time_create_internal (
        recur_time_window ? recur_time_window_local_nonprim : NULL,
        recur_type ? recur_type_local_nonprim : NULL,
        recur_month ? recur_monthList : NULL,
        recur_week ? recur_weekList : NULL,
        recur_day ? recur_dayList : NULL,
        recur_date ? recur_dateList : NULL,
        recur_end_time_local_str
        );

    if (!recur_time_local_var) {
        goto end;
    }

    return recur_time_local_var;
end:
    if (recur_time_window_local_nonprim) {
        valid_time_period_free(recur_time_window_local_nonprim);
        recur_time_window_local_nonprim = NULL;
    }
    if (recur_type_local_nonprim) {
        recur_type_free(recur_type_local_nonprim);
        recur_type_local_nonprim = NULL;
    }
    if (recur_monthList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, recur_monthList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(recur_monthList);
        recur_monthList = NULL;
    }
    if (recur_weekList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, recur_weekList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(recur_weekList);
        recur_weekList = NULL;
    }
    if (recur_dayList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, recur_dayList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(recur_dayList);
        recur_dayList = NULL;
    }
    if (recur_dateList) {
        list_freeList(recur_dateList);
        recur_dateList = NULL;
    }
    if (recur_end_time_local_str) {
        free(recur_end_time_local_str);
        recur_end_time_local_str = NULL;
    }
    return NULL;

}
