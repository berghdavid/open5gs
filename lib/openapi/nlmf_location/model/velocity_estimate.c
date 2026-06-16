#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "velocity_estimate.h"



static velocity_estimate_t *velocity_estimate_create_internal(
    float *h_speed,
    int *bearing,
    float *v_speed,
    lmf_location_vertical_direction__e v_direction,
    float *h_uncertainty,
    float *v_uncertainty,
    radial_velocity_t *r_velocity,
    angular_velocity_t *a_transverse_velocity,
    angular_velocity_t *e_transverse_velocity
    ) {
    velocity_estimate_t *velocity_estimate_local_var = malloc(sizeof(velocity_estimate_t));
    if (!velocity_estimate_local_var) {
        return NULL;
    }
    memset(velocity_estimate_local_var, 0, sizeof(velocity_estimate_t));
    velocity_estimate_local_var->_library_owned = 1;
    velocity_estimate_local_var->h_speed = h_speed;
    velocity_estimate_local_var->bearing = bearing;
    velocity_estimate_local_var->v_speed = v_speed;
    velocity_estimate_local_var->v_direction = v_direction;
    velocity_estimate_local_var->h_uncertainty = h_uncertainty;
    velocity_estimate_local_var->v_uncertainty = v_uncertainty;
    velocity_estimate_local_var->r_velocity = r_velocity;
    velocity_estimate_local_var->a_transverse_velocity = a_transverse_velocity;
    velocity_estimate_local_var->e_transverse_velocity = e_transverse_velocity;
    return velocity_estimate_local_var;
}

