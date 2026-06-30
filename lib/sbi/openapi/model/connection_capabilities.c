
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "connection_capabilities.h"

OpenAPI_connection_capabilities_t *OpenAPI_connection_capabilities_create(
)
{
    OpenAPI_connection_capabilities_t *connection_capabilities_local_var = ogs_malloc(sizeof(OpenAPI_connection_capabilities_t));
    log_assert(connection_capabilities_local_var);


    return connection_capabilities_local_var;
}

void OpenAPI_connection_capabilities_free(OpenAPI_connection_capabilities_t *connection_capabilities)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == connection_capabilities) {
        return;
    }
    ogs_free(connection_capabilities);
}

cJSON *OpenAPI_connection_capabilities_convertToJSON(OpenAPI_connection_capabilities_t *connection_capabilities)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (connection_capabilities == NULL) {
        log_error("OpenAPI_connection_capabilities_convertToJSON() failed [ConnectionCapabilities]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_connection_capabilities_t *OpenAPI_connection_capabilities_parseFromJSON(cJSON *connection_capabilitiesJSON)
{
    OpenAPI_connection_capabilities_t *connection_capabilities_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    connection_capabilities_local_var = OpenAPI_connection_capabilities_create (
    );

    return connection_capabilities_local_var;
end:
    return NULL;
}

OpenAPI_connection_capabilities_t *OpenAPI_connection_capabilities_copy(OpenAPI_connection_capabilities_t *dst, OpenAPI_connection_capabilities_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_connection_capabilities_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_connection_capabilities_convertToJSON() failed");
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

    OpenAPI_connection_capabilities_free(dst);
    dst = OpenAPI_connection_capabilities_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

