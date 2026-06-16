/*
 * usage.h
 *
 * Indicates usage made of the location measurement.
 */

#ifndef _usage_H_
#define _usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct usage_t usage_t;




typedef struct usage_t {

    int _library_owned; // Is the library responsible for freeing this object?
} usage_t;

__attribute__((deprecated)) usage_t *usage_create(
);

void usage_free(usage_t *usage);

usage_t *usage_parseFromJSON(cJSON *usageJSON);

cJSON *usage_convertToJSON(usage_t *usage);

#endif /* _usage_H_ */

