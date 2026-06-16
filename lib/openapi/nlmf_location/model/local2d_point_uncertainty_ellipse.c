#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local2d_point_uncertainty_ellipse.h"



static local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_create_internal(
    supported_gad_shapes_t *shape,
    local_origin_t *local_origin,
    relative_cartesian_location_t *point,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence
    ) {
    local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_local_var = malloc(sizeof(local2d_point_uncertainty_ellipse_t));
    if (!local2d_point_uncertainty_ellipse_local_var) {
        return NULL;
    }
    memset(local2d_point_uncertainty_ellipse_local_var, 0, sizeof(local2d_point_uncertainty_ellipse_t));
    local2d_point_uncertainty_ellipse_local_var->_library_owned = 1;
    local2d_point_uncertainty_ellipse_local_var->shape = shape;
    local2d_point_uncertainty_ellipse_local_var->local_origin = local_origin;
    local2d_point_uncertainty_ellipse_local_var->point = point;
    local2d_point_uncertainty_ellipse_local_var->uncertainty_ellipse = uncertainty_ellipse;
    local2d_point_uncertainty_ellipse_local_var->confidence = confidence;
    return local2d_point_uncertainty_ellipse_local_var;
}

__attribute__((deprecated)) local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_create(
    supported_gad_shapes_t *shape,
    local_origin_t *local_origin,
    relative_cartesian_location_t *point,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence
    ) {
    int *confidence_copy = NULL;
    if (confidence) {
        confidence_copy = malloc(sizeof(int));
        if (confidence_copy) *confidence_copy = *confidence;
    }
    local2d_point_uncertainty_ellipse_t *result = local2d_point_uncertainty_ellipse_create_internal (
        shape,
        local_origin,
        point,
        uncertainty_ellipse,
        confidence_copy
        );
    if (!result) {
        free(confidence_copy);
    }
    return result;
}

void local2d_point_uncertainty_ellipse_free(local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse) {
    if(NULL == local2d_point_uncertainty_ellipse){
        return ;
    }
    if(local2d_point_uncertainty_ellipse->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "local2d_point_uncertainty_ellipse_free");
        return ;
    }
    listEntry_t *listEntry;
    if (local2d_point_uncertainty_ellipse->shape) {
        supported_gad_shapes_free(local2d_point_uncertainty_ellipse->shape);
        local2d_point_uncertainty_ellipse->shape = NULL;
    }
    if (local2d_point_uncertainty_ellipse->local_origin) {
        local_origin_free(local2d_point_uncertainty_ellipse->local_origin);
        local2d_point_uncertainty_ellipse->local_origin = NULL;
    }
    if (local2d_point_uncertainty_ellipse->point) {
        relative_cartesian_location_free(local2d_point_uncertainty_ellipse->point);
        local2d_point_uncertainty_ellipse->point = NULL;
    }
    if (local2d_point_uncertainty_ellipse->uncertainty_ellipse) {
        uncertainty_ellipse_free(local2d_point_uncertainty_ellipse->uncertainty_ellipse);
        local2d_point_uncertainty_ellipse->uncertainty_ellipse = NULL;
    }
    if (local2d_point_uncertainty_ellipse->confidence) {
        free(local2d_point_uncertainty_ellipse->confidence);
        local2d_point_uncertainty_ellipse->confidence = NULL;
    }
    free(local2d_point_uncertainty_ellipse);
}

