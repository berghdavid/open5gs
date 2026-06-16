/*
 * lmf_data_exposure_cause.h
 *
 * The cause code for LMF Data Exposure Report.
 */

#ifndef _OpenAPI_lmf_data_exposure_cause_H_
#define _OpenAPI_lmf_data_exposure_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_lmf_data_exposure_cause_s OpenAPI_lmf_data_exposure_cause_t;
typedef struct OpenAPI_lmf_data_exposure_cause_s {
} OpenAPI_lmf_data_exposure_cause_t;

OpenAPI_lmf_data_exposure_cause_t *OpenAPI_lmf_data_exposure_cause_create(
);
void OpenAPI_lmf_data_exposure_cause_free(OpenAPI_lmf_data_exposure_cause_t *lmf_data_exposure_cause);
OpenAPI_lmf_data_exposure_cause_t *OpenAPI_lmf_data_exposure_cause_parseFromJSON(cJSON *lmf_data_exposure_causeJSON);
cJSON *OpenAPI_lmf_data_exposure_cause_convertToJSON(OpenAPI_lmf_data_exposure_cause_t *lmf_data_exposure_cause);
OpenAPI_lmf_data_exposure_cause_t *OpenAPI_lmf_data_exposure_cause_copy(OpenAPI_lmf_data_exposure_cause_t *dst, OpenAPI_lmf_data_exposure_cause_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_lmf_data_exposure_cause_H_ */

