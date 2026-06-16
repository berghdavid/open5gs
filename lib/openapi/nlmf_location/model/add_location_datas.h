/*
 * add_location_datas.h
 *
 * Additional Location Data.
 */

#ifndef _add_location_datas_H_
#define _add_location_datas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct add_location_datas_t add_location_datas_t;

#include "location_data.h"



typedef struct add_location_datas_t {
    list_t *add_location_datas; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} add_location_datas_t;

__attribute__((deprecated)) add_location_datas_t *add_location_datas_create(
    list_t *add_location_datas
);

void add_location_datas_free(add_location_datas_t *add_location_datas);

add_location_datas_t *add_location_datas_parseFromJSON(cJSON *add_location_datasJSON);

cJSON *add_location_datas_convertToJSON(add_location_datas_t *add_location_datas);

#endif /* _add_location_datas_H_ */

