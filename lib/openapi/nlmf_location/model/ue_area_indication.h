/*
 * ue_area_indication.h
 *
 * Indicates area (country, area in a country or international area) where UE is located 
 */

#ifndef _ue_area_indication_H_
#define _ue_area_indication_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ue_area_indication_t ue_area_indication_t;




typedef struct ue_area_indication_t {
    char *country; // string
    int *international_area_ind; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ue_area_indication_t;

__attribute__((deprecated)) ue_area_indication_t *ue_area_indication_create(
    char *country,
    int *international_area_ind
);

void ue_area_indication_free(ue_area_indication_t *ue_area_indication);

ue_area_indication_t *ue_area_indication_parseFromJSON(cJSON *ue_area_indicationJSON);

cJSON *ue_area_indication_convertToJSON(ue_area_indication_t *ue_area_indication);

#endif /* _ue_area_indication_H_ */

