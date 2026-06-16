/*
 * patch_item.h
 *
 * it contains information on data to be changed.
 */

#ifndef _patch_item_H_
#define _patch_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_item_t patch_item_t;

#include "any_type.h"
#include "patch_operation.h"



typedef struct patch_item_t {
    struct patch_operation_t *op; //model
    char *path; // string
    char *from; // string
    any_type_t *value; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} patch_item_t;

__attribute__((deprecated)) patch_item_t *patch_item_create(
    patch_operation_t *op,
    char *path,
    char *from,
    any_type_t *value
);

void patch_item_free(patch_item_t *patch_item);

patch_item_t *patch_item_parseFromJSON(cJSON *patch_itemJSON);

cJSON *patch_item_convertToJSON(patch_item_t *patch_item);

#endif /* _patch_item_H_ */

