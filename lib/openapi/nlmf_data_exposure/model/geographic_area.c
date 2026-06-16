#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geographic_area.h"



static geographic_area_t *geographic_area_create_internal(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    float *uncertainty,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence,
    list_t *point_list,
    double *altitude,
    float *uncertainty_altitude,
    int *v_confidence,
    int *inner_radius,
    float *uncertainty_radius,
    int *offset_angle,
    int *included_angle
    ) {
    geographic_area_t *geographic_area_local_var = malloc(sizeof(geographic_area_t));
    if (!geographic_area_local_var) {
        return NULL;
    }
    memset(geographic_area_local_var, 0, sizeof(geographic_area_t));
    geographic_area_local_var->_library_owned = 1;
    geographic_area_local_var->shape = shape;
    geographic_area_local_var->point = point;
    geographic_area_local_var->uncertainty = uncertainty;
    geographic_area_local_var->uncertainty_ellipse = uncertainty_ellipse;
    geographic_area_local_var->confidence = confidence;
    geographic_area_local_var->point_list = point_list;
    geographic_area_local_var->altitude = altitude;
    geographic_area_local_var->uncertainty_altitude = uncertainty_altitude;
    geographic_area_local_var->v_confidence = v_confidence;
    geographic_area_local_var->inner_radius = inner_radius;
    geographic_area_local_var->uncertainty_radius = uncertainty_radius;
    geographic_area_local_var->offset_angle = offset_angle;
    geographic_area_local_var->included_angle = included_angle;
    return geographic_area_local_var;
}

__attribute__((deprecated)) geographic_area_t *geographic_area_create(
    supported_gad_shapes_t *shape,
    geographical_coordinates_t *point,
    float *uncertainty,
    uncertainty_ellipse_t *uncertainty_ellipse,
    int *confidence,
    list_t *point_list,
    double *altitude,
    float *uncertainty_altitude,
    int *v_confidence,
    int *inner_radius,
    float *uncertainty_radius,
    int *offset_angle,
    int *included_angle
    ) {
    float *uncertainty_copy = NULL;
    if (uncertainty) {
        uncertainty_copy = malloc(sizeof(float));
        if (uncertainty_copy) *uncertainty_copy = *uncertainty;
    }
    int *confidence_copy = NULL;
    if (confidence) {
        confidence_copy = malloc(sizeof(int));
        if (confidence_copy) *confidence_copy = *confidence;
    }
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
    int *v_confidence_copy = NULL;
    if (v_confidence) {
        v_confidence_copy = malloc(sizeof(int));
        if (v_confidence_copy) *v_confidence_copy = *v_confidence;
    }
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
    geographic_area_t *result = geographic_area_create_internal (
        shape,
        point,
        uncertainty_copy,
        uncertainty_ellipse,
        confidence_copy,
        point_list,
        altitude_copy,
        uncertainty_altitude_copy,
        v_confidence_copy,
        inner_radius_copy,
        uncertainty_radius_copy,
        offset_angle_copy,
        included_angle_copy
        );
    if (!result) {
        free(uncertainty_copy);
        free(confidence_copy);
        free(altitude_copy);
        free(uncertainty_altitude_copy);
        free(v_confidence_copy);
        free(inner_radius_copy);
        free(uncertainty_radius_copy);
        free(offset_angle_copy);
        free(included_angle_copy);
    }
    return result;
}

