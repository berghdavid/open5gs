#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_loc_data.h"



static cancel_loc_data_t *cancel_loc_data_create_internal(
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    char *lcs_correlation_id,
    char *supported_features
    ) {
    cancel_loc_data_t *cancel_loc_data_local_var = malloc(sizeof(cancel_loc_data_t));
    if (!cancel_loc_data_local_var) {
        return NULL;
    }
    memset(cancel_loc_data_local_var, 0, sizeof(cancel_loc_data_t));
    cancel_loc_data_local_var->_library_owned = 1;
    cancel_loc_data_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
    cancel_loc_data_local_var->ldr_reference = ldr_reference;
    cancel_loc_data_local_var->lcs_correlation_id = lcs_correlation_id;
    cancel_loc_data_local_var->supported_features = supported_features;
    return cancel_loc_data_local_var;
}

__attribute__((deprecated)) cancel_loc_data_t *cancel_loc_data_create(
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    char *lcs_correlation_id,
    char *supported_features
    ) {
    cancel_loc_data_t *result = cancel_loc_data_create_internal (
        hgmlc_call_back_uri,
        ldr_reference,
        lcs_correlation_id,
        supported_features
        );
    if (!result) {
    }
    return result;
}

void cancel_loc_data_free(cancel_loc_data_t *cancel_loc_data) {
    if(NULL == cancel_loc_data){
        return ;
    }
    if(cancel_loc_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cancel_loc_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cancel_loc_data->hgmlc_call_back_uri) {
        free(cancel_loc_data->hgmlc_call_back_uri);
        cancel_loc_data->hgmlc_call_back_uri = NULL;
    }
    if (cancel_loc_data->ldr_reference) {
        free(cancel_loc_data->ldr_reference);
        cancel_loc_data->ldr_reference = NULL;
    }
    if (cancel_loc_data->lcs_correlation_id) {
        free(cancel_loc_data->lcs_correlation_id);
        cancel_loc_data->lcs_correlation_id = NULL;
    }
    if (cancel_loc_data->supported_features) {
        free(cancel_loc_data->supported_features);
        cancel_loc_data->supported_features = NULL;
    }
    free(cancel_loc_data);
}

cJSON *cancel_loc_data_convertToJSON(cancel_loc_data_t *cancel_loc_data) {
    cJSON *item = cJSON_CreateObject();

    // cancel_loc_data->hgmlc_call_back_uri
    if (!cancel_loc_data->hgmlc_call_back_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hgmlcCallBackURI", cancel_loc_data->hgmlc_call_back_uri) == NULL) {
    goto fail; //String
    }


    // cancel_loc_data->ldr_reference
    if (!cancel_loc_data->ldr_reference) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ldrReference", cancel_loc_data->ldr_reference) == NULL) {
    goto fail; //String
    }


    // cancel_loc_data->lcs_correlation_id
    if(cancel_loc_data->lcs_correlation_id) {
    if(cJSON_AddStringToObject(item, "lcsCorrelationID", cancel_loc_data->lcs_correlation_id) == NULL) {
    goto fail; //String
    }
    }


    // cancel_loc_data->supported_features
    if(cancel_loc_data->supported_features) {
    if(cJSON_AddStringToObject(item, "supportedFeatures", cancel_loc_data->supported_features) == NULL) {
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

cancel_loc_data_t *cancel_loc_data_parseFromJSON(cJSON *cancel_loc_dataJSON){

    cancel_loc_data_t *cancel_loc_data_local_var = NULL;

    char *hgmlc_call_back_uri_local_str = NULL;

    char *ldr_reference_local_str = NULL;

    char *lcs_correlation_id_local_str = NULL;

    char *supported_features_local_str = NULL;

    // cancel_loc_data->hgmlc_call_back_uri
    cJSON *hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON, "hgmlcCallBackURI");
    if (cJSON_IsNull(hgmlc_call_back_uri)) {
        hgmlc_call_back_uri = NULL;
    }
    if (!hgmlc_call_back_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(hgmlc_call_back_uri))
    {
    goto end; //String
    }

    // cancel_loc_data->ldr_reference
    cJSON *ldr_reference = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON, "ldrReference");
    if (cJSON_IsNull(ldr_reference)) {
        ldr_reference = NULL;
    }
    if (!ldr_reference) {
        goto end;
    }

    
    if(!cJSON_IsString(ldr_reference))
    {
    goto end; //String
    }

    // cancel_loc_data->lcs_correlation_id
    cJSON *lcs_correlation_id = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON, "lcsCorrelationID");
    if (cJSON_IsNull(lcs_correlation_id)) {
        lcs_correlation_id = NULL;
    }
    if (lcs_correlation_id) { 
    if(!cJSON_IsString(lcs_correlation_id) && !cJSON_IsNull(lcs_correlation_id))
    {
    goto end; //String
    }
    }

    // cancel_loc_data->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON, "supportedFeatures");
    if (cJSON_IsNull(supported_features)) {
        supported_features = NULL;
    }
    if (supported_features) { 
    if(!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features))
    {
    goto end; //String
    }
    }


    if (hgmlc_call_back_uri && !cJSON_IsNull(hgmlc_call_back_uri)) hgmlc_call_back_uri_local_str = strdup(hgmlc_call_back_uri->valuestring);
    if (ldr_reference && !cJSON_IsNull(ldr_reference)) ldr_reference_local_str = strdup(ldr_reference->valuestring);
    if (lcs_correlation_id && !cJSON_IsNull(lcs_correlation_id)) lcs_correlation_id_local_str = strdup(lcs_correlation_id->valuestring);
    if (supported_features && !cJSON_IsNull(supported_features)) supported_features_local_str = strdup(supported_features->valuestring);

    cancel_loc_data_local_var = cancel_loc_data_create_internal (
        hgmlc_call_back_uri_local_str,
        ldr_reference_local_str,
        lcs_correlation_id_local_str,
        supported_features_local_str
        );

    if (!cancel_loc_data_local_var) {
        goto end;
    }

    return cancel_loc_data_local_var;
end:
    if (hgmlc_call_back_uri_local_str) {
        free(hgmlc_call_back_uri_local_str);
        hgmlc_call_back_uri_local_str = NULL;
    }
    if (ldr_reference_local_str) {
        free(ldr_reference_local_str);
        ldr_reference_local_str = NULL;
    }
    if (lcs_correlation_id_local_str) {
        free(lcs_correlation_id_local_str);
        lcs_correlation_id_local_str = NULL;
    }
    if (supported_features_local_str) {
        free(supported_features_local_str);
        supported_features_local_str = NULL;
    }
    return NULL;

}
