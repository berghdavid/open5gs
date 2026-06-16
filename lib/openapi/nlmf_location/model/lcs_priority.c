#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_priority.h"



static lcs_priority_t *lcs_priority_create_internal(
    ) {
    lcs_priority_t *lcs_priority_local_var = malloc(sizeof(lcs_priority_t));
    if (!lcs_priority_local_var) {
        return NULL;
    }
    memset(lcs_priority_local_var, 0, sizeof(lcs_priority_t));
    lcs_priority_local_var->_library_owned = 1;
    return lcs_priority_local_var;
}

__attribute__((deprecated)) lcs_priority_t *lcs_priority_create(
    ) {
    lcs_priority_t *result = lcs_priority_create_internal (
        );
    if (!result) {
    }
    return result;
}

void lcs_priority_free(lcs_priority_t *lcs_priority) {
    if(NULL == lcs_priority){
        return ;
    }
    if(lcs_priority->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lcs_priority_free");
        return ;
    }
    listEntry_t *listEntry;
    free(lcs_priority);
}

cJSON *lcs_priority_convertToJSON(lcs_priority_t *lcs_priority) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lcs_priority_t *lcs_priority_parseFromJSON(cJSON *lcs_priorityJSON){

    lcs_priority_t *lcs_priority_local_var = NULL;



    lcs_priority_local_var = lcs_priority_create_internal (
        );

    if (!lcs_priority_local_var) {
        goto end;
    }

    return lcs_priority_local_var;
end:
    return NULL;

}
