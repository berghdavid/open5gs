
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ng_ksi.h"

OpenAPI_ng_ksi_t *OpenAPI_ng_ksi_create(
    OpenAPI_sc_type_e tsc,
    int ksi
)
{
    OpenAPI_ng_ksi_t *ng_ksi_local_var = ogs_malloc(sizeof(OpenAPI_ng_ksi_t));
    log_assert(ng_ksi_local_var);

    ng_ksi_local_var->tsc = tsc;
    ng_ksi_local_var->ksi = ksi;

    return ng_ksi_local_var;
}

void OpenAPI_ng_ksi_free(OpenAPI_ng_ksi_t *ng_ksi)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == ng_ksi) {
        return;
    }
    ogs_free(ng_ksi);
}

cJSON *OpenAPI_ng_ksi_convertToJSON(OpenAPI_ng_ksi_t *ng_ksi)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (ng_ksi == NULL) {
        log_error("OpenAPI_ng_ksi_convertToJSON() failed [NgKsi]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (ng_ksi->tsc == OpenAPI_sc_type_NULL) {
        log_error("OpenAPI_ng_ksi_convertToJSON() failed [tsc]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "tsc", OpenAPI_sc_type_ToString(ng_ksi->tsc)) == NULL) {
        log_error("OpenAPI_ng_ksi_convertToJSON() failed [tsc]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "ksi", ng_ksi->ksi) == NULL) {
        log_error("OpenAPI_ng_ksi_convertToJSON() failed [ksi]");
        goto end;
    }

end:
    return item;
}

OpenAPI_ng_ksi_t *OpenAPI_ng_ksi_parseFromJSON(cJSON *ng_ksiJSON)
{
    OpenAPI_ng_ksi_t *ng_ksi_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *tsc = NULL;
    OpenAPI_sc_type_e tscVariable = 0;
    cJSON *ksi = NULL;
    tsc = cJSON_GetObjectItemCaseSensitive(ng_ksiJSON, "tsc");
    if (!tsc) {
        log_error("OpenAPI_ng_ksi_parseFromJSON() failed [tsc]");
        goto end;
    }
    if (!cJSON_IsString(tsc)) {
        log_error("OpenAPI_ng_ksi_parseFromJSON() failed [tsc]");
        goto end;
    }
    tscVariable = OpenAPI_sc_type_FromString(tsc->valuestring);

    ksi = cJSON_GetObjectItemCaseSensitive(ng_ksiJSON, "ksi");
    if (!ksi) {
        log_error("OpenAPI_ng_ksi_parseFromJSON() failed [ksi]");
        goto end;
    }
    if (!cJSON_IsNumber(ksi)) {
        log_error("OpenAPI_ng_ksi_parseFromJSON() failed [ksi]");
        goto end;
    }

    ng_ksi_local_var = OpenAPI_ng_ksi_create (
        tscVariable,
        
        ksi->valuedouble
    );

    return ng_ksi_local_var;
end:
    return NULL;
}

OpenAPI_ng_ksi_t *OpenAPI_ng_ksi_copy(OpenAPI_ng_ksi_t *dst, OpenAPI_ng_ksi_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_ng_ksi_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_ng_ksi_convertToJSON() failed");
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

    OpenAPI_ng_ksi_free(dst);
    dst = OpenAPI_ng_ksi_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

