
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_subscription.h"

OpenAPI_lmf_data_exposure_subscription_t *OpenAPI_lmf_data_exposure_subscription_create(
    char *notification_uri,
    char *notify_correlation_id,
    OpenAPI_presence_info_t *aoi,
    OpenAPI_recur_time_t *recur_time,
    bool is_num_of_samples,
    int num_of_samples,
    OpenAPI_list_t *data_sources,
    OpenAPI_location_qo_s_t *quality_threshold,
    bool is_ml_model_id,
    int ml_model_id,
    char *expiry_time,
    bool is_pru_indication,
    int pru_indication
)
{
    OpenAPI_lmf_data_exposure_subscription_t *lmf_data_exposure_subscription_local_var = ogs_malloc(sizeof(OpenAPI_lmf_data_exposure_subscription_t));
    ogs_assert(lmf_data_exposure_subscription_local_var);

    lmf_data_exposure_subscription_local_var->notification_uri = notification_uri;
    lmf_data_exposure_subscription_local_var->notify_correlation_id = notify_correlation_id;
    lmf_data_exposure_subscription_local_var->aoi = aoi;
    lmf_data_exposure_subscription_local_var->recur_time = recur_time;
    lmf_data_exposure_subscription_local_var->is_num_of_samples = is_num_of_samples;
    lmf_data_exposure_subscription_local_var->num_of_samples = num_of_samples;
    lmf_data_exposure_subscription_local_var->data_sources = data_sources;
    lmf_data_exposure_subscription_local_var->quality_threshold = quality_threshold;
    lmf_data_exposure_subscription_local_var->is_ml_model_id = is_ml_model_id;
    lmf_data_exposure_subscription_local_var->ml_model_id = ml_model_id;
    lmf_data_exposure_subscription_local_var->expiry_time = expiry_time;
    lmf_data_exposure_subscription_local_var->is_pru_indication = is_pru_indication;
    lmf_data_exposure_subscription_local_var->pru_indication = pru_indication;

    return lmf_data_exposure_subscription_local_var;
}

void OpenAPI_lmf_data_exposure_subscription_free(OpenAPI_lmf_data_exposure_subscription_t *lmf_data_exposure_subscription)
{
    if (NULL == lmf_data_exposure_subscription) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(lmf_data_exposure_subscription->notification_uri);
    ogs_free(lmf_data_exposure_subscription->notify_correlation_id);
    OpenAPI_presence_info_free(lmf_data_exposure_subscription->aoi);
    OpenAPI_recur_time_free(lmf_data_exposure_subscription->recur_time);
    OpenAPI_list_for_each(lmf_data_exposure_subscription->data_sources, node) {
        OpenAPI_data_source_type_free(node->data);
    }
    OpenAPI_list_free(lmf_data_exposure_subscription->data_sources);
    OpenAPI_location_qo_s_free(lmf_data_exposure_subscription->quality_threshold);
    ogs_free(lmf_data_exposure_subscription->expiry_time);
    ogs_free(lmf_data_exposure_subscription);
}

