/*
 * recur_time.h
 *
 * Contains the recurring time period
 */

#ifndef _recur_time_H_
#define _recur_time_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct recur_time_t recur_time_t;

#include "recur_type.h"
#include "valid_time_period.h"



typedef struct recur_time_t {
    struct valid_time_period_t *recur_time_window; //model
    struct recur_type_t *recur_type; //model
    list_t *recur_month; //primitive container
    list_t *recur_week; //primitive container
    list_t *recur_day; //primitive container
    list_t *recur_date; //primitive container
    char *recur_end_time; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} recur_time_t;

__attribute__((deprecated)) recur_time_t *recur_time_create(
    valid_time_period_t *recur_time_window,
    recur_type_t *recur_type,
    list_t *recur_month,
    list_t *recur_week,
    list_t *recur_day,
    list_t *recur_date,
    char *recur_end_time
);

void recur_time_free(recur_time_t *recur_time);

recur_time_t *recur_time_parseFromJSON(cJSON *recur_timeJSON);

cJSON *recur_time_convertToJSON(recur_time_t *recur_time);

#endif /* _recur_time_H_ */

