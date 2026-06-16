/*
 * indoor_outdoor_ind.h
 *
 * Specifies UE location indoor or outdoor.
 */

#ifndef _indoor_outdoor_ind_H_
#define _indoor_outdoor_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct indoor_outdoor_ind_t indoor_outdoor_ind_t;




typedef struct indoor_outdoor_ind_t {

    int _library_owned; // Is the library responsible for freeing this object?
} indoor_outdoor_ind_t;

__attribute__((deprecated)) indoor_outdoor_ind_t *indoor_outdoor_ind_create(
);

void indoor_outdoor_ind_free(indoor_outdoor_ind_t *indoor_outdoor_ind);

indoor_outdoor_ind_t *indoor_outdoor_ind_parseFromJSON(cJSON *indoor_outdoor_indJSON);

cJSON *indoor_outdoor_ind_convertToJSON(indoor_outdoor_ind_t *indoor_outdoor_ind);

#endif /* _indoor_outdoor_ind_H_ */

