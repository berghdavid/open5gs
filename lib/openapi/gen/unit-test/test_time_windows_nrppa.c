#ifndef time_windows_nrppa_TEST
#define time_windows_nrppa_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define time_windows_nrppa_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/time_windows_nrppa.h"
time_windows_nrppa_t* instantiate_time_windows_nrppa(int include_optional);



time_windows_nrppa_t* instantiate_time_windows_nrppa(int include_optional) {
  time_windows_nrppa_t* time_windows_nrppa = NULL;
  if (include_optional) {
    time_windows_nrppa = time_windows_nrppa_create(
      "YQ==",
      "YQ=="
    );
  } else {
    time_windows_nrppa = time_windows_nrppa_create(
      "YQ==",
      "YQ=="
    );
  }

  return time_windows_nrppa;
}


#ifdef time_windows_nrppa_MAIN

void test_time_windows_nrppa(int include_optional) {
    time_windows_nrppa_t* time_windows_nrppa_1 = instantiate_time_windows_nrppa(include_optional);

	cJSON* jsontime_windows_nrppa_1 = time_windows_nrppa_convertToJSON(time_windows_nrppa_1);
	printf("time_windows_nrppa :\n%s\n", cJSON_Print(jsontime_windows_nrppa_1));
	time_windows_nrppa_t* time_windows_nrppa_2 = time_windows_nrppa_parseFromJSON(jsontime_windows_nrppa_1);
	cJSON* jsontime_windows_nrppa_2 = time_windows_nrppa_convertToJSON(time_windows_nrppa_2);
	printf("repeating time_windows_nrppa:\n%s\n", cJSON_Print(jsontime_windows_nrppa_2));
}

int main() {
  test_time_windows_nrppa(1);
  test_time_windows_nrppa(0);

  printf("Hello world \n");
  return 0;
}

#endif // time_windows_nrppa_MAIN
#endif // time_windows_nrppa_TEST
