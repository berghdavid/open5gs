/*
 * cm_state.h
 *
 * Describes the connection management state of a UE
 */

#ifndef _cm_state_H_
#define _cm_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cm_state_t cm_state_t;




typedef struct cm_state_t {

    int _library_owned; // Is the library responsible for freeing this object?
} cm_state_t;

__attribute__((deprecated)) cm_state_t *cm_state_create(
);

void cm_state_free(cm_state_t *cm_state);

cm_state_t *cm_state_parseFromJSON(cJSON *cm_stateJSON);

cJSON *cm_state_convertToJSON(cm_state_t *cm_state);

#endif /* _cm_state_H_ */

