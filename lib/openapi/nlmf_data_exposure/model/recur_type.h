/*
 * recur_type.h
 *
 * Indicates the recurrence applicable to a time window.
 */

#ifndef _recur_type_H_
#define _recur_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct recur_type_t recur_type_t;




typedef struct recur_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} recur_type_t;

__attribute__((deprecated)) recur_type_t *recur_type_create(
);

void recur_type_free(recur_type_t *recur_type);

recur_type_t *recur_type_parseFromJSON(cJSON *recur_typeJSON);

cJSON *recur_type_convertToJSON(recur_type_t *recur_type);

#endif /* _recur_type_H_ */

