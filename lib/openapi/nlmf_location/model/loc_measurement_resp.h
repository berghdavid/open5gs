/*
 * loc_measurement_resp.h
 *
 * Location Measurement Response.
 */

#ifndef _loc_measurement_resp_H_
#define _loc_measurement_resp_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct loc_measurement_resp_t loc_measurement_resp_t;

#include "loc_measurements.h"



typedef struct loc_measurement_resp_t {
    list_t *loc_measurements; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} loc_measurement_resp_t;

__attribute__((deprecated)) loc_measurement_resp_t *loc_measurement_resp_create(
    list_t *loc_measurements
);

void loc_measurement_resp_free(loc_measurement_resp_t *loc_measurement_resp);

loc_measurement_resp_t *loc_measurement_resp_parseFromJSON(cJSON *loc_measurement_respJSON);

cJSON *loc_measurement_resp_convertToJSON(loc_measurement_resp_t *loc_measurement_resp);

#endif /* _loc_measurement_resp_H_ */

