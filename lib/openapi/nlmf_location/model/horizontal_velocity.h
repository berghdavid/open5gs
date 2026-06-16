/*
 * horizontal_velocity.h
 *
 * Horizontal velocity.
 */

#ifndef _horizontal_velocity_H_
#define _horizontal_velocity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct horizontal_velocity_t horizontal_velocity_t;




typedef struct horizontal_velocity_t {
    float *h_speed; //numeric
    int *bearing; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} horizontal_velocity_t;

__attribute__((deprecated)) horizontal_velocity_t *horizontal_velocity_create(
    float *h_speed,
    int *bearing
);

void horizontal_velocity_free(horizontal_velocity_t *horizontal_velocity);

horizontal_velocity_t *horizontal_velocity_parseFromJSON(cJSON *horizontal_velocityJSON);

cJSON *horizontal_velocity_convertToJSON(horizontal_velocity_t *horizontal_velocity);

#endif /* _horizontal_velocity_H_ */

