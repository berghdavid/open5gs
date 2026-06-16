/*
 * integrity_protection_level.h
 *
 * Integrity Protection Level.
 */

#ifndef _integrity_protection_level_H_
#define _integrity_protection_level_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct integrity_protection_level_t integrity_protection_level_t;




typedef struct integrity_protection_level_t {
    int *horizontal_protection_level; //numeric
    int *vertical_protection_level; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} integrity_protection_level_t;

__attribute__((deprecated)) integrity_protection_level_t *integrity_protection_level_create(
    int *horizontal_protection_level,
    int *vertical_protection_level
);

void integrity_protection_level_free(integrity_protection_level_t *integrity_protection_level);

integrity_protection_level_t *integrity_protection_level_parseFromJSON(cJSON *integrity_protection_levelJSON);

cJSON *integrity_protection_level_convertToJSON(integrity_protection_level_t *integrity_protection_level);

#endif /* _integrity_protection_level_H_ */

