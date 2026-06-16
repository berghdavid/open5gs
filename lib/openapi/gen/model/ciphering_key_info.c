
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_key_info.h"

OpenAPI_ciphering_key_info_t *OpenAPI_ciphering_key_info_create(
    OpenAPI_list_t *ciphering_data,
    char *supported_features
)
{
    OpenAPI_ciphering_key_info_t *ciphering_key_info_local_var = ogs_malloc(sizeof(OpenAPI_ciphering_key_info_t));
    ogs_assert(ciphering_key_info_local_var);

    ciphering_key_info_local_var->ciphering_data = ciphering_data;
    ciphering_key_info_local_var->supported_features = supported_features;

    return ciphering_key_info_local_var;
}

void OpenAPI_ciphering_key_info_free(OpenAPI_ciphering_key_info_t *ciphering_key_info)
{
    if (NULL == ciphering_key_info) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_list_for_each(ciphering_key_info->ciphering_data, node) {
        OpenAPI_ciphering_data_set_free(node->data);
    }
    OpenAPI_list_free(ciphering_key_info->ciphering_data);
    ogs_free(ciphering_key_info->supported_features);
    ogs_free(ciphering_key_info);
}

cJSON *OpenAPI_ciphering_key_info_convertToJSON(OpenAPI_ciphering_key_info_t *ciphering_key_info)
{
    cJSON *item = NULL;

    if (ciphering_key_info == NULL) {
        ogs_error("OpenAPI_ciphering_key_info_convertToJSON() failed [CipheringKeyInfo]");
        return NULL;
    }

    item = cJSON_CreateObject();
    cJSON *ciphering_dataList = cJSON_AddArrayToObject(item, "cipheringData");
    if (ciphering_dataList == NULL) {
        ogs_error("OpenAPI_ciphering_key_info_convertToJSON() failed [ciphering_data]");
        goto end;
    }

    OpenAPI_lnode_t *ciphering_data_node;
    if (ciphering_key_info->ciphering_data) {
        OpenAPI_list_for_each(ciphering_key_info->ciphering_data, ciphering_data_node) {
            cJSON *itemLocal = OpenAPI_ciphering_data_set_convertToJSON(ciphering_data_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_ciphering_key_info_convertToJSON() failed [ciphering_data]");
                goto end;
            }
            cJSON_AddItemToArray(ciphering_dataList, itemLocal);
        }
    }

    if (ciphering_key_info->supported_features) {
    if (cJSON_AddStringToObject(item, "supportedFeatures", ciphering_key_info->supported_features) == NULL) {
        ogs_error("OpenAPI_ciphering_key_info_convertToJSON() failed [supported_features]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_ciphering_key_info_t *OpenAPI_ciphering_key_info_parseFromJSON(cJSON *ciphering_key_infoJSON)
{
    OpenAPI_ciphering_key_info_t *ciphering_key_info_local_var = NULL;
    cJSON *ciphering_data = cJSON_GetObjectItemCaseSensitive(ciphering_key_infoJSON, "cipheringData");
    if (!ciphering_data) {
        ogs_error("OpenAPI_ciphering_key_info_parseFromJSON() failed [ciphering_data]");
        goto end;
    }

    OpenAPI_list_t *ciphering_dataList;
    cJSON *ciphering_data_local_nonprimitive;
    if (!cJSON_IsArray(ciphering_data)){
        ogs_error("OpenAPI_ciphering_key_info_parseFromJSON() failed [ciphering_data]");
        goto end;
    }

    ciphering_dataList = OpenAPI_list_create();

    cJSON_ArrayForEach(ciphering_data_local_nonprimitive, ciphering_data ) {
        if (!cJSON_IsObject(ciphering_data_local_nonprimitive)) {
            ogs_error("OpenAPI_ciphering_key_info_parseFromJSON() failed [ciphering_data]");
            goto end;
        }
        OpenAPI_ciphering_data_set_t *ciphering_dataItem = OpenAPI_ciphering_data_set_parseFromJSON(ciphering_data_local_nonprimitive);

        if (!ciphering_dataItem) {
            ogs_error("No ciphering_dataItem");
            OpenAPI_list_free(ciphering_dataList);
            goto end;
        }

        OpenAPI_list_add(ciphering_dataList, ciphering_dataItem);
    }

    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(ciphering_key_infoJSON, "supportedFeatures");

    if (supported_features) {
    if (!cJSON_IsString(supported_features)) {
        ogs_error("OpenAPI_ciphering_key_info_parseFromJSON() failed [supported_features]");
        goto end;
    }
    }

    ciphering_key_info_local_var = OpenAPI_ciphering_key_info_create (
        ciphering_dataList,
        supported_features ? ogs_strdup(supported_features->valuestring) : NULL
    );

    return ciphering_key_info_local_var;
end:
    return NULL;
}

OpenAPI_ciphering_key_info_t *OpenAPI_ciphering_key_info_copy(OpenAPI_ciphering_key_info_t *dst, OpenAPI_ciphering_key_info_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_ciphering_key_info_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_ciphering_key_info_convertToJSON() failed");
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

    OpenAPI_ciphering_key_info_free(dst);
    dst = OpenAPI_ciphering_key_info_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

