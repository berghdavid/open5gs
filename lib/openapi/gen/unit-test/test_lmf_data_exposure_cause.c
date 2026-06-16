#ifndef lmf_data_exposure_cause_TEST
#define lmf_data_exposure_cause_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lmf_data_exposure_cause_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lmf_data_exposure_cause.h"
lmf_data_exposure_cause_t* instantiate_lmf_data_exposure_cause(int include_optional);



lmf_data_exposure_cause_t* instantiate_lmf_data_exposure_cause(int include_optional) {
  lmf_data_exposure_cause_t* lmf_data_exposure_cause = NULL;
  if (include_optional) {
    lmf_data_exposure_cause = lmf_data_exposure_cause_create(
    );
  } else {
    lmf_data_exposure_cause = lmf_data_exposure_cause_create(
    );
  }

  return lmf_data_exposure_cause;
}


#ifdef lmf_data_exposure_cause_MAIN

void test_lmf_data_exposure_cause(int include_optional) {
    lmf_data_exposure_cause_t* lmf_data_exposure_cause_1 = instantiate_lmf_data_exposure_cause(include_optional);

	cJSON* jsonlmf_data_exposure_cause_1 = lmf_data_exposure_cause_convertToJSON(lmf_data_exposure_cause_1);
	printf("lmf_data_exposure_cause :\n%s\n", cJSON_Print(jsonlmf_data_exposure_cause_1));
	lmf_data_exposure_cause_t* lmf_data_exposure_cause_2 = lmf_data_exposure_cause_parseFromJSON(jsonlmf_data_exposure_cause_1);
	cJSON* jsonlmf_data_exposure_cause_2 = lmf_data_exposure_cause_convertToJSON(lmf_data_exposure_cause_2);
	printf("repeating lmf_data_exposure_cause:\n%s\n", cJSON_Print(jsonlmf_data_exposure_cause_2));
}

int main() {
  test_lmf_data_exposure_cause(1);
  test_lmf_data_exposure_cause(0);

  printf("Hello world \n");
  return 0;
}

#endif // lmf_data_exposure_cause_MAIN
#endif // lmf_data_exposure_cause_TEST
