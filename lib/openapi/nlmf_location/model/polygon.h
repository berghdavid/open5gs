/*
 * polygon.h
 *
 * Polygon.
 */

#ifndef _polygon_H_
#define _polygon_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct polygon_t polygon_t;

#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"



typedef struct polygon_t {
    struct supported_gad_shapes_t *shape; //model
    list_t *point_list; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} polygon_t;

__attribute__((deprecated)) polygon_t *polygon_create(
    supported_gad_shapes_t *shape,
    list_t *point_list
);

void polygon_free(polygon_t *polygon);

polygon_t *polygon_parseFromJSON(cJSON *polygonJSON);

cJSON *polygon_convertToJSON(polygon_t *polygon);

#endif /* _polygon_H_ */

