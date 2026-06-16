/*
 * event_reporting_status.h
 *
 * Indicates the status of event reporting.
 */

#ifndef _event_reporting_status_H_
#define _event_reporting_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct event_reporting_status_t event_reporting_status_t;




typedef struct event_reporting_status_t {
    int *event_report_counter; //numeric
    int *event_report_duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} event_reporting_status_t;

__attribute__((deprecated)) event_reporting_status_t *event_reporting_status_create(
    int *event_report_counter,
    int *event_report_duration
);

void event_reporting_status_free(event_reporting_status_t *event_reporting_status);

event_reporting_status_t *event_reporting_status_parseFromJSON(cJSON *event_reporting_statusJSON);

cJSON *event_reporting_status_convertToJSON(event_reporting_status_t *event_reporting_status);

#endif /* _event_reporting_status_H_ */

