#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "periodic_event_info.h"



static periodic_event_info_t *periodic_event_info_create_internal(
    int *reporting_amount,
    int *reporting_interval,
    int *reporting_infinite_ind,
    int *reporting_interval_ms
    ) {
    periodic_event_info_t *periodic_event_info_local_var = malloc(sizeof(periodic_event_info_t));
    if (!periodic_event_info_local_var) {
        return NULL;
    }
    memset(periodic_event_info_local_var, 0, sizeof(periodic_event_info_t));
    periodic_event_info_local_var->_library_owned = 1;
    periodic_event_info_local_var->reporting_amount = reporting_amount;
    periodic_event_info_local_var->reporting_interval = reporting_interval;
    periodic_event_info_local_var->reporting_infinite_ind = reporting_infinite_ind;
    periodic_event_info_local_var->reporting_interval_ms = reporting_interval_ms;
    return periodic_event_info_local_var;
}

__attribute__((deprecated)) periodic_event_info_t *periodic_event_info_create(
    int *reporting_amount,
    int *reporting_interval,
    int *reporting_infinite_ind,
    int *reporting_interval_ms
    ) {
    int *reporting_amount_copy = NULL;
    if (reporting_amount) {
        reporting_amount_copy = malloc(sizeof(int));
        if (reporting_amount_copy) *reporting_amount_copy = *reporting_amount;
    }
    int *reporting_interval_copy = NULL;
    if (reporting_interval) {
        reporting_interval_copy = malloc(sizeof(int));
        if (reporting_interval_copy) *reporting_interval_copy = *reporting_interval;
    }
    int *reporting_infinite_ind_copy = NULL;
    if (reporting_infinite_ind) {
        reporting_infinite_ind_copy = malloc(sizeof(int));
        if (reporting_infinite_ind_copy) *reporting_infinite_ind_copy = *reporting_infinite_ind;
    }
    int *reporting_interval_ms_copy = NULL;
    if (reporting_interval_ms) {
        reporting_interval_ms_copy = malloc(sizeof(int));
        if (reporting_interval_ms_copy) *reporting_interval_ms_copy = *reporting_interval_ms;
    }
    periodic_event_info_t *result = periodic_event_info_create_internal (
        reporting_amount_copy,
        reporting_interval_copy,
        reporting_infinite_ind_copy,
        reporting_interval_ms_copy
        );
    if (!result) {
        free(reporting_amount_copy);
        free(reporting_interval_copy);
        free(reporting_infinite_ind_copy);
        free(reporting_interval_ms_copy);
    }
    return result;
}

void periodic_event_info_free(periodic_event_info_t *periodic_event_info) {
    if(NULL == periodic_event_info){
        return ;
    }
    if(periodic_event_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "periodic_event_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (periodic_event_info->reporting_amount) {
        free(periodic_event_info->reporting_amount);
        periodic_event_info->reporting_amount = NULL;
    }
    if (periodic_event_info->reporting_interval) {
        free(periodic_event_info->reporting_interval);
        periodic_event_info->reporting_interval = NULL;
    }
    if (periodic_event_info->reporting_infinite_ind) {
        free(periodic_event_info->reporting_infinite_ind);
        periodic_event_info->reporting_infinite_ind = NULL;
    }
    if (periodic_event_info->reporting_interval_ms) {
        free(periodic_event_info->reporting_interval_ms);
        periodic_event_info->reporting_interval_ms = NULL;
    }
    free(periodic_event_info);
}

