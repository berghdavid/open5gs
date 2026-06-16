#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "related_ue_type.h"



static related_ue_type_t *related_ue_type_create_internal(
    ) {
    related_ue_type_t *related_ue_type_local_var = malloc(sizeof(related_ue_type_t));
    if (!related_ue_type_local_var) {
        return NULL;
    }
    memset(related_ue_type_local_var, 0, sizeof(related_ue_type_t));
    related_ue_type_local_var->_library_owned = 1;
    return related_ue_type_local_var;
}

__attribute__((deprecated)) related_ue_type_t *related_ue_type_create(
    ) {
    related_ue_type_t *result = related_ue_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void related_ue_type_free(related_ue_type_t *related_ue_type) {
    if(NULL == related_ue_type){
        return ;
    }
    if(related_ue_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "related_ue_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(related_ue_type);
}

cJSON *related_ue_type_convertToJSON(related_ue_type_t *related_ue_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

related_ue_type_t *related_ue_type_parseFromJSON(cJSON *related_ue_typeJSON){

    related_ue_type_t *related_ue_type_local_var = NULL;



    related_ue_type_local_var = related_ue_type_create_internal (
        );

    if (!related_ue_type_local_var) {
        goto end;
    }

    return related_ue_type_local_var;
end:
    return NULL;

}
