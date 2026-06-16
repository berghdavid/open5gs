/*
 * minor_location_qo_s.h
 *
 * Contain Minor Location QoS.
 */

#ifndef _minor_location_qo_s_H_
#define _minor_location_qo_s_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct minor_location_qo_s_t minor_location_qo_s_t;




typedef struct minor_location_qo_s_t {
    float *h_accuracy; //numeric
    float *v_accuracy; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} minor_location_qo_s_t;

__attribute__((deprecated)) minor_location_qo_s_t *minor_location_qo_s_create(
    float *h_accuracy,
    float *v_accuracy
);

void minor_location_qo_s_free(minor_location_qo_s_t *minor_location_qo_s);

minor_location_qo_s_t *minor_location_qo_s_parseFromJSON(cJSON *minor_location_qo_sJSON);

cJSON *minor_location_qo_s_convertToJSON(minor_location_qo_s_t *minor_location_qo_s);

#endif /* _minor_location_qo_s_H_ */

