/*
 * ue_location_service_ind.h
 *
 * Specifies location service types requested by UE.
 */

#ifndef _ue_location_service_ind_H_
#define _ue_location_service_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ue_location_service_ind_t ue_location_service_ind_t;




typedef struct ue_location_service_ind_t {

    int _library_owned; // Is the library responsible for freeing this object?
} ue_location_service_ind_t;

__attribute__((deprecated)) ue_location_service_ind_t *ue_location_service_ind_create(
);

void ue_location_service_ind_free(ue_location_service_ind_t *ue_location_service_ind);

ue_location_service_ind_t *ue_location_service_ind_parseFromJSON(cJSON *ue_location_service_indJSON);

cJSON *ue_location_service_ind_convertToJSON(ue_location_service_ind_t *ue_location_service_ind);

#endif /* _ue_location_service_ind_H_ */

