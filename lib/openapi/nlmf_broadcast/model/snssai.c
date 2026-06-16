#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snssai.h"



static snssai_t *snssai_create_internal(
    int *sst,
    char *sd
    ) {
    snssai_t *snssai_local_var = malloc(sizeof(snssai_t));
    if (!snssai_local_var) {
        return NULL;
    }
    memset(snssai_local_var, 0, sizeof(snssai_t));
    snssai_local_var->_library_owned = 1;
    snssai_local_var->sst = sst;
    snssai_local_var->sd = sd;
    return snssai_local_var;
}

__attribute__((deprecated)) snssai_t *snssai_create(
    int *sst,
    char *sd
    ) {
    int *sst_copy = NULL;
    if (sst) {
        sst_copy = malloc(sizeof(int));
        if (sst_copy) *sst_copy = *sst;
    }
    snssai_t *result = snssai_create_internal (
        sst_copy,
        sd
        );
    if (!result) {
        free(sst_copy);
    }
    return result;
}

void snssai_free(snssai_t *snssai) {
    if(NULL == snssai){
        return ;
    }
    if(snssai->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snssai_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snssai->sst) {
        free(snssai->sst);
        snssai->sst = NULL;
    }
    if (snssai->sd) {
        free(snssai->sd);
        snssai->sd = NULL;
    }
    free(snssai);
}

cJSON *snssai_convertToJSON(snssai_t *snssai) {
    cJSON *item = cJSON_CreateObject();

    // snssai->sst
    if (!snssai->sst) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "sst", *snssai->sst) == NULL) {
    goto fail; //Numeric
    }


    // snssai->sd
    if(snssai->sd) {
    if(cJSON_AddStringToObject(item, "sd", snssai->sd) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

snssai_t *snssai_parseFromJSON(cJSON *snssaiJSON){

    snssai_t *snssai_local_var = NULL;

    // define the local variable for snssai->sst
    int *sst_local_var = NULL;

    char *sd_local_str = NULL;

    // snssai->sst
    cJSON *sst = cJSON_GetObjectItemCaseSensitive(snssaiJSON, "sst");
    if (cJSON_IsNull(sst)) {
        sst = NULL;
    }
    if (!sst) {
        goto end;
    }

    
    if(!cJSON_IsNumber(sst))
    {
    goto end; //Numeric
    }
    sst_local_var = malloc(sizeof(int));
    if(!sst_local_var)
    {
        goto end;
    }
    *sst_local_var = sst->valuedouble;

    // snssai->sd
    cJSON *sd = cJSON_GetObjectItemCaseSensitive(snssaiJSON, "sd");
    if (cJSON_IsNull(sd)) {
        sd = NULL;
    }
    if (sd) { 
    if(!cJSON_IsString(sd) && !cJSON_IsNull(sd))
    {
    goto end; //String
    }
    }


    if (sd && !cJSON_IsNull(sd)) sd_local_str = strdup(sd->valuestring);

    snssai_local_var = snssai_create_internal (
        sst_local_var,
        sd_local_str
        );

    if (!snssai_local_var) {
        goto end;
    }

    return snssai_local_var;
end:
    if (sst_local_var) {
        free(sst_local_var);
        sst_local_var = NULL;
    }
    if (sd_local_str) {
        free(sd_local_str);
        sd_local_str = NULL;
    }
    return NULL;

}
