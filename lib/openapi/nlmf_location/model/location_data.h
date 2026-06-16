/*
 * location_data.h
 *
 * Information within Determine Location Response.
 */

#ifndef _location_data_H_
#define _location_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct location_data_t location_data_t;

#include "accuracy_fulfilment_indicator.h"
#include "civic_address.h"
#include "ecgi.h"
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
#include "ncgi.h"
#include "periodic_event_info.h"
#include "positioning_method_and_usage.h"
#include "range_direction.h"
#include "ue_area_indication.h"
#include "velocity_estimate.h"



typedef struct location_data_t {
    struct geographic_area_t *location_estimate; //model
    struct accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator; //model
    int *age_of_location_estimate; //numeric
    char *timestamp_of_location_estimate; //date time
    struct velocity_estimate_t *velocity_estimate; //model
    struct civic_address_t *civic_address; //model
    struct local_area_t *local_location_estimate; //model
    list_t *positioning_data_list; //nonprimitive container
    list_t *gnss_positioning_data_list; //nonprimitive container
    struct ecgi_t *ecgi; //model
    struct ncgi_t *ncgi; //model
    int *remote_ue_ind; //boolean
    double *altitude; //numeric
    int *barometric_pressure; //numeric
    char *serving_lmf_identification; // string
    char *ue_positioning_cap; //ByteArray
    struct ue_area_indication_t *ue_area_ind; //model
    char *supported_features; // string
    struct minor_location_qo_s_t *achieved_qos; //model
    int *direct_report_ind; //boolean
    struct indoor_outdoor_ind_t *indoor_outdoor_ind; //model
    struct periodic_event_info_t *accepted_periodic_event_info; //model
    struct high_accuracy_gnss_metrics_t *ha_gnss_metrics; //model
    struct los_nlos_measure_ind_t *los_nlos_measure_ind; //model
    char *related_applicationlayer_id; // string
    struct range_direction_t *distance_direction; //model
    struct model_2_d_relative_location_t *_2d_relative_location; //model
    struct model_3_d_relative_location_t *_3d_relative_location; //model
    struct velocity_estimate_t *relative_velocity; //model
    char *ranging_sl_capability; //ByteArray
    struct integrity_result_t *integrity_result; //model
    int *nrppa_periodic_ind; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} location_data_t;

__attribute__((deprecated)) location_data_t *location_data_create(
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
    int *nrppa_periodic_ind
);

void location_data_free(location_data_t *location_data);

location_data_t *location_data_parseFromJSON(cJSON *location_dataJSON);

cJSON *location_data_convertToJSON(location_data_t *location_data);

#endif /* _location_data_H_ */

