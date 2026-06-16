#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_set_report.h"



static ciphering_set_report_t *ciphering_set_report_create_internal(
    int *ciphering_set_id,
    lmf_broadcast_storage_outcome__e storage_outcome
    ) {
    ciphering_set_report_t *ciphering_set_report_local_var = malloc(sizeof(ciphering_set_report_t));
    if (!ciphering_set_report_local_var) {
        return NULL;
    }
    memset(ciphering_set_report_local_var, 0, sizeof(ciphering_set_report_t));
    ciphering_set_report_local_var->_library_owned = 1;
    ciphering_set_report_local_var->ciphering_set_id = ciphering_set_id;
    ciphering_set_report_local_var->storage_outcome = storage_outcome;
    return ciphering_set_report_local_var;
}

__attribute__((deprecated)) ciphering_set_report_t *ciphering_set_report_create(
    int *ciphering_set_id,
    lmf_broadcast_storage_outcome__e storage_outcome
    ) {
    int *ciphering_set_id_copy = NULL;
    if (ciphering_set_id) {
        ciphering_set_id_copy = malloc(sizeof(int));
        if (ciphering_set_id_copy) *ciphering_set_id_copy = *ciphering_set_id;
    }
    ciphering_set_report_t *result = ciphering_set_report_create_internal (
        ciphering_set_id_copy,
        storage_outcome
        );
    if (!result) {
        free(ciphering_set_id_copy);
    }
    return result;
}

void ciphering_set_report_free(ciphering_set_report_t *ciphering_set_report) {
    if(NULL == ciphering_set_report){
        return ;
    }
    if(ciphering_set_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ciphering_set_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ciphering_set_report->ciphering_set_id) {
        free(ciphering_set_report->ciphering_set_id);
        ciphering_set_report->ciphering_set_id = NULL;
    }
    free(ciphering_set_report);
}

cJSON *ciphering_set_report_convertToJSON(ciphering_set_report_t *ciphering_set_report) {
    cJSON *item = cJSON_CreateObject();

    // ciphering_set_report->ciphering_set_id
    if (!ciphering_set_report->ciphering_set_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cipheringSetID", *ciphering_set_report->ciphering_set_id) == NULL) {
    goto fail; //Numeric
    }


    // ciphering_set_report->storage_outcome
    if (lmf_broadcast_storage_outcome__NULL == ciphering_set_report->storage_outcome) {
        goto fail;
    }
    cJSON *storage_outcome_local_JSON = storage_outcome_convertToJSON(ciphering_set_report->storage_outcome);
    if(storage_outcome_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "storageOutcome", storage_outcome_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ciphering_set_report_t *ciphering_set_report_parseFromJSON(cJSON *ciphering_set_reportJSON){

    ciphering_set_report_t *ciphering_set_report_local_var = NULL;

    // define the local variable for ciphering_set_report->ciphering_set_id
    int *ciphering_set_id_local_var = NULL;

    // define the local variable for ciphering_set_report->storage_outcome
    lmf_broadcast_storage_outcome__e storage_outcome_local_nonprim = 0;

    // ciphering_set_report->ciphering_set_id
    cJSON *ciphering_set_id = cJSON_GetObjectItemCaseSensitive(ciphering_set_reportJSON, "cipheringSetID");
    if (cJSON_IsNull(ciphering_set_id)) {
        ciphering_set_id = NULL;
    }
    if (!ciphering_set_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ciphering_set_id))
    {
    goto end; //Numeric
    }
    ciphering_set_id_local_var = malloc(sizeof(int));
    if(!ciphering_set_id_local_var)
    {
        goto end;
    }
    *ciphering_set_id_local_var = ciphering_set_id->valuedouble;

    // ciphering_set_report->storage_outcome
    cJSON *storage_outcome = cJSON_GetObjectItemCaseSensitive(ciphering_set_reportJSON, "storageOutcome");
    if (cJSON_IsNull(storage_outcome)) {
        storage_outcome = NULL;
    }
    if (!storage_outcome) {
        goto end;
    }

    
    storage_outcome_local_nonprim = storage_outcome_parseFromJSON(storage_outcome); //custom



    ciphering_set_report_local_var = ciphering_set_report_create_internal (
        ciphering_set_id_local_var,
        storage_outcome_local_nonprim
        );

    if (!ciphering_set_report_local_var) {
        goto end;
    }

    return ciphering_set_report_local_var;
end:
    if (ciphering_set_id_local_var) {
        free(ciphering_set_id_local_var);
        ciphering_set_id_local_var = NULL;
    }
    if (storage_outcome_local_nonprim) {
        storage_outcome_local_nonprim = 0;
    }
    return NULL;

}
