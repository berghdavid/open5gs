/*
 * reported_event_type.h
 *
 * Specifies type of event reporting.
 */

#ifndef _reported_event_type_H_
#define _reported_event_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reported_event_type_t reported_event_type_t;




typedef struct reported_event_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} reported_event_type_t;

__attribute__((deprecated)) reported_event_type_t *reported_event_type_create(
);

void reported_event_type_free(reported_event_type_t *reported_event_type);

reported_event_type_t *reported_event_type_parseFromJSON(cJSON *reported_event_typeJSON);

cJSON *reported_event_type_convertToJSON(reported_event_type_t *reported_event_type);

#endif /* _reported_event_type_H_ */

