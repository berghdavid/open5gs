/*
 * horizontal_with_vertical_velocity.h
 *
 * Horizontal and vertical velocity.
 */

#ifndef _horizontal_with_vertical_velocity_H_
#define _horizontal_with_vertical_velocity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct horizontal_with_vertical_velocity_t horizontal_with_vertical_velocity_t;

#include "vertical_direction.h"



typedef struct horizontal_with_vertical_velocity_t {
    float *h_speed; //numeric
    int *bearing; //numeric
    float *v_speed; //numeric
    lmf_location_vertical_direction__e v_direction; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} horizontal_with_vertical_velocity_t;

__attribute__((deprecated)) horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_create(
    float *h_speed,
    int *bearing,
    float *v_speed,
    lmf_location_vertical_direction__e v_direction
);

void horizontal_with_vertical_velocity_free(horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);

horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_parseFromJSON(cJSON *horizontal_with_vertical_velocityJSON);

cJSON *horizontal_with_vertical_velocity_convertToJSON(horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);

#endif /* _horizontal_with_vertical_velocity_H_ */

