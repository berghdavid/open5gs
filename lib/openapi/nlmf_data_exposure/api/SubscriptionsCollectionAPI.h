#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/lmf_data_exposure_subscription.h"
#include "../model/problem_details.h"
#include "../model/redirect_response.h"


// Nlmf_Data Exposure Subscribe Service Operation
//
lmf_data_exposure_subscription_t*
SubscriptionsCollectionAPI_createSubscription(apiClient_t *apiClient, lmf_data_exposure_subscription_t *lmf_data_exposure_subscription);


