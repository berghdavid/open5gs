#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_location_info.h"



static ue_location_info_t *ue_location_info_create_internal(
    geographic_area_t *location_estimate,
    int *age_of_location_estimate,
    char *timestamp_of_location_estimate,
    velocity_estimate_t *velocity_estimate,
    int *age_of_velocity_estimate,
    char *timestamp_of_velocity_estimate
    ) {
    ue_location_info_t *ue_location_info_local_var = malloc(sizeof(ue_location_info_t));
    if (!ue_location_info_local_var) {
        return NULL;
    }
    memset(ue_location_info_local_var, 0, sizeof(ue_location_info_t));
    ue_location_info_local_var->_library_owned = 1;
    ue_location_info_local_var->location_estimate = location_estimate;
    ue_location_info_local_var->age_of_location_estimate = age_of_location_estimate;
    ue_location_info_local_var->timestamp_of_location_estimate = timestamp_of_location_estimate;
    ue_location_info_local_var->velocity_estimate = velocity_estimate;
    ue_location_info_local_var->age_of_velocity_estimate = age_of_velocity_estimate;
    ue_location_info_local_var->timestamp_of_velocity_estimate = timestamp_of_velocity_estimate;
    return ue_location_info_local_var;
}

__attribute__((deprecated)) ue_location_info_t *ue_location_info_create(
    geographic_area_t *location_estimate,
    int *age_of_location_estimate,
    char *timestamp_of_location_estimate,
    velocity_estimate_t *velocity_estimate,
    int *age_of_velocity_estimate,
    char *timestamp_of_velocity_estimate
    ) {
    int *age_of_location_estimate_copy = NULL;
    if (age_of_location_estimate) {
        age_of_location_estimate_copy = malloc(sizeof(int));
        if (age_of_location_estimate_copy) *age_of_location_estimate_copy = *age_of_location_estimate;
    }
    int *age_of_velocity_estimate_copy = NULL;
    if (age_of_velocity_estimate) {
        age_of_velocity_estimate_copy = malloc(sizeof(int));
        if (age_of_velocity_estimate_copy) *age_of_velocity_estimate_copy = *age_of_velocity_estimate;
    }
    ue_location_info_t *result = ue_location_info_create_internal (
        location_estimate,
        age_of_location_estimate_copy,
        timestamp_of_location_estimate,
        velocity_estimate,
        age_of_velocity_estimate_copy,
        timestamp_of_velocity_estimate
        );
    if (!result) {
        free(age_of_location_estimate_copy);
        free(age_of_velocity_estimate_copy);
    }
    return result;
}

void ue_location_info_free(ue_location_info_t *ue_location_info) {
    if(NULL == ue_location_info){
        return ;
    }
    if(ue_location_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ue_location_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ue_location_info->location_estimate) {
        geographic_area_free(ue_location_info->location_estimate);
        ue_location_info->location_estimate = NULL;
    }
    if (ue_location_info->age_of_location_estimate) {
        free(ue_location_info->age_of_location_estimate);
        ue_location_info->age_of_location_estimate = NULL;
    }
    if (ue_location_info->timestamp_of_location_estimate) {
        free(ue_location_info->timestamp_of_location_estimate);
        ue_location_info->timestamp_of_location_estimate = NULL;
    }
    if (ue_location_info->velocity_estimate) {
        velocity_estimate_free(ue_location_info->velocity_estimate);
        ue_location_info->velocity_estimate = NULL;
    }
    if (ue_location_info->age_of_velocity_estimate) {
        free(ue_location_info->age_of_velocity_estimate);
        ue_location_info->age_of_velocity_estimate = NULL;
    }
    if (ue_location_info->timestamp_of_velocity_estimate) {
        free(ue_location_info->timestamp_of_velocity_estimate);
        ue_location_info->timestamp_of_velocity_estimate = NULL;
    }
    free(ue_location_info);
}

