#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cipher_request_data.h"



static cipher_request_data_t *cipher_request_data_create_internal(
    char *amf_call_back_uri,
    char *supported_features
    ) {
    cipher_request_data_t *cipher_request_data_local_var = malloc(sizeof(cipher_request_data_t));
    if (!cipher_request_data_local_var) {
        return NULL;
    }
    memset(cipher_request_data_local_var, 0, sizeof(cipher_request_data_t));
    cipher_request_data_local_var->_library_owned = 1;
    cipher_request_data_local_var->amf_call_back_uri = amf_call_back_uri;
    cipher_request_data_local_var->supported_features = supported_features;
    return cipher_request_data_local_var;
}

__attribute__((deprecated)) cipher_request_data_t *cipher_request_data_create(
    char *amf_call_back_uri,
    char *supported_features
    ) {
    cipher_request_data_t *result = cipher_request_data_create_internal (
        amf_call_back_uri,
        supported_features
        );
    if (!result) {
    }
    return result;
}

void cipher_request_data_free(cipher_request_data_t *cipher_request_data) {
    if(NULL == cipher_request_data){
        return ;
    }
    if(cipher_request_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cipher_request_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cipher_request_data->amf_call_back_uri) {
        free(cipher_request_data->amf_call_back_uri);
        cipher_request_data->amf_call_back_uri = NULL;
    }
    if (cipher_request_data->supported_features) {
        free(cipher_request_data->supported_features);
        cipher_request_data->supported_features = NULL;
    }
    free(cipher_request_data);
}

cJSON *cipher_request_data_convertToJSON(cipher_request_data_t *cipher_request_data) {
    cJSON *item = cJSON_CreateObject();

    // cipher_request_data->amf_call_back_uri
    if (!cipher_request_data->amf_call_back_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amfCallBackURI", cipher_request_data->amf_call_back_uri) == NULL) {
    goto fail; //String
    }


    // cipher_request_data->supported_features
    if(cipher_request_data->supported_features) {
    if(cJSON_AddStringToObject(item, "supportedFeatures", cipher_request_data->supported_features) == NULL) {
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

cipher_request_data_t *cipher_request_data_parseFromJSON(cJSON *cipher_request_dataJSON){

    cipher_request_data_t *cipher_request_data_local_var = NULL;

    char *amf_call_back_uri_local_str = NULL;

    char *supported_features_local_str = NULL;

    // cipher_request_data->amf_call_back_uri
    cJSON *amf_call_back_uri = cJSON_GetObjectItemCaseSensitive(cipher_request_dataJSON, "amfCallBackURI");
    if (cJSON_IsNull(amf_call_back_uri)) {
        amf_call_back_uri = NULL;
    }
    if (!amf_call_back_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(amf_call_back_uri))
    {
    goto end; //String
    }

    // cipher_request_data->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(cipher_request_dataJSON, "supportedFeatures");
    if (cJSON_IsNull(supported_features)) {
        supported_features = NULL;
    }
    if (supported_features) { 
    if(!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features))
    {
    goto end; //String
    }
    }


    if (amf_call_back_uri && !cJSON_IsNull(amf_call_back_uri)) amf_call_back_uri_local_str = strdup(amf_call_back_uri->valuestring);
    if (supported_features && !cJSON_IsNull(supported_features)) supported_features_local_str = strdup(supported_features->valuestring);

    cipher_request_data_local_var = cipher_request_data_create_internal (
        amf_call_back_uri_local_str,
        supported_features_local_str
        );

    if (!cipher_request_data_local_var) {
        goto end;
    }

    return cipher_request_data_local_var;
end:
    if (amf_call_back_uri_local_str) {
        free(amf_call_back_uri_local_str);
        amf_call_back_uri_local_str = NULL;
    }
    if (supported_features_local_str) {
        free(supported_features_local_str);
        supported_features_local_str = NULL;
    }
    return NULL;

}
