#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "area_event_info.h"



static area_event_info_t *area_event_info_create_internal(
    list_t *area_definition,
    occurrence_info_t *occurrence_info,
    int *minimum_interval,
    int *maximum_interval,
    int *sampling_interval,
    int *reporting_duration,
    int *reporting_location_req
    ) {
    area_event_info_t *area_event_info_local_var = malloc(sizeof(area_event_info_t));
    if (!area_event_info_local_var) {
        return NULL;
    }
    memset(area_event_info_local_var, 0, sizeof(area_event_info_t));
    area_event_info_local_var->_library_owned = 1;
    area_event_info_local_var->area_definition = area_definition;
    area_event_info_local_var->occurrence_info = occurrence_info;
    area_event_info_local_var->minimum_interval = minimum_interval;
    area_event_info_local_var->maximum_interval = maximum_interval;
    area_event_info_local_var->sampling_interval = sampling_interval;
    area_event_info_local_var->reporting_duration = reporting_duration;
    area_event_info_local_var->reporting_location_req = reporting_location_req;
    return area_event_info_local_var;
}

__attribute__((deprecated)) area_event_info_t *area_event_info_create(
    list_t *area_definition,
    occurrence_info_t *occurrence_info,
    int *minimum_interval,
    int *maximum_interval,
    int *sampling_interval,
    int *reporting_duration,
    int *reporting_location_req
    ) {
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
    area_event_info_t *result = area_event_info_create_internal (
        area_definition,
        occurrence_info,
        minimum_interval_copy,
        maximum_interval_copy,
        sampling_interval_copy,
        reporting_duration_copy,
        reporting_location_req_copy
        );
    if (!result) {
        free(minimum_interval_copy);
        free(maximum_interval_copy);
        free(sampling_interval_copy);
        free(reporting_duration_copy);
        free(reporting_location_req_copy);
    }
    return result;
}

void area_event_info_free(area_event_info_t *area_event_info) {
    if(NULL == area_event_info){
        return ;
    }
    if(area_event_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "area_event_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (area_event_info->area_definition) {
        list_ForEach(listEntry, area_event_info->area_definition) {
            reporting_area_free(listEntry->data);
        }
        list_freeList(area_event_info->area_definition);
        area_event_info->area_definition = NULL;
    }
    if (area_event_info->occurrence_info) {
        occurrence_info_free(area_event_info->occurrence_info);
        area_event_info->occurrence_info = NULL;
    }
    if (area_event_info->minimum_interval) {
        free(area_event_info->minimum_interval);
        area_event_info->minimum_interval = NULL;
    }
    if (area_event_info->maximum_interval) {
        free(area_event_info->maximum_interval);
        area_event_info->maximum_interval = NULL;
    }
    if (area_event_info->sampling_interval) {
        free(area_event_info->sampling_interval);
        area_event_info->sampling_interval = NULL;
    }
    if (area_event_info->reporting_duration) {
        free(area_event_info->reporting_duration);
        area_event_info->reporting_duration = NULL;
    }
    if (area_event_info->reporting_location_req) {
        free(area_event_info->reporting_location_req);
        area_event_info->reporting_location_req = NULL;
    }
    free(area_event_info);
}