cJSON *ue_location_info_convertToJSON(ue_location_info_t *ue_location_info) {
    cJSON *item = cJSON_CreateObject();

    // ue_location_info->location_estimate
    if(ue_location_info->location_estimate) {
    cJSON *location_estimate_local_JSON = geographic_area_convertToJSON(ue_location_info->location_estimate);
    if(location_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "locationEstimate", location_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ue_location_info->age_of_location_estimate
    if(ue_location_info->age_of_location_estimate) {
    if(cJSON_AddNumberToObject(item, "ageOfLocationEstimate", *ue_location_info->age_of_location_estimate) == NULL) {
    goto fail; //Numeric
    }
    }


    // ue_location_info->timestamp_of_location_estimate
    if(ue_location_info->timestamp_of_location_estimate) {
    if(cJSON_AddStringToObject(item, "timestampOfLocationEstimate", ue_location_info->timestamp_of_location_estimate) == NULL) {
    goto fail; //Date-Time
    }
    }


    // ue_location_info->velocity_estimate
    if(ue_location_info->velocity_estimate) {
    cJSON *velocity_estimate_local_JSON = velocity_estimate_convertToJSON(ue_location_info->velocity_estimate);
    if(velocity_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "velocityEstimate", velocity_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ue_location_info->age_of_velocity_estimate
    if(ue_location_info->age_of_velocity_estimate) {
    if(cJSON_AddNumberToObject(item, "ageOfVelocityEstimate", *ue_location_info->age_of_velocity_estimate) == NULL) {
    goto fail; //Numeric
    }
    }


    // ue_location_info->timestamp_of_velocity_estimate
    if(ue_location_info->timestamp_of_velocity_estimate) {
    if(cJSON_AddStringToObject(item, "timestampOfVelocityEstimate", ue_location_info->timestamp_of_velocity_estimate) == NULL) {
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

ue_location_info_t *ue_location_info_parseFromJSON(cJSON *ue_location_infoJSON){

    ue_location_info_t *ue_location_info_local_var = NULL;

    // define the local variable for ue_location_info->location_estimate
    geographic_area_t *location_estimate_local_nonprim = NULL;

    // define the local variable for ue_location_info->age_of_location_estimate
    int *age_of_location_estimate_local_var = NULL;

    char *timestamp_of_location_estimate_local_str = NULL;

    // define the local variable for ue_location_info->velocity_estimate
    velocity_estimate_t *velocity_estimate_local_nonprim = NULL;

    // define the local variable for ue_location_info->age_of_velocity_estimate
    int *age_of_velocity_estimate_local_var = NULL;

    char *timestamp_of_velocity_estimate_local_str = NULL;

    // ue_location_info->location_estimate
    cJSON *location_estimate = cJSON_GetObjectItemCaseSensitive(ue_location_infoJSON, "locationEstimate");
    if (cJSON_IsNull(location_estimate)) {
        location_estimate = NULL;
    }
    if (location_estimate) { 
    location_estimate_local_nonprim = geographic_area_parseFromJSON(location_estimate); //nonprimitive
    }

    // ue_location_info->age_of_location_estimate
    cJSON *age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(ue_location_infoJSON, "ageOfLocationEstimate");
    if (cJSON_IsNull(age_of_location_estimate)) {
        age_of_location_estimate = NULL;
    }
    if (age_of_location_estimate) { 
    if(!cJSON_IsNumber(age_of_location_estimate))
    {
    goto end; //Numeric
    }
    age_of_location_estimate_local_var = malloc(sizeof(int));
    if(!age_of_location_estimate_local_var)
    {
        goto end;
    }
    *age_of_location_estimate_local_var = age_of_location_estimate->valuedouble;
    }

    // ue_location_info->timestamp_of_location_estimate
    cJSON *timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(ue_location_infoJSON, "timestampOfLocationEstimate");
    if (cJSON_IsNull(timestamp_of_location_estimate)) {
        timestamp_of_location_estimate = NULL;
    }
    if (timestamp_of_location_estimate) { 
    if(!cJSON_IsString(timestamp_of_location_estimate) && !cJSON_IsNull(timestamp_of_location_estimate))
    {
    goto end; //DateTime
    }
    }

    // ue_location_info->velocity_estimate
    cJSON *velocity_estimate = cJSON_GetObjectItemCaseSensitive(ue_location_infoJSON, "velocityEstimate");
    if (cJSON_IsNull(velocity_estimate)) {
        velocity_estimate = NULL;
    }
    if (velocity_estimate) { 
    velocity_estimate_local_nonprim = velocity_estimate_parseFromJSON(velocity_estimate); //nonprimitive
    }

    // ue_location_info->age_of_velocity_estimate
    cJSON *age_of_velocity_estimate = cJSON_GetObjectItemCaseSensitive(ue_location_infoJSON, "ageOfVelocityEstimate");
    if (cJSON_IsNull(age_of_velocity_estimate)) {
        age_of_velocity_estimate = NULL;
    }
    if (age_of_velocity_estimate) { 
    if(!cJSON_IsNumber(age_of_velocity_estimate))
    {
    goto end; //Numeric
    }
    age_of_velocity_estimate_local_var = malloc(sizeof(int));
    if(!age_of_velocity_estimate_local_var)
    {
        goto end;
    }
    *age_of_velocity_estimate_local_var = age_of_velocity_estimate->valuedouble;
    }

    // ue_location_info->timestamp_of_velocity_estimate
    cJSON *timestamp_of_velocity_estimate = cJSON_GetObjectItemCaseSensitive(ue_location_infoJSON, "timestampOfVelocityEstimate");
    if (cJSON_IsNull(timestamp_of_velocity_estimate)) {
        timestamp_of_velocity_estimate = NULL;
    }
    if (timestamp_of_velocity_estimate) { 
    if(!cJSON_IsString(timestamp_of_velocity_estimate) && !cJSON_IsNull(timestamp_of_velocity_estimate))
    {
    goto end; //DateTime
    }
    }


    if (timestamp_of_location_estimate && !cJSON_IsNull(timestamp_of_location_estimate)) timestamp_of_location_estimate_local_str = strdup(timestamp_of_location_estimate->valuestring);
    if (timestamp_of_velocity_estimate && !cJSON_IsNull(timestamp_of_velocity_estimate)) timestamp_of_velocity_estimate_local_str = strdup(timestamp_of_velocity_estimate->valuestring);

    ue_location_info_local_var = ue_location_info_create_internal (
        location_estimate ? location_estimate_local_nonprim : NULL,
        age_of_location_estimate_local_var,
        timestamp_of_location_estimate_local_str,
        velocity_estimate ? velocity_estimate_local_nonprim : NULL,
        age_of_velocity_estimate_local_var,
        timestamp_of_velocity_estimate_local_str
        );

    if (!ue_location_info_local_var) {
        goto end;
    }

    return ue_location_info_local_var;
end:
    if (location_estimate_local_nonprim) {
        geographic_area_free(location_estimate_local_nonprim);
        location_estimate_local_nonprim = NULL;
    }
    if (age_of_location_estimate_local_var) {
        free(age_of_location_estimate_local_var);
        age_of_location_estimate_local_var = NULL;
    }
    if (timestamp_of_location_estimate_local_str) {
        free(timestamp_of_location_estimate_local_str);
        timestamp_of_location_estimate_local_str = NULL;
    }
    if (velocity_estimate_local_nonprim) {
        velocity_estimate_free(velocity_estimate_local_nonprim);
        velocity_estimate_local_nonprim = NULL;
    }
    if (age_of_velocity_estimate_local_var) {
        free(age_of_velocity_estimate_local_var);
        age_of_velocity_estimate_local_var = NULL;
    }
    if (timestamp_of_velocity_estimate_local_str) {
        free(timestamp_of_velocity_estimate_local_str);
        timestamp_of_velocity_estimate_local_str = NULL;
    }
    return NULL;

}
