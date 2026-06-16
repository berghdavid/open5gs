#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_notify_data_ext.h"



static event_notify_data_ext_t *event_notify_data_ext_create_internal(
    reported_event_type_t *reported_event_type,
    char *supi,
    char *gpsi,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    char *lir_reference,
    geographic_area_t *location_estimate,
    int *age_of_location_estimate,
    char *timestamp_of_location_estimate,
    civic_address_t *civic_address,
    local_area_t *local_location_estimate,
    list_t *positioning_data_list,
    list_t *gnss_positioning_data_list,
    char *serving_lm_fidentification,
    termination_cause_t *termination_cause,
    velocity_estimate_t *velocity_estimate,
    double *altitude,
    minor_location_qo_s_t *achieved_qos,
    char *supported_features,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    high_accuracy_gnss_metrics_t *ha_gnss_metrics,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    int *up_loc_rep_stat_af,
    char *related_applicationlayer_id,
    range_direction_t *distance_direction,
    model_2_d_relative_location_t *_2d_relative_location,
    model_3_d_relative_location_t *_3d_relative_location,
    velocity_estimate_t *relative_velocity,
    integrity_result_t *integrity_result,
    list_t *add_event_notify_datas
    ) {
    event_notify_data_ext_t *event_notify_data_ext_local_var = malloc(sizeof(event_notify_data_ext_t));
    if (!event_notify_data_ext_local_var) {
        return NULL;
    }
    memset(event_notify_data_ext_local_var, 0, sizeof(event_notify_data_ext_t));
    event_notify_data_ext_local_var->_library_owned = 1;
    event_notify_data_ext_local_var->reported_event_type = reported_event_type;
    event_notify_data_ext_local_var->supi = supi;
    event_notify_data_ext_local_var->gpsi = gpsi;
    event_notify_data_ext_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
    event_notify_data_ext_local_var->ldr_reference = ldr_reference;
    event_notify_data_ext_local_var->lir_reference = lir_reference;
    event_notify_data_ext_local_var->location_estimate = location_estimate;
    event_notify_data_ext_local_var->age_of_location_estimate = age_of_location_estimate;
    event_notify_data_ext_local_var->timestamp_of_location_estimate = timestamp_of_location_estimate;
    event_notify_data_ext_local_var->civic_address = civic_address;
    event_notify_data_ext_local_var->local_location_estimate = local_location_estimate;
    event_notify_data_ext_local_var->positioning_data_list = positioning_data_list;
    event_notify_data_ext_local_var->gnss_positioning_data_list = gnss_positioning_data_list;
    event_notify_data_ext_local_var->serving_lm_fidentification = serving_lm_fidentification;
    event_notify_data_ext_local_var->termination_cause = termination_cause;
    event_notify_data_ext_local_var->velocity_estimate = velocity_estimate;
    event_notify_data_ext_local_var->altitude = altitude;
    event_notify_data_ext_local_var->achieved_qos = achieved_qos;
    event_notify_data_ext_local_var->supported_features = supported_features;
    event_notify_data_ext_local_var->indoor_outdoor_ind = indoor_outdoor_ind;
    event_notify_data_ext_local_var->ha_gnss_metrics = ha_gnss_metrics;
    event_notify_data_ext_local_var->los_nlos_measure_ind = los_nlos_measure_ind;
    event_notify_data_ext_local_var->up_loc_rep_stat_af = up_loc_rep_stat_af;
    event_notify_data_ext_local_var->related_applicationlayer_id = related_applicationlayer_id;
    event_notify_data_ext_local_var->distance_direction = distance_direction;
    event_notify_data_ext_local_var->_2d_relative_location = _2d_relative_location;
    event_notify_data_ext_local_var->_3d_relative_location = _3d_relative_location;
    event_notify_data_ext_local_var->relative_velocity = relative_velocity;
    event_notify_data_ext_local_var->integrity_result = integrity_result;
    event_notify_data_ext_local_var->add_event_notify_datas = add_event_notify_datas;
    return event_notify_data_ext_local_var;
}

__attribute__((deprecated)) event_notify_data_ext_t *event_notify_data_ext_create(
    reported_event_type_t *reported_event_type,
    char *supi,
    char *gpsi,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    char *lir_reference,
    geographic_area_t *location_estimate,
    int *age_of_location_estimate,
    char *timestamp_of_location_estimate,
    civic_address_t *civic_address,
    local_area_t *local_location_estimate,
    list_t *positioning_data_list,
    list_t *gnss_positioning_data_list,
    char *serving_lm_fidentification,
    termination_cause_t *termination_cause,
    velocity_estimate_t *velocity_estimate,
    double *altitude,
    minor_location_qo_s_t *achieved_qos,
    char *supported_features,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    high_accuracy_gnss_metrics_t *ha_gnss_metrics,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    int *up_loc_rep_stat_af,
    char *related_applicationlayer_id,
    range_direction_t *distance_direction,
    model_2_d_relative_location_t *_2d_relative_location,
    model_3_d_relative_location_t *_3d_relative_location,
    velocity_estimate_t *relative_velocity,
    integrity_result_t *integrity_result,
    list_t *add_event_notify_datas
    ) {
    int *age_of_location_estimate_copy = NULL;
    if (age_of_location_estimate) {
        age_of_location_estimate_copy = malloc(sizeof(int));
        if (age_of_location_estimate_copy) *age_of_location_estimate_copy = *age_of_location_estimate;
    }
    double *altitude_copy = NULL;
    if (altitude) {
        altitude_copy = malloc(sizeof(double));
        if (altitude_copy) *altitude_copy = *altitude;
    }
    int *up_loc_rep_stat_af_copy = NULL;
    if (up_loc_rep_stat_af) {
        up_loc_rep_stat_af_copy = malloc(sizeof(int));
        if (up_loc_rep_stat_af_copy) *up_loc_rep_stat_af_copy = *up_loc_rep_stat_af;
    }
    event_notify_data_ext_t *result = event_notify_data_ext_create_internal (
        reported_event_type,
        supi,
        gpsi,
        hgmlc_call_back_uri,
        ldr_reference,
        lir_reference,
        location_estimate,
        age_of_location_estimate_copy,
        timestamp_of_location_estimate,
        civic_address,
        local_location_estimate,
        positioning_data_list,
        gnss_positioning_data_list,
        serving_lm_fidentification,
        termination_cause,
        velocity_estimate,
        altitude_copy,
        achieved_qos,
        supported_features,
        indoor_outdoor_ind,
        ha_gnss_metrics,
        los_nlos_measure_ind,
        up_loc_rep_stat_af_copy,
        related_applicationlayer_id,
        distance_direction,
        _2d_relative_location,
        _3d_relative_location,
        relative_velocity,
        integrity_result,
        add_event_notify_datas
        );
    if (!result) {
        free(age_of_location_estimate_copy);
        free(altitude_copy);
        free(up_loc_rep_stat_af_copy);
    }
    return result;
}

