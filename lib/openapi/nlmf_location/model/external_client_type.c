#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "external_client_type.h"



static external_client_type_t *external_client_type_create_internal(
    ) {
    external_client_type_t *external_client_type_local_var = malloc(sizeof(external_client_type_t));
    if (!external_client_type_local_var) {
        return NULL;
    }
    memset(external_client_type_local_var, 0, sizeof(external_client_type_t));
    external_client_type_local_var->_library_owned = 1;
    return external_client_type_local_var;
}

__attribute__((deprecated)) external_client_type_t *external_client_type_create(
    ) {
    external_client_type_t *result = external_client_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void external_client_type_free(external_client_type_t *external_client_type) {
    if(NULL == external_client_type){
        return ;
    }
    if(external_client_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "external_client_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(external_client_type);
}

cJSON *external_client_type_convertToJSON(external_client_type_t *external_client_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

external_client_type_t *external_client_type_parseFromJSON(cJSON *external_client_typeJSON){

    external_client_type_t *external_client_type_local_var = NULL;



    external_client_type_local_var = external_client_type_create_internal (
        );

    if (!external_client_type_local_var) {
        goto end;
    }

    return external_client_type_local_var;
end:
    return NULL;

}
