
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_type.h"

OpenAPI_event_type_t *OpenAPI_event_type_create(
)
{
    OpenAPI_event_type_t *event_type_local_var = ogs_malloc(sizeof(OpenAPI_event_type_t));
    log_assert(event_type_local_var);


    return event_type_local_var;
}

void OpenAPI_event_type_free(OpenAPI_event_type_t *event_type)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == event_type) {
        return;
    }
    ogs_free(event_type);
}

cJSON *OpenAPI_event_type_convertToJSON(OpenAPI_event_type_t *event_type)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (event_type == NULL) {
        log_error("OpenAPI_event_type_convertToJSON() failed [EventType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_event_type_t *OpenAPI_event_type_parseFromJSON(cJSON *event_typeJSON)
{
    OpenAPI_event_type_t *event_type_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    event_type_local_var = OpenAPI_event_type_create (
    );

    return event_type_local_var;
end:
    return NULL;
}

OpenAPI_event_type_t *OpenAPI_event_type_copy(OpenAPI_event_type_t *dst, OpenAPI_event_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_event_type_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_event_type_convertToJSON() failed");
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

    OpenAPI_event_type_free(dst);
    dst = OpenAPI_event_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

