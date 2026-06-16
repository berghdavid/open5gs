/*
 * lcs_qos_class.h
 *
 * Specifies LCS QoS class.
 */

#ifndef _lcs_qos_class_H_
#define _lcs_qos_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lcs_qos_class_t lcs_qos_class_t;




typedef struct lcs_qos_class_t {

    int _library_owned; // Is the library responsible for freeing this object?
} lcs_qos_class_t;

__attribute__((deprecated)) lcs_qos_class_t *lcs_qos_class_create(
);

void lcs_qos_class_free(lcs_qos_class_t *lcs_qos_class);

lcs_qos_class_t *lcs_qos_class_parseFromJSON(cJSON *lcs_qos_classJSON);

cJSON *lcs_qos_class_convertToJSON(lcs_qos_class_t *lcs_qos_class);

#endif /* _lcs_qos_class_H_ */

