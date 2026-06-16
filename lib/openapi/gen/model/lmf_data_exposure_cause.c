
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_cause.h"

OpenAPI_lmf_data_exposure_cause_t *OpenAPI_lmf_data_exposure_cause_create(
)
{
    OpenAPI_lmf_data_exposure_cause_t *lmf_data_exposure_cause_local_var = ogs_malloc(sizeof(OpenAPI_lmf_data_exposure_cause_t));
    ogs_assert(lmf_data_exposure_cause_local_var);


    return lmf_data_exposure_cause_local_var;
}

void OpenAPI_lmf_data_exposure_cause_free(OpenAPI_lmf_data_exposure_cause_t *lmf_data_exposure_cause)
{
    if (NULL == lmf_data_exposure_cause) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(lmf_data_exposure_cause);
}

cJSON *OpenAPI_lmf_data_exposure_cause_convertToJSON(OpenAPI_lmf_data_exposure_cause_t *lmf_data_exposure_cause)
{
    cJSON *item = NULL;

    if (lmf_data_exposure_cause == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_cause_convertToJSON() failed [LmfDataExposureCause]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_lmf_data_exposure_cause_t *OpenAPI_lmf_data_exposure_cause_parseFromJSON(cJSON *lmf_data_exposure_causeJSON)
{
    OpenAPI_lmf_data_exposure_cause_t *lmf_data_exposure_cause_local_var = NULL;
    lmf_data_exposure_cause_local_var = OpenAPI_lmf_data_exposure_cause_create (
    );

    return lmf_data_exposure_cause_local_var;
end:
    return NULL;
}

OpenAPI_lmf_data_exposure_cause_t *OpenAPI_lmf_data_exposure_cause_copy(OpenAPI_lmf_data_exposure_cause_t *dst, OpenAPI_lmf_data_exposure_cause_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_lmf_data_exposure_cause_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_lmf_data_exposure_cause_convertToJSON() failed");
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

    OpenAPI_lmf_data_exposure_cause_free(dst);
    dst = OpenAPI_lmf_data_exposure_cause_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

