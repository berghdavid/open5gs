
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cipher_request_data.h"

OpenAPI_cipher_request_data_t *OpenAPI_cipher_request_data_create(
    char *amf_call_back_uri,
    char *supported_features
)
{
    OpenAPI_cipher_request_data_t *cipher_request_data_local_var = ogs_malloc(sizeof(OpenAPI_cipher_request_data_t));
    ogs_assert(cipher_request_data_local_var);

    cipher_request_data_local_var->amf_call_back_uri = amf_call_back_uri;
    cipher_request_data_local_var->supported_features = supported_features;

    return cipher_request_data_local_var;
}

void OpenAPI_cipher_request_data_free(OpenAPI_cipher_request_data_t *cipher_request_data)
{
    if (NULL == cipher_request_data) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(cipher_request_data->amf_call_back_uri);
    ogs_free(cipher_request_data->supported_features);
    ogs_free(cipher_request_data);
}

cJSON *OpenAPI_cipher_request_data_convertToJSON(OpenAPI_cipher_request_data_t *cipher_request_data)
{
    cJSON *item = NULL;

    if (cipher_request_data == NULL) {
        ogs_error("OpenAPI_cipher_request_data_convertToJSON() failed [CipherRequestData]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddStringToObject(item, "amfCallBackURI", cipher_request_data->amf_call_back_uri) == NULL) {
        ogs_error("OpenAPI_cipher_request_data_convertToJSON() failed [amf_call_back_uri]");
        goto end;
    }

    if (cipher_request_data->supported_features) {
    if (cJSON_AddStringToObject(item, "supportedFeatures", cipher_request_data->supported_features) == NULL) {
        ogs_error("OpenAPI_cipher_request_data_convertToJSON() failed [supported_features]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_cipher_request_data_t *OpenAPI_cipher_request_data_parseFromJSON(cJSON *cipher_request_dataJSON)
{
    OpenAPI_cipher_request_data_t *cipher_request_data_local_var = NULL;
    cJSON *amf_call_back_uri = cJSON_GetObjectItemCaseSensitive(cipher_request_dataJSON, "amfCallBackURI");
    if (!amf_call_back_uri) {
        ogs_error("OpenAPI_cipher_request_data_parseFromJSON() failed [amf_call_back_uri]");
        goto end;
    }

    if (!cJSON_IsString(amf_call_back_uri)) {
        ogs_error("OpenAPI_cipher_request_data_parseFromJSON() failed [amf_call_back_uri]");
        goto end;
    }

    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(cipher_request_dataJSON, "supportedFeatures");

    if (supported_features) {
    if (!cJSON_IsString(supported_features)) {
        ogs_error("OpenAPI_cipher_request_data_parseFromJSON() failed [supported_features]");
        goto end;
    }
    }

    cipher_request_data_local_var = OpenAPI_cipher_request_data_create (
        ogs_strdup(amf_call_back_uri->valuestring),
        supported_features ? ogs_strdup(supported_features->valuestring) : NULL
    );

    return cipher_request_data_local_var;
end:
    return NULL;
}

OpenAPI_cipher_request_data_t *OpenAPI_cipher_request_data_copy(OpenAPI_cipher_request_data_t *dst, OpenAPI_cipher_request_data_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_cipher_request_data_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_cipher_request_data_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_cipher_request_data_free(dst);
    dst = OpenAPI_cipher_request_data_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

