#ifndef lmf_data_exposure_subscription_TEST
#define lmf_data_exposure_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lmf_data_exposure_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lmf_data_exposure_subscription.h"
lmf_data_exposure_subscription_t* instantiate_lmf_data_exposure_subscription(int include_optional);

#include "test_presence_info.c"
#include "test_recur_time.c"
#include "test_location_qo_s.c"


lmf_data_exposure_subscription_t* instantiate_lmf_data_exposure_subscription(int include_optional) {
  lmf_data_exposure_subscription_t* lmf_data_exposure_subscription = NULL;
  if (include_optional) {
    lmf_data_exposure_subscription = lmf_data_exposure_subscription_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_presence_info(0),
       // false, not to have infinite recursion
      instantiate_recur_time(0),
      0,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_location_qo_s(0),
      0,
      "2013-10-20T19:20:30+01:00",
      1
    );
  } else {
    lmf_data_exposure_subscription = lmf_data_exposure_subscription_create(
      "0",
      "0",
      NULL,
      NULL,
      0,
      list_createList(),
      NULL,
      0,
      "2013-10-20T19:20:30+01:00",
      1
    );
  }

  return lmf_data_exposure_subscription;
}


#ifdef lmf_data_exposure_subscription_MAIN

void test_lmf_data_exposure_subscription(int include_optional) {
    lmf_data_exposure_subscription_t* lmf_data_exposure_subscription_1 = instantiate_lmf_data_exposure_subscription(include_optional);

	cJSON* jsonlmf_data_exposure_subscription_1 = lmf_data_exposure_subscription_convertToJSON(lmf_data_exposure_subscription_1);
	printf("lmf_data_exposure_subscription :\n%s\n", cJSON_Print(jsonlmf_data_exposure_subscription_1));
	lmf_data_exposure_subscription_t* lmf_data_exposure_subscription_2 = lmf_data_exposure_subscription_parseFromJSON(jsonlmf_data_exposure_subscription_1);
	cJSON* jsonlmf_data_exposure_subscription_2 = lmf_data_exposure_subscription_convertToJSON(lmf_data_exposure_subscription_2);
	printf("repeating lmf_data_exposure_subscription:\n%s\n", cJSON_Print(jsonlmf_data_exposure_subscription_2));
}

int main() {
  test_lmf_data_exposure_subscription(1);
  test_lmf_data_exposure_subscription(0);

  printf("Hello world \n");
  return 0;
}

#endif // lmf_data_exposure_subscription_MAIN
#endif // lmf_data_exposure_subscription_TEST
