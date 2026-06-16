/*
 * lp_hap_type.h
 *
 * Type of Low Power and/or High Accuracy Positioning
 */

#ifndef _OpenAPI_lp_hap_type_H_
#define _OpenAPI_lp_hap_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_lp_hap_type_s OpenAPI_lp_hap_type_t;
typedef struct OpenAPI_lp_hap_type_s {
} OpenAPI_lp_hap_type_t;

OpenAPI_lp_hap_type_t *OpenAPI_lp_hap_type_create(
);
void OpenAPI_lp_hap_type_free(OpenAPI_lp_hap_type_t *lp_hap_type);
OpenAPI_lp_hap_type_t *OpenAPI_lp_hap_type_parseFromJSON(cJSON *lp_hap_typeJSON);
cJSON *OpenAPI_lp_hap_type_convertToJSON(OpenAPI_lp_hap_type_t *lp_hap_type);
OpenAPI_lp_hap_type_t *OpenAPI_lp_hap_type_copy(OpenAPI_lp_hap_type_t *dst, OpenAPI_lp_hap_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_lp_hap_type_H_ */

