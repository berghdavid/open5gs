#ifndef angular_velocity_TEST
#define angular_velocity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define angular_velocity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/angular_velocity.h"
angular_velocity_t* instantiate_angular_velocity(int include_optional);

#include "test_units_angular_velocity.c"


angular_velocity_t* instantiate_angular_velocity(int include_optional) {
  angular_velocity_t* angular_velocity = NULL;
  if (include_optional) {
    angular_velocity = angular_velocity_create(
      null,
      -1024,
      0
    );
  } else {
    angular_velocity = angular_velocity_create(
      null,
      -1024,
      0
    );
  }

  return angular_velocity;
}


#ifdef angular_velocity_MAIN

void test_angular_velocity(int include_optional) {
    angular_velocity_t* angular_velocity_1 = instantiate_angular_velocity(include_optional);

	cJSON* jsonangular_velocity_1 = angular_velocity_convertToJSON(angular_velocity_1);
	printf("angular_velocity :\n%s\n", cJSON_Print(jsonangular_velocity_1));
	angular_velocity_t* angular_velocity_2 = angular_velocity_parseFromJSON(jsonangular_velocity_1);
	cJSON* jsonangular_velocity_2 = angular_velocity_convertToJSON(angular_velocity_2);
	printf("repeating angular_velocity:\n%s\n", cJSON_Print(jsonangular_velocity_2));
}

int main() {
  test_angular_velocity(1);
  test_angular_velocity(0);

  printf("Hello world \n");
  return 0;
}

#endif // angular_velocity_MAIN
#endif // angular_velocity_TEST
