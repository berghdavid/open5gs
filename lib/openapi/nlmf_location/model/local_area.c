#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local_area.h"



static local_area_t *local_area_create_internal(
    supported_gad_shapes_t *shape,
    local_origin_t *local_origin,
    relative_cartesian_location_t *point,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence,
    uncertainty_ellipsoid_t *uncertainty_ellipsoid,
    int *v_confidence
    ) {
    local_area_t *local_area_local_var = malloc(sizeof(local_area_t));
    if (!local_area_local_var) {
        return NULL;
    }
    memset(local_area_local_var, 0, sizeof(local_area_t));
    local_area_local_var->_library_owned = 1;
    local_area_local_var->shape = shape;
    local_area_local_var->local_origin = local_origin;
    local_area_local_var->point = point;
    local_area_local_var->uncertainty_ellipse = uncertainty_ellipse;
    local_area_local_var->confidence = confidence;
    local_area_local_var->uncertainty_ellipsoid = uncertainty_ellipsoid;
    local_area_local_var->v_confidence = v_confidence;
    return local_area_local_var;
}

__attribute__((deprecated)) local_area_t *local_area_create(
    supported_gad_shapes_t *shape,
    local_origin_t *local_origin,
    relative_cartesian_location_t *point,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence,
    uncertainty_ellipsoid_t *uncertainty_ellipsoid,
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
    local_area_t *result = local_area_create_internal (
        shape,
        local_origin,
        point,
        uncertainty_ellipse,
        confidence_copy,
        uncertainty_ellipsoid,
        v_confidence_copy
        );
    if (!result) {
        free(confidence_copy);
        free(v_confidence_copy);
    }
    return result;
}

void local_area_free(local_area_t *local_area) {
    if(NULL == local_area){
        return ;
    }
    if(local_area->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "local_area_free");
        return ;
    }
    listEntry_t *listEntry;
    if (local_area->shape) {
        supported_gad_shapes_free(local_area->shape);
        local_area->shape = NULL;
    }
    if (local_area->local_origin) {
        local_origin_free(local_area->local_origin);
        local_area->local_origin = NULL;
    }
    if (local_area->point) {
        relative_cartesian_location_free(local_area->point);
        local_area->point = NULL;
    }
    if (local_area->uncertainty_ellipse) {
        uncertainty_ellipse_free(local_area->uncertainty_ellipse);
        local_area->uncertainty_ellipse = NULL;
    }
    if (local_area->confidence) {
        free(local_area->confidence);
        local_area->confidence = NULL;
    }
    if (local_area->uncertainty_ellipsoid) {
        uncertainty_ellipsoid_free(local_area->uncertainty_ellipsoid);
        local_area->uncertainty_ellipsoid = NULL;
    }
    if (local_area->v_confidence) {
        free(local_area->v_confidence);
        local_area->v_confidence = NULL;
    }
    free(local_area);
}

