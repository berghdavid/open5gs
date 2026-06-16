#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_data_ext.h"



static location_data_ext_t *location_data_ext_create_internal(
    geographic_area_t *location_estimate,
    accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator,
    int *age_of_location_estimate,
    char *timestamp_of_location_estimate,
    velocity_estimate_t *velocity_estimate,
    civic_address_t *civic_address,
    local_area_t *local_location_estimate,
    list_t *positioning_data_list,
    list_t *gnss_positioning_data_list,
    ecgi_t *ecgi,
    ncgi_t *ncgi,
    int *remote_ue_ind,
    double *altitude,
    int *barometric_pressure,
    char *serving_lmf_identification,
    char *ue_positioning_cap,
    ue_area_indication_t *ue_area_ind,
    char *supported_features,
    minor_location_qo_s_t *achieved_qos,
    int *direct_report_ind,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    periodic_event_info_t *accepted_periodic_event_info,
    high_accuracy_gnss_metrics_t *ha_gnss_metrics,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    char *related_applicationlayer_id,
    range_direction_t *distance_direction,
    model_2_d_relative_location_t *_2d_relative_location,
    model_3_d_relative_location_t *_3d_relative_location,
    velocity_estimate_t *relative_velocity,
    char *ranging_sl_capability,
    integrity_result_t *integrity_result,
    int *nrppa_periodic_ind,
    list_t *add_location_datas
    ) {
    location_data_ext_t *location_data_ext_local_var = malloc(sizeof(location_data_ext_t));
    if (!location_data_ext_local_var) {
        return NULL;
    }
    memset(location_data_ext_local_var, 0, sizeof(location_data_ext_t));
    location_data_ext_local_var->_library_owned = 1;
    location_data_ext_local_var->location_estimate = location_estimate;
    location_data_ext_local_var->accuracy_fulfilment_indicator = accuracy_fulfilment_indicator;
    location_data_ext_local_var->age_of_location_estimate = age_of_location_estimate;
    location_data_ext_local_var->timestamp_of_location_estimate = timestamp_of_location_estimate;
    location_data_ext_local_var->velocity_estimate = velocity_estimate;
    location_data_ext_local_var->civic_address = civic_address;
    location_data_ext_local_var->local_location_estimate = local_location_estimate;
    location_data_ext_local_var->positioning_data_list = positioning_data_list;
    location_data_ext_local_var->gnss_positioning_data_list = gnss_positioning_data_list;
    location_data_ext_local_var->ecgi = ecgi;
    location_data_ext_local_var->ncgi = ncgi;
    location_data_ext_local_var->remote_ue_ind = remote_ue_ind;
    location_data_ext_local_var->altitude = altitude;
    location_data_ext_local_var->barometric_pressure = barometric_pressure;
    location_data_ext_local_var->serving_lmf_identification = serving_lmf_identification;
    location_data_ext_local_var->ue_positioning_cap = ue_positioning_cap;
    location_data_ext_local_var->ue_area_ind = ue_area_ind;
    location_data_ext_local_var->supported_features = supported_features;
    location_data_ext_local_var->achieved_qos = achieved_qos;
    location_data_ext_local_var->direct_report_ind = direct_report_ind;
    location_data_ext_local_var->indoor_outdoor_ind = indoor_outdoor_ind;
    location_data_ext_local_var->accepted_periodic_event_info = accepted_periodic_event_info;
    location_data_ext_local_var->ha_gnss_metrics = ha_gnss_metrics;
    location_data_ext_local_var->los_nlos_measure_ind = los_nlos_measure_ind;
    location_data_ext_local_var->related_applicationlayer_id = related_applicationlayer_id;
    location_data_ext_local_var->distance_direction = distance_direction;
    location_data_ext_local_var->_2d_relative_location = _2d_relative_location;
    location_data_ext_local_var->_3d_relative_location = _3d_relative_location;
    location_data_ext_local_var->relative_velocity = relative_velocity;
    location_data_ext_local_var->ranging_sl_capability = ranging_sl_capability;
    location_data_ext_local_var->integrity_result = integrity_result;
    location_data_ext_local_var->nrppa_periodic_ind = nrppa_periodic_ind;
    location_data_ext_local_var->add_location_datas = add_location_datas;
    return location_data_ext_local_var;
}

