
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fix_type.h"

OpenAPI_fix_type_t *OpenAPI_fix_type_create(
)
{
    OpenAPI_fix_type_t *fix_type_local_var = ogs_malloc(sizeof(OpenAPI_fix_type_t));
    ogs_assert(fix_type_local_var);


    return fix_type_local_var;
}

void OpenAPI_fix_type_free(OpenAPI_fix_type_t *fix_type)
{
    if (NULL == fix_type) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(fix_type);
}

cJSON *OpenAPI_fix_type_convertToJSON(OpenAPI_fix_type_t *fix_type)
{
    cJSON *item = NULL;

    if (fix_type == NULL) {
        ogs_error("OpenAPI_fix_type_convertToJSON() failed [FixType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_fix_type_t *OpenAPI_fix_type_parseFromJSON(cJSON *fix_typeJSON)
{
    OpenAPI_fix_type_t *fix_type_local_var = NULL;
    fix_type_local_var = OpenAPI_fix_type_create (
    );

    return fix_type_local_var;
end:
    return NULL;
}

OpenAPI_fix_type_t *OpenAPI_fix_type_copy(OpenAPI_fix_type_t *dst, OpenAPI_fix_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_fix_type_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_fix_type_convertToJSON() failed");
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

    OpenAPI_fix_type_free(dst);
    dst = OpenAPI_fix_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

