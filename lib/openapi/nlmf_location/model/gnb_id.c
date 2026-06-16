#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gnb_id.h"



static gnb_id_t *gnb_id_create_internal(
    int *bit_length,
    char *g_nb_value
    ) {
    gnb_id_t *gnb_id_local_var = malloc(sizeof(gnb_id_t));
    if (!gnb_id_local_var) {
        return NULL;
    }
    memset(gnb_id_local_var, 0, sizeof(gnb_id_t));
    gnb_id_local_var->_library_owned = 1;
    gnb_id_local_var->bit_length = bit_length;
    gnb_id_local_var->g_nb_value = g_nb_value;
    return gnb_id_local_var;
}

__attribute__((deprecated)) gnb_id_t *gnb_id_create(
    int *bit_length,
    char *g_nb_value
    ) {
    int *bit_length_copy = NULL;
    if (bit_length) {
        bit_length_copy = malloc(sizeof(int));
        if (bit_length_copy) *bit_length_copy = *bit_length;
    }
    gnb_id_t *result = gnb_id_create_internal (
        bit_length_copy,
        g_nb_value
        );
    if (!result) {
        free(bit_length_copy);
    }
    return result;
}

void gnb_id_free(gnb_id_t *gnb_id) {
    if(NULL == gnb_id){
        return ;
    }
    if(gnb_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gnb_id_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gnb_id->bit_length) {
        free(gnb_id->bit_length);
        gnb_id->bit_length = NULL;
    }
    if (gnb_id->g_nb_value) {
        free(gnb_id->g_nb_value);
        gnb_id->g_nb_value = NULL;
    }
    free(gnb_id);
}

cJSON *gnb_id_convertToJSON(gnb_id_t *gnb_id) {
    cJSON *item = cJSON_CreateObject();

    // gnb_id->bit_length
    if (!gnb_id->bit_length) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bitLength", *gnb_id->bit_length) == NULL) {
    goto fail; //Numeric
    }


    // gnb_id->g_nb_value
    if (!gnb_id->g_nb_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gNBValue", gnb_id->g_nb_value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gnb_id_t *gnb_id_parseFromJSON(cJSON *gnb_idJSON){

    gnb_id_t *gnb_id_local_var = NULL;

    // define the local variable for gnb_id->bit_length
    int *bit_length_local_var = NULL;

    char *g_nb_value_local_str = NULL;

    // gnb_id->bit_length
    cJSON *bit_length = cJSON_GetObjectItemCaseSensitive(gnb_idJSON, "bitLength");
    if (cJSON_IsNull(bit_length)) {
        bit_length = NULL;
    }
    if (!bit_length) {
        goto end;
    }

    
    if(!cJSON_IsNumber(bit_length))
    {
    goto end; //Numeric
    }
    bit_length_local_var = malloc(sizeof(int));
    if(!bit_length_local_var)
    {
        goto end;
    }
    *bit_length_local_var = bit_length->valuedouble;

    // gnb_id->g_nb_value
    cJSON *g_nb_value = cJSON_GetObjectItemCaseSensitive(gnb_idJSON, "gNBValue");
    if (cJSON_IsNull(g_nb_value)) {
        g_nb_value = NULL;
    }
    if (!g_nb_value) {
        goto end;
    }

    
    if(!cJSON_IsString(g_nb_value))
    {
    goto end; //String
    }


    if (g_nb_value && !cJSON_IsNull(g_nb_value)) g_nb_value_local_str = strdup(g_nb_value->valuestring);

    gnb_id_local_var = gnb_id_create_internal (
        bit_length_local_var,
        g_nb_value_local_str
        );

    if (!gnb_id_local_var) {
        goto end;
    }

    return gnb_id_local_var;
end:
    if (bit_length_local_var) {
        free(bit_length_local_var);
        bit_length_local_var = NULL;
    }
    if (g_nb_value_local_str) {
        free(g_nb_value_local_str);
        g_nb_value_local_str = NULL;
    }
    return NULL;

}