__attribute__((deprecated)) location_data_ext_t *location_data_ext_create(
    geographic_area_t *location_estimate,
    accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator,
    int *age_of_location_estimate,
    char *timestamp_of_location_estimate,
    velocity_estimate_t *velocity_estimate,
    civic_address_t *civic_address,
    local_area_t *local_location_estimate,
    list_t *positioning_data_list,
    list_t *gnss_positioning_data_list,
    ecgi_t *ecgi,
    ncgi_t *ncgi,
    int *remote_ue_ind,
    double *altitude,
    int *barometric_pressure,
    char *serving_lmf_identification,
    char *ue_positioning_cap,
    ue_area_indication_t *ue_area_ind,
    char *supported_features,
    minor_location_qo_s_t *achieved_qos,
    int *direct_report_ind,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    periodic_event_info_t *accepted_periodic_event_info,
    high_accuracy_gnss_metrics_t *ha_gnss_metrics,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    char *related_applicationlayer_id,
    range_direction_t *distance_direction,
    model_2_d_relative_location_t *_2d_relative_location,
    model_3_d_relative_location_t *_3d_relative_location,
    velocity_estimate_t *relative_velocity,
    char *ranging_sl_capability,
    integrity_result_t *integrity_result,
    int *nrppa_periodic_ind,
    list_t *add_location_datas
    ) {
    int *age_of_location_estimate_copy = NULL;
    if (age_of_location_estimate) {
        age_of_location_estimate_copy = malloc(sizeof(int));
        if (age_of_location_estimate_copy) *age_of_location_estimate_copy = *age_of_location_estimate;
    }
    int *remote_ue_ind_copy = NULL;
    if (remote_ue_ind) {
        remote_ue_ind_copy = malloc(sizeof(int));
        if (remote_ue_ind_copy) *remote_ue_ind_copy = *remote_ue_ind;
    }
    double *altitude_copy = NULL;
    if (altitude) {
        altitude_copy = malloc(sizeof(double));
        if (altitude_copy) *altitude_copy = *altitude;
    }
    int *barometric_pressure_copy = NULL;
    if (barometric_pressure) {
        barometric_pressure_copy = malloc(sizeof(int));
        if (barometric_pressure_copy) *barometric_pressure_copy = *barometric_pressure;
    }
    int *direct_report_ind_copy = NULL;
    if (direct_report_ind) {
        direct_report_ind_copy = malloc(sizeof(int));
        if (direct_report_ind_copy) *direct_report_ind_copy = *direct_report_ind;
    }
    int *nrppa_periodic_ind_copy = NULL;
    if (nrppa_periodic_ind) {
        nrppa_periodic_ind_copy = malloc(sizeof(int));
        if (nrppa_periodic_ind_copy) *nrppa_periodic_ind_copy = *nrppa_periodic_ind;
    }
    location_data_ext_t *result = location_data_ext_create_internal (
        location_estimate,
        accuracy_fulfilment_indicator,
        age_of_location_estimate_copy,
        timestamp_of_location_estimate,
        velocity_estimate,
        civic_address,
        local_location_estimate,
        positioning_data_list,
        gnss_positioning_data_list,
        ecgi,
        ncgi,
        remote_ue_ind_copy,
        altitude_copy,
        barometric_pressure_copy,
        serving_lmf_identification,
        ue_positioning_cap,
        ue_area_ind,
        supported_features,
        achieved_qos,
        direct_report_ind_copy,
        indoor_outdoor_ind,
        accepted_periodic_event_info,
        ha_gnss_metrics,
        los_nlos_measure_ind,
        related_applicationlayer_id,
        distance_direction,
        _2d_relative_location,
        _3d_relative_location,
        relative_velocity,
        ranging_sl_capability,
        integrity_result,
        nrppa_periodic_ind_copy,
        add_location_datas
        );
    if (!result) {
        free(age_of_location_estimate_copy);
        free(remote_ue_ind_copy);
        free(altitude_copy);
        free(barometric_pressure_copy);
        free(direct_report_ind_copy);
        free(nrppa_periodic_ind_copy);
    }
    return result;
}

void location_data_ext_free(location_data_ext_t *location_data_ext) {
    if(NULL == location_data_ext){
        return ;
    }
    if(location_data_ext->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "location_data_ext_free");
        return ;
    }
    listEntry_t *listEntry;
    if (location_data_ext->location_estimate) {
        geographic_area_free(location_data_ext->location_estimate);
        location_data_ext->location_estimate = NULL;
    }
    if (location_data_ext->accuracy_fulfilment_indicator) {
        accuracy_fulfilment_indicator_free(location_data_ext->accuracy_fulfilment_indicator);
        location_data_ext->accuracy_fulfilment_indicator = NULL;
    }
    if (location_data_ext->age_of_location_estimate) {
        free(location_data_ext->age_of_location_estimate);
        location_data_ext->age_of_location_estimate = NULL;
    }
    if (location_data_ext->timestamp_of_location_estimate) {
        free(location_data_ext->timestamp_of_location_estimate);
        location_data_ext->timestamp_of_location_estimate = NULL;
    }
    if (location_data_ext->velocity_estimate) {
        velocity_estimate_free(location_data_ext->velocity_estimate);
        location_data_ext->velocity_estimate = NULL;
    }
    if (location_data_ext->civic_address) {
        civic_address_free(location_data_ext->civic_address);
        location_data_ext->civic_address = NULL;
    }
    if (location_data_ext->local_location_estimate) {
        local_area_free(location_data_ext->local_location_estimate);
        location_data_ext->local_location_estimate = NULL;
    }
    if (location_data_ext->positioning_data_list) {
        list_ForEach(listEntry, location_data_ext->positioning_data_list) {
            positioning_method_and_usage_free(listEntry->data);
        }
        list_freeList(location_data_ext->positioning_data_list);
        location_data_ext->positioning_data_list = NULL;
    }
    if (location_data_ext->gnss_positioning_data_list) {
        list_ForEach(listEntry, location_data_ext->gnss_positioning_data_list) {
            gnss_positioning_method_and_usage_free(listEntry->data);
        }
        list_freeList(location_data_ext->gnss_positioning_data_list);
        location_data_ext->gnss_positioning_data_list = NULL;
    }
    if (location_data_ext->ecgi) {
        ecgi_free(location_data_ext->ecgi);
        location_data_ext->ecgi = NULL;
    }
    if (location_data_ext->ncgi) {
        ncgi_free(location_data_ext->ncgi);
        location_data_ext->ncgi = NULL;
    }
    if (location_data_ext->remote_ue_ind) {
        free(location_data_ext->remote_ue_ind);
        location_data_ext->remote_ue_ind = NULL;
    }
    if (location_data_ext->altitude) {
        free(location_data_ext->altitude);
        location_data_ext->altitude = NULL;
    }
    if (location_data_ext->barometric_pressure) {
        free(location_data_ext->barometric_pressure);
        location_data_ext->barometric_pressure = NULL;
    }
    if (location_data_ext->serving_lmf_identification) {
        free(location_data_ext->serving_lmf_identification);
        location_data_ext->serving_lmf_identification = NULL;
    }
    if (location_data_ext->ue_positioning_cap) {
        free(location_data_ext->ue_positioning_cap);
        location_data_ext->ue_positioning_cap = NULL;
    }
    if (location_data_ext->ue_area_ind) {
        ue_area_indication_free(location_data_ext->ue_area_ind);
        location_data_ext->ue_area_ind = NULL;
    }
    if (location_data_ext->supported_features) {
        free(location_data_ext->supported_features);
        location_data_ext->supported_features = NULL;
    }
    if (location_data_ext->achieved_qos) {
        minor_location_qo_s_free(location_data_ext->achieved_qos);
        location_data_ext->achieved_qos = NULL;
    }
    if (location_data_ext->direct_report_ind) {
        free(location_data_ext->direct_report_ind);
        location_data_ext->direct_report_ind = NULL;
    }
    if (location_data_ext->indoor_outdoor_ind) {
        indoor_outdoor_ind_free(location_data_ext->indoor_outdoor_ind);
        location_data_ext->indoor_outdoor_ind = NULL;
    }
    if (location_data_ext->accepted_periodic_event_info) {
        periodic_event_info_free(location_data_ext->accepted_periodic_event_info);
        location_data_ext->accepted_periodic_event_info = NULL;
    }
    if (location_data_ext->ha_gnss_metrics) {
        high_accuracy_gnss_metrics_free(location_data_ext->ha_gnss_metrics);
        location_data_ext->ha_gnss_metrics = NULL;
    }
    if (location_data_ext->los_nlos_measure_ind) {
        los_nlos_measure_ind_free(location_data_ext->los_nlos_measure_ind);
        location_data_ext->los_nlos_measure_ind = NULL;
    }
    if (location_data_ext->related_applicationlayer_id) {
        free(location_data_ext->related_applicationlayer_id);
        location_data_ext->related_applicationlayer_id = NULL;
    }
    if (location_data_ext->distance_direction) {
        range_direction_free(location_data_ext->distance_direction);
        location_data_ext->distance_direction = NULL;
    }
    if (location_data_ext->_2d_relative_location) {
        model_2_d_relative_location_free(location_data_ext->_2d_relative_location);
        location_data_ext->_2d_relative_location = NULL;
    }
    if (location_data_ext->_3d_relative_location) {
        model_3_d_relative_location_free(location_data_ext->_3d_relative_location);
        location_data_ext->_3d_relative_location = NULL;
    }
    if (location_data_ext->relative_velocity) {
        velocity_estimate_free(location_data_ext->relative_velocity);
        location_data_ext->relative_velocity = NULL;
    }
    if (location_data_ext->ranging_sl_capability) {
        free(location_data_ext->ranging_sl_capability);
        location_data_ext->ranging_sl_capability = NULL;
    }
    if (location_data_ext->integrity_result) {
        integrity_result_free(location_data_ext->integrity_result);
        location_data_ext->integrity_result = NULL;
    }
    if (location_data_ext->nrppa_periodic_ind) {
        free(location_data_ext->nrppa_periodic_ind);
        location_data_ext->nrppa_periodic_ind = NULL;
    }
    if (location_data_ext->add_location_datas) {
        list_ForEach(listEntry, location_data_ext->add_location_datas) {
            location_data_free(listEntry->data);
        }
        list_freeList(location_data_ext->add_location_datas);
        location_data_ext->add_location_datas = NULL;
    }
    free(location_data_ext);
}

