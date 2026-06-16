#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_qos_class.h"



static lcs_qos_class_t *lcs_qos_class_create_internal(
    ) {
    lcs_qos_class_t *lcs_qos_class_local_var = malloc(sizeof(lcs_qos_class_t));
    if (!lcs_qos_class_local_var) {
        return NULL;
    }
    memset(lcs_qos_class_local_var, 0, sizeof(lcs_qos_class_t));
    lcs_qos_class_local_var->_library_owned = 1;
    return lcs_qos_class_local_var;
}

__attribute__((deprecated)) lcs_qos_class_t *lcs_qos_class_create(
    ) {
    lcs_qos_class_t *result = lcs_qos_class_create_internal (
        );
    if (!result) {
    }
    return result;
}

void lcs_qos_class_free(lcs_qos_class_t *lcs_qos_class) {
    if(NULL == lcs_qos_class){
        return ;
    }
    if(lcs_qos_class->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lcs_qos_class_free");
        return ;
    }
    listEntry_t *listEntry;
    free(lcs_qos_class);
}

cJSON *lcs_qos_class_convertToJSON(lcs_qos_class_t *lcs_qos_class) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lcs_qos_class_t *lcs_qos_class_parseFromJSON(cJSON *lcs_qos_classJSON){

    lcs_qos_class_t *lcs_qos_class_local_var = NULL;



    lcs_qos_class_local_var = lcs_qos_class_create_internal (
        );

    if (!lcs_qos_class_local_var) {
        goto end;
    }

    return lcs_qos_class_local_var;
end:
    return NULL;

}
