#ifndef input_data_TEST
#define input_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_data.h"
input_data_t* instantiate_input_data(int include_optional);

#include "test_external_client_type.c"
#include "test_location_qo_s.c"
#include "test_ecgi.c"
#include "test_ecgi.c"
#include "test_ncgi.c"
#include "test_ncgi.c"
#include "test_lcs_priority.c"
#include "test_velocity_requested.c"
#include "test_ue_lcs_capability.c"
#include "test_ldr_type.c"
#include "test_periodic_event_info.c"
#include "test_area_event_info.c"
#include "test_motion_event_info.c"
#include "test_ue_connectivity_state.c"
#include "test_ue_location_service_ind.c"
#include "test_lcs_broadcast_assistance_types_data.c"
#include "test_ref_to_binary_data.c"
#include "test_tnap_id.c"
#include "test_twap_id.c"
#include "test_lp_hap_type.c"
#include "test_reporting_ind.c"
#include "test_mbsr_info.c"
#include "test_integrity_requirements.c"
#include "test_up_loc_rep_addr_af.c"
#include "test_up_cum_evt_rpt_criteria.c"
#include "test_mapped_location_qo_s_eps.c"
#include "test_additional_ue_info.c"


input_data_t* instantiate_input_data(int include_optional) {
  input_data_t* input_data = NULL;
  if (include_optional) {
    input_data = input_data_create(
      null,
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_location_qo_s(0),
      list_createList(),
      "a",
      "a",
      "a",
      list_createList(),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_ecgi(0),
       // false, not to have infinite recursion
      instantiate_ecgi(0),
       // false, not to have infinite recursion
      instantiate_ncgi(0),
       // false, not to have infinite recursion
      instantiate_ncgi(0),
      null,
      null,
       // false, not to have infinite recursion
      instantiate_ue_lcs_capability(0),
      0,
      null,
      "0",
      "0",
      "0",
      "a",
      "a",
       // false, not to have infinite recursion
      instantiate_periodic_event_info(0),
       // false, not to have infinite recursion
      instantiate_area_event_info(0),
       // false, not to have infinite recursion
      instantiate_motion_event_info(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_ue_connectivity_state(0),
      null,
       // false, not to have infinite recursion
      instantiate_lcs_broadcast_assistance_types_data(0),
       // false, not to have infinite recursion
      instantiate_ref_to_binary_data(0),
      list_createList(),
      "a",
      "YQ==",
       // false, not to have infinite recursion
      instantiate_tnap_id(0),
       // false, not to have infinite recursion
      instantiate_twap_id(0),
      1,
      "2013-10-20T19:20:30+01:00",
      1,
      list_createList(),
      1,
      1,
      56,
      null,
      list_createList(),
      null,
       // false, not to have infinite recursion
      instantiate_mbsr_info(0),
      1,
       // false, not to have infinite recursion
      instantiate_integrity_requirements(0),
       // false, not to have infinite recursion
      instantiate_up_loc_rep_addr_af(0),
       // false, not to have infinite recursion
      instantiate_up_cum_evt_rpt_criteria(0),
       // false, not to have infinite recursion
      instantiate_mapped_location_qo_s_eps(0),
       // false, not to have infinite recursion
      instantiate_additional_ue_info(0),
      56,
      "YQ==",
      list_createList(),
      1
    );
  } else {
    input_data = input_data_create(
      null,
      "0",
      "0",
      NULL,
      list_createList(),
      "a",
      "a",
      "a",
      list_createList(),
      list_createList(),
      NULL,
      NULL,
      NULL,
      NULL,
      null,
      null,
      NULL,
      0,
      null,
      "0",
      "0",
      "0",
      "a",
      "a",
      NULL,
      NULL,
      NULL,
      list_createList(),
      NULL,
      null,
      NULL,
      NULL,
      list_createList(),
      "a",
      "YQ==",
      NULL,
      NULL,
      1,
      "2013-10-20T19:20:30+01:00",
      1,
      list_createList(),
      1,
      1,
      56,
      null,
      list_createList(),
      null,
      NULL,
      1,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      56,
      "YQ==",
      list_createList(),
      1
    );
  }

  return input_data;
}


#ifdef input_data_MAIN

void test_input_data(int include_optional) {
    input_data_t* input_data_1 = instantiate_input_data(include_optional);

	cJSON* jsoninput_data_1 = input_data_convertToJSON(input_data_1);
	printf("input_data :\n%s\n", cJSON_Print(jsoninput_data_1));
	input_data_t* input_data_2 = input_data_parseFromJSON(jsoninput_data_1);
	cJSON* jsoninput_data_2 = input_data_convertToJSON(input_data_2);
	printf("repeating input_data:\n%s\n", cJSON_Print(jsoninput_data_2));
}

int main() {
  test_input_data(1);
  test_input_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_data_MAIN
#endif // input_data_TEST
