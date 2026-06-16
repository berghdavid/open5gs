/*
 * horizontal_velocity_with_uncertainty.h
 *
 * Horizontal velocity with speed uncertainty.
 */

#ifndef _horizontal_velocity_with_uncertainty_H_
#define _horizontal_velocity_with_uncertainty_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct horizontal_velocity_with_uncertainty_t horizontal_velocity_with_uncertainty_t;




typedef struct horizontal_velocity_with_uncertainty_t {
    float *h_speed; //numeric
    int *bearing; //numeric
    float *h_uncertainty; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} horizontal_velocity_with_uncertainty_t;

__attribute__((deprecated)) horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty_create(
    float *h_speed,
    int *bearing,
    float *h_uncertainty
);

void horizontal_velocity_with_uncertainty_free(horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty_parseFromJSON(cJSON *horizontal_velocity_with_uncertaintyJSON);

cJSON *horizontal_velocity_with_uncertainty_convertToJSON(horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

#endif /* _horizontal_velocity_with_uncertainty_H_ */

