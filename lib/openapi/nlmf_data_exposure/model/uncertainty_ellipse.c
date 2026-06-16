#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "uncertainty_ellipse.h"



static uncertainty_ellipse_t *uncertainty_ellipse_create_internal(
    float *semi_major,
    float *semi_minor,
    int *orientation_major
    ) {
    uncertainty_ellipse_t *uncertainty_ellipse_local_var = malloc(sizeof(uncertainty_ellipse_t));
    if (!uncertainty_ellipse_local_var) {
        return NULL;
    }
    memset(uncertainty_ellipse_local_var, 0, sizeof(uncertainty_ellipse_t));
    uncertainty_ellipse_local_var->_library_owned = 1;
    uncertainty_ellipse_local_var->semi_major = semi_major;
    uncertainty_ellipse_local_var->semi_minor = semi_minor;
    uncertainty_ellipse_local_var->orientation_major = orientation_major;
    return uncertainty_ellipse_local_var;
}

__attribute__((deprecated)) uncertainty_ellipse_t *uncertainty_ellipse_create(
    float *semi_major,
    float *semi_minor,
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
    int *orientation_major_copy = NULL;
    if (orientation_major) {
        orientation_major_copy = malloc(sizeof(int));
        if (orientation_major_copy) *orientation_major_copy = *orientation_major;
    }
    uncertainty_ellipse_t *result = uncertainty_ellipse_create_internal (
        semi_major_copy,
        semi_minor_copy,
        orientation_major_copy
        );
    if (!result) {
        free(semi_major_copy);
        free(semi_minor_copy);
        free(orientation_major_copy);
    }
    return result;
}

void uncertainty_ellipse_free(uncertainty_ellipse_t *uncertainty_ellipse) {
    if(NULL == uncertainty_ellipse){
        return ;
    }
    if(uncertainty_ellipse->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "uncertainty_ellipse_free");
        return ;
    }
    listEntry_t *listEntry;
    if (uncertainty_ellipse->semi_major) {
        free(uncertainty_ellipse->semi_major);
        uncertainty_ellipse->semi_major = NULL;
    }
    if (uncertainty_ellipse->semi_minor) {
        free(uncertainty_ellipse->semi_minor);
        uncertainty_ellipse->semi_minor = NULL;
    }
    if (uncertainty_ellipse->orientation_major) {
        free(uncertainty_ellipse->orientation_major);
        uncertainty_ellipse->orientation_major = NULL;
    }
    free(uncertainty_ellipse);
}

cJSON *uncertainty_ellipse_convertToJSON(uncertainty_ellipse_t *uncertainty_ellipse) {
    cJSON *item = cJSON_CreateObject();

    // uncertainty_ellipse->semi_major
    if (!uncertainty_ellipse->semi_major) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "semiMajor", *uncertainty_ellipse->semi_major) == NULL) {
    goto fail; //Numeric
    }


    // uncertainty_ellipse->semi_minor
    if (!uncertainty_ellipse->semi_minor) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "semiMinor", *uncertainty_ellipse->semi_minor) == NULL) {
    goto fail; //Numeric
    }


    // uncertainty_ellipse->orientation_major
    if (!uncertainty_ellipse->orientation_major) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "orientationMajor", *uncertainty_ellipse->orientation_major) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

uncertainty_ellipse_t *uncertainty_ellipse_parseFromJSON(cJSON *uncertainty_ellipseJSON){

    uncertainty_ellipse_t *uncertainty_ellipse_local_var = NULL;

    // define the local variable for uncertainty_ellipse->semi_major
    float *semi_major_local_var = NULL;

    // define the local variable for uncertainty_ellipse->semi_minor
    float *semi_minor_local_var = NULL;

    // define the local variable for uncertainty_ellipse->orientation_major
    int *orientation_major_local_var = NULL;

    // uncertainty_ellipse->semi_major
    cJSON *semi_major = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipseJSON, "semiMajor");
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

    // uncertainty_ellipse->semi_minor
    cJSON *semi_minor = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipseJSON, "semiMinor");
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

    // uncertainty_ellipse->orientation_major
    cJSON *orientation_major = cJSON_GetObjectItemCaseSensitive(uncertainty_ellipseJSON, "orientationMajor");
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



    uncertainty_ellipse_local_var = uncertainty_ellipse_create_internal (
        semi_major_local_var,
        semi_minor_local_var,
        orientation_major_local_var
        );

    if (!uncertainty_ellipse_local_var) {
        goto end;
    }

    return uncertainty_ellipse_local_var;
end:
    if (semi_major_local_var) {
        free(semi_major_local_var);
        semi_major_local_var = NULL;
    }
    if (semi_minor_local_var) {
        free(semi_minor_local_var);
        semi_minor_local_var = NULL;
    }
    if (orientation_major_local_var) {
        free(orientation_major_local_var);
        orientation_major_local_var = NULL;
    }
    return NULL;

}
