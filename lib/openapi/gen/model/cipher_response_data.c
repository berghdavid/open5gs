
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cipher_response_data.h"

OpenAPI_cipher_response_data_t *OpenAPI_cipher_response_data_create(
    OpenAPI_data_availability_e data_availability
)
{
    OpenAPI_cipher_response_data_t *cipher_response_data_local_var = ogs_malloc(sizeof(OpenAPI_cipher_response_data_t));
    ogs_assert(cipher_response_data_local_var);

    cipher_response_data_local_var->data_availability = data_availability;

    return cipher_response_data_local_var;
}

void OpenAPI_cipher_response_data_free(OpenAPI_cipher_response_data_t *cipher_response_data)
{
    if (NULL == cipher_response_data) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(cipher_response_data);
}

cJSON *OpenAPI_cipher_response_data_convertToJSON(OpenAPI_cipher_response_data_t *cipher_response_data)
{
    cJSON *item = NULL;

    if (cipher_response_data == NULL) {
        ogs_error("OpenAPI_cipher_response_data_convertToJSON() failed [CipherResponseData]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddStringToObject(item, "dataAvailability", OpenAPI_data_availability_ToString(cipher_response_data->data_availability)) == NULL) {
        ogs_error("OpenAPI_cipher_response_data_convertToJSON() failed [data_availability]");
        goto end;
    }

end:
    return item;
}

OpenAPI_cipher_response_data_t *OpenAPI_cipher_response_data_parseFromJSON(cJSON *cipher_response_dataJSON)
{
    OpenAPI_cipher_response_data_t *cipher_response_data_local_var = NULL;
    cJSON *data_availability = cJSON_GetObjectItemCaseSensitive(cipher_response_dataJSON, "dataAvailability");
    if (!data_availability) {
        ogs_error("OpenAPI_cipher_response_data_parseFromJSON() failed [data_availability]");
        goto end;
    }

    OpenAPI_data_availability_e data_availabilityVariable;
    if (!cJSON_IsString(data_availability)) {
        ogs_error("OpenAPI_cipher_response_data_parseFromJSON() failed [data_availability]");
        goto end;
    }
    data_availabilityVariable = OpenAPI_data_availability_FromString(data_availability->valuestring);

    cipher_response_data_local_var = OpenAPI_cipher_response_data_create (
        data_availabilityVariable
    );

    return cipher_response_data_local_var;
end:
    return NULL;
}

OpenAPI_cipher_response_data_t *OpenAPI_cipher_response_data_copy(OpenAPI_cipher_response_data_t *dst, OpenAPI_cipher_response_data_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_cipher_response_data_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_cipher_response_data_convertToJSON() failed");
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

    OpenAPI_cipher_response_data_free(dst);
    dst = OpenAPI_cipher_response_data_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