cJSON *local_area_convertToJSON(local_area_t *local_area) {
    cJSON *item = cJSON_CreateObject();

    // local_area->shape
    if (!local_area->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(local_area->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local_area->local_origin
    if (!local_area->local_origin) {
        goto fail;
    }
    cJSON *local_origin_local_JSON = local_origin_convertToJSON(local_area->local_origin);
    if(local_origin_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "localOrigin", local_origin_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local_area->point
    if (!local_area->point) {
        goto fail;
    }
    cJSON *point_local_JSON = relative_cartesian_location_convertToJSON(local_area->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local_area->uncertainty_ellipse
    if (!local_area->uncertainty_ellipse) {
        goto fail;
    }
    cJSON *uncertainty_ellipse_local_JSON = uncertainty_ellipse_convertToJSON(local_area->uncertainty_ellipse);
    if(uncertainty_ellipse_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "uncertaintyEllipse", uncertainty_ellipse_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local_area->confidence
    if (!local_area->confidence) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "confidence", *local_area->confidence) == NULL) {
    goto fail; //Numeric
    }


    // local_area->uncertainty_ellipsoid
    if (!local_area->uncertainty_ellipsoid) {
        goto fail;
    }
    cJSON *uncertainty_ellipsoid_local_JSON = uncertainty_ellipsoid_convertToJSON(local_area->uncertainty_ellipsoid);
    if(uncertainty_ellipsoid_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "uncertaintyEllipsoid", uncertainty_ellipsoid_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // local_area->v_confidence
    if(local_area->v_confidence) {
    if(cJSON_AddNumberToObject(item, "vConfidence", *local_area->v_confidence) == NULL) {
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

local_area_t *local_area_parseFromJSON(cJSON *local_areaJSON){

    local_area_t *local_area_local_var = NULL;

    // define the local variable for local_area->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for local_area->local_origin
    local_origin_t *local_origin_local_nonprim = NULL;

    // define the local variable for local_area->point
    relative_cartesian_location_t *point_local_nonprim = NULL;

    // define the local variable for local_area->uncertainty_ellipse
    uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;

    // define the local variable for local_area->confidence
    int *confidence_local_var = NULL;

    // define the local variable for local_area->uncertainty_ellipsoid
    uncertainty_ellipsoid_t *uncertainty_ellipsoid_local_nonprim = NULL;

    // define the local variable for local_area->v_confidence
    int *v_confidence_local_var = NULL;

    // local_area->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(local_areaJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // local_area->local_origin
    cJSON *local_origin = cJSON_GetObjectItemCaseSensitive(local_areaJSON, "localOrigin");
    if (cJSON_IsNull(local_origin)) {
        local_origin = NULL;
    }
    if (!local_origin) {
        goto end;
    }

    
    local_origin_local_nonprim = local_origin_parseFromJSON(local_origin); //nonprimitive

    // local_area->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(local_areaJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = relative_cartesian_location_parseFromJSON(point); //nonprimitive

    // local_area->uncertainty_ellipse
    cJSON *uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(local_areaJSON, "uncertaintyEllipse");
    if (cJSON_IsNull(uncertainty_ellipse)) {
        uncertainty_ellipse = NULL;
    }
    if (!uncertainty_ellipse) {
        goto end;
    }

    
    uncertainty_ellipse_local_nonprim = uncertainty_ellipse_parseFromJSON(uncertainty_ellipse); //nonprimitive

    // local_area->confidence
    cJSON *confidence = cJSON_GetObjectItemCaseSensitive(local_areaJSON, "confidence");
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

    // local_area->uncertainty_ellipsoid
    cJSON *uncertainty_ellipsoid = cJSON_GetObjectItemCaseSensitive(local_areaJSON, "uncertaintyEllipsoid");
    if (cJSON_IsNull(uncertainty_ellipsoid)) {
        uncertainty_ellipsoid = NULL;
    }
    if (!uncertainty_ellipsoid) {
        goto end;
    }

    
    uncertainty_ellipsoid_local_nonprim = uncertainty_ellipsoid_parseFromJSON(uncertainty_ellipsoid); //nonprimitive

    // local_area->v_confidence
    cJSON *v_confidence = cJSON_GetObjectItemCaseSensitive(local_areaJSON, "vConfidence");
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



    local_area_local_var = local_area_create_internal (
        shape_local_nonprim,
        local_origin_local_nonprim,
        point_local_nonprim,
        uncertainty_ellipse_local_nonprim,
        confidence_local_var,
        uncertainty_ellipsoid_local_nonprim,
        v_confidence_local_var
        );

    if (!local_area_local_var) {
        goto end;
    }

    return local_area_local_var;
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
    if (uncertainty_ellipsoid_local_nonprim) {
        uncertainty_ellipsoid_free(uncertainty_ellipsoid_local_nonprim);
        uncertainty_ellipsoid_local_nonprim = NULL;
    }
    if (v_confidence_local_var) {
        free(v_confidence_local_var);
        v_confidence_local_var = NULL;
    }
    return NULL;

}
