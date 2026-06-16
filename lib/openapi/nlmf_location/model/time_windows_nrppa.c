#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time_windows_nrppa.h"



static time_windows_nrppa_t *time_windows_nrppa_create_internal(
    char *measurement_list,
    char *srs_list
    ) {
    time_windows_nrppa_t *time_windows_nrppa_local_var = malloc(sizeof(time_windows_nrppa_t));
    if (!time_windows_nrppa_local_var) {
        return NULL;
    }
    memset(time_windows_nrppa_local_var, 0, sizeof(time_windows_nrppa_t));
    time_windows_nrppa_local_var->_library_owned = 1;
    time_windows_nrppa_local_var->measurement_list = measurement_list;
    time_windows_nrppa_local_var->srs_list = srs_list;
    return time_windows_nrppa_local_var;
}

__attribute__((deprecated)) time_windows_nrppa_t *time_windows_nrppa_create(
    char *measurement_list,
    char *srs_list
    ) {
    time_windows_nrppa_t *result = time_windows_nrppa_create_internal (
        measurement_list,
        srs_list
        );
    if (!result) {
    }
    return result;
}

void time_windows_nrppa_free(time_windows_nrppa_t *time_windows_nrppa) {
    if(NULL == time_windows_nrppa){
        return ;
    }
    if(time_windows_nrppa->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "time_windows_nrppa_free");
        return ;
    }
    listEntry_t *listEntry;
    if (time_windows_nrppa->measurement_list) {
        free(time_windows_nrppa->measurement_list);
        time_windows_nrppa->measurement_list = NULL;
    }
    if (time_windows_nrppa->srs_list) {
        free(time_windows_nrppa->srs_list);
        time_windows_nrppa->srs_list = NULL;
    }
    free(time_windows_nrppa);
}

cJSON *time_windows_nrppa_convertToJSON(time_windows_nrppa_t *time_windows_nrppa) {
    cJSON *item = cJSON_CreateObject();

    // time_windows_nrppa->measurement_list
    if(time_windows_nrppa->measurement_list) {
    if(cJSON_AddStringToObject(item, "measurementList", time_windows_nrppa->measurement_list) == NULL) {
    goto fail; //ByteArray
    }
    }


    // time_windows_nrppa->srs_list
    if(time_windows_nrppa->srs_list) {
    if(cJSON_AddStringToObject(item, "srsList", time_windows_nrppa->srs_list) == NULL) {
    goto fail; //ByteArray
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

time_windows_nrppa_t *time_windows_nrppa_parseFromJSON(cJSON *time_windows_nrppaJSON){

    time_windows_nrppa_t *time_windows_nrppa_local_var = NULL;

    char *measurement_list_local_str = NULL;

    char *srs_list_local_str = NULL;

    // time_windows_nrppa->measurement_list
    cJSON *measurement_list = cJSON_GetObjectItemCaseSensitive(time_windows_nrppaJSON, "measurementList");
    if (cJSON_IsNull(measurement_list)) {
        measurement_list = NULL;
    }
    if (measurement_list) { 
    if(!cJSON_IsString(measurement_list))
    {
    goto end; //ByteArray
    }
    }

    // time_windows_nrppa->srs_list
    cJSON *srs_list = cJSON_GetObjectItemCaseSensitive(time_windows_nrppaJSON, "srsList");
    if (cJSON_IsNull(srs_list)) {
        srs_list = NULL;
    }
    if (srs_list) { 
    if(!cJSON_IsString(srs_list))
    {
    goto end; //ByteArray
    }
    }


    if (measurement_list) measurement_list_local_str = strdup(measurement_list->valuestring);
    if (srs_list) srs_list_local_str = strdup(srs_list->valuestring);

    time_windows_nrppa_local_var = time_windows_nrppa_create_internal (
        measurement_list_local_str,
        srs_list_local_str
        );

    if (!time_windows_nrppa_local_var) {
        goto end;
    }

    return time_windows_nrppa_local_var;
end:
    if (measurement_list_local_str) {
        free(measurement_list_local_str);
        measurement_list_local_str = NULL;
    }
    if (srs_list_local_str) {
        free(srs_list_local_str);
        srs_list_local_str = NULL;
    }
    return NULL;

}
