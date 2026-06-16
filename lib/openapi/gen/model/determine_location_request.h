/*
 * determine_location_request.h
 *
 * 
 */

#ifndef _OpenAPI_determine_location_request_H_
#define _OpenAPI_determine_location_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "input_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_determine_location_request_s OpenAPI_determine_location_request_t;
typedef struct OpenAPI_determine_location_request_s {
    struct OpenAPI_input_data_s *json_data;
    OpenAPI_binary_t* binary_data_lpp_message;
} OpenAPI_determine_location_request_t;

OpenAPI_determine_location_request_t *OpenAPI_determine_location_request_create(
    OpenAPI_input_data_t *json_data,
    OpenAPI_binary_t* binary_data_lpp_message
);
void OpenAPI_determine_location_request_free(OpenAPI_determine_location_request_t *determine_location_request);
OpenAPI_determine_location_request_t *OpenAPI_determine_location_request_parseFromJSON(cJSON *determine_location_requestJSON);
cJSON *OpenAPI_determine_location_request_convertToJSON(OpenAPI_determine_location_request_t *determine_location_request);
OpenAPI_determine_location_request_t *OpenAPI_determine_location_request_copy(OpenAPI_determine_location_request_t *dst, OpenAPI_determine_location_request_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_determine_location_request_H_ */

