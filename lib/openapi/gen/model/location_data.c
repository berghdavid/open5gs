
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_data.h"

OpenAPI_location_data_t *OpenAPI_location_data_create(
    OpenAPI_geographic_area_t *location_estimate,
    OpenAPI_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator,
    bool is_age_of_location_estimate,
    int age_of_location_estimate,
    char *timestamp_of_location_estimate,
    OpenAPI_velocity_estimate_t *velocity_estimate,
    OpenAPI_civic_address_t *civic_address,
    OpenAPI_local_area_t *local_location_estimate,
    OpenAPI_list_t *positioning_data_list,
    OpenAPI_list_t *gnss_positioning_data_list,
    OpenAPI_ecgi_t *ecgi,
    OpenAPI_ncgi_t *ncgi,
    bool is_remote_ue_ind,
    int remote_ue_ind,
    bool is_altitude,
    double altitude,
    bool is_barometric_pressure,
    int barometric_pressure,
    char *serving_lmf_identification,
    char ue_positioning_cap,
    OpenAPI_ue_area_indication_t *ue_area_ind,
    char *supported_features,
    OpenAPI_minor_location_qo_s_t *achieved_qos,
    bool is_direct_report_ind,
    int direct_report_ind,
    OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind,
    OpenAPI_periodic_event_info_t *accepted_periodic_event_info,
    OpenAPI_high_accuracy_gnss_metrics_t *ha_gnss_metrics,
    OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind,
    char *related_applicationlayer_id,
    OpenAPI_range_direction_t *distance_direction,
    OpenAPI_model_2_d_relative_location_t *_2d_relative_location,
    OpenAPI_model_3_d_relative_location_t *_3d_relative_location,
    OpenAPI_velocity_estimate_t *relative_velocity,
    char ranging_sl_capability,
    OpenAPI_integrity_result_t *integrity_result,
    bool is_nrppa_periodic_ind,
    int nrppa_periodic_ind
)
{
    OpenAPI_location_data_t *location_data_local_var = ogs_malloc(sizeof(OpenAPI_location_data_t));
    ogs_assert(location_data_local_var);

    location_data_local_var->location_estimate = location_estimate;
    location_data_local_var->accuracy_fulfilment_indicator = accuracy_fulfilment_indicator;
    location_data_local_var->is_age_of_location_estimate = is_age_of_location_estimate;
    location_data_local_var->age_of_location_estimate = age_of_location_estimate;
    location_data_local_var->timestamp_of_location_estimate = timestamp_of_location_estimate;
    location_data_local_var->velocity_estimate = velocity_estimate;
    location_data_local_var->civic_address = civic_address;
    location_data_local_var->local_location_estimate = local_location_estimate;
    location_data_local_var->positioning_data_list = positioning_data_list;
    location_data_local_var->gnss_positioning_data_list = gnss_positioning_data_list;
    location_data_local_var->ecgi = ecgi;
    location_data_local_var->ncgi = ncgi;
    location_data_local_var->is_remote_ue_ind = is_remote_ue_ind;
    location_data_local_var->remote_ue_ind = remote_ue_ind;
    location_data_local_var->is_altitude = is_altitude;
    location_data_local_var->altitude = altitude;
    location_data_local_var->is_barometric_pressure = is_barometric_pressure;
    location_data_local_var->barometric_pressure = barometric_pressure;
    location_data_local_var->serving_lmf_identification = serving_lmf_identification;
    location_data_local_var->ue_positioning_cap = ue_positioning_cap;
    location_data_local_var->ue_area_ind = ue_area_ind;
    location_data_local_var->supported_features = supported_features;
    location_data_local_var->achieved_qos = achieved_qos;
    location_data_local_var->is_direct_report_ind = is_direct_report_ind;
    location_data_local_var->direct_report_ind = direct_report_ind;
    location_data_local_var->indoor_outdoor_ind = indoor_outdoor_ind;
    location_data_local_var->accepted_periodic_event_info = accepted_periodic_event_info;
    location_data_local_var->ha_gnss_metrics = ha_gnss_metrics;
    location_data_local_var->los_nlos_measure_ind = los_nlos_measure_ind;
    location_data_local_var->related_applicationlayer_id = related_applicationlayer_id;
    location_data_local_var->distance_direction = distance_direction;
    location_data_local_var->_2d_relative_location = _2d_relative_location;
    location_data_local_var->_3d_relative_location = _3d_relative_location;
    location_data_local_var->relative_velocity = relative_velocity;
    location_data_local_var->ranging_sl_capability = ranging_sl_capability;
    location_data_local_var->integrity_result = integrity_result;
    location_data_local_var->is_nrppa_periodic_ind = is_nrppa_periodic_ind;
    location_data_local_var->nrppa_periodic_ind = nrppa_periodic_ind;

    return location_data_local_var;
}

