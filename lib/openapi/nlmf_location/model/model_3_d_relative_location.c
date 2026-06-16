#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_3_d_relative_location.h"



static model_3_d_relative_location_t *model_3_d_relative_location_create_internal(
    float *semi_minor,
    float *semi_major,
    float *vertical_uncertainty,
    int *orientation_angle
    ) {
    model_3_d_relative_location_t *model_3_d_relative_location_local_var = malloc(sizeof(model_3_d_relative_location_t));
    if (!model_3_d_relative_location_local_var) {
        return NULL;
    }
    memset(model_3_d_relative_location_local_var, 0, sizeof(model_3_d_relative_location_t));
    model_3_d_relative_location_local_var->_library_owned = 1;
    model_3_d_relative_location_local_var->semi_minor = semi_minor;
    model_3_d_relative_location_local_var->semi_major = semi_major;
    model_3_d_relative_location_local_var->vertical_uncertainty = vertical_uncertainty;
    model_3_d_relative_location_local_var->orientation_angle = orientation_angle;
    return model_3_d_relative_location_local_var;
}

__attribute__((deprecated)) model_3_d_relative_location_t *model_3_d_relative_location_create(
    float *semi_minor,
    float *semi_major,
    float *vertical_uncertainty,
    int *orientation_angle
    ) {
    float *semi_minor_copy = NULL;
    if (semi_minor) {
        semi_minor_copy = malloc(sizeof(float));
        if (semi_minor_copy) *semi_minor_copy = *semi_minor;
    }
    float *semi_major_copy = NULL;
    if (semi_major) {
        semi_major_copy = malloc(sizeof(float));
        if (semi_major_copy) *semi_major_copy = *semi_major;
    }
    float *vertical_uncertainty_copy = NULL;
    if (vertical_uncertainty) {
        vertical_uncertainty_copy = malloc(sizeof(float));
        if (vertical_uncertainty_copy) *vertical_uncertainty_copy = *vertical_uncertainty;
    }
    int *orientation_angle_copy = NULL;
    if (orientation_angle) {
        orientation_angle_copy = malloc(sizeof(int));
        if (orientation_angle_copy) *orientation_angle_copy = *orientation_angle;
    }
    model_3_d_relative_location_t *result = model_3_d_relative_location_create_internal (
        semi_minor_copy,
        semi_major_copy,
        vertical_uncertainty_copy,
        orientation_angle_copy
        );
    if (!result) {
        free(semi_minor_copy);
        free(semi_major_copy);
        free(vertical_uncertainty_copy);
        free(orientation_angle_copy);
    }
    return result;
}

void model_3_d_relative_location_free(model_3_d_relative_location_t *model_3_d_relative_location) {
    if(NULL == model_3_d_relative_location){
        return ;
    }
    if(model_3_d_relative_location->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_3_d_relative_location_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model_3_d_relative_location->semi_minor) {
        free(model_3_d_relative_location->semi_minor);
        model_3_d_relative_location->semi_minor = NULL;
    }
    if (model_3_d_relative_location->semi_major) {
        free(model_3_d_relative_location->semi_major);
        model_3_d_relative_location->semi_major = NULL;
    }
    if (model_3_d_relative_location->vertical_uncertainty) {
        free(model_3_d_relative_location->vertical_uncertainty);
        model_3_d_relative_location->vertical_uncertainty = NULL;
    }
    if (model_3_d_relative_location->orientation_angle) {
        free(model_3_d_relative_location->orientation_angle);
        model_3_d_relative_location->orientation_angle = NULL;
    }
    free(model_3_d_relative_location);
}

