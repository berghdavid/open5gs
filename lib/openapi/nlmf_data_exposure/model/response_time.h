/*
 * response_time.h
 *
 * Indicates acceptable delay of location request.
 */

#ifndef _response_time_H_
#define _response_time_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct response_time_t response_time_t;




typedef struct response_time_t {

    int _library_owned; // Is the library responsible for freeing this object?
} response_time_t;

__attribute__((deprecated)) response_time_t *response_time_create(
);

void response_time_free(response_time_t *response_time);

response_time_t *response_time_parseFromJSON(cJSON *response_timeJSON);

cJSON *response_time_convertToJSON(response_time_t *response_time);

#endif /* _response_time_H_ */

