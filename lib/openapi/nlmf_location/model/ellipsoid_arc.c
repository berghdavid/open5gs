#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ellipsoid_arc.h"



static ellipsoid_arc_t *ellipsoid_arc_create_internal(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    int *inner_radius,
    float *uncertainty_radius,
    int *offset_angle,
    int *included_angle,
    int *confidence
    ) {
    ellipsoid_arc_t *ellipsoid_arc_local_var = malloc(sizeof(ellipsoid_arc_t));
    if (!ellipsoid_arc_local_var) {
        return NULL;
    }
    memset(ellipsoid_arc_local_var, 0, sizeof(ellipsoid_arc_t));
    ellipsoid_arc_local_var->_library_owned = 1;
    ellipsoid_arc_local_var->shape = shape;
    ellipsoid_arc_local_var->point = point;
    ellipsoid_arc_local_var->inner_radius = inner_radius;
    ellipsoid_arc_local_var->uncertainty_radius = uncertainty_radius;
    ellipsoid_arc_local_var->offset_angle = offset_angle;
    ellipsoid_arc_local_var->included_angle = included_angle;
    ellipsoid_arc_local_var->confidence = confidence;
    return ellipsoid_arc_local_var;
}

__attribute__((deprecated)) ellipsoid_arc_t *ellipsoid_arc_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    int *inner_radius,
    float *uncertainty_radius,
    int *offset_angle,
    int *included_angle,
    int *confidence
    ) {
    int *inner_radius_copy = NULL;
    if (inner_radius) {
        inner_radius_copy = malloc(sizeof(int));
        if (inner_radius_copy) *inner_radius_copy = *inner_radius;
    }
    float *uncertainty_radius_copy = NULL;
    if (uncertainty_radius) {
        uncertainty_radius_copy = malloc(sizeof(float));
        if (uncertainty_radius_copy) *uncertainty_radius_copy = *uncertainty_radius;
    }
    int *offset_angle_copy = NULL;
    if (offset_angle) {
        offset_angle_copy = malloc(sizeof(int));
        if (offset_angle_copy) *offset_angle_copy = *offset_angle;
    }
    int *included_angle_copy = NULL;
    if (included_angle) {
        included_angle_copy = malloc(sizeof(int));
        if (included_angle_copy) *included_angle_copy = *included_angle;
    }
    int *confidence_copy = NULL;
    if (confidence) {
        confidence_copy = malloc(sizeof(int));
        if (confidence_copy) *confidence_copy = *confidence;
    }
    ellipsoid_arc_t *result = ellipsoid_arc_create_internal (
        shape,
        point,
        inner_radius_copy,
        uncertainty_radius_copy,
        offset_angle_copy,
        included_angle_copy,
        confidence_copy
        );
    if (!result) {
        free(inner_radius_copy);
        free(uncertainty_radius_copy);
        free(offset_angle_copy);
        free(included_angle_copy);
        free(confidence_copy);
    }
    return result;
}

void ellipsoid_arc_free(ellipsoid_arc_t *ellipsoid_arc) {
    if(NULL == ellipsoid_arc){
        return ;
    }
    if(ellipsoid_arc->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ellipsoid_arc_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ellipsoid_arc->shape) {
        supported_gad_shapes_free(ellipsoid_arc->shape);
        ellipsoid_arc->shape = NULL;
    }
    if (ellipsoid_arc->point) {
        geographical_coordinates_free(ellipsoid_arc->point);
        ellipsoid_arc->point = NULL;
    }
    if (ellipsoid_arc->inner_radius) {
        free(ellipsoid_arc->inner_radius);
        ellipsoid_arc->inner_radius = NULL;
    }
    if (ellipsoid_arc->uncertainty_radius) {
        free(ellipsoid_arc->uncertainty_radius);
        ellipsoid_arc->uncertainty_radius = NULL;
    }
    if (ellipsoid_arc->offset_angle) {
        free(ellipsoid_arc->offset_angle);
        ellipsoid_arc->offset_angle = NULL;
    }
    if (ellipsoid_arc->included_angle) {
        free(ellipsoid_arc->included_angle);
        ellipsoid_arc->included_angle = NULL;
    }
    if (ellipsoid_arc->confidence) {
        free(ellipsoid_arc->confidence);
        ellipsoid_arc->confidence = NULL;
    }
    free(ellipsoid_arc);
}

