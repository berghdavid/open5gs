/*
 * ellipsoid_arc.h
 *
 * Ellipsoid Arc.
 */

#ifndef _ellipsoid_arc_H_
#define _ellipsoid_arc_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ellipsoid_arc_t ellipsoid_arc_t;

#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"



typedef struct ellipsoid_arc_t {
    struct supported_gad_shapes_t *shape; //model
    struct geographical_coordinates_t *point; //model
    int *inner_radius; //numeric
    float *uncertainty_radius; //numeric
    int *offset_angle; //numeric
    int *included_angle; //numeric
    int *confidence; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} ellipsoid_arc_t;

__attribute__((deprecated)) ellipsoid_arc_t *ellipsoid_arc_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    int *inner_radius,
    float *uncertainty_radius,
    int *offset_angle,
    int *included_angle,
    int *confidence
);

void ellipsoid_arc_free(ellipsoid_arc_t *ellipsoid_arc);

ellipsoid_arc_t *ellipsoid_arc_parseFromJSON(cJSON *ellipsoid_arcJSON);

cJSON *ellipsoid_arc_convertToJSON(ellipsoid_arc_t *ellipsoid_arc);

#endif /* _ellipsoid_arc_H_ */

