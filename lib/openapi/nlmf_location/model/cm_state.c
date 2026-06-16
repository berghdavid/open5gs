#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cm_state.h"



static cm_state_t *cm_state_create_internal(
    ) {
    cm_state_t *cm_state_local_var = malloc(sizeof(cm_state_t));
    if (!cm_state_local_var) {
        return NULL;
    }
    memset(cm_state_local_var, 0, sizeof(cm_state_t));
    cm_state_local_var->_library_owned = 1;
    return cm_state_local_var;
}

__attribute__((deprecated)) cm_state_t *cm_state_create(
    ) {
    cm_state_t *result = cm_state_create_internal (
        );
    if (!result) {
    }
    return result;
}

void cm_state_free(cm_state_t *cm_state) {
    if(NULL == cm_state){
        return ;
    }
    if(cm_state->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cm_state_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cm_state);
}

cJSON *cm_state_convertToJSON(cm_state_t *cm_state) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cm_state_t *cm_state_parseFromJSON(cJSON *cm_stateJSON){

    cm_state_t *cm_state_local_var = NULL;



    cm_state_local_var = cm_state_create_internal (
        );

    if (!cm_state_local_var) {
        goto end;
    }

    return cm_state_local_var;
end:
    return NULL;

}
