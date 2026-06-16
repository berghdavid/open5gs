#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_key_response.h"



static ciphering_key_response_t *ciphering_key_response_create_internal(
    list_t *ciphering_data_report
    ) {
    ciphering_key_response_t *ciphering_key_response_local_var = malloc(sizeof(ciphering_key_response_t));
    if (!ciphering_key_response_local_var) {
        return NULL;
    }
    memset(ciphering_key_response_local_var, 0, sizeof(ciphering_key_response_t));
    ciphering_key_response_local_var->_library_owned = 1;
    ciphering_key_response_local_var->ciphering_data_report = ciphering_data_report;
    return ciphering_key_response_local_var;
}

__attribute__((deprecated)) ciphering_key_response_t *ciphering_key_response_create(
    list_t *ciphering_data_report
    ) {
    ciphering_key_response_t *result = ciphering_key_response_create_internal (
        ciphering_data_report
        );
    if (!result) {
    }
    return result;
}

void ciphering_key_response_free(ciphering_key_response_t *ciphering_key_response) {
    if(NULL == ciphering_key_response){
        return ;
    }
    if(ciphering_key_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ciphering_key_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ciphering_key_response->ciphering_data_report) {
        list_ForEach(listEntry, ciphering_key_response->ciphering_data_report) {
            ciphering_set_report_free(listEntry->data);
        }
        list_freeList(ciphering_key_response->ciphering_data_report);
        ciphering_key_response->ciphering_data_report = NULL;
    }
    free(ciphering_key_response);
}

cJSON *ciphering_key_response_convertToJSON(ciphering_key_response_t *ciphering_key_response) {
    cJSON *item = cJSON_CreateObject();

    // ciphering_key_response->ciphering_data_report
    if(ciphering_key_response->ciphering_data_report) {
    cJSON *ciphering_data_report = cJSON_AddArrayToObject(item, "cipheringDataReport");
    if(ciphering_data_report == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ciphering_data_reportListEntry;
    if (ciphering_key_response->ciphering_data_report) {
    list_ForEach(ciphering_data_reportListEntry, ciphering_key_response->ciphering_data_report) {
    cJSON *itemLocal = ciphering_set_report_convertToJSON(ciphering_data_reportListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ciphering_data_report, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ciphering_key_response_t *ciphering_key_response_parseFromJSON(cJSON *ciphering_key_responseJSON){

    ciphering_key_response_t *ciphering_key_response_local_var = NULL;

    // define the local list for ciphering_key_response->ciphering_data_report
    list_t *ciphering_data_reportList = NULL;

    // ciphering_key_response->ciphering_data_report
    cJSON *ciphering_data_report = cJSON_GetObjectItemCaseSensitive(ciphering_key_responseJSON, "cipheringDataReport");
    if (cJSON_IsNull(ciphering_data_report)) {
        ciphering_data_report = NULL;
    }
    if (ciphering_data_report) { 
    cJSON *ciphering_data_report_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ciphering_data_report)){
        goto end; //nonprimitive container
    }

    ciphering_data_reportList = list_createList();

    cJSON_ArrayForEach(ciphering_data_report_local_nonprimitive,ciphering_data_report )
    {
        if(!cJSON_IsObject(ciphering_data_report_local_nonprimitive)){
            goto end;
        }
        ciphering_set_report_t *ciphering_data_reportItem = ciphering_set_report_parseFromJSON(ciphering_data_report_local_nonprimitive);

        list_addElement(ciphering_data_reportList, ciphering_data_reportItem);
    }
    }



    ciphering_key_response_local_var = ciphering_key_response_create_internal (
        ciphering_data_report ? ciphering_data_reportList : NULL
        );

    if (!ciphering_key_response_local_var) {
        goto end;
    }

    return ciphering_key_response_local_var;
end:
    if (ciphering_data_reportList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ciphering_data_reportList) {
            ciphering_set_report_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ciphering_data_reportList);
        ciphering_data_reportList = NULL;
    }
    return NULL;

}
