/*
 * angular_velocity.h
 *
 * Rate of change of an angle.
 */

#ifndef _angular_velocity_H_
#define _angular_velocity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct angular_velocity_t angular_velocity_t;

#include "units_angular_velocity.h"



typedef struct angular_velocity_t {
    struct units_angular_velocity_t *units_angular_velocity; //model
    int *angular_velocity; //numeric
    int *a_velocity_uncertainty; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} angular_velocity_t;

__attribute__((deprecated)) angular_velocity_t *angular_velocity_create(
    units_angular_velocity_t *units_angular_velocity,
    int *angular_velocity,
    int *a_velocity_uncertainty
);

void angular_velocity_free(angular_velocity_t *angular_velocity);

angular_velocity_t *angular_velocity_parseFromJSON(cJSON *angular_velocityJSON);

cJSON *angular_velocity_convertToJSON(angular_velocity_t *angular_velocity);

#endif /* _angular_velocity_H_ */

