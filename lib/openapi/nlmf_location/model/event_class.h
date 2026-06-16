/*
 * event_class.h
 *
 * Specifies event classes.
 */

#ifndef _event_class_H_
#define _event_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct event_class_t event_class_t;




typedef struct event_class_t {

    int _library_owned; // Is the library responsible for freeing this object?
} event_class_t;

__attribute__((deprecated)) event_class_t *event_class_create(
);

void event_class_free(event_class_t *event_class);

event_class_t *event_class_parseFromJSON(cJSON *event_classJSON);

cJSON *event_class_convertToJSON(event_class_t *event_class);

#endif /* _event_class_H_ */

