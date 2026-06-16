
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "los_nlos_measure_ind.h"

OpenAPI_los_nlos_measure_ind_t *OpenAPI_los_nlos_measure_ind_create(
)
{
    OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind_local_var = ogs_malloc(sizeof(OpenAPI_los_nlos_measure_ind_t));
    ogs_assert(los_nlos_measure_ind_local_var);


    return los_nlos_measure_ind_local_var;
}

void OpenAPI_los_nlos_measure_ind_free(OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind)
{
    if (NULL == los_nlos_measure_ind) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(los_nlos_measure_ind);
}

cJSON *OpenAPI_los_nlos_measure_ind_convertToJSON(OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind)
{
    cJSON *item = NULL;

    if (los_nlos_measure_ind == NULL) {
        ogs_error("OpenAPI_los_nlos_measure_ind_convertToJSON() failed [LosNlosMeasureInd]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_los_nlos_measure_ind_t *OpenAPI_los_nlos_measure_ind_parseFromJSON(cJSON *los_nlos_measure_indJSON)
{
    OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind_local_var = NULL;
    los_nlos_measure_ind_local_var = OpenAPI_los_nlos_measure_ind_create (
    );

    return los_nlos_measure_ind_local_var;
end:
    return NULL;
}

OpenAPI_los_nlos_measure_ind_t *OpenAPI_los_nlos_measure_ind_copy(OpenAPI_los_nlos_measure_ind_t *dst, OpenAPI_los_nlos_measure_ind_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_los_nlos_measure_ind_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_los_nlos_measure_ind_convertToJSON() failed");
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

    OpenAPI_los_nlos_measure_ind_free(dst);
    dst = OpenAPI_los_nlos_measure_ind_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

