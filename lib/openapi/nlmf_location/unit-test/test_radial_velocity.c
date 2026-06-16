#ifndef radial_velocity_TEST
#define radial_velocity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define radial_velocity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/radial_velocity.h"
radial_velocity_t* instantiate_radial_velocity(int include_optional);

#include "test_units_linear_velocity.c"


radial_velocity_t* instantiate_radial_velocity(int include_optional) {
  radial_velocity_t* radial_velocity = NULL;
  if (include_optional) {
    radial_velocity = radial_velocity_create(
      null,
      -2048,
      0
    );
  } else {
    radial_velocity = radial_velocity_create(
      null,
      -2048,
      0
    );
  }

  return radial_velocity;
}


#ifdef radial_velocity_MAIN

void test_radial_velocity(int include_optional) {
    radial_velocity_t* radial_velocity_1 = instantiate_radial_velocity(include_optional);

	cJSON* jsonradial_velocity_1 = radial_velocity_convertToJSON(radial_velocity_1);
	printf("radial_velocity :\n%s\n", cJSON_Print(jsonradial_velocity_1));
	radial_velocity_t* radial_velocity_2 = radial_velocity_parseFromJSON(jsonradial_velocity_1);
	cJSON* jsonradial_velocity_2 = radial_velocity_convertToJSON(radial_velocity_2);
	printf("repeating radial_velocity:\n%s\n", cJSON_Print(jsonradial_velocity_2));
}

int main() {
  test_radial_velocity(1);
  test_radial_velocity(0);

  printf("Hello world \n");
  return 0;
}

#endif // radial_velocity_MAIN
#endif // radial_velocity_TEST