cJSON *model_3_d_relative_location_convertToJSON(model_3_d_relative_location_t *model_3_d_relative_location) {
    cJSON *item = cJSON_CreateObject();

    // model_3_d_relative_location->semi_minor
    if(model_3_d_relative_location->semi_minor) {
    if(cJSON_AddNumberToObject(item, "semiMinor", *model_3_d_relative_location->semi_minor) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_3_d_relative_location->semi_major
    if(model_3_d_relative_location->semi_major) {
    if(cJSON_AddNumberToObject(item, "semiMajor", *model_3_d_relative_location->semi_major) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_3_d_relative_location->vertical_uncertainty
    if(model_3_d_relative_location->vertical_uncertainty) {
    if(cJSON_AddNumberToObject(item, "verticalUncertainty", *model_3_d_relative_location->vertical_uncertainty) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_3_d_relative_location->orientation_angle
    if(model_3_d_relative_location->orientation_angle) {
    if(cJSON_AddNumberToObject(item, "orientationAngle", *model_3_d_relative_location->orientation_angle) == NULL) {
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

model_3_d_relative_location_t *model_3_d_relative_location_parseFromJSON(cJSON *model_3_d_relative_locationJSON){

    model_3_d_relative_location_t *model_3_d_relative_location_local_var = NULL;

    // define the local variable for model_3_d_relative_location->semi_minor
    float *semi_minor_local_var = NULL;

    // define the local variable for model_3_d_relative_location->semi_major
    float *semi_major_local_var = NULL;

    // define the local variable for model_3_d_relative_location->vertical_uncertainty
    float *vertical_uncertainty_local_var = NULL;

    // define the local variable for model_3_d_relative_location->orientation_angle
    int *orientation_angle_local_var = NULL;

    // model_3_d_relative_location->semi_minor
    cJSON *semi_minor = cJSON_GetObjectItemCaseSensitive(model_3_d_relative_locationJSON, "semiMinor");
    if (cJSON_IsNull(semi_minor)) {
        semi_minor = NULL;
    }
    if (semi_minor) { 
    if(!cJSON_IsNumber(semi_minor))
    {
    goto end; //Numeric
    }
    semi_minor_local_var = malloc(sizeof(float));
    if(!semi_minor_local_var)
    {
        goto end;
    }
    *semi_minor_local_var = semi_minor->valuedouble;
    }

    // model_3_d_relative_location->semi_major
    cJSON *semi_major = cJSON_GetObjectItemCaseSensitive(model_3_d_relative_locationJSON, "semiMajor");
    if (cJSON_IsNull(semi_major)) {
        semi_major = NULL;
    }
    if (semi_major) { 
    if(!cJSON_IsNumber(semi_major))
    {
    goto end; //Numeric
    }
    semi_major_local_var = malloc(sizeof(float));
    if(!semi_major_local_var)
    {
        goto end;
    }
    *semi_major_local_var = semi_major->valuedouble;
    }

    // model_3_d_relative_location->vertical_uncertainty
    cJSON *vertical_uncertainty = cJSON_GetObjectItemCaseSensitive(model_3_d_relative_locationJSON, "verticalUncertainty");
    if (cJSON_IsNull(vertical_uncertainty)) {
        vertical_uncertainty = NULL;
    }
    if (vertical_uncertainty) { 
    if(!cJSON_IsNumber(vertical_uncertainty))
    {
    goto end; //Numeric
    }
    vertical_uncertainty_local_var = malloc(sizeof(float));
    if(!vertical_uncertainty_local_var)
    {
        goto end;
    }
    *vertical_uncertainty_local_var = vertical_uncertainty->valuedouble;
    }

    // model_3_d_relative_location->orientation_angle
    cJSON *orientation_angle = cJSON_GetObjectItemCaseSensitive(model_3_d_relative_locationJSON, "orientationAngle");
    if (cJSON_IsNull(orientation_angle)) {
        orientation_angle = NULL;
    }
    if (orientation_angle) { 
    if(!cJSON_IsNumber(orientation_angle))
    {
    goto end; //Numeric
    }
    orientation_angle_local_var = malloc(sizeof(int));
    if(!orientation_angle_local_var)
    {
        goto end;
    }
    *orientation_angle_local_var = orientation_angle->valuedouble;
    }



    model_3_d_relative_location_local_var = model_3_d_relative_location_create_internal (
        semi_minor_local_var,
        semi_major_local_var,
        vertical_uncertainty_local_var,
        orientation_angle_local_var
        );

    if (!model_3_d_relative_location_local_var) {
        goto end;
    }

    return model_3_d_relative_location_local_var;
end:
    if (semi_minor_local_var) {
        free(semi_minor_local_var);
        semi_minor_local_var = NULL;
    }
    if (semi_major_local_var) {
        free(semi_major_local_var);
        semi_major_local_var = NULL;
    }
    if (vertical_uncertainty_local_var) {
        free(vertical_uncertainty_local_var);
        vertical_uncertainty_local_var = NULL;
    }
    if (orientation_angle_local_var) {
        free(orientation_angle_local_var);
        orientation_angle_local_var = NULL;
    }
    return NULL;

}
