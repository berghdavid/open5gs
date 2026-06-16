#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "valid_time_period.h"



static valid_time_period_t *valid_time_period_create_internal(
    char *start_time,
    char *end_time
    ) {
    valid_time_period_t *valid_time_period_local_var = malloc(sizeof(valid_time_period_t));
    if (!valid_time_period_local_var) {
        return NULL;
    }
    memset(valid_time_period_local_var, 0, sizeof(valid_time_period_t));
    valid_time_period_local_var->_library_owned = 1;
    valid_time_period_local_var->start_time = start_time;
    valid_time_period_local_var->end_time = end_time;
    return valid_time_period_local_var;
}

__attribute__((deprecated)) valid_time_period_t *valid_time_period_create(
    char *start_time,
    char *end_time
    ) {
    valid_time_period_t *result = valid_time_period_create_internal (
        start_time,
        end_time
        );
    if (!result) {
    }
    return result;
}

void valid_time_period_free(valid_time_period_t *valid_time_period) {
    if(NULL == valid_time_period){
        return ;
    }
    if(valid_time_period->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "valid_time_period_free");
        return ;
    }
    listEntry_t *listEntry;
    if (valid_time_period->start_time) {
        free(valid_time_period->start_time);
        valid_time_period->start_time = NULL;
    }
    if (valid_time_period->end_time) {
        free(valid_time_period->end_time);
        valid_time_period->end_time = NULL;
    }
    free(valid_time_period);
}

cJSON *valid_time_period_convertToJSON(valid_time_period_t *valid_time_period) {
    cJSON *item = cJSON_CreateObject();

    // valid_time_period->start_time
    if(valid_time_period->start_time) {
    if(cJSON_AddStringToObject(item, "startTime", valid_time_period->start_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // valid_time_period->end_time
    if(valid_time_period->end_time) {
    if(cJSON_AddStringToObject(item, "endTime", valid_time_period->end_time) == NULL) {
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

valid_time_period_t *valid_time_period_parseFromJSON(cJSON *valid_time_periodJSON){

    valid_time_period_t *valid_time_period_local_var = NULL;

    char *start_time_local_str = NULL;

    char *end_time_local_str = NULL;

    // valid_time_period->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(valid_time_periodJSON, "startTime");
    if (cJSON_IsNull(start_time)) {
        start_time = NULL;
    }
    if (start_time) { 
    if(!cJSON_IsString(start_time) && !cJSON_IsNull(start_time))
    {
    goto end; //DateTime
    }
    }

    // valid_time_period->end_time
    cJSON *end_time = cJSON_GetObjectItemCaseSensitive(valid_time_periodJSON, "endTime");
    if (cJSON_IsNull(end_time)) {
        end_time = NULL;
    }
    if (end_time) { 
    if(!cJSON_IsString(end_time) && !cJSON_IsNull(end_time))
    {
    goto end; //DateTime
    }
    }


    if (start_time && !cJSON_IsNull(start_time)) start_time_local_str = strdup(start_time->valuestring);
    if (end_time && !cJSON_IsNull(end_time)) end_time_local_str = strdup(end_time->valuestring);

    valid_time_period_local_var = valid_time_period_create_internal (
        start_time_local_str,
        end_time_local_str
        );

    if (!valid_time_period_local_var) {
        goto end;
    }

    return valid_time_period_local_var;
end:
    if (start_time_local_str) {
        free(start_time_local_str);
        start_time_local_str = NULL;
    }
    if (end_time_local_str) {
        free(end_time_local_str);
        end_time_local_str = NULL;
    }
    return NULL;

}
