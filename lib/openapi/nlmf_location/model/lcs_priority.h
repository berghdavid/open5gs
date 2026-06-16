/*
 * lcs_priority.h
 *
 * Indicates priority of the LCS client.
 */

#ifndef _lcs_priority_H_
#define _lcs_priority_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lcs_priority_t lcs_priority_t;




typedef struct lcs_priority_t {

    int _library_owned; // Is the library responsible for freeing this object?
} lcs_priority_t;

__attribute__((deprecated)) lcs_priority_t *lcs_priority_create(
);

void lcs_priority_free(lcs_priority_t *lcs_priority);

lcs_priority_t *lcs_priority_parseFromJSON(cJSON *lcs_priorityJSON);

cJSON *lcs_priority_convertToJSON(lcs_priority_t *lcs_priority);

#endif /* _lcs_priority_H_ */

