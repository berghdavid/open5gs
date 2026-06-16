/*
 * lmf_data_exposure_report.h
 *
 * Describes an LMF data collection exposure report
 */

#ifndef _OpenAPI_lmf_data_exposure_report_H_
#define _OpenAPI_lmf_data_exposure_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "lmf_data_exposure_cause.h"
#include "lmf_data_exposure_sampling_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_lmf_data_exposure_report_s OpenAPI_lmf_data_exposure_report_t;
typedef struct OpenAPI_lmf_data_exposure_report_s {
    OpenAPI_list_t *sampling_data_list;
    bool is_ml_model_id;
    int ml_model_id;
    struct OpenAPI_lmf_data_exposure_cause_s *cause;
} OpenAPI_lmf_data_exposure_report_t;

OpenAPI_lmf_data_exposure_report_t *OpenAPI_lmf_data_exposure_report_create(
    OpenAPI_list_t *sampling_data_list,
    bool is_ml_model_id,
    int ml_model_id,
    OpenAPI_lmf_data_exposure_cause_t *cause
);
void OpenAPI_lmf_data_exposure_report_free(OpenAPI_lmf_data_exposure_report_t *lmf_data_exposure_report);
OpenAPI_lmf_data_exposure_report_t *OpenAPI_lmf_data_exposure_report_parseFromJSON(cJSON *lmf_data_exposure_reportJSON);
cJSON *OpenAPI_lmf_data_exposure_report_convertToJSON(OpenAPI_lmf_data_exposure_report_t *lmf_data_exposure_report);
OpenAPI_lmf_data_exposure_report_t *OpenAPI_lmf_data_exposure_report_copy(OpenAPI_lmf_data_exposure_report_t *dst, OpenAPI_lmf_data_exposure_report_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_lmf_data_exposure_report_H_ */

