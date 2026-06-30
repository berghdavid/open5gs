
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ptw_parameters_1.h"

OpenAPI_ptw_parameters_1_t *OpenAPI_ptw_parameters_1_create(
    OpenAPI_operation_mode_e operation_mode,
    char *ptw_value
)
{
    OpenAPI_ptw_parameters_1_t *ptw_parameters_1_local_var = ogs_malloc(sizeof(OpenAPI_ptw_parameters_1_t));
    log_assert(ptw_parameters_1_local_var);

    ptw_parameters_1_local_var->operation_mode = operation_mode;
    ptw_parameters_1_local_var->ptw_value = ptw_value;

    return ptw_parameters_1_local_var;
}

void OpenAPI_ptw_parameters_1_free(OpenAPI_ptw_parameters_1_t *ptw_parameters_1)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == ptw_parameters_1) {
        return;
    }
    if (ptw_parameters_1->ptw_value) {
        ogs_free(ptw_parameters_1->ptw_value);
        ptw_parameters_1->ptw_value = NULL;
    }
    ogs_free(ptw_parameters_1);
}

cJSON *OpenAPI_ptw_parameters_1_convertToJSON(OpenAPI_ptw_parameters_1_t *ptw_parameters_1)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (ptw_parameters_1 == NULL) {
        log_error("OpenAPI_ptw_parameters_1_convertToJSON() failed [PtwParameters_1]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (ptw_parameters_1->operation_mode == OpenAPI_operation_mode_NULL) {
        log_error("OpenAPI_ptw_parameters_1_convertToJSON() failed [operation_mode]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "operationMode", OpenAPI_operation_mode_ToString(ptw_parameters_1->operation_mode)) == NULL) {
        log_error("OpenAPI_ptw_parameters_1_convertToJSON() failed [operation_mode]");
        goto end;
    }

    if (!ptw_parameters_1->ptw_value) {
        log_error("OpenAPI_ptw_parameters_1_convertToJSON() failed [ptw_value]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "ptwValue", ptw_parameters_1->ptw_value) == NULL) {
        log_error("OpenAPI_ptw_parameters_1_convertToJSON() failed [ptw_value]");
        goto end;
    }

end:
    return item;
}

OpenAPI_ptw_parameters_1_t *OpenAPI_ptw_parameters_1_parseFromJSON(cJSON *ptw_parameters_1JSON)
{
    OpenAPI_ptw_parameters_1_t *ptw_parameters_1_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *operation_mode = NULL;
    OpenAPI_operation_mode_e operation_modeVariable = 0;
    cJSON *ptw_value = NULL;
    operation_mode = cJSON_GetObjectItemCaseSensitive(ptw_parameters_1JSON, "operationMode");
    if (!operation_mode) {
        log_error("OpenAPI_ptw_parameters_1_parseFromJSON() failed [operation_mode]");
        goto end;
    }
    if (!cJSON_IsString(operation_mode)) {
        log_error("OpenAPI_ptw_parameters_1_parseFromJSON() failed [operation_mode]");
        goto end;
    }
    operation_modeVariable = OpenAPI_operation_mode_FromString(operation_mode->valuestring);

    ptw_value = cJSON_GetObjectItemCaseSensitive(ptw_parameters_1JSON, "ptwValue");
    if (!ptw_value) {
        log_error("OpenAPI_ptw_parameters_1_parseFromJSON() failed [ptw_value]");
        goto end;
    }
    if (!cJSON_IsString(ptw_value)) {
        log_error("OpenAPI_ptw_parameters_1_parseFromJSON() failed [ptw_value]");
        goto end;
    }

    ptw_parameters_1_local_var = OpenAPI_ptw_parameters_1_create (
        operation_modeVariable,
        ogs_strdup(ptw_value->valuestring)
    );

    return ptw_parameters_1_local_var;
end:
    return NULL;
}

OpenAPI_ptw_parameters_1_t *OpenAPI_ptw_parameters_1_copy(OpenAPI_ptw_parameters_1_t *dst, OpenAPI_ptw_parameters_1_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_ptw_parameters_1_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_ptw_parameters_1_convertToJSON() failed");
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

    OpenAPI_ptw_parameters_1_free(dst);
    dst = OpenAPI_ptw_parameters_1_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

