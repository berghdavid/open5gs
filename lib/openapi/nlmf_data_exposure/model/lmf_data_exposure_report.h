/*
 * lmf_data_exposure_report.h
 *
 * Describes an LMF data collection exposure report
 */

#ifndef _lmf_data_exposure_report_H_
#define _lmf_data_exposure_report_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lmf_data_exposure_report_t lmf_data_exposure_report_t;

#include "lmf_data_exposure_cause.h"
#include "lmf_data_exposure_sampling_data.h"



typedef struct lmf_data_exposure_report_t {
    list_t *sampling_data_list; //nonprimitive container
    int *ml_model_id; //numeric
    struct lmf_data_exposure_cause_t *cause; //model

    int _library_owned; // Is the library responsible for freeing this object?
} lmf_data_exposure_report_t;

__attribute__((deprecated)) lmf_data_exposure_report_t *lmf_data_exposure_report_create(
    list_t *sampling_data_list,
    int *ml_model_id,
    lmf_data_exposure_cause_t *cause
);

void lmf_data_exposure_report_free(lmf_data_exposure_report_t *lmf_data_exposure_report);

lmf_data_exposure_report_t *lmf_data_exposure_report_parseFromJSON(cJSON *lmf_data_exposure_reportJSON);

cJSON *lmf_data_exposure_report_convertToJSON(lmf_data_exposure_report_t *lmf_data_exposure_report);

#endif /* _lmf_data_exposure_report_H_ */

