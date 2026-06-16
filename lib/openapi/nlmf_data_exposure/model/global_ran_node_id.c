#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "global_ran_node_id.h"



static global_ran_node_id_t *global_ran_node_id_create_internal(
    plmn_id_t *plmn_id,
    char *n3_iwf_id,
    gnb_id_t *g_nb_id,
    char *nge_nb_id,
    char *wagf_id,
    char *tngf_id,
    char *nid,
    char *e_nb_id
    ) {
    global_ran_node_id_t *global_ran_node_id_local_var = malloc(sizeof(global_ran_node_id_t));
    if (!global_ran_node_id_local_var) {
        return NULL;
    }
    memset(global_ran_node_id_local_var, 0, sizeof(global_ran_node_id_t));
    global_ran_node_id_local_var->_library_owned = 1;
    global_ran_node_id_local_var->plmn_id = plmn_id;
    global_ran_node_id_local_var->n3_iwf_id = n3_iwf_id;
    global_ran_node_id_local_var->g_nb_id = g_nb_id;
    global_ran_node_id_local_var->nge_nb_id = nge_nb_id;
    global_ran_node_id_local_var->wagf_id = wagf_id;
    global_ran_node_id_local_var->tngf_id = tngf_id;
    global_ran_node_id_local_var->nid = nid;
    global_ran_node_id_local_var->e_nb_id = e_nb_id;
    return global_ran_node_id_local_var;
}

__attribute__((deprecated)) global_ran_node_id_t *global_ran_node_id_create(
    plmn_id_t *plmn_id,
    char *n3_iwf_id,
    gnb_id_t *g_nb_id,
    char *nge_nb_id,
    char *wagf_id,
    char *tngf_id,
    char *nid,
    char *e_nb_id
    ) {
    global_ran_node_id_t *result = global_ran_node_id_create_internal (
        plmn_id,
        n3_iwf_id,
        g_nb_id,
        nge_nb_id,
        wagf_id,
        tngf_id,
        nid,
        e_nb_id
        );
    if (!result) {
    }
    return result;
}

void global_ran_node_id_free(global_ran_node_id_t *global_ran_node_id) {
    if(NULL == global_ran_node_id){
        return ;
    }
    if(global_ran_node_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "global_ran_node_id_free");
        return ;
    }
    listEntry_t *listEntry;
    if (global_ran_node_id->plmn_id) {
        plmn_id_free(global_ran_node_id->plmn_id);
        global_ran_node_id->plmn_id = NULL;
    }
    if (global_ran_node_id->n3_iwf_id) {
        free(global_ran_node_id->n3_iwf_id);
        global_ran_node_id->n3_iwf_id = NULL;
    }
    if (global_ran_node_id->g_nb_id) {
        gnb_id_free(global_ran_node_id->g_nb_id);
        global_ran_node_id->g_nb_id = NULL;
    }
    if (global_ran_node_id->nge_nb_id) {
        free(global_ran_node_id->nge_nb_id);
        global_ran_node_id->nge_nb_id = NULL;
    }
    if (global_ran_node_id->wagf_id) {
        free(global_ran_node_id->wagf_id);
        global_ran_node_id->wagf_id = NULL;
    }
    if (global_ran_node_id->tngf_id) {
        free(global_ran_node_id->tngf_id);
        global_ran_node_id->tngf_id = NULL;
    }
    if (global_ran_node_id->nid) {
        free(global_ran_node_id->nid);
        global_ran_node_id->nid = NULL;
    }
    if (global_ran_node_id->e_nb_id) {
        free(global_ran_node_id->e_nb_id);
        global_ran_node_id->e_nb_id = NULL;
    }
    free(global_ran_node_id);
}

