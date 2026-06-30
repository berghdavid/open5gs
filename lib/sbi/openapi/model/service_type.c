
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_type.h"

OpenAPI_service_type_t *OpenAPI_service_type_create(
)
{
    OpenAPI_service_type_t *service_type_local_var = ogs_malloc(sizeof(OpenAPI_service_type_t));
    log_assert(service_type_local_var);


    return service_type_local_var;
}

void OpenAPI_service_type_free(OpenAPI_service_type_t *service_type)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == service_type) {
        return;
    }
    ogs_free(service_type);
}

cJSON *OpenAPI_service_type_convertToJSON(OpenAPI_service_type_t *service_type)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (service_type == NULL) {
        log_error("OpenAPI_service_type_convertToJSON() failed [ServiceType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_service_type_t *OpenAPI_service_type_parseFromJSON(cJSON *service_typeJSON)
{
    OpenAPI_service_type_t *service_type_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    service_type_local_var = OpenAPI_service_type_create (
    );

    return service_type_local_var;
end:
    return NULL;
}

OpenAPI_service_type_t *OpenAPI_service_type_copy(OpenAPI_service_type_t *dst, OpenAPI_service_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_service_type_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_service_type_convertToJSON() failed");
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

    OpenAPI_service_type_free(dst);
    dst = OpenAPI_service_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

