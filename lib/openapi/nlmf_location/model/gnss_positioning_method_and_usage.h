/*
 * gnss_positioning_method_and_usage.h
 *
 * Indicates the usage of a Global Navigation Satellite System (GNSS) positioning method. 
 */

#ifndef _gnss_positioning_method_and_usage_H_
#define _gnss_positioning_method_and_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gnss_positioning_method_and_usage_t gnss_positioning_method_and_usage_t;

#include "gnss_id.h"
#include "positioning_mode.h"
#include "usage.h"



typedef struct gnss_positioning_method_and_usage_t {
    struct positioning_mode_t *mode; //model
    struct gnss_id_t *gnss; //model
    struct usage_t *usage; //model

    int _library_owned; // Is the library responsible for freeing this object?
} gnss_positioning_method_and_usage_t;

__attribute__((deprecated)) gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_create(
    positioning_mode_t *mode,
    gnss_id_t *gnss,
    usage_t *usage
);

void gnss_positioning_method_and_usage_free(gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage);

gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_parseFromJSON(cJSON *gnss_positioning_method_and_usageJSON);

cJSON *gnss_positioning_method_and_usage_convertToJSON(gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage);

#endif /* _gnss_positioning_method_and_usage_H_ */

