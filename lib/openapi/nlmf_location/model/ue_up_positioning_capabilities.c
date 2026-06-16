#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_up_positioning_capabilities.h"



static ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_create_internal(
    ) {
    ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_local_var = malloc(sizeof(ue_up_positioning_capabilities_t));
    if (!ue_up_positioning_capabilities_local_var) {
        return NULL;
    }
    memset(ue_up_positioning_capabilities_local_var, 0, sizeof(ue_up_positioning_capabilities_t));
    ue_up_positioning_capabilities_local_var->_library_owned = 1;
    return ue_up_positioning_capabilities_local_var;
}

__attribute__((deprecated)) ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_create(
    ) {
    ue_up_positioning_capabilities_t *result = ue_up_positioning_capabilities_create_internal (
        );
    if (!result) {
    }
    return result;
}

void ue_up_positioning_capabilities_free(ue_up_positioning_capabilities_t *ue_up_positioning_capabilities) {
    if(NULL == ue_up_positioning_capabilities){
        return ;
    }
    if(ue_up_positioning_capabilities->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ue_up_positioning_capabilities_free");
        return ;
    }
    listEntry_t *listEntry;
    free(ue_up_positioning_capabilities);
}

cJSON *ue_up_positioning_capabilities_convertToJSON(ue_up_positioning_capabilities_t *ue_up_positioning_capabilities) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_parseFromJSON(cJSON *ue_up_positioning_capabilitiesJSON){

    ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_local_var = NULL;



    ue_up_positioning_capabilities_local_var = ue_up_positioning_capabilities_create_internal (
        );

    if (!ue_up_positioning_capabilities_local_var) {
        goto end;
    }

    return ue_up_positioning_capabilities_local_var;
end:
    return NULL;

}
