#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sl_positioning_capability.h"



static sl_positioning_capability_t *sl_positioning_capability_create_internal(
    ) {
    sl_positioning_capability_t *sl_positioning_capability_local_var = malloc(sizeof(sl_positioning_capability_t));
    if (!sl_positioning_capability_local_var) {
        return NULL;
    }
    memset(sl_positioning_capability_local_var, 0, sizeof(sl_positioning_capability_t));
    sl_positioning_capability_local_var->_library_owned = 1;
    return sl_positioning_capability_local_var;
}

__attribute__((deprecated)) sl_positioning_capability_t *sl_positioning_capability_create(
    ) {
    sl_positioning_capability_t *result = sl_positioning_capability_create_internal (
        );
    if (!result) {
    }
    return result;
}

void sl_positioning_capability_free(sl_positioning_capability_t *sl_positioning_capability) {
    if(NULL == sl_positioning_capability){
        return ;
    }
    if(sl_positioning_capability->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sl_positioning_capability_free");
        return ;
    }
    listEntry_t *listEntry;
    free(sl_positioning_capability);
}

cJSON *sl_positioning_capability_convertToJSON(sl_positioning_capability_t *sl_positioning_capability) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sl_positioning_capability_t *sl_positioning_capability_parseFromJSON(cJSON *sl_positioning_capabilityJSON){

    sl_positioning_capability_t *sl_positioning_capability_local_var = NULL;



    sl_positioning_capability_local_var = sl_positioning_capability_create_internal (
        );

    if (!sl_positioning_capability_local_var) {
        goto end;
    }

    return sl_positioning_capability_local_var;
end:
    return NULL;

}
