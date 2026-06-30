
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ng_ap_cause.h"

OpenAPI_ng_ap_cause_t *OpenAPI_ng_ap_cause_create(
    int group,
    int value
)
{
    OpenAPI_ng_ap_cause_t *ng_ap_cause_local_var = ogs_malloc(sizeof(OpenAPI_ng_ap_cause_t));
    log_assert(ng_ap_cause_local_var);

    ng_ap_cause_local_var->group = group;
    ng_ap_cause_local_var->value = value;

    return ng_ap_cause_local_var;
}

void OpenAPI_ng_ap_cause_free(OpenAPI_ng_ap_cause_t *ng_ap_cause)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == ng_ap_cause) {
        return;
    }
    ogs_free(ng_ap_cause);
}

cJSON *OpenAPI_ng_ap_cause_convertToJSON(OpenAPI_ng_ap_cause_t *ng_ap_cause)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (ng_ap_cause == NULL) {
        log_error("OpenAPI_ng_ap_cause_convertToJSON() failed [NgApCause]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddNumberToObject(item, "group", ng_ap_cause->group) == NULL) {
        log_error("OpenAPI_ng_ap_cause_convertToJSON() failed [group]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "value", ng_ap_cause->value) == NULL) {
        log_error("OpenAPI_ng_ap_cause_convertToJSON() failed [value]");
        goto end;
    }

end:
    return item;
}

OpenAPI_ng_ap_cause_t *OpenAPI_ng_ap_cause_parseFromJSON(cJSON *ng_ap_causeJSON)
{
    OpenAPI_ng_ap_cause_t *ng_ap_cause_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *group = NULL;
    cJSON *value = NULL;
    group = cJSON_GetObjectItemCaseSensitive(ng_ap_causeJSON, "group");
    if (!group) {
        log_error("OpenAPI_ng_ap_cause_parseFromJSON() failed [group]");
        goto end;
    }
    if (!cJSON_IsNumber(group)) {
        log_error("OpenAPI_ng_ap_cause_parseFromJSON() failed [group]");
        goto end;
    }

    value = cJSON_GetObjectItemCaseSensitive(ng_ap_causeJSON, "value");
    if (!value) {
        log_error("OpenAPI_ng_ap_cause_parseFromJSON() failed [value]");
        goto end;
    }
    if (!cJSON_IsNumber(value)) {
        log_error("OpenAPI_ng_ap_cause_parseFromJSON() failed [value]");
        goto end;
    }

    ng_ap_cause_local_var = OpenAPI_ng_ap_cause_create (
        
        group->valuedouble,
        
        value->valuedouble
    );

    return ng_ap_cause_local_var;
end:
    return NULL;
}

OpenAPI_ng_ap_cause_t *OpenAPI_ng_ap_cause_copy(OpenAPI_ng_ap_cause_t *dst, OpenAPI_ng_ap_cause_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_ng_ap_cause_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_ng_ap_cause_convertToJSON() failed");
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

    OpenAPI_ng_ap_cause_free(dst);
    dst = OpenAPI_ng_ap_cause_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