__attribute__((deprecated)) velocity_estimate_t *velocity_estimate_create(
    float *h_speed,
    int *bearing,
    float *v_speed,
    lmf_location_vertical_direction__e v_direction,
    float *h_uncertainty,
    float *v_uncertainty,
    radial_velocity_t *r_velocity,
    angular_velocity_t *a_transverse_velocity,
    angular_velocity_t *e_transverse_velocity
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
    velocity_estimate_t *result = velocity_estimate_create_internal (
        h_speed_copy,
        bearing_copy,
        v_speed_copy,
        v_direction,
        h_uncertainty_copy,
        v_uncertainty_copy,
        r_velocity,
        a_transverse_velocity,
        e_transverse_velocity
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

void velocity_estimate_free(velocity_estimate_t *velocity_estimate) {
    if(NULL == velocity_estimate){
        return ;
    }
    if(velocity_estimate->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "velocity_estimate_free");
        return ;
    }
    listEntry_t *listEntry;
    if (velocity_estimate->h_speed) {
        free(velocity_estimate->h_speed);
        velocity_estimate->h_speed = NULL;
    }
    if (velocity_estimate->bearing) {
        free(velocity_estimate->bearing);
        velocity_estimate->bearing = NULL;
    }
    if (velocity_estimate->v_speed) {
        free(velocity_estimate->v_speed);
        velocity_estimate->v_speed = NULL;
    }
    if (velocity_estimate->h_uncertainty) {
        free(velocity_estimate->h_uncertainty);
        velocity_estimate->h_uncertainty = NULL;
    }
    if (velocity_estimate->v_uncertainty) {
        free(velocity_estimate->v_uncertainty);
        velocity_estimate->v_uncertainty = NULL;
    }
    if (velocity_estimate->r_velocity) {
        radial_velocity_free(velocity_estimate->r_velocity);
        velocity_estimate->r_velocity = NULL;
    }
    if (velocity_estimate->a_transverse_velocity) {
        angular_velocity_free(velocity_estimate->a_transverse_velocity);
        velocity_estimate->a_transverse_velocity = NULL;
    }
    if (velocity_estimate->e_transverse_velocity) {
        angular_velocity_free(velocity_estimate->e_transverse_velocity);
        velocity_estimate->e_transverse_velocity = NULL;
    }
    free(velocity_estimate);
}

cJSON *velocity_estimate_convertToJSON(velocity_estimate_t *velocity_estimate) {
    cJSON *item = cJSON_CreateObject();

    // velocity_estimate->h_speed
    if (!velocity_estimate->h_speed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hSpeed", *velocity_estimate->h_speed) == NULL) {
    goto fail; //Numeric
    }


    // velocity_estimate->bearing
    if (!velocity_estimate->bearing) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bearing", *velocity_estimate->bearing) == NULL) {
    goto fail; //Numeric
    }


    // velocity_estimate->v_speed
    if (!velocity_estimate->v_speed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vSpeed", *velocity_estimate->v_speed) == NULL) {
    goto fail; //Numeric
    }


    // velocity_estimate->v_direction
    if (lmf_location_vertical_direction__NULL == velocity_estimate->v_direction) {
        goto fail;
    }
    cJSON *v_direction_local_JSON = vertical_direction_convertToJSON(velocity_estimate->v_direction);
    if(v_direction_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "vDirection", v_direction_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // velocity_estimate->h_uncertainty
    if (!velocity_estimate->h_uncertainty) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hUncertainty", *velocity_estimate->h_uncertainty) == NULL) {
    goto fail; //Numeric
    }


    // velocity_estimate->v_uncertainty
    if (!velocity_estimate->v_uncertainty) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vUncertainty", *velocity_estimate->v_uncertainty) == NULL) {
    goto fail; //Numeric
    }


    // velocity_estimate->r_velocity
    if(velocity_estimate->r_velocity) {
    cJSON *r_velocity_local_JSON = radial_velocity_convertToJSON(velocity_estimate->r_velocity);
    if(r_velocity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rVelocity", r_velocity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // velocity_estimate->a_transverse_velocity
    if(velocity_estimate->a_transverse_velocity) {
    cJSON *a_transverse_velocity_local_JSON = angular_velocity_convertToJSON(velocity_estimate->a_transverse_velocity);
    if(a_transverse_velocity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "aTransverseVelocity", a_transverse_velocity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // velocity_estimate->e_transverse_velocity
    if(velocity_estimate->e_transverse_velocity) {
    cJSON *e_transverse_velocity_local_JSON = angular_velocity_convertToJSON(velocity_estimate->e_transverse_velocity);
    if(e_transverse_velocity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "eTransverseVelocity", e_transverse_velocity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

velocity_estimate_t *velocity_estimate_parseFromJSON(cJSON *velocity_estimateJSON){

    velocity_estimate_t *velocity_estimate_local_var = NULL;

    // define the local variable for velocity_estimate->h_speed
    float *h_speed_local_var = NULL;

    // define the local variable for velocity_estimate->bearing
    int *bearing_local_var = NULL;

    // define the local variable for velocity_estimate->v_speed
    float *v_speed_local_var = NULL;

    // define the local variable for velocity_estimate->v_direction
    lmf_location_vertical_direction__e v_direction_local_nonprim = 0;

    // define the local variable for velocity_estimate->h_uncertainty
    float *h_uncertainty_local_var = NULL;

    // define the local variable for velocity_estimate->v_uncertainty
    float *v_uncertainty_local_var = NULL;

    // define the local variable for velocity_estimate->r_velocity
    radial_velocity_t *r_velocity_local_nonprim = NULL;

    // define the local variable for velocity_estimate->a_transverse_velocity
    angular_velocity_t *a_transverse_velocity_local_nonprim = NULL;

    // define the local variable for velocity_estimate->e_transverse_velocity
    angular_velocity_t *e_transverse_velocity_local_nonprim = NULL;

    // velocity_estimate->h_speed
    cJSON *h_speed = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "hSpeed");
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

    // velocity_estimate->bearing
    cJSON *bearing = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "bearing");
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

    // velocity_estimate->v_speed
    cJSON *v_speed = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "vSpeed");
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

    // velocity_estimate->v_direction
    cJSON *v_direction = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "vDirection");
    if (cJSON_IsNull(v_direction)) {
        v_direction = NULL;
    }
    if (!v_direction) {
        goto end;
    }

    
    v_direction_local_nonprim = vertical_direction_parseFromJSON(v_direction); //custom

    // velocity_estimate->h_uncertainty
    cJSON *h_uncertainty = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "hUncertainty");
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

    // velocity_estimate->v_uncertainty
    cJSON *v_uncertainty = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "vUncertainty");
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

    // velocity_estimate->r_velocity
    cJSON *r_velocity = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "rVelocity");
    if (cJSON_IsNull(r_velocity)) {
        r_velocity = NULL;
    }
    if (r_velocity) { 
    r_velocity_local_nonprim = radial_velocity_parseFromJSON(r_velocity); //nonprimitive
    }

    // velocity_estimate->a_transverse_velocity
    cJSON *a_transverse_velocity = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "aTransverseVelocity");
    if (cJSON_IsNull(a_transverse_velocity)) {
        a_transverse_velocity = NULL;
    }
    if (a_transverse_velocity) { 
    a_transverse_velocity_local_nonprim = angular_velocity_parseFromJSON(a_transverse_velocity); //nonprimitive
    }

    // velocity_estimate->e_transverse_velocity
    cJSON *e_transverse_velocity = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "eTransverseVelocity");
    if (cJSON_IsNull(e_transverse_velocity)) {
        e_transverse_velocity = NULL;
    }
    if (e_transverse_velocity) { 
    e_transverse_velocity_local_nonprim = angular_velocity_parseFromJSON(e_transverse_velocity); //nonprimitive
    }



    velocity_estimate_local_var = velocity_estimate_create_internal (
        h_speed_local_var,
        bearing_local_var,
        v_speed_local_var,
        v_direction_local_nonprim,
        h_uncertainty_local_var,
        v_uncertainty_local_var,
        r_velocity ? r_velocity_local_nonprim : NULL,
        a_transverse_velocity ? a_transverse_velocity_local_nonprim : NULL,
        e_transverse_velocity ? e_transverse_velocity_local_nonprim : NULL
        );

    if (!velocity_estimate_local_var) {
        goto end;
    }

    return velocity_estimate_local_var;
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
    if (r_velocity_local_nonprim) {
        radial_velocity_free(r_velocity_local_nonprim);
        r_velocity_local_nonprim = NULL;
    }
    if (a_transverse_velocity_local_nonprim) {
        angular_velocity_free(a_transverse_velocity_local_nonprim);
        a_transverse_velocity_local_nonprim = NULL;
    }
    if (e_transverse_velocity_local_nonprim) {
        angular_velocity_free(e_transverse_velocity_local_nonprim);
        e_transverse_velocity_local_nonprim = NULL;
    }
    return NULL;

}
