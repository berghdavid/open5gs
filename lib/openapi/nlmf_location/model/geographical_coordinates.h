/*
 * geographical_coordinates.h
 *
 * Geographical coordinates.
 */

#ifndef _geographical_coordinates_H_
#define _geographical_coordinates_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct geographical_coordinates_t geographical_coordinates_t;




typedef struct geographical_coordinates_t {
    double *lon; //numeric
    double *lat; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} geographical_coordinates_t;

__attribute__((deprecated)) geographical_coordinates_t *geographical_coordinates_create(
    double *lon,
    double *lat
);

void geographical_coordinates_free(geographical_coordinates_t *geographical_coordinates);

geographical_coordinates_t *geographical_coordinates_parseFromJSON(cJSON *geographical_coordinatesJSON);

cJSON *geographical_coordinates_convertToJSON(geographical_coordinates_t *geographical_coordinates);

#endif /* _geographical_coordinates_H_ */

