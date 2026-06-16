/*
 * units_linear_velocity.h
 *
 * The the units of linear velocity.
 */

#ifndef _units_linear_velocity_H_
#define _units_linear_velocity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct units_linear_velocity_t units_linear_velocity_t;




typedef struct units_linear_velocity_t {

    int _library_owned; // Is the library responsible for freeing this object?
} units_linear_velocity_t;

__attribute__((deprecated)) units_linear_velocity_t *units_linear_velocity_create(
);

void units_linear_velocity_free(units_linear_velocity_t *units_linear_velocity);

units_linear_velocity_t *units_linear_velocity_parseFromJSON(cJSON *units_linear_velocityJSON);

cJSON *units_linear_velocity_convertToJSON(units_linear_velocity_t *units_linear_velocity);

#endif /* _units_linear_velocity_H_ */

