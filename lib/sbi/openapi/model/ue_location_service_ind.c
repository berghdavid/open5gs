
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_location_service_ind.h"

OpenAPI_ue_location_service_ind_t *OpenAPI_ue_location_service_ind_create(
)
{
    OpenAPI_ue_location_service_ind_t *ue_location_service_ind_local_var = ogs_malloc(sizeof(OpenAPI_ue_location_service_ind_t));
    log_assert(ue_location_service_ind_local_var);


    return ue_location_service_ind_local_var;
}

void OpenAPI_ue_location_service_ind_free(OpenAPI_ue_location_service_ind_t *ue_location_service_ind)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == ue_location_service_ind) {
        return;
    }
    ogs_free(ue_location_service_ind);
}

cJSON *OpenAPI_ue_location_service_ind_convertToJSON(OpenAPI_ue_location_service_ind_t *ue_location_service_ind)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (ue_location_service_ind == NULL) {
        log_error("OpenAPI_ue_location_service_ind_convertToJSON() failed [UeLocationServiceInd]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_ue_location_service_ind_t *OpenAPI_ue_location_service_ind_parseFromJSON(cJSON *ue_location_service_indJSON)
{
    OpenAPI_ue_location_service_ind_t *ue_location_service_ind_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    ue_location_service_ind_local_var = OpenAPI_ue_location_service_ind_create (
    );

    return ue_location_service_ind_local_var;
end:
    return NULL;
}

OpenAPI_ue_location_service_ind_t *OpenAPI_ue_location_service_ind_copy(OpenAPI_ue_location_service_ind_t *dst, OpenAPI_ue_location_service_ind_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_ue_location_service_ind_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_ue_location_service_ind_convertToJSON() failed");
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

    OpenAPI_ue_location_service_ind_free(dst);
    dst = OpenAPI_ue_location_service_ind_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

