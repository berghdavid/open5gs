#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local3d_point_uncertainty_ellipsoid.h"



static local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid_create_internal(
    supported_gad_shapes_t *shape,
    local_origin_t *local_origin,
    relative_cartesian_location_t *point,
    uncertainty_ellipsoid_t *uncertainty_ellipsoid,
    int *confidence,
    int *v_confidence
    ) {
    local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid_local_var = malloc(sizeof(local3d_point_uncertainty_ellipsoid_t));
    if (!local3d_point_uncertainty_ellipsoid_local_var) {
        return NULL;
    }
    memset(local3d_point_uncertainty_ellipsoid_local_var, 0, sizeof(local3d_point_uncertainty_ellipsoid_t));
    local3d_point_uncertainty_ellipsoid_local_var->_library_owned = 1;
    local3d_point_uncertainty_ellipsoid_local_var->shape = shape;
    local3d_point_uncertainty_ellipsoid_local_var->local_origin = local_origin;
    local3d_point_uncertainty_ellipsoid_local_var->point = point;
    local3d_point_uncertainty_ellipsoid_local_var->uncertainty_ellipsoid = uncertainty_ellipsoid;
    local3d_point_uncertainty_ellipsoid_local_var->confidence = confidence;
    local3d_point_uncertainty_ellipsoid_local_var->v_confidence = v_confidence;
    return local3d_point_uncertainty_ellipsoid_local_var;
}

__attribute__((deprecated)) local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid_create(
    supported_gad_shapes_t *shape,
    local_origin_t *local_origin,
    relative_cartesian_location_t *point,
    uncertainty_ellipsoid_t *uncertainty_ellipsoid,
    int *confidence,
    int *v_confidence
    ) {
    int *confidence_copy = NULL;
    if (confidence) {
        confidence_copy = malloc(sizeof(int));
        if (confidence_copy) *confidence_copy = *confidence;
    }
    int *v_confidence_copy = NULL;
    if (v_confidence) {
        v_confidence_copy = malloc(sizeof(int));
        if (v_confidence_copy) *v_confidence_copy = *v_confidence;
    }
    local3d_point_uncertainty_ellipsoid_t *result = local3d_point_uncertainty_ellipsoid_create_internal (
        shape,
        local_origin,
        point,
        uncertainty_ellipsoid,
        confidence_copy,
        v_confidence_copy
        );
    if (!result) {
        free(confidence_copy);
        free(v_confidence_copy);
    }
    return result;
}

void local3d_point_uncertainty_ellipsoid_free(local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid) {
    if(NULL == local3d_point_uncertainty_ellipsoid){
        return ;
    }
    if(local3d_point_uncertainty_ellipsoid->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "local3d_point_uncertainty_ellipsoid_free");
        return ;
    }
    listEntry_t *listEntry;
    if (local3d_point_uncertainty_ellipsoid->shape) {
        supported_gad_shapes_free(local3d_point_uncertainty_ellipsoid->shape);
        local3d_point_uncertainty_ellipsoid->shape = NULL;
    }
    if (local3d_point_uncertainty_ellipsoid->local_origin) {
        local_origin_free(local3d_point_uncertainty_ellipsoid->local_origin);
        local3d_point_uncertainty_ellipsoid->local_origin = NULL;
    }
    if (local3d_point_uncertainty_ellipsoid->point) {
        relative_cartesian_location_free(local3d_point_uncertainty_ellipsoid->point);
        local3d_point_uncertainty_ellipsoid->point = NULL;
    }
    if (local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid) {
        uncertainty_ellipsoid_free(local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid);
        local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid = NULL;
    }
    if (local3d_point_uncertainty_ellipsoid->confidence) {
        free(local3d_point_uncertainty_ellipsoid->confidence);
        local3d_point_uncertainty_ellipsoid->confidence = NULL;
    }
    if (local3d_point_uncertainty_ellipsoid->v_confidence) {
        free(local3d_point_uncertainty_ellipsoid->v_confidence);
        local3d_point_uncertainty_ellipsoid->v_confidence = NULL;
    }
    free(local3d_point_uncertainty_ellipsoid);
}

