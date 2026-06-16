#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "horizontal_with_vertical_velocity_and_uncertainty.h"



static horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty_create_internal(
    float *h_speed,
    int *bearing,
    float *v_speed,
    lmf_location_vertical_direction__e v_direction,
    float *h_uncertainty,
    float *v_uncertainty
    ) {
    horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty_local_var = malloc(sizeof(horizontal_with_vertical_velocity_and_uncertainty_t));
    if (!horizontal_with_vertical_velocity_and_uncertainty_local_var) {
        return NULL;
    }
    memset(horizontal_with_vertical_velocity_and_uncertainty_local_var, 0, sizeof(horizontal_with_vertical_velocity_and_uncertainty_t));
    horizontal_with_vertical_velocity_and_uncertainty_local_var->_library_owned = 1;
    horizontal_with_vertical_velocity_and_uncertainty_local_var->h_speed = h_speed;
    horizontal_with_vertical_velocity_and_uncertainty_local_var->bearing = bearing;
    horizontal_with_vertical_velocity_and_uncertainty_local_var->v_speed = v_speed;
    horizontal_with_vertical_velocity_and_uncertainty_local_var->v_direction = v_direction;
    horizontal_with_vertical_velocity_and_uncertainty_local_var->h_uncertainty = h_uncertainty;
    horizontal_with_vertical_velocity_and_uncertainty_local_var->v_uncertainty = v_uncertainty;
    return horizontal_with_vertical_velocity_and_uncertainty_local_var;
}

__attribute__((deprecated)) horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty_create(
    float *h_speed,
    int *bearing,
    float *v_speed,
    lmf_location_vertical_direction__e v_direction,
    float *h_uncertainty,
    float *v_uncertainty
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
    float *v_speed_copy = NULL;
    if (v_speed) {
        v_speed_copy = malloc(sizeof(float));
        if (v_speed_copy) *v_speed_copy = *v_speed;
    }
    float *h_uncertainty_copy = NULL;
    if (h_uncertainty) {
        h_uncertainty_copy = malloc(sizeof(float));
        if (h_uncertainty_copy) *h_uncertainty_copy = *h_uncertainty;
    }
    float *v_uncertainty_copy = NULL;
    if (v_uncertainty) {
        v_uncertainty_copy = malloc(sizeof(float));
        if (v_uncertainty_copy) *v_uncertainty_copy = *v_uncertainty;
    }
    horizontal_with_vertical_velocity_and_uncertainty_t *result = horizontal_with_vertical_velocity_and_uncertainty_create_internal (
        h_speed_copy,
        bearing_copy,
        v_speed_copy,
        v_direction,
        h_uncertainty_copy,
        v_uncertainty_copy
        );
    if (!result) {
        free(h_speed_copy);
        free(bearing_copy);
        free(v_speed_copy);
        free(h_uncertainty_copy);
        free(v_uncertainty_copy);
    }
    return result;
}

void horizontal_with_vertical_velocity_and_uncertainty_free(horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty) {
    if(NULL == horizontal_with_vertical_velocity_and_uncertainty){
        return ;
    }
    if(horizontal_with_vertical_velocity_and_uncertainty->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "horizontal_with_vertical_velocity_and_uncertainty_free");
        return ;
    }
    listEntry_t *listEntry;
    if (horizontal_with_vertical_velocity_and_uncertainty->h_speed) {
        free(horizontal_with_vertical_velocity_and_uncertainty->h_speed);
        horizontal_with_vertical_velocity_and_uncertainty->h_speed = NULL;
    }
    if (horizontal_with_vertical_velocity_and_uncertainty->bearing) {
        free(horizontal_with_vertical_velocity_and_uncertainty->bearing);
        horizontal_with_vertical_velocity_and_uncertainty->bearing = NULL;
    }
    if (horizontal_with_vertical_velocity_and_uncertainty->v_speed) {
        free(horizontal_with_vertical_velocity_and_uncertainty->v_speed);
        horizontal_with_vertical_velocity_and_uncertainty->v_speed = NULL;
    }
    if (horizontal_with_vertical_velocity_and_uncertainty->h_uncertainty) {
        free(horizontal_with_vertical_velocity_and_uncertainty->h_uncertainty);
        horizontal_with_vertical_velocity_and_uncertainty->h_uncertainty = NULL;
    }
    if (horizontal_with_vertical_velocity_and_uncertainty->v_uncertainty) {
        free(horizontal_with_vertical_velocity_and_uncertainty->v_uncertainty);
        horizontal_with_vertical_velocity_and_uncertainty->v_uncertainty = NULL;
    }
    free(horizontal_with_vertical_velocity_and_uncertainty);
}

