/*
 * positioning_mode.h
 *
 * Indicates supported modes used for positioning method.
 */

#ifndef _positioning_mode_H_
#define _positioning_mode_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct positioning_mode_t positioning_mode_t;




typedef struct positioning_mode_t {

    int _library_owned; // Is the library responsible for freeing this object?
} positioning_mode_t;

__attribute__((deprecated)) positioning_mode_t *positioning_mode_create(
);

void positioning_mode_free(positioning_mode_t *positioning_mode);

positioning_mode_t *positioning_mode_parseFromJSON(cJSON *positioning_modeJSON);

cJSON *positioning_mode_convertToJSON(positioning_mode_t *positioning_mode);

#endif /* _positioning_mode_H_ */

