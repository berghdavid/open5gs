
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_data_set.h"

OpenAPI_ciphering_data_set_t *OpenAPI_ciphering_data_set_create(
    int ciphering_set_id,
    char ciphering_key,
    char c0,
    char lte_pos_sib_types,
    char nr_pos_sib_types,
    char *validity_start_time,
    int validity_duration,
    char tai_list
)
{
    OpenAPI_ciphering_data_set_t *ciphering_data_set_local_var = ogs_malloc(sizeof(OpenAPI_ciphering_data_set_t));
    ogs_assert(ciphering_data_set_local_var);

    ciphering_data_set_local_var->ciphering_set_id = ciphering_set_id;
    ciphering_data_set_local_var->ciphering_key = ciphering_key;
    ciphering_data_set_local_var->c0 = c0;
    ciphering_data_set_local_var->lte_pos_sib_types = lte_pos_sib_types;
    ciphering_data_set_local_var->nr_pos_sib_types = nr_pos_sib_types;
    ciphering_data_set_local_var->validity_start_time = validity_start_time;
    ciphering_data_set_local_var->validity_duration = validity_duration;
    ciphering_data_set_local_var->tai_list = tai_list;

    return ciphering_data_set_local_var;
}

void OpenAPI_ciphering_data_set_free(OpenAPI_ciphering_data_set_t *ciphering_data_set)
{
    if (NULL == ciphering_data_set) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(ciphering_data_set->validity_start_time);
    ogs_free(ciphering_data_set);
}

cJSON *OpenAPI_ciphering_data_set_convertToJSON(OpenAPI_ciphering_data_set_t *ciphering_data_set)
{
    cJSON *item = NULL;

    if (ciphering_data_set == NULL) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed [CipheringDataSet]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddNumberToObject(item, "cipheringSetID", ciphering_data_set->ciphering_set_id) == NULL) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed [ciphering_set_id]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "cipheringKey", ciphering_data_set->ciphering_key) == NULL) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed [ciphering_key]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "c0", ciphering_data_set->c0) == NULL) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed [c0]");
        goto end;
    }

    if (ciphering_data_set->lte_pos_sib_types) {
    if (cJSON_AddNumberToObject(item, "ltePosSibTypes", ciphering_data_set->lte_pos_sib_types) == NULL) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed [lte_pos_sib_types]");
        goto end;
    }
    }

    if (ciphering_data_set->nr_pos_sib_types) {
    if (cJSON_AddNumberToObject(item, "nrPosSibTypes", ciphering_data_set->nr_pos_sib_types) == NULL) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed [nr_pos_sib_types]");
        goto end;
    }
    }

    if (cJSON_AddStringToObject(item, "validityStartTime", ciphering_data_set->validity_start_time) == NULL) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed [validity_start_time]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "validityDuration", ciphering_data_set->validity_duration) == NULL) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed [validity_duration]");
        goto end;
    }

    if (ciphering_data_set->tai_list) {
    if (cJSON_AddNumberToObject(item, "taiList", ciphering_data_set->tai_list) == NULL) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed [tai_list]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_ciphering_data_set_t *OpenAPI_ciphering_data_set_parseFromJSON(cJSON *ciphering_data_setJSON)
{
    OpenAPI_ciphering_data_set_t *ciphering_data_set_local_var = NULL;
    cJSON *ciphering_set_id = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "cipheringSetID");
    if (!ciphering_set_id) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [ciphering_set_id]");
        goto end;
    }

    if (!cJSON_IsNumber(ciphering_set_id)) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [ciphering_set_id]");
        goto end;
    }

    cJSON *ciphering_key = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "cipheringKey");
    if (!ciphering_key) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [ciphering_key]");
        goto end;
    }

    if (!cJSON_IsNumber(ciphering_key)) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [ciphering_key]");
        goto end;
    }

    cJSON *c0 = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "c0");
    if (!c0) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [c0]");
        goto end;
    }

    if (!cJSON_IsNumber(c0)) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [c0]");
        goto end;
    }

    cJSON *lte_pos_sib_types = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "ltePosSibTypes");

    if (lte_pos_sib_types) {
    if (!cJSON_IsNumber(lte_pos_sib_types)) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [lte_pos_sib_types]");
        goto end;
    }
    }

    cJSON *nr_pos_sib_types = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "nrPosSibTypes");

    if (nr_pos_sib_types) {
    if (!cJSON_IsNumber(nr_pos_sib_types)) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [nr_pos_sib_types]");
        goto end;
    }
    }

    cJSON *validity_start_time = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "validityStartTime");
    if (!validity_start_time) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [validity_start_time]");
        goto end;
    }

    if (!cJSON_IsString(validity_start_time)) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [validity_start_time]");
        goto end;
    }

    cJSON *validity_duration = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "validityDuration");
    if (!validity_duration) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [validity_duration]");
        goto end;
    }

    if (!cJSON_IsNumber(validity_duration)) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [validity_duration]");
        goto end;
    }

    cJSON *tai_list = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "taiList");

    if (tai_list) {
    if (!cJSON_IsNumber(tai_list)) {
        ogs_error("OpenAPI_ciphering_data_set_parseFromJSON() failed [tai_list]");
        goto end;
    }
    }

    ciphering_data_set_local_var = OpenAPI_ciphering_data_set_create (
        
        ciphering_set_id->valuedouble,
        ciphering_key->valueint,
        c0->valueint,
        lte_pos_sib_types ? lte_pos_sib_types->valueint : 0,
        nr_pos_sib_types ? nr_pos_sib_types->valueint : 0,
        ogs_strdup(validity_start_time->valuestring),
        
        validity_duration->valuedouble,
        tai_list ? tai_list->valueint : 0
    );

    return ciphering_data_set_local_var;
end:
    return NULL;
}

OpenAPI_ciphering_data_set_t *OpenAPI_ciphering_data_set_copy(OpenAPI_ciphering_data_set_t *dst, OpenAPI_ciphering_data_set_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_ciphering_data_set_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_ciphering_data_set_convertToJSON() failed");
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

    OpenAPI_ciphering_data_set_free(dst);
    dst = OpenAPI_ciphering_data_set_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

