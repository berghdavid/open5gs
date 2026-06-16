
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trp_parameter.h"

OpenAPI_trp_parameter_t *OpenAPI_trp_parameter_create(
    OpenAPI_list_t *trp_ids,
    OpenAPI_global_ran_node_id_t *global_gnb_id
)
{
    OpenAPI_trp_parameter_t *trp_parameter_local_var = ogs_malloc(sizeof(OpenAPI_trp_parameter_t));
    ogs_assert(trp_parameter_local_var);

    trp_parameter_local_var->trp_ids = trp_ids;
    trp_parameter_local_var->global_gnb_id = global_gnb_id;

    return trp_parameter_local_var;
}

void OpenAPI_trp_parameter_free(OpenAPI_trp_parameter_t *trp_parameter)
{
    if (NULL == trp_parameter) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_list_for_each(trp_parameter->trp_ids, node) {
        ogs_free(node->data);
    }
    OpenAPI_list_free(trp_parameter->trp_ids);
    OpenAPI_global_ran_node_id_free(trp_parameter->global_gnb_id);
    ogs_free(trp_parameter);
}

cJSON *OpenAPI_trp_parameter_convertToJSON(OpenAPI_trp_parameter_t *trp_parameter)
{
    cJSON *item = NULL;

    if (trp_parameter == NULL) {
        ogs_error("OpenAPI_trp_parameter_convertToJSON() failed [TrpParameter]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (trp_parameter->trp_ids) {
    cJSON *trp_ids = cJSON_AddArrayToObject(item, "trpIds");
    if (trp_ids == NULL) {
        ogs_error("OpenAPI_trp_parameter_convertToJSON() failed [trp_ids]");
        goto end;
    }

    OpenAPI_lnode_t *trp_ids_node;
    OpenAPI_list_for_each(trp_parameter->trp_ids, trp_ids_node)  {
    if (cJSON_AddNumberToObject(trp_ids, "", *(double *)trp_ids_node->data) == NULL) {
        ogs_error("OpenAPI_trp_parameter_convertToJSON() failed [trp_ids]");
        goto end;
    }
                    }
    }

    if (trp_parameter->global_gnb_id) {
    cJSON *global_gnb_id_local_JSON = OpenAPI_global_ran_node_id_convertToJSON(trp_parameter->global_gnb_id);
    if (global_gnb_id_local_JSON == NULL) {
        ogs_error("OpenAPI_trp_parameter_convertToJSON() failed [global_gnb_id]");
        goto end;
    }
    cJSON_AddItemToObject(item, "globalGnbId", global_gnb_id_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_trp_parameter_convertToJSON() failed [global_gnb_id]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_trp_parameter_t *OpenAPI_trp_parameter_parseFromJSON(cJSON *trp_parameterJSON)
{
    OpenAPI_trp_parameter_t *trp_parameter_local_var = NULL;
    cJSON *trp_ids = cJSON_GetObjectItemCaseSensitive(trp_parameterJSON, "trpIds");

    OpenAPI_list_t *trp_idsList;
    if (trp_ids) {
    cJSON *trp_ids_local;
    if (!cJSON_IsArray(trp_ids)) {
        ogs_error("OpenAPI_trp_parameter_parseFromJSON() failed [trp_ids]");
        goto end;
    }
    trp_idsList = OpenAPI_list_create();

    cJSON_ArrayForEach(trp_ids_local, trp_ids) {
    if (!cJSON_IsNumber(trp_ids_local)) {
        ogs_error("OpenAPI_trp_parameter_parseFromJSON() failed [trp_ids]");
        goto end;
    }
    OpenAPI_list_add(trp_idsList, &trp_ids_local->valuedouble);
    }
    }

    cJSON *global_gnb_id = cJSON_GetObjectItemCaseSensitive(trp_parameterJSON, "globalGnbId");

    OpenAPI_global_ran_node_id_t *global_gnb_id_local_nonprim = NULL;
    if (global_gnb_id) {
    global_gnb_id_local_nonprim = OpenAPI_global_ran_node_id_parseFromJSON(global_gnb_id);
    }

    trp_parameter_local_var = OpenAPI_trp_parameter_create (
        trp_ids ? trp_idsList : NULL,
        global_gnb_id ? global_gnb_id_local_nonprim : NULL
    );

    return trp_parameter_local_var;
end:
    return NULL;
}

OpenAPI_trp_parameter_t *OpenAPI_trp_parameter_copy(OpenAPI_trp_parameter_t *dst, OpenAPI_trp_parameter_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_trp_parameter_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_trp_parameter_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_trp_parameter_free(dst);
    dst = OpenAPI_trp_parameter_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

