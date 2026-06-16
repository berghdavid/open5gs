
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_type.h"

OpenAPI_nf_type_t *OpenAPI_nf_type_create(
)
{
    OpenAPI_nf_type_t *nf_type_local_var = ogs_malloc(sizeof(OpenAPI_nf_type_t));
    ogs_assert(nf_type_local_var);


    return nf_type_local_var;
}

void OpenAPI_nf_type_free(OpenAPI_nf_type_t *nf_type)
{
    if (NULL == nf_type) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(nf_type);
}

cJSON *OpenAPI_nf_type_convertToJSON(OpenAPI_nf_type_t *nf_type)
{
    cJSON *item = NULL;

    if (nf_type == NULL) {
        ogs_error("OpenAPI_nf_type_convertToJSON() failed [NFType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_nf_type_t *OpenAPI_nf_type_parseFromJSON(cJSON *nf_typeJSON)
{
    OpenAPI_nf_type_t *nf_type_local_var = NULL;
    nf_type_local_var = OpenAPI_nf_type_create (
    );

    return nf_type_local_var;
end:
    return NULL;
}

OpenAPI_nf_type_t *OpenAPI_nf_type_copy(OpenAPI_nf_type_t *dst, OpenAPI_nf_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_nf_type_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_nf_type_convertToJSON() failed");
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

    OpenAPI_nf_type_free(dst);
    dst = OpenAPI_nf_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

