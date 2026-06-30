
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trigger_type.h"

OpenAPI_trigger_type_t *OpenAPI_trigger_type_create(
)
{
    OpenAPI_trigger_type_t *trigger_type_local_var = ogs_malloc(sizeof(OpenAPI_trigger_type_t));
    log_assert(trigger_type_local_var);


    return trigger_type_local_var;
}

void OpenAPI_trigger_type_free(OpenAPI_trigger_type_t *trigger_type)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == trigger_type) {
        return;
    }
    ogs_free(trigger_type);
}

cJSON *OpenAPI_trigger_type_convertToJSON(OpenAPI_trigger_type_t *trigger_type)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (trigger_type == NULL) {
        log_error("OpenAPI_trigger_type_convertToJSON() failed [TriggerType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_trigger_type_t *OpenAPI_trigger_type_parseFromJSON(cJSON *trigger_typeJSON)
{
    OpenAPI_trigger_type_t *trigger_type_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    trigger_type_local_var = OpenAPI_trigger_type_create (
    );

    return trigger_type_local_var;
end:
    return NULL;
}

OpenAPI_trigger_type_t *OpenAPI_trigger_type_copy(OpenAPI_trigger_type_t *dst, OpenAPI_trigger_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_trigger_type_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_trigger_type_convertToJSON() failed");
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

    OpenAPI_trigger_type_free(dst);
    dst = OpenAPI_trigger_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

