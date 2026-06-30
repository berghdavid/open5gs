
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ambr_1.h"

OpenAPI_ambr_1_t *OpenAPI_ambr_1_create(
    char *uplink,
    char *downlink
)
{
    OpenAPI_ambr_1_t *ambr_1_local_var = ogs_malloc(sizeof(OpenAPI_ambr_1_t));
    log_assert(ambr_1_local_var);

    ambr_1_local_var->uplink = uplink;
    ambr_1_local_var->downlink = downlink;

    return ambr_1_local_var;
}

void OpenAPI_ambr_1_free(OpenAPI_ambr_1_t *ambr_1)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == ambr_1) {
        return;
    }
    if (ambr_1->uplink) {
        ogs_free(ambr_1->uplink);
        ambr_1->uplink = NULL;
    }
    if (ambr_1->downlink) {
        ogs_free(ambr_1->downlink);
        ambr_1->downlink = NULL;
    }
    ogs_free(ambr_1);
}

cJSON *OpenAPI_ambr_1_convertToJSON(OpenAPI_ambr_1_t *ambr_1)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (ambr_1 == NULL) {
        log_error("OpenAPI_ambr_1_convertToJSON() failed [Ambr_1]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!ambr_1->uplink) {
        log_error("OpenAPI_ambr_1_convertToJSON() failed [uplink]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "uplink", ambr_1->uplink) == NULL) {
        log_error("OpenAPI_ambr_1_convertToJSON() failed [uplink]");
        goto end;
    }

    if (!ambr_1->downlink) {
        log_error("OpenAPI_ambr_1_convertToJSON() failed [downlink]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "downlink", ambr_1->downlink) == NULL) {
        log_error("OpenAPI_ambr_1_convertToJSON() failed [downlink]");
        goto end;
    }

end:
    return item;
}

OpenAPI_ambr_1_t *OpenAPI_ambr_1_parseFromJSON(cJSON *ambr_1JSON)
{
    OpenAPI_ambr_1_t *ambr_1_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *uplink = NULL;
    cJSON *downlink = NULL;
    uplink = cJSON_GetObjectItemCaseSensitive(ambr_1JSON, "uplink");
    if (!uplink) {
        log_error("OpenAPI_ambr_1_parseFromJSON() failed [uplink]");
        goto end;
    }
    if (!cJSON_IsString(uplink)) {
        log_error("OpenAPI_ambr_1_parseFromJSON() failed [uplink]");
        goto end;
    }

    downlink = cJSON_GetObjectItemCaseSensitive(ambr_1JSON, "downlink");
    if (!downlink) {
        log_error("OpenAPI_ambr_1_parseFromJSON() failed [downlink]");
        goto end;
    }
    if (!cJSON_IsString(downlink)) {
        log_error("OpenAPI_ambr_1_parseFromJSON() failed [downlink]");
        goto end;
    }

    ambr_1_local_var = OpenAPI_ambr_1_create (
        ogs_strdup(uplink->valuestring),
        ogs_strdup(downlink->valuestring)
    );

    return ambr_1_local_var;
end:
    return NULL;
}

OpenAPI_ambr_1_t *OpenAPI_ambr_1_copy(OpenAPI_ambr_1_t *dst, OpenAPI_ambr_1_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_ambr_1_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_ambr_1_convertToJSON() failed");
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

    OpenAPI_ambr_1_free(dst);
    dst = OpenAPI_ambr_1_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

