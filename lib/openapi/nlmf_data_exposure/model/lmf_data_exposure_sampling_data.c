#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_sampling_data.h"



static lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data_create_internal(
    char *timestamp,
    loc_measurements_t *loc_measure_data,
    location_data_t *ground_truth,
    float *quality_indicator,
    location_data_t *ml_loc_estimate
    ) {
    lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data_local_var = malloc(sizeof(lmf_data_exposure_sampling_data_t));
    if (!lmf_data_exposure_sampling_data_local_var) {
        return NULL;
    }
    memset(lmf_data_exposure_sampling_data_local_var, 0, sizeof(lmf_data_exposure_sampling_data_t));
    lmf_data_exposure_sampling_data_local_var->_library_owned = 1;
    lmf_data_exposure_sampling_data_local_var->timestamp = timestamp;
    lmf_data_exposure_sampling_data_local_var->loc_measure_data = loc_measure_data;
    lmf_data_exposure_sampling_data_local_var->ground_truth = ground_truth;
    lmf_data_exposure_sampling_data_local_var->quality_indicator = quality_indicator;
    lmf_data_exposure_sampling_data_local_var->ml_loc_estimate = ml_loc_estimate;
    return lmf_data_exposure_sampling_data_local_var;
}

__attribute__((deprecated)) lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data_create(
    char *timestamp,
    loc_measurements_t *loc_measure_data,
    location_data_t *ground_truth,
    float *quality_indicator,
    location_data_t *ml_loc_estimate
    ) {
    float *quality_indicator_copy = NULL;
    if (quality_indicator) {
        quality_indicator_copy = malloc(sizeof(float));
        if (quality_indicator_copy) *quality_indicator_copy = *quality_indicator;
    }
    lmf_data_exposure_sampling_data_t *result = lmf_data_exposure_sampling_data_create_internal (
        timestamp,
        loc_measure_data,
        ground_truth,
        quality_indicator_copy,
        ml_loc_estimate
        );
    if (!result) {
        free(quality_indicator_copy);
    }
    return result;
}

