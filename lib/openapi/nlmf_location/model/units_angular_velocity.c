#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "units_angular_velocity.h"



static units_angular_velocity_t *units_angular_velocity_create_internal(
    ) {
    units_angular_velocity_t *units_angular_velocity_local_var = malloc(sizeof(units_angular_velocity_t));
    if (!units_angular_velocity_local_var) {
        return NULL;
    }
    memset(units_angular_velocity_local_var, 0, sizeof(units_angular_velocity_t));
    units_angular_velocity_local_var->_library_owned = 1;
    return units_angular_velocity_local_var;
}

__attribute__((deprecated)) units_angular_velocity_t *units_angular_velocity_create(
    ) {
    units_angular_velocity_t *result = units_angular_velocity_create_internal (
        );
    if (!result) {
    }
    return result;
}

void units_angular_velocity_free(units_angular_velocity_t *units_angular_velocity) {
    if(NULL == units_angular_velocity){
        return ;
    }
    if(units_angular_velocity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "units_angular_velocity_free");
        return ;
    }
    listEntry_t *listEntry;
    free(units_angular_velocity);
}

cJSON *units_angular_velocity_convertToJSON(units_angular_velocity_t *units_angular_velocity) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

units_angular_velocity_t *units_angular_velocity_parseFromJSON(cJSON *units_angular_velocityJSON){

    units_angular_velocity_t *units_angular_velocity_local_var = NULL;



    units_angular_velocity_local_var = units_angular_velocity_create_internal (
        );

    if (!units_angular_velocity_local_var) {
        goto end;
    }

    return units_angular_velocity_local_var;
end:
    return NULL;

}
