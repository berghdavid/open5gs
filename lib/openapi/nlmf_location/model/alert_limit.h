/*
 * alert_limit.h
 *
 * Alert Limit.
 */

#ifndef _alert_limit_H_
#define _alert_limit_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct alert_limit_t alert_limit_t;




typedef struct alert_limit_t {
    int *horizontal_protection_level; //numeric
    int *vertical_protection_level; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} alert_limit_t;

__attribute__((deprecated)) alert_limit_t *alert_limit_create(
    int *horizontal_protection_level,
    int *vertical_protection_level
);

void alert_limit_free(alert_limit_t *alert_limit);

alert_limit_t *alert_limit_parseFromJSON(cJSON *alert_limitJSON);

cJSON *alert_limit_convertToJSON(alert_limit_t *alert_limit);

#endif /* _alert_limit_H_ */

