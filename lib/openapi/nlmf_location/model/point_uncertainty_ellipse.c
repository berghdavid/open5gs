#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_uncertainty_ellipse.h"



static point_uncertainty_ellipse_t *point_uncertainty_ellipse_create_internal(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence
    ) {
    point_uncertainty_ellipse_t *point_uncertainty_ellipse_local_var = malloc(sizeof(point_uncertainty_ellipse_t));
    if (!point_uncertainty_ellipse_local_var) {
        return NULL;
    }
    memset(point_uncertainty_ellipse_local_var, 0, sizeof(point_uncertainty_ellipse_t));
    point_uncertainty_ellipse_local_var->_library_owned = 1;
    point_uncertainty_ellipse_local_var->shape = shape;
    point_uncertainty_ellipse_local_var->point = point;
    point_uncertainty_ellipse_local_var->uncertainty_ellipse = uncertainty_ellipse;
    point_uncertainty_ellipse_local_var->confidence = confidence;
    return point_uncertainty_ellipse_local_var;
}

__attribute__((deprecated)) point_uncertainty_ellipse_t *point_uncertainty_ellipse_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence
    ) {
    int *confidence_copy = NULL;
    if (confidence) {
        confidence_copy = malloc(sizeof(int));
        if (confidence_copy) *confidence_copy = *confidence;
    }
    point_uncertainty_ellipse_t *result = point_uncertainty_ellipse_create_internal (
        shape,
        point,
        uncertainty_ellipse,
        confidence_copy
        );
    if (!result) {
        free(confidence_copy);
    }
    return result;
}

void point_uncertainty_ellipse_free(point_uncertainty_ellipse_t *point_uncertainty_ellipse) {
    if(NULL == point_uncertainty_ellipse){
        return ;
    }
    if(point_uncertainty_ellipse->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "point_uncertainty_ellipse_free");
        return ;
    }
    listEntry_t *listEntry;
    if (point_uncertainty_ellipse->shape) {
        supported_gad_shapes_free(point_uncertainty_ellipse->shape);
        point_uncertainty_ellipse->shape = NULL;
    }
    if (point_uncertainty_ellipse->point) {
        geographical_coordinates_free(point_uncertainty_ellipse->point);
        point_uncertainty_ellipse->point = NULL;
    }
    if (point_uncertainty_ellipse->uncertainty_ellipse) {
        uncertainty_ellipse_free(point_uncertainty_ellipse->uncertainty_ellipse);
        point_uncertainty_ellipse->uncertainty_ellipse = NULL;
    }
    if (point_uncertainty_ellipse->confidence) {
        free(point_uncertainty_ellipse->confidence);
        point_uncertainty_ellipse->confidence = NULL;
    }
    free(point_uncertainty_ellipse);
}

cJSON *point_uncertainty_ellipse_convertToJSON(point_uncertainty_ellipse_t *point_uncertainty_ellipse) {
    cJSON *item = cJSON_CreateObject();

    // point_uncertainty_ellipse->shape
    if (!point_uncertainty_ellipse->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(point_uncertainty_ellipse->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_uncertainty_ellipse->point
    if (!point_uncertainty_ellipse->point) {
        goto fail;
    }
    cJSON *point_local_JSON = geographical_coordinates_convertToJSON(point_uncertainty_ellipse->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_uncertainty_ellipse->uncertainty_ellipse
    if (!point_uncertainty_ellipse->uncertainty_ellipse) {
        goto fail;
    }
    cJSON *uncertainty_ellipse_local_JSON = uncertainty_ellipse_convertToJSON(point_uncertainty_ellipse->uncertainty_ellipse);
    if(uncertainty_ellipse_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "uncertaintyEllipse", uncertainty_ellipse_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_uncertainty_ellipse->confidence
    if (!point_uncertainty_ellipse->confidence) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "confidence", *point_uncertainty_ellipse->confidence) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

point_uncertainty_ellipse_t *point_uncertainty_ellipse_parseFromJSON(cJSON *point_uncertainty_ellipseJSON){

    point_uncertainty_ellipse_t *point_uncertainty_ellipse_local_var = NULL;

    // define the local variable for point_uncertainty_ellipse->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for point_uncertainty_ellipse->point
    geographical_coordinates_t *point_local_nonprim = NULL;

    // define the local variable for point_uncertainty_ellipse->uncertainty_ellipse
    uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;

    // define the local variable for point_uncertainty_ellipse->confidence
    int *confidence_local_var = NULL;

    // point_uncertainty_ellipse->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(point_uncertainty_ellipseJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // point_uncertainty_ellipse->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(point_uncertainty_ellipseJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = geographical_coordinates_parseFromJSON(point); //nonprimitive

    // point_uncertainty_ellipse->uncertainty_ellipse
    cJSON *uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(point_uncertainty_ellipseJSON, "uncertaintyEllipse");
    if (cJSON_IsNull(uncertainty_ellipse)) {
        uncertainty_ellipse = NULL;
    }
    if (!uncertainty_ellipse) {
        goto end;
    }

    
    uncertainty_ellipse_local_nonprim = uncertainty_ellipse_parseFromJSON(uncertainty_ellipse); //nonprimitive

    // point_uncertainty_ellipse->confidence
    cJSON *confidence = cJSON_GetObjectItemCaseSensitive(point_uncertainty_ellipseJSON, "confidence");
    if (cJSON_IsNull(confidence)) {
        confidence = NULL;
    }
    if (!confidence) {
        goto end;
    }

    
    if(!cJSON_IsNumber(confidence))
    {
    goto end; //Numeric
    }
    confidence_local_var = malloc(sizeof(int));
    if(!confidence_local_var)
    {
        goto end;
    }
    *confidence_local_var = confidence->valuedouble;



    point_uncertainty_ellipse_local_var = point_uncertainty_ellipse_create_internal (
        shape_local_nonprim,
        point_local_nonprim,
        uncertainty_ellipse_local_nonprim,
        confidence_local_var
        );

    if (!point_uncertainty_ellipse_local_var) {
        goto end;
    }

    return point_uncertainty_ellipse_local_var;
end:
    if (shape_local_nonprim) {
        supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
    }
    if (point_local_nonprim) {
        geographical_coordinates_free(point_local_nonprim);
        point_local_nonprim = NULL;
    }
    if (uncertainty_ellipse_local_nonprim) {
        uncertainty_ellipse_free(uncertainty_ellipse_local_nonprim);
        uncertainty_ellipse_local_nonprim = NULL;
    }
    if (confidence_local_var) {
        free(confidence_local_var);
        confidence_local_var = NULL;
    }
    return NULL;

}
