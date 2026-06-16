#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_connectivity_state.h"



static ue_connectivity_state_t *ue_connectivity_state_create_internal(
    lmf_location_access_type__e access_type,
    cm_state_t *connectivitystate
    ) {
    ue_connectivity_state_t *ue_connectivity_state_local_var = malloc(sizeof(ue_connectivity_state_t));
    if (!ue_connectivity_state_local_var) {
        return NULL;
    }
    memset(ue_connectivity_state_local_var, 0, sizeof(ue_connectivity_state_t));
    ue_connectivity_state_local_var->_library_owned = 1;
    ue_connectivity_state_local_var->access_type = access_type;
    ue_connectivity_state_local_var->connectivitystate = connectivitystate;
    return ue_connectivity_state_local_var;
}

__attribute__((deprecated)) ue_connectivity_state_t *ue_connectivity_state_create(
    lmf_location_access_type__e access_type,
    cm_state_t *connectivitystate
    ) {
    ue_connectivity_state_t *result = ue_connectivity_state_create_internal (
        access_type,
        connectivitystate
        );
    if (!result) {
    }
    return result;
}

void ue_connectivity_state_free(ue_connectivity_state_t *ue_connectivity_state) {
    if(NULL == ue_connectivity_state){
        return ;
    }
    if(ue_connectivity_state->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ue_connectivity_state_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ue_connectivity_state->connectivitystate) {
        cm_state_free(ue_connectivity_state->connectivitystate);
        ue_connectivity_state->connectivitystate = NULL;
    }
    free(ue_connectivity_state);
}

cJSON *ue_connectivity_state_convertToJSON(ue_connectivity_state_t *ue_connectivity_state) {
    cJSON *item = cJSON_CreateObject();

    // ue_connectivity_state->access_type
    if (lmf_location_access_type__NULL == ue_connectivity_state->access_type) {
        goto fail;
    }
    cJSON *access_type_local_JSON = access_type_convertToJSON(ue_connectivity_state->access_type);
    if(access_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "accessType", access_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // ue_connectivity_state->connectivitystate
    if(ue_connectivity_state->connectivitystate) {
    cJSON *connectivitystate_local_JSON = cm_state_convertToJSON(ue_connectivity_state->connectivitystate);
    if(connectivitystate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "connectivitystate", connectivitystate_local_JSON);
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

ue_connectivity_state_t *ue_connectivity_state_parseFromJSON(cJSON *ue_connectivity_stateJSON){

    ue_connectivity_state_t *ue_connectivity_state_local_var = NULL;

    // define the local variable for ue_connectivity_state->access_type
    lmf_location_access_type__e access_type_local_nonprim = 0;

    // define the local variable for ue_connectivity_state->connectivitystate
    cm_state_t *connectivitystate_local_nonprim = NULL;

    // ue_connectivity_state->access_type
    cJSON *access_type = cJSON_GetObjectItemCaseSensitive(ue_connectivity_stateJSON, "accessType");
    if (cJSON_IsNull(access_type)) {
        access_type = NULL;
    }
    if (!access_type) {
        goto end;
    }

    
    access_type_local_nonprim = access_type_parseFromJSON(access_type); //custom

    // ue_connectivity_state->connectivitystate
    cJSON *connectivitystate = cJSON_GetObjectItemCaseSensitive(ue_connectivity_stateJSON, "connectivitystate");
    if (cJSON_IsNull(connectivitystate)) {
        connectivitystate = NULL;
    }
    if (connectivitystate) { 
    connectivitystate_local_nonprim = cm_state_parseFromJSON(connectivitystate); //nonprimitive
    }



    ue_connectivity_state_local_var = ue_connectivity_state_create_internal (
        access_type_local_nonprim,
        connectivitystate ? connectivitystate_local_nonprim : NULL
        );

    if (!ue_connectivity_state_local_var) {
        goto end;
    }

    return ue_connectivity_state_local_var;
end:
    if (access_type_local_nonprim) {
        access_type_local_nonprim = 0;
    }
    if (connectivitystate_local_nonprim) {
        cm_state_free(connectivitystate_local_nonprim);
        connectivitystate_local_nonprim = NULL;
    }
    return NULL;

}
