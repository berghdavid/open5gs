#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_cause.h"



static lmf_data_exposure_cause_t *lmf_data_exposure_cause_create_internal(
    ) {
    lmf_data_exposure_cause_t *lmf_data_exposure_cause_local_var = malloc(sizeof(lmf_data_exposure_cause_t));
    if (!lmf_data_exposure_cause_local_var) {
        return NULL;
    }
    memset(lmf_data_exposure_cause_local_var, 0, sizeof(lmf_data_exposure_cause_t));
    lmf_data_exposure_cause_local_var->_library_owned = 1;
    return lmf_data_exposure_cause_local_var;
}

__attribute__((deprecated)) lmf_data_exposure_cause_t *lmf_data_exposure_cause_create(
    ) {
    lmf_data_exposure_cause_t *result = lmf_data_exposure_cause_create_internal (
        );
    if (!result) {
    }
    return result;
}

void lmf_data_exposure_cause_free(lmf_data_exposure_cause_t *lmf_data_exposure_cause) {
    if(NULL == lmf_data_exposure_cause){
        return ;
    }
    if(lmf_data_exposure_cause->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lmf_data_exposure_cause_free");
        return ;
    }
    listEntry_t *listEntry;
    free(lmf_data_exposure_cause);
}

cJSON *lmf_data_exposure_cause_convertToJSON(lmf_data_exposure_cause_t *lmf_data_exposure_cause) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lmf_data_exposure_cause_t *lmf_data_exposure_cause_parseFromJSON(cJSON *lmf_data_exposure_causeJSON){

    lmf_data_exposure_cause_t *lmf_data_exposure_cause_local_var = NULL;



    lmf_data_exposure_cause_local_var = lmf_data_exposure_cause_create_internal (
        );

    if (!lmf_data_exposure_cause_local_var) {
        goto end;
    }

    return lmf_data_exposure_cause_local_var;
end:
    return NULL;

}
