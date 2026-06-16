/*
 * data_source_type.h
 *
 * The data source for location measurement data collection.
 */

#ifndef _data_source_type_H_
#define _data_source_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct data_source_type_t data_source_type_t;




typedef struct data_source_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} data_source_type_t;

__attribute__((deprecated)) data_source_type_t *data_source_type_create(
);

void data_source_type_free(data_source_type_t *data_source_type);

data_source_type_t *data_source_type_parseFromJSON(cJSON *data_source_typeJSON);

cJSON *data_source_type_convertToJSON(data_source_type_t *data_source_type);

#endif /* _data_source_type_H_ */

