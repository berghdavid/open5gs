#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_altitude_uncertainty.h"



static point_altitude_uncertainty_t *point_altitude_uncertainty_create_internal(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    double *altitude,
    uncertainty_ellipse_t *uncertainty_ellipse,
    float *uncertainty_altitude,
    int *confidence,
    int *v_confidence
    ) {
    point_altitude_uncertainty_t *point_altitude_uncertainty_local_var = malloc(sizeof(point_altitude_uncertainty_t));
    if (!point_altitude_uncertainty_local_var) {
        return NULL;
    }
    memset(point_altitude_uncertainty_local_var, 0, sizeof(point_altitude_uncertainty_t));
    point_altitude_uncertainty_local_var->_library_owned = 1;
    point_altitude_uncertainty_local_var->shape = shape;
    point_altitude_uncertainty_local_var->point = point;
    point_altitude_uncertainty_local_var->altitude = altitude;
    point_altitude_uncertainty_local_var->uncertainty_ellipse = uncertainty_ellipse;
    point_altitude_uncertainty_local_var->uncertainty_altitude = uncertainty_altitude;
    point_altitude_uncertainty_local_var->confidence = confidence;
    point_altitude_uncertainty_local_var->v_confidence = v_confidence;
    return point_altitude_uncertainty_local_var;
}

__attribute__((deprecated)) point_altitude_uncertainty_t *point_altitude_uncertainty_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    double *altitude,
    uncertainty_ellipse_t *uncertainty_ellipse,
    float *uncertainty_altitude,
    int *confidence,
    int *v_confidence
    ) {
    double *altitude_copy = NULL;
    if (altitude) {
        altitude_copy = malloc(sizeof(double));
        if (altitude_copy) *altitude_copy = *altitude;
    }
    float *uncertainty_altitude_copy = NULL;
    if (uncertainty_altitude) {
        uncertainty_altitude_copy = malloc(sizeof(float));
        if (uncertainty_altitude_copy) *uncertainty_altitude_copy = *uncertainty_altitude;
    }
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
    point_altitude_uncertainty_t *result = point_altitude_uncertainty_create_internal (
        shape,
        point,
        altitude_copy,
        uncertainty_ellipse,
        uncertainty_altitude_copy,
        confidence_copy,
        v_confidence_copy
        );
    if (!result) {
        free(altitude_copy);
        free(uncertainty_altitude_copy);
        free(confidence_copy);
        free(v_confidence_copy);
    }
    return result;
}

void point_altitude_uncertainty_free(point_altitude_uncertainty_t *point_altitude_uncertainty) {
    if(NULL == point_altitude_uncertainty){
        return ;
    }
    if(point_altitude_uncertainty->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "point_altitude_uncertainty_free");
        return ;
    }
    listEntry_t *listEntry;
    if (point_altitude_uncertainty->shape) {
        supported_gad_shapes_free(point_altitude_uncertainty->shape);
        point_altitude_uncertainty->shape = NULL;
    }
    if (point_altitude_uncertainty->point) {
        geographical_coordinates_free(point_altitude_uncertainty->point);
        point_altitude_uncertainty->point = NULL;
    }
    if (point_altitude_uncertainty->altitude) {
        free(point_altitude_uncertainty->altitude);
        point_altitude_uncertainty->altitude = NULL;
    }
    if (point_altitude_uncertainty->uncertainty_ellipse) {
        uncertainty_ellipse_free(point_altitude_uncertainty->uncertainty_ellipse);
        point_altitude_uncertainty->uncertainty_ellipse = NULL;
    }
    if (point_altitude_uncertainty->uncertainty_altitude) {
        free(point_altitude_uncertainty->uncertainty_altitude);
        point_altitude_uncertainty->uncertainty_altitude = NULL;
    }
    if (point_altitude_uncertainty->confidence) {
        free(point_altitude_uncertainty->confidence);
        point_altitude_uncertainty->confidence = NULL;
    }
    if (point_altitude_uncertainty->v_confidence) {
        free(point_altitude_uncertainty->v_confidence);
        point_altitude_uncertainty->v_confidence = NULL;
    }
    free(point_altitude_uncertainty);
}

