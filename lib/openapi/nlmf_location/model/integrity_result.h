/*
 * integrity_result.h
 *
 * Integrity Result.
 */

#ifndef _integrity_result_H_
#define _integrity_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct integrity_result_t integrity_result_t;

#include "integrity_computing_entity.h"
#include "integrity_protection_level.h"



typedef struct integrity_result_t {
    struct integrity_computing_entity_t *computing_entity; //model
    struct integrity_protection_level_t *protection_level; //model
    int *integrity_req_met_ind; //boolean
    int *achieved_tir; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} integrity_result_t;

__attribute__((deprecated)) integrity_result_t *integrity_result_create(
    integrity_computing_entity_t *computing_entity,
    integrity_protection_level_t *protection_level,
    int *integrity_req_met_ind,
    int *achieved_tir
);

void integrity_result_free(integrity_result_t *integrity_result);

integrity_result_t *integrity_result_parseFromJSON(cJSON *integrity_resultJSON);

cJSON *integrity_result_convertToJSON(integrity_result_t *integrity_result);

#endif /* _integrity_result_H_ */

