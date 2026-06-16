/*
 * ldr_type.h
 *
 * Indicates LDR types.
 */

#ifndef _ldr_type_H_
#define _ldr_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ldr_type_t ldr_type_t;




typedef struct ldr_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} ldr_type_t;

__attribute__((deprecated)) ldr_type_t *ldr_type_create(
);

void ldr_type_free(ldr_type_t *ldr_type);

ldr_type_t *ldr_type_parseFromJSON(cJSON *ldr_typeJSON);

cJSON *ldr_type_convertToJSON(ldr_type_t *ldr_type);

#endif /* _ldr_type_H_ */

