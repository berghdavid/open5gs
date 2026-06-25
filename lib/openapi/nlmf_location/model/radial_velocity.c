#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "radial_velocity.h"



static radial_velocity_t *radial_velocity_create_internal(
    units_linear_velocity_t *units_radial_velocity,
    int *radial_velocity,
    int *r_velocity_uncertainty
    ) {
    radial_velocity_t *radial_velocity_local_var = malloc(sizeof(radial_velocity_t));
    if (!radial_velocity_local_var) {
        return NULL;
    }
    memset(radial_velocity_local_var, 0, sizeof(radial_velocity_t));
    radial_velocity_local_var->_library_owned = 1;
    radial_velocity_local_var->units_radial_velocity = units_radial_velocity;
    radial_velocity_local_var->radial_velocity = radial_velocity;
    radial_velocity_local_var->r_velocity_uncertainty = r_velocity_uncertainty;
    return radial_velocity_local_var;
}

__attribute__((deprecated)) radial_velocity_t *radial_velocity_create(
    units_linear_velocity_t *units_radial_velocity,
    int *radial_velocity,
    int *r_velocity_uncertainty
    ) {
    int *radial_velocity_copy = NULL;
    if (radial_velocity) {
        radial_velocity_copy = malloc(sizeof(int));
        if (radial_velocity_copy) *radial_velocity_copy = *radial_velocity;
    }
    int *r_velocity_uncertainty_copy = NULL;
    if (r_velocity_uncertainty) {
        r_velocity_uncertainty_copy = malloc(sizeof(int));
        if (r_velocity_uncertainty_copy) *r_velocity_uncertainty_copy = *r_velocity_uncertainty;
    }
    radial_velocity_t *result = radial_velocity_create_internal (
        units_radial_velocity,
        radial_velocity_copy,
        r_velocity_uncertainty_copy
        );
    if (!result) {
        free(radial_velocity_copy);
        free(r_velocity_uncertainty_copy);
    }
    return result;
}

void radial_velocity_free(radial_velocity_t *radial_velocity) {
    if(NULL == radial_velocity){
        return ;
    }
    if(radial_velocity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "radial_velocity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (radial_velocity->units_radial_velocity) {
        units_linear_velocity_free(radial_velocity->units_radial_velocity);
        radial_velocity->units_radial_velocity = NULL;
    }
    if (radial_velocity->radial_velocity) {
        free(radial_velocity->radial_velocity);
        radial_velocity->radial_velocity = NULL;
    }
    if (radial_velocity->r_velocity_uncertainty) {
        free(radial_velocity->r_velocity_uncertainty);
        radial_velocity->r_velocity_uncertainty = NULL;
    }
    free(radial_velocity);
}

cJSON *radial_velocity_convertToJSON(radial_velocity_t *radial_velocity) {
    cJSON *item = cJSON_CreateObject();

    // radial_velocity->units_radial_velocity
    if (!radial_velocity->units_radial_velocity) {
        goto fail;
    }
    cJSON *units_radial_velocity_local_JSON = units_linear_velocity_convertToJSON(radial_velocity->units_radial_velocity);
    if(units_radial_velocity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "unitsRadialVelocity", units_radial_velocity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // radial_velocity->radial_velocity
    if (!radial_velocity->radial_velocity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "radialVelocity", *radial_velocity->radial_velocity) == NULL) {
    goto fail; //Numeric
    }


    // radial_velocity->r_velocity_uncertainty
    if (!radial_velocity->r_velocity_uncertainty) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "rVelocityUncertainty", *radial_velocity->r_velocity_uncertainty) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

radial_velocity_t *radial_velocity_parseFromJSON(cJSON *radial_velocityJSON){

    radial_velocity_t *radial_velocity = NULL;

    // define the local variable for radial_velocity->units_radial_velocity
    units_linear_velocity_t *units_radial_velocity_local_nonprim = NULL;

    // define the local variable for radial_velocity->radial_velocity
    int *radial_velocity_local_var = NULL;

    // define the local variable for radial_velocity->r_velocity_uncertainty
    int *r_velocity_uncertainty_local_var = NULL;

    // radial_velocity->units_radial_velocity
    cJSON *units_radial_velocity = cJSON_GetObjectItemCaseSensitive(radial_velocityJSON, "unitsRadialVelocity");
    if (cJSON_IsNull(units_radial_velocity)) {
        units_radial_velocity = NULL;
    }
    if (!units_radial_velocity) {
        goto end;
    }

    
    units_radial_velocity_local_nonprim = units_linear_velocity_parseFromJSON(units_radial_velocity); //nonprimitive

    // radial_velocity->radial_velocity
    cJSON *radial_velocity_item_cjson = cJSON_GetObjectItemCaseSensitive(radial_velocityJSON, "radialVelocity");
    if (cJSON_IsNull(radial_velocity_item_cjson)) {
        radial_velocity_item_cjson = NULL;
    }
    if (!radial_velocity_item_cjson) {
        goto end;
    }

    
    if(!cJSON_IsNumber(radial_velocity_item_cjson))
    {
    goto end; //Numeric
    }
    radial_velocity_local_var = malloc(sizeof(int));
    if(!radial_velocity_local_var)
    {
        goto end;
    }
    *radial_velocity_local_var = radial_velocity_item_cjson->valueint;

    // radial_velocity->r_velocity_uncertainty
    cJSON *r_velocity_uncertainty = cJSON_GetObjectItemCaseSensitive(radial_velocityJSON, "rVelocityUncertainty");
    if (cJSON_IsNull(r_velocity_uncertainty)) {
        r_velocity_uncertainty = NULL;
    }
    if (!r_velocity_uncertainty) {
        goto end;
    }

    
    if(!cJSON_IsNumber(r_velocity_uncertainty))
    {
    goto end; //Numeric
    }
    r_velocity_uncertainty_local_var = malloc(sizeof(int));
    if(!r_velocity_uncertainty_local_var)
    {
        goto end;
    }
    *r_velocity_uncertainty_local_var = r_velocity_uncertainty->valuedouble;



    radial_velocity = radial_velocity_create_internal (
        units_radial_velocity_local_nonprim,
        radial_velocity_local_var,
        r_velocity_uncertainty_local_var
        );

    if (!radial_velocity) {
        goto end;
    }

    return radial_velocity;
end:
    if (radial_velocity_item_cjson) {
        cJSON_Delete(radial_velocity_item_cjson);
        radial_velocity_item_cjson = NULL;
    }
    if (units_radial_velocity_local_nonprim) {
        units_linear_velocity_free(units_radial_velocity_local_nonprim);
        units_radial_velocity_local_nonprim = NULL;
    }
    if (radial_velocity_local_var) {
        free(radial_velocity_local_var);
        radial_velocity_local_var = NULL;
    }
    if (r_velocity_uncertainty_local_var) {
        free(r_velocity_uncertainty_local_var);
        r_velocity_uncertainty_local_var = NULL;
    }
    return NULL;

}