void geographic_area_free(geographic_area_t *geographic_area) {
    if(NULL == geographic_area){
        return ;
    }
    if(geographic_area->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "geographic_area_free");
        return ;
    }
    listEntry_t *listEntry;
    if (geographic_area->shape) {
        supported_gad_shapes_free(geographic_area->shape);
        geographic_area->shape = NULL;
    }
    if (geographic_area->point) {
        geographical_coordinates_free(geographic_area->point);
        geographic_area->point = NULL;
    }
    if (geographic_area->uncertainty) {
        free(geographic_area->uncertainty);
        geographic_area->uncertainty = NULL;
    }
    if (geographic_area->uncertainty_ellipse) {
        uncertainty_ellipse_free(geographic_area->uncertainty_ellipse);
        geographic_area->uncertainty_ellipse = NULL;
    }
    if (geographic_area->confidence) {
        free(geographic_area->confidence);
        geographic_area->confidence = NULL;
    }
    if (geographic_area->point_list) {
        list_ForEach(listEntry, geographic_area->point_list) {
            geographical_coordinates_free(listEntry->data);
        }
        list_freeList(geographic_area->point_list);
        geographic_area->point_list = NULL;
    }
    if (geographic_area->altitude) {
        free(geographic_area->altitude);
        geographic_area->altitude = NULL;
    }
    if (geographic_area->uncertainty_altitude) {
        free(geographic_area->uncertainty_altitude);
        geographic_area->uncertainty_altitude = NULL;
    }
    if (geographic_area->v_confidence) {
        free(geographic_area->v_confidence);
        geographic_area->v_confidence = NULL;
    }
    if (geographic_area->inner_radius) {
        free(geographic_area->inner_radius);
        geographic_area->inner_radius = NULL;
    }
    if (geographic_area->uncertainty_radius) {
        free(geographic_area->uncertainty_radius);
        geographic_area->uncertainty_radius = NULL;
    }
    if (geographic_area->offset_angle) {
        free(geographic_area->offset_angle);
        geographic_area->offset_angle = NULL;
    }
    if (geographic_area->included_angle) {
        free(geographic_area->included_angle);
        geographic_area->included_angle = NULL;
    }
    free(geographic_area);
}

cJSON *geographic_area_convertToJSON(geographic_area_t *geographic_area) {
    cJSON *item = cJSON_CreateObject();

    // geographic_area->shape
    if (!geographic_area->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(geographic_area->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // geographic_area->point
    if (!geographic_area->point) {
        goto fail;
    }
    cJSON *point_local_JSON = geographical_coordinates_convertToJSON(geographic_area->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // geographic_area->uncertainty
    if (!geographic_area->uncertainty) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "uncertainty", *geographic_area->uncertainty) == NULL) {
    goto fail; //Numeric
    }


    // geographic_area->uncertainty_ellipse
    if (!geographic_area->uncertainty_ellipse) {
        goto fail;
    }
    cJSON *uncertainty_ellipse_local_JSON = uncertainty_ellipse_convertToJSON(geographic_area->uncertainty_ellipse);
    if(uncertainty_ellipse_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "uncertaintyEllipse", uncertainty_ellipse_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // geographic_area->confidence
    if (!geographic_area->confidence) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "confidence", *geographic_area->confidence) == NULL) {
    goto fail; //Numeric
    }


    // geographic_area->point_list
    if (!geographic_area->point_list) {
        goto fail;
    }
    cJSON *point_list = cJSON_AddArrayToObject(item, "pointList");
    if(point_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *point_listListEntry;
    if (geographic_area->point_list) {
    list_ForEach(point_listListEntry, geographic_area->point_list) {
    cJSON *itemLocal = geographical_coordinates_convertToJSON(point_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(point_list, itemLocal);
    }
    }


    // geographic_area->altitude
    if (!geographic_area->altitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "altitude", *geographic_area->altitude) == NULL) {
    goto fail; //Numeric
    }


    // geographic_area->uncertainty_altitude
    if (!geographic_area->uncertainty_altitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "uncertaintyAltitude", *geographic_area->uncertainty_altitude) == NULL) {
    goto fail; //Numeric
    }


    // geographic_area->v_confidence
    if(geographic_area->v_confidence) {
    if(cJSON_AddNumberToObject(item, "vConfidence", *geographic_area->v_confidence) == NULL) {
    goto fail; //Numeric
    }
    }


    // geographic_area->inner_radius
    if (!geographic_area->inner_radius) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "innerRadius", *geographic_area->inner_radius) == NULL) {
    goto fail; //Numeric
    }


    // geographic_area->uncertainty_radius
    if (!geographic_area->uncertainty_radius) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "uncertaintyRadius", *geographic_area->uncertainty_radius) == NULL) {
    goto fail; //Numeric
    }


    // geographic_area->offset_angle
    if (!geographic_area->offset_angle) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offsetAngle", *geographic_area->offset_angle) == NULL) {
    goto fail; //Numeric
    }


    // geographic_area->included_angle
    if (!geographic_area->included_angle) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "includedAngle", *geographic_area->included_angle) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

