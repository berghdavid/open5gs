#ifndef data_source_type_TEST
#define data_source_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define data_source_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/data_source_type.h"
data_source_type_t* instantiate_data_source_type(int include_optional);



data_source_type_t* instantiate_data_source_type(int include_optional) {
  data_source_type_t* data_source_type = NULL;
  if (include_optional) {
    data_source_type = data_source_type_create(
    );
  } else {
    data_source_type = data_source_type_create(
    );
  }

  return data_source_type;
}


#ifdef data_source_type_MAIN

void test_data_source_type(int include_optional) {
    data_source_type_t* data_source_type_1 = instantiate_data_source_type(include_optional);

	cJSON* jsondata_source_type_1 = data_source_type_convertToJSON(data_source_type_1);
	printf("data_source_type :\n%s\n", cJSON_Print(jsondata_source_type_1));
	data_source_type_t* data_source_type_2 = data_source_type_parseFromJSON(jsondata_source_type_1);
	cJSON* jsondata_source_type_2 = data_source_type_convertToJSON(data_source_type_2);
	printf("repeating data_source_type:\n%s\n", cJSON_Print(jsondata_source_type_2));
}

int main() {
  test_data_source_type(1);
  test_data_source_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // data_source_type_MAIN
#endif // data_source_type_TEST
