#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "relative_velocity_with_uncertainty.h"



static relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty_create_internal(
    radial_velocity_t *r_velocity,
    angular_velocity_t *a_transverse_velocity,
    angular_velocity_t *e_transverse_velocity
    ) {
    relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty_local_var = malloc(sizeof(relative_velocity_with_uncertainty_t));
    if (!relative_velocity_with_uncertainty_local_var) {
        return NULL;
    }
    memset(relative_velocity_with_uncertainty_local_var, 0, sizeof(relative_velocity_with_uncertainty_t));
    relative_velocity_with_uncertainty_local_var->_library_owned = 1;
    relative_velocity_with_uncertainty_local_var->r_velocity = r_velocity;
    relative_velocity_with_uncertainty_local_var->a_transverse_velocity = a_transverse_velocity;
    relative_velocity_with_uncertainty_local_var->e_transverse_velocity = e_transverse_velocity;
    return relative_velocity_with_uncertainty_local_var;
}

__attribute__((deprecated)) relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty_create(
    radial_velocity_t *r_velocity,
    angular_velocity_t *a_transverse_velocity,
    angular_velocity_t *e_transverse_velocity
    ) {
    relative_velocity_with_uncertainty_t *result = relative_velocity_with_uncertainty_create_internal (
        r_velocity,
        a_transverse_velocity,
        e_transverse_velocity
        );
    if (!result) {
    }
    return result;
}

void relative_velocity_with_uncertainty_free(relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty) {
    if(NULL == relative_velocity_with_uncertainty){
        return ;
    }
    if(relative_velocity_with_uncertainty->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "relative_velocity_with_uncertainty_free");
        return ;
    }
    listEntry_t *listEntry;
    if (relative_velocity_with_uncertainty->r_velocity) {
        radial_velocity_free(relative_velocity_with_uncertainty->r_velocity);
        relative_velocity_with_uncertainty->r_velocity = NULL;
    }
    if (relative_velocity_with_uncertainty->a_transverse_velocity) {
        angular_velocity_free(relative_velocity_with_uncertainty->a_transverse_velocity);
        relative_velocity_with_uncertainty->a_transverse_velocity = NULL;
    }
    if (relative_velocity_with_uncertainty->e_transverse_velocity) {
        angular_velocity_free(relative_velocity_with_uncertainty->e_transverse_velocity);
        relative_velocity_with_uncertainty->e_transverse_velocity = NULL;
    }
    free(relative_velocity_with_uncertainty);
}

cJSON *relative_velocity_with_uncertainty_convertToJSON(relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty) {
    cJSON *item = cJSON_CreateObject();

    // relative_velocity_with_uncertainty->r_velocity
    if(relative_velocity_with_uncertainty->r_velocity) {
    cJSON *r_velocity_local_JSON = radial_velocity_convertToJSON(relative_velocity_with_uncertainty->r_velocity);
    if(r_velocity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rVelocity", r_velocity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // relative_velocity_with_uncertainty->a_transverse_velocity
    if(relative_velocity_with_uncertainty->a_transverse_velocity) {
    cJSON *a_transverse_velocity_local_JSON = angular_velocity_convertToJSON(relative_velocity_with_uncertainty->a_transverse_velocity);
    if(a_transverse_velocity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "aTransverseVelocity", a_transverse_velocity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // relative_velocity_with_uncertainty->e_transverse_velocity
    if(relative_velocity_with_uncertainty->e_transverse_velocity) {
    cJSON *e_transverse_velocity_local_JSON = angular_velocity_convertToJSON(relative_velocity_with_uncertainty->e_transverse_velocity);
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

relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty_parseFromJSON(cJSON *relative_velocity_with_uncertaintyJSON){

    relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty_local_var = NULL;

    // define the local variable for relative_velocity_with_uncertainty->r_velocity
    radial_velocity_t *r_velocity_local_nonprim = NULL;

    // define the local variable for relative_velocity_with_uncertainty->a_transverse_velocity
    angular_velocity_t *a_transverse_velocity_local_nonprim = NULL;

    // define the local variable for relative_velocity_with_uncertainty->e_transverse_velocity
    angular_velocity_t *e_transverse_velocity_local_nonprim = NULL;

    // relative_velocity_with_uncertainty->r_velocity
    cJSON *r_velocity = cJSON_GetObjectItemCaseSensitive(relative_velocity_with_uncertaintyJSON, "rVelocity");
    if (cJSON_IsNull(r_velocity)) {
        r_velocity = NULL;
    }
    if (r_velocity) { 
    r_velocity_local_nonprim = radial_velocity_parseFromJSON(r_velocity); //nonprimitive
    }

    // relative_velocity_with_uncertainty->a_transverse_velocity
    cJSON *a_transverse_velocity = cJSON_GetObjectItemCaseSensitive(relative_velocity_with_uncertaintyJSON, "aTransverseVelocity");
    if (cJSON_IsNull(a_transverse_velocity)) {
        a_transverse_velocity = NULL;
    }
    if (a_transverse_velocity) { 
    a_transverse_velocity_local_nonprim = angular_velocity_parseFromJSON(a_transverse_velocity); //nonprimitive
    }

    // relative_velocity_with_uncertainty->e_transverse_velocity
    cJSON *e_transverse_velocity = cJSON_GetObjectItemCaseSensitive(relative_velocity_with_uncertaintyJSON, "eTransverseVelocity");
    if (cJSON_IsNull(e_transverse_velocity)) {
        e_transverse_velocity = NULL;
    }
    if (e_transverse_velocity) { 
    e_transverse_velocity_local_nonprim = angular_velocity_parseFromJSON(e_transverse_velocity); //nonprimitive
    }



    relative_velocity_with_uncertainty_local_var = relative_velocity_with_uncertainty_create_internal (
        r_velocity ? r_velocity_local_nonprim : NULL,
        a_transverse_velocity ? a_transverse_velocity_local_nonprim : NULL,
        e_transverse_velocity ? e_transverse_velocity_local_nonprim : NULL
        );

    if (!relative_velocity_with_uncertainty_local_var) {
        goto end;
    }

    return relative_velocity_with_uncertainty_local_var;
end:
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
