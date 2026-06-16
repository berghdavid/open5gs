
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "determine_location_request.h"

OpenAPI_determine_location_request_t *OpenAPI_determine_location_request_create(
    OpenAPI_input_data_t *json_data,
    OpenAPI_binary_t* binary_data_lpp_message
)
{
    OpenAPI_determine_location_request_t *determine_location_request_local_var = ogs_malloc(sizeof(OpenAPI_determine_location_request_t));
    ogs_assert(determine_location_request_local_var);

    determine_location_request_local_var->json_data = json_data;
    determine_location_request_local_var->binary_data_lpp_message = binary_data_lpp_message;

    return determine_location_request_local_var;
}

void OpenAPI_determine_location_request_free(OpenAPI_determine_location_request_t *determine_location_request)
{
    if (NULL == determine_location_request) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_input_data_free(determine_location_request->json_data);
    ogs_free(determine_location_request->binary_data_lpp_message->data);
    ogs_free(determine_location_request);
}

cJSON *OpenAPI_determine_location_request_convertToJSON(OpenAPI_determine_location_request_t *determine_location_request)
{
    cJSON *item = NULL;

    if (determine_location_request == NULL) {
        ogs_error("OpenAPI_determine_location_request_convertToJSON() failed [DetermineLocation_request]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (determine_location_request->json_data) {
    cJSON *json_data_local_JSON = OpenAPI_input_data_convertToJSON(determine_location_request->json_data);
    if (json_data_local_JSON == NULL) {
        ogs_error("OpenAPI_determine_location_request_convertToJSON() failed [json_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "jsonData", json_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_determine_location_request_convertToJSON() failed [json_data]");
        goto end;
    }
    }

    if (determine_location_request->binary_data_lpp_message) {
    char* encoded_str_binary_data_lpp_message = OpenAPI_base64encode(determine_location_request->binary_data_lpp_message->data,determine_location_request->binary_data_lpp_message->len);
    if (cJSON_AddStringToObject(item, "binaryDataLppMessage", encoded_str_binary_data_lpp_message) == NULL) {
        ogs_error("OpenAPI_determine_location_request_convertToJSON() failed [binary_data_lpp_message]");
        goto end;
    }
    ogs_free(encoded_str_binary_data_lpp_message);
    }

end:
    return item;
}

OpenAPI_determine_location_request_t *OpenAPI_determine_location_request_parseFromJSON(cJSON *determine_location_requestJSON)
{
    OpenAPI_determine_location_request_t *determine_location_request_local_var = NULL;
    cJSON *json_data = cJSON_GetObjectItemCaseSensitive(determine_location_requestJSON, "jsonData");

    OpenAPI_input_data_t *json_data_local_nonprim = NULL;
    if (json_data) {
    json_data_local_nonprim = OpenAPI_input_data_parseFromJSON(json_data);
    }

    cJSON *binary_data_lpp_message = cJSON_GetObjectItemCaseSensitive(determine_location_requestJSON, "binaryDataLppMessage");

    OpenAPI_binary_t* decoded_str_binary_data_lpp_message = ogs_malloc(sizeof(OpenAPI_binary_t));
    ogs_assert(decoded_str_binary_data_lpp_message);
    if (binary_data_lpp_message) {
    if (!cJSON_IsString(binary_data_lpp_message)) {
        ogs_error("OpenAPI_determine_location_request_parseFromJSON() failed [binary_data_lpp_message]");
        goto end;
    }
    decoded_str_binary_data_lpp_message->data = OpenAPI_base64decode(binary_data_lpp_message->valuestring, strlen(binary_data_lpp_message->valuestring), &decoded_str_binary_data_lpp_message->len);
    if (!decoded_str_binary_data_lpp_message->data) {
        ogs_error("OpenAPI_determine_location_request_parseFromJSON() failed [binary_data_lpp_message]");
        goto end;
    }
    }

    determine_location_request_local_var = OpenAPI_determine_location_request_create (
        json_data ? json_data_local_nonprim : NULL,
        binary_data_lpp_message ? decoded_str_binary_data_lpp_message : NULL
    );

    return determine_location_request_local_var;
end:
    return NULL;
}

OpenAPI_determine_location_request_t *OpenAPI_determine_location_request_copy(OpenAPI_determine_location_request_t *dst, OpenAPI_determine_location_request_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_determine_location_request_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_determine_location_request_convertToJSON() failed");
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

    OpenAPI_determine_location_request_free(dst);
    dst = OpenAPI_determine_location_request_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