cJSON *local2d_point_uncertainty_ellipse_convertToJSON(local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse) {
    cJSON *item = cJSON_CreateObject();

    // local2d_point_uncertainty_ellipse->shape
    if (!local2d_point_uncertainty_ellipse->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(local2d_point_uncertainty_ellipse->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local2d_point_uncertainty_ellipse->local_origin
    if (!local2d_point_uncertainty_ellipse->local_origin) {
        goto fail;
    }
    cJSON *local_origin_local_JSON = local_origin_convertToJSON(local2d_point_uncertainty_ellipse->local_origin);
    if(local_origin_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "localOrigin", local_origin_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local2d_point_uncertainty_ellipse->point
    if (!local2d_point_uncertainty_ellipse->point) {
        goto fail;
    }
    cJSON *point_local_JSON = relative_cartesian_location_convertToJSON(local2d_point_uncertainty_ellipse->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local2d_point_uncertainty_ellipse->uncertainty_ellipse
    if (!local2d_point_uncertainty_ellipse->uncertainty_ellipse) {
        goto fail;
    }
    cJSON *uncertainty_ellipse_local_JSON = uncertainty_ellipse_convertToJSON(local2d_point_uncertainty_ellipse->uncertainty_ellipse);
    if(uncertainty_ellipse_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "uncertaintyEllipse", uncertainty_ellipse_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local2d_point_uncertainty_ellipse->confidence
    if (!local2d_point_uncertainty_ellipse->confidence) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "confidence", *local2d_point_uncertainty_ellipse->confidence) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_parseFromJSON(cJSON *local2d_point_uncertainty_ellipseJSON){

    local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_local_var = NULL;

    // define the local variable for local2d_point_uncertainty_ellipse->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for local2d_point_uncertainty_ellipse->local_origin
    local_origin_t *local_origin_local_nonprim = NULL;

    // define the local variable for local2d_point_uncertainty_ellipse->point
    relative_cartesian_location_t *point_local_nonprim = NULL;

    // define the local variable for local2d_point_uncertainty_ellipse->uncertainty_ellipse
    uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;

    // define the local variable for local2d_point_uncertainty_ellipse->confidence
    int *confidence_local_var = NULL;

    // local2d_point_uncertainty_ellipse->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(local2d_point_uncertainty_ellipseJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // local2d_point_uncertainty_ellipse->local_origin
    cJSON *local_origin = cJSON_GetObjectItemCaseSensitive(local2d_point_uncertainty_ellipseJSON, "localOrigin");
    if (cJSON_IsNull(local_origin)) {
        local_origin = NULL;
    }
    if (!local_origin) {
        goto end;
    }

    
    local_origin_local_nonprim = local_origin_parseFromJSON(local_origin); //nonprimitive

    // local2d_point_uncertainty_ellipse->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(local2d_point_uncertainty_ellipseJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = relative_cartesian_location_parseFromJSON(point); //nonprimitive

    // local2d_point_uncertainty_ellipse->uncertainty_ellipse
    cJSON *uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(local2d_point_uncertainty_ellipseJSON, "uncertaintyEllipse");
    if (cJSON_IsNull(uncertainty_ellipse)) {
        uncertainty_ellipse = NULL;
    }
    if (!uncertainty_ellipse) {
        goto end;
    }

    
    uncertainty_ellipse_local_nonprim = uncertainty_ellipse_parseFromJSON(uncertainty_ellipse); //nonprimitive

    // local2d_point_uncertainty_ellipse->confidence
    cJSON *confidence = cJSON_GetObjectItemCaseSensitive(local2d_point_uncertainty_ellipseJSON, "confidence");
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



    local2d_point_uncertainty_ellipse_local_var = local2d_point_uncertainty_ellipse_create_internal (
        shape_local_nonprim,
        local_origin_local_nonprim,
        point_local_nonprim,
        uncertainty_ellipse_local_nonprim,
        confidence_local_var
        );

    if (!local2d_point_uncertainty_ellipse_local_var) {
        goto end;
    }

    return local2d_point_uncertainty_ellipse_local_var;
end:
    if (shape_local_nonprim) {
        supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
    }
    if (local_origin_local_nonprim) {
        local_origin_free(local_origin_local_nonprim);
        local_origin_local_nonprim = NULL;
    }
    if (point_local_nonprim) {
        relative_cartesian_location_free(point_local_nonprim);
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
