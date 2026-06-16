#ifndef patch_item_TEST
#define patch_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_item.h"
patch_item_t* instantiate_patch_item(int include_optional);

#include "test_patch_operation.c"


patch_item_t* instantiate_patch_item(int include_optional) {
  patch_item_t* patch_item = NULL;
  if (include_optional) {
    patch_item = patch_item_create(
      null,
      "0",
      "0",
      null
    );
  } else {
    patch_item = patch_item_create(
      null,
      "0",
      "0",
      null
    );
  }

  return patch_item;
}


#ifdef patch_item_MAIN

void test_patch_item(int include_optional) {
    patch_item_t* patch_item_1 = instantiate_patch_item(include_optional);

	cJSON* jsonpatch_item_1 = patch_item_convertToJSON(patch_item_1);
	printf("patch_item :\n%s\n", cJSON_Print(jsonpatch_item_1));
	patch_item_t* patch_item_2 = patch_item_parseFromJSON(jsonpatch_item_1);
	cJSON* jsonpatch_item_2 = patch_item_convertToJSON(patch_item_2);
	printf("repeating patch_item:\n%s\n", cJSON_Print(jsonpatch_item_2));
}

int main() {
  test_patch_item(1);
  test_patch_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_item_MAIN
#endif // patch_item_TEST
