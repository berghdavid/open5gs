#ifndef relative_velocity_with_uncertainty_TEST
#define relative_velocity_with_uncertainty_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define relative_velocity_with_uncertainty_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/relative_velocity_with_uncertainty.h"
relative_velocity_with_uncertainty_t* instantiate_relative_velocity_with_uncertainty(int include_optional);

#include "test_radial_velocity.c"
#include "test_angular_velocity.c"
#include "test_angular_velocity.c"


relative_velocity_with_uncertainty_t* instantiate_relative_velocity_with_uncertainty(int include_optional) {
  relative_velocity_with_uncertainty_t* relative_velocity_with_uncertainty = NULL;
  if (include_optional) {
    relative_velocity_with_uncertainty = relative_velocity_with_uncertainty_create(
       // false, not to have infinite recursion
      instantiate_radial_velocity(0),
       // false, not to have infinite recursion
      instantiate_angular_velocity(0),
       // false, not to have infinite recursion
      instantiate_angular_velocity(0)
    );
  } else {
    relative_velocity_with_uncertainty = relative_velocity_with_uncertainty_create(
      NULL,
      NULL,
      NULL
    );
  }

  return relative_velocity_with_uncertainty;
}


#ifdef relative_velocity_with_uncertainty_MAIN

void test_relative_velocity_with_uncertainty(int include_optional) {
    relative_velocity_with_uncertainty_t* relative_velocity_with_uncertainty_1 = instantiate_relative_velocity_with_uncertainty(include_optional);

	cJSON* jsonrelative_velocity_with_uncertainty_1 = relative_velocity_with_uncertainty_convertToJSON(relative_velocity_with_uncertainty_1);
	printf("relative_velocity_with_uncertainty :\n%s\n", cJSON_Print(jsonrelative_velocity_with_uncertainty_1));
	relative_velocity_with_uncertainty_t* relative_velocity_with_uncertainty_2 = relative_velocity_with_uncertainty_parseFromJSON(jsonrelative_velocity_with_uncertainty_1);
	cJSON* jsonrelative_velocity_with_uncertainty_2 = relative_velocity_with_uncertainty_convertToJSON(relative_velocity_with_uncertainty_2);
	printf("repeating relative_velocity_with_uncertainty:\n%s\n", cJSON_Print(jsonrelative_velocity_with_uncertainty_2));
}

int main() {
  test_relative_velocity_with_uncertainty(1);
  test_relative_velocity_with_uncertainty(0);

  printf("Hello world \n");
  return 0;
}

#endif // relative_velocity_with_uncertainty_MAIN
#endif // relative_velocity_with_uncertainty_TEST
