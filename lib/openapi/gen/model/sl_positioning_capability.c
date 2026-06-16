
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sl_positioning_capability.h"

OpenAPI_sl_positioning_capability_t *OpenAPI_sl_positioning_capability_create(
)
{
    OpenAPI_sl_positioning_capability_t *sl_positioning_capability_local_var = ogs_malloc(sizeof(OpenAPI_sl_positioning_capability_t));
    ogs_assert(sl_positioning_capability_local_var);


    return sl_positioning_capability_local_var;
}

void OpenAPI_sl_positioning_capability_free(OpenAPI_sl_positioning_capability_t *sl_positioning_capability)
{
    if (NULL == sl_positioning_capability) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(sl_positioning_capability);
}

cJSON *OpenAPI_sl_positioning_capability_convertToJSON(OpenAPI_sl_positioning_capability_t *sl_positioning_capability)
{
    cJSON *item = NULL;

    if (sl_positioning_capability == NULL) {
        ogs_error("OpenAPI_sl_positioning_capability_convertToJSON() failed [SlPositioningCapability]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_sl_positioning_capability_t *OpenAPI_sl_positioning_capability_parseFromJSON(cJSON *sl_positioning_capabilityJSON)
{
    OpenAPI_sl_positioning_capability_t *sl_positioning_capability_local_var = NULL;
    sl_positioning_capability_local_var = OpenAPI_sl_positioning_capability_create (
    );

    return sl_positioning_capability_local_var;
end:
    return NULL;
}

OpenAPI_sl_positioning_capability_t *OpenAPI_sl_positioning_capability_copy(OpenAPI_sl_positioning_capability_t *dst, OpenAPI_sl_positioning_capability_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_sl_positioning_capability_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_sl_positioning_capability_convertToJSON() failed");
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

    OpenAPI_sl_positioning_capability_free(dst);
    dst = OpenAPI_sl_positioning_capability_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

