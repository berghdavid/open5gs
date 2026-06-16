/*
 * vertical_direction.h
 *
 * Indicates direction of vertical speed.
 */

#ifndef _vertical_direction_H_
#define _vertical_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vertical_direction_t vertical_direction_t;


// Enum  for vertical_direction

typedef enum { lmf_location_vertical_direction__NULL = 0, lmf_location_vertical_direction__UPWARD, lmf_location_vertical_direction__DOWNWARD } lmf_location_vertical_direction__e;

char* vertical_direction_vertical_direction_ToString(lmf_location_vertical_direction__e vertical_direction);

lmf_location_vertical_direction__e vertical_direction_vertical_direction_FromString(char* vertical_direction);

cJSON *vertical_direction_convertToJSON(lmf_location_vertical_direction__e vertical_direction);

lmf_location_vertical_direction__e vertical_direction_parseFromJSON(cJSON *vertical_directionJSON);

#endif /* _vertical_direction_H_ */