cJSON *ellipsoid_arc_convertToJSON(ellipsoid_arc_t *ellipsoid_arc) {
    cJSON *item = cJSON_CreateObject();

    // ellipsoid_arc->shape
    if (!ellipsoid_arc->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(ellipsoid_arc->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ellipsoid_arc->point
    if (!ellipsoid_arc->point) {
        goto fail;
    }
    cJSON *point_local_JSON = geographical_coordinates_convertToJSON(ellipsoid_arc->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ellipsoid_arc->inner_radius
    if (!ellipsoid_arc->inner_radius) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "innerRadius", *ellipsoid_arc->inner_radius) == NULL) {
    goto fail; //Numeric
    }


    // ellipsoid_arc->uncertainty_radius
    if (!ellipsoid_arc->uncertainty_radius) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "uncertaintyRadius", *ellipsoid_arc->uncertainty_radius) == NULL) {
    goto fail; //Numeric
    }


    // ellipsoid_arc->offset_angle
    if (!ellipsoid_arc->offset_angle) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offsetAngle", *ellipsoid_arc->offset_angle) == NULL) {
    goto fail; //Numeric
    }


    // ellipsoid_arc->included_angle
    if (!ellipsoid_arc->included_angle) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "includedAngle", *ellipsoid_arc->included_angle) == NULL) {
    goto fail; //Numeric
    }


    // ellipsoid_arc->confidence
    if (!ellipsoid_arc->confidence) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "confidence", *ellipsoid_arc->confidence) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ellipsoid_arc_t *ellipsoid_arc_parseFromJSON(cJSON *ellipsoid_arcJSON){

    ellipsoid_arc_t *ellipsoid_arc_local_var = NULL;

    // define the local variable for ellipsoid_arc->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for ellipsoid_arc->point
    geographical_coordinates_t *point_local_nonprim = NULL;

    // define the local variable for ellipsoid_arc->inner_radius
    int *inner_radius_local_var = NULL;

    // define the local variable for ellipsoid_arc->uncertainty_radius
    float *uncertainty_radius_local_var = NULL;

    // define the local variable for ellipsoid_arc->offset_angle
    int *offset_angle_local_var = NULL;

    // define the local variable for ellipsoid_arc->included_angle
    int *included_angle_local_var = NULL;

    // define the local variable for ellipsoid_arc->confidence
    int *confidence_local_var = NULL;

    // ellipsoid_arc->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(ellipsoid_arcJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // ellipsoid_arc->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(ellipsoid_arcJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = geographical_coordinates_parseFromJSON(point); //nonprimitive

    // ellipsoid_arc->inner_radius
    cJSON *inner_radius = cJSON_GetObjectItemCaseSensitive(ellipsoid_arcJSON, "innerRadius");
    if (cJSON_IsNull(inner_radius)) {
        inner_radius = NULL;
    }
    if (!inner_radius) {
        goto end;
    }

    
    if(!cJSON_IsNumber(inner_radius))
    {
    goto end; //Numeric
    }
    inner_radius_local_var = malloc(sizeof(int));
    if(!inner_radius_local_var)
    {
        goto end;
    }
    *inner_radius_local_var = inner_radius->valuedouble;

    // ellipsoid_arc->uncertainty_radius
    cJSON *uncertainty_radius = cJSON_GetObjectItemCaseSensitive(ellipsoid_arcJSON, "uncertaintyRadius");
    if (cJSON_IsNull(uncertainty_radius)) {
        uncertainty_radius = NULL;
    }
    if (!uncertainty_radius) {
        goto end;
    }

    
    if(!cJSON_IsNumber(uncertainty_radius))
    {
    goto end; //Numeric
    }
    uncertainty_radius_local_var = malloc(sizeof(float));
    if(!uncertainty_radius_local_var)
    {
        goto end;
    }
    *uncertainty_radius_local_var = uncertainty_radius->valuedouble;

    // ellipsoid_arc->offset_angle
    cJSON *offset_angle = cJSON_GetObjectItemCaseSensitive(ellipsoid_arcJSON, "offsetAngle");
    if (cJSON_IsNull(offset_angle)) {
        offset_angle = NULL;
    }
    if (!offset_angle) {
        goto end;
    }

    
    if(!cJSON_IsNumber(offset_angle))
    {
    goto end; //Numeric
    }
    offset_angle_local_var = malloc(sizeof(int));
    if(!offset_angle_local_var)
    {
        goto end;
    }
    *offset_angle_local_var = offset_angle->valuedouble;

    // ellipsoid_arc->included_angle
    cJSON *included_angle = cJSON_GetObjectItemCaseSensitive(ellipsoid_arcJSON, "includedAngle");
    if (cJSON_IsNull(included_angle)) {
        included_angle = NULL;
    }
    if (!included_angle) {
        goto end;
    }

    
    if(!cJSON_IsNumber(included_angle))
    {
    goto end; //Numeric
    }
    included_angle_local_var = malloc(sizeof(int));
    if(!included_angle_local_var)
    {
        goto end;
    }
    *included_angle_local_var = included_angle->valuedouble;

    // ellipsoid_arc->confidence
    cJSON *confidence = cJSON_GetObjectItemCaseSensitive(ellipsoid_arcJSON, "confidence");
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



    ellipsoid_arc_local_var = ellipsoid_arc_create_internal (
        shape_local_nonprim,
        point_local_nonprim,
        inner_radius_local_var,
        uncertainty_radius_local_var,
        offset_angle_local_var,
        included_angle_local_var,
        confidence_local_var
        );

    if (!ellipsoid_arc_local_var) {
        goto end;
    }

    return ellipsoid_arc_local_var;
end:
    if (shape_local_nonprim) {
        supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
    }
    if (point_local_nonprim) {
        geographical_coordinates_free(point_local_nonprim);
        point_local_nonprim = NULL;
    }
    if (inner_radius_local_var) {
        free(inner_radius_local_var);
        inner_radius_local_var = NULL;
    }
    if (uncertainty_radius_local_var) {
        free(uncertainty_radius_local_var);
        uncertainty_radius_local_var = NULL;
    }
    if (offset_angle_local_var) {
        free(offset_angle_local_var);
        offset_angle_local_var = NULL;
    }
    if (included_angle_local_var) {
        free(included_angle_local_var);
        included_angle_local_var = NULL;
    }
    if (confidence_local_var) {
        free(confidence_local_var);
        confidence_local_var = NULL;
    }
    return NULL;

}
