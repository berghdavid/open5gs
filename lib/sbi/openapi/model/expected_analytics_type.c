
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "expected_analytics_type.h"

OpenAPI_expected_analytics_type_t *OpenAPI_expected_analytics_type_create(
)
{
    OpenAPI_expected_analytics_type_t *expected_analytics_type_local_var = ogs_malloc(sizeof(OpenAPI_expected_analytics_type_t));
    log_assert(expected_analytics_type_local_var);


    return expected_analytics_type_local_var;
}

void OpenAPI_expected_analytics_type_free(OpenAPI_expected_analytics_type_t *expected_analytics_type)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == expected_analytics_type) {
        return;
    }
    ogs_free(expected_analytics_type);
}

cJSON *OpenAPI_expected_analytics_type_convertToJSON(OpenAPI_expected_analytics_type_t *expected_analytics_type)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (expected_analytics_type == NULL) {
        log_error("OpenAPI_expected_analytics_type_convertToJSON() failed [ExpectedAnalyticsType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_expected_analytics_type_t *OpenAPI_expected_analytics_type_parseFromJSON(cJSON *expected_analytics_typeJSON)
{
    OpenAPI_expected_analytics_type_t *expected_analytics_type_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    expected_analytics_type_local_var = OpenAPI_expected_analytics_type_create (
    );

    return expected_analytics_type_local_var;
end:
    return NULL;
}

OpenAPI_expected_analytics_type_t *OpenAPI_expected_analytics_type_copy(OpenAPI_expected_analytics_type_t *dst, OpenAPI_expected_analytics_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_expected_analytics_type_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_expected_analytics_type_convertToJSON() failed");
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

    OpenAPI_expected_analytics_type_free(dst);
    dst = OpenAPI_expected_analytics_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

