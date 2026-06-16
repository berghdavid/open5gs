/*
 * relative_cartesian_location.h
 *
 * Relative Cartesian Location
 */

#ifndef _relative_cartesian_location_H_
#define _relative_cartesian_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct relative_cartesian_location_t relative_cartesian_location_t;




typedef struct relative_cartesian_location_t {
    float *x; //numeric
    float *y; //numeric
    float *z; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} relative_cartesian_location_t;

__attribute__((deprecated)) relative_cartesian_location_t *relative_cartesian_location_create(
    float *x,
    float *y,
    float *z
);

void relative_cartesian_location_free(relative_cartesian_location_t *relative_cartesian_location);

relative_cartesian_location_t *relative_cartesian_location_parseFromJSON(cJSON *relative_cartesian_locationJSON);

cJSON *relative_cartesian_location_convertToJSON(relative_cartesian_location_t *relative_cartesian_location);

#endif /* _relative_cartesian_location_H_ */

