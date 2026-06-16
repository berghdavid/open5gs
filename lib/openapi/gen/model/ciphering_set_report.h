/*
 * ciphering_set_report.h
 *
 * Represents a report of Ciphering Data Set storage.
 */

#ifndef _OpenAPI_ciphering_set_report_H_
#define _OpenAPI_ciphering_set_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "storage_outcome.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_ciphering_set_report_s OpenAPI_ciphering_set_report_t;
typedef struct OpenAPI_ciphering_set_report_s {
    int ciphering_set_id;
    OpenAPI_storage_outcome_e storage_outcome;
} OpenAPI_ciphering_set_report_t;

OpenAPI_ciphering_set_report_t *OpenAPI_ciphering_set_report_create(
    int ciphering_set_id,
    OpenAPI_storage_outcome_e storage_outcome
);
void OpenAPI_ciphering_set_report_free(OpenAPI_ciphering_set_report_t *ciphering_set_report);
OpenAPI_ciphering_set_report_t *OpenAPI_ciphering_set_report_parseFromJSON(cJSON *ciphering_set_reportJSON);
cJSON *OpenAPI_ciphering_set_report_convertToJSON(OpenAPI_ciphering_set_report_t *ciphering_set_report);
OpenAPI_ciphering_set_report_t *OpenAPI_ciphering_set_report_copy(OpenAPI_ciphering_set_report_t *dst, OpenAPI_ciphering_set_report_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_ciphering_set_report_H_ */

