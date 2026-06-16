
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_key_response.h"

OpenAPI_ciphering_key_response_t *OpenAPI_ciphering_key_response_create(
    OpenAPI_list_t *ciphering_data_report
)
{
    OpenAPI_ciphering_key_response_t *ciphering_key_response_local_var = ogs_malloc(sizeof(OpenAPI_ciphering_key_response_t));
    ogs_assert(ciphering_key_response_local_var);

    ciphering_key_response_local_var->ciphering_data_report = ciphering_data_report;

    return ciphering_key_response_local_var;
}

void OpenAPI_ciphering_key_response_free(OpenAPI_ciphering_key_response_t *ciphering_key_response)
{
    if (NULL == ciphering_key_response) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_list_for_each(ciphering_key_response->ciphering_data_report, node) {
        OpenAPI_ciphering_set_report_free(node->data);
    }
    OpenAPI_list_free(ciphering_key_response->ciphering_data_report);
    ogs_free(ciphering_key_response);
}

cJSON *OpenAPI_ciphering_key_response_convertToJSON(OpenAPI_ciphering_key_response_t *ciphering_key_response)
{
    cJSON *item = NULL;

    if (ciphering_key_response == NULL) {
        ogs_error("OpenAPI_ciphering_key_response_convertToJSON() failed [CipheringKeyResponse]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (ciphering_key_response->ciphering_data_report) {
    cJSON *ciphering_data_reportList = cJSON_AddArrayToObject(item, "cipheringDataReport");
    if (ciphering_data_reportList == NULL) {
        ogs_error("OpenAPI_ciphering_key_response_convertToJSON() failed [ciphering_data_report]");
        goto end;
    }

    OpenAPI_lnode_t *ciphering_data_report_node;
    if (ciphering_key_response->ciphering_data_report) {
        OpenAPI_list_for_each(ciphering_key_response->ciphering_data_report, ciphering_data_report_node) {
            cJSON *itemLocal = OpenAPI_ciphering_set_report_convertToJSON(ciphering_data_report_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_ciphering_key_response_convertToJSON() failed [ciphering_data_report]");
                goto end;
            }
            cJSON_AddItemToArray(ciphering_data_reportList, itemLocal);
        }
    }
    }

end:
    return item;
}

OpenAPI_ciphering_key_response_t *OpenAPI_ciphering_key_response_parseFromJSON(cJSON *ciphering_key_responseJSON)
{
    OpenAPI_ciphering_key_response_t *ciphering_key_response_local_var = NULL;
    cJSON *ciphering_data_report = cJSON_GetObjectItemCaseSensitive(ciphering_key_responseJSON, "cipheringDataReport");

    OpenAPI_list_t *ciphering_data_reportList;
    if (ciphering_data_report) {
    cJSON *ciphering_data_report_local_nonprimitive;
    if (!cJSON_IsArray(ciphering_data_report)){
        ogs_error("OpenAPI_ciphering_key_response_parseFromJSON() failed [ciphering_data_report]");
        goto end;
    }

    ciphering_data_reportList = OpenAPI_list_create();

    cJSON_ArrayForEach(ciphering_data_report_local_nonprimitive, ciphering_data_report ) {
        if (!cJSON_IsObject(ciphering_data_report_local_nonprimitive)) {
            ogs_error("OpenAPI_ciphering_key_response_parseFromJSON() failed [ciphering_data_report]");
            goto end;
        }
        OpenAPI_ciphering_set_report_t *ciphering_data_reportItem = OpenAPI_ciphering_set_report_parseFromJSON(ciphering_data_report_local_nonprimitive);

        if (!ciphering_data_reportItem) {
            ogs_error("No ciphering_data_reportItem");
            OpenAPI_list_free(ciphering_data_reportList);
            goto end;
        }

        OpenAPI_list_add(ciphering_data_reportList, ciphering_data_reportItem);
    }
    }

    ciphering_key_response_local_var = OpenAPI_ciphering_key_response_create (
        ciphering_data_report ? ciphering_data_reportList : NULL
    );

    return ciphering_key_response_local_var;
end:
    return NULL;
}

OpenAPI_ciphering_key_response_t *OpenAPI_ciphering_key_response_copy(OpenAPI_ciphering_key_response_t *dst, OpenAPI_ciphering_key_response_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_ciphering_key_response_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_ciphering_key_response_convertToJSON() failed");
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

    OpenAPI_ciphering_key_response_free(dst);
    dst = OpenAPI_ciphering_key_response_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

