#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "units_linear_velocity.h"



static units_linear_velocity_t *units_linear_velocity_create_internal(
    ) {
    units_linear_velocity_t *units_linear_velocity_local_var = malloc(sizeof(units_linear_velocity_t));
    if (!units_linear_velocity_local_var) {
        return NULL;
    }
    memset(units_linear_velocity_local_var, 0, sizeof(units_linear_velocity_t));
    units_linear_velocity_local_var->_library_owned = 1;
    return units_linear_velocity_local_var;
}

__attribute__((deprecated)) units_linear_velocity_t *units_linear_velocity_create(
    ) {
    units_linear_velocity_t *result = units_linear_velocity_create_internal (
        );
    if (!result) {
    }
    return result;
}

void units_linear_velocity_free(units_linear_velocity_t *units_linear_velocity) {
    if(NULL == units_linear_velocity){
        return ;
    }
    if(units_linear_velocity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "units_linear_velocity_free");
        return ;
    }
    listEntry_t *listEntry;
    free(units_linear_velocity);
}

cJSON *units_linear_velocity_convertToJSON(units_linear_velocity_t *units_linear_velocity) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

units_linear_velocity_t *units_linear_velocity_parseFromJSON(cJSON *units_linear_velocityJSON){

    units_linear_velocity_t *units_linear_velocity_local_var = NULL;



    units_linear_velocity_local_var = units_linear_velocity_create_internal (
        );

    if (!units_linear_velocity_local_var) {
        goto end;
    }

    return units_linear_velocity_local_var;
end:
    return NULL;

}