cJSON *area_event_info_convertToJSON(area_event_info_t *area_event_info) {
    cJSON *item = cJSON_CreateObject();

    // area_event_info->area_definition
    if (!area_event_info->area_definition) {
        goto fail;
    }
    cJSON *area_definition = cJSON_AddArrayToObject(item, "areaDefinition");
    if(area_definition == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *area_definitionListEntry;
    if (area_event_info->area_definition) {
    list_ForEach(area_definitionListEntry, area_event_info->area_definition) {
    cJSON *itemLocal = reporting_area_convertToJSON(area_definitionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(area_definition, itemLocal);
    }
    }


    // area_event_info->occurrence_info
    if(area_event_info->occurrence_info) {
    cJSON *occurrence_info_local_JSON = occurrence_info_convertToJSON(area_event_info->occurrence_info);
    if(occurrence_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "occurrenceInfo", occurrence_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // area_event_info->minimum_interval
    if(area_event_info->minimum_interval) {
    if(cJSON_AddNumberToObject(item, "minimumInterval", *area_event_info->minimum_interval) == NULL) {
    goto fail; //Numeric
    }
    }


    // area_event_info->maximum_interval
    if(area_event_info->maximum_interval) {
    if(cJSON_AddNumberToObject(item, "maximumInterval", *area_event_info->maximum_interval) == NULL) {
    goto fail; //Numeric
    }
    }


    // area_event_info->sampling_interval
    if(area_event_info->sampling_interval) {
    if(cJSON_AddNumberToObject(item, "samplingInterval", *area_event_info->sampling_interval) == NULL) {
    goto fail; //Numeric
    }
    }


    // area_event_info->reporting_duration
    if(area_event_info->reporting_duration) {
    if(cJSON_AddNumberToObject(item, "reportingDuration", *area_event_info->reporting_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // area_event_info->reporting_location_req
    if(area_event_info->reporting_location_req) {
    if(cJSON_AddBoolToObject(item, "reportingLocationReq", *area_event_info->reporting_location_req) == NULL) {
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

area_event_info_t *area_event_info_parseFromJSON(cJSON *area_event_infoJSON){

    area_event_info_t *area_event_info_local_var = NULL;

    // define the local list for area_event_info->area_definition
    list_t *area_definitionList = NULL;

    // define the local variable for area_event_info->occurrence_info
    occurrence_info_t *occurrence_info_local_nonprim = NULL;

    // define the local variable for area_event_info->minimum_interval
    int *minimum_interval_local_var = NULL;

    // define the local variable for area_event_info->maximum_interval
    int *maximum_interval_local_var = NULL;

    // define the local variable for area_event_info->sampling_interval
    int *sampling_interval_local_var = NULL;

    // define the local variable for area_event_info->reporting_duration
    int *reporting_duration_local_var = NULL;

    // define the local variable for area_event_info->reporting_location_req
    int *reporting_location_req_local_var = NULL;

    // area_event_info->area_definition
    cJSON *area_definition = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON, "areaDefinition");
    if (cJSON_IsNull(area_definition)) {
        area_definition = NULL;
    }
    if (!area_definition) {
        goto end;
    }

    
    cJSON *area_definition_local_nonprimitive = NULL;
    if(!cJSON_IsArray(area_definition)){
        goto end; //nonprimitive container
    }

    area_definitionList = list_createList();

    cJSON_ArrayForEach(area_definition_local_nonprimitive,area_definition )
    {
        if(!cJSON_IsObject(area_definition_local_nonprimitive)){
            goto end;
        }
        reporting_area_t *area_definitionItem = reporting_area_parseFromJSON(area_definition_local_nonprimitive);

        list_addElement(area_definitionList, area_definitionItem);
    }

    // area_event_info->occurrence_info
    cJSON *occurrence_info = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON, "occurrenceInfo");
    if (cJSON_IsNull(occurrence_info)) {
        occurrence_info = NULL;
    }
    if (occurrence_info) { 
    occurrence_info_local_nonprim = occurrence_info_parseFromJSON(occurrence_info); //nonprimitive
    }

    // area_event_info->minimum_interval
    cJSON *minimum_interval = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON, "minimumInterval");
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

    // area_event_info->maximum_interval
    cJSON *maximum_interval = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON, "maximumInterval");
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

    // area_event_info->sampling_interval
    cJSON *sampling_interval = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON, "samplingInterval");
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

    // area_event_info->reporting_duration
    cJSON *reporting_duration = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON, "reportingDuration");
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

    // area_event_info->reporting_location_req
    cJSON *reporting_location_req = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON, "reportingLocationReq");
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



    area_event_info_local_var = area_event_info_create_internal (
        area_definitionList,
        occurrence_info ? occurrence_info_local_nonprim : NULL,
        minimum_interval_local_var,
        maximum_interval_local_var,
        sampling_interval_local_var,
        reporting_duration_local_var,
        reporting_location_req_local_var
        );

    if (!area_event_info_local_var) {
        goto end;
    }

    return area_event_info_local_var;
end:
    if (area_definitionList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, area_definitionList) {
            reporting_area_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(area_definitionList);
        area_definitionList = NULL;
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
