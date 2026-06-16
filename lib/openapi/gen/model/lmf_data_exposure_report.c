
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_report.h"

OpenAPI_lmf_data_exposure_report_t *OpenAPI_lmf_data_exposure_report_create(
    OpenAPI_list_t *sampling_data_list,
    bool is_ml_model_id,
    int ml_model_id,
    OpenAPI_lmf_data_exposure_cause_t *cause
)
{
    OpenAPI_lmf_data_exposure_report_t *lmf_data_exposure_report_local_var = ogs_malloc(sizeof(OpenAPI_lmf_data_exposure_report_t));
    ogs_assert(lmf_data_exposure_report_local_var);

    lmf_data_exposure_report_local_var->sampling_data_list = sampling_data_list;
    lmf_data_exposure_report_local_var->is_ml_model_id = is_ml_model_id;
    lmf_data_exposure_report_local_var->ml_model_id = ml_model_id;
    lmf_data_exposure_report_local_var->cause = cause;

    return lmf_data_exposure_report_local_var;
}

void OpenAPI_lmf_data_exposure_report_free(OpenAPI_lmf_data_exposure_report_t *lmf_data_exposure_report)
{
    if (NULL == lmf_data_exposure_report) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_list_for_each(lmf_data_exposure_report->sampling_data_list, node) {
        OpenAPI_lmf_data_exposure_sampling_data_free(node->data);
    }
    OpenAPI_list_free(lmf_data_exposure_report->sampling_data_list);
    OpenAPI_lmf_data_exposure_cause_free(lmf_data_exposure_report->cause);
    ogs_free(lmf_data_exposure_report);
}

cJSON *OpenAPI_lmf_data_exposure_report_convertToJSON(OpenAPI_lmf_data_exposure_report_t *lmf_data_exposure_report)
{
    cJSON *item = NULL;

    if (lmf_data_exposure_report == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_report_convertToJSON() failed [LmfDataExposureReport]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (lmf_data_exposure_report->sampling_data_list) {
    cJSON *sampling_data_listList = cJSON_AddArrayToObject(item, "samplingDataList");
    if (sampling_data_listList == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_report_convertToJSON() failed [sampling_data_list]");
        goto end;
    }

    OpenAPI_lnode_t *sampling_data_list_node;
    if (lmf_data_exposure_report->sampling_data_list) {
        OpenAPI_list_for_each(lmf_data_exposure_report->sampling_data_list, sampling_data_list_node) {
            cJSON *itemLocal = OpenAPI_lmf_data_exposure_sampling_data_convertToJSON(sampling_data_list_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_lmf_data_exposure_report_convertToJSON() failed [sampling_data_list]");
                goto end;
            }
            cJSON_AddItemToArray(sampling_data_listList, itemLocal);
        }
    }
    }

    if (lmf_data_exposure_report->is_ml_model_id) {
    if (cJSON_AddNumberToObject(item, "mlModelId", lmf_data_exposure_report->ml_model_id) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_report_convertToJSON() failed [ml_model_id]");
        goto end;
    }
    }

    if (lmf_data_exposure_report->cause) {
    cJSON *cause_local_JSON = OpenAPI_lmf_data_exposure_cause_convertToJSON(lmf_data_exposure_report->cause);
    if (cause_local_JSON == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_report_convertToJSON() failed [cause]");
        goto end;
    }
    cJSON_AddItemToObject(item, "cause", cause_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_report_convertToJSON() failed [cause]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_lmf_data_exposure_report_t *OpenAPI_lmf_data_exposure_report_parseFromJSON(cJSON *lmf_data_exposure_reportJSON)
{
    OpenAPI_lmf_data_exposure_report_t *lmf_data_exposure_report_local_var = NULL;
    cJSON *sampling_data_list = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_reportJSON, "samplingDataList");

    OpenAPI_list_t *sampling_data_listList;
    if (sampling_data_list) {
    cJSON *sampling_data_list_local_nonprimitive;
    if (!cJSON_IsArray(sampling_data_list)){
        ogs_error("OpenAPI_lmf_data_exposure_report_parseFromJSON() failed [sampling_data_list]");
        goto end;
    }

    sampling_data_listList = OpenAPI_list_create();

    cJSON_ArrayForEach(sampling_data_list_local_nonprimitive, sampling_data_list ) {
        if (!cJSON_IsObject(sampling_data_list_local_nonprimitive)) {
            ogs_error("OpenAPI_lmf_data_exposure_report_parseFromJSON() failed [sampling_data_list]");
            goto end;
        }
        OpenAPI_lmf_data_exposure_sampling_data_t *sampling_data_listItem = OpenAPI_lmf_data_exposure_sampling_data_parseFromJSON(sampling_data_list_local_nonprimitive);

        if (!sampling_data_listItem) {
            ogs_error("No sampling_data_listItem");
            OpenAPI_list_free(sampling_data_listList);
            goto end;
        }

        OpenAPI_list_add(sampling_data_listList, sampling_data_listItem);
    }
    }

    cJSON *ml_model_id = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_reportJSON, "mlModelId");

    if (ml_model_id) {
    if (!cJSON_IsNumber(ml_model_id)) {
        ogs_error("OpenAPI_lmf_data_exposure_report_parseFromJSON() failed [ml_model_id]");
        goto end;
    }
    }

    cJSON *cause = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_reportJSON, "cause");

    OpenAPI_lmf_data_exposure_cause_t *cause_local_nonprim = NULL;
    if (cause) {
    cause_local_nonprim = OpenAPI_lmf_data_exposure_cause_parseFromJSON(cause);
    }

    lmf_data_exposure_report_local_var = OpenAPI_lmf_data_exposure_report_create (
        sampling_data_list ? sampling_data_listList : NULL,
        ml_model_id ? true : false,
        ml_model_id ? ml_model_id->valuedouble : 0,
        cause ? cause_local_nonprim : NULL
    );

    return lmf_data_exposure_report_local_var;
end:
    return NULL;
}

OpenAPI_lmf_data_exposure_report_t *OpenAPI_lmf_data_exposure_report_copy(OpenAPI_lmf_data_exposure_report_t *dst, OpenAPI_lmf_data_exposure_report_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_lmf_data_exposure_report_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_lmf_data_exposure_report_convertToJSON() failed");
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

    OpenAPI_lmf_data_exposure_report_free(dst);
    dst = OpenAPI_lmf_data_exposure_report_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

