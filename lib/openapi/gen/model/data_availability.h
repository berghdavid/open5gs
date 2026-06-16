/*
 * data_availability.h
 *
 * Indicates availability of ciphering key data at an LMF.
 */

#ifndef _OpenAPI_data_availability_H_
#define _OpenAPI_data_availability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { OpenAPI_data_availability_NULL = 0, OpenAPI_data_availability_CIPHERING_KEY_DATA_AVAILABLE, OpenAPI_data_availability_CIPHERING_KEY_DATA_NOT_AVAILABLE } OpenAPI_data_availability_e;

char* OpenAPI_data_availability_ToString(OpenAPI_data_availability_e data_availability);

OpenAPI_data_availability_e OpenAPI_data_availability_FromString(char* data_availability);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_data_availability_H_ */

