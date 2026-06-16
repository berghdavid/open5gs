/*
 * range_direction.h
 *
 * Represents a distance and direction from a point A to a point B.
 */

#ifndef _range_direction_H_
#define _range_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct range_direction_t range_direction_t;




typedef struct range_direction_t {
    double *distance; //numeric
    int *azimuth_direction; //numeric
    int *elevation_direction; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} range_direction_t;

__attribute__((deprecated)) range_direction_t *range_direction_create(
    double *distance,
    int *azimuth_direction,
    int *elevation_direction
);

void range_direction_free(range_direction_t *range_direction);

range_direction_t *range_direction_parseFromJSON(cJSON *range_directionJSON);

cJSON *range_direction_convertToJSON(range_direction_t *range_direction);

#endif /* _range_direction_H_ */

