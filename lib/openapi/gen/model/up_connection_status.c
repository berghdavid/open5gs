
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_connection_status.h"

OpenAPI_up_connection_status_t *OpenAPI_up_connection_status_create(
)
{
    OpenAPI_up_connection_status_t *up_connection_status_local_var = ogs_malloc(sizeof(OpenAPI_up_connection_status_t));
    ogs_assert(up_connection_status_local_var);


    return up_connection_status_local_var;
}

void OpenAPI_up_connection_status_free(OpenAPI_up_connection_status_t *up_connection_status)
{
    if (NULL == up_connection_status) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(up_connection_status);
}

cJSON *OpenAPI_up_connection_status_convertToJSON(OpenAPI_up_connection_status_t *up_connection_status)
{
    cJSON *item = NULL;

    if (up_connection_status == NULL) {
        ogs_error("OpenAPI_up_connection_status_convertToJSON() failed [UpConnectionStatus]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_up_connection_status_t *OpenAPI_up_connection_status_parseFromJSON(cJSON *up_connection_statusJSON)
{
    OpenAPI_up_connection_status_t *up_connection_status_local_var = NULL;
    up_connection_status_local_var = OpenAPI_up_connection_status_create (
    );

    return up_connection_status_local_var;
end:
    return NULL;
}

OpenAPI_up_connection_status_t *OpenAPI_up_connection_status_copy(OpenAPI_up_connection_status_t *dst, OpenAPI_up_connection_status_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_up_connection_status_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_up_connection_status_convertToJSON() failed");
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

    OpenAPI_up_connection_status_free(dst);
    dst = OpenAPI_up_connection_status_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

