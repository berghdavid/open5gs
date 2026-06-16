/*
 * positioning_method.h
 *
 * Indicates supported positioning methods.
 */

#ifndef _positioning_method_H_
#define _positioning_method_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct positioning_method_t positioning_method_t;




typedef struct positioning_method_t {

    int _library_owned; // Is the library responsible for freeing this object?
} positioning_method_t;

__attribute__((deprecated)) positioning_method_t *positioning_method_create(
);

void positioning_method_free(positioning_method_t *positioning_method);

positioning_method_t *positioning_method_parseFromJSON(cJSON *positioning_methodJSON);

cJSON *positioning_method_convertToJSON(positioning_method_t *positioning_method);

#endif /* _positioning_method_H_ */

