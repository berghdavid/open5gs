
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "additional_ue_info.h"

OpenAPI_additional_ue_info_t *OpenAPI_additional_ue_info_create(
    OpenAPI_ncgi_t *ncgi,
    OpenAPI_tai_t *tai
)
{
    OpenAPI_additional_ue_info_t *additional_ue_info_local_var = ogs_malloc(sizeof(OpenAPI_additional_ue_info_t));
    ogs_assert(additional_ue_info_local_var);

    additional_ue_info_local_var->ncgi = ncgi;
    additional_ue_info_local_var->tai = tai;

    return additional_ue_info_local_var;
}

void OpenAPI_additional_ue_info_free(OpenAPI_additional_ue_info_t *additional_ue_info)
{
    if (NULL == additional_ue_info) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_ncgi_free(additional_ue_info->ncgi);
    OpenAPI_tai_free(additional_ue_info->tai);
    ogs_free(additional_ue_info);
}

cJSON *OpenAPI_additional_ue_info_convertToJSON(OpenAPI_additional_ue_info_t *additional_ue_info)
{
    cJSON *item = NULL;

    if (additional_ue_info == NULL) {
        ogs_error("OpenAPI_additional_ue_info_convertToJSON() failed [AdditionalUeInfo]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (additional_ue_info->ncgi) {
    cJSON *ncgi_local_JSON = OpenAPI_ncgi_convertToJSON(additional_ue_info->ncgi);
    if (ncgi_local_JSON == NULL) {
        ogs_error("OpenAPI_additional_ue_info_convertToJSON() failed [ncgi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_additional_ue_info_convertToJSON() failed [ncgi]");
        goto end;
    }
    }

    if (additional_ue_info->tai) {
    cJSON *tai_local_JSON = OpenAPI_tai_convertToJSON(additional_ue_info->tai);
    if (tai_local_JSON == NULL) {
        ogs_error("OpenAPI_additional_ue_info_convertToJSON() failed [tai]");
        goto end;
    }
    cJSON_AddItemToObject(item, "tai", tai_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_additional_ue_info_convertToJSON() failed [tai]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_additional_ue_info_t *OpenAPI_additional_ue_info_parseFromJSON(cJSON *additional_ue_infoJSON)
{
    OpenAPI_additional_ue_info_t *additional_ue_info_local_var = NULL;
    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(additional_ue_infoJSON, "ncgi");

    OpenAPI_ncgi_t *ncgi_local_nonprim = NULL;
    if (ncgi) {
    ncgi_local_nonprim = OpenAPI_ncgi_parseFromJSON(ncgi);
    }

    cJSON *tai = cJSON_GetObjectItemCaseSensitive(additional_ue_infoJSON, "tai");

    OpenAPI_tai_t *tai_local_nonprim = NULL;
    if (tai) {
    tai_local_nonprim = OpenAPI_tai_parseFromJSON(tai);
    }

    additional_ue_info_local_var = OpenAPI_additional_ue_info_create (
        ncgi ? ncgi_local_nonprim : NULL,
        tai ? tai_local_nonprim : NULL
    );

    return additional_ue_info_local_var;
end:
    return NULL;
}

OpenAPI_additional_ue_info_t *OpenAPI_additional_ue_info_copy(OpenAPI_additional_ue_info_t *dst, OpenAPI_additional_ue_info_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_additional_ue_info_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_additional_ue_info_convertToJSON() failed");
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

    OpenAPI_additional_ue_info_free(dst);
    dst = OpenAPI_additional_ue_info_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

