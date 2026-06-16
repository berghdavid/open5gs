/*
 * sl_positioning_capability.h
 *
 * The Ranging and sidelink positioning capabilities supported by the UE.
 */

#ifndef _sl_positioning_capability_H_
#define _sl_positioning_capability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sl_positioning_capability_t sl_positioning_capability_t;




typedef struct sl_positioning_capability_t {

    int _library_owned; // Is the library responsible for freeing this object?
} sl_positioning_capability_t;

__attribute__((deprecated)) sl_positioning_capability_t *sl_positioning_capability_create(
);

void sl_positioning_capability_free(sl_positioning_capability_t *sl_positioning_capability);

sl_positioning_capability_t *sl_positioning_capability_parseFromJSON(cJSON *sl_positioning_capabilityJSON);

cJSON *sl_positioning_capability_convertToJSON(sl_positioning_capability_t *sl_positioning_capability);

#endif /* _sl_positioning_capability_H_ */

