#ifndef lmf_data_exposure_report_TEST
#define lmf_data_exposure_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define lmf_data_exposure_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/lmf_data_exposure_report.h"
lmf_data_exposure_report_t* instantiate_lmf_data_exposure_report(int include_optional);

#include "test_lmf_data_exposure_cause.c"


lmf_data_exposure_report_t* instantiate_lmf_data_exposure_report(int include_optional) {
  lmf_data_exposure_report_t* lmf_data_exposure_report = NULL;
  if (include_optional) {
    lmf_data_exposure_report = lmf_data_exposure_report_create(
      list_createList(),
      0,
      null
    );
  } else {
    lmf_data_exposure_report = lmf_data_exposure_report_create(
      list_createList(),
      0,
      null
    );
  }

  return lmf_data_exposure_report;
}


#ifdef lmf_data_exposure_report_MAIN

void test_lmf_data_exposure_report(int include_optional) {
    lmf_data_exposure_report_t* lmf_data_exposure_report_1 = instantiate_lmf_data_exposure_report(include_optional);

	cJSON* jsonlmf_data_exposure_report_1 = lmf_data_exposure_report_convertToJSON(lmf_data_exposure_report_1);
	printf("lmf_data_exposure_report :\n%s\n", cJSON_Print(jsonlmf_data_exposure_report_1));
	lmf_data_exposure_report_t* lmf_data_exposure_report_2 = lmf_data_exposure_report_parseFromJSON(jsonlmf_data_exposure_report_1);
	cJSON* jsonlmf_data_exposure_report_2 = lmf_data_exposure_report_convertToJSON(lmf_data_exposure_report_2);
	printf("repeating lmf_data_exposure_report:\n%s\n", cJSON_Print(jsonlmf_data_exposure_report_2));
}

int main() {
  test_lmf_data_exposure_report(1);
  test_lmf_data_exposure_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // lmf_data_exposure_report_MAIN
#endif // lmf_data_exposure_report_TEST
