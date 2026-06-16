#ifndef ml_model_inter_ind_TEST
#define ml_model_inter_ind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ml_model_inter_ind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ml_model_inter_ind.h"
ml_model_inter_ind_t* instantiate_ml_model_inter_ind(int include_optional);

#include "test_nwdaf_event.c"


ml_model_inter_ind_t* instantiate_ml_model_inter_ind(int include_optional) {
  ml_model_inter_ind_t* ml_model_inter_ind = NULL;
  if (include_optional) {
    ml_model_inter_ind = ml_model_inter_ind_create(
      null,
      list_createList()
    );
  } else {
    ml_model_inter_ind = ml_model_inter_ind_create(
      null,
      list_createList()
    );
  }

  return ml_model_inter_ind;
}


#ifdef ml_model_inter_ind_MAIN

void test_ml_model_inter_ind(int include_optional) {
    ml_model_inter_ind_t* ml_model_inter_ind_1 = instantiate_ml_model_inter_ind(include_optional);

	cJSON* jsonml_model_inter_ind_1 = ml_model_inter_ind_convertToJSON(ml_model_inter_ind_1);
	printf("ml_model_inter_ind :\n%s\n", cJSON_Print(jsonml_model_inter_ind_1));
	ml_model_inter_ind_t* ml_model_inter_ind_2 = ml_model_inter_ind_parseFromJSON(jsonml_model_inter_ind_1);
	cJSON* jsonml_model_inter_ind_2 = ml_model_inter_ind_convertToJSON(ml_model_inter_ind_2);
	printf("repeating ml_model_inter_ind:\n%s\n", cJSON_Print(jsonml_model_inter_ind_2));
}

int main() {
  test_ml_model_inter_ind(1);
  test_ml_model_inter_ind(0);

  printf("Hello world \n");
  return 0;
}

#endif // ml_model_inter_ind_MAIN
#endif // ml_model_inter_ind_TEST
