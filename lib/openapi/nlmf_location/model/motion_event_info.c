#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "motion_event_info.h"



static motion_event_info_t *motion_event_info_create_internal(
    int *linear_distance,
    occurrence_info_t *occurrence_info,
    int *minimum_interval,
    int *maximum_interval,
    int *sampling_interval,
    int *reporting_duration,
    int *reporting_location_req
    ) {
    motion_event_info_t *motion_event_info_local_var = malloc(sizeof(motion_event_info_t));
    if (!motion_event_info_local_var) {
        return NULL;
    }
    memset(motion_event_info_local_var, 0, sizeof(motion_event_info_t));
    motion_event_info_local_var->_library_owned = 1;
    motion_event_info_local_var->linear_distance = linear_distance;
    motion_event_info_local_var->occurrence_info = occurrence_info;
    motion_event_info_local_var->minimum_interval = minimum_interval;
    motion_event_info_local_var->maximum_interval = maximum_interval;
    motion_event_info_local_var->sampling_interval = sampling_interval;
    motion_event_info_local_var->reporting_duration = reporting_duration;
    motion_event_info_local_var->reporting_location_req = reporting_location_req;
    return motion_event_info_local_var;
}

__attribute__((deprecated)) motion_event_info_t *motion_event_info_create(
    int *linear_distance,
    occurrence_info_t *occurrence_info,
    int *minimum_interval,
    int *maximum_interval,
    int *sampling_interval,
    int *reporting_duration,
    int *reporting_location_req
    ) {
    int *linear_distance_copy = NULL;
    if (linear_distance) {
        linear_distance_copy = malloc(sizeof(int));
        if (linear_distance_copy) *linear_distance_copy = *linear_distance;
    }
    int *minimum_interval_copy = NULL;
    if (minimum_interval) {
        minimum_interval_copy = malloc(sizeof(int));
        if (minimum_interval_copy) *minimum_interval_copy = *minimum_interval;
    }
    int *maximum_interval_copy = NULL;
    if (maximum_interval) {
        maximum_interval_copy = malloc(sizeof(int));
        if (maximum_interval_copy) *maximum_interval_copy = *maximum_interval;
    }
    int *sampling_interval_copy = NULL;
    if (sampling_interval) {
        sampling_interval_copy = malloc(sizeof(int));
        if (sampling_interval_copy) *sampling_interval_copy = *sampling_interval;
    }
    int *reporting_duration_copy = NULL;
    if (reporting_duration) {
        reporting_duration_copy = malloc(sizeof(int));
        if (reporting_duration_copy) *reporting_duration_copy = *reporting_duration;
    }
    int *reporting_location_req_copy = NULL;
    if (reporting_location_req) {
        reporting_location_req_copy = malloc(sizeof(int));
        if (reporting_location_req_copy) *reporting_location_req_copy = *reporting_location_req;
    }
    motion_event_info_t *result = motion_event_info_create_internal (
        linear_distance_copy,
        occurrence_info,
        minimum_interval_copy,
        maximum_interval_copy,
        sampling_interval_copy,
        reporting_duration_copy,
        reporting_location_req_copy
        );
    if (!result) {
        free(linear_distance_copy);
        free(minimum_interval_copy);
        free(maximum_interval_copy);
        free(sampling_interval_copy);
        free(reporting_duration_copy);
        free(reporting_location_req_copy);
    }
    return result;
}

void motion_event_info_free(motion_event_info_t *motion_event_info) {
    if(NULL == motion_event_info){
        return ;
    }
    if(motion_event_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "motion_event_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (motion_event_info->linear_distance) {
        free(motion_event_info->linear_distance);
        motion_event_info->linear_distance = NULL;
    }
    if (motion_event_info->occurrence_info) {
        occurrence_info_free(motion_event_info->occurrence_info);
        motion_event_info->occurrence_info = NULL;
    }
    if (motion_event_info->minimum_interval) {
        free(motion_event_info->minimum_interval);
        motion_event_info->minimum_interval = NULL;
    }
    if (motion_event_info->maximum_interval) {
        free(motion_event_info->maximum_interval);
        motion_event_info->maximum_interval = NULL;
    }
    if (motion_event_info->sampling_interval) {
        free(motion_event_info->sampling_interval);
        motion_event_info->sampling_interval = NULL;
    }
    if (motion_event_info->reporting_duration) {
        free(motion_event_info->reporting_duration);
        motion_event_info->reporting_duration = NULL;
    }
    if (motion_event_info->reporting_location_req) {
        free(motion_event_info->reporting_location_req);
        motion_event_info->reporting_location_req = NULL;
    }
    free(motion_event_info);
}

