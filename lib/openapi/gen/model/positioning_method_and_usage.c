
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_method_and_usage.h"

OpenAPI_positioning_method_and_usage_t *OpenAPI_positioning_method_and_usage_create(
    OpenAPI_positioning_method_t *method,
    OpenAPI_positioning_mode_t *mode,
    OpenAPI_usage_t *usage,
    bool is_method_code,
    int method_code
)
{
    OpenAPI_positioning_method_and_usage_t *positioning_method_and_usage_local_var = ogs_malloc(sizeof(OpenAPI_positioning_method_and_usage_t));
    ogs_assert(positioning_method_and_usage_local_var);

    positioning_method_and_usage_local_var->method = method;
    positioning_method_and_usage_local_var->mode = mode;
    positioning_method_and_usage_local_var->usage = usage;
    positioning_method_and_usage_local_var->is_method_code = is_method_code;
    positioning_method_and_usage_local_var->method_code = method_code;

    return positioning_method_and_usage_local_var;
}

void OpenAPI_positioning_method_and_usage_free(OpenAPI_positioning_method_and_usage_t *positioning_method_and_usage)
{
    if (NULL == positioning_method_and_usage) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_positioning_method_free(positioning_method_and_usage->method);
    OpenAPI_positioning_mode_free(positioning_method_and_usage->mode);
    OpenAPI_usage_free(positioning_method_and_usage->usage);
    ogs_free(positioning_method_and_usage);
}

cJSON *OpenAPI_positioning_method_and_usage_convertToJSON(OpenAPI_positioning_method_and_usage_t *positioning_method_and_usage)
{
    cJSON *item = NULL;

    if (positioning_method_and_usage == NULL) {
        ogs_error("OpenAPI_positioning_method_and_usage_convertToJSON() failed [PositioningMethodAndUsage]");
        return NULL;
    }

    item = cJSON_CreateObject();
    cJSON *method_local_JSON = OpenAPI_positioning_method_convertToJSON(positioning_method_and_usage->method);
    if (method_local_JSON == NULL) {
        ogs_error("OpenAPI_positioning_method_and_usage_convertToJSON() failed [method]");
        goto end;
    }
    cJSON_AddItemToObject(item, "method", method_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_positioning_method_and_usage_convertToJSON() failed [method]");
        goto end;
    }

    cJSON *mode_local_JSON = OpenAPI_positioning_mode_convertToJSON(positioning_method_and_usage->mode);
    if (mode_local_JSON == NULL) {
        ogs_error("OpenAPI_positioning_method_and_usage_convertToJSON() failed [mode]");
        goto end;
    }
    cJSON_AddItemToObject(item, "mode", mode_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_positioning_method_and_usage_convertToJSON() failed [mode]");
        goto end;
    }

    cJSON *usage_local_JSON = OpenAPI_usage_convertToJSON(positioning_method_and_usage->usage);
    if (usage_local_JSON == NULL) {
        ogs_error("OpenAPI_positioning_method_and_usage_convertToJSON() failed [usage]");
        goto end;
    }
    cJSON_AddItemToObject(item, "usage", usage_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_positioning_method_and_usage_convertToJSON() failed [usage]");
        goto end;
    }

    if (positioning_method_and_usage->is_method_code) {
    if (cJSON_AddNumberToObject(item, "methodCode", positioning_method_and_usage->method_code) == NULL) {
        ogs_error("OpenAPI_positioning_method_and_usage_convertToJSON() failed [method_code]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_positioning_method_and_usage_t *OpenAPI_positioning_method_and_usage_parseFromJSON(cJSON *positioning_method_and_usageJSON)
{
    OpenAPI_positioning_method_and_usage_t *positioning_method_and_usage_local_var = NULL;
    cJSON *method = cJSON_GetObjectItemCaseSensitive(positioning_method_and_usageJSON, "method");
    if (!method) {
        ogs_error("OpenAPI_positioning_method_and_usage_parseFromJSON() failed [method]");
        goto end;
    }

    OpenAPI_positioning_method_t *method_local_nonprim = NULL;
    method_local_nonprim = OpenAPI_positioning_method_parseFromJSON(method);

    cJSON *mode = cJSON_GetObjectItemCaseSensitive(positioning_method_and_usageJSON, "mode");
    if (!mode) {
        ogs_error("OpenAPI_positioning_method_and_usage_parseFromJSON() failed [mode]");
        goto end;
    }

    OpenAPI_positioning_mode_t *mode_local_nonprim = NULL;
    mode_local_nonprim = OpenAPI_positioning_mode_parseFromJSON(mode);

    cJSON *usage = cJSON_GetObjectItemCaseSensitive(positioning_method_and_usageJSON, "usage");
    if (!usage) {
        ogs_error("OpenAPI_positioning_method_and_usage_parseFromJSON() failed [usage]");
        goto end;
    }

    OpenAPI_usage_t *usage_local_nonprim = NULL;
    usage_local_nonprim = OpenAPI_usage_parseFromJSON(usage);

    cJSON *method_code = cJSON_GetObjectItemCaseSensitive(positioning_method_and_usageJSON, "methodCode");

    if (method_code) {
    if (!cJSON_IsNumber(method_code)) {
        ogs_error("OpenAPI_positioning_method_and_usage_parseFromJSON() failed [method_code]");
        goto end;
    }
    }

    positioning_method_and_usage_local_var = OpenAPI_positioning_method_and_usage_create (
        method_local_nonprim,
        mode_local_nonprim,
        usage_local_nonprim,
        method_code ? true : false,
        method_code ? method_code->valuedouble : 0
    );

    return positioning_method_and_usage_local_var;
end:
    return NULL;
}

OpenAPI_positioning_method_and_usage_t *OpenAPI_positioning_method_and_usage_copy(OpenAPI_positioning_method_and_usage_t *dst, OpenAPI_positioning_method_and_usage_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_positioning_method_and_usage_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_positioning_method_and_usage_convertToJSON() failed");
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

    OpenAPI_positioning_method_and_usage_free(dst);
    dst = OpenAPI_positioning_method_and_usage_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

