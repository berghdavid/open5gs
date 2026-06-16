/*
 * lp_hap_type.h
 *
 * Type of Low Power and/or High Accuracy Positioning
 */

#ifndef _lp_hap_type_H_
#define _lp_hap_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lp_hap_type_t lp_hap_type_t;




typedef struct lp_hap_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} lp_hap_type_t;

__attribute__((deprecated)) lp_hap_type_t *lp_hap_type_create(
);

void lp_hap_type_free(lp_hap_type_t *lp_hap_type);

lp_hap_type_t *lp_hap_type_parseFromJSON(cJSON *lp_hap_typeJSON);

cJSON *lp_hap_type_convertToJSON(lp_hap_type_t *lp_hap_type);

#endif /* _lp_hap_type_H_ */

