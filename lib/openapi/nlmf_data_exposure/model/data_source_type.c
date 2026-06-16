#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data_source_type.h"



static data_source_type_t *data_source_type_create_internal(
    ) {
    data_source_type_t *data_source_type_local_var = malloc(sizeof(data_source_type_t));
    if (!data_source_type_local_var) {
        return NULL;
    }
    memset(data_source_type_local_var, 0, sizeof(data_source_type_t));
    data_source_type_local_var->_library_owned = 1;
    return data_source_type_local_var;
}

__attribute__((deprecated)) data_source_type_t *data_source_type_create(
    ) {
    data_source_type_t *result = data_source_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void data_source_type_free(data_source_type_t *data_source_type) {
    if(NULL == data_source_type){
        return ;
    }
    if(data_source_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "data_source_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(data_source_type);
}

cJSON *data_source_type_convertToJSON(data_source_type_t *data_source_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

data_source_type_t *data_source_type_parseFromJSON(cJSON *data_source_typeJSON){

    data_source_type_t *data_source_type_local_var = NULL;



    data_source_type_local_var = data_source_type_create_internal (
        );

    if (!data_source_type_local_var) {
        goto end;
    }

    return data_source_type_local_var;
end:
    return NULL;

}
