/*
 * lmf_data_exposure_subscription.h
 *
 * Describes subscription operation of LMF data exposure
 */

#ifndef _OpenAPI_lmf_data_exposure_subscription_H_
#define _OpenAPI_lmf_data_exposure_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "data_source_type.h"
#include "location_qo_s.h"
#include "presence_info.h"
#include "recur_time.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_lmf_data_exposure_subscription_s OpenAPI_lmf_data_exposure_subscription_t;
typedef struct OpenAPI_lmf_data_exposure_subscription_s {
    char *notification_uri;
    char *notify_correlation_id;
    struct OpenAPI_presence_info_s *aoi;
    struct OpenAPI_recur_time_s *recur_time;
    bool is_num_of_samples;
    int num_of_samples;
    OpenAPI_list_t *data_sources;
    struct OpenAPI_location_qo_s_s *quality_threshold;
    bool is_ml_model_id;
    int ml_model_id;
    char *expiry_time;
    bool is_pru_indication;
    int pru_indication;
} OpenAPI_lmf_data_exposure_subscription_t;

OpenAPI_lmf_data_exposure_subscription_t *OpenAPI_lmf_data_exposure_subscription_create(
    char *notification_uri,
    char *notify_correlation_id,
    OpenAPI_presence_info_t *aoi,
    OpenAPI_recur_time_t *recur_time,
    bool is_num_of_samples,
    int num_of_samples,
    OpenAPI_list_t *data_sources,
    OpenAPI_location_qo_s_t *quality_threshold,
    bool is_ml_model_id,
    int ml_model_id,
    char *expiry_time,
    bool is_pru_indication,
    int pru_indication
);
void OpenAPI_lmf_data_exposure_subscription_free(OpenAPI_lmf_data_exposure_subscription_t *lmf_data_exposure_subscription);
OpenAPI_lmf_data_exposure_subscription_t *OpenAPI_lmf_data_exposure_subscription_parseFromJSON(cJSON *lmf_data_exposure_subscriptionJSON);
cJSON *OpenAPI_lmf_data_exposure_subscription_convertToJSON(OpenAPI_lmf_data_exposure_subscription_t *lmf_data_exposure_subscription);
OpenAPI_lmf_data_exposure_subscription_t *OpenAPI_lmf_data_exposure_subscription_copy(OpenAPI_lmf_data_exposure_subscription_t *dst, OpenAPI_lmf_data_exposure_subscription_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_lmf_data_exposure_subscription_H_ */