void event_notify_data_ext_free(event_notify_data_ext_t *event_notify_data_ext) {
    if(NULL == event_notify_data_ext){
        return ;
    }
    if(event_notify_data_ext->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "event_notify_data_ext_free");
        return ;
    }
    listEntry_t *listEntry;
    if (event_notify_data_ext->reported_event_type) {
        reported_event_type_free(event_notify_data_ext->reported_event_type);
        event_notify_data_ext->reported_event_type = NULL;
    }
    if (event_notify_data_ext->supi) {
        free(event_notify_data_ext->supi);
        event_notify_data_ext->supi = NULL;
    }
    if (event_notify_data_ext->gpsi) {
        free(event_notify_data_ext->gpsi);
        event_notify_data_ext->gpsi = NULL;
    }
    if (event_notify_data_ext->hgmlc_call_back_uri) {
        free(event_notify_data_ext->hgmlc_call_back_uri);
        event_notify_data_ext->hgmlc_call_back_uri = NULL;
    }
    if (event_notify_data_ext->ldr_reference) {
        free(event_notify_data_ext->ldr_reference);
        event_notify_data_ext->ldr_reference = NULL;
    }
    if (event_notify_data_ext->lir_reference) {
        free(event_notify_data_ext->lir_reference);
        event_notify_data_ext->lir_reference = NULL;
    }
    if (event_notify_data_ext->location_estimate) {
        geographic_area_free(event_notify_data_ext->location_estimate);
        event_notify_data_ext->location_estimate = NULL;
    }
    if (event_notify_data_ext->age_of_location_estimate) {
        free(event_notify_data_ext->age_of_location_estimate);
        event_notify_data_ext->age_of_location_estimate = NULL;
    }
    if (event_notify_data_ext->timestamp_of_location_estimate) {
        free(event_notify_data_ext->timestamp_of_location_estimate);
        event_notify_data_ext->timestamp_of_location_estimate = NULL;
    }
    if (event_notify_data_ext->civic_address) {
        civic_address_free(event_notify_data_ext->civic_address);
        event_notify_data_ext->civic_address = NULL;
    }
    if (event_notify_data_ext->local_location_estimate) {
        local_area_free(event_notify_data_ext->local_location_estimate);
        event_notify_data_ext->local_location_estimate = NULL;
    }
    if (event_notify_data_ext->positioning_data_list) {
        list_ForEach(listEntry, event_notify_data_ext->positioning_data_list) {
            positioning_method_and_usage_free(listEntry->data);
        }
        list_freeList(event_notify_data_ext->positioning_data_list);
        event_notify_data_ext->positioning_data_list = NULL;
    }
    if (event_notify_data_ext->gnss_positioning_data_list) {
        list_ForEach(listEntry, event_notify_data_ext->gnss_positioning_data_list) {
            gnss_positioning_method_and_usage_free(listEntry->data);
        }
        list_freeList(event_notify_data_ext->gnss_positioning_data_list);
        event_notify_data_ext->gnss_positioning_data_list = NULL;
    }
    if (event_notify_data_ext->serving_lm_fidentification) {
        free(event_notify_data_ext->serving_lm_fidentification);
        event_notify_data_ext->serving_lm_fidentification = NULL;
    }
    if (event_notify_data_ext->termination_cause) {
        termination_cause_free(event_notify_data_ext->termination_cause);
        event_notify_data_ext->termination_cause = NULL;
    }
    if (event_notify_data_ext->velocity_estimate) {
        velocity_estimate_free(event_notify_data_ext->velocity_estimate);
        event_notify_data_ext->velocity_estimate = NULL;
    }
    if (event_notify_data_ext->altitude) {
        free(event_notify_data_ext->altitude);
        event_notify_data_ext->altitude = NULL;
    }
    if (event_notify_data_ext->achieved_qos) {
        minor_location_qo_s_free(event_notify_data_ext->achieved_qos);
        event_notify_data_ext->achieved_qos = NULL;
    }
    if (event_notify_data_ext->supported_features) {
        free(event_notify_data_ext->supported_features);
        event_notify_data_ext->supported_features = NULL;
    }
    if (event_notify_data_ext->indoor_outdoor_ind) {
        indoor_outdoor_ind_free(event_notify_data_ext->indoor_outdoor_ind);
        event_notify_data_ext->indoor_outdoor_ind = NULL;
    }
    if (event_notify_data_ext->ha_gnss_metrics) {
        high_accuracy_gnss_metrics_free(event_notify_data_ext->ha_gnss_metrics);
        event_notify_data_ext->ha_gnss_metrics = NULL;
    }
    if (event_notify_data_ext->los_nlos_measure_ind) {
        los_nlos_measure_ind_free(event_notify_data_ext->los_nlos_measure_ind);
        event_notify_data_ext->los_nlos_measure_ind = NULL;
    }
    if (event_notify_data_ext->up_loc_rep_stat_af) {
        free(event_notify_data_ext->up_loc_rep_stat_af);
        event_notify_data_ext->up_loc_rep_stat_af = NULL;
    }
    if (event_notify_data_ext->related_applicationlayer_id) {
        free(event_notify_data_ext->related_applicationlayer_id);
        event_notify_data_ext->related_applicationlayer_id = NULL;
    }
    if (event_notify_data_ext->distance_direction) {
        range_direction_free(event_notify_data_ext->distance_direction);
        event_notify_data_ext->distance_direction = NULL;
    }
    if (event_notify_data_ext->_2d_relative_location) {
        model_2_d_relative_location_free(event_notify_data_ext->_2d_relative_location);
        event_notify_data_ext->_2d_relative_location = NULL;
    }
    if (event_notify_data_ext->_3d_relative_location) {
        model_3_d_relative_location_free(event_notify_data_ext->_3d_relative_location);
        event_notify_data_ext->_3d_relative_location = NULL;
    }
    if (event_notify_data_ext->relative_velocity) {
        velocity_estimate_free(event_notify_data_ext->relative_velocity);
        event_notify_data_ext->relative_velocity = NULL;
    }
    if (event_notify_data_ext->integrity_result) {
        integrity_result_free(event_notify_data_ext->integrity_result);
        event_notify_data_ext->integrity_result = NULL;
    }
    if (event_notify_data_ext->add_event_notify_datas) {
        list_ForEach(listEntry, event_notify_data_ext->add_event_notify_datas) {
            event_notify_data_free(listEntry->data);
        }
        list_freeList(event_notify_data_ext->add_event_notify_datas);
        event_notify_data_ext->add_event_notify_datas = NULL;
    }
    free(event_notify_data_ext);
}

