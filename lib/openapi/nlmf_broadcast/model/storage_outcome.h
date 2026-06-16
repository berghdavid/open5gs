/*
 * storage_outcome.h
 *
 * Indicates the result of Ciphering Data Set storage.
 */

#ifndef _storage_outcome_H_
#define _storage_outcome_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_outcome_t storage_outcome_t;


// Enum  for storage_outcome

typedef enum { lmf_broadcast_storage_outcome__NULL = 0, lmf_broadcast_storage_outcome__STORAGE_SUCCESSFUL, lmf_broadcast_storage_outcome__STORAGE_FAILED } lmf_broadcast_storage_outcome__e;

char* storage_outcome_storage_outcome_ToString(lmf_broadcast_storage_outcome__e storage_outcome);

lmf_broadcast_storage_outcome__e storage_outcome_storage_outcome_FromString(char* storage_outcome);

cJSON *storage_outcome_convertToJSON(lmf_broadcast_storage_outcome__e storage_outcome);

lmf_broadcast_storage_outcome__e storage_outcome_parseFromJSON(cJSON *storage_outcomeJSON);

#endif /* _storage_outcome_H_ */

