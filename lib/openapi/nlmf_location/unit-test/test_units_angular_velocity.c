#ifndef units_angular_velocity_TEST
#define units_angular_velocity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define units_angular_velocity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/units_angular_velocity.h"
units_angular_velocity_t* instantiate_units_angular_velocity(int include_optional);



units_angular_velocity_t* instantiate_units_angular_velocity(int include_optional) {
  units_angular_velocity_t* units_angular_velocity = NULL;
  if (include_optional) {
    units_angular_velocity = units_angular_velocity_create(
    );
  } else {
    units_angular_velocity = units_angular_velocity_create(
    );
  }

  return units_angular_velocity;
}


#ifdef units_angular_velocity_MAIN

void test_units_angular_velocity(int include_optional) {
    units_angular_velocity_t* units_angular_velocity_1 = instantiate_units_angular_velocity(include_optional);

	cJSON* jsonunits_angular_velocity_1 = units_angular_velocity_convertToJSON(units_angular_velocity_1);
	printf("units_angular_velocity :\n%s\n", cJSON_Print(jsonunits_angular_velocity_1));
	units_angular_velocity_t* units_angular_velocity_2 = units_angular_velocity_parseFromJSON(jsonunits_angular_velocity_1);
	cJSON* jsonunits_angular_velocity_2 = units_angular_velocity_convertToJSON(units_angular_velocity_2);
	printf("repeating units_angular_velocity:\n%s\n", cJSON_Print(jsonunits_angular_velocity_2));
}

int main() {
  test_units_angular_velocity(1);
  test_units_angular_velocity(0);

  printf("Hello world \n");
  return 0;
}

#endif // units_angular_velocity_MAIN
#endif // units_angular_velocity_TEST