cJSON *event_notify_data_ext_convertToJSON(event_notify_data_ext_t *event_notify_data_ext) {
    cJSON *item = cJSON_CreateObject();

    // event_notify_data_ext->reported_event_type
    if (!event_notify_data_ext->reported_event_type) {
        goto fail;
    }
    cJSON *reported_event_type_local_JSON = reported_event_type_convertToJSON(event_notify_data_ext->reported_event_type);
    if(reported_event_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reportedEventType", reported_event_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // event_notify_data_ext->supi
    if(event_notify_data_ext->supi) {
    if(cJSON_AddStringToObject(item, "supi", event_notify_data_ext->supi) == NULL) {
    goto fail; //String
    }
    }


    // event_notify_data_ext->gpsi
    if(event_notify_data_ext->gpsi) {
    if(cJSON_AddStringToObject(item, "gpsi", event_notify_data_ext->gpsi) == NULL) {
    goto fail; //String
    }
    }


    // event_notify_data_ext->hgmlc_call_back_uri
    if(event_notify_data_ext->hgmlc_call_back_uri) {
    if(cJSON_AddStringToObject(item, "hgmlcCallBackURI", event_notify_data_ext->hgmlc_call_back_uri) == NULL) {
    goto fail; //String
    }
    }


    // event_notify_data_ext->ldr_reference
    if (!event_notify_data_ext->ldr_reference) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ldrReference", event_notify_data_ext->ldr_reference) == NULL) {
    goto fail; //String
    }


    // event_notify_data_ext->lir_reference
    if(event_notify_data_ext->lir_reference) {
    if(cJSON_AddStringToObject(item, "lirReference", event_notify_data_ext->lir_reference) == NULL) {
    goto fail; //String
    }
    }


    // event_notify_data_ext->location_estimate
    if(event_notify_data_ext->location_estimate) {
    cJSON *location_estimate_local_JSON = geographic_area_convertToJSON(event_notify_data_ext->location_estimate);
    if(location_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "locationEstimate", location_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->age_of_location_estimate
    if(event_notify_data_ext->age_of_location_estimate) {
    if(cJSON_AddNumberToObject(item, "ageOfLocationEstimate", *event_notify_data_ext->age_of_location_estimate) == NULL) {
    goto fail; //Numeric
    }
    }


    // event_notify_data_ext->timestamp_of_location_estimate
    if(event_notify_data_ext->timestamp_of_location_estimate) {
    if(cJSON_AddStringToObject(item, "timestampOfLocationEstimate", event_notify_data_ext->timestamp_of_location_estimate) == NULL) {
    goto fail; //Date-Time
    }
    }


    // event_notify_data_ext->civic_address
    if(event_notify_data_ext->civic_address) {
    cJSON *civic_address_local_JSON = civic_address_convertToJSON(event_notify_data_ext->civic_address);
    if(civic_address_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "civicAddress", civic_address_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->local_location_estimate
    if(event_notify_data_ext->local_location_estimate) {
    cJSON *local_location_estimate_local_JSON = local_area_convertToJSON(event_notify_data_ext->local_location_estimate);
    if(local_location_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "localLocationEstimate", local_location_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->positioning_data_list
    if(event_notify_data_ext->positioning_data_list) {
    cJSON *positioning_data_list = cJSON_AddArrayToObject(item, "positioningDataList");
    if(positioning_data_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *positioning_data_listListEntry;
    if (event_notify_data_ext->positioning_data_list) {
    list_ForEach(positioning_data_listListEntry, event_notify_data_ext->positioning_data_list) {
    cJSON *itemLocal = positioning_method_and_usage_convertToJSON(positioning_data_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(positioning_data_list, itemLocal);
    }
    }
    }


    // event_notify_data_ext->gnss_positioning_data_list
    if(event_notify_data_ext->gnss_positioning_data_list) {
    cJSON *gnss_positioning_data_list = cJSON_AddArrayToObject(item, "gnssPositioningDataList");
    if(gnss_positioning_data_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *gnss_positioning_data_listListEntry;
    if (event_notify_data_ext->gnss_positioning_data_list) {
    list_ForEach(gnss_positioning_data_listListEntry, event_notify_data_ext->gnss_positioning_data_list) {
    cJSON *itemLocal = gnss_positioning_method_and_usage_convertToJSON(gnss_positioning_data_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(gnss_positioning_data_list, itemLocal);
    }
    }
    }


    // event_notify_data_ext->serving_lm_fidentification
    if(event_notify_data_ext->serving_lm_fidentification) {
    if(cJSON_AddStringToObject(item, "servingLMFidentification", event_notify_data_ext->serving_lm_fidentification) == NULL) {
    goto fail; //String
    }
    }


    // event_notify_data_ext->termination_cause
    if(event_notify_data_ext->termination_cause) {
    cJSON *termination_cause_local_JSON = termination_cause_convertToJSON(event_notify_data_ext->termination_cause);
    if(termination_cause_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "terminationCause", termination_cause_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->velocity_estimate
    if(event_notify_data_ext->velocity_estimate) {
    cJSON *velocity_estimate_local_JSON = velocity_estimate_convertToJSON(event_notify_data_ext->velocity_estimate);
    if(velocity_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "velocityEstimate", velocity_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->altitude
    if(event_notify_data_ext->altitude) {
    if(cJSON_AddNumberToObject(item, "altitude", *event_notify_data_ext->altitude) == NULL) {
    goto fail; //Numeric
    }
    }


    // event_notify_data_ext->achieved_qos
    if(event_notify_data_ext->achieved_qos) {
    cJSON *achieved_qos_local_JSON = minor_location_qo_s_convertToJSON(event_notify_data_ext->achieved_qos);
    if(achieved_qos_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "achievedQos", achieved_qos_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->supported_features
    if(event_notify_data_ext->supported_features) {
    if(cJSON_AddStringToObject(item, "supportedFeatures", event_notify_data_ext->supported_features) == NULL) {
    goto fail; //String
    }
    }


    // event_notify_data_ext->indoor_outdoor_ind
    if(event_notify_data_ext->indoor_outdoor_ind) {
    cJSON *indoor_outdoor_ind_local_JSON = indoor_outdoor_ind_convertToJSON(event_notify_data_ext->indoor_outdoor_ind);
    if(indoor_outdoor_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "indoorOutdoorInd", indoor_outdoor_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->ha_gnss_metrics
    if(event_notify_data_ext->ha_gnss_metrics) {
    cJSON *ha_gnss_metrics_local_JSON = high_accuracy_gnss_metrics_convertToJSON(event_notify_data_ext->ha_gnss_metrics);
    if(ha_gnss_metrics_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "haGnssMetrics", ha_gnss_metrics_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->los_nlos_measure_ind
    if(event_notify_data_ext->los_nlos_measure_ind) {
    cJSON *los_nlos_measure_ind_local_JSON = los_nlos_measure_ind_convertToJSON(event_notify_data_ext->los_nlos_measure_ind);
    if(los_nlos_measure_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "losNlosMeasureInd", los_nlos_measure_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->up_loc_rep_stat_af
    if(event_notify_data_ext->up_loc_rep_stat_af) {
    if(cJSON_AddNumberToObject(item, "upLocRepStatAf", *event_notify_data_ext->up_loc_rep_stat_af) == NULL) {
    goto fail; //Numeric
    }
    }


    // event_notify_data_ext->related_applicationlayer_id
    if(event_notify_data_ext->related_applicationlayer_id) {
    if(cJSON_AddStringToObject(item, "relatedApplicationlayerId", event_notify_data_ext->related_applicationlayer_id) == NULL) {
    goto fail; //String
    }
    }


    // event_notify_data_ext->distance_direction
    if(event_notify_data_ext->distance_direction) {
    cJSON *distance_direction_local_JSON = range_direction_convertToJSON(event_notify_data_ext->distance_direction);
    if(distance_direction_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "distanceDirection", distance_direction_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->_2d_relative_location
    if(event_notify_data_ext->_2d_relative_location) {
    cJSON *_2d_relative_location_local_JSON = model_2_d_relative_location_convertToJSON(event_notify_data_ext->_2d_relative_location);
    if(_2d_relative_location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "2dRelativeLocation", _2d_relative_location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->_3d_relative_location
    if(event_notify_data_ext->_3d_relative_location) {
    cJSON *_3d_relative_location_local_JSON = model_3_d_relative_location_convertToJSON(event_notify_data_ext->_3d_relative_location);
    if(_3d_relative_location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "3dRelativeLocation", _3d_relative_location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->relative_velocity
    if(event_notify_data_ext->relative_velocity) {
    cJSON *relative_velocity_local_JSON = velocity_estimate_convertToJSON(event_notify_data_ext->relative_velocity);
    if(relative_velocity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "relativeVelocity", relative_velocity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->integrity_result
    if(event_notify_data_ext->integrity_result) {
    cJSON *integrity_result_local_JSON = integrity_result_convertToJSON(event_notify_data_ext->integrity_result);
    if(integrity_result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "integrityResult", integrity_result_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // event_notify_data_ext->add_event_notify_datas
    if(event_notify_data_ext->add_event_notify_datas) {
    cJSON *add_event_notify_datas = cJSON_AddArrayToObject(item, "addEventNotifyDatas");
    if(add_event_notify_datas == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *add_event_notify_datasListEntry;
    if (event_notify_data_ext->add_event_notify_datas) {
    list_ForEach(add_event_notify_datasListEntry, event_notify_data_ext->add_event_notify_datas) {
    cJSON *itemLocal = event_notify_data_convertToJSON(add_event_notify_datasListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(add_event_notify_datas, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

event_notify_data_ext_t *event_notify_data_ext_parseFromJSON(cJSON *event_notify_data_extJSON){

    event_notify_data_ext_t *event_notify_data_ext_local_var = NULL;

    // define the local variable for event_notify_data_ext->reported_event_type
    reported_event_type_t *reported_event_type_local_nonprim = NULL;

    char *supi_local_str = NULL;

    char *gpsi_local_str = NULL;

    char *hgmlc_call_back_uri_local_str = NULL;

    char *ldr_reference_local_str = NULL;

    char *lir_reference_local_str = NULL;

    // define the local variable for event_notify_data_ext->location_estimate
    geographic_area_t *location_estimate_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->age_of_location_estimate
    int *age_of_location_estimate_local_var = NULL;

    char *timestamp_of_location_estimate_local_str = NULL;

    // define the local variable for event_notify_data_ext->civic_address
    civic_address_t *civic_address_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->local_location_estimate
    local_area_t *local_location_estimate_local_nonprim = NULL;

    // define the local list for event_notify_data_ext->positioning_data_list
    list_t *positioning_data_listList = NULL;

    // define the local list for event_notify_data_ext->gnss_positioning_data_list
    list_t *gnss_positioning_data_listList = NULL;

    char *serving_lm_fidentification_local_str = NULL;

    // define the local variable for event_notify_data_ext->termination_cause
    termination_cause_t *termination_cause_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->velocity_estimate
    velocity_estimate_t *velocity_estimate_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->altitude
    double *altitude_local_var = NULL;

    // define the local variable for event_notify_data_ext->achieved_qos
    minor_location_qo_s_t *achieved_qos_local_nonprim = NULL;

    char *supported_features_local_str = NULL;

    // define the local variable for event_notify_data_ext->indoor_outdoor_ind
    indoor_outdoor_ind_t *indoor_outdoor_ind_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->ha_gnss_metrics
    high_accuracy_gnss_metrics_t *ha_gnss_metrics_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->los_nlos_measure_ind
    los_nlos_measure_ind_t *los_nlos_measure_ind_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->up_loc_rep_stat_af
    int *up_loc_rep_stat_af_local_var = NULL;

    char *related_applicationlayer_id_local_str = NULL;

    // define the local variable for event_notify_data_ext->distance_direction
    range_direction_t *distance_direction_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->_2d_relative_location
    model_2_d_relative_location_t *_2d_relative_location_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->_3d_relative_location
    model_3_d_relative_location_t *_3d_relative_location_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->relative_velocity
    velocity_estimate_t *relative_velocity_local_nonprim = NULL;

    // define the local variable for event_notify_data_ext->integrity_result
    integrity_result_t *integrity_result_local_nonprim = NULL;

    // define the local list for event_notify_data_ext->add_event_notify_datas
    list_t *add_event_notify_datasList = NULL;

    // event_notify_data_ext->reported_event_type
    cJSON *reported_event_type = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "reportedEventType");
    if (cJSON_IsNull(reported_event_type)) {
        reported_event_type = NULL;
    }
    if (!reported_event_type) {
        goto end;
    }

    
    reported_event_type_local_nonprim = reported_event_type_parseFromJSON(reported_event_type); //nonprimitive

    // event_notify_data_ext->supi
    cJSON *supi = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "supi");
    if (cJSON_IsNull(supi)) {
        supi = NULL;
    }
    if (supi) { 
    if(!cJSON_IsString(supi) && !cJSON_IsNull(supi))
    {
    goto end; //String
    }
    }

    // event_notify_data_ext->gpsi
    cJSON *gpsi = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "gpsi");
    if (cJSON_IsNull(gpsi)) {
        gpsi = NULL;
    }
    if (gpsi) { 
    if(!cJSON_IsString(gpsi) && !cJSON_IsNull(gpsi))
    {
    goto end; //String
    }
    }

    // event_notify_data_ext->hgmlc_call_back_uri
    cJSON *hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "hgmlcCallBackURI");
    if (cJSON_IsNull(hgmlc_call_back_uri)) {
        hgmlc_call_back_uri = NULL;
    }
    if (hgmlc_call_back_uri) { 
    if(!cJSON_IsString(hgmlc_call_back_uri) && !cJSON_IsNull(hgmlc_call_back_uri))
    {
    goto end; //String
    }
    }

    // event_notify_data_ext->ldr_reference
    cJSON *ldr_reference = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "ldrReference");
    if (cJSON_IsNull(ldr_reference)) {
        ldr_reference = NULL;
    }
    if (!ldr_reference) {
        goto end;
    }

    
    if(!cJSON_IsString(ldr_reference))
    {
    goto end; //String
    }

    // event_notify_data_ext->lir_reference
    cJSON *lir_reference = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "lirReference");
    if (cJSON_IsNull(lir_reference)) {
        lir_reference = NULL;
    }
    if (lir_reference) { 
    if(!cJSON_IsString(lir_reference) && !cJSON_IsNull(lir_reference))
    {
    goto end; //String
    }
    }

    // event_notify_data_ext->location_estimate
    cJSON *location_estimate = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "locationEstimate");
    if (cJSON_IsNull(location_estimate)) {
        location_estimate = NULL;
    }
    if (location_estimate) { 
    location_estimate_local_nonprim = geographic_area_parseFromJSON(location_estimate); //nonprimitive
    }

    // event_notify_data_ext->age_of_location_estimate
    cJSON *age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "ageOfLocationEstimate");
    if (cJSON_IsNull(age_of_location_estimate)) {
        age_of_location_estimate = NULL;
    }
    if (age_of_location_estimate) { 
    if(!cJSON_IsNumber(age_of_location_estimate))
    {
    goto end; //Numeric
    }
    age_of_location_estimate_local_var = malloc(sizeof(int));
    if(!age_of_location_estimate_local_var)
    {
        goto end;
    }
    *age_of_location_estimate_local_var = age_of_location_estimate->valuedouble;
    }

    // event_notify_data_ext->timestamp_of_location_estimate
    cJSON *timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "timestampOfLocationEstimate");
    if (cJSON_IsNull(timestamp_of_location_estimate)) {
        timestamp_of_location_estimate = NULL;
    }
    if (timestamp_of_location_estimate) { 
    if(!cJSON_IsString(timestamp_of_location_estimate) && !cJSON_IsNull(timestamp_of_location_estimate))
    {
    goto end; //DateTime
    }
    }

    // event_notify_data_ext->civic_address
    cJSON *civic_address = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "civicAddress");
    if (cJSON_IsNull(civic_address)) {
        civic_address = NULL;
    }
    if (civic_address) { 
    civic_address_local_nonprim = civic_address_parseFromJSON(civic_address); //nonprimitive
    }

    // event_notify_data_ext->local_location_estimate
    cJSON *local_location_estimate = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "localLocationEstimate");
    if (cJSON_IsNull(local_location_estimate)) {
        local_location_estimate = NULL;
    }
    if (local_location_estimate) { 
    local_location_estimate_local_nonprim = local_area_parseFromJSON(local_location_estimate); //nonprimitive
    }

    // event_notify_data_ext->positioning_data_list
    cJSON *positioning_data_list = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "positioningDataList");
    if (cJSON_IsNull(positioning_data_list)) {
        positioning_data_list = NULL;
    }
    if (positioning_data_list) { 
    cJSON *positioning_data_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(positioning_data_list)){
        goto end; //nonprimitive container
    }

    positioning_data_listList = list_createList();

    cJSON_ArrayForEach(positioning_data_list_local_nonprimitive,positioning_data_list )
    {
        if(!cJSON_IsObject(positioning_data_list_local_nonprimitive)){
            goto end;
        }
        positioning_method_and_usage_t *positioning_data_listItem = positioning_method_and_usage_parseFromJSON(positioning_data_list_local_nonprimitive);

        list_addElement(positioning_data_listList, positioning_data_listItem);
    }
    }

    // event_notify_data_ext->gnss_positioning_data_list
    cJSON *gnss_positioning_data_list = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "gnssPositioningDataList");
    if (cJSON_IsNull(gnss_positioning_data_list)) {
        gnss_positioning_data_list = NULL;
    }
    if (gnss_positioning_data_list) { 
    cJSON *gnss_positioning_data_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(gnss_positioning_data_list)){
        goto end; //nonprimitive container
    }

    gnss_positioning_data_listList = list_createList();

    cJSON_ArrayForEach(gnss_positioning_data_list_local_nonprimitive,gnss_positioning_data_list )
    {
        if(!cJSON_IsObject(gnss_positioning_data_list_local_nonprimitive)){
            goto end;
        }
        gnss_positioning_method_and_usage_t *gnss_positioning_data_listItem = gnss_positioning_method_and_usage_parseFromJSON(gnss_positioning_data_list_local_nonprimitive);

        list_addElement(gnss_positioning_data_listList, gnss_positioning_data_listItem);
    }
    }

    // event_notify_data_ext->serving_lm_fidentification
    cJSON *serving_lm_fidentification = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "servingLMFidentification");
    if (cJSON_IsNull(serving_lm_fidentification)) {
        serving_lm_fidentification = NULL;
    }
    if (serving_lm_fidentification) { 
    if(!cJSON_IsString(serving_lm_fidentification) && !cJSON_IsNull(serving_lm_fidentification))
    {
    goto end; //String
    }
    }

    // event_notify_data_ext->termination_cause
    cJSON *termination_cause = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "terminationCause");
    if (cJSON_IsNull(termination_cause)) {
        termination_cause = NULL;
    }
    if (termination_cause) { 
    termination_cause_local_nonprim = termination_cause_parseFromJSON(termination_cause); //nonprimitive
    }

    // event_notify_data_ext->velocity_estimate
    cJSON *velocity_estimate = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "velocityEstimate");
    if (cJSON_IsNull(velocity_estimate)) {
        velocity_estimate = NULL;
    }
    if (velocity_estimate) { 
    velocity_estimate_local_nonprim = velocity_estimate_parseFromJSON(velocity_estimate); //nonprimitive
    }

    // event_notify_data_ext->altitude
    cJSON *altitude = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "altitude");
    if (cJSON_IsNull(altitude)) {
        altitude = NULL;
    }
    if (altitude) { 
    if(!cJSON_IsNumber(altitude))
    {
    goto end; //Numeric
    }
    altitude_local_var = malloc(sizeof(double));
    if(!altitude_local_var)
    {
        goto end;
    }
    *altitude_local_var = altitude->valuedouble;
    }

    // event_notify_data_ext->achieved_qos
    cJSON *achieved_qos = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "achievedQos");
    if (cJSON_IsNull(achieved_qos)) {
        achieved_qos = NULL;
    }
    if (achieved_qos) { 
    achieved_qos_local_nonprim = minor_location_qo_s_parseFromJSON(achieved_qos); //nonprimitive
    }

    // event_notify_data_ext->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "supportedFeatures");
    if (cJSON_IsNull(supported_features)) {
        supported_features = NULL;
    }
    if (supported_features) { 
    if(!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features))
    {
    goto end; //String
    }
    }

    // event_notify_data_ext->indoor_outdoor_ind
    cJSON *indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "indoorOutdoorInd");
    if (cJSON_IsNull(indoor_outdoor_ind)) {
        indoor_outdoor_ind = NULL;
    }
    if (indoor_outdoor_ind) { 
    indoor_outdoor_ind_local_nonprim = indoor_outdoor_ind_parseFromJSON(indoor_outdoor_ind); //nonprimitive
    }

    // event_notify_data_ext->ha_gnss_metrics
    cJSON *ha_gnss_metrics = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "haGnssMetrics");
    if (cJSON_IsNull(ha_gnss_metrics)) {
        ha_gnss_metrics = NULL;
    }
    if (ha_gnss_metrics) { 
    ha_gnss_metrics_local_nonprim = high_accuracy_gnss_metrics_parseFromJSON(ha_gnss_metrics); //nonprimitive
    }

    // event_notify_data_ext->los_nlos_measure_ind
    cJSON *los_nlos_measure_ind = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "losNlosMeasureInd");
    if (cJSON_IsNull(los_nlos_measure_ind)) {
        los_nlos_measure_ind = NULL;
    }
    if (los_nlos_measure_ind) { 
    los_nlos_measure_ind_local_nonprim = los_nlos_measure_ind_parseFromJSON(los_nlos_measure_ind); //nonprimitive
    }

    // event_notify_data_ext->up_loc_rep_stat_af
    cJSON *up_loc_rep_stat_af = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "upLocRepStatAf");
    if (cJSON_IsNull(up_loc_rep_stat_af)) {
        up_loc_rep_stat_af = NULL;
    }
    if (up_loc_rep_stat_af) { 
    if(!cJSON_IsNumber(up_loc_rep_stat_af))
    {
    goto end; //Numeric
    }
    up_loc_rep_stat_af_local_var = malloc(sizeof(int));
    if(!up_loc_rep_stat_af_local_var)
    {
        goto end;
    }
    *up_loc_rep_stat_af_local_var = up_loc_rep_stat_af->valuedouble;
    }

    // event_notify_data_ext->related_applicationlayer_id
    cJSON *related_applicationlayer_id = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "relatedApplicationlayerId");
    if (cJSON_IsNull(related_applicationlayer_id)) {
        related_applicationlayer_id = NULL;
    }
    if (related_applicationlayer_id) { 
    if(!cJSON_IsString(related_applicationlayer_id) && !cJSON_IsNull(related_applicationlayer_id))
    {
    goto end; //String
    }
    }

    // event_notify_data_ext->distance_direction
    cJSON *distance_direction = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "distanceDirection");
    if (cJSON_IsNull(distance_direction)) {
        distance_direction = NULL;
    }
    if (distance_direction) { 
    distance_direction_local_nonprim = range_direction_parseFromJSON(distance_direction); //nonprimitive
    }

    // event_notify_data_ext->_2d_relative_location
    cJSON *_2d_relative_location = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "2dRelativeLocation");
    if (cJSON_IsNull(_2d_relative_location)) {
        _2d_relative_location = NULL;
    }
    if (_2d_relative_location) { 
    _2d_relative_location_local_nonprim = model_2_d_relative_location_parseFromJSON(_2d_relative_location); //nonprimitive
    }

    // event_notify_data_ext->_3d_relative_location
    cJSON *_3d_relative_location = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "3dRelativeLocation");
    if (cJSON_IsNull(_3d_relative_location)) {
        _3d_relative_location = NULL;
    }
    if (_3d_relative_location) { 
    _3d_relative_location_local_nonprim = model_3_d_relative_location_parseFromJSON(_3d_relative_location); //nonprimitive
    }

    // event_notify_data_ext->relative_velocity
    cJSON *relative_velocity = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "relativeVelocity");
    if (cJSON_IsNull(relative_velocity)) {
        relative_velocity = NULL;
    }
    if (relative_velocity) { 
    relative_velocity_local_nonprim = velocity_estimate_parseFromJSON(relative_velocity); //nonprimitive
    }

    // event_notify_data_ext->integrity_result
    cJSON *integrity_result = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "integrityResult");
    if (cJSON_IsNull(integrity_result)) {
        integrity_result = NULL;
    }
    if (integrity_result) { 
    integrity_result_local_nonprim = integrity_result_parseFromJSON(integrity_result); //nonprimitive
    }

    // event_notify_data_ext->add_event_notify_datas
    cJSON *add_event_notify_datas = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON, "addEventNotifyDatas");
    if (cJSON_IsNull(add_event_notify_datas)) {
        add_event_notify_datas = NULL;
    }
    if (add_event_notify_datas) { 
    cJSON *add_event_notify_datas_local_nonprimitive = NULL;
    if(!cJSON_IsArray(add_event_notify_datas)){
        goto end; //nonprimitive container
    }

    add_event_notify_datasList = list_createList();

    cJSON_ArrayForEach(add_event_notify_datas_local_nonprimitive,add_event_notify_datas )
    {
        if(!cJSON_IsObject(add_event_notify_datas_local_nonprimitive)){
            goto end;
        }
        event_notify_data_t *add_event_notify_datasItem = event_notify_data_parseFromJSON(add_event_notify_datas_local_nonprimitive);

        list_addElement(add_event_notify_datasList, add_event_notify_datasItem);
    }
    }


    if (supi && !cJSON_IsNull(supi)) supi_local_str = strdup(supi->valuestring);
    if (gpsi && !cJSON_IsNull(gpsi)) gpsi_local_str = strdup(gpsi->valuestring);
    if (hgmlc_call_back_uri && !cJSON_IsNull(hgmlc_call_back_uri)) hgmlc_call_back_uri_local_str = strdup(hgmlc_call_back_uri->valuestring);
    if (ldr_reference && !cJSON_IsNull(ldr_reference)) ldr_reference_local_str = strdup(ldr_reference->valuestring);
    if (lir_reference && !cJSON_IsNull(lir_reference)) lir_reference_local_str = strdup(lir_reference->valuestring);
    if (timestamp_of_location_estimate && !cJSON_IsNull(timestamp_of_location_estimate)) timestamp_of_location_estimate_local_str = strdup(timestamp_of_location_estimate->valuestring);
    if (serving_lm_fidentification && !cJSON_IsNull(serving_lm_fidentification)) serving_lm_fidentification_local_str = strdup(serving_lm_fidentification->valuestring);
    if (supported_features && !cJSON_IsNull(supported_features)) supported_features_local_str = strdup(supported_features->valuestring);
    if (related_applicationlayer_id && !cJSON_IsNull(related_applicationlayer_id)) related_applicationlayer_id_local_str = strdup(related_applicationlayer_id->valuestring);

    event_notify_data_ext_local_var = event_notify_data_ext_create_internal (
        reported_event_type_local_nonprim,
        supi_local_str,
        gpsi_local_str,
        hgmlc_call_back_uri_local_str,
        ldr_reference_local_str,
        lir_reference_local_str,
        location_estimate ? location_estimate_local_nonprim : NULL,
        age_of_location_estimate_local_var,
        timestamp_of_location_estimate_local_str,
        civic_address ? civic_address_local_nonprim : NULL,
        local_location_estimate ? local_location_estimate_local_nonprim : NULL,
        positioning_data_list ? positioning_data_listList : NULL,
        gnss_positioning_data_list ? gnss_positioning_data_listList : NULL,
        serving_lm_fidentification_local_str,
        termination_cause ? termination_cause_local_nonprim : NULL,
        velocity_estimate ? velocity_estimate_local_nonprim : NULL,
        altitude_local_var,
        achieved_qos ? achieved_qos_local_nonprim : NULL,
        supported_features_local_str,
        indoor_outdoor_ind ? indoor_outdoor_ind_local_nonprim : NULL,
        ha_gnss_metrics ? ha_gnss_metrics_local_nonprim : NULL,
        los_nlos_measure_ind ? los_nlos_measure_ind_local_nonprim : NULL,
        up_loc_rep_stat_af_local_var,
        related_applicationlayer_id_local_str,
        distance_direction ? distance_direction_local_nonprim : NULL,
        _2d_relative_location ? _2d_relative_location_local_nonprim : NULL,
        _3d_relative_location ? _3d_relative_location_local_nonprim : NULL,
        relative_velocity ? relative_velocity_local_nonprim : NULL,
        integrity_result ? integrity_result_local_nonprim : NULL,
        add_event_notify_datas ? add_event_notify_datasList : NULL
        );

    if (!event_notify_data_ext_local_var) {
        goto end;
    }

    return event_notify_data_ext_local_var;
end:
    if (reported_event_type_local_nonprim) {
        reported_event_type_free(reported_event_type_local_nonprim);
        reported_event_type_local_nonprim = NULL;
    }
    if (supi_local_str) {
        free(supi_local_str);
        supi_local_str = NULL;
    }
    if (gpsi_local_str) {
        free(gpsi_local_str);
        gpsi_local_str = NULL;
    }
    if (hgmlc_call_back_uri_local_str) {
        free(hgmlc_call_back_uri_local_str);
        hgmlc_call_back_uri_local_str = NULL;
    }
    if (ldr_reference_local_str) {
        free(ldr_reference_local_str);
        ldr_reference_local_str = NULL;
    }
    if (lir_reference_local_str) {
        free(lir_reference_local_str);
        lir_reference_local_str = NULL;
    }
    if (location_estimate_local_nonprim) {
        geographic_area_free(location_estimate_local_nonprim);
        location_estimate_local_nonprim = NULL;
    }
    if (age_of_location_estimate_local_var) {
        free(age_of_location_estimate_local_var);
        age_of_location_estimate_local_var = NULL;
    }
    if (timestamp_of_location_estimate_local_str) {
        free(timestamp_of_location_estimate_local_str);
        timestamp_of_location_estimate_local_str = NULL;
    }
    if (civic_address_local_nonprim) {
        civic_address_free(civic_address_local_nonprim);
        civic_address_local_nonprim = NULL;
    }
    if (local_location_estimate_local_nonprim) {
        local_area_free(local_location_estimate_local_nonprim);
        local_location_estimate_local_nonprim = NULL;
    }
    if (positioning_data_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, positioning_data_listList) {
            positioning_method_and_usage_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(positioning_data_listList);
        positioning_data_listList = NULL;
    }
    if (gnss_positioning_data_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, gnss_positioning_data_listList) {
            gnss_positioning_method_and_usage_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(gnss_positioning_data_listList);
        gnss_positioning_data_listList = NULL;
    }
    if (serving_lm_fidentification_local_str) {
        free(serving_lm_fidentification_local_str);
        serving_lm_fidentification_local_str = NULL;
    }
    if (termination_cause_local_nonprim) {
        termination_cause_free(termination_cause_local_nonprim);
        termination_cause_local_nonprim = NULL;
    }
    if (velocity_estimate_local_nonprim) {
        velocity_estimate_free(velocity_estimate_local_nonprim);
        velocity_estimate_local_nonprim = NULL;
    }
    if (altitude_local_var) {
        free(altitude_local_var);
        altitude_local_var = NULL;
    }
    if (achieved_qos_local_nonprim) {
        minor_location_qo_s_free(achieved_qos_local_nonprim);
        achieved_qos_local_nonprim = NULL;
    }
    if (supported_features_local_str) {
        free(supported_features_local_str);
        supported_features_local_str = NULL;
    }
    if (indoor_outdoor_ind_local_nonprim) {
        indoor_outdoor_ind_free(indoor_outdoor_ind_local_nonprim);
        indoor_outdoor_ind_local_nonprim = NULL;
    }
    if (ha_gnss_metrics_local_nonprim) {
        high_accuracy_gnss_metrics_free(ha_gnss_metrics_local_nonprim);
        ha_gnss_metrics_local_nonprim = NULL;
    }
    if (los_nlos_measure_ind_local_nonprim) {
        los_nlos_measure_ind_free(los_nlos_measure_ind_local_nonprim);
        los_nlos_measure_ind_local_nonprim = NULL;
    }
    if (up_loc_rep_stat_af_local_var) {
        free(up_loc_rep_stat_af_local_var);
        up_loc_rep_stat_af_local_var = NULL;
    }
    if (related_applicationlayer_id_local_str) {
        free(related_applicationlayer_id_local_str);
        related_applicationlayer_id_local_str = NULL;
    }
    if (distance_direction_local_nonprim) {
        range_direction_free(distance_direction_local_nonprim);
        distance_direction_local_nonprim = NULL;
    }
    if (_2d_relative_location_local_nonprim) {
        model_2_d_relative_location_free(_2d_relative_location_local_nonprim);
        _2d_relative_location_local_nonprim = NULL;
    }
    if (_3d_relative_location_local_nonprim) {
        model_3_d_relative_location_free(_3d_relative_location_local_nonprim);
        _3d_relative_location_local_nonprim = NULL;
    }
    if (relative_velocity_local_nonprim) {
        velocity_estimate_free(relative_velocity_local_nonprim);
        relative_velocity_local_nonprim = NULL;
    }
    if (integrity_result_local_nonprim) {
        integrity_result_free(integrity_result_local_nonprim);
        integrity_result_local_nonprim = NULL;
    }
    if (add_event_notify_datasList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, add_event_notify_datasList) {
            event_notify_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(add_event_notify_datasList);
        add_event_notify_datasList = NULL;
    }
    return NULL;

}
