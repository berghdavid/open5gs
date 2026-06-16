
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_up_positioning_capabilities.h"

OpenAPI_ue_up_positioning_capabilities_t *OpenAPI_ue_up_positioning_capabilities_create(
)
{
    OpenAPI_ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_local_var = ogs_malloc(sizeof(OpenAPI_ue_up_positioning_capabilities_t));
    ogs_assert(ue_up_positioning_capabilities_local_var);


    return ue_up_positioning_capabilities_local_var;
}

void OpenAPI_ue_up_positioning_capabilities_free(OpenAPI_ue_up_positioning_capabilities_t *ue_up_positioning_capabilities)
{
    if (NULL == ue_up_positioning_capabilities) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(ue_up_positioning_capabilities);
}

cJSON *OpenAPI_ue_up_positioning_capabilities_convertToJSON(OpenAPI_ue_up_positioning_capabilities_t *ue_up_positioning_capabilities)
{
    cJSON *item = NULL;

    if (ue_up_positioning_capabilities == NULL) {
        ogs_error("OpenAPI_ue_up_positioning_capabilities_convertToJSON() failed [UeUpPositioningCapabilities]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_ue_up_positioning_capabilities_t *OpenAPI_ue_up_positioning_capabilities_parseFromJSON(cJSON *ue_up_positioning_capabilitiesJSON)
{
    OpenAPI_ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_local_var = NULL;
    ue_up_positioning_capabilities_local_var = OpenAPI_ue_up_positioning_capabilities_create (
    );

    return ue_up_positioning_capabilities_local_var;
end:
    return NULL;
}

OpenAPI_ue_up_positioning_capabilities_t *OpenAPI_ue_up_positioning_capabilities_copy(OpenAPI_ue_up_positioning_capabilities_t *dst, OpenAPI_ue_up_positioning_capabilities_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_ue_up_positioning_capabilities_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_ue_up_positioning_capabilities_convertToJSON() failed");
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

    OpenAPI_ue_up_positioning_capabilities_free(dst);
    dst = OpenAPI_ue_up_positioning_capabilities_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