void lmf_data_exposure_sampling_data_free(lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data) {
    if(NULL == lmf_data_exposure_sampling_data){
        return ;
    }
    if(lmf_data_exposure_sampling_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lmf_data_exposure_sampling_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (lmf_data_exposure_sampling_data->timestamp) {
        free(lmf_data_exposure_sampling_data->timestamp);
        lmf_data_exposure_sampling_data->timestamp = NULL;
    }
    if (lmf_data_exposure_sampling_data->loc_measure_data) {
        loc_measurements_free(lmf_data_exposure_sampling_data->loc_measure_data);
        lmf_data_exposure_sampling_data->loc_measure_data = NULL;
    }
    if (lmf_data_exposure_sampling_data->ground_truth) {
        location_data_free(lmf_data_exposure_sampling_data->ground_truth);
        lmf_data_exposure_sampling_data->ground_truth = NULL;
    }
    if (lmf_data_exposure_sampling_data->quality_indicator) {
        free(lmf_data_exposure_sampling_data->quality_indicator);
        lmf_data_exposure_sampling_data->quality_indicator = NULL;
    }
    if (lmf_data_exposure_sampling_data->ml_loc_estimate) {
        location_data_free(lmf_data_exposure_sampling_data->ml_loc_estimate);
        lmf_data_exposure_sampling_data->ml_loc_estimate = NULL;
    }
    free(lmf_data_exposure_sampling_data);
}

cJSON *lmf_data_exposure_sampling_data_convertToJSON(lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data) {
    cJSON *item = cJSON_CreateObject();

    // lmf_data_exposure_sampling_data->timestamp
    if (!lmf_data_exposure_sampling_data->timestamp) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "timestamp", lmf_data_exposure_sampling_data->timestamp) == NULL) {
    goto fail; //Date-Time
    }


    // lmf_data_exposure_sampling_data->loc_measure_data
    if (!lmf_data_exposure_sampling_data->loc_measure_data) {
        goto fail;
    }
    cJSON *loc_measure_data_local_JSON = loc_measurements_convertToJSON(lmf_data_exposure_sampling_data->loc_measure_data);
    if(loc_measure_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "locMeasureData", loc_measure_data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // lmf_data_exposure_sampling_data->ground_truth
    if (!lmf_data_exposure_sampling_data->ground_truth) {
        goto fail;
    }
    cJSON *ground_truth_local_JSON = location_data_convertToJSON(lmf_data_exposure_sampling_data->ground_truth);
    if(ground_truth_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "groundTruth", ground_truth_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // lmf_data_exposure_sampling_data->quality_indicator
    if(lmf_data_exposure_sampling_data->quality_indicator) {
    if(cJSON_AddNumberToObject(item, "qualityIndicator", *lmf_data_exposure_sampling_data->quality_indicator) == NULL) {
    goto fail; //Numeric
    }
    }


    // lmf_data_exposure_sampling_data->ml_loc_estimate
    if(lmf_data_exposure_sampling_data->ml_loc_estimate) {
    cJSON *ml_loc_estimate_local_JSON = location_data_convertToJSON(lmf_data_exposure_sampling_data->ml_loc_estimate);
    if(ml_loc_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "mlLocEstimate", ml_loc_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data_parseFromJSON(cJSON *lmf_data_exposure_sampling_dataJSON){

    lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data_local_var = NULL;

    char *timestamp_local_str = NULL;

    // define the local variable for lmf_data_exposure_sampling_data->loc_measure_data
    loc_measurements_t *loc_measure_data_local_nonprim = NULL;

    // define the local variable for lmf_data_exposure_sampling_data->ground_truth
    location_data_t *ground_truth_local_nonprim = NULL;

    // define the local variable for lmf_data_exposure_sampling_data->quality_indicator
    float *quality_indicator_local_var = NULL;

    // define the local variable for lmf_data_exposure_sampling_data->ml_loc_estimate
    location_data_t *ml_loc_estimate_local_nonprim = NULL;

    // lmf_data_exposure_sampling_data->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "timestamp");
    if (cJSON_IsNull(timestamp)) {
        timestamp = NULL;
    }
    if (!timestamp) {
        goto end;
    }

    
    if(!cJSON_IsString(timestamp) && !cJSON_IsNull(timestamp))
    {
    goto end; //DateTime
    }

    // lmf_data_exposure_sampling_data->loc_measure_data
    cJSON *loc_measure_data = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "locMeasureData");
    if (cJSON_IsNull(loc_measure_data)) {
        loc_measure_data = NULL;
    }
    if (!loc_measure_data) {
        goto end;
    }

    
    loc_measure_data_local_nonprim = loc_measurements_parseFromJSON(loc_measure_data); //nonprimitive

    // lmf_data_exposure_sampling_data->ground_truth
    cJSON *ground_truth = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "groundTruth");
    if (cJSON_IsNull(ground_truth)) {
        ground_truth = NULL;
    }
    if (!ground_truth) {
        goto end;
    }

    
    ground_truth_local_nonprim = location_data_parseFromJSON(ground_truth); //nonprimitive

    // lmf_data_exposure_sampling_data->quality_indicator
    cJSON *quality_indicator = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "qualityIndicator");
    if (cJSON_IsNull(quality_indicator)) {
        quality_indicator = NULL;
    }
    if (quality_indicator) { 
    if(!cJSON_IsNumber(quality_indicator))
    {
    goto end; //Numeric
    }
    quality_indicator_local_var = malloc(sizeof(float));
    if(!quality_indicator_local_var)
    {
        goto end;
    }
    *quality_indicator_local_var = quality_indicator->valuedouble;
    }

    // lmf_data_exposure_sampling_data->ml_loc_estimate
    cJSON *ml_loc_estimate = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_sampling_dataJSON, "mlLocEstimate");
    if (cJSON_IsNull(ml_loc_estimate)) {
        ml_loc_estimate = NULL;
    }
    if (ml_loc_estimate) { 
    ml_loc_estimate_local_nonprim = location_data_parseFromJSON(ml_loc_estimate); //nonprimitive
    }


    if (timestamp && !cJSON_IsNull(timestamp)) timestamp_local_str = strdup(timestamp->valuestring);

    lmf_data_exposure_sampling_data_local_var = lmf_data_exposure_sampling_data_create_internal (
        timestamp_local_str,
        loc_measure_data_local_nonprim,
        ground_truth_local_nonprim,
        quality_indicator_local_var,
        ml_loc_estimate ? ml_loc_estimate_local_nonprim : NULL
        );

    if (!lmf_data_exposure_sampling_data_local_var) {
        goto end;
    }

    return lmf_data_exposure_sampling_data_local_var;
end:
    if (timestamp_local_str) {
        free(timestamp_local_str);
        timestamp_local_str = NULL;
    }
    if (loc_measure_data_local_nonprim) {
        loc_measurements_free(loc_measure_data_local_nonprim);
        loc_measure_data_local_nonprim = NULL;
    }
    if (ground_truth_local_nonprim) {
        location_data_free(ground_truth_local_nonprim);
        ground_truth_local_nonprim = NULL;
    }
    if (quality_indicator_local_var) {
        free(quality_indicator_local_var);
        quality_indicator_local_var = NULL;
    }
    if (ml_loc_estimate_local_nonprim) {
        location_data_free(ml_loc_estimate_local_nonprim);
        ml_loc_estimate_local_nonprim = NULL;
    }
    return NULL;

}
