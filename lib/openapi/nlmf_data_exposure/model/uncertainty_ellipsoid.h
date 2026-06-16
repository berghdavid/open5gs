/*
 * uncertainty_ellipsoid.h
 *
 * Ellipsoid with uncertainty
 */

#ifndef _uncertainty_ellipsoid_H_
#define _uncertainty_ellipsoid_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct uncertainty_ellipsoid_t uncertainty_ellipsoid_t;




typedef struct uncertainty_ellipsoid_t {
    float *semi_major; //numeric
    float *semi_minor; //numeric
    float *vertical; //numeric
    int *orientation_major; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} uncertainty_ellipsoid_t;

__attribute__((deprecated)) uncertainty_ellipsoid_t *uncertainty_ellipsoid_create(
    float *semi_major,
    float *semi_minor,
    float *vertical,
    int *orientation_major
);

void uncertainty_ellipsoid_free(uncertainty_ellipsoid_t *uncertainty_ellipsoid);

uncertainty_ellipsoid_t *uncertainty_ellipsoid_parseFromJSON(cJSON *uncertainty_ellipsoidJSON);

cJSON *uncertainty_ellipsoid_convertToJSON(uncertainty_ellipsoid_t *uncertainty_ellipsoid);

#endif /* _uncertainty_ellipsoid_H_ */

