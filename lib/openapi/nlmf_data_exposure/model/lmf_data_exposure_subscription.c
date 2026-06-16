#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_subscription.h"



static lmf_data_exposure_subscription_t *lmf_data_exposure_subscription_create_internal(
    char *notification_uri,
    char *notify_correlation_id,
    presence_info_t *aoi,
    recur_time_t *recur_time,
    int *num_of_samples,
    list_t *data_sources,
    location_qo_s_t *quality_threshold,
    int *ml_model_id,
    char *expiry_time,
    int *pru_indication
    ) {
    lmf_data_exposure_subscription_t *lmf_data_exposure_subscription_local_var = malloc(sizeof(lmf_data_exposure_subscription_t));
    if (!lmf_data_exposure_subscription_local_var) {
        return NULL;
    }
    memset(lmf_data_exposure_subscription_local_var, 0, sizeof(lmf_data_exposure_subscription_t));
    lmf_data_exposure_subscription_local_var->_library_owned = 1;
    lmf_data_exposure_subscription_local_var->notification_uri = notification_uri;
    lmf_data_exposure_subscription_local_var->notify_correlation_id = notify_correlation_id;
    lmf_data_exposure_subscription_local_var->aoi = aoi;
    lmf_data_exposure_subscription_local_var->recur_time = recur_time;
    lmf_data_exposure_subscription_local_var->num_of_samples = num_of_samples;
    lmf_data_exposure_subscription_local_var->data_sources = data_sources;
    lmf_data_exposure_subscription_local_var->quality_threshold = quality_threshold;
    lmf_data_exposure_subscription_local_var->ml_model_id = ml_model_id;
    lmf_data_exposure_subscription_local_var->expiry_time = expiry_time;
    lmf_data_exposure_subscription_local_var->pru_indication = pru_indication;
    return lmf_data_exposure_subscription_local_var;
}

__attribute__((deprecated)) lmf_data_exposure_subscription_t *lmf_data_exposure_subscription_create(
    char *notification_uri,
    char *notify_correlation_id,
    presence_info_t *aoi,
    recur_time_t *recur_time,
    int *num_of_samples,
    list_t *data_sources,
    location_qo_s_t *quality_threshold,
    int *ml_model_id,
    char *expiry_time,
    int *pru_indication
    ) {
    int *num_of_samples_copy = NULL;
    if (num_of_samples) {
        num_of_samples_copy = malloc(sizeof(int));
        if (num_of_samples_copy) *num_of_samples_copy = *num_of_samples;
    }
    int *ml_model_id_copy = NULL;
    if (ml_model_id) {
        ml_model_id_copy = malloc(sizeof(int));
        if (ml_model_id_copy) *ml_model_id_copy = *ml_model_id;
    }
    int *pru_indication_copy = NULL;
    if (pru_indication) {
        pru_indication_copy = malloc(sizeof(int));
        if (pru_indication_copy) *pru_indication_copy = *pru_indication;
    }
    lmf_data_exposure_subscription_t *result = lmf_data_exposure_subscription_create_internal (
        notification_uri,
        notify_correlation_id,
        aoi,
        recur_time,
        num_of_samples_copy,
        data_sources,
        quality_threshold,
        ml_model_id_copy,
        expiry_time,
        pru_indication_copy
        );
    if (!result) {
        free(num_of_samples_copy);
        free(ml_model_id_copy);
        free(pru_indication_copy);
    }
    return result;
}

