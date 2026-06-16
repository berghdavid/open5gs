/*
 * presence_state.h
 *
 * Possible values are: -IN_AREA: Indicates that the UE is inside or enters the presence reporting area. -OUT_OF_AREA: Indicates that the UE is outside or leaves the presence reporting area -UNKNOW: Indicates it is unknown whether the UE is in the presence reporting area or not -INACTIVE: Indicates that the presence reporting area is inactive in the serving node.  
 */

#ifndef _presence_state_H_
#define _presence_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct presence_state_t presence_state_t;




typedef struct presence_state_t {

    int _library_owned; // Is the library responsible for freeing this object?
} presence_state_t;

__attribute__((deprecated)) presence_state_t *presence_state_create(
);

void presence_state_free(presence_state_t *presence_state);

presence_state_t *presence_state_parseFromJSON(cJSON *presence_stateJSON);

cJSON *presence_state_convertToJSON(presence_state_t *presence_state);

#endif /* _presence_state_H_ */

