#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point.h"



static point_t *point_create_internal(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point
    ) {
    point_t *point_local_var = malloc(sizeof(point_t));
    if (!point_local_var) {
        return NULL;
    }
    memset(point_local_var, 0, sizeof(point_t));
    point_local_var->_library_owned = 1;
    point_local_var->shape = shape;
    point_local_var->point = point;
    return point_local_var;
}

__attribute__((deprecated)) point_t *point_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point
    ) {
    point_t *result = point_create_internal (
        shape,
        point
        );
    if (!result) {
    }
    return result;
}

void point_free(point_t *point) {
    if(NULL == point){
        return ;
    }
    if(point->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "point_free");
        return ;
    }
    listEntry_t *listEntry;
    if (point->shape) {
        supported_gad_shapes_free(point->shape);
        point->shape = NULL;
    }
    if (point->point) {
        geographical_coordinates_free(point->point);
        point->point = NULL;
    }
    free(point);
}

cJSON *point_convertToJSON(point_t *point) {
    cJSON *item = cJSON_CreateObject();

    // point->shape
    if (!point->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(point->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point->point
    if (!point->point) {
        goto fail;
    }
    cJSON *point_local_JSON = geographical_coordinates_convertToJSON(point->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

point_t *point_parseFromJSON(cJSON *pointJSON){

    point_t *point_local_var = NULL;

    // define the local variable for point->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for point->point
    geographical_coordinates_t *point_local_nonprim = NULL;

    // point->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(pointJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // point->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(pointJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = geographical_coordinates_parseFromJSON(point); //nonprimitive



    point_local_var = point_create_internal (
        shape_local_nonprim,
        point_local_nonprim
        );

    if (!point_local_var) {
        goto end;
    }

    return point_local_var;
end:
    if (shape_local_nonprim) {
        supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
    }
    if (point_local_nonprim) {
        geographical_coordinates_free(point_local_nonprim);
        point_local_nonprim = NULL;
    }
    return NULL;

}
