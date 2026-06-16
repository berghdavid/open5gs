/*
 * loc_measurements.h
 *
 * PRU Location Measurements.
 */

#ifndef _loc_measurements_H_
#define _loc_measurements_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct loc_measurements_t loc_measurements_t;




typedef struct loc_measurements_t {
    char *loc_info; //ByteArray

    int _library_owned; // Is the library responsible for freeing this object?
} loc_measurements_t;

__attribute__((deprecated)) loc_measurements_t *loc_measurements_create(
    char *loc_info
);

void loc_measurements_free(loc_measurements_t *loc_measurements);

loc_measurements_t *loc_measurements_parseFromJSON(cJSON *loc_measurementsJSON);

cJSON *loc_measurements_convertToJSON(loc_measurements_t *loc_measurements);

#endif /* _loc_measurements_H_ */