void lmf_data_exposure_subscription_free(lmf_data_exposure_subscription_t *lmf_data_exposure_subscription) {
    if(NULL == lmf_data_exposure_subscription){
        return ;
    }
    if(lmf_data_exposure_subscription->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lmf_data_exposure_subscription_free");
        return ;
    }
    listEntry_t *listEntry;
    if (lmf_data_exposure_subscription->notification_uri) {
        free(lmf_data_exposure_subscription->notification_uri);
        lmf_data_exposure_subscription->notification_uri = NULL;
    }
    if (lmf_data_exposure_subscription->notify_correlation_id) {
        free(lmf_data_exposure_subscription->notify_correlation_id);
        lmf_data_exposure_subscription->notify_correlation_id = NULL;
    }
    if (lmf_data_exposure_subscription->aoi) {
        presence_info_free(lmf_data_exposure_subscription->aoi);
        lmf_data_exposure_subscription->aoi = NULL;
    }
    if (lmf_data_exposure_subscription->recur_time) {
        recur_time_free(lmf_data_exposure_subscription->recur_time);
        lmf_data_exposure_subscription->recur_time = NULL;
    }
    if (lmf_data_exposure_subscription->num_of_samples) {
        free(lmf_data_exposure_subscription->num_of_samples);
        lmf_data_exposure_subscription->num_of_samples = NULL;
    }
    if (lmf_data_exposure_subscription->data_sources) {
        list_ForEach(listEntry, lmf_data_exposure_subscription->data_sources) {
            data_source_type_free(listEntry->data);
        }
        list_freeList(lmf_data_exposure_subscription->data_sources);
        lmf_data_exposure_subscription->data_sources = NULL;
    }
    if (lmf_data_exposure_subscription->quality_threshold) {
        location_qo_s_free(lmf_data_exposure_subscription->quality_threshold);
        lmf_data_exposure_subscription->quality_threshold = NULL;
    }
    if (lmf_data_exposure_subscription->ml_model_id) {
        free(lmf_data_exposure_subscription->ml_model_id);
        lmf_data_exposure_subscription->ml_model_id = NULL;
    }
    if (lmf_data_exposure_subscription->expiry_time) {
        free(lmf_data_exposure_subscription->expiry_time);
        lmf_data_exposure_subscription->expiry_time = NULL;
    }
    if (lmf_data_exposure_subscription->pru_indication) {
        free(lmf_data_exposure_subscription->pru_indication);
        lmf_data_exposure_subscription->pru_indication = NULL;
    }
    free(lmf_data_exposure_subscription);
}

