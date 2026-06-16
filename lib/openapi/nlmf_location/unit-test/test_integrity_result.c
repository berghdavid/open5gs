#ifndef integrity_result_TEST
#define integrity_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define integrity_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/integrity_result.h"
integrity_result_t* instantiate_integrity_result(int include_optional);

#include "test_integrity_computing_entity.c"
#include "test_integrity_protection_level.c"


integrity_result_t* instantiate_integrity_result(int include_optional) {
  integrity_result_t* integrity_result = NULL;
  if (include_optional) {
    integrity_result = integrity_result_create(
      null,
       // false, not to have infinite recursion
      instantiate_integrity_protection_level(0),
      1,
      10
    );
  } else {
    integrity_result = integrity_result_create(
      null,
      NULL,
      1,
      10
    );
  }

  return integrity_result;
}


#ifdef integrity_result_MAIN

void test_integrity_result(int include_optional) {
    integrity_result_t* integrity_result_1 = instantiate_integrity_result(include_optional);

	cJSON* jsonintegrity_result_1 = integrity_result_convertToJSON(integrity_result_1);
	printf("integrity_result :\n%s\n", cJSON_Print(jsonintegrity_result_1));
	integrity_result_t* integrity_result_2 = integrity_result_parseFromJSON(jsonintegrity_result_1);
	cJSON* jsonintegrity_result_2 = integrity_result_convertToJSON(integrity_result_2);
	printf("repeating integrity_result:\n%s\n", cJSON_Print(jsonintegrity_result_2));
}

int main() {
  test_integrity_result(1);
  test_integrity_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // integrity_result_MAIN
#endif // integrity_result_TEST
