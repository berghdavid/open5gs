#ifndef integrity_protection_level_TEST
#define integrity_protection_level_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define integrity_protection_level_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/integrity_protection_level.h"
integrity_protection_level_t* instantiate_integrity_protection_level(int include_optional);



integrity_protection_level_t* instantiate_integrity_protection_level(int include_optional) {
  integrity_protection_level_t* integrity_protection_level = NULL;
  if (include_optional) {
    integrity_protection_level = integrity_protection_level_create(
      0,
      0
    );
  } else {
    integrity_protection_level = integrity_protection_level_create(
      0,
      0
    );
  }

  return integrity_protection_level;
}


#ifdef integrity_protection_level_MAIN

void test_integrity_protection_level(int include_optional) {
    integrity_protection_level_t* integrity_protection_level_1 = instantiate_integrity_protection_level(include_optional);

	cJSON* jsonintegrity_protection_level_1 = integrity_protection_level_convertToJSON(integrity_protection_level_1);
	printf("integrity_protection_level :\n%s\n", cJSON_Print(jsonintegrity_protection_level_1));
	integrity_protection_level_t* integrity_protection_level_2 = integrity_protection_level_parseFromJSON(jsonintegrity_protection_level_1);
	cJSON* jsonintegrity_protection_level_2 = integrity_protection_level_convertToJSON(integrity_protection_level_2);
	printf("repeating integrity_protection_level:\n%s\n", cJSON_Print(jsonintegrity_protection_level_2));
}

int main() {
  test_integrity_protection_level(1);
  test_integrity_protection_level(0);

  printf("Hello world \n");
  return 0;
}

#endif // integrity_protection_level_MAIN
#endif // integrity_protection_level_TEST
