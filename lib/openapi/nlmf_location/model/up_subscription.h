/*
 * up_subscription.h
 *
 * UP Subscription
 */

#ifndef _up_subscription_H_
#define _up_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct up_subscription_t up_subscription_t;




typedef struct up_subscription_t {
    char *up_notify_call_back_uri; // string
    char *notif_correlation_id; // string
    char *supi; // string
    char *gpsi; // string

    int _library_owned; // Is the library responsible for freeing this object?
} up_subscription_t;

__attribute__((deprecated)) up_subscription_t *up_subscription_create(
    char *up_notify_call_back_uri,
    char *notif_correlation_id,
    char *supi,
    char *gpsi
);

void up_subscription_free(up_subscription_t *up_subscription);

up_subscription_t *up_subscription_parseFromJSON(cJSON *up_subscriptionJSON);

cJSON *up_subscription_convertToJSON(up_subscription_t *up_subscription);

#endif /* _up_subscription_H_ */

