
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "related_ue_type.h"

OpenAPI_related_ue_type_t *OpenAPI_related_ue_type_create(
)
{
    OpenAPI_related_ue_type_t *related_ue_type_local_var = ogs_malloc(sizeof(OpenAPI_related_ue_type_t));
    ogs_assert(related_ue_type_local_var);


    return related_ue_type_local_var;
}

void OpenAPI_related_ue_type_free(OpenAPI_related_ue_type_t *related_ue_type)
{
    if (NULL == related_ue_type) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(related_ue_type);
}

cJSON *OpenAPI_related_ue_type_convertToJSON(OpenAPI_related_ue_type_t *related_ue_type)
{
    cJSON *item = NULL;

    if (related_ue_type == NULL) {
        ogs_error("OpenAPI_related_ue_type_convertToJSON() failed [RelatedUeType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_related_ue_type_t *OpenAPI_related_ue_type_parseFromJSON(cJSON *related_ue_typeJSON)
{
    OpenAPI_related_ue_type_t *related_ue_type_local_var = NULL;
    related_ue_type_local_var = OpenAPI_related_ue_type_create (
    );

    return related_ue_type_local_var;
end:
    return NULL;
}

OpenAPI_related_ue_type_t *OpenAPI_related_ue_type_copy(OpenAPI_related_ue_type_t *dst, OpenAPI_related_ue_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_related_ue_type_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_related_ue_type_convertToJSON() failed");
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

    OpenAPI_related_ue_type_free(dst);
    dst = OpenAPI_related_ue_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

