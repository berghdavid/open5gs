/*
 * add_location_context.h
 *
 * Information within Location context(s).
 */

#ifndef _add_location_context_H_
#define _add_location_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct add_location_context_t add_location_context_t;

#include "area_event_info.h"
#include "event_report_message.h"
#include "event_reporting_status.h"
#include "indoor_outdoor_ind.h"
#include "ldr_type.h"
#include "location_qo_s.h"
#include "los_nlos_measure_ind.h"
#include "motion_event_info.h"
#include "periodic_event_info.h"
#include "ue_location_info.h"
#include "up_cum_evt_rpt_criteria.h"



typedef struct add_location_context_t {
    struct location_qo_s_t *location_qo_s; //model
    struct ldr_type_t *ldr_type; //model
    char *hgmlc_call_back_uri; // string
    char *ldr_reference; // string
    struct periodic_event_info_t *periodic_event_info; //model
    struct area_event_info_t *area_event_info; //model
    struct motion_event_info_t *motion_event_info; //model
    struct event_report_message_t *event_report_message; //model
    struct event_reporting_status_t *event_reporting_status; //model
    struct ue_location_info_t *ue_location_info; //model
    char *scheduled_loc_time; //date time
    struct indoor_outdoor_ind_t *indoor_outdoor_ind; //model
    struct los_nlos_measure_ind_t *los_nlos_measure_ind; //model
    struct up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria; //model
    int *lcs_upp_exist_ind; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} add_location_context_t;

__attribute__((deprecated)) add_location_context_t *add_location_context_create(
    location_qo_s_t *location_qo_s,
    ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    periodic_event_info_t *periodic_event_info,
    area_event_info_t *area_event_info,
    motion_event_info_t *motion_event_info,
    event_report_message_t *event_report_message,
    event_reporting_status_t *event_reporting_status,
    ue_location_info_t *ue_location_info,
    char *scheduled_loc_time,
    indoor_outdoor_ind_t *indoor_outdoor_ind,
    los_nlos_measure_ind_t *los_nlos_measure_ind,
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    int *lcs_upp_exist_ind
);

void add_location_context_free(add_location_context_t *add_location_context);

add_location_context_t *add_location_context_parseFromJSON(cJSON *add_location_contextJSON);

cJSON *add_location_context_convertToJSON(add_location_context_t *add_location_context);

#endif /* _add_location_context_H_ */

