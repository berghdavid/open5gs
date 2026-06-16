#ifndef determine_location_request_TEST
#define determine_location_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define determine_location_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/determine_location_request.h"
determine_location_request_t* instantiate_determine_location_request(int include_optional);

#include "test_input_data.c"


determine_location_request_t* instantiate_determine_location_request(int include_optional) {
  determine_location_request_t* determine_location_request = NULL;
  if (include_optional) {
    determine_location_request = determine_location_request_create(
       // false, not to have infinite recursion
      instantiate_input_data(0),
      instantiate_binary_t("blah", 5)
    );
  } else {
    determine_location_request = determine_location_request_create(
      NULL,
      instantiate_binary_t("blah", 5)
    );
  }

  return determine_location_request;
}


#ifdef determine_location_request_MAIN

void test_determine_location_request(int include_optional) {
    determine_location_request_t* determine_location_request_1 = instantiate_determine_location_request(include_optional);

	cJSON* jsondetermine_location_request_1 = determine_location_request_convertToJSON(determine_location_request_1);
	printf("determine_location_request :\n%s\n", cJSON_Print(jsondetermine_location_request_1));
	determine_location_request_t* determine_location_request_2 = determine_location_request_parseFromJSON(jsondetermine_location_request_1);
	cJSON* jsondetermine_location_request_2 = determine_location_request_convertToJSON(determine_location_request_2);
	printf("repeating determine_location_request:\n%s\n", cJSON_Print(jsondetermine_location_request_2));
}

int main() {
  test_determine_location_request(1);
  test_determine_location_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // determine_location_request_MAIN
#endif // determine_location_request_TEST
