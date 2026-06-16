/*
 * point_altitude_uncertainty.h
 *
 * Ellipsoid point with altitude and uncertainty ellipsoid.
 */

#ifndef _point_altitude_uncertainty_H_
#define _point_altitude_uncertainty_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct point_altitude_uncertainty_t point_altitude_uncertainty_t;

#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipse.h"



typedef struct point_altitude_uncertainty_t {
    struct supported_gad_shapes_t *shape; //model
    struct geographical_coordinates_t *point; //model
    double *altitude; //numeric
    struct uncertainty_ellipse_t *uncertainty_ellipse; //model
    float *uncertainty_altitude; //numeric
    int *confidence; //numeric
    int *v_confidence; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} point_altitude_uncertainty_t;

__attribute__((deprecated)) point_altitude_uncertainty_t *point_altitude_uncertainty_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    double *altitude,
    uncertainty_ellipse_t *uncertainty_ellipse,
    float *uncertainty_altitude,
    int *confidence,
    int *v_confidence
);

void point_altitude_uncertainty_free(point_altitude_uncertainty_t *point_altitude_uncertainty);

point_altitude_uncertainty_t *point_altitude_uncertainty_parseFromJSON(cJSON *point_altitude_uncertaintyJSON);

cJSON *point_altitude_uncertainty_convertToJSON(point_altitude_uncertainty_t *point_altitude_uncertainty);

#endif /* _point_altitude_uncertainty_H_ */

