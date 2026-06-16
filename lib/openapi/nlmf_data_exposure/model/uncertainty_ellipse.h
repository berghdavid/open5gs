/*
 * uncertainty_ellipse.h
 *
 * Ellipse with uncertainty.
 */

#ifndef _uncertainty_ellipse_H_
#define _uncertainty_ellipse_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct uncertainty_ellipse_t uncertainty_ellipse_t;




typedef struct uncertainty_ellipse_t {
    float *semi_major; //numeric
    float *semi_minor; //numeric
    int *orientation_major; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} uncertainty_ellipse_t;

__attribute__((deprecated)) uncertainty_ellipse_t *uncertainty_ellipse_create(
    float *semi_major,
    float *semi_minor,
    int *orientation_major
);

void uncertainty_ellipse_free(uncertainty_ellipse_t *uncertainty_ellipse);

uncertainty_ellipse_t *uncertainty_ellipse_parseFromJSON(cJSON *uncertainty_ellipseJSON);

cJSON *uncertainty_ellipse_convertToJSON(uncertainty_ellipse_t *uncertainty_ellipse);

#endif /* _uncertainty_ellipse_H_ */

