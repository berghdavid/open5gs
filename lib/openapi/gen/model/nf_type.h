/*
 * nf_type.h
 *
 * NF types known to NRF
 */

#ifndef _OpenAPI_nf_type_H_
#define _OpenAPI_nf_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_nf_type_s OpenAPI_nf_type_t;
typedef struct OpenAPI_nf_type_s {
} OpenAPI_nf_type_t;

OpenAPI_nf_type_t *OpenAPI_nf_type_create(
);
void OpenAPI_nf_type_free(OpenAPI_nf_type_t *nf_type);
OpenAPI_nf_type_t *OpenAPI_nf_type_parseFromJSON(cJSON *nf_typeJSON);
cJSON *OpenAPI_nf_type_convertToJSON(OpenAPI_nf_type_t *nf_type);
OpenAPI_nf_type_t *OpenAPI_nf_type_copy(OpenAPI_nf_type_t *dst, OpenAPI_nf_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_nf_type_H_ */

