#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "horizontal_velocity.h"



static horizontal_velocity_t *horizontal_velocity_create_internal(
    float *h_speed,
    int *bearing
    ) {
    horizontal_velocity_t *horizontal_velocity_local_var = malloc(sizeof(horizontal_velocity_t));
    if (!horizontal_velocity_local_var) {
        return NULL;
    }
    memset(horizontal_velocity_local_var, 0, sizeof(horizontal_velocity_t));
    horizontal_velocity_local_var->_library_owned = 1;
    horizontal_velocity_local_var->h_speed = h_speed;
    horizontal_velocity_local_var->bearing = bearing;
    return horizontal_velocity_local_var;
}

__attribute__((deprecated)) horizontal_velocity_t *horizontal_velocity_create(
    float *h_speed,
    int *bearing
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
    horizontal_velocity_t *result = horizontal_velocity_create_internal (
        h_speed_copy,
        bearing_copy
        );
    if (!result) {
        free(h_speed_copy);
        free(bearing_copy);
    }
    return result;
}

void horizontal_velocity_free(horizontal_velocity_t *horizontal_velocity) {
    if(NULL == horizontal_velocity){
        return ;
    }
    if(horizontal_velocity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "horizontal_velocity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (horizontal_velocity->h_speed) {
        free(horizontal_velocity->h_speed);
        horizontal_velocity->h_speed = NULL;
    }
    if (horizontal_velocity->bearing) {
        free(horizontal_velocity->bearing);
        horizontal_velocity->bearing = NULL;
    }
    free(horizontal_velocity);
}

cJSON *horizontal_velocity_convertToJSON(horizontal_velocity_t *horizontal_velocity) {
    cJSON *item = cJSON_CreateObject();

    // horizontal_velocity->h_speed
    if (!horizontal_velocity->h_speed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hSpeed", *horizontal_velocity->h_speed) == NULL) {
    goto fail; //Numeric
    }


    // horizontal_velocity->bearing
    if (!horizontal_velocity->bearing) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bearing", *horizontal_velocity->bearing) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

horizontal_velocity_t *horizontal_velocity_parseFromJSON(cJSON *horizontal_velocityJSON){

    horizontal_velocity_t *horizontal_velocity_local_var = NULL;

    // define the local variable for horizontal_velocity->h_speed
    float *h_speed_local_var = NULL;

    // define the local variable for horizontal_velocity->bearing
    int *bearing_local_var = NULL;

    // horizontal_velocity->h_speed
    cJSON *h_speed = cJSON_GetObjectItemCaseSensitive(horizontal_velocityJSON, "hSpeed");
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

    // horizontal_velocity->bearing
    cJSON *bearing = cJSON_GetObjectItemCaseSensitive(horizontal_velocityJSON, "bearing");
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



    horizontal_velocity_local_var = horizontal_velocity_create_internal (
        h_speed_local_var,
        bearing_local_var
        );

    if (!horizontal_velocity_local_var) {
        goto end;
    }

    return horizontal_velocity_local_var;
end:
    if (h_speed_local_var) {
        free(h_speed_local_var);
        h_speed_local_var = NULL;
    }
    if (bearing_local_var) {
        free(bearing_local_var);
        bearing_local_var = NULL;
    }
    return NULL;

}
