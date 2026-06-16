/*
 * lmf_data_exposure_notification.h
 *
 * Describes Notification for LMF data collection
 */

#ifndef _OpenAPI_lmf_data_exposure_notification_H_
#define _OpenAPI_lmf_data_exposure_notification_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "lmf_data_exposure_report.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_lmf_data_exposure_notification_s OpenAPI_lmf_data_exposure_notification_t;
typedef struct OpenAPI_lmf_data_exposure_notification_s {
    char *notify_correlation_id;
    OpenAPI_list_t *reports;
} OpenAPI_lmf_data_exposure_notification_t;

OpenAPI_lmf_data_exposure_notification_t *OpenAPI_lmf_data_exposure_notification_create(
    char *notify_correlation_id,
    OpenAPI_list_t *reports
);
void OpenAPI_lmf_data_exposure_notification_free(OpenAPI_lmf_data_exposure_notification_t *lmf_data_exposure_notification);
OpenAPI_lmf_data_exposure_notification_t *OpenAPI_lmf_data_exposure_notification_parseFromJSON(cJSON *lmf_data_exposure_notificationJSON);
cJSON *OpenAPI_lmf_data_exposure_notification_convertToJSON(OpenAPI_lmf_data_exposure_notification_t *lmf_data_exposure_notification);
OpenAPI_lmf_data_exposure_notification_t *OpenAPI_lmf_data_exposure_notification_copy(OpenAPI_lmf_data_exposure_notification_t *dst, OpenAPI_lmf_data_exposure_notification_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_lmf_data_exposure_notification_H_ */

