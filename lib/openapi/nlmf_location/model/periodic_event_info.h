/*
 * periodic_event_info.h
 *
 * Indicates the information of periodic event reporting.
 */

#ifndef _periodic_event_info_H_
#define _periodic_event_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct periodic_event_info_t periodic_event_info_t;




typedef struct periodic_event_info_t {
    int *reporting_amount; //numeric
    int *reporting_interval; //numeric
    int *reporting_infinite_ind; //boolean
    int *reporting_interval_ms; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} periodic_event_info_t;

__attribute__((deprecated)) periodic_event_info_t *periodic_event_info_create(
    int *reporting_amount,
    int *reporting_interval,
    int *reporting_infinite_ind,
    int *reporting_interval_ms
);

void periodic_event_info_free(periodic_event_info_t *periodic_event_info);

periodic_event_info_t *periodic_event_info_parseFromJSON(cJSON *periodic_event_infoJSON);

cJSON *periodic_event_info_convertToJSON(periodic_event_info_t *periodic_event_info);

#endif /* _periodic_event_info_H_ */

