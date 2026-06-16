
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_sampling_data.h"

OpenAPI_lmf_data_exposure_sampling_data_t *OpenAPI_lmf_data_exposure_sampling_data_create(
    char *timestamp,
    OpenAPI_loc_measurements_t *loc_measure_data,
    OpenAPI_location_data_t *ground_truth,
    bool is_quality_indicator,
    float quality_indicator,
    OpenAPI_location_data_t *ml_loc_estimate
)
{
    OpenAPI_lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data_local_var = ogs_malloc(sizeof(OpenAPI_lmf_data_exposure_sampling_data_t));
    ogs_assert(lmf_data_exposure_sampling_data_local_var);

    lmf_data_exposure_sampling_data_local_var->timestamp = timestamp;
    lmf_data_exposure_sampling_data_local_var->loc_measure_data = loc_measure_data;
    lmf_data_exposure_sampling_data_local_var->ground_truth = ground_truth;
    lmf_data_exposure_sampling_data_local_var->is_quality_indicator = is_quality_indicator;
    lmf_data_exposure_sampling_data_local_var->quality_indicator = quality_indicator;
    lmf_data_exposure_sampling_data_local_var->ml_loc_estimate = ml_loc_estimate;

    return lmf_data_exposure_sampling_data_local_var;
}

void OpenAPI_lmf_data_exposure_sampling_data_free(OpenAPI_lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data)
{
    if (NULL == lmf_data_exposure_sampling_data) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(lmf_data_exposure_sampling_data->timestamp);
    OpenAPI_loc_measurements_free(lmf_data_exposure_sampling_data->loc_measure_data);
    OpenAPI_location_data_free(lmf_data_exposure_sampling_data->ground_truth);
    OpenAPI_location_data_free(lmf_data_exposure_sampling_data->ml_loc_estimate);
    ogs_free(lmf_data_exposure_sampling_data);
}

cJSON *OpenAPI_lmf_data_exposure_sampling_data_convertToJSON(OpenAPI_lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data)
{
    cJSON *item = NULL;

    if (lmf_data_exposure_sampling_data == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed [LmfDataExposureSamplingData]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddStringToObject(item, "timestamp", lmf_data_exposure_sampling_data->timestamp) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed [timestamp]");
        goto end;
    }

    cJSON *loc_measure_data_local_JSON = OpenAPI_loc_measurements_convertToJSON(lmf_data_exposure_sampling_data->loc_measure_data);
    if (loc_measure_data_local_JSON == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed [loc_measure_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "locMeasureData", loc_measure_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed [loc_measure_data]");
        goto end;
    }

    cJSON *ground_truth_local_JSON = OpenAPI_location_data_convertToJSON(lmf_data_exposure_sampling_data->ground_truth);
    if (ground_truth_local_JSON == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed [ground_truth]");
        goto end;
    }
    cJSON_AddItemToObject(item, "groundTruth", ground_truth_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed [ground_truth]");
        goto end;
    }

    if (lmf_data_exposure_sampling_data->is_quality_indicator) {
    if (cJSON_AddNumberToObject(item, "qualityIndicator", lmf_data_exposure_sampling_data->quality_indicator) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed [quality_indicator]");
        goto end;
    }
    }

    if (lmf_data_exposure_sampling_data->ml_loc_estimate) {
    cJSON *ml_loc_estimate_local_JSON = OpenAPI_location_data_convertToJSON(lmf_data_exposure_sampling_data->ml_loc_estimate);
    if (ml_loc_estimate_local_JSON == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed [ml_loc_estimate]");
        goto end;
    }
    cJSON_AddItemToObject(item, "mlLocEstimate", ml_loc_estimate_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed [ml_loc_estimate]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_lmf_data_exposure_sampling_data_t *OpenAPI_lmf_data_exposure_sampling_data_parseFromJSON(cJSON *lmf_data_exposure_sampling_dataJSON)
{
    OpenAPI_lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data_local_var = NULL;
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "timestamp");
    if (!timestamp) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_parseFromJSON() failed [timestamp]");
        goto end;
    }

    if (!cJSON_IsString(timestamp)) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_parseFromJSON() failed [timestamp]");
        goto end;
    }

    cJSON *loc_measure_data = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "locMeasureData");
    if (!loc_measure_data) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_parseFromJSON() failed [loc_measure_data]");
        goto end;
    }

    OpenAPI_loc_measurements_t *loc_measure_data_local_nonprim = NULL;
    loc_measure_data_local_nonprim = OpenAPI_loc_measurements_parseFromJSON(loc_measure_data);

    cJSON *ground_truth = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "groundTruth");
    if (!ground_truth) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_parseFromJSON() failed [ground_truth]");
        goto end;
    }

    OpenAPI_location_data_t *ground_truth_local_nonprim = NULL;
    ground_truth_local_nonprim = OpenAPI_location_data_parseFromJSON(ground_truth);

    cJSON *quality_indicator = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "qualityIndicator");

    if (quality_indicator) {
    if (!cJSON_IsNumber(quality_indicator)) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_parseFromJSON() failed [quality_indicator]");
        goto end;
    }
    }

    cJSON *ml_loc_estimate = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "mlLocEstimate");

    OpenAPI_location_data_t *ml_loc_estimate_local_nonprim = NULL;
    if (ml_loc_estimate) {
    ml_loc_estimate_local_nonprim = OpenAPI_location_data_parseFromJSON(ml_loc_estimate);
    }

    lmf_data_exposure_sampling_data_local_var = OpenAPI_lmf_data_exposure_sampling_data_create (
        ogs_strdup(timestamp->valuestring),
        loc_measure_data_local_nonprim,
        ground_truth_local_nonprim,
        quality_indicator ? true : false,
        quality_indicator ? quality_indicator->valuedouble : 0,
        ml_loc_estimate ? ml_loc_estimate_local_nonprim : NULL
    );

    return lmf_data_exposure_sampling_data_local_var;
end:
    return NULL;
}

OpenAPI_lmf_data_exposure_sampling_data_t *OpenAPI_lmf_data_exposure_sampling_data_copy(OpenAPI_lmf_data_exposure_sampling_data_t *dst, OpenAPI_lmf_data_exposure_sampling_data_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_lmf_data_exposure_sampling_data_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_lmf_data_exposure_sampling_data_convertToJSON() failed");
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

    OpenAPI_lmf_data_exposure_sampling_data_free(dst);
    dst = OpenAPI_lmf_data_exposure_sampling_data_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

