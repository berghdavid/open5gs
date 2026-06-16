#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local_origin.h"



static local_origin_t *local_origin_create_internal(
    char *coordinate_id,
    geographical_coordinates_t *point,
    geographic_area_t *area,
    int *horiz_axes_orientation
    ) {
    local_origin_t *local_origin_local_var = malloc(sizeof(local_origin_t));
    if (!local_origin_local_var) {
        return NULL;
    }
    memset(local_origin_local_var, 0, sizeof(local_origin_t));
    local_origin_local_var->_library_owned = 1;
    local_origin_local_var->coordinate_id = coordinate_id;
    local_origin_local_var->point = point;
    local_origin_local_var->area = area;
    local_origin_local_var->horiz_axes_orientation = horiz_axes_orientation;
    return local_origin_local_var;
}

__attribute__((deprecated)) local_origin_t *local_origin_create(
    char *coordinate_id,
    geographical_coordinates_t *point,
    geographic_area_t *area,
    int *horiz_axes_orientation
    ) {
    int *horiz_axes_orientation_copy = NULL;
    if (horiz_axes_orientation) {
        horiz_axes_orientation_copy = malloc(sizeof(int));
        if (horiz_axes_orientation_copy) *horiz_axes_orientation_copy = *horiz_axes_orientation;
    }
    local_origin_t *result = local_origin_create_internal (
        coordinate_id,
        point,
        area,
        horiz_axes_orientation_copy
        );
    if (!result) {
        free(horiz_axes_orientation_copy);
    }
    return result;
}

void local_origin_free(local_origin_t *local_origin) {
    if(NULL == local_origin){
        return ;
    }
    if(local_origin->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "local_origin_free");
        return ;
    }
    listEntry_t *listEntry;
    if (local_origin->coordinate_id) {
        free(local_origin->coordinate_id);
        local_origin->coordinate_id = NULL;
    }
    if (local_origin->point) {
        geographical_coordinates_free(local_origin->point);
        local_origin->point = NULL;
    }
    if (local_origin->area) {
        geographic_area_free(local_origin->area);
        local_origin->area = NULL;
    }
    if (local_origin->horiz_axes_orientation) {
        free(local_origin->horiz_axes_orientation);
        local_origin->horiz_axes_orientation = NULL;
    }
    free(local_origin);
}

cJSON *local_origin_convertToJSON(local_origin_t *local_origin) {
    cJSON *item = cJSON_CreateObject();

    // local_origin->coordinate_id
    if (!local_origin->coordinate_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "coordinateId", local_origin->coordinate_id) == NULL) {
    goto fail; //String
    }


    // local_origin->point
    if(local_origin->point) {
    cJSON *point_local_JSON = geographical_coordinates_convertToJSON(local_origin->point);
    if(point_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // local_origin->area
    if(local_origin->area) {
    cJSON *area_local_JSON = geographic_area_convertToJSON(local_origin->area);
    if(area_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "area", area_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // local_origin->horiz_axes_orientation
    if(local_origin->horiz_axes_orientation) {
    if(cJSON_AddNumberToObject(item, "horizAxesOrientation", *local_origin->horiz_axes_orientation) == NULL) {
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

local_origin_t *local_origin_parseFromJSON(cJSON *local_originJSON){

    local_origin_t *local_origin_local_var = NULL;

    char *coordinate_id_local_str = NULL;

    // define the local variable for local_origin->point
    geographical_coordinates_t *point_local_nonprim = NULL;

    // define the local variable for local_origin->area
    geographic_area_t *area_local_nonprim = NULL;

    // define the local variable for local_origin->horiz_axes_orientation
    int *horiz_axes_orientation_local_var = NULL;

    // local_origin->coordinate_id
    cJSON *coordinate_id = cJSON_GetObjectItemCaseSensitive(local_originJSON, "coordinateId");
    if (cJSON_IsNull(coordinate_id)) {
        coordinate_id = NULL;
    }
    if (!coordinate_id) {
        goto end;
    }

    
    if(!cJSON_IsString(coordinate_id))
    {
    goto end; //String
    }

    // local_origin->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(local_originJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (point) { 
    point_local_nonprim = geographical_coordinates_parseFromJSON(point); //nonprimitive
    }

    // local_origin->area
    cJSON *area = cJSON_GetObjectItemCaseSensitive(local_originJSON, "area");
    if (cJSON_IsNull(area)) {
        area = NULL;
    }
    if (area) { 
    area_local_nonprim = geographic_area_parseFromJSON(area); //nonprimitive
    }

    // local_origin->horiz_axes_orientation
    cJSON *horiz_axes_orientation = cJSON_GetObjectItemCaseSensitive(local_originJSON, "horizAxesOrientation");
    if (cJSON_IsNull(horiz_axes_orientation)) {
        horiz_axes_orientation = NULL;
    }
    if (horiz_axes_orientation) { 
    if(!cJSON_IsNumber(horiz_axes_orientation))
    {
    goto end; //Numeric
    }
    horiz_axes_orientation_local_var = malloc(sizeof(int));
    if(!horiz_axes_orientation_local_var)
    {
        goto end;
    }
    *horiz_axes_orientation_local_var = horiz_axes_orientation->valuedouble;
    }


    if (coordinate_id && !cJSON_IsNull(coordinate_id)) coordinate_id_local_str = strdup(coordinate_id->valuestring);

    local_origin_local_var = local_origin_create_internal (
        coordinate_id_local_str,
        point ? point_local_nonprim : NULL,
        area ? area_local_nonprim : NULL,
        horiz_axes_orientation_local_var
        );

    if (!local_origin_local_var) {
        goto end;
    }

    return local_origin_local_var;
end:
    if (coordinate_id_local_str) {
        free(coordinate_id_local_str);
        coordinate_id_local_str = NULL;
    }
    if (point_local_nonprim) {
        geographical_coordinates_free(point_local_nonprim);
        point_local_nonprim = NULL;
    }
    if (area_local_nonprim) {
        geographic_area_free(area_local_nonprim);
        area_local_nonprim = NULL;
    }
    if (horiz_axes_orientation_local_var) {
        free(horiz_axes_orientation_local_var);
        horiz_axes_orientation_local_var = NULL;
    }
    return NULL;

}
