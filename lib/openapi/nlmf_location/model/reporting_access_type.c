#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_access_type.h"



static reporting_access_type_t *reporting_access_type_create_internal(
    ) {
    reporting_access_type_t *reporting_access_type_local_var = malloc(sizeof(reporting_access_type_t));
    if (!reporting_access_type_local_var) {
        return NULL;
    }
    memset(reporting_access_type_local_var, 0, sizeof(reporting_access_type_t));
    reporting_access_type_local_var->_library_owned = 1;
    return reporting_access_type_local_var;
}

__attribute__((deprecated)) reporting_access_type_t *reporting_access_type_create(
    ) {
    reporting_access_type_t *result = reporting_access_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void reporting_access_type_free(reporting_access_type_t *reporting_access_type) {
    if(NULL == reporting_access_type){
        return ;
    }
    if(reporting_access_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reporting_access_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(reporting_access_type);
}

cJSON *reporting_access_type_convertToJSON(reporting_access_type_t *reporting_access_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reporting_access_type_t *reporting_access_type_parseFromJSON(cJSON *reporting_access_typeJSON){

    reporting_access_type_t *reporting_access_type_local_var = NULL;



    reporting_access_type_local_var = reporting_access_type_create_internal (
        );

    if (!reporting_access_type_local_var) {
        goto end;
    }

    return reporting_access_type_local_var;
end:
    return NULL;

}
