#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recur_type.h"



static recur_type_t *recur_type_create_internal(
    ) {
    recur_type_t *recur_type_local_var = malloc(sizeof(recur_type_t));
    if (!recur_type_local_var) {
        return NULL;
    }
    memset(recur_type_local_var, 0, sizeof(recur_type_t));
    recur_type_local_var->_library_owned = 1;
    return recur_type_local_var;
}

__attribute__((deprecated)) recur_type_t *recur_type_create(
    ) {
    recur_type_t *result = recur_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void recur_type_free(recur_type_t *recur_type) {
    if(NULL == recur_type){
        return ;
    }
    if(recur_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "recur_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(recur_type);
}

cJSON *recur_type_convertToJSON(recur_type_t *recur_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

recur_type_t *recur_type_parseFromJSON(cJSON *recur_typeJSON){

    recur_type_t *recur_type_local_var = NULL;



    recur_type_local_var = recur_type_create_internal (
        );

    if (!recur_type_local_var) {
        goto end;
    }

    return recur_type_local_var;
end:
    return NULL;

}
