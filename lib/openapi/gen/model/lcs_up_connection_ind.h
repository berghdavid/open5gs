/*
 * lcs_up_connection_ind.h
 *
 * LCS UP Connection Indication.
 */

#ifndef _OpenAPI_lcs_up_connection_ind_H_
#define _OpenAPI_lcs_up_connection_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_lcs_up_connection_ind_s OpenAPI_lcs_up_connection_ind_t;
typedef struct OpenAPI_lcs_up_connection_ind_s {
} OpenAPI_lcs_up_connection_ind_t;

OpenAPI_lcs_up_connection_ind_t *OpenAPI_lcs_up_connection_ind_create(
);
void OpenAPI_lcs_up_connection_ind_free(OpenAPI_lcs_up_connection_ind_t *lcs_up_connection_ind);
OpenAPI_lcs_up_connection_ind_t *OpenAPI_lcs_up_connection_ind_parseFromJSON(cJSON *lcs_up_connection_indJSON);
cJSON *OpenAPI_lcs_up_connection_ind_convertToJSON(OpenAPI_lcs_up_connection_ind_t *lcs_up_connection_ind);
OpenAPI_lcs_up_connection_ind_t *OpenAPI_lcs_up_connection_ind_copy(OpenAPI_lcs_up_connection_ind_t *dst, OpenAPI_lcs_up_connection_ind_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_lcs_up_connection_ind_H_ */

