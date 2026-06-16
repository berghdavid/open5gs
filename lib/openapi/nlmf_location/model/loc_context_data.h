/*
 * loc_context_data.h
 *
 * Information within Transfer Location Context Request.
 */

#ifndef _loc_context_data_H_
#define _loc_context_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct loc_context_data_t loc_context_data_t;

#include "add_location_context.h"
#include "area_event_info.h"
#include "ecgi.h"
#include "event_report_message.h"
#include "event_reporting_status.h"
#include "guami.h"
#include "indoor_outdoor_ind.h"
#include "ldr_type.h"
#include "location_qo_s.h"
#include "los_nlos_measure_ind.h"
#include "motion_event_info.h"
#include "ncgi.h"
#include "periodic_event_info.h"
#include "supported_gad_shapes.h"
#include "ue_location_info.h"
#include "ue_up_positioning_capabilities.h"
#include "up_cum_evt_rpt_criteria.h"



typedef struct loc_context_data_t {
    char *amf_id; // string
    struct location_qo_s_t *location_qo_s; //model
    list_t *supported_gad_shapes; //nonprimitive container
    char *supi; // string
    char *gpsi; // string
    list_t *add_loc_context_list; //nonprimitive container
    struct ldr_type_t *ldr_type; //model
    char *hgmlc_call_back_uri; // string
    char *ldr_reference; // string
    struct periodic_event_info_t *periodic_event_info; //model
    struct area_event_info_t *area_event_info; //model
    struct motion_event_info_t *motion_event_info; //model
    struct event_report_message_t *event_report_message; //model
    struct event_reporting_status_t *event_reporting_status; //model
    struct ue_location_info_t *ue_location_info; //model
    int *c_io_t5_gs_optimisation; //boolean
    struct ecgi_t *ecgi; //model
    struct ncgi_t *ncgi; //model
    struct guami_t *guami; //model
    char *supported_features; // string
    char *ue_positioning_cap; //ByteArray
    list_t *ue_up_pos_caps; //nonprimitive container
    char *scheduled_loc_time; //date time
    struct indoor_outdoor_ind_t *indoor_outdoor_ind; //model
    struct los_nlos_measure_ind_t *los_nlos_measure_ind; //model
    struct up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria; //model
    int *lcs_upp_exist_ind; //boolean
    char *src_lmf_routing_info; // string
    int *extended_facility_ind; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} loc_context_data_t;

__attribute__((deprecated)) loc_context_data_t *loc_context_data_create(
    char *amf_id,
    location_qo_s_t *location_qo_s,
    list_t *supported_gad_shapes,
    char *supi,
    char *gpsi,
    list_t *add_loc_context_list,
    ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    periodic_event_info_t *periodic_event_info,
    area_event_info_t *area_event_info,
    motion_event_info_t *motion_event_info,
    event_report_message_t *event_report_message,
    event_reporting_status_t *event_reporting_status,
    ue_location_info_t *ue_location_info,
    int *c_io_t5_gs_optimisation,
    ecgi_t *ecgi,
    ncgi_t *ncgi,
    guami_t *guami,
    char *supported_features,
    char *ue_positioning_cap,
    list_t *ue_up_pos_caps,
    char *scheduled_loc_time,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    int *lcs_upp_exist_ind,
    char *src_lmf_routing_info,
    int *extended_facility_ind
);

void loc_context_data_free(loc_context_data_t *loc_context_data);

loc_context_data_t *loc_context_data_parseFromJSON(cJSON *loc_context_dataJSON);

cJSON *loc_context_data_convertToJSON(loc_context_data_t *loc_context_data);

#endif /* _loc_context_data_H_ */

