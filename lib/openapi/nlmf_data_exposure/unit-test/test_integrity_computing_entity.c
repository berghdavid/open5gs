#ifndef integrity_computing_entity_TEST
#define integrity_computing_entity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define integrity_computing_entity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/integrity_computing_entity.h"
integrity_computing_entity_t* instantiate_integrity_computing_entity(int include_optional);



integrity_computing_entity_t* instantiate_integrity_computing_entity(int include_optional) {
  integrity_computing_entity_t* integrity_computing_entity = NULL;
  if (include_optional) {
    integrity_computing_entity = integrity_computing_entity_create(
    );
  } else {
    integrity_computing_entity = integrity_computing_entity_create(
    );
  }

  return integrity_computing_entity;
}


#ifdef integrity_computing_entity_MAIN

void test_integrity_computing_entity(int include_optional) {
    integrity_computing_entity_t* integrity_computing_entity_1 = instantiate_integrity_computing_entity(include_optional);

	cJSON* jsonintegrity_computing_entity_1 = integrity_computing_entity_convertToJSON(integrity_computing_entity_1);
	printf("integrity_computing_entity :\n%s\n", cJSON_Print(jsonintegrity_computing_entity_1));
	integrity_computing_entity_t* integrity_computing_entity_2 = integrity_computing_entity_parseFromJSON(jsonintegrity_computing_entity_1);
	cJSON* jsonintegrity_computing_entity_2 = integrity_computing_entity_convertToJSON(integrity_computing_entity_2);
	printf("repeating integrity_computing_entity:\n%s\n", cJSON_Print(jsonintegrity_computing_entity_2));
}

int main() {
  test_integrity_computing_entity(1);
  test_integrity_computing_entity(0);

  printf("Hello world \n");
  return 0;
}

#endif // integrity_computing_entity_MAIN
#endif // integrity_computing_entity_TEST
