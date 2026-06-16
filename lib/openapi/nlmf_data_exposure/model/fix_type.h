/*
 * fix_type.h
 *
 * Specifies the positioning fix type.
 */

#ifndef _fix_type_H_
#define _fix_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct fix_type_t fix_type_t;




typedef struct fix_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} fix_type_t;

__attribute__((deprecated)) fix_type_t *fix_type_create(
);

void fix_type_free(fix_type_t *fix_type);

fix_type_t *fix_type_parseFromJSON(cJSON *fix_typeJSON);

cJSON *fix_type_convertToJSON(fix_type_t *fix_type);

#endif /* _fix_type_H_ */

