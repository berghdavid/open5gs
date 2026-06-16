
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_set_report.h"

OpenAPI_ciphering_set_report_t *OpenAPI_ciphering_set_report_create(
    int ciphering_set_id,
    OpenAPI_storage_outcome_e storage_outcome
)
{
    OpenAPI_ciphering_set_report_t *ciphering_set_report_local_var = ogs_malloc(sizeof(OpenAPI_ciphering_set_report_t));
    ogs_assert(ciphering_set_report_local_var);

    ciphering_set_report_local_var->ciphering_set_id = ciphering_set_id;
    ciphering_set_report_local_var->storage_outcome = storage_outcome;

    return ciphering_set_report_local_var;
}

void OpenAPI_ciphering_set_report_free(OpenAPI_ciphering_set_report_t *ciphering_set_report)
{
    if (NULL == ciphering_set_report) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(ciphering_set_report);
}

cJSON *OpenAPI_ciphering_set_report_convertToJSON(OpenAPI_ciphering_set_report_t *ciphering_set_report)
{
    cJSON *item = NULL;

    if (ciphering_set_report == NULL) {
        ogs_error("OpenAPI_ciphering_set_report_convertToJSON() failed [CipheringSetReport]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddNumberToObject(item, "cipheringSetID", ciphering_set_report->ciphering_set_id) == NULL) {
        ogs_error("OpenAPI_ciphering_set_report_convertToJSON() failed [ciphering_set_id]");
        goto end;
    }

    if (cJSON_AddStringToObject(item, "storageOutcome", OpenAPI_storage_outcome_ToString(ciphering_set_report->storage_outcome)) == NULL) {
        ogs_error("OpenAPI_ciphering_set_report_convertToJSON() failed [storage_outcome]");
        goto end;
    }

end:
    return item;
}

OpenAPI_ciphering_set_report_t *OpenAPI_ciphering_set_report_parseFromJSON(cJSON *ciphering_set_reportJSON)
{
    OpenAPI_ciphering_set_report_t *ciphering_set_report_local_var = NULL;
    cJSON *ciphering_set_id = cJSON_GetObjectItemCaseSensitive(ciphering_set_reportJSON, "cipheringSetID");
    if (!ciphering_set_id) {
        ogs_error("OpenAPI_ciphering_set_report_parseFromJSON() failed [ciphering_set_id]");
        goto end;
    }

    if (!cJSON_IsNumber(ciphering_set_id)) {
        ogs_error("OpenAPI_ciphering_set_report_parseFromJSON() failed [ciphering_set_id]");
        goto end;
    }

    cJSON *storage_outcome = cJSON_GetObjectItemCaseSensitive(ciphering_set_reportJSON, "storageOutcome");
    if (!storage_outcome) {
        ogs_error("OpenAPI_ciphering_set_report_parseFromJSON() failed [storage_outcome]");
        goto end;
    }

    OpenAPI_storage_outcome_e storage_outcomeVariable;
    if (!cJSON_IsString(storage_outcome)) {
        ogs_error("OpenAPI_ciphering_set_report_parseFromJSON() failed [storage_outcome]");
        goto end;
    }
    storage_outcomeVariable = OpenAPI_storage_outcome_FromString(storage_outcome->valuestring);

    ciphering_set_report_local_var = OpenAPI_ciphering_set_report_create (
        
        ciphering_set_id->valuedouble,
        storage_outcomeVariable
    );

    return ciphering_set_report_local_var;
end:
    return NULL;
}

OpenAPI_ciphering_set_report_t *OpenAPI_ciphering_set_report_copy(OpenAPI_ciphering_set_report_t *dst, OpenAPI_ciphering_set_report_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_ciphering_set_report_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_ciphering_set_report_convertToJSON() failed");
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

    OpenAPI_ciphering_set_report_free(dst);
    dst = OpenAPI_ciphering_set_report_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

