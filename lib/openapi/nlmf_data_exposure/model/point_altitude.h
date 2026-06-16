/*
 * point_altitude.h
 *
 * Ellipsoid point with altitude.
 */

#ifndef _point_altitude_H_
#define _point_altitude_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct point_altitude_t point_altitude_t;

#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"



typedef struct point_altitude_t {
    struct supported_gad_shapes_t *shape; //model
    struct geographical_coordinates_t *point; //model
    double *altitude; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} point_altitude_t;

__attribute__((deprecated)) point_altitude_t *point_altitude_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    double *altitude
);

void point_altitude_free(point_altitude_t *point_altitude);

point_altitude_t *point_altitude_parseFromJSON(cJSON *point_altitudeJSON);

cJSON *point_altitude_convertToJSON(point_altitude_t *point_altitude);

#endif /* _point_altitude_H_ */

