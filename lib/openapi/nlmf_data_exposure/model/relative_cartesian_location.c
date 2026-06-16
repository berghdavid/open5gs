#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "relative_cartesian_location.h"



static relative_cartesian_location_t *relative_cartesian_location_create_internal(
    float *x,
    float *y,
    float *z
    ) {
    relative_cartesian_location_t *relative_cartesian_location_local_var = malloc(sizeof(relative_cartesian_location_t));
    if (!relative_cartesian_location_local_var) {
        return NULL;
    }
    memset(relative_cartesian_location_local_var, 0, sizeof(relative_cartesian_location_t));
    relative_cartesian_location_local_var->_library_owned = 1;
    relative_cartesian_location_local_var->x = x;
    relative_cartesian_location_local_var->y = y;
    relative_cartesian_location_local_var->z = z;
    return relative_cartesian_location_local_var;
}

__attribute__((deprecated)) relative_cartesian_location_t *relative_cartesian_location_create(
    float *x,
    float *y,
    float *z
    ) {
    float *x_copy = NULL;
    if (x) {
        x_copy = malloc(sizeof(float));
        if (x_copy) *x_copy = *x;
    }
    float *y_copy = NULL;
    if (y) {
        y_copy = malloc(sizeof(float));
        if (y_copy) *y_copy = *y;
    }
    float *z_copy = NULL;
    if (z) {
        z_copy = malloc(sizeof(float));
        if (z_copy) *z_copy = *z;
    }
    relative_cartesian_location_t *result = relative_cartesian_location_create_internal (
        x_copy,
        y_copy,
        z_copy
        );
    if (!result) {
        free(x_copy);
        free(y_copy);
        free(z_copy);
    }
    return result;
}

void relative_cartesian_location_free(relative_cartesian_location_t *relative_cartesian_location) {
    if(NULL == relative_cartesian_location){
        return ;
    }
    if(relative_cartesian_location->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "relative_cartesian_location_free");
        return ;
    }
    listEntry_t *listEntry;
    if (relative_cartesian_location->x) {
        free(relative_cartesian_location->x);
        relative_cartesian_location->x = NULL;
    }
    if (relative_cartesian_location->y) {
        free(relative_cartesian_location->y);
        relative_cartesian_location->y = NULL;
    }
    if (relative_cartesian_location->z) {
        free(relative_cartesian_location->z);
        relative_cartesian_location->z = NULL;
    }
    free(relative_cartesian_location);
}

cJSON *relative_cartesian_location_convertToJSON(relative_cartesian_location_t *relative_cartesian_location) {
    cJSON *item = cJSON_CreateObject();

    // relative_cartesian_location->x
    if (!relative_cartesian_location->x) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "x", *relative_cartesian_location->x) == NULL) {
    goto fail; //Numeric
    }


    // relative_cartesian_location->y
    if (!relative_cartesian_location->y) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "y", *relative_cartesian_location->y) == NULL) {
    goto fail; //Numeric
    }


    // relative_cartesian_location->z
    if(relative_cartesian_location->z) {
    if(cJSON_AddNumberToObject(item, "z", *relative_cartesian_location->z) == NULL) {
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

relative_cartesian_location_t *relative_cartesian_location_parseFromJSON(cJSON *relative_cartesian_locationJSON){

    relative_cartesian_location_t *relative_cartesian_location_local_var = NULL;

    // define the local variable for relative_cartesian_location->x
    float *x_local_var = NULL;

    // define the local variable for relative_cartesian_location->y
    float *y_local_var = NULL;

    // define the local variable for relative_cartesian_location->z
    float *z_local_var = NULL;

    // relative_cartesian_location->x
    cJSON *x = cJSON_GetObjectItemCaseSensitive(relative_cartesian_locationJSON, "x");
    if (cJSON_IsNull(x)) {
        x = NULL;
    }
    if (!x) {
        goto end;
    }

    
    if(!cJSON_IsNumber(x))
    {
    goto end; //Numeric
    }
    x_local_var = malloc(sizeof(float));
    if(!x_local_var)
    {
        goto end;
    }
    *x_local_var = x->valuedouble;

    // relative_cartesian_location->y
    cJSON *y = cJSON_GetObjectItemCaseSensitive(relative_cartesian_locationJSON, "y");
    if (cJSON_IsNull(y)) {
        y = NULL;
    }
    if (!y) {
        goto end;
    }

    
    if(!cJSON_IsNumber(y))
    {
    goto end; //Numeric
    }
    y_local_var = malloc(sizeof(float));
    if(!y_local_var)
    {
        goto end;
    }
    *y_local_var = y->valuedouble;

    // relative_cartesian_location->z
    cJSON *z = cJSON_GetObjectItemCaseSensitive(relative_cartesian_locationJSON, "z");
    if (cJSON_IsNull(z)) {
        z = NULL;
    }
    if (z) { 
    if(!cJSON_IsNumber(z))
    {
    goto end; //Numeric
    }
    z_local_var = malloc(sizeof(float));
    if(!z_local_var)
    {
        goto end;
    }
    *z_local_var = z->valuedouble;
    }



    relative_cartesian_location_local_var = relative_cartesian_location_create_internal (
        x_local_var,
        y_local_var,
        z_local_var
        );

    if (!relative_cartesian_location_local_var) {
        goto end;
    }

    return relative_cartesian_location_local_var;
end:
    if (x_local_var) {
        free(x_local_var);
        x_local_var = NULL;
    }
    if (y_local_var) {
        free(y_local_var);
        y_local_var = NULL;
    }
    if (z_local_var) {
        free(z_local_var);
        z_local_var = NULL;
    }
    return NULL;

}
