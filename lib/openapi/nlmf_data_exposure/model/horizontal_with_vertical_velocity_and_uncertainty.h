/*
 * horizontal_with_vertical_velocity_and_uncertainty.h
 *
 * Horizontal and vertical velocity with speed uncertainty.
 */

#ifndef _horizontal_with_vertical_velocity_and_uncertainty_H_
#define _horizontal_with_vertical_velocity_and_uncertainty_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct horizontal_with_vertical_velocity_and_uncertainty_t horizontal_with_vertical_velocity_and_uncertainty_t;

#include "vertical_direction.h"



typedef struct horizontal_with_vertical_velocity_and_uncertainty_t {
    float *h_speed; //numeric
    int *bearing; //numeric
    float *v_speed; //numeric
    nlmf_dataexposure_vertical_direction__e v_direction; //referenced enum
    float *h_uncertainty; //numeric
    float *v_uncertainty; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} horizontal_with_vertical_velocity_and_uncertainty_t;

__attribute__((deprecated)) horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty_create(
    float *h_speed,
    int *bearing,
    float *v_speed,
    nlmf_dataexposure_vertical_direction__e v_direction,
    float *h_uncertainty,
    float *v_uncertainty
);

void horizontal_with_vertical_velocity_and_uncertainty_free(horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty);

horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty_parseFromJSON(cJSON *horizontal_with_vertical_velocity_and_uncertaintyJSON);

cJSON *horizontal_with_vertical_velocity_and_uncertainty_convertToJSON(horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty);

#endif /* _horizontal_with_vertical_velocity_and_uncertainty_H_ */

