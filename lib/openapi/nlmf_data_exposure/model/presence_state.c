#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "presence_state.h"



static presence_state_t *presence_state_create_internal(
    ) {
    presence_state_t *presence_state_local_var = malloc(sizeof(presence_state_t));
    if (!presence_state_local_var) {
        return NULL;
    }
    memset(presence_state_local_var, 0, sizeof(presence_state_t));
    presence_state_local_var->_library_owned = 1;
    return presence_state_local_var;
}

__attribute__((deprecated)) presence_state_t *presence_state_create(
    ) {
    presence_state_t *result = presence_state_create_internal (
        );
    if (!result) {
    }
    return result;
}

void presence_state_free(presence_state_t *presence_state) {
    if(NULL == presence_state){
        return ;
    }
    if(presence_state->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "presence_state_free");
        return ;
    }
    listEntry_t *listEntry;
    free(presence_state);
}

cJSON *presence_state_convertToJSON(presence_state_t *presence_state) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

presence_state_t *presence_state_parseFromJSON(cJSON *presence_stateJSON){

    presence_state_t *presence_state_local_var = NULL;



    presence_state_local_var = presence_state_create_internal (
        );

    if (!presence_state_local_var) {
        goto end;
    }

    return presence_state_local_var;
end:
    return NULL;

}
