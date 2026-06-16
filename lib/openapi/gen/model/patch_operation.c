
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_operation.h"

OpenAPI_patch_operation_t *OpenAPI_patch_operation_create(
)
{
    OpenAPI_patch_operation_t *patch_operation_local_var = ogs_malloc(sizeof(OpenAPI_patch_operation_t));
    ogs_assert(patch_operation_local_var);


    return patch_operation_local_var;
}

void OpenAPI_patch_operation_free(OpenAPI_patch_operation_t *patch_operation)
{
    if (NULL == patch_operation) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(patch_operation);
}

cJSON *OpenAPI_patch_operation_convertToJSON(OpenAPI_patch_operation_t *patch_operation)
{
    cJSON *item = NULL;

    if (patch_operation == NULL) {
        ogs_error("OpenAPI_patch_operation_convertToJSON() failed [PatchOperation]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_patch_operation_t *OpenAPI_patch_operation_parseFromJSON(cJSON *patch_operationJSON)
{
    OpenAPI_patch_operation_t *patch_operation_local_var = NULL;
    patch_operation_local_var = OpenAPI_patch_operation_create (
    );

    return patch_operation_local_var;
end:
    return NULL;
}

OpenAPI_patch_operation_t *OpenAPI_patch_operation_copy(OpenAPI_patch_operation_t *dst, OpenAPI_patch_operation_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_patch_operation_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_patch_operation_convertToJSON() failed");
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

    OpenAPI_patch_operation_free(dst);
    dst = OpenAPI_patch_operation_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

