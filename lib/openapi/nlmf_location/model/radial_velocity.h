/*
 * radial_velocity.h
 *
 * Rate of change of a range.
 */

#ifndef _radial_velocity_H_
#define _radial_velocity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct radial_velocity_t radial_velocity_t;

#include "units_linear_velocity.h"



typedef struct radial_velocity_t {
    struct units_linear_velocity_t *units_radial_velocity; //model
    int *radial_velocity; //numeric
    int *r_velocity_uncertainty; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} radial_velocity_t;

__attribute__((deprecated)) radial_velocity_t *radial_velocity_create(
    units_linear_velocity_t *units_radial_velocity,
    int *radial_velocity,
    int *r_velocity_uncertainty
);

void radial_velocity_free(radial_velocity_t *radial_velocity);

radial_velocity_t *radial_velocity_parseFromJSON(cJSON *radial_velocityJSON);

cJSON *radial_velocity_convertToJSON(radial_velocity_t *radial_velocity);

#endif /* _radial_velocity_H_ */

