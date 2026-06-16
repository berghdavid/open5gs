#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "polygon.h"



static polygon_t *polygon_create_internal(
    supported_gad_shapes_t *shape,
    list_t *point_list
    ) {
    polygon_t *polygon_local_var = malloc(sizeof(polygon_t));
    if (!polygon_local_var) {
        return NULL;
    }
    memset(polygon_local_var, 0, sizeof(polygon_t));
    polygon_local_var->_library_owned = 1;
    polygon_local_var->shape = shape;
    polygon_local_var->point_list = point_list;
    return polygon_local_var;
}

__attribute__((deprecated)) polygon_t *polygon_create(
    supported_gad_shapes_t *shape,
    list_t *point_list
    ) {
    polygon_t *result = polygon_create_internal (
        shape,
        point_list
        );
    if (!result) {
    }
    return result;
}

void polygon_free(polygon_t *polygon) {
    if(NULL == polygon){
        return ;
    }
    if(polygon->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "polygon_free");
        return ;
    }
    listEntry_t *listEntry;
    if (polygon->shape) {
        supported_gad_shapes_free(polygon->shape);
        polygon->shape = NULL;
    }
    if (polygon->point_list) {
        list_ForEach(listEntry, polygon->point_list) {
            geographical_coordinates_free(listEntry->data);
        }
        list_freeList(polygon->point_list);
        polygon->point_list = NULL;
    }
    free(polygon);
}

cJSON *polygon_convertToJSON(polygon_t *polygon) {
    cJSON *item = cJSON_CreateObject();

    // polygon->shape
    if (!polygon->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(polygon->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // polygon->point_list
    if (!polygon->point_list) {
        goto fail;
    }
    cJSON *point_list = cJSON_AddArrayToObject(item, "pointList");
    if(point_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *point_listListEntry;
    if (polygon->point_list) {
    list_ForEach(point_listListEntry, polygon->point_list) {
    cJSON *itemLocal = geographical_coordinates_convertToJSON(point_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(point_list, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

polygon_t *polygon_parseFromJSON(cJSON *polygonJSON){

    polygon_t *polygon_local_var = NULL;

    // define the local variable for polygon->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // define the local list for polygon->point_list
    list_t *point_listList = NULL;

    // polygon->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(polygonJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive

    // polygon->point_list
    cJSON *point_list = cJSON_GetObjectItemCaseSensitive(polygonJSON, "pointList");
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



    polygon_local_var = polygon_create_internal (
        shape_local_nonprim,
        point_listList
        );

    if (!polygon_local_var) {
        goto end;
    }

    return polygon_local_var;
end:
    if (shape_local_nonprim) {
        supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
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
    return NULL;

}
