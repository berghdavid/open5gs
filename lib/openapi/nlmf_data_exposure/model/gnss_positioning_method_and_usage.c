#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gnss_positioning_method_and_usage.h"



static gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_create_internal(
    positioning_mode_t *mode,
    gnss_id_t *gnss,
    usage_t *usage
    ) {
    gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_local_var = malloc(sizeof(gnss_positioning_method_and_usage_t));
    if (!gnss_positioning_method_and_usage_local_var) {
        return NULL;
    }
    memset(gnss_positioning_method_and_usage_local_var, 0, sizeof(gnss_positioning_method_and_usage_t));
    gnss_positioning_method_and_usage_local_var->_library_owned = 1;
    gnss_positioning_method_and_usage_local_var->mode = mode;
    gnss_positioning_method_and_usage_local_var->gnss = gnss;
    gnss_positioning_method_and_usage_local_var->usage = usage;
    return gnss_positioning_method_and_usage_local_var;
}

__attribute__((deprecated)) gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_create(
    positioning_mode_t *mode,
    gnss_id_t *gnss,
    usage_t *usage
    ) {
    gnss_positioning_method_and_usage_t *result = gnss_positioning_method_and_usage_create_internal (
        mode,
        gnss,
        usage
        );
    if (!result) {
    }
    return result;
}

void gnss_positioning_method_and_usage_free(gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage) {
    if(NULL == gnss_positioning_method_and_usage){
        return ;
    }
    if(gnss_positioning_method_and_usage->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gnss_positioning_method_and_usage_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gnss_positioning_method_and_usage->mode) {
        positioning_mode_free(gnss_positioning_method_and_usage->mode);
        gnss_positioning_method_and_usage->mode = NULL;
    }
    if (gnss_positioning_method_and_usage->gnss) {
        gnss_id_free(gnss_positioning_method_and_usage->gnss);
        gnss_positioning_method_and_usage->gnss = NULL;
    }
    if (gnss_positioning_method_and_usage->usage) {
        usage_free(gnss_positioning_method_and_usage->usage);
        gnss_positioning_method_and_usage->usage = NULL;
    }
    free(gnss_positioning_method_and_usage);
}

cJSON *gnss_positioning_method_and_usage_convertToJSON(gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage) {
    cJSON *item = cJSON_CreateObject();

    // gnss_positioning_method_and_usage->mode
    if (!gnss_positioning_method_and_usage->mode) {
        goto fail;
    }
    cJSON *mode_local_JSON = positioning_mode_convertToJSON(gnss_positioning_method_and_usage->mode);
    if(mode_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "mode", mode_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // gnss_positioning_method_and_usage->gnss
    if (!gnss_positioning_method_and_usage->gnss) {
        goto fail;
    }
    cJSON *gnss_local_JSON = gnss_id_convertToJSON(gnss_positioning_method_and_usage->gnss);
    if(gnss_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gnss", gnss_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // gnss_positioning_method_and_usage->usage
    if (!gnss_positioning_method_and_usage->usage) {
        goto fail;
    }
    cJSON *usage_local_JSON = usage_convertToJSON(gnss_positioning_method_and_usage->usage);
    if(usage_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "usage", usage_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_parseFromJSON(cJSON *gnss_positioning_method_and_usageJSON){

    gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_local_var = NULL;

    // define the local variable for gnss_positioning_method_and_usage->mode
    positioning_mode_t *mode_local_nonprim = NULL;

    // define the local variable for gnss_positioning_method_and_usage->gnss
    gnss_id_t *gnss_local_nonprim = NULL;

    // define the local variable for gnss_positioning_method_and_usage->usage
    usage_t *usage_local_nonprim = NULL;

    // gnss_positioning_method_and_usage->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(gnss_positioning_method_and_usageJSON, "mode");
    if (cJSON_IsNull(mode)) {
        mode = NULL;
    }
    if (!mode) {
        goto end;
    }

    
    mode_local_nonprim = positioning_mode_parseFromJSON(mode); //nonprimitive

    // gnss_positioning_method_and_usage->gnss
    cJSON *gnss = cJSON_GetObjectItemCaseSensitive(gnss_positioning_method_and_usageJSON, "gnss");
    if (cJSON_IsNull(gnss)) {
        gnss = NULL;
    }
    if (!gnss) {
        goto end;
    }

    
    gnss_local_nonprim = gnss_id_parseFromJSON(gnss); //nonprimitive

    // gnss_positioning_method_and_usage->usage
    cJSON *usage = cJSON_GetObjectItemCaseSensitive(gnss_positioning_method_and_usageJSON, "usage");
    if (cJSON_IsNull(usage)) {
        usage = NULL;
    }
    if (!usage) {
        goto end;
    }

    
    usage_local_nonprim = usage_parseFromJSON(usage); //nonprimitive



    gnss_positioning_method_and_usage_local_var = gnss_positioning_method_and_usage_create_internal (
        mode_local_nonprim,
        gnss_local_nonprim,
        usage_local_nonprim
        );

    if (!gnss_positioning_method_and_usage_local_var) {
        goto end;
    }

    return gnss_positioning_method_and_usage_local_var;
end:
    if (mode_local_nonprim) {
        positioning_mode_free(mode_local_nonprim);
        mode_local_nonprim = NULL;
    }
    if (gnss_local_nonprim) {
        gnss_id_free(gnss_local_nonprim);
        gnss_local_nonprim = NULL;
    }
    if (usage_local_nonprim) {
        usage_free(usage_local_nonprim);
        usage_local_nonprim = NULL;
    }
    return NULL;

}