cJSON *OpenAPI_lmf_data_exposure_subscription_convertToJSON(OpenAPI_lmf_data_exposure_subscription_t *lmf_data_exposure_subscription)
{
    cJSON *item = NULL;

    if (lmf_data_exposure_subscription == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [LmfDataExposureSubscription]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddStringToObject(item, "notificationUri", lmf_data_exposure_subscription->notification_uri) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [notification_uri]");
        goto end;
    }

    if (cJSON_AddStringToObject(item, "notifyCorrelationId", lmf_data_exposure_subscription->notify_correlation_id) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [notify_correlation_id]");
        goto end;
    }

    cJSON *aoi_local_JSON = OpenAPI_presence_info_convertToJSON(lmf_data_exposure_subscription->aoi);
    if (aoi_local_JSON == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [aoi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "aoi", aoi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [aoi]");
        goto end;
    }

    if (lmf_data_exposure_subscription->recur_time) {
    cJSON *recur_time_local_JSON = OpenAPI_recur_time_convertToJSON(lmf_data_exposure_subscription->recur_time);
    if (recur_time_local_JSON == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [recur_time]");
        goto end;
    }
    cJSON_AddItemToObject(item, "recurTime", recur_time_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [recur_time]");
        goto end;
    }
    }

    if (lmf_data_exposure_subscription->is_num_of_samples) {
    if (cJSON_AddNumberToObject(item, "numOfSamples", lmf_data_exposure_subscription->num_of_samples) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [num_of_samples]");
        goto end;
    }
    }

    if (lmf_data_exposure_subscription->data_sources) {
    cJSON *data_sourcesList = cJSON_AddArrayToObject(item, "dataSources");
    if (data_sourcesList == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [data_sources]");
        goto end;
    }

    OpenAPI_lnode_t *data_sources_node;
    if (lmf_data_exposure_subscription->data_sources) {
        OpenAPI_list_for_each(lmf_data_exposure_subscription->data_sources, data_sources_node) {
            cJSON *itemLocal = OpenAPI_data_source_type_convertToJSON(data_sources_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [data_sources]");
                goto end;
            }
            cJSON_AddItemToArray(data_sourcesList, itemLocal);
        }
    }
    }

    if (lmf_data_exposure_subscription->quality_threshold) {
    cJSON *quality_threshold_local_JSON = OpenAPI_location_qo_s_convertToJSON(lmf_data_exposure_subscription->quality_threshold);
    if (quality_threshold_local_JSON == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [quality_threshold]");
        goto end;
    }
    cJSON_AddItemToObject(item, "qualityThreshold", quality_threshold_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [quality_threshold]");
        goto end;
    }
    }

    if (lmf_data_exposure_subscription->is_ml_model_id) {
    if (cJSON_AddNumberToObject(item, "mlModelId", lmf_data_exposure_subscription->ml_model_id) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [ml_model_id]");
        goto end;
    }
    }

    if (lmf_data_exposure_subscription->expiry_time) {
    if (cJSON_AddStringToObject(item, "expiryTime", lmf_data_exposure_subscription->expiry_time) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [expiry_time]");
        goto end;
    }
    }

    if (lmf_data_exposure_subscription->is_pru_indication) {
    if (cJSON_AddBoolToObject(item, "pruIndication", lmf_data_exposure_subscription->pru_indication) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed [pru_indication]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_lmf_data_exposure_subscription_t *OpenAPI_lmf_data_exposure_subscription_parseFromJSON(cJSON *lmf_data_exposure_subscriptionJSON)
{
    OpenAPI_lmf_data_exposure_subscription_t *lmf_data_exposure_subscription_local_var = NULL;
    cJSON *notification_uri = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "notificationUri");
    if (!notification_uri) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [notification_uri]");
        goto end;
    }

    if (!cJSON_IsString(notification_uri)) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [notification_uri]");
        goto end;
    }

    cJSON *notify_correlation_id = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "notifyCorrelationId");
    if (!notify_correlation_id) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [notify_correlation_id]");
        goto end;
    }

    if (!cJSON_IsString(notify_correlation_id)) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [notify_correlation_id]");
        goto end;
    }

    cJSON *aoi = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "aoi");
    if (!aoi) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [aoi]");
        goto end;
    }

    OpenAPI_presence_info_t *aoi_local_nonprim = NULL;
    aoi_local_nonprim = OpenAPI_presence_info_parseFromJSON(aoi);

    cJSON *recur_time = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "recurTime");

    OpenAPI_recur_time_t *recur_time_local_nonprim = NULL;
    if (recur_time) {
    recur_time_local_nonprim = OpenAPI_recur_time_parseFromJSON(recur_time);
    }

    cJSON *num_of_samples = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "numOfSamples");

    if (num_of_samples) {
    if (!cJSON_IsNumber(num_of_samples)) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [num_of_samples]");
        goto end;
    }
    }

    cJSON *data_sources = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "dataSources");

    OpenAPI_list_t *data_sourcesList;
    if (data_sources) {
    cJSON *data_sources_local_nonprimitive;
    if (!cJSON_IsArray(data_sources)){
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [data_sources]");
        goto end;
    }

    data_sourcesList = OpenAPI_list_create();

    cJSON_ArrayForEach(data_sources_local_nonprimitive, data_sources ) {
        if (!cJSON_IsObject(data_sources_local_nonprimitive)) {
            ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [data_sources]");
            goto end;
        }
        OpenAPI_data_source_type_t *data_sourcesItem = OpenAPI_data_source_type_parseFromJSON(data_sources_local_nonprimitive);

        if (!data_sourcesItem) {
            ogs_error("No data_sourcesItem");
            OpenAPI_list_free(data_sourcesList);
            goto end;
        }

        OpenAPI_list_add(data_sourcesList, data_sourcesItem);
    }
    }

    cJSON *quality_threshold = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "qualityThreshold");

    OpenAPI_location_qo_s_t *quality_threshold_local_nonprim = NULL;
    if (quality_threshold) {
    quality_threshold_local_nonprim = OpenAPI_location_qo_s_parseFromJSON(quality_threshold);
    }

    cJSON *ml_model_id = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "mlModelId");

    if (ml_model_id) {
    if (!cJSON_IsNumber(ml_model_id)) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [ml_model_id]");
        goto end;
    }
    }

    cJSON *expiry_time = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "expiryTime");

    if (expiry_time) {
    if (!cJSON_IsString(expiry_time)) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [expiry_time]");
        goto end;
    }
    }

    cJSON *pru_indication = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "pruIndication");

    if (pru_indication) {
    if (!cJSON_IsBool(pru_indication)) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_parseFromJSON() failed [pru_indication]");
        goto end;
    }
    }

    lmf_data_exposure_subscription_local_var = OpenAPI_lmf_data_exposure_subscription_create (
        ogs_strdup(notification_uri->valuestring),
        ogs_strdup(notify_correlation_id->valuestring),
        aoi_local_nonprim,
        recur_time ? recur_time_local_nonprim : NULL,
        num_of_samples ? true : false,
        num_of_samples ? num_of_samples->valuedouble : 0,
        data_sources ? data_sourcesList : NULL,
        quality_threshold ? quality_threshold_local_nonprim : NULL,
        ml_model_id ? true : false,
        ml_model_id ? ml_model_id->valuedouble : 0,
        expiry_time ? ogs_strdup(expiry_time->valuestring) : NULL,
        pru_indication ? true : false,
        pru_indication ? pru_indication->valueint : 0
    );

    return lmf_data_exposure_subscription_local_var;
end:
    return NULL;
}

OpenAPI_lmf_data_exposure_subscription_t *OpenAPI_lmf_data_exposure_subscription_copy(OpenAPI_lmf_data_exposure_subscription_t *dst, OpenAPI_lmf_data_exposure_subscription_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_lmf_data_exposure_subscription_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_lmf_data_exposure_subscription_convertToJSON() failed");
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

    OpenAPI_lmf_data_exposure_subscription_free(dst);
    dst = OpenAPI_lmf_data_exposure_subscription_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

