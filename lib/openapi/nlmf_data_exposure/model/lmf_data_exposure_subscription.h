/*
 * lmf_data_exposure_subscription.h
 *
 * Describes subscription operation of LMF data exposure
 */

#ifndef _lmf_data_exposure_subscription_H_
#define _lmf_data_exposure_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lmf_data_exposure_subscription_t lmf_data_exposure_subscription_t;

#include "data_source_type.h"
#include "location_qo_s.h"
#include "presence_info.h"
#include "recur_time.h"



typedef struct lmf_data_exposure_subscription_t {
    char *notification_uri; // string
    char *notify_correlation_id; // string
    struct presence_info_t *aoi; //model
    struct recur_time_t *recur_time; //model
    int *num_of_samples; //numeric
    list_t *data_sources; //nonprimitive container
    struct location_qo_s_t *quality_threshold; //model
    int *ml_model_id; //numeric
    char *expiry_time; //date time
    int *pru_indication; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} lmf_data_exposure_subscription_t;

__attribute__((deprecated)) lmf_data_exposure_subscription_t *lmf_data_exposure_subscription_create(
    char *notification_uri,
    char *notify_correlation_id,
    presence_info_t *aoi,
    recur_time_t *recur_time,
    int *num_of_samples,
    list_t *data_sources,
    location_qo_s_t *quality_threshold,
    int *ml_model_id,
    char *expiry_time,
    int *pru_indication
);

void lmf_data_exposure_subscription_free(lmf_data_exposure_subscription_t *lmf_data_exposure_subscription);

lmf_data_exposure_subscription_t *lmf_data_exposure_subscription_parseFromJSON(cJSON *lmf_data_exposure_subscriptionJSON);

cJSON *lmf_data_exposure_subscription_convertToJSON(lmf_data_exposure_subscription_t *lmf_data_exposure_subscription);

#endif /* _lmf_data_exposure_subscription_H_ */

