#ifndef sl_positioning_capability_TEST
#define sl_positioning_capability_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sl_positioning_capability_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sl_positioning_capability.h"
sl_positioning_capability_t* instantiate_sl_positioning_capability(int include_optional);



sl_positioning_capability_t* instantiate_sl_positioning_capability(int include_optional) {
  sl_positioning_capability_t* sl_positioning_capability = NULL;
  if (include_optional) {
    sl_positioning_capability = sl_positioning_capability_create(
    );
  } else {
    sl_positioning_capability = sl_positioning_capability_create(
    );
  }

  return sl_positioning_capability;
}


#ifdef sl_positioning_capability_MAIN

void test_sl_positioning_capability(int include_optional) {
    sl_positioning_capability_t* sl_positioning_capability_1 = instantiate_sl_positioning_capability(include_optional);

	cJSON* jsonsl_positioning_capability_1 = sl_positioning_capability_convertToJSON(sl_positioning_capability_1);
	printf("sl_positioning_capability :\n%s\n", cJSON_Print(jsonsl_positioning_capability_1));
	sl_positioning_capability_t* sl_positioning_capability_2 = sl_positioning_capability_parseFromJSON(jsonsl_positioning_capability_1);
	cJSON* jsonsl_positioning_capability_2 = sl_positioning_capability_convertToJSON(sl_positioning_capability_2);
	printf("repeating sl_positioning_capability:\n%s\n", cJSON_Print(jsonsl_positioning_capability_2));
}

int main() {
  test_sl_positioning_capability(1);
  test_sl_positioning_capability(0);

  printf("Hello world \n");
  return 0;
}

#endif // sl_positioning_capability_MAIN
#endif // sl_positioning_capability_TEST
