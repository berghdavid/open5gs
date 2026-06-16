#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "integrity_computing_entity.h"



static integrity_computing_entity_t *integrity_computing_entity_create_internal(
    ) {
    integrity_computing_entity_t *integrity_computing_entity_local_var = malloc(sizeof(integrity_computing_entity_t));
    if (!integrity_computing_entity_local_var) {
        return NULL;
    }
    memset(integrity_computing_entity_local_var, 0, sizeof(integrity_computing_entity_t));
    integrity_computing_entity_local_var->_library_owned = 1;
    return integrity_computing_entity_local_var;
}

__attribute__((deprecated)) integrity_computing_entity_t *integrity_computing_entity_create(
    ) {
    integrity_computing_entity_t *result = integrity_computing_entity_create_internal (
        );
    if (!result) {
    }
    return result;
}

void integrity_computing_entity_free(integrity_computing_entity_t *integrity_computing_entity) {
    if(NULL == integrity_computing_entity){
        return ;
    }
    if(integrity_computing_entity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "integrity_computing_entity_free");
        return ;
    }
    listEntry_t *listEntry;
    free(integrity_computing_entity);
}

cJSON *integrity_computing_entity_convertToJSON(integrity_computing_entity_t *integrity_computing_entity) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

integrity_computing_entity_t *integrity_computing_entity_parseFromJSON(cJSON *integrity_computing_entityJSON){

    integrity_computing_entity_t *integrity_computing_entity_local_var = NULL;



    integrity_computing_entity_local_var = integrity_computing_entity_create_internal (
        );

    if (!integrity_computing_entity_local_var) {
        goto end;
    }

    return integrity_computing_entity_local_var;
end:
    return NULL;

}
