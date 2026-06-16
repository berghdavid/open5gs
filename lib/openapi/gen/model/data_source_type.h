/*
 * data_source_type.h
 *
 * The data source for location measurement data collection.
 */

#ifndef _OpenAPI_data_source_type_H_
#define _OpenAPI_data_source_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_data_source_type_s OpenAPI_data_source_type_t;
typedef struct OpenAPI_data_source_type_s {
} OpenAPI_data_source_type_t;

OpenAPI_data_source_type_t *OpenAPI_data_source_type_create(
);
void OpenAPI_data_source_type_free(OpenAPI_data_source_type_t *data_source_type);
OpenAPI_data_source_type_t *OpenAPI_data_source_type_parseFromJSON(cJSON *data_source_typeJSON);
cJSON *OpenAPI_data_source_type_convertToJSON(OpenAPI_data_source_type_t *data_source_type);
OpenAPI_data_source_type_t *OpenAPI_data_source_type_copy(OpenAPI_data_source_type_t *dst, OpenAPI_data_source_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_data_source_type_H_ */

