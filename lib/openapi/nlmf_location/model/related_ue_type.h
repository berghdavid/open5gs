/*
 * related_ue_type.h
 *
 * Specifies the different roles of UE for ranging and sidelink positioning service.
 */

#ifndef _related_ue_type_H_
#define _related_ue_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct related_ue_type_t related_ue_type_t;




typedef struct related_ue_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} related_ue_type_t;

__attribute__((deprecated)) related_ue_type_t *related_ue_type_create(
);

void related_ue_type_free(related_ue_type_t *related_ue_type);

related_ue_type_t *related_ue_type_parseFromJSON(cJSON *related_ue_typeJSON);

cJSON *related_ue_type_convertToJSON(related_ue_type_t *related_ue_type);

#endif /* _related_ue_type_H_ */

