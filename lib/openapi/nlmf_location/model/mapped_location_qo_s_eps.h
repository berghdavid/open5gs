/*
 * mapped_location_qo_s_eps.h
 *
 * Mapped Location QoS for EPS.
 */

#ifndef _mapped_location_qo_s_eps_H_
#define _mapped_location_qo_s_eps_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct mapped_location_qo_s_eps_t mapped_location_qo_s_eps_t;




typedef struct mapped_location_qo_s_eps_t {
    float *h_accuracy; //numeric
    float *v_accuracy; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} mapped_location_qo_s_eps_t;

__attribute__((deprecated)) mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_create(
    float *h_accuracy,
    float *v_accuracy
);

void mapped_location_qo_s_eps_free(mapped_location_qo_s_eps_t *mapped_location_qo_s_eps);

mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_parseFromJSON(cJSON *mapped_location_qo_s_epsJSON);

cJSON *mapped_location_qo_s_eps_convertToJSON(mapped_location_qo_s_eps_t *mapped_location_qo_s_eps);

#endif /* _mapped_location_qo_s_eps_H_ */

