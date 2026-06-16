/*
 * valid_time_period.h
 *
 * Contains the validity time period
 */

#ifndef _valid_time_period_H_
#define _valid_time_period_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct valid_time_period_t valid_time_period_t;




typedef struct valid_time_period_t {
    char *start_time; //date time
    char *end_time; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} valid_time_period_t;

__attribute__((deprecated)) valid_time_period_t *valid_time_period_create(
    char *start_time,
    char *end_time
);

void valid_time_period_free(valid_time_period_t *valid_time_period);

valid_time_period_t *valid_time_period_parseFromJSON(cJSON *valid_time_periodJSON);

cJSON *valid_time_period_convertToJSON(valid_time_period_t *valid_time_period);

#endif /* _valid_time_period_H_ */

