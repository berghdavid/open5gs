/*
 * positioning_method_and_usage.h
 *
 * Indicates the usage of a positioning method.
 */

#ifndef _positioning_method_and_usage_H_
#define _positioning_method_and_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct positioning_method_and_usage_t positioning_method_and_usage_t;

#include "positioning_method.h"
#include "positioning_mode.h"
#include "usage.h"



typedef struct positioning_method_and_usage_t {
    struct positioning_method_t *method; //model
    struct positioning_mode_t *mode; //model
    struct usage_t *usage; //model
    int *method_code; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} positioning_method_and_usage_t;

__attribute__((deprecated)) positioning_method_and_usage_t *positioning_method_and_usage_create(
    positioning_method_t *method,
    positioning_mode_t *mode,
    usage_t *usage,
    int *method_code
);

void positioning_method_and_usage_free(positioning_method_and_usage_t *positioning_method_and_usage);

positioning_method_and_usage_t *positioning_method_and_usage_parseFromJSON(cJSON *positioning_method_and_usageJSON);

cJSON *positioning_method_and_usage_convertToJSON(positioning_method_and_usage_t *positioning_method_and_usage);

#endif /* _positioning_method_and_usage_H_ */

