/*
 * patch_operation.h
 *
 * Operations as defined in IETF RFC 6902.
 */

#ifndef _patch_operation_H_
#define _patch_operation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_operation_t patch_operation_t;




typedef struct patch_operation_t {

    int _library_owned; // Is the library responsible for freeing this object?
} patch_operation_t;

__attribute__((deprecated)) patch_operation_t *patch_operation_create(
);

void patch_operation_free(patch_operation_t *patch_operation);

patch_operation_t *patch_operation_parseFromJSON(cJSON *patch_operationJSON);

cJSON *patch_operation_convertToJSON(patch_operation_t *patch_operation);

#endif /* _patch_operation_H_ */

