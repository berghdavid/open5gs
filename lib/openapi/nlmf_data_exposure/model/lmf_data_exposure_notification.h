/*
 * lmf_data_exposure_notification.h
 *
 * Describes Notification for LMF data collection
 */

#ifndef _lmf_data_exposure_notification_H_
#define _lmf_data_exposure_notification_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lmf_data_exposure_notification_t lmf_data_exposure_notification_t;

#include "lmf_data_exposure_report.h"



typedef struct lmf_data_exposure_notification_t {
    char *notify_correlation_id; // string
    list_t *reports; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} lmf_data_exposure_notification_t;

__attribute__((deprecated)) lmf_data_exposure_notification_t *lmf_data_exposure_notification_create(
    char *notify_correlation_id,
    list_t *reports
);

void lmf_data_exposure_notification_free(lmf_data_exposure_notification_t *lmf_data_exposure_notification);

lmf_data_exposure_notification_t *lmf_data_exposure_notification_parseFromJSON(cJSON *lmf_data_exposure_notificationJSON);

cJSON *lmf_data_exposure_notification_convertToJSON(lmf_data_exposure_notification_t *lmf_data_exposure_notification);

#endif /* _lmf_data_exposure_notification_H_ */

