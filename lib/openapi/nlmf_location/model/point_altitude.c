#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_altitude.h"



static point_altitude_t *point_altitude_create_internal(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    double *altitude
    ) {
    point_altitude_t *point_altitude_local_var = malloc(sizeof(point_altitude_t));
    if (!point_altitude_local_var) {
        return NULL;
    }
    memset(point_altitude_local_var, 0, sizeof(point_altitude_t));
    point_altitude_local_var->_library_owned = 1;
    point_altitude_local_var->shape = shape;
    point_altitude_local_var->point = point;
    point_altitude_local_var->altitude = altitude;
    return point_altitude_local_var;
}

__attribute__((deprecated)) point_altitude_t *point_altitude_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    double *altitude
    ) {
    double *altitude_copy = NULL;
    if (altitude) {
        altitude_copy = malloc(sizeof(double));
        if (altitude_copy) *altitude_copy = *altitude;
    }
    point_altitude_t *result = point_altitude_create_internal (
        shape,
        point,
        altitude_copy
        );
    if (!result) {
        free(altitude_copy);
    }
    return result;
}

void point_altitude_free(point_altitude_t *point_altitude) {
    if(NULL == point_altitude){
        return ;
    }
    if(point_altitude->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "point_altitude_free");
        return ;
    }
    listEntry_t *listEntry;
    if (point_altitude->shape) {
        supported_gad_shapes_free(point_altitude->shape);
        point_altitude->shape = NULL;
    }
    if (point_altitude->point) {
        geographical_coordinates_free(point_altitude->point);
        point_altitude->point = NULL;
    }
    if (point_altitude->altitude) {
        free(point_altitude->altitude);
        point_altitude->altitude = NULL;
    }
    free(point_altitude);
}

cJSON *point_altitude_convertToJSON(point_altitude_t *point_altitude) {
    cJSON *item = cJSON_CreateObject();

    // point_altitude->shape
    if (!point_altitude->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(point_altitude->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_altitude->point
    if (!point_altitude->point) {
        goto fail;
    }
    cJSON *point_local_JSON = geographical_coordinates_convertToJSON(point_altitude->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_altitude->altitude
    if (!point_altitude->altitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "altitude", *point_altitude->altitude) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

point_altitude_t *point_altitude_parseFromJSON(cJSON *point_altitudeJSON){

    point_altitude_t *point_altitude_local_var = NULL;

    // define the local variable for point_altitude->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for point_altitude->point
    geographical_coordinates_t *point_local_nonprim = NULL;

    // define the local variable for point_altitude->altitude
    double *altitude_local_var = NULL;

    // point_altitude->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(point_altitudeJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // point_altitude->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(point_altitudeJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = geographical_coordinates_parseFromJSON(point); //nonprimitive

    // point_altitude->altitude
    cJSON *altitude = cJSON_GetObjectItemCaseSensitive(point_altitudeJSON, "altitude");
    if (cJSON_IsNull(altitude)) {
        altitude = NULL;
    }
    if (!altitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(altitude))
    {
    goto end; //Numeric
    }
    altitude_local_var = malloc(sizeof(double));
    if(!altitude_local_var)
    {
        goto end;
    }
    *altitude_local_var = altitude->valuedouble;



    point_altitude_local_var = point_altitude_create_internal (
        shape_local_nonprim,
        point_local_nonprim,
        altitude_local_var
        );

    if (!point_altitude_local_var) {
        goto end;
    }

    return point_altitude_local_var;
end:
    if (shape_local_nonprim) {
        supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
    }
    if (point_local_nonprim) {
        geographical_coordinates_free(point_local_nonprim);
        point_local_nonprim = NULL;
    }
    if (altitude_local_var) {
        free(altitude_local_var);
        altitude_local_var = NULL;
    }
    return NULL;

}
