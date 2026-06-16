
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "indoor_outdoor_ind.h"

OpenAPI_indoor_outdoor_ind_t *OpenAPI_indoor_outdoor_ind_create(
)
{
    OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind_local_var = ogs_malloc(sizeof(OpenAPI_indoor_outdoor_ind_t));
    ogs_assert(indoor_outdoor_ind_local_var);


    return indoor_outdoor_ind_local_var;
}

void OpenAPI_indoor_outdoor_ind_free(OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind)
{
    if (NULL == indoor_outdoor_ind) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(indoor_outdoor_ind);
}

cJSON *OpenAPI_indoor_outdoor_ind_convertToJSON(OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind)
{
    cJSON *item = NULL;

    if (indoor_outdoor_ind == NULL) {
        ogs_error("OpenAPI_indoor_outdoor_ind_convertToJSON() failed [IndoorOutdoorInd]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_indoor_outdoor_ind_t *OpenAPI_indoor_outdoor_ind_parseFromJSON(cJSON *indoor_outdoor_indJSON)
{
    OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind_local_var = NULL;
    indoor_outdoor_ind_local_var = OpenAPI_indoor_outdoor_ind_create (
    );

    return indoor_outdoor_ind_local_var;
end:
    return NULL;
}

OpenAPI_indoor_outdoor_ind_t *OpenAPI_indoor_outdoor_ind_copy(OpenAPI_indoor_outdoor_ind_t *dst, OpenAPI_indoor_outdoor_ind_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_indoor_outdoor_ind_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_indoor_outdoor_ind_convertToJSON() failed");
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

    OpenAPI_indoor_outdoor_ind_free(dst);
    dst = OpenAPI_indoor_outdoor_ind_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

