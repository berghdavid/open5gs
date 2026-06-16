
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_up_connection_ind.h"

OpenAPI_lcs_up_connection_ind_t *OpenAPI_lcs_up_connection_ind_create(
)
{
    OpenAPI_lcs_up_connection_ind_t *lcs_up_connection_ind_local_var = ogs_malloc(sizeof(OpenAPI_lcs_up_connection_ind_t));
    ogs_assert(lcs_up_connection_ind_local_var);


    return lcs_up_connection_ind_local_var;
}

void OpenAPI_lcs_up_connection_ind_free(OpenAPI_lcs_up_connection_ind_t *lcs_up_connection_ind)
{
    if (NULL == lcs_up_connection_ind) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(lcs_up_connection_ind);
}

cJSON *OpenAPI_lcs_up_connection_ind_convertToJSON(OpenAPI_lcs_up_connection_ind_t *lcs_up_connection_ind)
{
    cJSON *item = NULL;

    if (lcs_up_connection_ind == NULL) {
        ogs_error("OpenAPI_lcs_up_connection_ind_convertToJSON() failed [LcsUpConnectionInd]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_lcs_up_connection_ind_t *OpenAPI_lcs_up_connection_ind_parseFromJSON(cJSON *lcs_up_connection_indJSON)
{
    OpenAPI_lcs_up_connection_ind_t *lcs_up_connection_ind_local_var = NULL;
    lcs_up_connection_ind_local_var = OpenAPI_lcs_up_connection_ind_create (
    );

    return lcs_up_connection_ind_local_var;
end:
    return NULL;
}

OpenAPI_lcs_up_connection_ind_t *OpenAPI_lcs_up_connection_ind_copy(OpenAPI_lcs_up_connection_ind_t *dst, OpenAPI_lcs_up_connection_ind_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_lcs_up_connection_ind_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_lcs_up_connection_ind_convertToJSON() failed");
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

    OpenAPI_lcs_up_connection_ind_free(dst);
    dst = OpenAPI_lcs_up_connection_ind_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

