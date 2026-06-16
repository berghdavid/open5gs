/*
 * reporting_access_type.h
 *
 * Specifies access types of event reporting.
 */

#ifndef _reporting_access_type_H_
#define _reporting_access_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reporting_access_type_t reporting_access_type_t;




typedef struct reporting_access_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} reporting_access_type_t;

__attribute__((deprecated)) reporting_access_type_t *reporting_access_type_create(
);

void reporting_access_type_free(reporting_access_type_t *reporting_access_type);

reporting_access_type_t *reporting_access_type_parseFromJSON(cJSON *reporting_access_typeJSON);

cJSON *reporting_access_type_convertToJSON(reporting_access_type_t *reporting_access_type);

#endif /* _reporting_access_type_H_ */

