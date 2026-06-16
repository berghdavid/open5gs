/*
 * local_origin.h
 *
 * Indicates a Local origin in a reference system
 */

#ifndef _local_origin_H_
#define _local_origin_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct local_origin_t local_origin_t;

#include "geographic_area.h"
#include "geographical_coordinates.h"



typedef struct local_origin_t {
    char *coordinate_id; // string
    struct geographical_coordinates_t *point; //model
    struct geographic_area_t *area; //model
    int *horiz_axes_orientation; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} local_origin_t;

__attribute__((deprecated)) local_origin_t *local_origin_create(
    char *coordinate_id,
    geographical_coordinates_t *point,
    geographic_area_t *area,
    int *horiz_axes_orientation
);

void local_origin_free(local_origin_t *local_origin);

local_origin_t *local_origin_parseFromJSON(cJSON *local_originJSON);

cJSON *local_origin_convertToJSON(local_origin_t *local_origin);

#endif /* _local_origin_H_ */

