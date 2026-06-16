#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "uncertainty_ellipsoid.h"



static uncertainty_ellipsoid_t *uncertainty_ellipsoid_create_internal(
    float *semi_major,
    float *semi_minor,
    float *vertical,
    int *orientation_major
    ) {
    uncertainty_ellipsoid_t *uncertainty_ellipsoid_local_var = malloc(sizeof(uncertainty_ellipsoid_t));
    if (!uncertainty_ellipsoid_local_var) {
        return NULL;
    }
    memset(uncertainty_ellipsoid_local_var, 0, sizeof(uncertainty_ellipsoid_t));
    uncertainty_ellipsoid_local_var->_library_owned = 1;
    uncertainty_ellipsoid_local_var->semi_major = semi_major;
    uncertainty_ellipsoid_local_var->semi_minor = semi_minor;
    uncertainty_ellipsoid_local_var->vertical = vertical;
    uncertainty_ellipsoid_local_var->orientation_major = orientation_major;
    return uncertainty_ellipsoid_local_var;
}

__attribute__((deprecated)) uncertainty_ellipsoid_t *uncertainty_ellipsoid_create(
    float *semi_major,
    float *semi_minor,
    float *vertical,
    int *orientation_major
    ) {
    float *semi_major_copy = NULL;
    if (semi_major) {
        semi_major_copy = malloc(sizeof(float));
        if (semi_major_copy) *semi_major_copy = *semi_major;
    }
    float *semi_minor_copy = NULL;
    if (semi_minor) {
        semi_minor_copy = malloc(sizeof(float));
        if (semi_minor_copy) *semi_minor_copy = *semi_minor;
    }
    float *vertical_copy = NULL;
    if (vertical) {
        vertical_copy = malloc(sizeof(float));
        if (vertical_copy) *vertical_copy = *vertical;
    }
    int *orientation_major_copy = NULL;
    if (orientation_major) {
        orientation_major_copy = malloc(sizeof(int));
        if (orientation_major_copy) *orientation_major_copy = *orientation_major;
    }
    uncertainty_ellipsoid_t *result = uncertainty_ellipsoid_create_internal (
        semi_major_copy,
        semi_minor_copy,
        vertical_copy,
        orientation_major_copy
        );
    if (!result) {
        free(semi_major_copy);
        free(semi_minor_copy);
        free(vertical_copy);
        free(orientation_major_copy);
    }
    return result;
}

void uncertainty_ellipsoid_free(uncertainty_ellipsoid_t *uncertainty_ellipsoid) {
    if(NULL == uncertainty_ellipsoid){
        return ;
    }
    if(uncertainty_ellipsoid->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "uncertainty_ellipsoid_free");
        return ;
    }
    listEntry_t *listEntry;
    if (uncertainty_ellipsoid->semi_major) {
        free(uncertainty_ellipsoid->semi_major);
        uncertainty_ellipsoid->semi_major = NULL;
    }
    if (uncertainty_ellipsoid->semi_minor) {
        free(uncertainty_ellipsoid->semi_minor);
        uncertainty_ellipsoid->semi_minor = NULL;
    }
    if (uncertainty_ellipsoid->vertical) {
        free(uncertainty_ellipsoid->vertical);
        uncertainty_ellipsoid->vertical = NULL;
    }
    if (uncertainty_ellipsoid->orientation_major) {
        free(uncertainty_ellipsoid->orientation_major);
        uncertainty_ellipsoid->orientation_major = NULL;
    }
    free(uncertainty_ellipsoid);
}

cJSON *uncertainty_ellipsoid_convertToJSON(uncertainty_ellipsoid_t *uncertainty_ellipsoid) {
    cJSON *item = cJSON_CreateObject();

    // uncertainty_ellipsoid->semi_major
    if (!uncertainty_ellipsoid->semi_major) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "semiMajor", *uncertainty_ellipsoid->semi_major) == NULL) {
    goto fail; //Numeric
    }


    // uncertainty_ellipsoid->semi_minor
    if (!uncertainty_ellipsoid->semi_minor) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "semiMinor", *uncertainty_ellipsoid->semi_minor) == NULL) {
    goto fail; //Numeric
    }


    // uncertainty_ellipsoid->vertical
    if (!uncertainty_ellipsoid->vertical) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vertical", *uncertainty_ellipsoid->vertical) == NULL) {
    goto fail; //Numeric
    }


    // uncertainty_ellipsoid->orientation_major
    if (!uncertainty_ellipsoid->orientation_major) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "orientationMajor", *uncertainty_ellipsoid->orientation_major) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

uncertainty_ellipsoid_t *uncertainty_ellipsoid_parseFromJSON(cJSON *uncertainty_ellipsoidJSON){

    uncertainty_ellipsoid_t *uncertainty_ellipsoid_local_var = NULL;

    // define the local variable for uncertainty_ellipsoid->semi_major
    float *semi_major_local_var = NULL;

    // define the local variable for uncertainty_ellipsoid->semi_minor
    float *semi_minor_local_var = NULL;

    // define the local variable for uncertainty_ellipsoid->vertical
    float *vertical_local_var = NULL;

    // define the local variable for uncertainty_ellipsoid->orientation_major
    int *orientation_major_local_var = NULL;

    // uncertainty_ellipsoid->semi_major
    cJSON *semi_major = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipsoidJSON, "semiMajor");
    if (cJSON_IsNull(semi_major)) {
        semi_major = NULL;
    }
    if (!semi_major) {
        goto end;
    }

    
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

    // uncertainty_ellipsoid->semi_minor
    cJSON *semi_minor = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipsoidJSON, "semiMinor");
    if (cJSON_IsNull(semi_minor)) {
        semi_minor = NULL;
    }
    if (!semi_minor) {
        goto end;
    }

    
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

    // uncertainty_ellipsoid->vertical
    cJSON *vertical = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipsoidJSON, "vertical");
    if (cJSON_IsNull(vertical)) {
        vertical = NULL;
    }
    if (!vertical) {
        goto end;
    }

    
    if(!cJSON_IsNumber(vertical))
    {
    goto end; //Numeric
    }
    vertical_local_var = malloc(sizeof(float));
    if(!vertical_local_var)
    {
        goto end;
    }
    *vertical_local_var = vertical->valuedouble;

    // uncertainty_ellipsoid->orientation_major
    cJSON *orientation_major = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipsoidJSON, "orientationMajor");
    if (cJSON_IsNull(orientation_major)) {
        orientation_major = NULL;
    }
    if (!orientation_major) {
        goto end;
    }

    
    if(!cJSON_IsNumber(orientation_major))
    {
    goto end; //Numeric
    }
    orientation_major_local_var = malloc(sizeof(int));
    if(!orientation_major_local_var)
    {
        goto end;
    }
    *orientation_major_local_var = orientation_major->valuedouble;



    uncertainty_ellipsoid_local_var = uncertainty_ellipsoid_create_internal (
        semi_major_local_var,
        semi_minor_local_var,
        vertical_local_var,
        orientation_major_local_var
        );

    if (!uncertainty_ellipsoid_local_var) {
        goto end;
    }

    return uncertainty_ellipsoid_local_var;
end:
    if (semi_major_local_var) {
        free(semi_major_local_var);
        semi_major_local_var = NULL;
    }
    if (semi_minor_local_var) {
        free(semi_minor_local_var);
        semi_minor_local_var = NULL;
    }
    if (vertical_local_var) {
        free(vertical_local_var);
        vertical_local_var = NULL;
    }
    if (orientation_major_local_var) {
        free(orientation_major_local_var);
        orientation_major_local_var = NULL;
    }
    return NULL;

}
