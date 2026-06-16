/*
 * lmf_data_exposure_sampling_data.h
 *
 * Describes an LMF data collection exposure Sampling Data
 */

#ifndef _OpenAPI_lmf_data_exposure_sampling_data_H_
#define _OpenAPI_lmf_data_exposure_sampling_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "loc_measurements.h"
#include "location_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_lmf_data_exposure_sampling_data_s OpenAPI_lmf_data_exposure_sampling_data_t;
typedef struct OpenAPI_lmf_data_exposure_sampling_data_s {
    char *timestamp;
    struct OpenAPI_loc_measurements_s *loc_measure_data;
    struct OpenAPI_location_data_s *ground_truth;
    bool is_quality_indicator;
    float quality_indicator;
    struct OpenAPI_location_data_s *ml_loc_estimate;
} OpenAPI_lmf_data_exposure_sampling_data_t;

OpenAPI_lmf_data_exposure_sampling_data_t *OpenAPI_lmf_data_exposure_sampling_data_create(
    char *timestamp,
    OpenAPI_loc_measurements_t *loc_measure_data,
    OpenAPI_location_data_t *ground_truth,
    bool is_quality_indicator,
    float quality_indicator,
    OpenAPI_location_data_t *ml_loc_estimate
);
void OpenAPI_lmf_data_exposure_sampling_data_free(OpenAPI_lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data);
OpenAPI_lmf_data_exposure_sampling_data_t *OpenAPI_lmf_data_exposure_sampling_data_parseFromJSON(cJSON *lmf_data_exposure_sampling_dataJSON);
cJSON *OpenAPI_lmf_data_exposure_sampling_data_convertToJSON(OpenAPI_lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data);
OpenAPI_lmf_data_exposure_sampling_data_t *OpenAPI_lmf_data_exposure_sampling_data_copy(OpenAPI_lmf_data_exposure_sampling_data_t *dst, OpenAPI_lmf_data_exposure_sampling_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_lmf_data_exposure_sampling_data_H_ */

