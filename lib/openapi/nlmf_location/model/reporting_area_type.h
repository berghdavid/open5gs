/*
 * reporting_area_type.h
 *
 * Indicates type of event reporting area.
 */

#ifndef _reporting_area_type_H_
#define _reporting_area_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reporting_area_type_t reporting_area_type_t;




typedef struct reporting_area_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} reporting_area_type_t;

__attribute__((deprecated)) reporting_area_type_t *reporting_area_type_create(
);

void reporting_area_type_free(reporting_area_type_t *reporting_area_type);

reporting_area_type_t *reporting_area_type_parseFromJSON(cJSON *reporting_area_typeJSON);

cJSON *reporting_area_type_convertToJSON(reporting_area_type_t *reporting_area_type);

#endif /* _reporting_area_type_H_ */

