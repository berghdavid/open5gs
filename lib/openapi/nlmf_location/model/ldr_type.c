#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ldr_type.h"



static ldr_type_t *ldr_type_create_internal(
    ) {
    ldr_type_t *ldr_type_local_var = malloc(sizeof(ldr_type_t));
    if (!ldr_type_local_var) {
        return NULL;
    }
    memset(ldr_type_local_var, 0, sizeof(ldr_type_t));
    ldr_type_local_var->_library_owned = 1;
    return ldr_type_local_var;
}

__attribute__((deprecated)) ldr_type_t *ldr_type_create(
    ) {
    ldr_type_t *result = ldr_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void ldr_type_free(ldr_type_t *ldr_type) {
    if(NULL == ldr_type){
        return ;
    }
    if(ldr_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ldr_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(ldr_type);
}

cJSON *ldr_type_convertToJSON(ldr_type_t *ldr_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ldr_type_t *ldr_type_parseFromJSON(cJSON *ldr_typeJSON){

    ldr_type_t *ldr_type_local_var = NULL;



    ldr_type_local_var = ldr_type_create_internal (
        );

    if (!ldr_type_local_var) {
        goto end;
    }

    return ldr_type_local_var;
end:
    return NULL;

}
