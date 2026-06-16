/*
 * up_notify_data.h
 *
 * UP Subscription
 */

#ifndef _up_notify_data_H_
#define _up_notify_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct up_notify_data_t up_notify_data_t;

#include "up_connection_status.h"



typedef struct up_notify_data_t {
    char *notif_correlation_id; // string
    struct up_connection_status_t *up_connection_status; //model
    char *target_lmfid; // string

    int _library_owned; // Is the library responsible for freeing this object?
} up_notify_data_t;

__attribute__((deprecated)) up_notify_data_t *up_notify_data_create(
    char *notif_correlation_id,
    up_connection_status_t *up_connection_status,
    char *target_lmfid
);

void up_notify_data_free(up_notify_data_t *up_notify_data);

up_notify_data_t *up_notify_data_parseFromJSON(cJSON *up_notify_dataJSON);

cJSON *up_notify_data_convertToJSON(up_notify_data_t *up_notify_data);

#endif /* _up_notify_data_H_ */

