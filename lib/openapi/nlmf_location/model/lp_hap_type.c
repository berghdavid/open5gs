#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lp_hap_type.h"



static lp_hap_type_t *lp_hap_type_create_internal(
    ) {
    lp_hap_type_t *lp_hap_type_local_var = malloc(sizeof(lp_hap_type_t));
    if (!lp_hap_type_local_var) {
        return NULL;
    }
    memset(lp_hap_type_local_var, 0, sizeof(lp_hap_type_t));
    lp_hap_type_local_var->_library_owned = 1;
    return lp_hap_type_local_var;
}

__attribute__((deprecated)) lp_hap_type_t *lp_hap_type_create(
    ) {
    lp_hap_type_t *result = lp_hap_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void lp_hap_type_free(lp_hap_type_t *lp_hap_type) {
    if(NULL == lp_hap_type){
        return ;
    }
    if(lp_hap_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lp_hap_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(lp_hap_type);
}

cJSON *lp_hap_type_convertToJSON(lp_hap_type_t *lp_hap_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lp_hap_type_t *lp_hap_type_parseFromJSON(cJSON *lp_hap_typeJSON){

    lp_hap_type_t *lp_hap_type_local_var = NULL;



    lp_hap_type_local_var = lp_hap_type_create_internal (
        );

    if (!lp_hap_type_local_var) {
        goto end;
    }

    return lp_hap_type_local_var;
end:
    return NULL;

}
