#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_method.h"



static positioning_method_t *positioning_method_create_internal(
    ) {
    positioning_method_t *positioning_method_local_var = malloc(sizeof(positioning_method_t));
    if (!positioning_method_local_var) {
        return NULL;
    }
    memset(positioning_method_local_var, 0, sizeof(positioning_method_t));
    positioning_method_local_var->_library_owned = 1;
    return positioning_method_local_var;
}

__attribute__((deprecated)) positioning_method_t *positioning_method_create(
    ) {
    positioning_method_t *result = positioning_method_create_internal (
        );
    if (!result) {
    }
    return result;
}

void positioning_method_free(positioning_method_t *positioning_method) {
    if(NULL == positioning_method){
        return ;
    }
    if(positioning_method->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "positioning_method_free");
        return ;
    }
    listEntry_t *listEntry;
    free(positioning_method);
}

cJSON *positioning_method_convertToJSON(positioning_method_t *positioning_method) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

positioning_method_t *positioning_method_parseFromJSON(cJSON *positioning_methodJSON){

    positioning_method_t *positioning_method_local_var = NULL;



    positioning_method_local_var = positioning_method_create_internal (
        );

    if (!positioning_method_local_var) {
        goto end;
    }

    return positioning_method_local_var;
end:
    return NULL;

}
