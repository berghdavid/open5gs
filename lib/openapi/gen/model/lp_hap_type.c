
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lp_hap_type.h"

OpenAPI_lp_hap_type_t *OpenAPI_lp_hap_type_create(
)
{
    OpenAPI_lp_hap_type_t *lp_hap_type_local_var = ogs_malloc(sizeof(OpenAPI_lp_hap_type_t));
    ogs_assert(lp_hap_type_local_var);


    return lp_hap_type_local_var;
}

void OpenAPI_lp_hap_type_free(OpenAPI_lp_hap_type_t *lp_hap_type)
{
    if (NULL == lp_hap_type) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(lp_hap_type);
}

cJSON *OpenAPI_lp_hap_type_convertToJSON(OpenAPI_lp_hap_type_t *lp_hap_type)
{
    cJSON *item = NULL;

    if (lp_hap_type == NULL) {
        ogs_error("OpenAPI_lp_hap_type_convertToJSON() failed [LpHapType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_lp_hap_type_t *OpenAPI_lp_hap_type_parseFromJSON(cJSON *lp_hap_typeJSON)
{
    OpenAPI_lp_hap_type_t *lp_hap_type_local_var = NULL;
    lp_hap_type_local_var = OpenAPI_lp_hap_type_create (
    );

    return lp_hap_type_local_var;
end:
    return NULL;
}

OpenAPI_lp_hap_type_t *OpenAPI_lp_hap_type_copy(OpenAPI_lp_hap_type_t *dst, OpenAPI_lp_hap_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_lp_hap_type_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_lp_hap_type_convertToJSON() failed");
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

    OpenAPI_lp_hap_type_free(dst);
    dst = OpenAPI_lp_hap_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

