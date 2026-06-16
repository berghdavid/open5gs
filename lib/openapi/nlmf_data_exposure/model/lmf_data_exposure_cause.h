/*
 * lmf_data_exposure_cause.h
 *
 * The cause code for LMF Data Exposure Report.
 */

#ifndef _lmf_data_exposure_cause_H_
#define _lmf_data_exposure_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lmf_data_exposure_cause_t lmf_data_exposure_cause_t;




typedef struct lmf_data_exposure_cause_t {

    int _library_owned; // Is the library responsible for freeing this object?
} lmf_data_exposure_cause_t;

__attribute__((deprecated)) lmf_data_exposure_cause_t *lmf_data_exposure_cause_create(
);

void lmf_data_exposure_cause_free(lmf_data_exposure_cause_t *lmf_data_exposure_cause);

lmf_data_exposure_cause_t *lmf_data_exposure_cause_parseFromJSON(cJSON *lmf_data_exposure_causeJSON);

cJSON *lmf_data_exposure_cause_convertToJSON(lmf_data_exposure_cause_t *lmf_data_exposure_cause);

#endif /* _lmf_data_exposure_cause_H_ */

