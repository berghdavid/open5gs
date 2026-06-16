/*
 * storage_outcome.h
 *
 * Indicates the result of Ciphering Data Set storage.
 */

#ifndef _OpenAPI_storage_outcome_H_
#define _OpenAPI_storage_outcome_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { OpenAPI_storage_outcome_NULL = 0, OpenAPI_storage_outcome_STORAGE_SUCCESSFUL, OpenAPI_storage_outcome_STORAGE_FAILED } OpenAPI_storage_outcome_e;

char* OpenAPI_storage_outcome_ToString(OpenAPI_storage_outcome_e storage_outcome);

OpenAPI_storage_outcome_e OpenAPI_storage_outcome_FromString(char* storage_outcome);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_storage_outcome_H_ */