cJSON *lmf_data_exposure_subscription_convertToJSON(lmf_data_exposure_subscription_t *lmf_data_exposure_subscription) {
    cJSON *item = cJSON_CreateObject();

    // lmf_data_exposure_subscription->notification_uri
    if (!lmf_data_exposure_subscription->notification_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "notificationUri", lmf_data_exposure_subscription->notification_uri) == NULL) {
    goto fail; //String
    }


    // lmf_data_exposure_subscription->notify_correlation_id
    if (!lmf_data_exposure_subscription->notify_correlation_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "notifyCorrelationId", lmf_data_exposure_subscription->notify_correlation_id) == NULL) {
    goto fail; //String
    }


    // lmf_data_exposure_subscription->aoi
    if (!lmf_data_exposure_subscription->aoi) {
        goto fail;
    }
    cJSON *aoi_local_JSON = presence_info_convertToJSON(lmf_data_exposure_subscription->aoi);
    if(aoi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "aoi", aoi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // lmf_data_exposure_subscription->recur_time
    if(lmf_data_exposure_subscription->recur_time) {
    cJSON *recur_time_local_JSON = recur_time_convertToJSON(lmf_data_exposure_subscription->recur_time);
    if(recur_time_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "recurTime", recur_time_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // lmf_data_exposure_subscription->num_of_samples
    if(lmf_data_exposure_subscription->num_of_samples) {
    if(cJSON_AddNumberToObject(item, "numOfSamples", *lmf_data_exposure_subscription->num_of_samples) == NULL) {
    goto fail; //Numeric
    }
    }


    // lmf_data_exposure_subscription->data_sources
    if(lmf_data_exposure_subscription->data_sources) {
    cJSON *data_sources = cJSON_AddArrayToObject(item, "dataSources");
    if(data_sources == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *data_sourcesListEntry;
    if (lmf_data_exposure_subscription->data_sources) {
    list_ForEach(data_sourcesListEntry, lmf_data_exposure_subscription->data_sources) {
    cJSON *itemLocal = data_source_type_convertToJSON(data_sourcesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data_sources, itemLocal);
    }
    }
    }


    // lmf_data_exposure_subscription->quality_threshold
    if(lmf_data_exposure_subscription->quality_threshold) {
    cJSON *quality_threshold_local_JSON = location_qo_s_convertToJSON(lmf_data_exposure_subscription->quality_threshold);
    if(quality_threshold_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "qualityThreshold", quality_threshold_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // lmf_data_exposure_subscription->ml_model_id
    if(lmf_data_exposure_subscription->ml_model_id) {
    if(cJSON_AddNumberToObject(item, "mlModelId", *lmf_data_exposure_subscription->ml_model_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // lmf_data_exposure_subscription->expiry_time
    if(lmf_data_exposure_subscription->expiry_time) {
    if(cJSON_AddStringToObject(item, "expiryTime", lmf_data_exposure_subscription->expiry_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // lmf_data_exposure_subscription->pru_indication
    if(lmf_data_exposure_subscription->pru_indication) {
    if(cJSON_AddBoolToObject(item, "pruIndication", *lmf_data_exposure_subscription->pru_indication) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lmf_data_exposure_subscription_t *lmf_data_exposure_subscription_parseFromJSON(cJSON *lmf_data_exposure_subscriptionJSON){

    lmf_data_exposure_subscription_t *lmf_data_exposure_subscription_local_var = NULL;

    char *notification_uri_local_str = NULL;

    char *notify_correlation_id_local_str = NULL;

    // define the local variable for lmf_data_exposure_subscription->aoi
    presence_info_t *aoi_local_nonprim = NULL;

    // define the local variable for lmf_data_exposure_subscription->recur_time
    recur_time_t *recur_time_local_nonprim = NULL;

    // define the local variable for lmf_data_exposure_subscription->num_of_samples
    int *num_of_samples_local_var = NULL;

    // define the local list for lmf_data_exposure_subscription->data_sources
    list_t *data_sourcesList = NULL;

    // define the local variable for lmf_data_exposure_subscription->quality_threshold
    location_qo_s_t *quality_threshold_local_nonprim = NULL;

    // define the local variable for lmf_data_exposure_subscription->ml_model_id
    int *ml_model_id_local_var = NULL;

    char *expiry_time_local_str = NULL;

    // define the local variable for lmf_data_exposure_subscription->pru_indication
    int *pru_indication_local_var = NULL;

    // lmf_data_exposure_subscription->notification_uri
    cJSON *notification_uri = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "notificationUri");
    if (cJSON_IsNull(notification_uri)) {
        notification_uri = NULL;
    }
    if (!notification_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(notification_uri))
    {
    goto end; //String
    }

    // lmf_data_exposure_subscription->notify_correlation_id
    cJSON *notify_correlation_id = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "notifyCorrelationId");
    if (cJSON_IsNull(notify_correlation_id)) {
        notify_correlation_id = NULL;
    }
    if (!notify_correlation_id) {
        goto end;
    }

    
    if(!cJSON_IsString(notify_correlation_id))
    {
    goto end; //String
    }

    // lmf_data_exposure_subscription->aoi
    cJSON *aoi = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "aoi");
    if (cJSON_IsNull(aoi)) {
        aoi = NULL;
    }
    if (!aoi) {
        goto end;
    }

    
    aoi_local_nonprim = presence_info_parseFromJSON(aoi); //nonprimitive

    // lmf_data_exposure_subscription->recur_time
    cJSON *recur_time = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "recurTime");
    if (cJSON_IsNull(recur_time)) {
        recur_time = NULL;
    }
    if (recur_time) { 
    recur_time_local_nonprim = recur_time_parseFromJSON(recur_time); //nonprimitive
    }

    // lmf_data_exposure_subscription->num_of_samples
    cJSON *num_of_samples = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "numOfSamples");
    if (cJSON_IsNull(num_of_samples)) {
        num_of_samples = NULL;
    }
    if (num_of_samples) { 
    if(!cJSON_IsNumber(num_of_samples))
    {
    goto end; //Numeric
    }
    num_of_samples_local_var = malloc(sizeof(int));
    if(!num_of_samples_local_var)
    {
        goto end;
    }
    *num_of_samples_local_var = num_of_samples->valuedouble;
    }

    // lmf_data_exposure_subscription->data_sources
    cJSON *data_sources = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "dataSources");
    if (cJSON_IsNull(data_sources)) {
        data_sources = NULL;
    }
    if (data_sources) { 
    cJSON *data_sources_local_nonprimitive = NULL;
    if(!cJSON_IsArray(data_sources)){
        goto end; //nonprimitive container
    }

    data_sourcesList = list_createList();

    cJSON_ArrayForEach(data_sources_local_nonprimitive,data_sources )
    {
        if(!cJSON_IsObject(data_sources_local_nonprimitive)){
            goto end;
        }
        data_source_type_t *data_sourcesItem = data_source_type_parseFromJSON(data_sources_local_nonprimitive);

        list_addElement(data_sourcesList, data_sourcesItem);
    }
    }

    // lmf_data_exposure_subscription->quality_threshold
    cJSON *quality_threshold = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "qualityThreshold");
    if (cJSON_IsNull(quality_threshold)) {
        quality_threshold = NULL;
    }
    if (quality_threshold) { 
    quality_threshold_local_nonprim = location_qo_s_parseFromJSON(quality_threshold); //nonprimitive
    }

    // lmf_data_exposure_subscription->ml_model_id
    cJSON *ml_model_id = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "mlModelId");
    if (cJSON_IsNull(ml_model_id)) {
        ml_model_id = NULL;
    }
    if (ml_model_id) { 
    if(!cJSON_IsNumber(ml_model_id))
    {
    goto end; //Numeric
    }
    ml_model_id_local_var = malloc(sizeof(int));
    if(!ml_model_id_local_var)
    {
        goto end;
    }
    *ml_model_id_local_var = ml_model_id->valuedouble;
    }

    // lmf_data_exposure_subscription->expiry_time
    cJSON *expiry_time = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "expiryTime");
    if (cJSON_IsNull(expiry_time)) {
        expiry_time = NULL;
    }
    if (expiry_time) { 
    if(!cJSON_IsString(expiry_time) && !cJSON_IsNull(expiry_time))
    {
    goto end; //DateTime
    }
    }

    // lmf_data_exposure_subscription->pru_indication
    cJSON *pru_indication = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_subscriptionJSON, "pruIndication");
    if (cJSON_IsNull(pru_indication)) {
        pru_indication = NULL;
    }
    if (pru_indication) { 
    if(!cJSON_IsBool(pru_indication))
    {
    goto end; //Bool
    }
    pru_indication_local_var = malloc(sizeof(int));
    if(!pru_indication_local_var)
    {
        goto end;
    }
    *pru_indication_local_var = pru_indication->valueint;
    }


    if (notification_uri && !cJSON_IsNull(notification_uri)) notification_uri_local_str = strdup(notification_uri->valuestring);
    if (notify_correlation_id && !cJSON_IsNull(notify_correlation_id)) notify_correlation_id_local_str = strdup(notify_correlation_id->valuestring);
    if (expiry_time && !cJSON_IsNull(expiry_time)) expiry_time_local_str = strdup(expiry_time->valuestring);

    lmf_data_exposure_subscription_local_var = lmf_data_exposure_subscription_create_internal (
        notification_uri_local_str,
        notify_correlation_id_local_str,
        aoi_local_nonprim,
        recur_time ? recur_time_local_nonprim : NULL,
        num_of_samples_local_var,
        data_sources ? data_sourcesList : NULL,
        quality_threshold ? quality_threshold_local_nonprim : NULL,
        ml_model_id_local_var,
        expiry_time_local_str,
        pru_indication_local_var
        );

    if (!lmf_data_exposure_subscription_local_var) {
        goto end;
    }

    return lmf_data_exposure_subscription_local_var;
end:
    if (notification_uri_local_str) {
        free(notification_uri_local_str);
        notification_uri_local_str = NULL;
    }
    if (notify_correlation_id_local_str) {
        free(notify_correlation_id_local_str);
        notify_correlation_id_local_str = NULL;
    }
    if (aoi_local_nonprim) {
        presence_info_free(aoi_local_nonprim);
        aoi_local_nonprim = NULL;
    }
    if (recur_time_local_nonprim) {
        recur_time_free(recur_time_local_nonprim);
        recur_time_local_nonprim = NULL;
    }
    if (num_of_samples_local_var) {
        free(num_of_samples_local_var);
        num_of_samples_local_var = NULL;
    }
    if (data_sourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, data_sourcesList) {
            data_source_type_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(data_sourcesList);
        data_sourcesList = NULL;
    }
    if (quality_threshold_local_nonprim) {
        location_qo_s_free(quality_threshold_local_nonprim);
        quality_threshold_local_nonprim = NULL;
    }
    if (ml_model_id_local_var) {
        free(ml_model_id_local_var);
        ml_model_id_local_var = NULL;
    }
    if (expiry_time_local_str) {
        free(expiry_time_local_str);
        expiry_time_local_str = NULL;
    }
    if (pru_indication_local_var) {
        free(pru_indication_local_var);
        pru_indication_local_var = NULL;
    }
    return NULL;

}
