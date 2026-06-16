#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "horizontal_with_vertical_velocity.h"



static horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_create_internal(
    float *h_speed,
    int *bearing,
    float *v_speed,
    lmf_location_vertical_direction__e v_direction
    ) {
    horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_local_var = malloc(sizeof(horizontal_with_vertical_velocity_t));
    if (!horizontal_with_vertical_velocity_local_var) {
        return NULL;
    }
    memset(horizontal_with_vertical_velocity_local_var, 0, sizeof(horizontal_with_vertical_velocity_t));
    horizontal_with_vertical_velocity_local_var->_library_owned = 1;
    horizontal_with_vertical_velocity_local_var->h_speed = h_speed;
    horizontal_with_vertical_velocity_local_var->bearing = bearing;
    horizontal_with_vertical_velocity_local_var->v_speed = v_speed;
    horizontal_with_vertical_velocity_local_var->v_direction = v_direction;
    return horizontal_with_vertical_velocity_local_var;
}

__attribute__((deprecated)) horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_create(
    float *h_speed,
    int *bearing,
    float *v_speed,
    lmf_location_vertical_direction__e v_direction
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
    horizontal_with_vertical_velocity_t *result = horizontal_with_vertical_velocity_create_internal (
        h_speed_copy,
        bearing_copy,
        v_speed_copy,
        v_direction
        );
    if (!result) {
        free(h_speed_copy);
        free(bearing_copy);
        free(v_speed_copy);
    }
    return result;
}

void horizontal_with_vertical_velocity_free(horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity) {
    if(NULL == horizontal_with_vertical_velocity){
        return ;
    }
    if(horizontal_with_vertical_velocity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "horizontal_with_vertical_velocity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (horizontal_with_vertical_velocity->h_speed) {
        free(horizontal_with_vertical_velocity->h_speed);
        horizontal_with_vertical_velocity->h_speed = NULL;
    }
    if (horizontal_with_vertical_velocity->bearing) {
        free(horizontal_with_vertical_velocity->bearing);
        horizontal_with_vertical_velocity->bearing = NULL;
    }
    if (horizontal_with_vertical_velocity->v_speed) {
        free(horizontal_with_vertical_velocity->v_speed);
        horizontal_with_vertical_velocity->v_speed = NULL;
    }
    free(horizontal_with_vertical_velocity);
}

cJSON *horizontal_with_vertical_velocity_convertToJSON(horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity) {
    cJSON *item = cJSON_CreateObject();

    // horizontal_with_vertical_velocity->h_speed
    if (!horizontal_with_vertical_velocity->h_speed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hSpeed", *horizontal_with_vertical_velocity->h_speed) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_with_vertical_velocity->bearing
    if (!horizontal_with_vertical_velocity->bearing) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bearing", *horizontal_with_vertical_velocity->bearing) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_with_vertical_velocity->v_speed
    if (!horizontal_with_vertical_velocity->v_speed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vSpeed", *horizontal_with_vertical_velocity->v_speed) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_with_vertical_velocity->v_direction
    if (lmf_location_vertical_direction__NULL == horizontal_with_vertical_velocity->v_direction) {
        goto fail;
    }
    cJSON *v_direction_local_JSON = vertical_direction_convertToJSON(horizontal_with_vertical_velocity->v_direction);
    if(v_direction_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "vDirection", v_direction_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_parseFromJSON(cJSON *horizontal_with_vertical_velocityJSON){

    horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_local_var = NULL;

    // define the local variable for horizontal_with_vertical_velocity->h_speed
    float *h_speed_local_var = NULL;

    // define the local variable for horizontal_with_vertical_velocity->bearing
    int *bearing_local_var = NULL;

    // define the local variable for horizontal_with_vertical_velocity->v_speed
    float *v_speed_local_var = NULL;

    // define the local variable for horizontal_with_vertical_velocity->v_direction
    lmf_location_vertical_direction__e v_direction_local_nonprim = 0;

    // horizontal_with_vertical_velocity->h_speed
    cJSON *h_speed = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocityJSON, "hSpeed");
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

    // horizontal_with_vertical_velocity->bearing
    cJSON *bearing = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocityJSON, "bearing");
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

    // horizontal_with_vertical_velocity->v_speed
    cJSON *v_speed = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocityJSON, "vSpeed");
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

    // horizontal_with_vertical_velocity->v_direction
    cJSON *v_direction = cJSON_GetObjectItemCaseSensitive(horizontal_with_vertical_velocityJSON, "vDirection");
    if (cJSON_IsNull(v_direction)) {
        v_direction = NULL;
    }
    if (!v_direction) {
        goto end;
    }

    
    v_direction_local_nonprim = vertical_direction_parseFromJSON(v_direction); //custom



    horizontal_with_vertical_velocity_local_var = horizontal_with_vertical_velocity_create_internal (
        h_speed_local_var,
        bearing_local_var,
        v_speed_local_var,
        v_direction_local_nonprim
        );

    if (!horizontal_with_vertical_velocity_local_var) {
        goto end;
    }

    return horizontal_with_vertical_velocity_local_var;
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
    return NULL;

}
