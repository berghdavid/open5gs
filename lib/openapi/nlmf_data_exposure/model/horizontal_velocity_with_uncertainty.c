#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "horizontal_velocity_with_uncertainty.h"



static horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty_create_internal(
    float *h_speed,
    int *bearing,
    float *h_uncertainty
    ) {
    horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty_local_var = malloc(sizeof(horizontal_velocity_with_uncertainty_t));
    if (!horizontal_velocity_with_uncertainty_local_var) {
        return NULL;
    }
    memset(horizontal_velocity_with_uncertainty_local_var, 0, sizeof(horizontal_velocity_with_uncertainty_t));
    horizontal_velocity_with_uncertainty_local_var->_library_owned = 1;
    horizontal_velocity_with_uncertainty_local_var->h_speed = h_speed;
    horizontal_velocity_with_uncertainty_local_var->bearing = bearing;
    horizontal_velocity_with_uncertainty_local_var->h_uncertainty = h_uncertainty;
    return horizontal_velocity_with_uncertainty_local_var;
}

__attribute__((deprecated)) horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty_create(
    float *h_speed,
    int *bearing,
    float *h_uncertainty
    ) {
    float *h_speed_copy = NULL;
    if (h_speed) {
        h_speed_copy = malloc(sizeof(float));
        if (h_speed_copy) *h_speed_copy = *h_speed;
    }
    int *bearing_copy = NULL;
    if (bearing) {
        bearing_copy = malloc(sizeof(int));
        if (bearing_copy) *bearing_copy = *bearing;
    }
    float *h_uncertainty_copy = NULL;
    if (h_uncertainty) {
        h_uncertainty_copy = malloc(sizeof(float));
        if (h_uncertainty_copy) *h_uncertainty_copy = *h_uncertainty;
    }
    horizontal_velocity_with_uncertainty_t *result = horizontal_velocity_with_uncertainty_create_internal (
        h_speed_copy,
        bearing_copy,
        h_uncertainty_copy
        );
    if (!result) {
        free(h_speed_copy);
        free(bearing_copy);
        free(h_uncertainty_copy);
    }
    return result;
}

void horizontal_velocity_with_uncertainty_free(horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty) {
    if(NULL == horizontal_velocity_with_uncertainty){
        return ;
    }
    if(horizontal_velocity_with_uncertainty->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "horizontal_velocity_with_uncertainty_free");
        return ;
    }
    listEntry_t *listEntry;
    if (horizontal_velocity_with_uncertainty->h_speed) {
        free(horizontal_velocity_with_uncertainty->h_speed);
        horizontal_velocity_with_uncertainty->h_speed = NULL;
    }
    if (horizontal_velocity_with_uncertainty->bearing) {
        free(horizontal_velocity_with_uncertainty->bearing);
        horizontal_velocity_with_uncertainty->bearing = NULL;
    }
    if (horizontal_velocity_with_uncertainty->h_uncertainty) {
        free(horizontal_velocity_with_uncertainty->h_uncertainty);
        horizontal_velocity_with_uncertainty->h_uncertainty = NULL;
    }
    free(horizontal_velocity_with_uncertainty);
}

cJSON *horizontal_velocity_with_uncertainty_convertToJSON(horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty) {
    cJSON *item = cJSON_CreateObject();

    // horizontal_velocity_with_uncertainty->h_speed
    if (!horizontal_velocity_with_uncertainty->h_speed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hSpeed", *horizontal_velocity_with_uncertainty->h_speed) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_velocity_with_uncertainty->bearing
    if (!horizontal_velocity_with_uncertainty->bearing) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bearing", *horizontal_velocity_with_uncertainty->bearing) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_velocity_with_uncertainty->h_uncertainty
    if (!horizontal_velocity_with_uncertainty->h_uncertainty) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hUncertainty", *horizontal_velocity_with_uncertainty->h_uncertainty) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty_parseFromJSON(cJSON *horizontal_velocity_with_uncertaintyJSON){

    horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty_local_var = NULL;

    // define the local variable for horizontal_velocity_with_uncertainty->h_speed
    float *h_speed_local_var = NULL;

    // define the local variable for horizontal_velocity_with_uncertainty->bearing
    int *bearing_local_var = NULL;

    // define the local variable for horizontal_velocity_with_uncertainty->h_uncertainty
    float *h_uncertainty_local_var = NULL;

    // horizontal_velocity_with_uncertainty->h_speed
    cJSON *h_speed = cJSON_GetObjectItemCaseSensitive(horizontal_velocity_with_uncertaintyJSON, "hSpeed");
    if (cJSON_IsNull(h_speed)) {
        h_speed = NULL;
    }
    if (!h_speed) {
        goto end;
    }

    
    if(!cJSON_IsNumber(h_speed))
    {
    goto end; //Numeric
    }
    h_speed_local_var = malloc(sizeof(float));
    if(!h_speed_local_var)
    {
        goto end;
    }
    *h_speed_local_var = h_speed->valuedouble;

    // horizontal_velocity_with_uncertainty->bearing
    cJSON *bearing = cJSON_GetObjectItemCaseSensitive(horizontal_velocity_with_uncertaintyJSON, "bearing");
    if (cJSON_IsNull(bearing)) {
        bearing = NULL;
    }
    if (!bearing) {
        goto end;
    }

    
    if(!cJSON_IsNumber(bearing))
    {
    goto end; //Numeric
    }
    bearing_local_var = malloc(sizeof(int));
    if(!bearing_local_var)
    {
        goto end;
    }
    *bearing_local_var = bearing->valuedouble;

    // horizontal_velocity_with_uncertainty->h_uncertainty
    cJSON *h_uncertainty = cJSON_GetObjectItemCaseSensitive(horizontal_velocity_with_uncertaintyJSON, "hUncertainty");
    if (cJSON_IsNull(h_uncertainty)) {
        h_uncertainty = NULL;
    }
    if (!h_uncertainty) {
        goto end;
    }

    
    if(!cJSON_IsNumber(h_uncertainty))
    {
    goto end; //Numeric
    }
    h_uncertainty_local_var = malloc(sizeof(float));
    if(!h_uncertainty_local_var)
    {
        goto end;
    }
    *h_uncertainty_local_var = h_uncertainty->valuedouble;



    horizontal_velocity_with_uncertainty_local_var = horizontal_velocity_with_uncertainty_create_internal (
        h_speed_local_var,
        bearing_local_var,
        h_uncertainty_local_var
        );

    if (!horizontal_velocity_with_uncertainty_local_var) {
        goto end;
    }

    return horizontal_velocity_with_uncertainty_local_var;
end:
    if (h_speed_local_var) {
        free(h_speed_local_var);
        h_speed_local_var = NULL;
    }
    if (bearing_local_var) {
        free(bearing_local_var);
        bearing_local_var = NULL;
    }
    if (h_uncertainty_local_var) {
        free(h_uncertainty_local_var);
        h_uncertainty_local_var = NULL;
    }
    return NULL;

}