cJSON *local3d_point_uncertainty_ellipsoid_convertToJSON(local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid) {
    cJSON *item = cJSON_CreateObject();

    // local3d_point_uncertainty_ellipsoid->shape
    if (!local3d_point_uncertainty_ellipsoid->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(local3d_point_uncertainty_ellipsoid->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local3d_point_uncertainty_ellipsoid->local_origin
    if (!local3d_point_uncertainty_ellipsoid->local_origin) {
        goto fail;
    }
    cJSON *local_origin_local_JSON = local_origin_convertToJSON(local3d_point_uncertainty_ellipsoid->local_origin);
    if(local_origin_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "localOrigin", local_origin_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local3d_point_uncertainty_ellipsoid->point
    if (!local3d_point_uncertainty_ellipsoid->point) {
        goto fail;
    }
    cJSON *point_local_JSON = relative_cartesian_location_convertToJSON(local3d_point_uncertainty_ellipsoid->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid
    if (!local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid) {
        goto fail;
    }
    cJSON *uncertainty_ellipsoid_local_JSON = uncertainty_ellipsoid_convertToJSON(local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid);
    if(uncertainty_ellipsoid_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "uncertaintyEllipsoid", uncertainty_ellipsoid_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local3d_point_uncertainty_ellipsoid->confidence
    if (!local3d_point_uncertainty_ellipsoid->confidence) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "confidence", *local3d_point_uncertainty_ellipsoid->confidence) == NULL) {
    goto fail; //Numeric
    }


    // local3d_point_uncertainty_ellipsoid->v_confidence
    if(local3d_point_uncertainty_ellipsoid->v_confidence) {
    if(cJSON_AddNumberToObject(item, "vConfidence", *local3d_point_uncertainty_ellipsoid->v_confidence) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid_parseFromJSON(cJSON *local3d_point_uncertainty_ellipsoidJSON){

    local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid_local_var = NULL;

    // define the local variable for local3d_point_uncertainty_ellipsoid->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for local3d_point_uncertainty_ellipsoid->local_origin
    local_origin_t *local_origin_local_nonprim = NULL;

    // define the local variable for local3d_point_uncertainty_ellipsoid->point
    relative_cartesian_location_t *point_local_nonprim = NULL;

    // define the local variable for local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid
    uncertainty_ellipsoid_t *uncertainty_ellipsoid_local_nonprim = NULL;

    // define the local variable for local3d_point_uncertainty_ellipsoid->confidence
    int *confidence_local_var = NULL;

    // define the local variable for local3d_point_uncertainty_ellipsoid->v_confidence
    int *v_confidence_local_var = NULL;

    // local3d_point_uncertainty_ellipsoid->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(local3d_point_uncertainty_ellipsoidJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // local3d_point_uncertainty_ellipsoid->local_origin
    cJSON *local_origin = cJSON_GetObjectItemCaseSensitive(local3d_point_uncertainty_ellipsoidJSON, "localOrigin");
    if (cJSON_IsNull(local_origin)) {
        local_origin = NULL;
    }
    if (!local_origin) {
        goto end;
    }

    
    local_origin_local_nonprim = local_origin_parseFromJSON(local_origin); //nonprimitive

    // local3d_point_uncertainty_ellipsoid->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(local3d_point_uncertainty_ellipsoidJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = relative_cartesian_location_parseFromJSON(point); //nonprimitive

    // local3d_point_uncertainty_ellipsoid->uncertainty_ellipsoid
    cJSON *uncertainty_ellipsoid = cJSON_GetObjectItemCaseSensitive(local3d_point_uncertainty_ellipsoidJSON, "uncertaintyEllipsoid");
    if (cJSON_IsNull(uncertainty_ellipsoid)) {
        uncertainty_ellipsoid = NULL;
    }
    if (!uncertainty_ellipsoid) {
        goto end;
    }

    
    uncertainty_ellipsoid_local_nonprim = uncertainty_ellipsoid_parseFromJSON(uncertainty_ellipsoid); //nonprimitive

    // local3d_point_uncertainty_ellipsoid->confidence
    cJSON *confidence = cJSON_GetObjectItemCaseSensitive(local3d_point_uncertainty_ellipsoidJSON, "confidence");
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

    // local3d_point_uncertainty_ellipsoid->v_confidence
    cJSON *v_confidence = cJSON_GetObjectItemCaseSensitive(local3d_point_uncertainty_ellipsoidJSON, "vConfidence");
    if (cJSON_IsNull(v_confidence)) {
        v_confidence = NULL;
    }
    if (v_confidence) { 
    if(!cJSON_IsNumber(v_confidence))
    {
    goto end; //Numeric
    }
    v_confidence_local_var = malloc(sizeof(int));
    if(!v_confidence_local_var)
    {
        goto end;
    }
    *v_confidence_local_var = v_confidence->valuedouble;
    }



    local3d_point_uncertainty_ellipsoid_local_var = local3d_point_uncertainty_ellipsoid_create_internal (
        shape_local_nonprim,
        local_origin_local_nonprim,
        point_local_nonprim,
        uncertainty_ellipsoid_local_nonprim,
        confidence_local_var,
        v_confidence_local_var
        );

    if (!local3d_point_uncertainty_ellipsoid_local_var) {
        goto end;
    }

    return local3d_point_uncertainty_ellipsoid_local_var;
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
    if (uncertainty_ellipsoid_local_nonprim) {
        uncertainty_ellipsoid_free(uncertainty_ellipsoid_local_nonprim);
        uncertainty_ellipsoid_local_nonprim = NULL;
    }
    if (confidence_local_var) {
        free(confidence_local_var);
        confidence_local_var = NULL;
    }
    if (v_confidence_local_var) {
        free(v_confidence_local_var);
        v_confidence_local_var = NULL;
    }
    return NULL;

}
