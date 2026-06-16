#ifndef lmf_data_exposure_notification_TEST
#define lmf_data_exposure_notification_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lmf_data_exposure_notification_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lmf_data_exposure_notification.h"
lmf_data_exposure_notification_t* instantiate_lmf_data_exposure_notification(int include_optional);



lmf_data_exposure_notification_t* instantiate_lmf_data_exposure_notification(int include_optional) {
  lmf_data_exposure_notification_t* lmf_data_exposure_notification = NULL;
  if (include_optional) {
    lmf_data_exposure_notification = lmf_data_exposure_notification_create(
      "0",
      list_createList()
    );
  } else {
    lmf_data_exposure_notification = lmf_data_exposure_notification_create(
      "0",
      list_createList()
    );
  }

  return lmf_data_exposure_notification;
}


#ifdef lmf_data_exposure_notification_MAIN

void test_lmf_data_exposure_notification(int include_optional) {
    lmf_data_exposure_notification_t* lmf_data_exposure_notification_1 = instantiate_lmf_data_exposure_notification(include_optional);

	cJSON* jsonlmf_data_exposure_notification_1 = lmf_data_exposure_notification_convertToJSON(lmf_data_exposure_notification_1);
	printf("lmf_data_exposure_notification :\n%s\n", cJSON_Print(jsonlmf_data_exposure_notification_1));
	lmf_data_exposure_notification_t* lmf_data_exposure_notification_2 = lmf_data_exposure_notification_parseFromJSON(jsonlmf_data_exposure_notification_1);
	cJSON* jsonlmf_data_exposure_notification_2 = lmf_data_exposure_notification_convertToJSON(lmf_data_exposure_notification_2);
	printf("repeating lmf_data_exposure_notification:\n%s\n", cJSON_Print(jsonlmf_data_exposure_notification_2));
}

int main() {
  test_lmf_data_exposure_notification(1);
  test_lmf_data_exposure_notification(0);

  printf("Hello world \n");
  return 0;
}

#endif // lmf_data_exposure_notification_MAIN
#endif // lmf_data_exposure_notification_TEST
