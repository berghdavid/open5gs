/*
 * reporting_area.h
 *
 * Indicates an area for event reporting.
 */

#ifndef _reporting_area_H_
#define _reporting_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reporting_area_t reporting_area_t;

#include "ecgi.h"
#include "ncgi.h"
#include "reporting_area_type.h"
#include "tai.h"



typedef struct reporting_area_t {
    struct reporting_area_type_t *area_type; //model
    struct tai_t *tai; //model
    struct ecgi_t *ecgi; //model
    struct ncgi_t *ncgi; //model

    int _library_owned; // Is the library responsible for freeing this object?
} reporting_area_t;

__attribute__((deprecated)) reporting_area_t *reporting_area_create(
    reporting_area_type_t *area_type,
    tai_t *tai,
    ecgi_t *ecgi,
    ncgi_t *ncgi
);

void reporting_area_free(reporting_area_t *reporting_area);

reporting_area_t *reporting_area_parseFromJSON(cJSON *reporting_areaJSON);

cJSON *reporting_area_convertToJSON(reporting_area_t *reporting_area);

#endif /* _reporting_area_H_ */

