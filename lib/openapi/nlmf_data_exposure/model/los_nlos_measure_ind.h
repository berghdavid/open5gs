/*
 * los_nlos_measure_ind.h
 *
 * Specifies LOS measurement or NLOS measurement.
 */

#ifndef _los_nlos_measure_ind_H_
#define _los_nlos_measure_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct los_nlos_measure_ind_t los_nlos_measure_ind_t;




typedef struct los_nlos_measure_ind_t {

    int _library_owned; // Is the library responsible for freeing this object?
} los_nlos_measure_ind_t;

__attribute__((deprecated)) los_nlos_measure_ind_t *los_nlos_measure_ind_create(
);

void los_nlos_measure_ind_free(los_nlos_measure_ind_t *los_nlos_measure_ind);

los_nlos_measure_ind_t *los_nlos_measure_ind_parseFromJSON(cJSON *los_nlos_measure_indJSON);

cJSON *los_nlos_measure_ind_convertToJSON(los_nlos_measure_ind_t *los_nlos_measure_ind);

#endif /* _los_nlos_measure_ind_H_ */

