/*
 * units_linear_velocity.h
 *
 * The the units of linear velocity.
 */

#ifndef _OpenAPI_units_linear_velocity_H_
#define _OpenAPI_units_linear_velocity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_units_linear_velocity_s OpenAPI_units_linear_velocity_t;
typedef struct OpenAPI_units_linear_velocity_s {
} OpenAPI_units_linear_velocity_t;

OpenAPI_units_linear_velocity_t *OpenAPI_units_linear_velocity_create(
);
void OpenAPI_units_linear_velocity_free(OpenAPI_units_linear_velocity_t *units_linear_velocity);
OpenAPI_units_linear_velocity_t *OpenAPI_units_linear_velocity_parseFromJSON(cJSON *units_linear_velocityJSON);
cJSON *OpenAPI_units_linear_velocity_convertToJSON(OpenAPI_units_linear_velocity_t *units_linear_velocity);
OpenAPI_units_linear_velocity_t *OpenAPI_units_linear_velocity_copy(OpenAPI_units_linear_velocity_t *dst, OpenAPI_units_linear_velocity_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_units_linear_velocity_H_ */

