/*
 * event_notify_data.h
 *
 * Information within Event Notify Request.
 */

#ifndef _event_notify_data_H_
#define _event_notify_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct event_notify_data_t event_notify_data_t;

#include "civic_address.h"
#include "geographic_area.h"
#include "gnss_positioning_method_and_usage.h"
#include "high_accuracy_gnss_metrics.h"
#include "indoor_outdoor_ind.h"
#include "integrity_result.h"
#include "local_area.h"
#include "los_nlos_measure_ind.h"
#include "minor_location_qo_s.h"
#include "model_2_d_relative_location.h"
#include "model_3_d_relative_location.h"
#include "positioning_method_and_usage.h"
#include "range_direction.h"
#include "reported_event_type.h"
#include "termination_cause.h"
#include "velocity_estimate.h"



typedef struct event_notify_data_t {
    struct reported_event_type_t *reported_event_type; //model
    char *supi; // string
    char *gpsi; // string
    char *hgmlc_call_back_uri; // string
    char *ldr_reference; // string
    char *lir_reference; // string
    struct geographic_area_t *location_estimate; //model
    int *age_of_location_estimate; //numeric
    char *timestamp_of_location_estimate; //date time
    struct civic_address_t *civic_address; //model
    struct local_area_t *local_location_estimate; //model
    list_t *positioning_data_list; //nonprimitive container
    list_t *gnss_positioning_data_list; //nonprimitive container
    char *serving_lm_fidentification; // string
    struct termination_cause_t *termination_cause; //model
    struct velocity_estimate_t *velocity_estimate; //model
    double *altitude; //numeric
    struct minor_location_qo_s_t *achieved_qos; //model
    char *supported_features; // string
    struct indoor_outdoor_ind_t *indoor_outdoor_ind; //model
    struct high_accuracy_gnss_metrics_t *ha_gnss_metrics; //model
    struct los_nlos_measure_ind_t *los_nlos_measure_ind; //model
    int *up_loc_rep_stat_af; //numeric
    char *related_applicationlayer_id; // string
    struct range_direction_t *distance_direction; //model
    struct model_2_d_relative_location_t *_2d_relative_location; //model
    struct model_3_d_relative_location_t *_3d_relative_location; //model
    struct velocity_estimate_t *relative_velocity; //model
    struct integrity_result_t *integrity_result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} event_notify_data_t;

__attribute__((deprecated)) event_notify_data_t *event_notify_data_create(
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
    integrity_result_t *integrity_result
);

void event_notify_data_free(event_notify_data_t *event_notify_data);

event_notify_data_t *event_notify_data_parseFromJSON(cJSON *event_notify_dataJSON);

cJSON *event_notify_data_convertToJSON(event_notify_data_t *event_notify_data);

#endif /* _event_notify_data_H_ */

