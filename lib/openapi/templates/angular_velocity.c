#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "angular_velocity.h"



static angular_velocity_t *angular_velocity_create_internal(
    units_angular_velocity_t *units_angular_velocity,
    int *angular_velocity,
    int *a_velocity_uncertainty
    ) {
    angular_velocity_t *angular_velocity_local_var = malloc(sizeof(angular_velocity_t));
    if (!angular_velocity_local_var) {
        return NULL;
    }
    memset(angular_velocity_local_var, 0, sizeof(angular_velocity_t));
    angular_velocity_local_var->_library_owned = 1;
    angular_velocity_local_var->units_angular_velocity = units_angular_velocity;
    angular_velocity_local_var->angular_velocity = angular_velocity;
    angular_velocity_local_var->a_velocity_uncertainty = a_velocity_uncertainty;
    return angular_velocity_local_var;
}

__attribute__((deprecated)) angular_velocity_t *angular_velocity_create(
    units_angular_velocity_t *units_angular_velocity,
    int *angular_velocity,
    int *a_velocity_uncertainty
    ) {
    int *angular_velocity_copy = NULL;
    if (angular_velocity) {
        angular_velocity_copy = malloc(sizeof(int));
        if (angular_velocity_copy) *angular_velocity_copy = *angular_velocity;
    }
    int *a_velocity_uncertainty_copy = NULL;
    if (a_velocity_uncertainty) {
        a_velocity_uncertainty_copy = malloc(sizeof(int));
        if (a_velocity_uncertainty_copy) *a_velocity_uncertainty_copy = *a_velocity_uncertainty;
    }
    angular_velocity_t *result = angular_velocity_create_internal (
        units_angular_velocity,
        angular_velocity_copy,
        a_velocity_uncertainty_copy
        );
    if (!result) {
        free(angular_velocity_copy);
        free(a_velocity_uncertainty_copy);
    }
    return result;
}

void angular_velocity_free(angular_velocity_t *angular_velocity) {
    if(NULL == angular_velocity){
        return ;
    }
    if(angular_velocity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "angular_velocity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (angular_velocity->units_angular_velocity) {
        units_angular_velocity_free(angular_velocity->units_angular_velocity);
        angular_velocity->units_angular_velocity = NULL;
    }
    if (angular_velocity->angular_velocity) {
        free(angular_velocity->angular_velocity);
        angular_velocity->angular_velocity = NULL;
    }
    if (angular_velocity->a_velocity_uncertainty) {
        free(angular_velocity->a_velocity_uncertainty);
        angular_velocity->a_velocity_uncertainty = NULL;
    }
    free(angular_velocity);
}

cJSON *angular_velocity_convertToJSON(angular_velocity_t *angular_velocity) {
    cJSON *item = cJSON_CreateObject();

    // angular_velocity->units_angular_velocity
    if (!angular_velocity->units_angular_velocity) {
        goto fail;
    }
    cJSON *units_angular_velocity_local_JSON = units_angular_velocity_convertToJSON(angular_velocity->units_angular_velocity);
    if(units_angular_velocity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "unitsAngularVelocity", units_angular_velocity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // angular_velocity->angular_velocity
    if (!angular_velocity->angular_velocity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "angularVelocity", *angular_velocity->angular_velocity) == NULL) {
    goto fail; //Numeric
    }


    // angular_velocity->a_velocity_uncertainty
    if (!angular_velocity->a_velocity_uncertainty) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "aVelocityUncertainty", *angular_velocity->a_velocity_uncertainty) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

angular_velocity_t *angular_velocity_parseFromJSON(cJSON *angular_velocityJSON){

    angular_velocity_t *angular_velocity_local_var = NULL;

    // define the local variable for angular_velocity->units_angular_velocity
    units_angular_velocity_t *units_angular_velocity_local_nonprim = NULL;

    // define the local variable for angular_velocity->angular_velocity
    int *angular_velocity_local_var_int = NULL;

    // define the local variable for angular_velocity->a_velocity_uncertainty
    int *a_velocity_uncertainty_local_var = NULL;

    // angular_velocity->units_angular_velocity
    cJSON *units_angular_velocity = cJSON_GetObjectItemCaseSensitive(angular_velocityJSON, "unitsAngularVelocity");
    if (cJSON_IsNull(units_angular_velocity)) {
        units_angular_velocity = NULL;
    }
    if (!units_angular_velocity) {
        goto end;
    }

    
    units_angular_velocity_local_nonprim = units_angular_velocity_parseFromJSON(units_angular_velocity); //nonprimitive

    // angular_velocity->angular_velocity
    cJSON *angular_velocity = cJSON_GetObjectItemCaseSensitive(angular_velocityJSON, "angularVelocity");
    if (cJSON_IsNull(angular_velocity)) {
        angular_velocity = NULL;
    }
    if (!angular_velocity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(angular_velocity))
    {
        goto end; //Numeric
    }
    angular_velocity_local_var_int = malloc(sizeof(int));
    if(!angular_velocity_local_var_int)
    {
        goto end;
    }
    *angular_velocity_local_var_int = angular_velocity->valuedouble;

    // angular_velocity->a_velocity_uncertainty
    cJSON *a_velocity_uncertainty = cJSON_GetObjectItemCaseSensitive(angular_velocityJSON, "aVelocityUncertainty");
    if (cJSON_IsNull(a_velocity_uncertainty)) {
        a_velocity_uncertainty = NULL;
    }
    if (!a_velocity_uncertainty) {
        goto end;
    }

    
    if(!cJSON_IsNumber(a_velocity_uncertainty))
    {
    goto end; //Numeric
    }
    a_velocity_uncertainty_local_var = malloc(sizeof(int));
    if(!a_velocity_uncertainty_local_var)
    {
        goto end;
    }
    *a_velocity_uncertainty_local_var = a_velocity_uncertainty->valuedouble;



    angular_velocity_local_var = angular_velocity_create_internal (
        units_angular_velocity_local_nonprim,
        angular_velocity_local_var_int,
        a_velocity_uncertainty_local_var
        );

    if (!angular_velocity_local_var) {
        goto end;
    }

    return angular_velocity_local_var;
end:
    if (units_angular_velocity_local_nonprim) {
        units_angular_velocity_free(units_angular_velocity_local_nonprim);
        units_angular_velocity_local_nonprim = NULL;
    }
    if (angular_velocity_local_var_int) {
        free(angular_velocity_local_var_int);
        angular_velocity_local_var_int = NULL;
    }
    if (a_velocity_uncertainty_local_var) {
        free(a_velocity_uncertainty_local_var);
        a_velocity_uncertainty_local_var = NULL;
    }
    return NULL;

}