cJSON *global_ran_node_id_convertToJSON(global_ran_node_id_t *global_ran_node_id) {
    cJSON *item = cJSON_CreateObject();

    // global_ran_node_id->plmn_id
    if (!global_ran_node_id->plmn_id) {
        goto fail;
    }
    cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(global_ran_node_id->plmn_id);
    if(plmn_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // global_ran_node_id->n3_iwf_id
    if(global_ran_node_id->n3_iwf_id) {
    if(cJSON_AddStringToObject(item, "n3IwfId", global_ran_node_id->n3_iwf_id) == NULL) {
    goto fail; //String
    }
    }


    // global_ran_node_id->g_nb_id
    if(global_ran_node_id->g_nb_id) {
    cJSON *g_nb_id_local_JSON = gnb_id_convertToJSON(global_ran_node_id->g_nb_id);
    if(g_nb_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gNbId", g_nb_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // global_ran_node_id->nge_nb_id
    if(global_ran_node_id->nge_nb_id) {
    if(cJSON_AddStringToObject(item, "ngeNbId", global_ran_node_id->nge_nb_id) == NULL) {
    goto fail; //String
    }
    }


    // global_ran_node_id->wagf_id
    if(global_ran_node_id->wagf_id) {
    if(cJSON_AddStringToObject(item, "wagfId", global_ran_node_id->wagf_id) == NULL) {
    goto fail; //String
    }
    }


    // global_ran_node_id->tngf_id
    if(global_ran_node_id->tngf_id) {
    if(cJSON_AddStringToObject(item, "tngfId", global_ran_node_id->tngf_id) == NULL) {
    goto fail; //String
    }
    }


    // global_ran_node_id->nid
    if(global_ran_node_id->nid) {
    if(cJSON_AddStringToObject(item, "nid", global_ran_node_id->nid) == NULL) {
    goto fail; //String
    }
    }


    // global_ran_node_id->e_nb_id
    if(global_ran_node_id->e_nb_id) {
    if(cJSON_AddStringToObject(item, "eNbId", global_ran_node_id->e_nb_id) == NULL) {
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

global_ran_node_id_t *global_ran_node_id_parseFromJSON(cJSON *global_ran_node_idJSON){

    global_ran_node_id_t *global_ran_node_id_local_var = NULL;

    // define the local variable for global_ran_node_id->plmn_id
    plmn_id_t *plmn_id_local_nonprim = NULL;

    char *n3_iwf_id_local_str = NULL;

    // define the local variable for global_ran_node_id->g_nb_id
    gnb_id_t *g_nb_id_local_nonprim = NULL;

    char *nge_nb_id_local_str = NULL;

    char *wagf_id_local_str = NULL;

    char *tngf_id_local_str = NULL;

    char *nid_local_str = NULL;

    char *e_nb_id_local_str = NULL;

    // global_ran_node_id->plmn_id
    cJSON *plmn_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON, "plmnId");
    if (cJSON_IsNull(plmn_id)) {
        plmn_id = NULL;
    }
    if (!plmn_id) {
        goto end;
    }

    
    plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id); //nonprimitive

    // global_ran_node_id->n3_iwf_id
    cJSON *n3_iwf_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON, "n3IwfId");
    if (cJSON_IsNull(n3_iwf_id)) {
        n3_iwf_id = NULL;
    }
    if (n3_iwf_id) { 
    if(!cJSON_IsString(n3_iwf_id) && !cJSON_IsNull(n3_iwf_id))
    {
    goto end; //String
    }
    }

    // global_ran_node_id->g_nb_id
    cJSON *g_nb_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON, "gNbId");
    if (cJSON_IsNull(g_nb_id)) {
        g_nb_id = NULL;
    }
    if (g_nb_id) { 
    g_nb_id_local_nonprim = gnb_id_parseFromJSON(g_nb_id); //nonprimitive
    }

    // global_ran_node_id->nge_nb_id
    cJSON *nge_nb_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON, "ngeNbId");
    if (cJSON_IsNull(nge_nb_id)) {
        nge_nb_id = NULL;
    }
    if (nge_nb_id) { 
    if(!cJSON_IsString(nge_nb_id) && !cJSON_IsNull(nge_nb_id))
    {
    goto end; //String
    }
    }

    // global_ran_node_id->wagf_id
    cJSON *wagf_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON, "wagfId");
    if (cJSON_IsNull(wagf_id)) {
        wagf_id = NULL;
    }
    if (wagf_id) { 
    if(!cJSON_IsString(wagf_id) && !cJSON_IsNull(wagf_id))
    {
    goto end; //String
    }
    }

    // global_ran_node_id->tngf_id
    cJSON *tngf_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON, "tngfId");
    if (cJSON_IsNull(tngf_id)) {
        tngf_id = NULL;
    }
    if (tngf_id) { 
    if(!cJSON_IsString(tngf_id) && !cJSON_IsNull(tngf_id))
    {
    goto end; //String
    }
    }

    // global_ran_node_id->nid
    cJSON *nid = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON, "nid");
    if (cJSON_IsNull(nid)) {
        nid = NULL;
    }
    if (nid) { 
    if(!cJSON_IsString(nid) && !cJSON_IsNull(nid))
    {
    goto end; //String
    }
    }

    // global_ran_node_id->e_nb_id
    cJSON *e_nb_id = cJSON_GetObjectItemCaseSensitive(global_ran_node_idJSON, "eNbId");
    if (cJSON_IsNull(e_nb_id)) {
        e_nb_id = NULL;
    }
    if (e_nb_id) { 
    if(!cJSON_IsString(e_nb_id) && !cJSON_IsNull(e_nb_id))
    {
    goto end; //String
    }
    }


    if (n3_iwf_id && !cJSON_IsNull(n3_iwf_id)) n3_iwf_id_local_str = strdup(n3_iwf_id->valuestring);
    if (nge_nb_id && !cJSON_IsNull(nge_nb_id)) nge_nb_id_local_str = strdup(nge_nb_id->valuestring);
    if (wagf_id && !cJSON_IsNull(wagf_id)) wagf_id_local_str = strdup(wagf_id->valuestring);
    if (tngf_id && !cJSON_IsNull(tngf_id)) tngf_id_local_str = strdup(tngf_id->valuestring);
    if (nid && !cJSON_IsNull(nid)) nid_local_str = strdup(nid->valuestring);
    if (e_nb_id && !cJSON_IsNull(e_nb_id)) e_nb_id_local_str = strdup(e_nb_id->valuestring);

    global_ran_node_id_local_var = global_ran_node_id_create_internal (
        plmn_id_local_nonprim,
        n3_iwf_id_local_str,
        g_nb_id ? g_nb_id_local_nonprim : NULL,
        nge_nb_id_local_str,
        wagf_id_local_str,
        tngf_id_local_str,
        nid_local_str,
        e_nb_id_local_str
        );

    if (!global_ran_node_id_local_var) {
        goto end;
    }

    return global_ran_node_id_local_var;
end:
    if (plmn_id_local_nonprim) {
        plmn_id_free(plmn_id_local_nonprim);
        plmn_id_local_nonprim = NULL;
    }
    if (n3_iwf_id_local_str) {
        free(n3_iwf_id_local_str);
        n3_iwf_id_local_str = NULL;
    }
    if (g_nb_id_local_nonprim) {
        gnb_id_free(g_nb_id_local_nonprim);
        g_nb_id_local_nonprim = NULL;
    }
    if (nge_nb_id_local_str) {
        free(nge_nb_id_local_str);
        nge_nb_id_local_str = NULL;
    }
    if (wagf_id_local_str) {
        free(wagf_id_local_str);
        wagf_id_local_str = NULL;
    }
    if (tngf_id_local_str) {
        free(tngf_id_local_str);
        tngf_id_local_str = NULL;
    }
    if (nid_local_str) {
        free(nid_local_str);
        nid_local_str = NULL;
    }
    if (e_nb_id_local_str) {
        free(e_nb_id_local_str);
        e_nb_id_local_str = NULL;
    }
    return NULL;

}
