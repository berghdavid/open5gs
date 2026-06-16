/*
 * point_uncertainty_ellipse.h
 *
 * Ellipsoid point with uncertainty ellipse.
 */

#ifndef _point_uncertainty_ellipse_H_
#define _point_uncertainty_ellipse_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct point_uncertainty_ellipse_t point_uncertainty_ellipse_t;

#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipse.h"



typedef struct point_uncertainty_ellipse_t {
    struct supported_gad_shapes_t *shape; //model
    struct geographical_coordinates_t *point; //model
    struct uncertainty_ellipse_t *uncertainty_ellipse; //model
    int *confidence; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} point_uncertainty_ellipse_t;

__attribute__((deprecated)) point_uncertainty_ellipse_t *point_uncertainty_ellipse_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence
);

void point_uncertainty_ellipse_free(point_uncertainty_ellipse_t *point_uncertainty_ellipse);

point_uncertainty_ellipse_t *point_uncertainty_ellipse_parseFromJSON(cJSON *point_uncertainty_ellipseJSON);

cJSON *point_uncertainty_ellipse_convertToJSON(point_uncertainty_ellipse_t *point_uncertainty_ellipse);

#endif /* _point_uncertainty_ellipse_H_ */

