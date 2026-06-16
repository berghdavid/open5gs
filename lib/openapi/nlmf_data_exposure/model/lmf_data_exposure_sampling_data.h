/*
 * lmf_data_exposure_sampling_data.h
 *
 * Describes an LMF data collection exposure Sampling Data
 */

#ifndef _lmf_data_exposure_sampling_data_H_
#define _lmf_data_exposure_sampling_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lmf_data_exposure_sampling_data_t lmf_data_exposure_sampling_data_t;

#include "loc_measurements.h"
#include "location_data.h"



typedef struct lmf_data_exposure_sampling_data_t {
    char *timestamp; //date time
    struct loc_measurements_t *loc_measure_data; //model
    struct location_data_t *ground_truth; //model
    float *quality_indicator; //numeric
    struct location_data_t *ml_loc_estimate; //model

    int _library_owned; // Is the library responsible for freeing this object?
} lmf_data_exposure_sampling_data_t;

__attribute__((deprecated)) lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data_create(
    char *timestamp,
    loc_measurements_t *loc_measure_data,
    location_data_t *ground_truth,
    float *quality_indicator,
    location_data_t *ml_loc_estimate
);

void lmf_data_exposure_sampling_data_free(lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data);

lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data_parseFromJSON(cJSON *lmf_data_exposure_sampling_dataJSON);

cJSON *lmf_data_exposure_sampling_data_convertToJSON(lmf_data_exposure_sampling_data_t *lmf_data_exposure_sampling_data);

#endif /* _lmf_data_exposure_sampling_data_H_ */