void OpenAPI_location_data_free(OpenAPI_location_data_t *location_data)
{
    if (NULL == location_data) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_geographic_area_free(location_data->location_estimate);
    OpenAPI_accuracy_fulfilment_indicator_free(location_data->accuracy_fulfilment_indicator);
    ogs_free(location_data->timestamp_of_location_estimate);
    OpenAPI_velocity_estimate_free(location_data->velocity_estimate);
    OpenAPI_civic_address_free(location_data->civic_address);
    OpenAPI_local_area_free(location_data->local_location_estimate);
    OpenAPI_list_for_each(location_data->positioning_data_list, node) {
        OpenAPI_positioning_method_and_usage_free(node->data);
    }
    OpenAPI_list_free(location_data->positioning_data_list);
    OpenAPI_list_for_each(location_data->gnss_positioning_data_list, node) {
        OpenAPI_gnss_positioning_method_and_usage_free(node->data);
    }
    OpenAPI_list_free(location_data->gnss_positioning_data_list);
    OpenAPI_ecgi_free(location_data->ecgi);
    OpenAPI_ncgi_free(location_data->ncgi);
    ogs_free(location_data->serving_lmf_identification);
    OpenAPI_ue_area_indication_free(location_data->ue_area_ind);
    ogs_free(location_data->supported_features);
    OpenAPI_minor_location_qo_s_free(location_data->achieved_qos);
    OpenAPI_indoor_outdoor_ind_free(location_data->indoor_outdoor_ind);
    OpenAPI_periodic_event_info_free(location_data->accepted_periodic_event_info);
    OpenAPI_high_accuracy_gnss_metrics_free(location_data->ha_gnss_metrics);
    OpenAPI_los_nlos_measure_ind_free(location_data->los_nlos_measure_ind);
    ogs_free(location_data->related_applicationlayer_id);
    OpenAPI_range_direction_free(location_data->distance_direction);
    OpenAPI_model_2_d_relative_location_free(location_data->_2d_relative_location);
    OpenAPI_model_3_d_relative_location_free(location_data->_3d_relative_location);
    OpenAPI_velocity_estimate_free(location_data->relative_velocity);
    OpenAPI_integrity_result_free(location_data->integrity_result);
    ogs_free(location_data);
}

