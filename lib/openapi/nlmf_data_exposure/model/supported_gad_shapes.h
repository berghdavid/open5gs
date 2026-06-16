/*
 * supported_gad_shapes.h
 *
 * Indicates supported GAD shapes.
 */

#ifndef _supported_gad_shapes_H_
#define _supported_gad_shapes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct supported_gad_shapes_t supported_gad_shapes_t;




typedef struct supported_gad_shapes_t {

    int _library_owned; // Is the library responsible for freeing this object?
} supported_gad_shapes_t;

__attribute__((deprecated)) supported_gad_shapes_t *supported_gad_shapes_create(
);

void supported_gad_shapes_free(supported_gad_shapes_t *supported_gad_shapes);

supported_gad_shapes_t *supported_gad_shapes_parseFromJSON(cJSON *supported_gad_shapesJSON);

cJSON *supported_gad_shapes_convertToJSON(supported_gad_shapes_t *supported_gad_shapes);

#endif /* _supported_gad_shapes_H_ */

