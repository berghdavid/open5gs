/*
 * occurrence_info.h
 *
 * Specifies occurrence of event reporting.
 */

#ifndef _occurrence_info_H_
#define _occurrence_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct occurrence_info_t occurrence_info_t;




typedef struct occurrence_info_t {

    int _library_owned; // Is the library responsible for freeing this object?
} occurrence_info_t;

__attribute__((deprecated)) occurrence_info_t *occurrence_info_create(
);

void occurrence_info_free(occurrence_info_t *occurrence_info);

occurrence_info_t *occurrence_info_parseFromJSON(cJSON *occurrence_infoJSON);

cJSON *occurrence_info_convertToJSON(occurrence_info_t *occurrence_info);

#endif /* _occurrence_info_H_ */