cJSON *OpenAPI_location_data_convertToJSON(OpenAPI_location_data_t *location_data)
{
    cJSON *item = NULL;

    if (location_data == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [LocationData]");
        return NULL;
    }

    item = cJSON_CreateObject();
    cJSON *location_estimate_local_JSON = OpenAPI_geographic_area_convertToJSON(location_data->location_estimate);
    if (location_estimate_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [location_estimate]");
        goto end;
    }
    cJSON_AddItemToObject(item, "locationEstimate", location_estimate_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [location_estimate]");
        goto end;
    }

    if (location_data->accuracy_fulfilment_indicator) {
    cJSON *accuracy_fulfilment_indicator_local_JSON = OpenAPI_accuracy_fulfilment_indicator_convertToJSON(location_data->accuracy_fulfilment_indicator);
    if (accuracy_fulfilment_indicator_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [accuracy_fulfilment_indicator]");
        goto end;
    }
    cJSON_AddItemToObject(item, "accuracyFulfilmentIndicator", accuracy_fulfilment_indicator_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [accuracy_fulfilment_indicator]");
        goto end;
    }
    }

    if (location_data->is_age_of_location_estimate) {
    if (cJSON_AddNumberToObject(item, "ageOfLocationEstimate", location_data->age_of_location_estimate) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [age_of_location_estimate]");
        goto end;
    }
    }

    if (location_data->timestamp_of_location_estimate) {
    if (cJSON_AddStringToObject(item, "timestampOfLocationEstimate", location_data->timestamp_of_location_estimate) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [timestamp_of_location_estimate]");
        goto end;
    }
    }

    if (location_data->velocity_estimate) {
    cJSON *velocity_estimate_local_JSON = OpenAPI_velocity_estimate_convertToJSON(location_data->velocity_estimate);
    if (velocity_estimate_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [velocity_estimate]");
        goto end;
    }
    cJSON_AddItemToObject(item, "velocityEstimate", velocity_estimate_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [velocity_estimate]");
        goto end;
    }
    }

    if (location_data->civic_address) {
    cJSON *civic_address_local_JSON = OpenAPI_civic_address_convertToJSON(location_data->civic_address);
    if (civic_address_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [civic_address]");
        goto end;
    }
    cJSON_AddItemToObject(item, "civicAddress", civic_address_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [civic_address]");
        goto end;
    }
    }

    if (location_data->local_location_estimate) {
    cJSON *local_location_estimate_local_JSON = OpenAPI_local_area_convertToJSON(location_data->local_location_estimate);
    if (local_location_estimate_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [local_location_estimate]");
        goto end;
    }
    cJSON_AddItemToObject(item, "localLocationEstimate", local_location_estimate_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [local_location_estimate]");
        goto end;
    }
    }

    if (location_data->positioning_data_list) {
    cJSON *positioning_data_listList = cJSON_AddArrayToObject(item, "positioningDataList");
    if (positioning_data_listList == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [positioning_data_list]");
        goto end;
    }

    OpenAPI_lnode_t *positioning_data_list_node;
    if (location_data->positioning_data_list) {
        OpenAPI_list_for_each(location_data->positioning_data_list, positioning_data_list_node) {
            cJSON *itemLocal = OpenAPI_positioning_method_and_usage_convertToJSON(positioning_data_list_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_location_data_convertToJSON() failed [positioning_data_list]");
                goto end;
            }
            cJSON_AddItemToArray(positioning_data_listList, itemLocal);
        }
    }
    }

    if (location_data->gnss_positioning_data_list) {
    cJSON *gnss_positioning_data_listList = cJSON_AddArrayToObject(item, "gnssPositioningDataList");
    if (gnss_positioning_data_listList == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [gnss_positioning_data_list]");
        goto end;
    }

    OpenAPI_lnode_t *gnss_positioning_data_list_node;
    if (location_data->gnss_positioning_data_list) {
        OpenAPI_list_for_each(location_data->gnss_positioning_data_list, gnss_positioning_data_list_node) {
            cJSON *itemLocal = OpenAPI_gnss_positioning_method_and_usage_convertToJSON(gnss_positioning_data_list_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_location_data_convertToJSON() failed [gnss_positioning_data_list]");
                goto end;
            }
            cJSON_AddItemToArray(gnss_positioning_data_listList, itemLocal);
        }
    }
    }

    if (location_data->ecgi) {
    cJSON *ecgi_local_JSON = OpenAPI_ecgi_convertToJSON(location_data->ecgi);
    if (ecgi_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ecgi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ecgi]");
        goto end;
    }
    }

    if (location_data->ncgi) {
    cJSON *ncgi_local_JSON = OpenAPI_ncgi_convertToJSON(location_data->ncgi);
    if (ncgi_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ncgi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ncgi]");
        goto end;
    }
    }

    if (location_data->is_remote_ue_ind) {
    if (cJSON_AddBoolToObject(item, "remoteUeInd", location_data->remote_ue_ind) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [remote_ue_ind]");
        goto end;
    }
    }

    if (location_data->is_altitude) {
    if (cJSON_AddNumberToObject(item, "altitude", location_data->altitude) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [altitude]");
        goto end;
    }
    }

    if (location_data->is_barometric_pressure) {
    if (cJSON_AddNumberToObject(item, "barometricPressure", location_data->barometric_pressure) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [barometric_pressure]");
        goto end;
    }
    }

    if (location_data->serving_lmf_identification) {
    if (cJSON_AddStringToObject(item, "servingLMFIdentification", location_data->serving_lmf_identification) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [serving_lmf_identification]");
        goto end;
    }
    }

    if (location_data->ue_positioning_cap) {
    if (cJSON_AddNumberToObject(item, "uePositioningCap", location_data->ue_positioning_cap) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ue_positioning_cap]");
        goto end;
    }
    }

    if (location_data->ue_area_ind) {
    cJSON *ue_area_ind_local_JSON = OpenAPI_ue_area_indication_convertToJSON(location_data->ue_area_ind);
    if (ue_area_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ue_area_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ueAreaInd", ue_area_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ue_area_ind]");
        goto end;
    }
    }

    if (location_data->supported_features) {
    if (cJSON_AddStringToObject(item, "supportedFeatures", location_data->supported_features) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [supported_features]");
        goto end;
    }
    }

    if (location_data->achieved_qos) {
    cJSON *achieved_qos_local_JSON = OpenAPI_minor_location_qo_s_convertToJSON(location_data->achieved_qos);
    if (achieved_qos_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [achieved_qos]");
        goto end;
    }
    cJSON_AddItemToObject(item, "achievedQos", achieved_qos_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [achieved_qos]");
        goto end;
    }
    }

    if (location_data->is_direct_report_ind) {
    if (cJSON_AddBoolToObject(item, "directReportInd", location_data->direct_report_ind) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [direct_report_ind]");
        goto end;
    }
    }

    if (location_data->indoor_outdoor_ind) {
    cJSON *indoor_outdoor_ind_local_JSON = OpenAPI_indoor_outdoor_ind_convertToJSON(location_data->indoor_outdoor_ind);
    if (indoor_outdoor_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [indoor_outdoor_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "indoorOutdoorInd", indoor_outdoor_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [indoor_outdoor_ind]");
        goto end;
    }
    }

    if (location_data->accepted_periodic_event_info) {
    cJSON *accepted_periodic_event_info_local_JSON = OpenAPI_periodic_event_info_convertToJSON(location_data->accepted_periodic_event_info);
    if (accepted_periodic_event_info_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [accepted_periodic_event_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "acceptedPeriodicEventInfo", accepted_periodic_event_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [accepted_periodic_event_info]");
        goto end;
    }
    }

    if (location_data->ha_gnss_metrics) {
    cJSON *ha_gnss_metrics_local_JSON = OpenAPI_high_accuracy_gnss_metrics_convertToJSON(location_data->ha_gnss_metrics);
    if (ha_gnss_metrics_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ha_gnss_metrics]");
        goto end;
    }
    cJSON_AddItemToObject(item, "haGnssMetrics", ha_gnss_metrics_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ha_gnss_metrics]");
        goto end;
    }
    }

    if (location_data->los_nlos_measure_ind) {
    cJSON *los_nlos_measure_ind_local_JSON = OpenAPI_los_nlos_measure_ind_convertToJSON(location_data->los_nlos_measure_ind);
    if (los_nlos_measure_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [los_nlos_measure_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "losNlosMeasureInd", los_nlos_measure_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [los_nlos_measure_ind]");
        goto end;
    }
    }

    if (location_data->related_applicationlayer_id) {
    if (cJSON_AddStringToObject(item, "relatedApplicationlayerId", location_data->related_applicationlayer_id) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [related_applicationlayer_id]");
        goto end;
    }
    }

    if (location_data->distance_direction) {
    cJSON *distance_direction_local_JSON = OpenAPI_range_direction_convertToJSON(location_data->distance_direction);
    if (distance_direction_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [distance_direction]");
        goto end;
    }
    cJSON_AddItemToObject(item, "distanceDirection", distance_direction_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [distance_direction]");
        goto end;
    }
    }

    if (location_data->_2d_relative_location) {
    cJSON *_2d_relative_location_local_JSON = OpenAPI_model_2_d_relative_location_convertToJSON(location_data->_2d_relative_location);
    if (_2d_relative_location_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [_2d_relative_location]");
        goto end;
    }
    cJSON_AddItemToObject(item, "2dRelativeLocation", _2d_relative_location_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [_2d_relative_location]");
        goto end;
    }
    }

    if (location_data->_3d_relative_location) {
    cJSON *_3d_relative_location_local_JSON = OpenAPI_model_3_d_relative_location_convertToJSON(location_data->_3d_relative_location);
    if (_3d_relative_location_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [_3d_relative_location]");
        goto end;
    }
    cJSON_AddItemToObject(item, "3dRelativeLocation", _3d_relative_location_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [_3d_relative_location]");
        goto end;
    }
    }

    if (location_data->relative_velocity) {
    cJSON *relative_velocity_local_JSON = OpenAPI_velocity_estimate_convertToJSON(location_data->relative_velocity);
    if (relative_velocity_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [relative_velocity]");
        goto end;
    }
    cJSON_AddItemToObject(item, "relativeVelocity", relative_velocity_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [relative_velocity]");
        goto end;
    }
    }

    if (location_data->ranging_sl_capability) {
    if (cJSON_AddNumberToObject(item, "rangingSlCapability", location_data->ranging_sl_capability) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [ranging_sl_capability]");
        goto end;
    }
    }

    if (location_data->integrity_result) {
    cJSON *integrity_result_local_JSON = OpenAPI_integrity_result_convertToJSON(location_data->integrity_result);
    if (integrity_result_local_JSON == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [integrity_result]");
        goto end;
    }
    cJSON_AddItemToObject(item, "integrityResult", integrity_result_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [integrity_result]");
        goto end;
    }
    }

    if (location_data->is_nrppa_periodic_ind) {
    if (cJSON_AddBoolToObject(item, "nrppaPeriodicInd", location_data->nrppa_periodic_ind) == NULL) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed [nrppa_periodic_ind]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_location_data_t *OpenAPI_location_data_parseFromJSON(cJSON *location_dataJSON)
{
    OpenAPI_location_data_t *location_data_local_var = NULL;
    cJSON *location_estimate = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "locationEstimate");
    if (!location_estimate) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [location_estimate]");
        goto end;
    }

    OpenAPI_geographic_area_t *location_estimate_local_nonprim = NULL;
    location_estimate_local_nonprim = OpenAPI_geographic_area_parseFromJSON(location_estimate);

    cJSON *accuracy_fulfilment_indicator = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "accuracyFulfilmentIndicator");

    OpenAPI_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_local_nonprim = NULL;
    if (accuracy_fulfilment_indicator) {
    accuracy_fulfilment_indicator_local_nonprim = OpenAPI_accuracy_fulfilment_indicator_parseFromJSON(accuracy_fulfilment_indicator);
    }

    cJSON *age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "ageOfLocationEstimate");

    if (age_of_location_estimate) {
    if (!cJSON_IsNumber(age_of_location_estimate)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [age_of_location_estimate]");
        goto end;
    }
    }

    cJSON *timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "timestampOfLocationEstimate");

    if (timestamp_of_location_estimate) {
    if (!cJSON_IsString(timestamp_of_location_estimate)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [timestamp_of_location_estimate]");
        goto end;
    }
    }

    cJSON *velocity_estimate = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "velocityEstimate");

    OpenAPI_velocity_estimate_t *velocity_estimate_local_nonprim = NULL;
    if (velocity_estimate) {
    velocity_estimate_local_nonprim = OpenAPI_velocity_estimate_parseFromJSON(velocity_estimate);
    }

    cJSON *civic_address = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "civicAddress");

    OpenAPI_civic_address_t *civic_address_local_nonprim = NULL;
    if (civic_address) {
    civic_address_local_nonprim = OpenAPI_civic_address_parseFromJSON(civic_address);
    }

    cJSON *local_location_estimate = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "localLocationEstimate");

    OpenAPI_local_area_t *local_location_estimate_local_nonprim = NULL;
    if (local_location_estimate) {
    local_location_estimate_local_nonprim = OpenAPI_local_area_parseFromJSON(local_location_estimate);
    }

    cJSON *positioning_data_list = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "positioningDataList");

    OpenAPI_list_t *positioning_data_listList;
    if (positioning_data_list) {
    cJSON *positioning_data_list_local_nonprimitive;
    if (!cJSON_IsArray(positioning_data_list)){
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [positioning_data_list]");
        goto end;
    }

    positioning_data_listList = OpenAPI_list_create();

    cJSON_ArrayForEach(positioning_data_list_local_nonprimitive, positioning_data_list ) {
        if (!cJSON_IsObject(positioning_data_list_local_nonprimitive)) {
            ogs_error("OpenAPI_location_data_parseFromJSON() failed [positioning_data_list]");
            goto end;
        }
        OpenAPI_positioning_method_and_usage_t *positioning_data_listItem = OpenAPI_positioning_method_and_usage_parseFromJSON(positioning_data_list_local_nonprimitive);

        if (!positioning_data_listItem) {
            ogs_error("No positioning_data_listItem");
            OpenAPI_list_free(positioning_data_listList);
            goto end;
        }

        OpenAPI_list_add(positioning_data_listList, positioning_data_listItem);
    }
    }

    cJSON *gnss_positioning_data_list = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "gnssPositioningDataList");

    OpenAPI_list_t *gnss_positioning_data_listList;
    if (gnss_positioning_data_list) {
    cJSON *gnss_positioning_data_list_local_nonprimitive;
    if (!cJSON_IsArray(gnss_positioning_data_list)){
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [gnss_positioning_data_list]");
        goto end;
    }

    gnss_positioning_data_listList = OpenAPI_list_create();

    cJSON_ArrayForEach(gnss_positioning_data_list_local_nonprimitive, gnss_positioning_data_list ) {
        if (!cJSON_IsObject(gnss_positioning_data_list_local_nonprimitive)) {
            ogs_error("OpenAPI_location_data_parseFromJSON() failed [gnss_positioning_data_list]");
            goto end;
        }
        OpenAPI_gnss_positioning_method_and_usage_t *gnss_positioning_data_listItem = OpenAPI_gnss_positioning_method_and_usage_parseFromJSON(gnss_positioning_data_list_local_nonprimitive);

        if (!gnss_positioning_data_listItem) {
            ogs_error("No gnss_positioning_data_listItem");
            OpenAPI_list_free(gnss_positioning_data_listList);
            goto end;
        }

        OpenAPI_list_add(gnss_positioning_data_listList, gnss_positioning_data_listItem);
    }
    }

    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "ecgi");

    OpenAPI_ecgi_t *ecgi_local_nonprim = NULL;
    if (ecgi) {
    ecgi_local_nonprim = OpenAPI_ecgi_parseFromJSON(ecgi);
    }

    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "ncgi");

    OpenAPI_ncgi_t *ncgi_local_nonprim = NULL;
    if (ncgi) {
    ncgi_local_nonprim = OpenAPI_ncgi_parseFromJSON(ncgi);
    }

    cJSON *remote_ue_ind = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "remoteUeInd");

    if (remote_ue_ind) {
    if (!cJSON_IsBool(remote_ue_ind)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [remote_ue_ind]");
        goto end;
    }
    }

    cJSON *altitude = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "altitude");

    if (altitude) {
    if (!cJSON_IsNumber(altitude)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [altitude]");
        goto end;
    }
    }

    cJSON *barometric_pressure = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "barometricPressure");

    if (barometric_pressure) {
    if (!cJSON_IsNumber(barometric_pressure)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [barometric_pressure]");
        goto end;
    }
    }

    cJSON *serving_lmf_identification = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "servingLMFIdentification");

    if (serving_lmf_identification) {
    if (!cJSON_IsString(serving_lmf_identification)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [serving_lmf_identification]");
        goto end;
    }
    }

    cJSON *ue_positioning_cap = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "uePositioningCap");

    if (ue_positioning_cap) {
    if (!cJSON_IsNumber(ue_positioning_cap)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [ue_positioning_cap]");
        goto end;
    }
    }

    cJSON *ue_area_ind = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "ueAreaInd");

    OpenAPI_ue_area_indication_t *ue_area_ind_local_nonprim = NULL;
    if (ue_area_ind) {
    ue_area_ind_local_nonprim = OpenAPI_ue_area_indication_parseFromJSON(ue_area_ind);
    }

    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "supportedFeatures");

    if (supported_features) {
    if (!cJSON_IsString(supported_features)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [supported_features]");
        goto end;
    }
    }

    cJSON *achieved_qos = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "achievedQos");

    OpenAPI_minor_location_qo_s_t *achieved_qos_local_nonprim = NULL;
    if (achieved_qos) {
    achieved_qos_local_nonprim = OpenAPI_minor_location_qo_s_parseFromJSON(achieved_qos);
    }

    cJSON *direct_report_ind = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "directReportInd");

    if (direct_report_ind) {
    if (!cJSON_IsBool(direct_report_ind)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [direct_report_ind]");
        goto end;
    }
    }

    cJSON *indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "indoorOutdoorInd");

    OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind_local_nonprim = NULL;
    if (indoor_outdoor_ind) {
    indoor_outdoor_ind_local_nonprim = OpenAPI_indoor_outdoor_ind_parseFromJSON(indoor_outdoor_ind);
    }

    cJSON *accepted_periodic_event_info = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "acceptedPeriodicEventInfo");

    OpenAPI_periodic_event_info_t *accepted_periodic_event_info_local_nonprim = NULL;
    if (accepted_periodic_event_info) {
    accepted_periodic_event_info_local_nonprim = OpenAPI_periodic_event_info_parseFromJSON(accepted_periodic_event_info);
    }

    cJSON *ha_gnss_metrics = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "haGnssMetrics");

    OpenAPI_high_accuracy_gnss_metrics_t *ha_gnss_metrics_local_nonprim = NULL;
    if (ha_gnss_metrics) {
    ha_gnss_metrics_local_nonprim = OpenAPI_high_accuracy_gnss_metrics_parseFromJSON(ha_gnss_metrics);
    }

    cJSON *los_nlos_measure_ind = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "losNlosMeasureInd");

    OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind_local_nonprim = NULL;
    if (los_nlos_measure_ind) {
    los_nlos_measure_ind_local_nonprim = OpenAPI_los_nlos_measure_ind_parseFromJSON(los_nlos_measure_ind);
    }

    cJSON *related_applicationlayer_id = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "relatedApplicationlayerId");

    if (related_applicationlayer_id) {
    if (!cJSON_IsString(related_applicationlayer_id)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [related_applicationlayer_id]");
        goto end;
    }
    }

    cJSON *distance_direction = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "distanceDirection");

    OpenAPI_range_direction_t *distance_direction_local_nonprim = NULL;
    if (distance_direction) {
    distance_direction_local_nonprim = OpenAPI_range_direction_parseFromJSON(distance_direction);
    }

    cJSON *_2d_relative_location = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "2dRelativeLocation");

    OpenAPI_model_2_d_relative_location_t *_2d_relative_location_local_nonprim = NULL;
    if (_2d_relative_location) {
    _2d_relative_location_local_nonprim = OpenAPI_model_2_d_relative_location_parseFromJSON(_2d_relative_location);
    }

    cJSON *_3d_relative_location = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "3dRelativeLocation");

    OpenAPI_model_3_d_relative_location_t *_3d_relative_location_local_nonprim = NULL;
    if (_3d_relative_location) {
    _3d_relative_location_local_nonprim = OpenAPI_model_3_d_relative_location_parseFromJSON(_3d_relative_location);
    }

    cJSON *relative_velocity = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "relativeVelocity");

    OpenAPI_velocity_estimate_t *relative_velocity_local_nonprim = NULL;
    if (relative_velocity) {
    relative_velocity_local_nonprim = OpenAPI_velocity_estimate_parseFromJSON(relative_velocity);
    }

    cJSON *ranging_sl_capability = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "rangingSlCapability");

    if (ranging_sl_capability) {
    if (!cJSON_IsNumber(ranging_sl_capability)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [ranging_sl_capability]");
        goto end;
    }
    }

    cJSON *integrity_result = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "integrityResult");

    OpenAPI_integrity_result_t *integrity_result_local_nonprim = NULL;
    if (integrity_result) {
    integrity_result_local_nonprim = OpenAPI_integrity_result_parseFromJSON(integrity_result);
    }

    cJSON *nrppa_periodic_ind = cJSON_GetObjectItemCaseSensitive(location_dataJSON, "nrppaPeriodicInd");

    if (nrppa_periodic_ind) {
    if (!cJSON_IsBool(nrppa_periodic_ind)) {
        ogs_error("OpenAPI_location_data_parseFromJSON() failed [nrppa_periodic_ind]");
        goto end;
    }
    }

    location_data_local_var = OpenAPI_location_data_create (
        location_estimate_local_nonprim,
        accuracy_fulfilment_indicator ? accuracy_fulfilment_indicator_local_nonprim : NULL,
        age_of_location_estimate ? true : false,
        age_of_location_estimate ? age_of_location_estimate->valuedouble : 0,
        timestamp_of_location_estimate ? ogs_strdup(timestamp_of_location_estimate->valuestring) : NULL,
        velocity_estimate ? velocity_estimate_local_nonprim : NULL,
        civic_address ? civic_address_local_nonprim : NULL,
        local_location_estimate ? local_location_estimate_local_nonprim : NULL,
        positioning_data_list ? positioning_data_listList : NULL,
        gnss_positioning_data_list ? gnss_positioning_data_listList : NULL,
        ecgi ? ecgi_local_nonprim : NULL,
        ncgi ? ncgi_local_nonprim : NULL,
        remote_ue_ind ? true : false,
        remote_ue_ind ? remote_ue_ind->valueint : 0,
        altitude ? true : false,
        altitude ? altitude->valuedouble : 0,
        barometric_pressure ? true : false,
        barometric_pressure ? barometric_pressure->valuedouble : 0,
        serving_lmf_identification ? ogs_strdup(serving_lmf_identification->valuestring) : NULL,
        ue_positioning_cap ? ue_positioning_cap->valueint : 0,
        ue_area_ind ? ue_area_ind_local_nonprim : NULL,
        supported_features ? ogs_strdup(supported_features->valuestring) : NULL,
        achieved_qos ? achieved_qos_local_nonprim : NULL,
        direct_report_ind ? true : false,
        direct_report_ind ? direct_report_ind->valueint : 0,
        indoor_outdoor_ind ? indoor_outdoor_ind_local_nonprim : NULL,
        accepted_periodic_event_info ? accepted_periodic_event_info_local_nonprim : NULL,
        ha_gnss_metrics ? ha_gnss_metrics_local_nonprim : NULL,
        los_nlos_measure_ind ? los_nlos_measure_ind_local_nonprim : NULL,
        related_applicationlayer_id ? ogs_strdup(related_applicationlayer_id->valuestring) : NULL,
        distance_direction ? distance_direction_local_nonprim : NULL,
        _2d_relative_location ? _2d_relative_location_local_nonprim : NULL,
        _3d_relative_location ? _3d_relative_location_local_nonprim : NULL,
        relative_velocity ? relative_velocity_local_nonprim : NULL,
        ranging_sl_capability ? ranging_sl_capability->valueint : 0,
        integrity_result ? integrity_result_local_nonprim : NULL,
        nrppa_periodic_ind ? true : false,
        nrppa_periodic_ind ? nrppa_periodic_ind->valueint : 0
    );

    return location_data_local_var;
end:
    return NULL;
}

OpenAPI_location_data_t *OpenAPI_location_data_copy(OpenAPI_location_data_t *dst, OpenAPI_location_data_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_location_data_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_location_data_convertToJSON() failed");
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

    OpenAPI_location_data_free(dst);
    dst = OpenAPI_location_data_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