cJSON *horizontal_with_vertical_velocity_and_uncertainty_convertToJSON(horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty) {
    cJSON *item = cJSON_CreateObject();

    // horizontal_with_vertical_velocity_and_uncertainty->h_speed
    if (!horizontal_with_vertical_velocity_and_uncertainty->h_speed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hSpeed", *horizontal_with_vertical_velocity_and_uncertainty->h_speed) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_with_vertical_velocity_and_uncertainty->bearing
    if (!horizontal_with_vertical_velocity_and_uncertainty->bearing) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bearing", *horizontal_with_vertical_velocity_and_uncertainty->bearing) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_with_vertical_velocity_and_uncertainty->v_speed
    if (!horizontal_with_vertical_velocity_and_uncertainty->v_speed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vSpeed", *horizontal_with_vertical_velocity_and_uncertainty->v_speed) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_with_vertical_velocity_and_uncertainty->v_direction
    if (lmf_location_vertical_direction__NULL == horizontal_with_vertical_velocity_and_uncertainty->v_direction) {
        goto fail;
    }
    cJSON *v_direction_local_JSON = vertical_direction_convertToJSON(horizontal_with_vertical_velocity_and_uncertainty->v_direction);
    if(v_direction_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "vDirection", v_direction_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // horizontal_with_vertical_velocity_and_uncertainty->h_uncertainty
    if (!horizontal_with_vertical_velocity_and_uncertainty->h_uncertainty) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hUncertainty", *horizontal_with_vertical_velocity_and_uncertainty->h_uncertainty) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_with_vertical_velocity_and_uncertainty->v_uncertainty
    if (!horizontal_with_vertical_velocity_and_uncertainty->v_uncertainty) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vUncertainty", *horizontal_with_vertical_velocity_and_uncertainty->v_uncertainty) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty_parseFromJSON(cJSON *horizontal_with_vertical_velocity_and_uncertaintyJSON){

    horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty_local_var = NULL;

    // define the local variable for horizontal_with_vertical_velocity_and_uncertainty->h_speed
    float *h_speed_local_var = NULL;

    // define the local variable for horizontal_with_vertical_velocity_and_uncertainty->bearing
    int *bearing_local_var = NULL;

    // define the local variable for horizontal_with_vertical_velocity_and_uncertainty->v_speed
    float *v_speed_local_var = NULL;

    // define the local variable for horizontal_with_vertical_velocity_and_uncertainty->v_direction
    lmf_location_vertical_direction__e v_direction_local_nonprim = 0;

    // define the local variable for horizontal_with_vertical_velocity_and_uncertainty->h_uncertainty
    float *h_uncertainty_local_var = NULL;

    // define the local variable for horizontal_with_vertical_velocity_and_uncertainty->v_uncertainty
    float *v_uncertainty_local_var = NULL;

    // horizontal_with_vertical_velocity_and_uncertainty->h_speed
    cJSON *h_speed = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocity_and_uncertaintyJSON, "hSpeed");
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

    // horizontal_with_vertical_velocity_and_uncertainty->bearing
    cJSON *bearing = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocity_and_uncertaintyJSON, "bearing");
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

    // horizontal_with_vertical_velocity_and_uncertainty->v_speed
    cJSON *v_speed = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocity_and_uncertaintyJSON, "vSpeed");
    if (cJSON_IsNull(v_speed)) {
        v_speed = NULL;
    }
    if (!v_speed) {
        goto end;
    }

    
    if(!cJSON_IsNumber(v_speed))
    {
    goto end; //Numeric
    }
    v_speed_local_var = malloc(sizeof(float));
    if(!v_speed_local_var)
    {
        goto end;
    }
    *v_speed_local_var = v_speed->valuedouble;

    // horizontal_with_vertical_velocity_and_uncertainty->v_direction
    cJSON *v_direction = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocity_and_uncertaintyJSON, "vDirection");
    if (cJSON_IsNull(v_direction)) {
        v_direction = NULL;
    }
    if (!v_direction) {
        goto end;
    }

    
    v_direction_local_nonprim = vertical_direction_parseFromJSON(v_direction); //custom

    // horizontal_with_vertical_velocity_and_uncertainty->h_uncertainty
    cJSON *h_uncertainty = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocity_and_uncertaintyJSON, "hUncertainty");
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

    // horizontal_with_vertical_velocity_and_uncertainty->v_uncertainty
    cJSON *v_uncertainty = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocity_and_uncertaintyJSON, "vUncertainty");
    if (cJSON_IsNull(v_uncertainty)) {
        v_uncertainty = NULL;
    }
    if (!v_uncertainty) {
        goto end;
    }

    
    if(!cJSON_IsNumber(v_uncertainty))
    {
    goto end; //Numeric
    }
    v_uncertainty_local_var = malloc(sizeof(float));
    if(!v_uncertainty_local_var)
    {
        goto end;
    }
    *v_uncertainty_local_var = v_uncertainty->valuedouble;



    horizontal_with_vertical_velocity_and_uncertainty_local_var = horizontal_with_vertical_velocity_and_uncertainty_create_internal (
        h_speed_local_var,
        bearing_local_var,
        v_speed_local_var,
        v_direction_local_nonprim,
        h_uncertainty_local_var,
        v_uncertainty_local_var
        );

    if (!horizontal_with_vertical_velocity_and_uncertainty_local_var) {
        goto end;
    }

    return horizontal_with_vertical_velocity_and_uncertainty_local_var;
end:
    if (h_speed_local_var) {
        free(h_speed_local_var);
        h_speed_local_var = NULL;
    }
    if (bearing_local_var) {
        free(bearing_local_var);
        bearing_local_var = NULL;
    }
    if (v_speed_local_var) {
        free(v_speed_local_var);
        v_speed_local_var = NULL;
    }
    if (v_direction_local_nonprim) {
        v_direction_local_nonprim = 0;
    }
    if (h_uncertainty_local_var) {
        free(h_uncertainty_local_var);
        h_uncertainty_local_var = NULL;
    }
    if (v_uncertainty_local_var) {
        free(v_uncertainty_local_var);
        v_uncertainty_local_var = NULL;
    }
    return NULL;

}
