/*
 * high_accuracy_gnss_metrics.h
 *
 * High Accuracy GNSS Positioning Metrics.
 */

#ifndef _high_accuracy_gnss_metrics_H_
#define _high_accuracy_gnss_metrics_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct high_accuracy_gnss_metrics_t high_accuracy_gnss_metrics_t;

#include "fix_type.h"



typedef struct high_accuracy_gnss_metrics_t {
    int *nr_of_used_satellites; //numeric
    int *hdopi; //numeric
    int *pdopi; //numeric
    int *age; //numeric
    struct fix_type_t *fix_type; //model

    int _library_owned; // Is the library responsible for freeing this object?
} high_accuracy_gnss_metrics_t;

__attribute__((deprecated)) high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_create(
    int *nr_of_used_satellites,
    int *hdopi,
    int *pdopi,
    int *age,
    fix_type_t *fix_type
);

void high_accuracy_gnss_metrics_free(high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_parseFromJSON(cJSON *high_accuracy_gnss_metricsJSON);

cJSON *high_accuracy_gnss_metrics_convertToJSON(high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

#endif /* _high_accuracy_gnss_metrics_H_ */

