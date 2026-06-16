#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_area_type.h"



static reporting_area_type_t *reporting_area_type_create_internal(
    ) {
    reporting_area_type_t *reporting_area_type_local_var = malloc(sizeof(reporting_area_type_t));
    if (!reporting_area_type_local_var) {
        return NULL;
    }
    memset(reporting_area_type_local_var, 0, sizeof(reporting_area_type_t));
    reporting_area_type_local_var->_library_owned = 1;
    return reporting_area_type_local_var;
}

__attribute__((deprecated)) reporting_area_type_t *reporting_area_type_create(
    ) {
    reporting_area_type_t *result = reporting_area_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void reporting_area_type_free(reporting_area_type_t *reporting_area_type) {
    if(NULL == reporting_area_type){
        return ;
    }
    if(reporting_area_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reporting_area_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(reporting_area_type);
}

cJSON *reporting_area_type_convertToJSON(reporting_area_type_t *reporting_area_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reporting_area_type_t *reporting_area_type_parseFromJSON(cJSON *reporting_area_typeJSON){

    reporting_area_type_t *reporting_area_type_local_var = NULL;



    reporting_area_type_local_var = reporting_area_type_create_internal (
        );

    if (!reporting_area_type_local_var) {
        goto end;
    }

    return reporting_area_type_local_var;
end:
    return NULL;

}
