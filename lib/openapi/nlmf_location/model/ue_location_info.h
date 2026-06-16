/*
 * ue_location_info.h
 *
 * Indicates location information of a UE.
 */

#ifndef _ue_location_info_H_
#define _ue_location_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ue_location_info_t ue_location_info_t;

#include "geographic_area.h"
#include "velocity_estimate.h"



typedef struct ue_location_info_t {
    struct geographic_area_t *location_estimate; //model
    int *age_of_location_estimate; //numeric
    char *timestamp_of_location_estimate; //date time
    struct velocity_estimate_t *velocity_estimate; //model
    int *age_of_velocity_estimate; //numeric
    char *timestamp_of_velocity_estimate; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} ue_location_info_t;

__attribute__((deprecated)) ue_location_info_t *ue_location_info_create(
    geographic_area_t *location_estimate,
    int *age_of_location_estimate,
    char *timestamp_of_location_estimate,
    velocity_estimate_t *velocity_estimate,
    int *age_of_velocity_estimate,
    char *timestamp_of_velocity_estimate
);

void ue_location_info_free(ue_location_info_t *ue_location_info);

ue_location_info_t *ue_location_info_parseFromJSON(cJSON *ue_location_infoJSON);

cJSON *ue_location_info_convertToJSON(ue_location_info_t *ue_location_info);

#endif /* _ue_location_info_H_ */

