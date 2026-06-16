/*
 * model_3_d_relative_location.h
 *
 * Represents a relative 3D location with uncertainty ellipsoid.
 */

#ifndef _model_3_d_relative_location_H_
#define _model_3_d_relative_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_3_d_relative_location_t model_3_d_relative_location_t;




typedef struct model_3_d_relative_location_t {
    float *semi_minor; //numeric
    float *semi_major; //numeric
    float *vertical_uncertainty; //numeric
    int *orientation_angle; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} model_3_d_relative_location_t;

__attribute__((deprecated)) model_3_d_relative_location_t *model_3_d_relative_location_create(
    float *semi_minor,
    float *semi_major,
    float *vertical_uncertainty,
    int *orientation_angle
);

void model_3_d_relative_location_free(model_3_d_relative_location_t *model_3_d_relative_location);

model_3_d_relative_location_t *model_3_d_relative_location_parseFromJSON(cJSON *model_3_d_relative_locationJSON);

cJSON *model_3_d_relative_location_convertToJSON(model_3_d_relative_location_t *model_3_d_relative_location);

#endif /* _model_3_d_relative_location_H_ */

