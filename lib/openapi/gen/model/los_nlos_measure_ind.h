/*
 * los_nlos_measure_ind.h
 *
 * Specifies LOS measurement or NLOS measurement.
 */

#ifndef _OpenAPI_los_nlos_measure_ind_H_
#define _OpenAPI_los_nlos_measure_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_los_nlos_measure_ind_s OpenAPI_los_nlos_measure_ind_t;
typedef struct OpenAPI_los_nlos_measure_ind_s {
} OpenAPI_los_nlos_measure_ind_t;

OpenAPI_los_nlos_measure_ind_t *OpenAPI_los_nlos_measure_ind_create(
);
void OpenAPI_los_nlos_measure_ind_free(OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind);
OpenAPI_los_nlos_measure_ind_t *OpenAPI_los_nlos_measure_ind_parseFromJSON(cJSON *los_nlos_measure_indJSON);
cJSON *OpenAPI_los_nlos_measure_ind_convertToJSON(OpenAPI_los_nlos_measure_ind_t *los_nlos_measure_ind);
OpenAPI_los_nlos_measure_ind_t *OpenAPI_los_nlos_measure_ind_copy(OpenAPI_los_nlos_measure_ind_t *dst, OpenAPI_los_nlos_measure_ind_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_los_nlos_measure_ind_H_ */

