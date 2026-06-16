/*
 * related_ue.h
 *
 * Related UE Information
 */

#ifndef _related_ue_H_
#define _related_ue_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct related_ue_t related_ue_t;

#include "related_ue_type.h"



typedef struct related_ue_t {
    char *applicationlayer_id; // string
    struct related_ue_type_t *related_ue_type; //model

    int _library_owned; // Is the library responsible for freeing this object?
} related_ue_t;

__attribute__((deprecated)) related_ue_t *related_ue_create(
    char *applicationlayer_id,
    related_ue_type_t *related_ue_type
);

void related_ue_free(related_ue_t *related_ue);

related_ue_t *related_ue_parseFromJSON(cJSON *related_ueJSON);

cJSON *related_ue_convertToJSON(related_ue_t *related_ue);

#endif /* _related_ue_H_ */

