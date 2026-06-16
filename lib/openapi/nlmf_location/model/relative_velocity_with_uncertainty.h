/*
 * relative_velocity_with_uncertainty.h
 *
 * Relative velocity with radial velocity and transverse velocity.
 */

#ifndef _relative_velocity_with_uncertainty_H_
#define _relative_velocity_with_uncertainty_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct relative_velocity_with_uncertainty_t relative_velocity_with_uncertainty_t;

#include "angular_velocity.h"
#include "radial_velocity.h"



typedef struct relative_velocity_with_uncertainty_t {
    struct radial_velocity_t *r_velocity; //model
    struct angular_velocity_t *a_transverse_velocity; //model
    struct angular_velocity_t *e_transverse_velocity; //model

    int _library_owned; // Is the library responsible for freeing this object?
} relative_velocity_with_uncertainty_t;

__attribute__((deprecated)) relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty_create(
    radial_velocity_t *r_velocity,
    angular_velocity_t *a_transverse_velocity,
    angular_velocity_t *e_transverse_velocity
);

void relative_velocity_with_uncertainty_free(relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);

relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty_parseFromJSON(cJSON *relative_velocity_with_uncertaintyJSON);

cJSON *relative_velocity_with_uncertainty_convertToJSON(relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty);

#endif /* _relative_velocity_with_uncertainty_H_ */

