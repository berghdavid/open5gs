#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "accuracy_fulfilment_indicator.h"



static accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_create_internal(
    ) {
    accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_local_var = malloc(sizeof(accuracy_fulfilment_indicator_t));
    if (!accuracy_fulfilment_indicator_local_var) {
        return NULL;
    }
    memset(accuracy_fulfilment_indicator_local_var, 0, sizeof(accuracy_fulfilment_indicator_t));
    accuracy_fulfilment_indicator_local_var->_library_owned = 1;
    return accuracy_fulfilment_indicator_local_var;
}

__attribute__((deprecated)) accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_create(
    ) {
    accuracy_fulfilment_indicator_t *result = accuracy_fulfilment_indicator_create_internal (
        );
    if (!result) {
    }
    return result;
}

void accuracy_fulfilment_indicator_free(accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator) {
    if(NULL == accuracy_fulfilment_indicator){
        return ;
    }
    if(accuracy_fulfilment_indicator->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "accuracy_fulfilment_indicator_free");
        return ;
    }
    listEntry_t *listEntry;
    free(accuracy_fulfilment_indicator);
}

cJSON *accuracy_fulfilment_indicator_convertToJSON(accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_parseFromJSON(cJSON *accuracy_fulfilment_indicatorJSON){

    accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_local_var = NULL;



    accuracy_fulfilment_indicator_local_var = accuracy_fulfilment_indicator_create_internal (
        );

    if (!accuracy_fulfilment_indicator_local_var) {
        goto end;
    }

    return accuracy_fulfilment_indicator_local_var;
end:
    return NULL;

}
