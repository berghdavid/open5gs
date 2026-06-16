/*
 * local2d_point_uncertainty_ellipse.h
 *
 * Local 2D point with uncertainty ellipse
 */

#ifndef _local2d_point_uncertainty_ellipse_H_
#define _local2d_point_uncertainty_ellipse_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct local2d_point_uncertainty_ellipse_t local2d_point_uncertainty_ellipse_t;

#include "gad_shape.h"
#include "local_origin.h"
#include "relative_cartesian_location.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipse.h"



typedef struct local2d_point_uncertainty_ellipse_t {
    struct supported_gad_shapes_t *shape; //model
    struct local_origin_t *local_origin; //model
    struct relative_cartesian_location_t *point; //model
    struct uncertainty_ellipse_t *uncertainty_ellipse; //model
    int *confidence; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} local2d_point_uncertainty_ellipse_t;

__attribute__((deprecated)) local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_create(
    supported_gad_shapes_t *shape,
    local_origin_t *local_origin,
    relative_cartesian_location_t *point,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence
);

void local2d_point_uncertainty_ellipse_free(local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);

local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_parseFromJSON(cJSON *local2d_point_uncertainty_ellipseJSON);

cJSON *local2d_point_uncertainty_ellipse_convertToJSON(local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);

#endif /* _local2d_point_uncertainty_ellipse_H_ */

