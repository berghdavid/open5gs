/*
 * accuracy_fulfilment_indicator.h
 *
 * Indicates fulfilment of requested accuracy.
 */

#ifndef _accuracy_fulfilment_indicator_H_
#define _accuracy_fulfilment_indicator_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct accuracy_fulfilment_indicator_t accuracy_fulfilment_indicator_t;




typedef struct accuracy_fulfilment_indicator_t {

    int _library_owned; // Is the library responsible for freeing this object?
} accuracy_fulfilment_indicator_t;

__attribute__((deprecated)) accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_create(
);

void accuracy_fulfilment_indicator_free(accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator);

accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator_parseFromJSON(cJSON *accuracy_fulfilment_indicatorJSON);

cJSON *accuracy_fulfilment_indicator_convertToJSON(accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator);

#endif /* _accuracy_fulfilment_indicator_H_ */

