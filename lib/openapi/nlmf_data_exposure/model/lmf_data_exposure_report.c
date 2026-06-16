#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_report.h"



static lmf_data_exposure_report_t *lmf_data_exposure_report_create_internal(
    list_t *sampling_data_list,
    int *ml_model_id,
    lmf_data_exposure_cause_t *cause
    ) {
    lmf_data_exposure_report_t *lmf_data_exposure_report_local_var = malloc(sizeof(lmf_data_exposure_report_t));
    if (!lmf_data_exposure_report_local_var) {
        return NULL;
    }
    memset(lmf_data_exposure_report_local_var, 0, sizeof(lmf_data_exposure_report_t));
    lmf_data_exposure_report_local_var->_library_owned = 1;
    lmf_data_exposure_report_local_var->sampling_data_list = sampling_data_list;
    lmf_data_exposure_report_local_var->ml_model_id = ml_model_id;
    lmf_data_exposure_report_local_var->cause = cause;
    return lmf_data_exposure_report_local_var;
}

__attribute__((deprecated)) lmf_data_exposure_report_t *lmf_data_exposure_report_create(
    list_t *sampling_data_list,
    int *ml_model_id,
    lmf_data_exposure_cause_t *cause
    ) {
    int *ml_model_id_copy = NULL;
    if (ml_model_id) {
        ml_model_id_copy = malloc(sizeof(int));
        if (ml_model_id_copy) *ml_model_id_copy = *ml_model_id;
    }
    lmf_data_exposure_report_t *result = lmf_data_exposure_report_create_internal (
        sampling_data_list,
        ml_model_id_copy,
        cause
        );
    if (!result) {
        free(ml_model_id_copy);
    }
    return result;
}

void lmf_data_exposure_report_free(lmf_data_exposure_report_t *lmf_data_exposure_report) {
    if(NULL == lmf_data_exposure_report){
        return ;
    }
    if(lmf_data_exposure_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lmf_data_exposure_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (lmf_data_exposure_report->sampling_data_list) {
        list_ForEach(listEntry, lmf_data_exposure_report->sampling_data_list) {
            lmf_data_exposure_sampling_data_free(listEntry->data);
        }
        list_freeList(lmf_data_exposure_report->sampling_data_list);
        lmf_data_exposure_report->sampling_data_list = NULL;
    }
    if (lmf_data_exposure_report->ml_model_id) {
        free(lmf_data_exposure_report->ml_model_id);
        lmf_data_exposure_report->ml_model_id = NULL;
    }
    if (lmf_data_exposure_report->cause) {
        lmf_data_exposure_cause_free(lmf_data_exposure_report->cause);
        lmf_data_exposure_report->cause = NULL;
    }
    free(lmf_data_exposure_report);
}

cJSON *lmf_data_exposure_report_convertToJSON(lmf_data_exposure_report_t *lmf_data_exposure_report) {
    cJSON *item = cJSON_CreateObject();

    // lmf_data_exposure_report->sampling_data_list
    if(lmf_data_exposure_report->sampling_data_list) {
    cJSON *sampling_data_list = cJSON_AddArrayToObject(item, "samplingDataList");
    if(sampling_data_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *sampling_data_listListEntry;
    if (lmf_data_exposure_report->sampling_data_list) {
    list_ForEach(sampling_data_listListEntry, lmf_data_exposure_report->sampling_data_list) {
    cJSON *itemLocal = lmf_data_exposure_sampling_data_convertToJSON(sampling_data_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(sampling_data_list, itemLocal);
    }
    }
    }


    // lmf_data_exposure_report->ml_model_id
    if(lmf_data_exposure_report->ml_model_id) {
    if(cJSON_AddNumberToObject(item, "mlModelId", *lmf_data_exposure_report->ml_model_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // lmf_data_exposure_report->cause
    if(lmf_data_exposure_report->cause) {
    cJSON *cause_local_JSON = lmf_data_exposure_cause_convertToJSON(lmf_data_exposure_report->cause);
    if(cause_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cause", cause_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lmf_data_exposure_report_t *lmf_data_exposure_report_parseFromJSON(cJSON *lmf_data_exposure_reportJSON){

    lmf_data_exposure_report_t *lmf_data_exposure_report_local_var = NULL;

    // define the local list for lmf_data_exposure_report->sampling_data_list
    list_t *sampling_data_listList = NULL;

    // define the local variable for lmf_data_exposure_report->ml_model_id
    int *ml_model_id_local_var = NULL;

    // define the local variable for lmf_data_exposure_report->cause
    lmf_data_exposure_cause_t *cause_local_nonprim = NULL;

    // lmf_data_exposure_report->sampling_data_list
    cJSON *sampling_data_list = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_reportJSON, "samplingDataList");
    if (cJSON_IsNull(sampling_data_list)) {
        sampling_data_list = NULL;
    }
    if (sampling_data_list) { 
    cJSON *sampling_data_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(sampling_data_list)){
        goto end; //nonprimitive container
    }

    sampling_data_listList = list_createList();

    cJSON_ArrayForEach(sampling_data_list_local_nonprimitive,sampling_data_list )
    {
        if(!cJSON_IsObject(sampling_data_list_local_nonprimitive)){
            goto end;
        }
        lmf_data_exposure_sampling_data_t *sampling_data_listItem = lmf_data_exposure_sampling_data_parseFromJSON(sampling_data_list_local_nonprimitive);

        list_addElement(sampling_data_listList, sampling_data_listItem);
    }
    }

    // lmf_data_exposure_report->ml_model_id
    cJSON *ml_model_id = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_reportJSON, "mlModelId");
    if (cJSON_IsNull(ml_model_id)) {
        ml_model_id = NULL;
    }
    if (ml_model_id) { 
    if(!cJSON_IsNumber(ml_model_id))
    {
    goto end; //Numeric
    }
    ml_model_id_local_var = malloc(sizeof(int));
    if(!ml_model_id_local_var)
    {
        goto end;
    }
    *ml_model_id_local_var = ml_model_id->valuedouble;
    }

    // lmf_data_exposure_report->cause
    cJSON *cause = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_reportJSON, "cause");
    if (cJSON_IsNull(cause)) {
        cause = NULL;
    }
    if (cause) { 
    cause_local_nonprim = lmf_data_exposure_cause_parseFromJSON(cause); //nonprimitive
    }



    lmf_data_exposure_report_local_var = lmf_data_exposure_report_create_internal (
        sampling_data_list ? sampling_data_listList : NULL,
        ml_model_id_local_var,
        cause ? cause_local_nonprim : NULL
        );

    if (!lmf_data_exposure_report_local_var) {
        goto end;
    }

    return lmf_data_exposure_report_local_var;
end:
    if (sampling_data_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, sampling_data_listList) {
            lmf_data_exposure_sampling_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(sampling_data_listList);
        sampling_data_listList = NULL;
    }
    if (ml_model_id_local_var) {
        free(ml_model_id_local_var);
        ml_model_id_local_var = NULL;
    }
    if (cause_local_nonprim) {
        lmf_data_exposure_cause_free(cause_local_nonprim);
        cause_local_nonprim = NULL;
    }
    return NULL;

}
