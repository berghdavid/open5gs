/*
 * termination_cause.h
 *
 * Specifies causes of event reporting termination.
 */

#ifndef _termination_cause_H_
#define _termination_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct termination_cause_t termination_cause_t;




typedef struct termination_cause_t {

    int _library_owned; // Is the library responsible for freeing this object?
} termination_cause_t;

__attribute__((deprecated)) termination_cause_t *termination_cause_create(
);

void termination_cause_free(termination_cause_t *termination_cause);

termination_cause_t *termination_cause_parseFromJSON(cJSON *termination_causeJSON);

cJSON *termination_cause_convertToJSON(termination_cause_t *termination_cause);

#endif /* _termination_cause_H_ */

