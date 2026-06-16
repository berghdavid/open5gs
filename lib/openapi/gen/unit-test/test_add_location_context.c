#ifndef add_location_context_TEST
#define add_location_context_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define add_location_context_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/add_location_context.h"
add_location_context_t* instantiate_add_location_context(int include_optional);

#include "test_location_qo_s.c"
#include "test_ldr_type.c"
#include "test_periodic_event_info.c"
#include "test_area_event_info.c"
#include "test_motion_event_info.c"
#include "test_event_report_message.c"
#include "test_event_reporting_status.c"
#include "test_ue_location_info.c"
#include "test_indoor_outdoor_ind.c"
#include "test_los_nlos_measure_ind.c"
#include "test_up_cum_evt_rpt_criteria.c"


add_location_context_t* instantiate_add_location_context(int include_optional) {
  add_location_context_t* add_location_context = NULL;
  if (include_optional) {
    add_location_context = add_location_context_create(
       // false, not to have infinite recursion
      instantiate_location_qo_s(0),
      null,
      "0",
      "a",
       // false, not to have infinite recursion
      instantiate_periodic_event_info(0),
       // false, not to have infinite recursion
      instantiate_area_event_info(0),
       // false, not to have infinite recursion
      instantiate_motion_event_info(0),
       // false, not to have infinite recursion
      instantiate_event_report_message(0),
       // false, not to have infinite recursion
      instantiate_event_reporting_status(0),
       // false, not to have infinite recursion
      instantiate_ue_location_info(0),
      "2013-10-20T19:20:30+01:00",
      null,
      null,
       // false, not to have infinite recursion
      instantiate_up_cum_evt_rpt_criteria(0),
      1
    );
  } else {
    add_location_context = add_location_context_create(
      NULL,
      null,
      "0",
      "a",
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      "2013-10-20T19:20:30+01:00",
      null,
      null,
      NULL,
      1
    );
  }

  return add_location_context;
}


#ifdef add_location_context_MAIN

void test_add_location_context(int include_optional) {
    add_location_context_t* add_location_context_1 = instantiate_add_location_context(include_optional);

	cJSON* jsonadd_location_context_1 = add_location_context_convertToJSON(add_location_context_1);
	printf("add_location_context :\n%s\n", cJSON_Print(jsonadd_location_context_1));
	add_location_context_t* add_location_context_2 = add_location_context_parseFromJSON(jsonadd_location_context_1);
	cJSON* jsonadd_location_context_2 = add_location_context_convertToJSON(add_location_context_2);
	printf("repeating add_location_context:\n%s\n", cJSON_Print(jsonadd_location_context_2));
}

int main() {
  test_add_location_context(1);
  test_add_location_context(0);

  printf("Hello world \n");
  return 0;
}

#endif // add_location_context_MAIN
#endif // add_location_context_TEST
