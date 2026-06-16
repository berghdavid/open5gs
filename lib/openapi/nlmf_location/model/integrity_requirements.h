/*
 * integrity_requirements.h
 *
 * integrity requirements.
 */

#ifndef _integrity_requirements_H_
#define _integrity_requirements_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct integrity_requirements_t integrity_requirements_t;

#include "alert_limit.h"



typedef struct integrity_requirements_t {
    int *time_to_alert; //numeric
    int *target_integrity_risk; //numeric
    struct alert_limit_t *alert_limit; //model

    int _library_owned; // Is the library responsible for freeing this object?
} integrity_requirements_t;

__attribute__((deprecated)) integrity_requirements_t *integrity_requirements_create(
    int *time_to_alert,
    int *target_integrity_risk,
    alert_limit_t *alert_limit
);

void integrity_requirements_free(integrity_requirements_t *integrity_requirements);

integrity_requirements_t *integrity_requirements_parseFromJSON(cJSON *integrity_requirementsJSON);

cJSON *integrity_requirements_convertToJSON(integrity_requirements_t *integrity_requirements);

#endif /* _integrity_requirements_H_ */