geographic_area_t *geographic_area_parseFromJSON(cJSON *geographic_areaJSON){

    geographic_area_t *geographic_area_local_var = NULL;

    // define the local variable for geographic_area->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local variable for geographic_area->point
    geographical_coordinates_t *point_local_nonprim = NULL;

    // define the local variable for geographic_area->uncertainty
    float *uncertainty_local_var = NULL;

    // define the local variable for geographic_area->uncertainty_ellipse
    uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;

    // define the local variable for geographic_area->confidence
    int *confidence_local_var = NULL;

    // define the local list for geographic_area->point_list
    list_t *point_listList = NULL;

    // define the local variable for geographic_area->altitude
    double *altitude_local_var = NULL;

    // define the local variable for geographic_area->uncertainty_altitude
    float *uncertainty_altitude_local_var = NULL;

    // define the local variable for geographic_area->v_confidence
    int *v_confidence_local_var = NULL;

    // define the local variable for geographic_area->inner_radius
    int *inner_radius_local_var = NULL;

    // define the local variable for geographic_area->uncertainty_radius
    float *uncertainty_radius_local_var = NULL;

    // define the local variable for geographic_area->offset_angle
    int *offset_angle_local_var = NULL;

    // define the local variable for geographic_area->included_angle
    int *included_angle_local_var = NULL;

    // geographic_area->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // geographic_area->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    
    point_local_nonprim = geographical_coordinates_parseFromJSON(point); //nonprimitive

    // geographic_area->uncertainty
    cJSON *uncertainty = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "uncertainty");
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

    // geographic_area->uncertainty_ellipse
    cJSON *uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "uncertaintyEllipse");
    if (cJSON_IsNull(uncertainty_ellipse)) {
        uncertainty_ellipse = NULL;
    }
    if (!uncertainty_ellipse) {
        goto end;
    }

    
    uncertainty_ellipse_local_nonprim = uncertainty_ellipse_parseFromJSON(uncertainty_ellipse); //nonprimitive

    // geographic_area->confidence
    cJSON *confidence = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "confidence");
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

    // geographic_area->point_list
    cJSON *point_list = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "pointList");
    if (cJSON_IsNull(point_list)) {
        point_list = NULL;
    }
    if (!point_list) {
        goto end;
    }

    
    cJSON *point_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(point_list)){
        goto end; //nonprimitive container
    }

    point_listList = list_createList();

    cJSON_ArrayForEach(point_list_local_nonprimitive,point_list )
    {
        if(!cJSON_IsObject(point_list_local_nonprimitive)){
            goto end;
        }
        geographical_coordinates_t *point_listItem = geographical_coordinates_parseFromJSON(point_list_local_nonprimitive);

        list_addElement(point_listList, point_listItem);
    }

    // geographic_area->altitude
    cJSON *altitude = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "altitude");
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

    // geographic_area->uncertainty_altitude
    cJSON *uncertainty_altitude = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "uncertaintyAltitude");
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

    // geographic_area->v_confidence
    cJSON *v_confidence = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "vConfidence");
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

    // geographic_area->inner_radius
    cJSON *inner_radius = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "innerRadius");
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

    // geographic_area->uncertainty_radius
    cJSON *uncertainty_radius = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "uncertaintyRadius");
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

    // geographic_area->offset_angle
    cJSON *offset_angle = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "offsetAngle");
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

    // geographic_area->included_angle
    cJSON *included_angle = cJSON_GetObjectItemCaseSensitive(geographic_areaJSON, "includedAngle");
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



    geographic_area_local_var = geographic_area_create_internal (
        shape_local_nonprim,
        point_local_nonprim,
        uncertainty_local_var,
        uncertainty_ellipse_local_nonprim,
        confidence_local_var,
        point_listList,
        altitude_local_var,
        uncertainty_altitude_local_var,
        v_confidence_local_var,
        inner_radius_local_var,
        uncertainty_radius_local_var,
        offset_angle_local_var,
        included_angle_local_var
        );

    if (!geographic_area_local_var) {
        goto end;
    }

    return geographic_area_local_var;
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
    if (uncertainty_ellipse_local_nonprim) {
        uncertainty_ellipse_free(uncertainty_ellipse_local_nonprim);
        uncertainty_ellipse_local_nonprim = NULL;
    }
    if (confidence_local_var) {
        free(confidence_local_var);
        confidence_local_var = NULL;
    }
    if (point_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, point_listList) {
            geographical_coordinates_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(point_listList);
        point_listList = NULL;
    }
    if (altitude_local_var) {
        free(altitude_local_var);
        altitude_local_var = NULL;
    }
    if (uncertainty_altitude_local_var) {
        free(uncertainty_altitude_local_var);
        uncertainty_altitude_local_var = NULL;
    }
    if (v_confidence_local_var) {
        free(v_confidence_local_var);
        v_confidence_local_var = NULL;
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
    return NULL;

}