cJSON *periodic_event_info_convertToJSON(periodic_event_info_t *periodic_event_info) {
    cJSON *item = cJSON_CreateObject();

    // periodic_event_info->reporting_amount
    if (!periodic_event_info->reporting_amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "reportingAmount", *periodic_event_info->reporting_amount) == NULL) {
    goto fail; //Numeric
    }


    // periodic_event_info->reporting_interval
    if (!periodic_event_info->reporting_interval) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "reportingInterval", *periodic_event_info->reporting_interval) == NULL) {
    goto fail; //Numeric
    }


    // periodic_event_info->reporting_infinite_ind
    if(periodic_event_info->reporting_infinite_ind) {
    if(cJSON_AddBoolToObject(item, "reportingInfiniteInd", *periodic_event_info->reporting_infinite_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // periodic_event_info->reporting_interval_ms
    if(periodic_event_info->reporting_interval_ms) {
    if(cJSON_AddNumberToObject(item, "reportingIntervalMs", *periodic_event_info->reporting_interval_ms) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

periodic_event_info_t *periodic_event_info_parseFromJSON(cJSON *periodic_event_infoJSON){

    periodic_event_info_t *periodic_event_info_local_var = NULL;

    // define the local variable for periodic_event_info->reporting_amount
    int *reporting_amount_local_var = NULL;

    // define the local variable for periodic_event_info->reporting_interval
    int *reporting_interval_local_var = NULL;

    // define the local variable for periodic_event_info->reporting_infinite_ind
    int *reporting_infinite_ind_local_var = NULL;

    // define the local variable for periodic_event_info->reporting_interval_ms
    int *reporting_interval_ms_local_var = NULL;

    // periodic_event_info->reporting_amount
    cJSON *reporting_amount = cJSON_GetObjectItemCaseSensitive(periodic_event_infoJSON, "reportingAmount");
    if (cJSON_IsNull(reporting_amount)) {
        reporting_amount = NULL;
    }
    if (!reporting_amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(reporting_amount))
    {
    goto end; //Numeric
    }
    reporting_amount_local_var = malloc(sizeof(int));
    if(!reporting_amount_local_var)
    {
        goto end;
    }
    *reporting_amount_local_var = reporting_amount->valuedouble;

    // periodic_event_info->reporting_interval
    cJSON *reporting_interval = cJSON_GetObjectItemCaseSensitive(periodic_event_infoJSON, "reportingInterval");
    if (cJSON_IsNull(reporting_interval)) {
        reporting_interval = NULL;
    }
    if (!reporting_interval) {
        goto end;
    }

    
    if(!cJSON_IsNumber(reporting_interval))
    {
    goto end; //Numeric
    }
    reporting_interval_local_var = malloc(sizeof(int));
    if(!reporting_interval_local_var)
    {
        goto end;
    }
    *reporting_interval_local_var = reporting_interval->valuedouble;

    // periodic_event_info->reporting_infinite_ind
    cJSON *reporting_infinite_ind = cJSON_GetObjectItemCaseSensitive(periodic_event_infoJSON, "reportingInfiniteInd");
    if (cJSON_IsNull(reporting_infinite_ind)) {
        reporting_infinite_ind = NULL;
    }
    if (reporting_infinite_ind) { 
    if(!cJSON_IsBool(reporting_infinite_ind))
    {
    goto end; //Bool
    }
    reporting_infinite_ind_local_var = malloc(sizeof(int));
    if(!reporting_infinite_ind_local_var)
    {
        goto end;
    }
    *reporting_infinite_ind_local_var = reporting_infinite_ind->valueint;
    }

    // periodic_event_info->reporting_interval_ms
    cJSON *reporting_interval_ms = cJSON_GetObjectItemCaseSensitive(periodic_event_infoJSON, "reportingIntervalMs");
    if (cJSON_IsNull(reporting_interval_ms)) {
        reporting_interval_ms = NULL;
    }
    if (reporting_interval_ms) { 
    if(!cJSON_IsNumber(reporting_interval_ms))
    {
    goto end; //Numeric
    }
    reporting_interval_ms_local_var = malloc(sizeof(int));
    if(!reporting_interval_ms_local_var)
    {
        goto end;
    }
    *reporting_interval_ms_local_var = reporting_interval_ms->valuedouble;
    }



    periodic_event_info_local_var = periodic_event_info_create_internal (
        reporting_amount_local_var,
        reporting_interval_local_var,
        reporting_infinite_ind_local_var,
        reporting_interval_ms_local_var
        );

    if (!periodic_event_info_local_var) {
        goto end;
    }

    return periodic_event_info_local_var;
end:
    if (reporting_amount_local_var) {
        free(reporting_amount_local_var);
        reporting_amount_local_var = NULL;
    }
    if (reporting_interval_local_var) {
        free(reporting_interval_local_var);
        reporting_interval_local_var = NULL;
    }
    if (reporting_infinite_ind_local_var) {
        free(reporting_infinite_ind_local_var);
        reporting_infinite_ind_local_var = NULL;
    }
    if (reporting_interval_ms_local_var) {
        free(reporting_interval_ms_local_var);
        reporting_interval_ms_local_var = NULL;
    }
    return NULL;

}
