
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ml_model_inter_ind.h"

OpenAPI_ml_model_inter_ind_t *OpenAPI_ml_model_inter_ind_create(
    OpenAPI_nwdaf_event_t *analytics_id,
    OpenAPI_list_t *vendor_list
)
{
    OpenAPI_ml_model_inter_ind_t *ml_model_inter_ind_local_var = ogs_malloc(sizeof(OpenAPI_ml_model_inter_ind_t));
    ogs_assert(ml_model_inter_ind_local_var);

    ml_model_inter_ind_local_var->analytics_id = analytics_id;
    ml_model_inter_ind_local_var->vendor_list = vendor_list;

    return ml_model_inter_ind_local_var;
}

void OpenAPI_ml_model_inter_ind_free(OpenAPI_ml_model_inter_ind_t *ml_model_inter_ind)
{
    if (NULL == ml_model_inter_ind) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_nwdaf_event_free(ml_model_inter_ind->analytics_id);
    OpenAPI_list_for_each(ml_model_inter_ind->vendor_list, node) {
        ogs_free(node->data);
    }
    OpenAPI_list_free(ml_model_inter_ind->vendor_list);
    ogs_free(ml_model_inter_ind);
}

cJSON *OpenAPI_ml_model_inter_ind_convertToJSON(OpenAPI_ml_model_inter_ind_t *ml_model_inter_ind)
{
    cJSON *item = NULL;

    if (ml_model_inter_ind == NULL) {
        ogs_error("OpenAPI_ml_model_inter_ind_convertToJSON() failed [MlModelInterInd]");
        return NULL;
    }

    item = cJSON_CreateObject();
    cJSON *analytics_id_local_JSON = OpenAPI_nwdaf_event_convertToJSON(ml_model_inter_ind->analytics_id);
    if (analytics_id_local_JSON == NULL) {
        ogs_error("OpenAPI_ml_model_inter_ind_convertToJSON() failed [analytics_id]");
        goto end;
    }
    cJSON_AddItemToObject(item, "analyticsId", analytics_id_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_ml_model_inter_ind_convertToJSON() failed [analytics_id]");
        goto end;
    }

    cJSON *vendor_list = cJSON_AddArrayToObject(item, "vendorList");
    if (vendor_list == NULL) {
        ogs_error("OpenAPI_ml_model_inter_ind_convertToJSON() failed [vendor_list]");
        goto end;
    }

    OpenAPI_lnode_t *vendor_list_node;
    OpenAPI_list_for_each(ml_model_inter_ind->vendor_list, vendor_list_node)  {
    if (cJSON_AddStringToObject(vendor_list, "", (char*)vendor_list_node->data) == NULL) {
        ogs_error("OpenAPI_ml_model_inter_ind_convertToJSON() failed [vendor_list]");
        goto end;
    }
                    }

end:
    return item;
}

OpenAPI_ml_model_inter_ind_t *OpenAPI_ml_model_inter_ind_parseFromJSON(cJSON *ml_model_inter_indJSON)
{
    OpenAPI_ml_model_inter_ind_t *ml_model_inter_ind_local_var = NULL;
    cJSON *analytics_id = cJSON_GetObjectItemCaseSensitive(ml_model_inter_indJSON, "analyticsId");
    if (!analytics_id) {
        ogs_error("OpenAPI_ml_model_inter_ind_parseFromJSON() failed [analytics_id]");
        goto end;
    }

    OpenAPI_nwdaf_event_t *analytics_id_local_nonprim = NULL;
    analytics_id_local_nonprim = OpenAPI_nwdaf_event_parseFromJSON(analytics_id);

    cJSON *vendor_list = cJSON_GetObjectItemCaseSensitive(ml_model_inter_indJSON, "vendorList");
    if (!vendor_list) {
        ogs_error("OpenAPI_ml_model_inter_ind_parseFromJSON() failed [vendor_list]");
        goto end;
    }

    OpenAPI_list_t *vendor_listList;
    cJSON *vendor_list_local;
    if (!cJSON_IsArray(vendor_list)) {
        ogs_error("OpenAPI_ml_model_inter_ind_parseFromJSON() failed [vendor_list]");
        goto end;
    }
    vendor_listList = OpenAPI_list_create();

    cJSON_ArrayForEach(vendor_list_local, vendor_list) {
    if (!cJSON_IsString(vendor_list_local)) {
        ogs_error("OpenAPI_ml_model_inter_ind_parseFromJSON() failed [vendor_list]");
        goto end;
    }
    OpenAPI_list_add(vendor_listList, ogs_strdup(vendor_list_local->valuestring));
    }

    ml_model_inter_ind_local_var = OpenAPI_ml_model_inter_ind_create (
        analytics_id_local_nonprim,
        vendor_listList
    );

    return ml_model_inter_ind_local_var;
end:
    return NULL;
}

OpenAPI_ml_model_inter_ind_t *OpenAPI_ml_model_inter_ind_copy(OpenAPI_ml_model_inter_ind_t *dst, OpenAPI_ml_model_inter_ind_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_ml_model_inter_ind_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_ml_model_inter_ind_convertToJSON() failed");
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

    OpenAPI_ml_model_inter_ind_free(dst);
    dst = OpenAPI_ml_model_inter_ind_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

