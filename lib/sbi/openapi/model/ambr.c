
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ambr.h"

OpenAPI_ambr_t *OpenAPI_ambr_create(
    char *uplink,
    char *downlink
)
{
    OpenAPI_ambr_t *ambr_local_var = ogs_malloc(sizeof(OpenAPI_ambr_t));
    log_assert(ambr_local_var);

    ambr_local_var->uplink = uplink;
    ambr_local_var->downlink = downlink;

    return ambr_local_var;
}

void OpenAPI_ambr_free(OpenAPI_ambr_t *ambr)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == ambr) {
        return;
    }
    if (ambr->uplink) {
        ogs_free(ambr->uplink);
        ambr->uplink = NULL;
    }
    if (ambr->downlink) {
        ogs_free(ambr->downlink);
        ambr->downlink = NULL;
    }
    ogs_free(ambr);
}

cJSON *OpenAPI_ambr_convertToJSON(OpenAPI_ambr_t *ambr)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (ambr == NULL) {
        log_error("OpenAPI_ambr_convertToJSON() failed [Ambr]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!ambr->uplink) {
        log_error("OpenAPI_ambr_convertToJSON() failed [uplink]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "uplink", ambr->uplink) == NULL) {
        log_error("OpenAPI_ambr_convertToJSON() failed [uplink]");
        goto end;
    }

    if (!ambr->downlink) {
        log_error("OpenAPI_ambr_convertToJSON() failed [downlink]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "downlink", ambr->downlink) == NULL) {
        log_error("OpenAPI_ambr_convertToJSON() failed [downlink]");
        goto end;
    }

end:
    return item;
}

OpenAPI_ambr_t *OpenAPI_ambr_parseFromJSON(cJSON *ambrJSON)
{
    OpenAPI_ambr_t *ambr_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *uplink = NULL;
    cJSON *downlink = NULL;
    uplink = cJSON_GetObjectItemCaseSensitive(ambrJSON, "uplink");
    if (!uplink) {
        log_error("OpenAPI_ambr_parseFromJSON() failed [uplink]");
        goto end;
    }
    if (!cJSON_IsString(uplink)) {
        log_error("OpenAPI_ambr_parseFromJSON() failed [uplink]");
        goto end;
    }

    downlink = cJSON_GetObjectItemCaseSensitive(ambrJSON, "downlink");
    if (!downlink) {
        log_error("OpenAPI_ambr_parseFromJSON() failed [downlink]");
        goto end;
    }
    if (!cJSON_IsString(downlink)) {
        log_error("OpenAPI_ambr_parseFromJSON() failed [downlink]");
        goto end;
    }

    ambr_local_var = OpenAPI_ambr_create (
        ogs_strdup(uplink->valuestring),
        ogs_strdup(downlink->valuestring)
    );

    return ambr_local_var;
end:
    return NULL;
}

OpenAPI_ambr_t *OpenAPI_ambr_copy(OpenAPI_ambr_t *dst, OpenAPI_ambr_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_ambr_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_ambr_convertToJSON() failed");
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

    OpenAPI_ambr_free(dst);
    dst = OpenAPI_ambr_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

