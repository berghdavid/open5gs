#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "alert_limit.h"



static alert_limit_t *alert_limit_create_internal(
    int *horizontal_protection_level,
    int *vertical_protection_level
    ) {
    alert_limit_t *alert_limit_local_var = malloc(sizeof(alert_limit_t));
    if (!alert_limit_local_var) {
        return NULL;
    }
    memset(alert_limit_local_var, 0, sizeof(alert_limit_t));
    alert_limit_local_var->_library_owned = 1;
    alert_limit_local_var->horizontal_protection_level = horizontal_protection_level;
    alert_limit_local_var->vertical_protection_level = vertical_protection_level;
    return alert_limit_local_var;
}

__attribute__((deprecated)) alert_limit_t *alert_limit_create(
    int *horizontal_protection_level,
    int *vertical_protection_level
    ) {
    int *horizontal_protection_level_copy = NULL;
    if (horizontal_protection_level) {
        horizontal_protection_level_copy = malloc(sizeof(int));
        if (horizontal_protection_level_copy) *horizontal_protection_level_copy = *horizontal_protection_level;
    }
    int *vertical_protection_level_copy = NULL;
    if (vertical_protection_level) {
        vertical_protection_level_copy = malloc(sizeof(int));
        if (vertical_protection_level_copy) *vertical_protection_level_copy = *vertical_protection_level;
    }
    alert_limit_t *result = alert_limit_create_internal (
        horizontal_protection_level_copy,
        vertical_protection_level_copy
        );
    if (!result) {
        free(horizontal_protection_level_copy);
        free(vertical_protection_level_copy);
    }
    return result;
}

void alert_limit_free(alert_limit_t *alert_limit) {
    if(NULL == alert_limit){
        return ;
    }
    if(alert_limit->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "alert_limit_free");
        return ;
    }
    listEntry_t *listEntry;
    if (alert_limit->horizontal_protection_level) {
        free(alert_limit->horizontal_protection_level);
        alert_limit->horizontal_protection_level = NULL;
    }
    if (alert_limit->vertical_protection_level) {
        free(alert_limit->vertical_protection_level);
        alert_limit->vertical_protection_level = NULL;
    }
    free(alert_limit);
}

cJSON *alert_limit_convertToJSON(alert_limit_t *alert_limit) {
    cJSON *item = cJSON_CreateObject();

    // alert_limit->horizontal_protection_level
    if (!alert_limit->horizontal_protection_level) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "horizontalProtectionLevel", *alert_limit->horizontal_protection_level) == NULL) {
    goto fail; //Numeric
    }


    // alert_limit->vertical_protection_level
    if(alert_limit->vertical_protection_level) {
    if(cJSON_AddNumberToObject(item, "verticalProtectionLevel", *alert_limit->vertical_protection_level) == NULL) {
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

alert_limit_t *alert_limit_parseFromJSON(cJSON *alert_limitJSON){

    alert_limit_t *alert_limit_local_var = NULL;

    // define the local variable for alert_limit->horizontal_protection_level
    int *horizontal_protection_level_local_var = NULL;

    // define the local variable for alert_limit->vertical_protection_level
    int *vertical_protection_level_local_var = NULL;

    // alert_limit->horizontal_protection_level
    cJSON *horizontal_protection_level = cJSON_GetObjectItemCaseSensitive(alert_limitJSON, "horizontalProtectionLevel");
    if (cJSON_IsNull(horizontal_protection_level)) {
        horizontal_protection_level = NULL;
    }
    if (!horizontal_protection_level) {
        goto end;
    }

    
    if(!cJSON_IsNumber(horizontal_protection_level))
    {
    goto end; //Numeric
    }
    horizontal_protection_level_local_var = malloc(sizeof(int));
    if(!horizontal_protection_level_local_var)
    {
        goto end;
    }
    *horizontal_protection_level_local_var = horizontal_protection_level->valuedouble;

    // alert_limit->vertical_protection_level
    cJSON *vertical_protection_level = cJSON_GetObjectItemCaseSensitive(alert_limitJSON, "verticalProtectionLevel");
    if (cJSON_IsNull(vertical_protection_level)) {
        vertical_protection_level = NULL;
    }
    if (vertical_protection_level) { 
    if(!cJSON_IsNumber(vertical_protection_level))
    {
    goto end; //Numeric
    }
    vertical_protection_level_local_var = malloc(sizeof(int));
    if(!vertical_protection_level_local_var)
    {
        goto end;
    }
    *vertical_protection_level_local_var = vertical_protection_level->valuedouble;
    }



    alert_limit_local_var = alert_limit_create_internal (
        horizontal_protection_level_local_var,
        vertical_protection_level_local_var
        );

    if (!alert_limit_local_var) {
        goto end;
    }

    return alert_limit_local_var;
end:
    if (horizontal_protection_level_local_var) {
        free(horizontal_protection_level_local_var);
        horizontal_protection_level_local_var = NULL;
    }
    if (vertical_protection_level_local_var) {
        free(vertical_protection_level_local_var);
        vertical_protection_level_local_var = NULL;
    }
    return NULL;

}
