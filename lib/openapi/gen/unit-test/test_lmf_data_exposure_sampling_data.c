#ifndef lmf_data_exposure_sampling_data_TEST
#define lmf_data_exposure_sampling_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lmf_data_exposure_sampling_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lmf_data_exposure_sampling_data.h"
lmf_data_exposure_sampling_data_t* instantiate_lmf_data_exposure_sampling_data(int include_optional);

#include "test_loc_measurements.c"
#include "test_location_data.c"
#include "test_location_data.c"


lmf_data_exposure_sampling_data_t* instantiate_lmf_data_exposure_sampling_data(int include_optional) {
  lmf_data_exposure_sampling_data_t* lmf_data_exposure_sampling_data = NULL;
  if (include_optional) {
    lmf_data_exposure_sampling_data = lmf_data_exposure_sampling_data_create(
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_loc_measurements(0),
       // false, not to have infinite recursion
      instantiate_location_data(0),
      0,
       // false, not to have infinite recursion
      instantiate_location_data(0)
    );
  } else {
    lmf_data_exposure_sampling_data = lmf_data_exposure_sampling_data_create(
      "2013-10-20T19:20:30+01:00",
      NULL,
      NULL,
      0,
      NULL
    );
  }

  return lmf_data_exposure_sampling_data;
}


#ifdef lmf_data_exposure_sampling_data_MAIN

void test_lmf_data_exposure_sampling_data(int include_optional) {
    lmf_data_exposure_sampling_data_t* lmf_data_exposure_sampling_data_1 = instantiate_lmf_data_exposure_sampling_data(include_optional);

	cJSON* jsonlmf_data_exposure_sampling_data_1 = lmf_data_exposure_sampling_data_convertToJSON(lmf_data_exposure_sampling_data_1);
	printf("lmf_data_exposure_sampling_data :\n%s\n", cJSON_Print(jsonlmf_data_exposure_sampling_data_1));
	lmf_data_exposure_sampling_data_t* lmf_data_exposure_sampling_data_2 = lmf_data_exposure_sampling_data_parseFromJSON(jsonlmf_data_exposure_sampling_data_1);
	cJSON* jsonlmf_data_exposure_sampling_data_2 = lmf_data_exposure_sampling_data_convertToJSON(lmf_data_exposure_sampling_data_2);
	printf("repeating lmf_data_exposure_sampling_data:\n%s\n", cJSON_Print(jsonlmf_data_exposure_sampling_data_2));
}

int main() {
  test_lmf_data_exposure_sampling_data(1);
  test_lmf_data_exposure_sampling_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // lmf_data_exposure_sampling_data_MAIN
#endif // lmf_data_exposure_sampling_data_TEST
