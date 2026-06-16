/*
 * geographic_area.h
 *
 * Geographic area specified by different shape.
 */

#ifndef _geographic_area_H_
#define _geographic_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct geographic_area_t geographic_area_t;

#include "ellipsoid_arc.h"
#include "geographical_coordinates.h"
#include "point.h"
#include "point_altitude.h"
#include "point_altitude_uncertainty.h"
#include "point_uncertainty_circle.h"
#include "point_uncertainty_ellipse.h"
#include "polygon.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipse.h"



typedef struct geographic_area_t {
    struct supported_gad_shapes_t *shape; //model
    struct geographical_coordinates_t *point; //model
    float *uncertainty; //numeric
    struct uncertainty_ellipse_t *uncertainty_ellipse; //model
    int *confidence; //numeric
    list_t *point_list; //nonprimitive container
    double *altitude; //numeric
    float *uncertainty_altitude; //numeric
    int *v_confidence; //numeric
    int *inner_radius; //numeric
    float *uncertainty_radius; //numeric
    int *offset_angle; //numeric
    int *included_angle; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} geographic_area_t;

__attribute__((deprecated)) geographic_area_t *geographic_area_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    float *uncertainty,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence,
    list_t *point_list,
    double *altitude,
    float *uncertainty_altitude,
    int *v_confidence,
    int *inner_radius,
    float *uncertainty_radius,
    int *offset_angle,
    int *included_angle
);

void geographic_area_free(geographic_area_t *geographic_area);

geographic_area_t *geographic_area_parseFromJSON(cJSON *geographic_areaJSON);

cJSON *geographic_area_convertToJSON(geographic_area_t *geographic_area);

#endif /* _geographic_area_H_ */

