#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fix_type.h"



static fix_type_t *fix_type_create_internal(
    ) {
    fix_type_t *fix_type_local_var = malloc(sizeof(fix_type_t));
    if (!fix_type_local_var) {
        return NULL;
    }
    memset(fix_type_local_var, 0, sizeof(fix_type_t));
    fix_type_local_var->_library_owned = 1;
    return fix_type_local_var;
}

__attribute__((deprecated)) fix_type_t *fix_type_create(
    ) {
    fix_type_t *result = fix_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void fix_type_free(fix_type_t *fix_type) {
    if(NULL == fix_type){
        return ;
    }
    if(fix_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "fix_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(fix_type);
}

cJSON *fix_type_convertToJSON(fix_type_t *fix_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

fix_type_t *fix_type_parseFromJSON(cJSON *fix_typeJSON){

    fix_type_t *fix_type_local_var = NULL;



    fix_type_local_var = fix_type_create_internal (
        );

    if (!fix_type_local_var) {
        goto end;
    }

    return fix_type_local_var;
end:
    return NULL;

}