cJSON *location_data_ext_convertToJSON(location_data_ext_t *location_data_ext) {
    cJSON *item = cJSON_CreateObject();

    // location_data_ext->location_estimate
    if (!location_data_ext->location_estimate) {
        goto fail;
    }
    cJSON *location_estimate_local_JSON = geographic_area_convertToJSON(location_data_ext->location_estimate);
    if(location_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "locationEstimate", location_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // location_data_ext->accuracy_fulfilment_indicator
    if(location_data_ext->accuracy_fulfilment_indicator) {
    cJSON *accuracy_fulfilment_indicator_local_JSON = accuracy_fulfilment_indicator_convertToJSON(location_data_ext->accuracy_fulfilment_indicator);
    if(accuracy_fulfilment_indicator_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "accuracyFulfilmentIndicator", accuracy_fulfilment_indicator_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->age_of_location_estimate
    if(location_data_ext->age_of_location_estimate) {
    if(cJSON_AddNumberToObject(item, "ageOfLocationEstimate", *location_data_ext->age_of_location_estimate) == NULL) {
    goto fail; //Numeric
    }
    }


    // location_data_ext->timestamp_of_location_estimate
    if(location_data_ext->timestamp_of_location_estimate) {
    if(cJSON_AddStringToObject(item, "timestampOfLocationEstimate", location_data_ext->timestamp_of_location_estimate) == NULL) {
    goto fail; //Date-Time
    }
    }


    // location_data_ext->velocity_estimate
    if(location_data_ext->velocity_estimate) {
    cJSON *velocity_estimate_local_JSON = velocity_estimate_convertToJSON(location_data_ext->velocity_estimate);
    if(velocity_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "velocityEstimate", velocity_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->civic_address
    if(location_data_ext->civic_address) {
    cJSON *civic_address_local_JSON = civic_address_convertToJSON(location_data_ext->civic_address);
    if(civic_address_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "civicAddress", civic_address_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->local_location_estimate
    if(location_data_ext->local_location_estimate) {
    cJSON *local_location_estimate_local_JSON = local_area_convertToJSON(location_data_ext->local_location_estimate);
    if(local_location_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "localLocationEstimate", local_location_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->positioning_data_list
    if(location_data_ext->positioning_data_list) {
    cJSON *positioning_data_list = cJSON_AddArrayToObject(item, "positioningDataList");
    if(positioning_data_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *positioning_data_listListEntry;
    if (location_data_ext->positioning_data_list) {
    list_ForEach(positioning_data_listListEntry, location_data_ext->positioning_data_list) {
    cJSON *itemLocal = positioning_method_and_usage_convertToJSON(positioning_data_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(positioning_data_list, itemLocal);
    }
    }
    }


    // location_data_ext->gnss_positioning_data_list
    if(location_data_ext->gnss_positioning_data_list) {
    cJSON *gnss_positioning_data_list = cJSON_AddArrayToObject(item, "gnssPositioningDataList");
    if(gnss_positioning_data_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *gnss_positioning_data_listListEntry;
    if (location_data_ext->gnss_positioning_data_list) {
    list_ForEach(gnss_positioning_data_listListEntry, location_data_ext->gnss_positioning_data_list) {
    cJSON *itemLocal = gnss_positioning_method_and_usage_convertToJSON(gnss_positioning_data_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(gnss_positioning_data_list, itemLocal);
    }
    }
    }


    // location_data_ext->ecgi
    if(location_data_ext->ecgi) {
    cJSON *ecgi_local_JSON = ecgi_convertToJSON(location_data_ext->ecgi);
    if(ecgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->ncgi
    if(location_data_ext->ncgi) {
    cJSON *ncgi_local_JSON = ncgi_convertToJSON(location_data_ext->ncgi);
    if(ncgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->remote_ue_ind
    if(location_data_ext->remote_ue_ind) {
    if(cJSON_AddBoolToObject(item, "remoteUeInd", *location_data_ext->remote_ue_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // location_data_ext->altitude
    if(location_data_ext->altitude) {
    if(cJSON_AddNumberToObject(item, "altitude", *location_data_ext->altitude) == NULL) {
    goto fail; //Numeric
    }
    }


    // location_data_ext->barometric_pressure
    if(location_data_ext->barometric_pressure) {
    if(cJSON_AddNumberToObject(item, "barometricPressure", *location_data_ext->barometric_pressure) == NULL) {
    goto fail; //Numeric
    }
    }


    // location_data_ext->serving_lmf_identification
    if(location_data_ext->serving_lmf_identification) {
    if(cJSON_AddStringToObject(item, "servingLMFIdentification", location_data_ext->serving_lmf_identification) == NULL) {
    goto fail; //String
    }
    }


    // location_data_ext->ue_positioning_cap
    if(location_data_ext->ue_positioning_cap) {
    if(cJSON_AddStringToObject(item, "uePositioningCap", location_data_ext->ue_positioning_cap) == NULL) {
    goto fail; //ByteArray
    }
    }


    // location_data_ext->ue_area_ind
    if(location_data_ext->ue_area_ind) {
    cJSON *ue_area_ind_local_JSON = ue_area_indication_convertToJSON(location_data_ext->ue_area_ind);
    if(ue_area_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ueAreaInd", ue_area_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->supported_features
    if(location_data_ext->supported_features) {
    if(cJSON_AddStringToObject(item, "supportedFeatures", location_data_ext->supported_features) == NULL) {
    goto fail; //String
    }
    }


    // location_data_ext->achieved_qos
    if(location_data_ext->achieved_qos) {
    cJSON *achieved_qos_local_JSON = minor_location_qo_s_convertToJSON(location_data_ext->achieved_qos);
    if(achieved_qos_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "achievedQos", achieved_qos_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->direct_report_ind
    if(location_data_ext->direct_report_ind) {
    if(cJSON_AddBoolToObject(item, "directReportInd", *location_data_ext->direct_report_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // location_data_ext->indoor_outdoor_ind
    if(location_data_ext->indoor_outdoor_ind) {
    cJSON *indoor_outdoor_ind_local_JSON = indoor_outdoor_ind_convertToJSON(location_data_ext->indoor_outdoor_ind);
    if(indoor_outdoor_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "indoorOutdoorInd", indoor_outdoor_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->accepted_periodic_event_info
    if(location_data_ext->accepted_periodic_event_info) {
    cJSON *accepted_periodic_event_info_local_JSON = periodic_event_info_convertToJSON(location_data_ext->accepted_periodic_event_info);
    if(accepted_periodic_event_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "acceptedPeriodicEventInfo", accepted_periodic_event_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->ha_gnss_metrics
    if(location_data_ext->ha_gnss_metrics) {
    cJSON *ha_gnss_metrics_local_JSON = high_accuracy_gnss_metrics_convertToJSON(location_data_ext->ha_gnss_metrics);
    if(ha_gnss_metrics_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "haGnssMetrics", ha_gnss_metrics_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->los_nlos_measure_ind
    if(location_data_ext->los_nlos_measure_ind) {
    cJSON *los_nlos_measure_ind_local_JSON = los_nlos_measure_ind_convertToJSON(location_data_ext->los_nlos_measure_ind);
    if(los_nlos_measure_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "losNlosMeasureInd", los_nlos_measure_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->related_applicationlayer_id
    if(location_data_ext->related_applicationlayer_id) {
    if(cJSON_AddStringToObject(item, "relatedApplicationlayerId", location_data_ext->related_applicationlayer_id) == NULL) {
    goto fail; //String
    }
    }


    // location_data_ext->distance_direction
    if(location_data_ext->distance_direction) {
    cJSON *distance_direction_local_JSON = range_direction_convertToJSON(location_data_ext->distance_direction);
    if(distance_direction_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "distanceDirection", distance_direction_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->_2d_relative_location
    if(location_data_ext->_2d_relative_location) {
    cJSON *_2d_relative_location_local_JSON = model_2_d_relative_location_convertToJSON(location_data_ext->_2d_relative_location);
    if(_2d_relative_location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "2dRelativeLocation", _2d_relative_location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->_3d_relative_location
    if(location_data_ext->_3d_relative_location) {
    cJSON *_3d_relative_location_local_JSON = model_3_d_relative_location_convertToJSON(location_data_ext->_3d_relative_location);
    if(_3d_relative_location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "3dRelativeLocation", _3d_relative_location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->relative_velocity
    if(location_data_ext->relative_velocity) {
    cJSON *relative_velocity_local_JSON = velocity_estimate_convertToJSON(location_data_ext->relative_velocity);
    if(relative_velocity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "relativeVelocity", relative_velocity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->ranging_sl_capability
    if(location_data_ext->ranging_sl_capability) {
    if(cJSON_AddStringToObject(item, "rangingSlCapability", location_data_ext->ranging_sl_capability) == NULL) {
    goto fail; //ByteArray
    }
    }


    // location_data_ext->integrity_result
    if(location_data_ext->integrity_result) {
    cJSON *integrity_result_local_JSON = integrity_result_convertToJSON(location_data_ext->integrity_result);
    if(integrity_result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "integrityResult", integrity_result_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_data_ext->nrppa_periodic_ind
    if(location_data_ext->nrppa_periodic_ind) {
    if(cJSON_AddBoolToObject(item, "nrppaPeriodicInd", *location_data_ext->nrppa_periodic_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // location_data_ext->add_location_datas
    if(location_data_ext->add_location_datas) {
    cJSON *add_location_datas = cJSON_AddArrayToObject(item, "addLocationDatas");
    if(add_location_datas == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *add_location_datasListEntry;
    if (location_data_ext->add_location_datas) {
    list_ForEach(add_location_datasListEntry, location_data_ext->add_location_datas) {
    cJSON *itemLocal = location_data_convertToJSON(add_location_datasListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(add_location_datas, itemLocal);
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

location_data_ext_t *location_data_ext_parseFromJSON(cJSON *location_data_extJSON){

    location_data_ext_t *location_data_ext_local_var = NULL;

    // define the local variable for location_data_ext->location_estimate
    geographic_area_t *location_estimate_local_nonprim = NULL;

    // define the local variable for location_data_ext->accuracy_fulfilment_indicator
    accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_local_nonprim = NULL;

    // define the local variable for location_data_ext->age_of_location_estimate
    int *age_of_location_estimate_local_var = NULL;

    char *timestamp_of_location_estimate_local_str = NULL;

    // define the local variable for location_data_ext->velocity_estimate
    velocity_estimate_t *velocity_estimate_local_nonprim = NULL;

    // define the local variable for location_data_ext->civic_address
    civic_address_t *civic_address_local_nonprim = NULL;

    // define the local variable for location_data_ext->local_location_estimate
    local_area_t *local_location_estimate_local_nonprim = NULL;

    // define the local list for location_data_ext->positioning_data_list
    list_t *positioning_data_listList = NULL;

    // define the local list for location_data_ext->gnss_positioning_data_list
    list_t *gnss_positioning_data_listList = NULL;

    // define the local variable for location_data_ext->ecgi
    ecgi_t *ecgi_local_nonprim = NULL;

    // define the local variable for location_data_ext->ncgi
    ncgi_t *ncgi_local_nonprim = NULL;

    // define the local variable for location_data_ext->remote_ue_ind
    int *remote_ue_ind_local_var = NULL;

    // define the local variable for location_data_ext->altitude
    double *altitude_local_var = NULL;

    // define the local variable for location_data_ext->barometric_pressure
    int *barometric_pressure_local_var = NULL;

    char *serving_lmf_identification_local_str = NULL;

    char *ue_positioning_cap_local_str = NULL;

    // define the local variable for location_data_ext->ue_area_ind
    ue_area_indication_t *ue_area_ind_local_nonprim = NULL;

    char *supported_features_local_str = NULL;

    // define the local variable for location_data_ext->achieved_qos
    minor_location_qo_s_t *achieved_qos_local_nonprim = NULL;

    // define the local variable for location_data_ext->direct_report_ind
    int *direct_report_ind_local_var = NULL;

    // define the local variable for location_data_ext->indoor_outdoor_ind
    indoor_outdoor_ind_t *indoor_outdoor_ind_local_nonprim = NULL;

    // define the local variable for location_data_ext->accepted_periodic_event_info
    periodic_event_info_t *accepted_periodic_event_info_local_nonprim = NULL;

    // define the local variable for location_data_ext->ha_gnss_metrics
    high_accuracy_gnss_metrics_t *ha_gnss_metrics_local_nonprim = NULL;

    // define the local variable for location_data_ext->los_nlos_measure_ind
    los_nlos_measure_ind_t *los_nlos_measure_ind_local_nonprim = NULL;

    char *related_applicationlayer_id_local_str = NULL;

    // define the local variable for location_data_ext->distance_direction
    range_direction_t *distance_direction_local_nonprim = NULL;

    // define the local variable for location_data_ext->_2d_relative_location
    model_2_d_relative_location_t *_2d_relative_location_local_nonprim = NULL;

    // define the local variable for location_data_ext->_3d_relative_location
    model_3_d_relative_location_t *_3d_relative_location_local_nonprim = NULL;

    // define the local variable for location_data_ext->relative_velocity
    velocity_estimate_t *relative_velocity_local_nonprim = NULL;

    char *ranging_sl_capability_local_str = NULL;

    // define the local variable for location_data_ext->integrity_result
    integrity_result_t *integrity_result_local_nonprim = NULL;

    // define the local variable for location_data_ext->nrppa_periodic_ind
    int *nrppa_periodic_ind_local_var = NULL;

    // define the local list for location_data_ext->add_location_datas
    list_t *add_location_datasList = NULL;

    // location_data_ext->location_estimate
    cJSON *location_estimate = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "locationEstimate");
    if (cJSON_IsNull(location_estimate)) {
        location_estimate = NULL;
    }
    if (!location_estimate) {
        goto end;
    }

    
    location_estimate_local_nonprim = geographic_area_parseFromJSON(location_estimate); //nonprimitive

    // location_data_ext->accuracy_fulfilment_indicator
    cJSON *accuracy_fulfilment_indicator = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "accuracyFulfilmentIndicator");
    if (cJSON_IsNull(accuracy_fulfilment_indicator)) {
        accuracy_fulfilment_indicator = NULL;
    }
    if (accuracy_fulfilment_indicator) { 
    accuracy_fulfilment_indicator_local_nonprim = accuracy_fulfilment_indicator_parseFromJSON(accuracy_fulfilment_indicator); //nonprimitive
    }

    // location_data_ext->age_of_location_estimate
    cJSON *age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "ageOfLocationEstimate");
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

    // location_data_ext->timestamp_of_location_estimate
    cJSON *timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "timestampOfLocationEstimate");
    if (cJSON_IsNull(timestamp_of_location_estimate)) {
        timestamp_of_location_estimate = NULL;
    }
    if (timestamp_of_location_estimate) { 
    if(!cJSON_IsString(timestamp_of_location_estimate) && !cJSON_IsNull(timestamp_of_location_estimate))
    {
    goto end; //DateTime
    }
    }

    // location_data_ext->velocity_estimate
    cJSON *velocity_estimate = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "velocityEstimate");
    if (cJSON_IsNull(velocity_estimate)) {
        velocity_estimate = NULL;
    }
    if (velocity_estimate) { 
    velocity_estimate_local_nonprim = velocity_estimate_parseFromJSON(velocity_estimate); //nonprimitive
    }

    // location_data_ext->civic_address
    cJSON *civic_address = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "civicAddress");
    if (cJSON_IsNull(civic_address)) {
        civic_address = NULL;
    }
    if (civic_address) { 
    civic_address_local_nonprim = civic_address_parseFromJSON(civic_address); //nonprimitive
    }

    // location_data_ext->local_location_estimate
    cJSON *local_location_estimate = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "localLocationEstimate");
    if (cJSON_IsNull(local_location_estimate)) {
        local_location_estimate = NULL;
    }
    if (local_location_estimate) { 
    local_location_estimate_local_nonprim = local_area_parseFromJSON(local_location_estimate); //nonprimitive
    }

    // location_data_ext->positioning_data_list
    cJSON *positioning_data_list = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "positioningDataList");
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

    // location_data_ext->gnss_positioning_data_list
    cJSON *gnss_positioning_data_list = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "gnssPositioningDataList");
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

    // location_data_ext->ecgi
    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "ecgi");
    if (cJSON_IsNull(ecgi)) {
        ecgi = NULL;
    }
    if (ecgi) { 
    ecgi_local_nonprim = ecgi_parseFromJSON(ecgi); //nonprimitive
    }

    // location_data_ext->ncgi
    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "ncgi");
    if (cJSON_IsNull(ncgi)) {
        ncgi = NULL;
    }
    if (ncgi) { 
    ncgi_local_nonprim = ncgi_parseFromJSON(ncgi); //nonprimitive
    }

    // location_data_ext->remote_ue_ind
    cJSON *remote_ue_ind = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "remoteUeInd");
    if (cJSON_IsNull(remote_ue_ind)) {
        remote_ue_ind = NULL;
    }
    if (remote_ue_ind) { 
    if(!cJSON_IsBool(remote_ue_ind))
    {
    goto end; //Bool
    }
    remote_ue_ind_local_var = malloc(sizeof(int));
    if(!remote_ue_ind_local_var)
    {
        goto end;
    }
    *remote_ue_ind_local_var = remote_ue_ind->valueint;
    }

    // location_data_ext->altitude
    cJSON *altitude = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "altitude");
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

    // location_data_ext->barometric_pressure
    cJSON *barometric_pressure = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "barometricPressure");
    if (cJSON_IsNull(barometric_pressure)) {
        barometric_pressure = NULL;
    }
    if (barometric_pressure) { 
    if(!cJSON_IsNumber(barometric_pressure))
    {
    goto end; //Numeric
    }
    barometric_pressure_local_var = malloc(sizeof(int));
    if(!barometric_pressure_local_var)
    {
        goto end;
    }
    *barometric_pressure_local_var = barometric_pressure->valuedouble;
    }

    // location_data_ext->serving_lmf_identification
    cJSON *serving_lmf_identification = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "servingLMFIdentification");
    if (cJSON_IsNull(serving_lmf_identification)) {
        serving_lmf_identification = NULL;
    }
    if (serving_lmf_identification) { 
    if(!cJSON_IsString(serving_lmf_identification) && !cJSON_IsNull(serving_lmf_identification))
    {
    goto end; //String
    }
    }

    // location_data_ext->ue_positioning_cap
    cJSON *ue_positioning_cap = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "uePositioningCap");
    if (cJSON_IsNull(ue_positioning_cap)) {
        ue_positioning_cap = NULL;
    }
    if (ue_positioning_cap) { 
    if(!cJSON_IsString(ue_positioning_cap))
    {
    goto end; //ByteArray
    }
    }

    // location_data_ext->ue_area_ind
    cJSON *ue_area_ind = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "ueAreaInd");
    if (cJSON_IsNull(ue_area_ind)) {
        ue_area_ind = NULL;
    }
    if (ue_area_ind) { 
    ue_area_ind_local_nonprim = ue_area_indication_parseFromJSON(ue_area_ind); //nonprimitive
    }

    // location_data_ext->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "supportedFeatures");
    if (cJSON_IsNull(supported_features)) {
        supported_features = NULL;
    }
    if (supported_features) { 
    if(!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features))
    {
    goto end; //String
    }
    }

    // location_data_ext->achieved_qos
    cJSON *achieved_qos = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "achievedQos");
    if (cJSON_IsNull(achieved_qos)) {
        achieved_qos = NULL;
    }
    if (achieved_qos) { 
    achieved_qos_local_nonprim = minor_location_qo_s_parseFromJSON(achieved_qos); //nonprimitive
    }

    // location_data_ext->direct_report_ind
    cJSON *direct_report_ind = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "directReportInd");
    if (cJSON_IsNull(direct_report_ind)) {
        direct_report_ind = NULL;
    }
    if (direct_report_ind) { 
    if(!cJSON_IsBool(direct_report_ind))
    {
    goto end; //Bool
    }
    direct_report_ind_local_var = malloc(sizeof(int));
    if(!direct_report_ind_local_var)
    {
        goto end;
    }
    *direct_report_ind_local_var = direct_report_ind->valueint;
    }

    // location_data_ext->indoor_outdoor_ind
    cJSON *indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "indoorOutdoorInd");
    if (cJSON_IsNull(indoor_outdoor_ind)) {
        indoor_outdoor_ind = NULL;
    }
    if (indoor_outdoor_ind) { 
    indoor_outdoor_ind_local_nonprim = indoor_outdoor_ind_parseFromJSON(indoor_outdoor_ind); //nonprimitive
    }

    // location_data_ext->accepted_periodic_event_info
    cJSON *accepted_periodic_event_info = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "acceptedPeriodicEventInfo");
    if (cJSON_IsNull(accepted_periodic_event_info)) {
        accepted_periodic_event_info = NULL;
    }
    if (accepted_periodic_event_info) { 
    accepted_periodic_event_info_local_nonprim = periodic_event_info_parseFromJSON(accepted_periodic_event_info); //nonprimitive
    }

    // location_data_ext->ha_gnss_metrics
    cJSON *ha_gnss_metrics = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "haGnssMetrics");
    if (cJSON_IsNull(ha_gnss_metrics)) {
        ha_gnss_metrics = NULL;
    }
    if (ha_gnss_metrics) { 
    ha_gnss_metrics_local_nonprim = high_accuracy_gnss_metrics_parseFromJSON(ha_gnss_metrics); //nonprimitive
    }

    // location_data_ext->los_nlos_measure_ind
    cJSON *los_nlos_measure_ind = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "losNlosMeasureInd");
    if (cJSON_IsNull(los_nlos_measure_ind)) {
        los_nlos_measure_ind = NULL;
    }
    if (los_nlos_measure_ind) { 
    los_nlos_measure_ind_local_nonprim = los_nlos_measure_ind_parseFromJSON(los_nlos_measure_ind); //nonprimitive
    }

    // location_data_ext->related_applicationlayer_id
    cJSON *related_applicationlayer_id = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "relatedApplicationlayerId");
    if (cJSON_IsNull(related_applicationlayer_id)) {
        related_applicationlayer_id = NULL;
    }
    if (related_applicationlayer_id) { 
    if(!cJSON_IsString(related_applicationlayer_id) && !cJSON_IsNull(related_applicationlayer_id))
    {
    goto end; //String
    }
    }

    // location_data_ext->distance_direction
    cJSON *distance_direction = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "distanceDirection");
    if (cJSON_IsNull(distance_direction)) {
        distance_direction = NULL;
    }
    if (distance_direction) { 
    distance_direction_local_nonprim = range_direction_parseFromJSON(distance_direction); //nonprimitive
    }

    // location_data_ext->_2d_relative_location
    cJSON *_2d_relative_location = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "2dRelativeLocation");
    if (cJSON_IsNull(_2d_relative_location)) {
        _2d_relative_location = NULL;
    }
    if (_2d_relative_location) { 
    _2d_relative_location_local_nonprim = model_2_d_relative_location_parseFromJSON(_2d_relative_location); //nonprimitive
    }

    // location_data_ext->_3d_relative_location
    cJSON *_3d_relative_location = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "3dRelativeLocation");
    if (cJSON_IsNull(_3d_relative_location)) {
        _3d_relative_location = NULL;
    }
    if (_3d_relative_location) { 
    _3d_relative_location_local_nonprim = model_3_d_relative_location_parseFromJSON(_3d_relative_location); //nonprimitive
    }

    // location_data_ext->relative_velocity
    cJSON *relative_velocity = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "relativeVelocity");
    if (cJSON_IsNull(relative_velocity)) {
        relative_velocity = NULL;
    }
    if (relative_velocity) { 
    relative_velocity_local_nonprim = velocity_estimate_parseFromJSON(relative_velocity); //nonprimitive
    }

    // location_data_ext->ranging_sl_capability
    cJSON *ranging_sl_capability = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "rangingSlCapability");
    if (cJSON_IsNull(ranging_sl_capability)) {
        ranging_sl_capability = NULL;
    }
    if (ranging_sl_capability) { 
    if(!cJSON_IsString(ranging_sl_capability))
    {
    goto end; //ByteArray
    }
    }

    // location_data_ext->integrity_result
    cJSON *integrity_result = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "integrityResult");
    if (cJSON_IsNull(integrity_result)) {
        integrity_result = NULL;
    }
    if (integrity_result) { 
    integrity_result_local_nonprim = integrity_result_parseFromJSON(integrity_result); //nonprimitive
    }

    // location_data_ext->nrppa_periodic_ind
    cJSON *nrppa_periodic_ind = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "nrppaPeriodicInd");
    if (cJSON_IsNull(nrppa_periodic_ind)) {
        nrppa_periodic_ind = NULL;
    }
    if (nrppa_periodic_ind) { 
    if(!cJSON_IsBool(nrppa_periodic_ind))
    {
    goto end; //Bool
    }
    nrppa_periodic_ind_local_var = malloc(sizeof(int));
    if(!nrppa_periodic_ind_local_var)
    {
        goto end;
    }
    *nrppa_periodic_ind_local_var = nrppa_periodic_ind->valueint;
    }

    // location_data_ext->add_location_datas
    cJSON *add_location_datas = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "addLocationDatas");
    if (cJSON_IsNull(add_location_datas)) {
        add_location_datas = NULL;
    }
    if (add_location_datas) { 
    cJSON *add_location_datas_local_nonprimitive = NULL;
    if(!cJSON_IsArray(add_location_datas)){
        goto end; //nonprimitive container
    }

    add_location_datasList = list_createList();

    cJSON_ArrayForEach(add_location_datas_local_nonprimitive,add_location_datas )
    {
        if(!cJSON_IsObject(add_location_datas_local_nonprimitive)){
            goto end;
        }
        location_data_t *add_location_datasItem = location_data_parseFromJSON(add_location_datas_local_nonprimitive);

        list_addElement(add_location_datasList, add_location_datasItem);
    }
    }


    if (timestamp_of_location_estimate && !cJSON_IsNull(timestamp_of_location_estimate)) timestamp_of_location_estimate_local_str = strdup(timestamp_of_location_estimate->valuestring);
    if (serving_lmf_identification && !cJSON_IsNull(serving_lmf_identification)) serving_lmf_identification_local_str = strdup(serving_lmf_identification->valuestring);
    if (ue_positioning_cap) ue_positioning_cap_local_str = strdup(ue_positioning_cap->valuestring);
    if (supported_features && !cJSON_IsNull(supported_features)) supported_features_local_str = strdup(supported_features->valuestring);
    if (related_applicationlayer_id && !cJSON_IsNull(related_applicationlayer_id)) related_applicationlayer_id_local_str = strdup(related_applicationlayer_id->valuestring);
    if (ranging_sl_capability) ranging_sl_capability_local_str = strdup(ranging_sl_capability->valuestring);

    location_data_ext_local_var = location_data_ext_create_internal (
        location_estimate_local_nonprim,
        accuracy_fulfilment_indicator ? accuracy_fulfilment_indicator_local_nonprim : NULL,
        age_of_location_estimate_local_var,
        timestamp_of_location_estimate_local_str,
        velocity_estimate ? velocity_estimate_local_nonprim : NULL,
        civic_address ? civic_address_local_nonprim : NULL,
        local_location_estimate ? local_location_estimate_local_nonprim : NULL,
        positioning_data_list ? positioning_data_listList : NULL,
        gnss_positioning_data_list ? gnss_positioning_data_listList : NULL,
        ecgi ? ecgi_local_nonprim : NULL,
        ncgi ? ncgi_local_nonprim : NULL,
        remote_ue_ind_local_var,
        altitude_local_var,
        barometric_pressure_local_var,
        serving_lmf_identification_local_str,
        ue_positioning_cap_local_str,
        ue_area_ind ? ue_area_ind_local_nonprim : NULL,
        supported_features_local_str,
        achieved_qos ? achieved_qos_local_nonprim : NULL,
        direct_report_ind_local_var,
        indoor_outdoor_ind ? indoor_outdoor_ind_local_nonprim : NULL,
        accepted_periodic_event_info ? accepted_periodic_event_info_local_nonprim : NULL,
        ha_gnss_metrics ? ha_gnss_metrics_local_nonprim : NULL,
        los_nlos_measure_ind ? los_nlos_measure_ind_local_nonprim : NULL,
        related_applicationlayer_id_local_str,
        distance_direction ? distance_direction_local_nonprim : NULL,
        _2d_relative_location ? _2d_relative_location_local_nonprim : NULL,
        _3d_relative_location ? _3d_relative_location_local_nonprim : NULL,
        relative_velocity ? relative_velocity_local_nonprim : NULL,
        ranging_sl_capability_local_str,
        integrity_result ? integrity_result_local_nonprim : NULL,
        nrppa_periodic_ind_local_var,
        add_location_datas ? add_location_datasList : NULL
        );

    if (!location_data_ext_local_var) {
        goto end;
    }

    return location_data_ext_local_var;
end:
    if (location_estimate_local_nonprim) {
        geographic_area_free(location_estimate_local_nonprim);
        location_estimate_local_nonprim = NULL;
    }
    if (accuracy_fulfilment_indicator_local_nonprim) {
        accuracy_fulfilment_indicator_free(accuracy_fulfilment_indicator_local_nonprim);
        accuracy_fulfilment_indicator_local_nonprim = NULL;
    }
    if (age_of_location_estimate_local_var) {
        free(age_of_location_estimate_local_var);
        age_of_location_estimate_local_var = NULL;
    }
    if (timestamp_of_location_estimate_local_str) {
        free(timestamp_of_location_estimate_local_str);
        timestamp_of_location_estimate_local_str = NULL;
    }
    if (velocity_estimate_local_nonprim) {
        velocity_estimate_free(velocity_estimate_local_nonprim);
        velocity_estimate_local_nonprim = NULL;
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
    if (ecgi_local_nonprim) {
        ecgi_free(ecgi_local_nonprim);
        ecgi_local_nonprim = NULL;
    }
    if (ncgi_local_nonprim) {
        ncgi_free(ncgi_local_nonprim);
        ncgi_local_nonprim = NULL;
    }
    if (remote_ue_ind_local_var) {
        free(remote_ue_ind_local_var);
        remote_ue_ind_local_var = NULL;
    }
    if (altitude_local_var) {
        free(altitude_local_var);
        altitude_local_var = NULL;
    }
    if (barometric_pressure_local_var) {
        free(barometric_pressure_local_var);
        barometric_pressure_local_var = NULL;
    }
    if (serving_lmf_identification_local_str) {
        free(serving_lmf_identification_local_str);
        serving_lmf_identification_local_str = NULL;
    }
    if (ue_positioning_cap_local_str) {
        free(ue_positioning_cap_local_str);
        ue_positioning_cap_local_str = NULL;
    }
    if (ue_area_ind_local_nonprim) {
        ue_area_indication_free(ue_area_ind_local_nonprim);
        ue_area_ind_local_nonprim = NULL;
    }
    if (supported_features_local_str) {
        free(supported_features_local_str);
        supported_features_local_str = NULL;
    }
    if (achieved_qos_local_nonprim) {
        minor_location_qo_s_free(achieved_qos_local_nonprim);
        achieved_qos_local_nonprim = NULL;
    }
    if (direct_report_ind_local_var) {
        free(direct_report_ind_local_var);
        direct_report_ind_local_var = NULL;
    }
    if (indoor_outdoor_ind_local_nonprim) {
        indoor_outdoor_ind_free(indoor_outdoor_ind_local_nonprim);
        indoor_outdoor_ind_local_nonprim = NULL;
    }
    if (accepted_periodic_event_info_local_nonprim) {
        periodic_event_info_free(accepted_periodic_event_info_local_nonprim);
        accepted_periodic_event_info_local_nonprim = NULL;
    }
    if (ha_gnss_metrics_local_nonprim) {
        high_accuracy_gnss_metrics_free(ha_gnss_metrics_local_nonprim);
        ha_gnss_metrics_local_nonprim = NULL;
    }
    if (los_nlos_measure_ind_local_nonprim) {
        los_nlos_measure_ind_free(los_nlos_measure_ind_local_nonprim);
        los_nlos_measure_ind_local_nonprim = NULL;
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
    if (ranging_sl_capability_local_str) {
        free(ranging_sl_capability_local_str);
        ranging_sl_capability_local_str = NULL;
    }
    if (integrity_result_local_nonprim) {
        integrity_result_free(integrity_result_local_nonprim);
        integrity_result_local_nonprim = NULL;
    }
    if (nrppa_periodic_ind_local_var) {
        free(nrppa_periodic_ind_local_var);
        nrppa_periodic_ind_local_var = NULL;
    }
    if (add_location_datasList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, add_location_datasList) {
            location_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(add_location_datasList);
        add_location_datasList = NULL;
    }
    return NULL;

}
