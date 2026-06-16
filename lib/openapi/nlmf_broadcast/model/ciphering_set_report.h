/*
 * ciphering_set_report.h
 *
 * Represents a report of Ciphering Data Set storage.
 */

#ifndef _ciphering_set_report_H_
#define _ciphering_set_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ciphering_set_report_t ciphering_set_report_t;

#include "storage_outcome.h"



typedef struct ciphering_set_report_t {
    int *ciphering_set_id; //numeric
    lmf_broadcast_storage_outcome__e storage_outcome; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} ciphering_set_report_t;

__attribute__((deprecated)) ciphering_set_report_t *ciphering_set_report_create(
    int *ciphering_set_id,
    lmf_broadcast_storage_outcome__e storage_outcome
);

void ciphering_set_report_free(ciphering_set_report_t *ciphering_set_report);

ciphering_set_report_t *ciphering_set_report_parseFromJSON(cJSON *ciphering_set_reportJSON);

cJSON *ciphering_set_report_convertToJSON(ciphering_set_report_t *ciphering_set_report);

#endif /* _ciphering_set_report_H_ */

