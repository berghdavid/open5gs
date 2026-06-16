/*
 * location_qo_s.h
 *
 * QoS of Location request.
 */

#ifndef _location_qo_s_H_
#define _location_qo_s_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct location_qo_s_t location_qo_s_t;

#include "lcs_qos_class.h"
#include "minor_location_qo_s.h"
#include "response_time.h"



typedef struct location_qo_s_t {
    float *h_accuracy; //numeric
    float *v_accuracy; //numeric
    int *vertical_requested; //boolean
    struct response_time_t *response_time; //model
    list_t *minor_loc_qoses; //nonprimitive container
    struct lcs_qos_class_t *lcs_qos_class; //model

    int _library_owned; // Is the library responsible for freeing this object?
} location_qo_s_t;

__attribute__((deprecated)) location_qo_s_t *location_qo_s_create(
    float *h_accuracy,
    float *v_accuracy,
    int *vertical_requested,
    response_time_t *response_time,
    list_t *minor_loc_qoses,
    lcs_qos_class_t *lcs_qos_class
);

void location_qo_s_free(location_qo_s_t *location_qo_s);

location_qo_s_t *location_qo_s_parseFromJSON(cJSON *location_qo_sJSON);

cJSON *location_qo_s_convertToJSON(location_qo_s_t *location_qo_s);

#endif /* _location_qo_s_H_ */

