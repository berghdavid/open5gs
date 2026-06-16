
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "related_ue.h"

OpenAPI_related_ue_t *OpenAPI_related_ue_create(
    char *applicationlayer_id,
    OpenAPI_related_ue_type_t *related_ue_type
)
{
    OpenAPI_related_ue_t *related_ue_local_var = ogs_malloc(sizeof(OpenAPI_related_ue_t));
    ogs_assert(related_ue_local_var);

    related_ue_local_var->applicationlayer_id = applicationlayer_id;
    related_ue_local_var->related_ue_type = related_ue_type;

    return related_ue_local_var;
}

void OpenAPI_related_ue_free(OpenAPI_related_ue_t *related_ue)
{
    if (NULL == related_ue) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(related_ue->applicationlayer_id);
    OpenAPI_related_ue_type_free(related_ue->related_ue_type);
    ogs_free(related_ue);
}

cJSON *OpenAPI_related_ue_convertToJSON(OpenAPI_related_ue_t *related_ue)
{
    cJSON *item = NULL;

    if (related_ue == NULL) {
        ogs_error("OpenAPI_related_ue_convertToJSON() failed [RelatedUe]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddStringToObject(item, "applicationlayerId", related_ue->applicationlayer_id) == NULL) {
        ogs_error("OpenAPI_related_ue_convertToJSON() failed [applicationlayer_id]");
        goto end;
    }

    cJSON *related_ue_type_local_JSON = OpenAPI_related_ue_type_convertToJSON(related_ue->related_ue_type);
    if (related_ue_type_local_JSON == NULL) {
        ogs_error("OpenAPI_related_ue_convertToJSON() failed [related_ue_type]");
        goto end;
    }
    cJSON_AddItemToObject(item, "relatedUeType", related_ue_type_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_related_ue_convertToJSON() failed [related_ue_type]");
        goto end;
    }

end:
    return item;
}

OpenAPI_related_ue_t *OpenAPI_related_ue_parseFromJSON(cJSON *related_ueJSON)
{
    OpenAPI_related_ue_t *related_ue_local_var = NULL;
    cJSON *applicationlayer_id = cJSON_GetObjectItemCaseSensitive(related_ueJSON, "applicationlayerId");
    if (!applicationlayer_id) {
        ogs_error("OpenAPI_related_ue_parseFromJSON() failed [applicationlayer_id]");
        goto end;
    }

    if (!cJSON_IsString(applicationlayer_id)) {
        ogs_error("OpenAPI_related_ue_parseFromJSON() failed [applicationlayer_id]");
        goto end;
    }

    cJSON *related_ue_type = cJSON_GetObjectItemCaseSensitive(related_ueJSON, "relatedUeType");
    if (!related_ue_type) {
        ogs_error("OpenAPI_related_ue_parseFromJSON() failed [related_ue_type]");
        goto end;
    }

    OpenAPI_related_ue_type_t *related_ue_type_local_nonprim = NULL;
    related_ue_type_local_nonprim = OpenAPI_related_ue_type_parseFromJSON(related_ue_type);

    related_ue_local_var = OpenAPI_related_ue_create (
        ogs_strdup(applicationlayer_id->valuestring),
        related_ue_type_local_nonprim
    );

    return related_ue_local_var;
end:
    return NULL;
}

OpenAPI_related_ue_t *OpenAPI_related_ue_copy(OpenAPI_related_ue_t *dst, OpenAPI_related_ue_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_related_ue_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_related_ue_convertToJSON() failed");
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

    OpenAPI_related_ue_free(dst);
    dst = OpenAPI_related_ue_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

