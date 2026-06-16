/*
 * reporting_ind.h
 *
 * Indicates whether the UE is allowed to generate and send the event report inside or outside the event report allowed(expected) area. Possible values are: - INSIDE_REPORTING: Reporting when UE is inside the event report allowed/expected area. - OUTSIDE_REPORTING: Reporting when UE is outside the event report allowed/expected area. 
 */

#ifndef _reporting_ind_H_
#define _reporting_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reporting_ind_t reporting_ind_t;




typedef struct reporting_ind_t {

    int _library_owned; // Is the library responsible for freeing this object?
} reporting_ind_t;

__attribute__((deprecated)) reporting_ind_t *reporting_ind_create(
);

void reporting_ind_free(reporting_ind_t *reporting_ind);

reporting_ind_t *reporting_ind_parseFromJSON(cJSON *reporting_indJSON);

cJSON *reporting_ind_convertToJSON(reporting_ind_t *reporting_ind);

#endif /* _reporting_ind_H_ */

