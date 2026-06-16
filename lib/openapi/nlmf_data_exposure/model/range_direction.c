#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "range_direction.h"



static range_direction_t *range_direction_create_internal(
    double *distance,
    int *azimuth_direction,
    int *elevation_direction
    ) {
    range_direction_t *range_direction_local_var = malloc(sizeof(range_direction_t));
    if (!range_direction_local_var) {
        return NULL;
    }
    memset(range_direction_local_var, 0, sizeof(range_direction_t));
    range_direction_local_var->_library_owned = 1;
    range_direction_local_var->distance = distance;
    range_direction_local_var->azimuth_direction = azimuth_direction;
    range_direction_local_var->elevation_direction = elevation_direction;
    return range_direction_local_var;
}

__attribute__((deprecated)) range_direction_t *range_direction_create(
    double *distance,
    int *azimuth_direction,
    int *elevation_direction
    ) {
    double *distance_copy = NULL;
    if (distance) {
        distance_copy = malloc(sizeof(double));
        if (distance_copy) *distance_copy = *distance;
    }
    int *azimuth_direction_copy = NULL;
    if (azimuth_direction) {
        azimuth_direction_copy = malloc(sizeof(int));
        if (azimuth_direction_copy) *azimuth_direction_copy = *azimuth_direction;
    }
    int *elevation_direction_copy = NULL;
    if (elevation_direction) {
        elevation_direction_copy = malloc(sizeof(int));
        if (elevation_direction_copy) *elevation_direction_copy = *elevation_direction;
    }
    range_direction_t *result = range_direction_create_internal (
        distance_copy,
        azimuth_direction_copy,
        elevation_direction_copy
        );
    if (!result) {
        free(distance_copy);
        free(azimuth_direction_copy);
        free(elevation_direction_copy);
    }
    return result;
}

void range_direction_free(range_direction_t *range_direction) {
    if(NULL == range_direction){
        return ;
    }
    if(range_direction->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "range_direction_free");
        return ;
    }
    listEntry_t *listEntry;
    if (range_direction->distance) {
        free(range_direction->distance);
        range_direction->distance = NULL;
    }
    if (range_direction->azimuth_direction) {
        free(range_direction->azimuth_direction);
        range_direction->azimuth_direction = NULL;
    }
    if (range_direction->elevation_direction) {
        free(range_direction->elevation_direction);
        range_direction->elevation_direction = NULL;
    }
    free(range_direction);
}

cJSON *range_direction_convertToJSON(range_direction_t *range_direction) {
    cJSON *item = cJSON_CreateObject();

    // range_direction->distance
    if(range_direction->distance) {
    if(cJSON_AddNumberToObject(item, "distance", *range_direction->distance) == NULL) {
    goto fail; //Numeric
    }
    }


    // range_direction->azimuth_direction
    if(range_direction->azimuth_direction) {
    if(cJSON_AddNumberToObject(item, "azimuthDirection", *range_direction->azimuth_direction) == NULL) {
    goto fail; //Numeric
    }
    }


    // range_direction->elevation_direction
    if(range_direction->elevation_direction) {
    if(cJSON_AddNumberToObject(item, "elevationDirection", *range_direction->elevation_direction) == NULL) {
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

range_direction_t *range_direction_parseFromJSON(cJSON *range_directionJSON){

    range_direction_t *range_direction_local_var = NULL;

    // define the local variable for range_direction->distance
    double *distance_local_var = NULL;

    // define the local variable for range_direction->azimuth_direction
    int *azimuth_direction_local_var = NULL;

    // define the local variable for range_direction->elevation_direction
    int *elevation_direction_local_var = NULL;

    // range_direction->distance
    cJSON *distance = cJSON_GetObjectItemCaseSensitive(range_directionJSON, "distance");
    if (cJSON_IsNull(distance)) {
        distance = NULL;
    }
    if (distance) { 
    if(!cJSON_IsNumber(distance))
    {
    goto end; //Numeric
    }
    distance_local_var = malloc(sizeof(double));
    if(!distance_local_var)
    {
        goto end;
    }
    *distance_local_var = distance->valuedouble;
    }

    // range_direction->azimuth_direction
    cJSON *azimuth_direction = cJSON_GetObjectItemCaseSensitive(range_directionJSON, "azimuthDirection");
    if (cJSON_IsNull(azimuth_direction)) {
        azimuth_direction = NULL;
    }
    if (azimuth_direction) { 
    if(!cJSON_IsNumber(azimuth_direction))
    {
    goto end; //Numeric
    }
    azimuth_direction_local_var = malloc(sizeof(int));
    if(!azimuth_direction_local_var)
    {
        goto end;
    }
    *azimuth_direction_local_var = azimuth_direction->valuedouble;
    }

    // range_direction->elevation_direction
    cJSON *elevation_direction = cJSON_GetObjectItemCaseSensitive(range_directionJSON, "elevationDirection");
    if (cJSON_IsNull(elevation_direction)) {
        elevation_direction = NULL;
    }
    if (elevation_direction) { 
    if(!cJSON_IsNumber(elevation_direction))
    {
    goto end; //Numeric
    }
    elevation_direction_local_var = malloc(sizeof(int));
    if(!elevation_direction_local_var)
    {
        goto end;
    }
    *elevation_direction_local_var = elevation_direction->valuedouble;
    }



    range_direction_local_var = range_direction_create_internal (
        distance_local_var,
        azimuth_direction_local_var,
        elevation_direction_local_var
        );

    if (!range_direction_local_var) {
        goto end;
    }

    return range_direction_local_var;
end:
    if (distance_local_var) {
        free(distance_local_var);
        distance_local_var = NULL;
    }
    if (azimuth_direction_local_var) {
        free(azimuth_direction_local_var);
        azimuth_direction_local_var = NULL;
    }
    if (elevation_direction_local_var) {
        free(elevation_direction_local_var);
        elevation_direction_local_var = NULL;
    }
    return NULL;

}
