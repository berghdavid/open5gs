#ifndef units_linear_velocity_TEST
#define units_linear_velocity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define units_linear_velocity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/units_linear_velocity.h"
units_linear_velocity_t* instantiate_units_linear_velocity(int include_optional);



units_linear_velocity_t* instantiate_units_linear_velocity(int include_optional) {
  units_linear_velocity_t* units_linear_velocity = NULL;
  if (include_optional) {
    units_linear_velocity = units_linear_velocity_create(
    );
  } else {
    units_linear_velocity = units_linear_velocity_create(
    );
  }

  return units_linear_velocity;
}


#ifdef units_linear_velocity_MAIN

void test_units_linear_velocity(int include_optional) {
    units_linear_velocity_t* units_linear_velocity_1 = instantiate_units_linear_velocity(include_optional);

	cJSON* jsonunits_linear_velocity_1 = units_linear_velocity_convertToJSON(units_linear_velocity_1);
	printf("units_linear_velocity :\n%s\n", cJSON_Print(jsonunits_linear_velocity_1));
	units_linear_velocity_t* units_linear_velocity_2 = units_linear_velocity_parseFromJSON(jsonunits_linear_velocity_1);
	cJSON* jsonunits_linear_velocity_2 = units_linear_velocity_convertToJSON(units_linear_velocity_2);
	printf("repeating units_linear_velocity:\n%s\n", cJSON_Print(jsonunits_linear_velocity_2));
}

int main() {
  test_units_linear_velocity(1);
  test_units_linear_velocity(0);

  printf("Hello world \n");
  return 0;
}

#endif // units_linear_velocity_MAIN
#endif // units_linear_velocity_TEST
