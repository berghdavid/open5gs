/*
 * units_angular_velocity.h
 *
 * The units of angular velocity.
 */

#ifndef _units_angular_velocity_H_
#define _units_angular_velocity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct units_angular_velocity_t units_angular_velocity_t;




typedef struct units_angular_velocity_t {

    int _library_owned; // Is the library responsible for freeing this object?
} units_angular_velocity_t;

__attribute__((deprecated)) units_angular_velocity_t *units_angular_velocity_create(
);

void units_angular_velocity_free(units_angular_velocity_t *units_angular_velocity);

units_angular_velocity_t *units_angular_velocity_parseFromJSON(cJSON *units_angular_velocityJSON);

cJSON *units_angular_velocity_convertToJSON(units_angular_velocity_t *units_angular_velocity);

#endif /* _units_angular_velocity_H_ */

