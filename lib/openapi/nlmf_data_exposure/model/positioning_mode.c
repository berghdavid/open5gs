#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_mode.h"



static positioning_mode_t *positioning_mode_create_internal(
    ) {
    positioning_mode_t *positioning_mode_local_var = malloc(sizeof(positioning_mode_t));
    if (!positioning_mode_local_var) {
        return NULL;
    }
    memset(positioning_mode_local_var, 0, sizeof(positioning_mode_t));
    positioning_mode_local_var->_library_owned = 1;
    return positioning_mode_local_var;
}

__attribute__((deprecated)) positioning_mode_t *positioning_mode_create(
    ) {
    positioning_mode_t *result = positioning_mode_create_internal (
        );
    if (!result) {
    }
    return result;
}

void positioning_mode_free(positioning_mode_t *positioning_mode) {
    if(NULL == positioning_mode){
        return ;
    }
    if(positioning_mode->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "positioning_mode_free");
        return ;
    }
    listEntry_t *listEntry;
    free(positioning_mode);
}

cJSON *positioning_mode_convertToJSON(positioning_mode_t *positioning_mode) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

positioning_mode_t *positioning_mode_parseFromJSON(cJSON *positioning_modeJSON){

    positioning_mode_t *positioning_mode_local_var = NULL;



    positioning_mode_local_var = positioning_mode_create_internal (
        );

    if (!positioning_mode_local_var) {
        goto end;
    }

    return positioning_mode_local_var;
end:
    return NULL;

}
