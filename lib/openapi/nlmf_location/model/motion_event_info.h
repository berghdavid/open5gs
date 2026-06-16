/*
 * motion_event_info.h
 *
 * Indicates the information of motion based event reporting.
 */

#ifndef _motion_event_info_H_
#define _motion_event_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct motion_event_info_t motion_event_info_t;

#include "occurrence_info.h"



typedef struct motion_event_info_t {
    int *linear_distance; //numeric
    struct occurrence_info_t *occurrence_info; //model
    int *minimum_interval; //numeric
    int *maximum_interval; //numeric
    int *sampling_interval; //numeric
    int *reporting_duration; //numeric
    int *reporting_location_req; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} motion_event_info_t;

__attribute__((deprecated)) motion_event_info_t *motion_event_info_create(
    int *linear_distance,
    occurrence_info_t *occurrence_info,
    int *minimum_interval,
    int *maximum_interval,
    int *sampling_interval,
    int *reporting_duration,
    int *reporting_location_req
);

void motion_event_info_free(motion_event_info_t *motion_event_info);

motion_event_info_t *motion_event_info_parseFromJSON(cJSON *motion_event_infoJSON);

cJSON *motion_event_info_convertToJSON(motion_event_info_t *motion_event_info);

#endif /* _motion_event_info_H_ */

