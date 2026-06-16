
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recur_type.h"

OpenAPI_recur_type_t *OpenAPI_recur_type_create(
)
{
    OpenAPI_recur_type_t *recur_type_local_var = ogs_malloc(sizeof(OpenAPI_recur_type_t));
    ogs_assert(recur_type_local_var);


    return recur_type_local_var;
}

void OpenAPI_recur_type_free(OpenAPI_recur_type_t *recur_type)
{
    if (NULL == recur_type) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(recur_type);
}

cJSON *OpenAPI_recur_type_convertToJSON(OpenAPI_recur_type_t *recur_type)
{
    cJSON *item = NULL;

    if (recur_type == NULL) {
        ogs_error("OpenAPI_recur_type_convertToJSON() failed [RecurType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_recur_type_t *OpenAPI_recur_type_parseFromJSON(cJSON *recur_typeJSON)
{
    OpenAPI_recur_type_t *recur_type_local_var = NULL;
    recur_type_local_var = OpenAPI_recur_type_create (
    );

    return recur_type_local_var;
end:
    return NULL;
}

OpenAPI_recur_type_t *OpenAPI_recur_type_copy(OpenAPI_recur_type_t *dst, OpenAPI_recur_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_recur_type_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_recur_type_convertToJSON() failed");
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

    OpenAPI_recur_type_free(dst);
    dst = OpenAPI_recur_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

