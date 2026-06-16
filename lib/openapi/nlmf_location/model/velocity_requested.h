/*
 * velocity_requested.h
 *
 * Indicates velocity requirement.
 */

#ifndef _velocity_requested_H_
#define _velocity_requested_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct velocity_requested_t velocity_requested_t;




typedef struct velocity_requested_t {

    int _library_owned; // Is the library responsible for freeing this object?
} velocity_requested_t;

__attribute__((deprecated)) velocity_requested_t *velocity_requested_create(
);

void velocity_requested_free(velocity_requested_t *velocity_requested);

velocity_requested_t *velocity_requested_parseFromJSON(cJSON *velocity_requestedJSON);

cJSON *velocity_requested_convertToJSON(velocity_requested_t *velocity_requested);

#endif /* _velocity_requested_H_ */

