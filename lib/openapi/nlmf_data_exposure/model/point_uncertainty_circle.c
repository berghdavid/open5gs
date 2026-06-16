#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_uncertainty_circle.h"



static point_uncertainty_circle_t *point_uncertainty_circle_create_internal(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    float *uncertainty
    ) {
    point_uncertainty_circle_t *point_uncertainty_circle_local_var = malloc(sizeof(point_uncertainty_circle_t));
    if (!point_uncertainty_circle_local_var) {
        return NULL;
    }
    memset(point_uncertainty_circle_local_var, 0, sizeof(point_uncertainty_circle_t));
    point_uncertainty_circle_local_var->_library_owned = 1;
    point_uncertainty_circle_local_var->shape = shape;
    point_uncertainty_circle_local_var->point = point;
    point_uncertainty_circle_local_var->uncertainty = uncertainty;
    return point_uncertainty_circle_local_var;
}

__attribute__((deprecated)) point_uncertainty_circle_t *point_uncertainty_circle_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    float *uncertainty
    ) {
    float *uncertainty_copy = NULL;
    if (uncertainty) {
        uncertainty_copy = malloc(sizeof(float));
        if (uncertainty_copy) *uncertainty_copy = *uncertainty;
    }
    point_uncertainty_circle_t *result = point_uncertainty_circle_create_internal (
        shape,
        point,
        uncertainty_copy
        );
    if (!result) {
        free(uncertainty_copy);
    }
    return result;
}

void point_uncertainty_circle_free(point_uncertainty_circle_t *point_uncertainty_circle) {
    if(NULL == point_uncertainty_circle){
        return ;
    }
    if(point_uncertainty_circle->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "point_uncertainty_circle_free");
        return ;
    }
    listEntry_t *listEntry;
    if (point_uncertainty_circle->shape) {
        supported_gad_shapes_free(point_uncertainty_circle->shape);
        point_uncertainty_circle->shape = NULL;
    }
    if (point_uncertainty_circle->point) {
        geographical_coordinates_free(point_uncertainty_circle->point);
        point_uncertainty_circle->point = NULL;
    }
    if (point_uncertainty_circle->uncertainty) {
        free(point_uncertainty_circle->uncertainty);
        point_uncertainty_circle->uncertainty = NULL;
    }
    free(point_uncertainty_circle);
}

cJSON *point_uncertainty_circle_convertToJSON(point_uncertainty_circle_t *point_uncertainty_circle) {
    cJSON *item = cJSON_CreateObject();

    // point_uncertainty_circle->shape
    if (!point_uncertainty_circle->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(point_uncertainty_circle->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_uncertainty_circle->point
    if (!point_uncertainty_circle->point) {
        goto fail;
    }
    cJSON *point_local_JSON = geographical_coordinates_convertToJSON(point_uncertainty_circle->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_uncertainty_circle->uncertainty
    if (!point_uncertainty_circle->uncertainty) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "uncertainty", *point_uncertainty_circle->uncertainty) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

point_uncertainty_circle_t *point_uncertainty_circle_parseFromJSON(cJSON *point_uncertainty_circleJSON){

    point_uncertainty_circle_t *point_uncertainty_circle_local_var = NULL;

    // define the local variable for point_uncertainty_circle->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for point_uncertainty_circle->point
    geographical_coordinates_t *point_local_nonprim = NULL;

    // define the local variable for point_uncertainty_circle->uncertainty
    float *uncertainty_local_var = NULL;

    // point_uncertainty_circle->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(point_uncertainty_circleJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // point_uncertainty_circle->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(point_uncertainty_circleJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = geographical_coordinates_parseFromJSON(point); //nonprimitive

    // point_uncertainty_circle->uncertainty
    cJSON *uncertainty = cJSON_GetObjectItemCaseSensitive(point_uncertainty_circleJSON, "uncertainty");
    if (cJSON_IsNull(uncertainty)) {
        uncertainty = NULL;
    }
    if (!uncertainty) {
        goto end;
    }

    
    if(!cJSON_IsNumber(uncertainty))
    {
    goto end; //Numeric
    }
    uncertainty_local_var = malloc(sizeof(float));
    if(!uncertainty_local_var)
    {
        goto end;
    }
    *uncertainty_local_var = uncertainty->valuedouble;



    point_uncertainty_circle_local_var = point_uncertainty_circle_create_internal (
        shape_local_nonprim,
        point_local_nonprim,
        uncertainty_local_var
        );

    if (!point_uncertainty_circle_local_var) {
        goto end;
    }

    return point_uncertainty_circle_local_var;
end:
    if (shape_local_nonprim) {
        supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
    }
    if (point_local_nonprim) {
        geographical_coordinates_free(point_local_nonprim);
        point_local_nonprim = NULL;
    }
    if (uncertainty_local_var) {
        free(uncertainty_local_var);
        uncertainty_local_var = NULL;
    }
    return NULL;

}
