#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_operation.h"



static patch_operation_t *patch_operation_create_internal(
    ) {
    patch_operation_t *patch_operation_local_var = malloc(sizeof(patch_operation_t));
    if (!patch_operation_local_var) {
        return NULL;
    }
    memset(patch_operation_local_var, 0, sizeof(patch_operation_t));
    patch_operation_local_var->_library_owned = 1;
    return patch_operation_local_var;
}

__attribute__((deprecated)) patch_operation_t *patch_operation_create(
    ) {
    patch_operation_t *result = patch_operation_create_internal (
        );
    if (!result) {
    }
    return result;
}

void patch_operation_free(patch_operation_t *patch_operation) {
    if(NULL == patch_operation){
        return ;
    }
    if(patch_operation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_operation_free");
        return ;
    }
    listEntry_t *listEntry;
    free(patch_operation);
}

cJSON *patch_operation_convertToJSON(patch_operation_t *patch_operation) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_operation_t *patch_operation_parseFromJSON(cJSON *patch_operationJSON){

    patch_operation_t *patch_operation_local_var = NULL;



    patch_operation_local_var = patch_operation_create_internal (
        );

    if (!patch_operation_local_var) {
        goto end;
    }

    return patch_operation_local_var;
end:
    return NULL;

}
