/*
 * model_2_d_relative_location.h
 *
 * Represents a relative 2D location with uncertainty ellipse.
 */

#ifndef _model_2_d_relative_location_H_
#define _model_2_d_relative_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_2_d_relative_location_t model_2_d_relative_location_t;




typedef struct model_2_d_relative_location_t {
    float *semi_minor; //numeric
    float *semi_major; //numeric
    int *orientation_angle; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} model_2_d_relative_location_t;

__attribute__((deprecated)) model_2_d_relative_location_t *model_2_d_relative_location_create(
    float *semi_minor,
    float *semi_major,
    int *orientation_angle
);

void model_2_d_relative_location_free(model_2_d_relative_location_t *model_2_d_relative_location);

model_2_d_relative_location_t *model_2_d_relative_location_parseFromJSON(cJSON *model_2_d_relative_locationJSON);

cJSON *model_2_d_relative_location_convertToJSON(model_2_d_relative_location_t *model_2_d_relative_location);

#endif /* _model_2_d_relative_location_H_ */

