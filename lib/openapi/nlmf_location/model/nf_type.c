#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_type.h"



static nf_type_t *nf_type_create_internal(
    ) {
    nf_type_t *nf_type_local_var = malloc(sizeof(nf_type_t));
    if (!nf_type_local_var) {
        return NULL;
    }
    memset(nf_type_local_var, 0, sizeof(nf_type_t));
    nf_type_local_var->_library_owned = 1;
    return nf_type_local_var;
}

__attribute__((deprecated)) nf_type_t *nf_type_create(
    ) {
    nf_type_t *result = nf_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void nf_type_free(nf_type_t *nf_type) {
    if(NULL == nf_type){
        return ;
    }
    if(nf_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "nf_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(nf_type);
}

cJSON *nf_type_convertToJSON(nf_type_t *nf_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

nf_type_t *nf_type_parseFromJSON(cJSON *nf_typeJSON){

    nf_type_t *nf_type_local_var = NULL;



    nf_type_local_var = nf_type_create_internal (
        );

    if (!nf_type_local_var) {
        goto end;
    }

    return nf_type_local_var;
end:
    return NULL;

}