cJSON *motion_event_info_convertToJSON(motion_event_info_t *motion_event_info) {
    cJSON *item = cJSON_CreateObject();

    // motion_event_info->linear_distance
    if (!motion_event_info->linear_distance) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "linearDistance", *motion_event_info->linear_distance) == NULL) {
    goto fail; //Numeric
    }


    // motion_event_info->occurrence_info
    if(motion_event_info->occurrence_info) {
    cJSON *occurrence_info_local_JSON = occurrence_info_convertToJSON(motion_event_info->occurrence_info);
    if(occurrence_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "occurrenceInfo", occurrence_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // motion_event_info->minimum_interval
    if(motion_event_info->minimum_interval) {
    if(cJSON_AddNumberToObject(item, "minimumInterval", *motion_event_info->minimum_interval) == NULL) {
    goto fail; //Numeric
    }
    }


    // motion_event_info->maximum_interval
    if(motion_event_info->maximum_interval) {
    if(cJSON_AddNumberToObject(item, "maximumInterval", *motion_event_info->maximum_interval) == NULL) {
    goto fail; //Numeric
    }
    }


    // motion_event_info->sampling_interval
    if(motion_event_info->sampling_interval) {
    if(cJSON_AddNumberToObject(item, "samplingInterval", *motion_event_info->sampling_interval) == NULL) {
    goto fail; //Numeric
    }
    }


    // motion_event_info->reporting_duration
    if(motion_event_info->reporting_duration) {
    if(cJSON_AddNumberToObject(item, "reportingDuration", *motion_event_info->reporting_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // motion_event_info->reporting_location_req
    if(motion_event_info->reporting_location_req) {
    if(cJSON_AddBoolToObject(item, "reportingLocationReq", *motion_event_info->reporting_location_req) == NULL) {
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

motion_event_info_t *motion_event_info_parseFromJSON(cJSON *motion_event_infoJSON){

    motion_event_info_t *motion_event_info_local_var = NULL;

    // define the local variable for motion_event_info->linear_distance
    int *linear_distance_local_var = NULL;

    // define the local variable for motion_event_info->occurrence_info
    occurrence_info_t *occurrence_info_local_nonprim = NULL;

    // define the local variable for motion_event_info->minimum_interval
    int *minimum_interval_local_var = NULL;

    // define the local variable for motion_event_info->maximum_interval
    int *maximum_interval_local_var = NULL;

    // define the local variable for motion_event_info->sampling_interval
    int *sampling_interval_local_var = NULL;

    // define the local variable for motion_event_info->reporting_duration
    int *reporting_duration_local_var = NULL;

    // define the local variable for motion_event_info->reporting_location_req
    int *reporting_location_req_local_var = NULL;

    // motion_event_info->linear_distance
    cJSON *linear_distance = cJSON_GetObjectItemCaseSensitive(motion_event_infoJSON, "linearDistance");
    if (cJSON_IsNull(linear_distance)) {
        linear_distance = NULL;
    }
    if (!linear_distance) {
        goto end;
    }

    
    if(!cJSON_IsNumber(linear_distance))
    {
    goto end; //Numeric
    }
    linear_distance_local_var = malloc(sizeof(int));
    if(!linear_distance_local_var)
    {
        goto end;
    }
    *linear_distance_local_var = linear_distance->valuedouble;

    // motion_event_info->occurrence_info
    cJSON *occurrence_info = cJSON_GetObjectItemCaseSensitive(motion_event_infoJSON, "occurrenceInfo");
    if (cJSON_IsNull(occurrence_info)) {
        occurrence_info = NULL;
    }
    if (occurrence_info) { 
    occurrence_info_local_nonprim = occurrence_info_parseFromJSON(occurrence_info); //nonprimitive
    }

    // motion_event_info->minimum_interval
    cJSON *minimum_interval = cJSON_GetObjectItemCaseSensitive(motion_event_infoJSON, "minimumInterval");
    if (cJSON_IsNull(minimum_interval)) {
        minimum_interval = NULL;
    }
    if (minimum_interval) { 
    if(!cJSON_IsNumber(minimum_interval))
    {
    goto end; //Numeric
    }
    minimum_interval_local_var = malloc(sizeof(int));
    if(!minimum_interval_local_var)
    {
        goto end;
    }
    *minimum_interval_local_var = minimum_interval->valuedouble;
    }

    // motion_event_info->maximum_interval
    cJSON *maximum_interval = cJSON_GetObjectItemCaseSensitive(motion_event_infoJSON, "maximumInterval");
    if (cJSON_IsNull(maximum_interval)) {
        maximum_interval = NULL;
    }
    if (maximum_interval) { 
    if(!cJSON_IsNumber(maximum_interval))
    {
    goto end; //Numeric
    }
    maximum_interval_local_var = malloc(sizeof(int));
    if(!maximum_interval_local_var)
    {
        goto end;
    }
    *maximum_interval_local_var = maximum_interval->valuedouble;
    }

    // motion_event_info->sampling_interval
    cJSON *sampling_interval = cJSON_GetObjectItemCaseSensitive(motion_event_infoJSON, "samplingInterval");
    if (cJSON_IsNull(sampling_interval)) {
        sampling_interval = NULL;
    }
    if (sampling_interval) { 
    if(!cJSON_IsNumber(sampling_interval))
    {
    goto end; //Numeric
    }
    sampling_interval_local_var = malloc(sizeof(int));
    if(!sampling_interval_local_var)
    {
        goto end;
    }
    *sampling_interval_local_var = sampling_interval->valuedouble;
    }

    // motion_event_info->reporting_duration
    cJSON *reporting_duration = cJSON_GetObjectItemCaseSensitive(motion_event_infoJSON, "reportingDuration");
    if (cJSON_IsNull(reporting_duration)) {
        reporting_duration = NULL;
    }
    if (reporting_duration) { 
    if(!cJSON_IsNumber(reporting_duration))
    {
    goto end; //Numeric
    }
    reporting_duration_local_var = malloc(sizeof(int));
    if(!reporting_duration_local_var)
    {
        goto end;
    }
    *reporting_duration_local_var = reporting_duration->valuedouble;
    }

    // motion_event_info->reporting_location_req
    cJSON *reporting_location_req = cJSON_GetObjectItemCaseSensitive(motion_event_infoJSON, "reportingLocationReq");
    if (cJSON_IsNull(reporting_location_req)) {
        reporting_location_req = NULL;
    }
    if (reporting_location_req) { 
    if(!cJSON_IsBool(reporting_location_req))
    {
    goto end; //Bool
    }
    reporting_location_req_local_var = malloc(sizeof(int));
    if(!reporting_location_req_local_var)
    {
        goto end;
    }
    *reporting_location_req_local_var = reporting_location_req->valueint;
    }



    motion_event_info_local_var = motion_event_info_create_internal (
        linear_distance_local_var,
        occurrence_info ? occurrence_info_local_nonprim : NULL,
        minimum_interval_local_var,
        maximum_interval_local_var,
        sampling_interval_local_var,
        reporting_duration_local_var,
        reporting_location_req_local_var
        );

    if (!motion_event_info_local_var) {
        goto end;
    }

    return motion_event_info_local_var;
end:
    if (linear_distance_local_var) {
        free(linear_distance_local_var);
        linear_distance_local_var = NULL;
    }
    if (occurrence_info_local_nonprim) {
        occurrence_info_free(occurrence_info_local_nonprim);
        occurrence_info_local_nonprim = NULL;
    }
    if (minimum_interval_local_var) {
        free(minimum_interval_local_var);
        minimum_interval_local_var = NULL;
    }
    if (maximum_interval_local_var) {
        free(maximum_interval_local_var);
        maximum_interval_local_var = NULL;
    }
    if (sampling_interval_local_var) {
        free(sampling_interval_local_var);
        sampling_interval_local_var = NULL;
    }
    if (reporting_duration_local_var) {
        free(reporting_duration_local_var);
        reporting_duration_local_var = NULL;
    }
    if (reporting_location_req_local_var) {
        free(reporting_location_req_local_var);
        reporting_location_req_local_var = NULL;
    }
    return NULL;

}
