#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_key_info.h"



static ciphering_key_info_t *ciphering_key_info_create_internal(
    list_t *ciphering_data,
    char *supported_features
    ) {
    ciphering_key_info_t *ciphering_key_info_local_var = malloc(sizeof(ciphering_key_info_t));
    if (!ciphering_key_info_local_var) {
        return NULL;
    }
    memset(ciphering_key_info_local_var, 0, sizeof(ciphering_key_info_t));
    ciphering_key_info_local_var->_library_owned = 1;
    ciphering_key_info_local_var->ciphering_data = ciphering_data;
    ciphering_key_info_local_var->supported_features = supported_features;
    return ciphering_key_info_local_var;
}

__attribute__((deprecated)) ciphering_key_info_t *ciphering_key_info_create(
    list_t *ciphering_data,
    char *supported_features
    ) {
    ciphering_key_info_t *result = ciphering_key_info_create_internal (
        ciphering_data,
        supported_features
        );
    if (!result) {
    }
    return result;
}

void ciphering_key_info_free(ciphering_key_info_t *ciphering_key_info) {
    if(NULL == ciphering_key_info){
        return ;
    }
    if(ciphering_key_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ciphering_key_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ciphering_key_info->ciphering_data) {
        list_ForEach(listEntry, ciphering_key_info->ciphering_data) {
            ciphering_data_set_free(listEntry->data);
        }
        list_freeList(ciphering_key_info->ciphering_data);
        ciphering_key_info->ciphering_data = NULL;
    }
    if (ciphering_key_info->supported_features) {
        free(ciphering_key_info->supported_features);
        ciphering_key_info->supported_features = NULL;
    }
    free(ciphering_key_info);
}

cJSON *ciphering_key_info_convertToJSON(ciphering_key_info_t *ciphering_key_info) {
    cJSON *item = cJSON_CreateObject();

    // ciphering_key_info->ciphering_data
    if (!ciphering_key_info->ciphering_data) {
        goto fail;
    }
    cJSON *ciphering_data = cJSON_AddArrayToObject(item, "cipheringData");
    if(ciphering_data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ciphering_dataListEntry;
    if (ciphering_key_info->ciphering_data) {
    list_ForEach(ciphering_dataListEntry, ciphering_key_info->ciphering_data) {
    cJSON *itemLocal = ciphering_data_set_convertToJSON(ciphering_dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ciphering_data, itemLocal);
    }
    }


    // ciphering_key_info->supported_features
    if(ciphering_key_info->supported_features) {
    if(cJSON_AddStringToObject(item, "supportedFeatures", ciphering_key_info->supported_features) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ciphering_key_info_t *ciphering_key_info_parseFromJSON(cJSON *ciphering_key_infoJSON){

    ciphering_key_info_t *ciphering_key_info_local_var = NULL;

    // define the local list for ciphering_key_info->ciphering_data
    list_t *ciphering_dataList = NULL;

    char *supported_features_local_str = NULL;

    // ciphering_key_info->ciphering_data
    cJSON *ciphering_data = cJSON_GetObjectItemCaseSensitive(ciphering_key_infoJSON, "cipheringData");
    if (cJSON_IsNull(ciphering_data)) {
        ciphering_data = NULL;
    }
    if (!ciphering_data) {
        goto end;
    }

    
    cJSON *ciphering_data_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ciphering_data)){
        goto end; //nonprimitive container
    }

    ciphering_dataList = list_createList();

    cJSON_ArrayForEach(ciphering_data_local_nonprimitive,ciphering_data )
    {
        if(!cJSON_IsObject(ciphering_data_local_nonprimitive)){
            goto end;
        }
        ciphering_data_set_t *ciphering_dataItem = ciphering_data_set_parseFromJSON(ciphering_data_local_nonprimitive);

        list_addElement(ciphering_dataList, ciphering_dataItem);
    }

    // ciphering_key_info->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(ciphering_key_infoJSON, "supportedFeatures");
    if (cJSON_IsNull(supported_features)) {
        supported_features = NULL;
    }
    if (supported_features) { 
    if(!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features))
    {
    goto end; //String
    }
    }


    if (supported_features && !cJSON_IsNull(supported_features)) supported_features_local_str = strdup(supported_features->valuestring);

    ciphering_key_info_local_var = ciphering_key_info_create_internal (
        ciphering_dataList,
        supported_features_local_str
        );

    if (!ciphering_key_info_local_var) {
        goto end;
    }

    return ciphering_key_info_local_var;
end:
    if (ciphering_dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ciphering_dataList) {
            ciphering_data_set_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ciphering_dataList);
        ciphering_dataList = NULL;
    }
    if (supported_features_local_str) {
        free(supported_features_local_str);
        supported_features_local_str = NULL;
    }
    return NULL;

}
