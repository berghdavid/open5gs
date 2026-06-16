/*
 * point_uncertainty_circle.h
 *
 * Ellipsoid point with uncertainty circle.
 */

#ifndef _point_uncertainty_circle_H_
#define _point_uncertainty_circle_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct point_uncertainty_circle_t point_uncertainty_circle_t;

#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"



typedef struct point_uncertainty_circle_t {
    struct supported_gad_shapes_t *shape; //model
    struct geographical_coordinates_t *point; //model
    float *uncertainty; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} point_uncertainty_circle_t;

__attribute__((deprecated)) point_uncertainty_circle_t *point_uncertainty_circle_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    float *uncertainty
);

void point_uncertainty_circle_free(point_uncertainty_circle_t *point_uncertainty_circle);

point_uncertainty_circle_t *point_uncertainty_circle_parseFromJSON(cJSON *point_uncertainty_circleJSON);

cJSON *point_uncertainty_circle_convertToJSON(point_uncertainty_circle_t *point_uncertainty_circle);

#endif /* _point_uncertainty_circle_H_ */

