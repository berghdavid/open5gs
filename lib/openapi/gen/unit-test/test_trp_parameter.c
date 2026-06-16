#ifndef trp_parameter_TEST
#define trp_parameter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define trp_parameter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/trp_parameter.h"
trp_parameter_t* instantiate_trp_parameter(int include_optional);

#include "test_global_ran_node_id.c"


trp_parameter_t* instantiate_trp_parameter(int include_optional) {
  trp_parameter_t* trp_parameter = NULL;
  if (include_optional) {
    trp_parameter = trp_parameter_create(
      list_createList(),
       // false, not to have infinite recursion
      instantiate_global_ran_node_id(0)
    );
  } else {
    trp_parameter = trp_parameter_create(
      list_createList(),
      NULL
    );
  }

  return trp_parameter;
}


#ifdef trp_parameter_MAIN

void test_trp_parameter(int include_optional) {
    trp_parameter_t* trp_parameter_1 = instantiate_trp_parameter(include_optional);

	cJSON* jsontrp_parameter_1 = trp_parameter_convertToJSON(trp_parameter_1);
	printf("trp_parameter :\n%s\n", cJSON_Print(jsontrp_parameter_1));
	trp_parameter_t* trp_parameter_2 = trp_parameter_parseFromJSON(jsontrp_parameter_1);
	cJSON* jsontrp_parameter_2 = trp_parameter_convertToJSON(trp_parameter_2);
	printf("repeating trp_parameter:\n%s\n", cJSON_Print(jsontrp_parameter_2));
}

int main() {
  test_trp_parameter(1);
  test_trp_parameter(0);

  printf("Hello world \n");
  return 0;
}

#endif // trp_parameter_MAIN
#endif // trp_parameter_TEST
