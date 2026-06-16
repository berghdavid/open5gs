#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "usage.h"



static usage_t *usage_create_internal(
    ) {
    usage_t *usage_local_var = malloc(sizeof(usage_t));
    if (!usage_local_var) {
        return NULL;
    }
    memset(usage_local_var, 0, sizeof(usage_t));
    usage_local_var->_library_owned = 1;
    return usage_local_var;
}

__attribute__((deprecated)) usage_t *usage_create(
    ) {
    usage_t *result = usage_create_internal (
        );
    if (!result) {
    }
    return result;
}

void usage_free(usage_t *usage) {
    if(NULL == usage){
        return ;
    }
    if(usage->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "usage_free");
        return ;
    }
    listEntry_t *listEntry;
    free(usage);
}

cJSON *usage_convertToJSON(usage_t *usage) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

usage_t *usage_parseFromJSON(cJSON *usageJSON){

    usage_t *usage_local_var = NULL;



    usage_local_var = usage_create_internal (
        );

    if (!usage_local_var) {
        goto end;
    }

    return usage_local_var;
end:
    return NULL;

}
