
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_mode.h"

OpenAPI_positioning_mode_t *OpenAPI_positioning_mode_create(
)
{
    OpenAPI_positioning_mode_t *positioning_mode_local_var = ogs_malloc(sizeof(OpenAPI_positioning_mode_t));
    log_assert(positioning_mode_local_var);


    return positioning_mode_local_var;
}

void OpenAPI_positioning_mode_free(OpenAPI_positioning_mode_t *positioning_mode)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == positioning_mode) {
        return;
    }
    ogs_free(positioning_mode);
}

cJSON *OpenAPI_positioning_mode_convertToJSON(OpenAPI_positioning_mode_t *positioning_mode)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (positioning_mode == NULL) {
        log_error("OpenAPI_positioning_mode_convertToJSON() failed [PositioningMode]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_positioning_mode_t *OpenAPI_positioning_mode_parseFromJSON(cJSON *positioning_modeJSON)
{
    OpenAPI_positioning_mode_t *positioning_mode_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    positioning_mode_local_var = OpenAPI_positioning_mode_create (
    );

    return positioning_mode_local_var;
end:
    return NULL;
}

OpenAPI_positioning_mode_t *OpenAPI_positioning_mode_copy(OpenAPI_positioning_mode_t *dst, OpenAPI_positioning_mode_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_positioning_mode_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_positioning_mode_convertToJSON() failed");
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

    OpenAPI_positioning_mode_free(dst);
    dst = OpenAPI_positioning_mode_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

