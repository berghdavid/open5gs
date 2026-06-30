
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partial_record_method.h"

OpenAPI_partial_record_method_t *OpenAPI_partial_record_method_create(
)
{
    OpenAPI_partial_record_method_t *partial_record_method_local_var = ogs_malloc(sizeof(OpenAPI_partial_record_method_t));
    log_assert(partial_record_method_local_var);


    return partial_record_method_local_var;
}

void OpenAPI_partial_record_method_free(OpenAPI_partial_record_method_t *partial_record_method)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == partial_record_method) {
        return;
    }
    ogs_free(partial_record_method);
}

cJSON *OpenAPI_partial_record_method_convertToJSON(OpenAPI_partial_record_method_t *partial_record_method)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (partial_record_method == NULL) {
        log_error("OpenAPI_partial_record_method_convertToJSON() failed [PartialRecordMethod]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_partial_record_method_t *OpenAPI_partial_record_method_parseFromJSON(cJSON *partial_record_methodJSON)
{
    OpenAPI_partial_record_method_t *partial_record_method_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    partial_record_method_local_var = OpenAPI_partial_record_method_create (
    );

    return partial_record_method_local_var;
end:
    return NULL;
}

OpenAPI_partial_record_method_t *OpenAPI_partial_record_method_copy(OpenAPI_partial_record_method_t *dst, OpenAPI_partial_record_method_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_partial_record_method_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_partial_record_method_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        log_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        log_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_partial_record_method_free(dst);
    dst = OpenAPI_partial_record_method_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

