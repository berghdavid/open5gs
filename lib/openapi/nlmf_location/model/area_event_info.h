/*
 * area_event_info.h
 *
 * Indicates the information of area based event reporting.
 */

#ifndef _area_event_info_H_
#define _area_event_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct area_event_info_t area_event_info_t;

#include "occurrence_info.h"
#include "reporting_area.h"



typedef struct area_event_info_t {
    list_t *area_definition; //nonprimitive container
    struct occurrence_info_t *occurrence_info; //model
    int *minimum_interval; //numeric
    int *maximum_interval; //numeric
    int *sampling_interval; //numeric
    int *reporting_duration; //numeric
    int *reporting_location_req; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} area_event_info_t;

__attribute__((deprecated)) area_event_info_t *area_event_info_create(
    list_t *area_definition,
    occurrence_info_t *occurrence_info,
    int *minimum_interval,
    int *maximum_interval,
    int *sampling_interval,
    int *reporting_duration,
    int *reporting_location_req
);

void area_event_info_free(area_event_info_t *area_event_info);

area_event_info_t *area_event_info_parseFromJSON(cJSON *area_event_infoJSON);

cJSON *area_event_info_convertToJSON(area_event_info_t *area_event_info);

#endif /* _area_event_info_H_ */