cJSON *point_altitude_uncertainty_convertToJSON(point_altitude_uncertainty_t *point_altitude_uncertainty) {
    cJSON *item = cJSON_CreateObject();

    // point_altitude_uncertainty->shape
    if (!point_altitude_uncertainty->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(point_altitude_uncertainty->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_altitude_uncertainty->point
    if (!point_altitude_uncertainty->point) {
        goto fail;
    }
    cJSON *point_local_JSON = geographical_coordinates_convertToJSON(point_altitude_uncertainty->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_altitude_uncertainty->altitude
    if (!point_altitude_uncertainty->altitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "altitude", *point_altitude_uncertainty->altitude) == NULL) {
    goto fail; //Numeric
    }


    // point_altitude_uncertainty->uncertainty_ellipse
    if (!point_altitude_uncertainty->uncertainty_ellipse) {
        goto fail;
    }
    cJSON *uncertainty_ellipse_local_JSON = uncertainty_ellipse_convertToJSON(point_altitude_uncertainty->uncertainty_ellipse);
    if(uncertainty_ellipse_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "uncertaintyEllipse", uncertainty_ellipse_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // point_altitude_uncertainty->uncertainty_altitude
    if (!point_altitude_uncertainty->uncertainty_altitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "uncertaintyAltitude", *point_altitude_uncertainty->uncertainty_altitude) == NULL) {
    goto fail; //Numeric
    }


    // point_altitude_uncertainty->confidence
    if (!point_altitude_uncertainty->confidence) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "confidence", *point_altitude_uncertainty->confidence) == NULL) {
    goto fail; //Numeric
    }


    // point_altitude_uncertainty->v_confidence
    if(point_altitude_uncertainty->v_confidence) {
    if(cJSON_AddNumberToObject(item, "vConfidence", *point_altitude_uncertainty->v_confidence) == NULL) {
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

point_altitude_uncertainty_t *point_altitude_uncertainty_parseFromJSON(cJSON *point_altitude_uncertaintyJSON){

    point_altitude_uncertainty_t *point_altitude_uncertainty_local_var = NULL;

    // define the local variable for point_altitude_uncertainty->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for point_altitude_uncertainty->point
    geographical_coordinates_t *point_local_nonprim = NULL;

    // define the local variable for point_altitude_uncertainty->altitude
    double *altitude_local_var = NULL;

    // define the local variable for point_altitude_uncertainty->uncertainty_ellipse
    uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;

    // define the local variable for point_altitude_uncertainty->uncertainty_altitude
    float *uncertainty_altitude_local_var = NULL;

    // define the local variable for point_altitude_uncertainty->confidence
    int *confidence_local_var = NULL;

    // define the local variable for point_altitude_uncertainty->v_confidence
    int *v_confidence_local_var = NULL;

    // point_altitude_uncertainty->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(point_altitude_uncertaintyJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // point_altitude_uncertainty->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(point_altitude_uncertaintyJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = geographical_coordinates_parseFromJSON(point); //nonprimitive

    // point_altitude_uncertainty->altitude
    cJSON *altitude = cJSON_GetObjectItemCaseSensitive(point_altitude_uncertaintyJSON, "altitude");
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

    // point_altitude_uncertainty->uncertainty_ellipse
    cJSON *uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(point_altitude_uncertaintyJSON, "uncertaintyEllipse");
    if (cJSON_IsNull(uncertainty_ellipse)) {
        uncertainty_ellipse = NULL;
    }
    if (!uncertainty_ellipse) {
        goto end;
    }

    
    uncertainty_ellipse_local_nonprim = uncertainty_ellipse_parseFromJSON(uncertainty_ellipse); //nonprimitive

    // point_altitude_uncertainty->uncertainty_altitude
    cJSON *uncertainty_altitude = cJSON_GetObjectItemCaseSensitive(point_altitude_uncertaintyJSON, "uncertaintyAltitude");
    if (cJSON_IsNull(uncertainty_altitude)) {
        uncertainty_altitude = NULL;
    }
    if (!uncertainty_altitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(uncertainty_altitude))
    {
    goto end; //Numeric
    }
    uncertainty_altitude_local_var = malloc(sizeof(float));
    if(!uncertainty_altitude_local_var)
    {
        goto end;
    }
    *uncertainty_altitude_local_var = uncertainty_altitude->valuedouble;

    // point_altitude_uncertainty->confidence
    cJSON *confidence = cJSON_GetObjectItemCaseSensitive(point_altitude_uncertaintyJSON, "confidence");
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

    // point_altitude_uncertainty->v_confidence
    cJSON *v_confidence = cJSON_GetObjectItemCaseSensitive(point_altitude_uncertaintyJSON, "vConfidence");
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



    point_altitude_uncertainty_local_var = point_altitude_uncertainty_create_internal (
        shape_local_nonprim,
        point_local_nonprim,
        altitude_local_var,
        uncertainty_ellipse_local_nonprim,
        uncertainty_altitude_local_var,
        confidence_local_var,
        v_confidence_local_var
        );

    if (!point_altitude_uncertainty_local_var) {
        goto end;
    }

    return point_altitude_uncertainty_local_var;
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
    if (uncertainty_ellipse_local_nonprim) {
        uncertainty_ellipse_free(uncertainty_ellipse_local_nonprim);
        uncertainty_ellipse_local_nonprim = NULL;
    }
    if (uncertainty_altitude_local_var) {
        free(uncertainty_altitude_local_var);
        uncertainty_altitude_local_var = NULL;
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
