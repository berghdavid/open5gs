/*
 * velocity_estimate.h
 *
 * Velocity estimate.
 */

#ifndef _velocity_estimate_H_
#define _velocity_estimate_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct velocity_estimate_t velocity_estimate_t;

#include "angular_velocity.h"
#include "horizontal_velocity.h"
#include "horizontal_velocity_with_uncertainty.h"
#include "horizontal_with_vertical_velocity.h"
#include "horizontal_with_vertical_velocity_and_uncertainty.h"
#include "radial_velocity.h"
#include "relative_velocity_with_uncertainty.h"
#include "vertical_direction.h"



typedef struct velocity_estimate_t {
    float *h_speed; //numeric
    int *bearing; //numeric
    float *v_speed; //numeric
    nlmf_dataexposure_vertical_direction__e v_direction; //referenced enum
    float *h_uncertainty; //numeric
    float *v_uncertainty; //numeric
    struct radial_velocity_t *r_velocity; //model
    struct angular_velocity_t *a_transverse_velocity; //model
    struct angular_velocity_t *e_transverse_velocity; //model

    int _library_owned; // Is the library responsible for freeing this object?
} velocity_estimate_t;

__attribute__((deprecated)) velocity_estimate_t *velocity_estimate_create(
    float *h_speed,
    int *bearing,
    float *v_speed,
    nlmf_dataexposure_vertical_direction__e v_direction,
    float *h_uncertainty,
    float *v_uncertainty,
    radial_velocity_t *r_velocity,
    angular_velocity_t *a_transverse_velocity,
    angular_velocity_t *e_transverse_velocity
);

void velocity_estimate_free(velocity_estimate_t *velocity_estimate);

velocity_estimate_t *velocity_estimate_parseFromJSON(cJSON *velocity_estimateJSON);

cJSON *velocity_estimate_convertToJSON(velocity_estimate_t *velocity_estimate);

#endif /* _velocity_estimate_H_ */

