#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "integrity_protection_level.h"



static integrity_protection_level_t *integrity_protection_level_create_internal(
    int *horizontal_protection_level,
    int *vertical_protection_level
    ) {
    integrity_protection_level_t *integrity_protection_level_local_var = malloc(sizeof(integrity_protection_level_t));
    if (!integrity_protection_level_local_var) {
        return NULL;
    }
    memset(integrity_protection_level_local_var, 0, sizeof(integrity_protection_level_t));
    integrity_protection_level_local_var->_library_owned = 1;
    integrity_protection_level_local_var->horizontal_protection_level = horizontal_protection_level;
    integrity_protection_level_local_var->vertical_protection_level = vertical_protection_level;
    return integrity_protection_level_local_var;
}

__attribute__((deprecated)) integrity_protection_level_t *integrity_protection_level_create(
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
    integrity_protection_level_t *result = integrity_protection_level_create_internal (
        horizontal_protection_level_copy,
        vertical_protection_level_copy
        );
    if (!result) {
        free(horizontal_protection_level_copy);
        free(vertical_protection_level_copy);
    }
    return result;
}

void integrity_protection_level_free(integrity_protection_level_t *integrity_protection_level) {
    if(NULL == integrity_protection_level){
        return ;
    }
    if(integrity_protection_level->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "integrity_protection_level_free");
        return ;
    }
    listEntry_t *listEntry;
    if (integrity_protection_level->horizontal_protection_level) {
        free(integrity_protection_level->horizontal_protection_level);
        integrity_protection_level->horizontal_protection_level = NULL;
    }
    if (integrity_protection_level->vertical_protection_level) {
        free(integrity_protection_level->vertical_protection_level);
        integrity_protection_level->vertical_protection_level = NULL;
    }
    free(integrity_protection_level);
}

cJSON *integrity_protection_level_convertToJSON(integrity_protection_level_t *integrity_protection_level) {
    cJSON *item = cJSON_CreateObject();

    // integrity_protection_level->horizontal_protection_level
    if (!integrity_protection_level->horizontal_protection_level) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "horizontalProtectionLevel", *integrity_protection_level->horizontal_protection_level) == NULL) {
    goto fail; //Numeric
    }


    // integrity_protection_level->vertical_protection_level
    if(integrity_protection_level->vertical_protection_level) {
    if(cJSON_AddNumberToObject(item, "verticalProtectionLevel", *integrity_protection_level->vertical_protection_level) == NULL) {
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

integrity_protection_level_t *integrity_protection_level_parseFromJSON(cJSON *integrity_protection_levelJSON){

    integrity_protection_level_t *integrity_protection_level_local_var = NULL;

    // define the local variable for integrity_protection_level->horizontal_protection_level
    int *horizontal_protection_level_local_var = NULL;

    // define the local variable for integrity_protection_level->vertical_protection_level
    int *vertical_protection_level_local_var = NULL;

    // integrity_protection_level->horizontal_protection_level
    cJSON *horizontal_protection_level = cJSON_GetObjectItemCaseSensitive(integrity_protection_levelJSON, "horizontalProtectionLevel");
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

    // integrity_protection_level->vertical_protection_level
    cJSON *vertical_protection_level = cJSON_GetObjectItemCaseSensitive(integrity_protection_levelJSON, "verticalProtectionLevel");
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



    integrity_protection_level_local_var = integrity_protection_level_create_internal (
        horizontal_protection_level_local_var,
        vertical_protection_level_local_var
        );

    if (!integrity_protection_level_local_var) {
        goto end;
    }

    return integrity_protection_level_local_var;
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
