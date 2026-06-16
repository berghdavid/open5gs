#ifndef patch_operation_TEST
#define patch_operation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_operation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_operation.h"
patch_operation_t* instantiate_patch_operation(int include_optional);



patch_operation_t* instantiate_patch_operation(int include_optional) {
  patch_operation_t* patch_operation = NULL;
  if (include_optional) {
    patch_operation = patch_operation_create(
    );
  } else {
    patch_operation = patch_operation_create(
    );
  }

  return patch_operation;
}


#ifdef patch_operation_MAIN

void test_patch_operation(int include_optional) {
    patch_operation_t* patch_operation_1 = instantiate_patch_operation(include_optional);

	cJSON* jsonpatch_operation_1 = patch_operation_convertToJSON(patch_operation_1);
	printf("patch_operation :\n%s\n", cJSON_Print(jsonpatch_operation_1));
	patch_operation_t* patch_operation_2 = patch_operation_parseFromJSON(jsonpatch_operation_1);
	cJSON* jsonpatch_operation_2 = patch_operation_convertToJSON(patch_operation_2);
	printf("repeating patch_operation:\n%s\n", cJSON_Print(jsonpatch_operation_2));
}

int main() {
  test_patch_operation(1);
  test_patch_operation(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_operation_MAIN
#endif // patch_operation_TEST
