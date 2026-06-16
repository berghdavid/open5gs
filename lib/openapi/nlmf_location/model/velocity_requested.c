#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "velocity_requested.h"



static velocity_requested_t *velocity_requested_create_internal(
    ) {
    velocity_requested_t *velocity_requested_local_var = malloc(sizeof(velocity_requested_t));
    if (!velocity_requested_local_var) {
        return NULL;
    }
    memset(velocity_requested_local_var, 0, sizeof(velocity_requested_t));
    velocity_requested_local_var->_library_owned = 1;
    return velocity_requested_local_var;
}

__attribute__((deprecated)) velocity_requested_t *velocity_requested_create(
    ) {
    velocity_requested_t *result = velocity_requested_create_internal (
        );
    if (!result) {
    }
    return result;
}

void velocity_requested_free(velocity_requested_t *velocity_requested) {
    if(NULL == velocity_requested){
        return ;
    }
    if(velocity_requested->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "velocity_requested_free");
        return ;
    }
    listEntry_t *listEntry;
    free(velocity_requested);
}

cJSON *velocity_requested_convertToJSON(velocity_requested_t *velocity_requested) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

velocity_requested_t *velocity_requested_parseFromJSON(cJSON *velocity_requestedJSON){

    velocity_requested_t *velocity_requested_local_var = NULL;



    velocity_requested_local_var = velocity_requested_create_internal (
        );

    if (!velocity_requested_local_var) {
        goto end;
    }

    return velocity_requested_local_var;
end:
    return NULL;

}
