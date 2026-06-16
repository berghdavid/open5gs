/*
 * local_area.h
 *
 * Local area specified by different shape
 */

#ifndef _local_area_H_
#define _local_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct local_area_t local_area_t;

#include "local2d_point_uncertainty_ellipse.h"
#include "local3d_point_uncertainty_ellipsoid.h"
#include "local_origin.h"
#include "relative_cartesian_location.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipse.h"
#include "uncertainty_ellipsoid.h"



typedef struct local_area_t {
    struct supported_gad_shapes_t *shape; //model
    struct local_origin_t *local_origin; //model
    struct relative_cartesian_location_t *point; //model
    struct uncertainty_ellipse_t *uncertainty_ellipse; //model
    int *confidence; //numeric
    struct uncertainty_ellipsoid_t *uncertainty_ellipsoid; //model
    int *v_confidence; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} local_area_t;

__attribute__((deprecated)) local_area_t *local_area_create(
    supported_gad_shapes_t *shape,
    local_origin_t *local_origin,
    relative_cartesian_location_t *point,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence,
    uncertainty_ellipsoid_t *uncertainty_ellipsoid,
    int *v_confidence
);

void local_area_free(local_area_t *local_area);

local_area_t *local_area_parseFromJSON(cJSON *local_areaJSON);

cJSON *local_area_convertToJSON(local_area_t *local_area);

#endif /* _local_area_H_ */

