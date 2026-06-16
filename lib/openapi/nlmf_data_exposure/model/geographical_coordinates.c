#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geographical_coordinates.h"



static geographical_coordinates_t *geographical_coordinates_create_internal(
    double *lon,
    double *lat
    ) {
    geographical_coordinates_t *geographical_coordinates_local_var = malloc(sizeof(geographical_coordinates_t));
    if (!geographical_coordinates_local_var) {
        return NULL;
    }
    memset(geographical_coordinates_local_var, 0, sizeof(geographical_coordinates_t));
    geographical_coordinates_local_var->_library_owned = 1;
    geographical_coordinates_local_var->lon = lon;
    geographical_coordinates_local_var->lat = lat;
    return geographical_coordinates_local_var;
}

__attribute__((deprecated)) geographical_coordinates_t *geographical_coordinates_create(
    double *lon,
    double *lat
    ) {
    double *lon_copy = NULL;
    if (lon) {
        lon_copy = malloc(sizeof(double));
        if (lon_copy) *lon_copy = *lon;
    }
    double *lat_copy = NULL;
    if (lat) {
        lat_copy = malloc(sizeof(double));
        if (lat_copy) *lat_copy = *lat;
    }
    geographical_coordinates_t *result = geographical_coordinates_create_internal (
        lon_copy,
        lat_copy
        );
    if (!result) {
        free(lon_copy);
        free(lat_copy);
    }
    return result;
}

void geographical_coordinates_free(geographical_coordinates_t *geographical_coordinates) {
    if(NULL == geographical_coordinates){
        return ;
    }
    if(geographical_coordinates->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "geographical_coordinates_free");
        return ;
    }
    listEntry_t *listEntry;
    if (geographical_coordinates->lon) {
        free(geographical_coordinates->lon);
        geographical_coordinates->lon = NULL;
    }
    if (geographical_coordinates->lat) {
        free(geographical_coordinates->lat);
        geographical_coordinates->lat = NULL;
    }
    free(geographical_coordinates);
}

cJSON *geographical_coordinates_convertToJSON(geographical_coordinates_t *geographical_coordinates) {
    cJSON *item = cJSON_CreateObject();

    // geographical_coordinates->lon
    if (!geographical_coordinates->lon) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "lon", *geographical_coordinates->lon) == NULL) {
    goto fail; //Numeric
    }


    // geographical_coordinates->lat
    if (!geographical_coordinates->lat) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "lat", *geographical_coordinates->lat) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

geographical_coordinates_t *geographical_coordinates_parseFromJSON(cJSON *geographical_coordinatesJSON){

    geographical_coordinates_t *geographical_coordinates_local_var = NULL;

    // define the local variable for geographical_coordinates->lon
    double *lon_local_var = NULL;

    // define the local variable for geographical_coordinates->lat
    double *lat_local_var = NULL;

    // geographical_coordinates->lon
    cJSON *lon = cJSON_GetObjectItemCaseSensitive(geographical_coordinatesJSON, "lon");
    if (cJSON_IsNull(lon)) {
        lon = NULL;
    }
    if (!lon) {
        goto end;
    }

    
    if(!cJSON_IsNumber(lon))
    {
    goto end; //Numeric
    }
    lon_local_var = malloc(sizeof(double));
    if(!lon_local_var)
    {
        goto end;
    }
    *lon_local_var = lon->valuedouble;

    // geographical_coordinates->lat
    cJSON *lat = cJSON_GetObjectItemCaseSensitive(geographical_coordinatesJSON, "lat");
    if (cJSON_IsNull(lat)) {
        lat = NULL;
    }
    if (!lat) {
        goto end;
    }

    
    if(!cJSON_IsNumber(lat))
    {
    goto end; //Numeric
    }
    lat_local_var = malloc(sizeof(double));
    if(!lat_local_var)
    {
        goto end;
    }
    *lat_local_var = lat->valuedouble;



    geographical_coordinates_local_var = geographical_coordinates_create_internal (
        lon_local_var,
        lat_local_var
        );

    if (!geographical_coordinates_local_var) {
        goto end;
    }

    return geographical_coordinates_local_var;
end:
    if (lon_local_var) {
        free(lon_local_var);
        lon_local_var = NULL;
    }
    if (lat_local_var) {
        free(lat_local_var);
        lat_local_var = NULL;
    }
    return NULL;

}
