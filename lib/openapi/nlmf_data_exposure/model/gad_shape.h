/*
 * gad_shape.h
 *
 * Common base type for GAD shapes.
 */

#ifndef _gad_shape_H_
#define _gad_shape_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gad_shape_t gad_shape_t;

#include "supported_gad_shapes.h"



typedef struct gad_shape_t {
    struct supported_gad_shapes_t *shape; //model

    int _library_owned; // Is the library responsible for freeing this object?
} gad_shape_t;

__attribute__((deprecated)) gad_shape_t *gad_shape_create(
    supported_gad_shapes_t *shape
);

void gad_shape_free(gad_shape_t *gad_shape);

gad_shape_t *gad_shape_parseFromJSON(cJSON *gad_shapeJSON);

cJSON *gad_shape_convertToJSON(gad_shape_t *gad_shape);

#endif /* _gad_shape_H_ */

