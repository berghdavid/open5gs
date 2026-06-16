/*
 * determine_location_request.h
 *
 * 
 */

#ifndef _determine_location_request_H_
#define _determine_location_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct determine_location_request_t determine_location_request_t;

#include "input_data.h"



typedef struct determine_location_request_t {
    struct input_data_t *json_data; //model
    binary_t* binary_data_lpp_message; //binary

    int _library_owned; // Is the library responsible for freeing this object?
} determine_location_request_t;

__attribute__((deprecated)) determine_location_request_t *determine_location_request_create(
    input_data_t *json_data,
    binary_t* binary_data_lpp_message
);

void determine_location_request_free(determine_location_request_t *determine_location_request);

determine_location_request_t *determine_location_request_parseFromJSON(cJSON *determine_location_requestJSON);

cJSON *determine_location_request_convertToJSON(determine_location_request_t *determine_location_request);

#endif /* _determine_location_request_H_ */

