/*
 * point.h
 *
 * Ellipsoid Point.
 */

#ifndef _point_H_
#define _point_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct point_t point_t;

#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"



typedef struct point_t {
    struct supported_gad_shapes_t *shape; //model
    struct geographical_coordinates_t *point; //model

    int _library_owned; // Is the library responsible for freeing this object?
} point_t;

__attribute__((deprecated)) point_t *point_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point
);

void point_free(point_t *point);

point_t *point_parseFromJSON(cJSON *pointJSON);

cJSON *point_convertToJSON(point_t *point);

#endif /* _point_H_ */

