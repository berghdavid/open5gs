
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nwdaf_registration_info.h"

OpenAPI_nwdaf_registration_info_t *OpenAPI_nwdaf_registration_info_create(
    OpenAPI_list_t *nwdaf_registration_list
)
{
    OpenAPI_nwdaf_registration_info_t *nwdaf_registration_info_local_var = ogs_malloc(sizeof(OpenAPI_nwdaf_registration_info_t));
    log_assert(nwdaf_registration_info_local_var);

    nwdaf_registration_info_local_var->nwdaf_registration_list = nwdaf_registration_list;

    return nwdaf_registration_info_local_var;
}

void OpenAPI_nwdaf_registration_info_free(OpenAPI_nwdaf_registration_info_t *nwdaf_registration_info)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == nwdaf_registration_info) {
        return;
    }
    if (nwdaf_registration_info->nwdaf_registration_list) {
        OpenAPI_list_for_each(nwdaf_registration_info->nwdaf_registration_list, node) {
            OpenAPI_nwdaf_registration_free(node->data);
        }
        OpenAPI_list_free(nwdaf_registration_info->nwdaf_registration_list);
        nwdaf_registration_info->nwdaf_registration_list = NULL;
    }
    ogs_free(nwdaf_registration_info);
}

cJSON *OpenAPI_nwdaf_registration_info_convertToJSON(OpenAPI_nwdaf_registration_info_t *nwdaf_registration_info)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (nwdaf_registration_info == NULL) {
        log_error("OpenAPI_nwdaf_registration_info_convertToJSON() failed [NwdafRegistrationInfo]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!nwdaf_registration_info->nwdaf_registration_list) {
        log_error("OpenAPI_nwdaf_registration_info_convertToJSON() failed [nwdaf_registration_list]");
        return NULL;
    }
    cJSON *nwdaf_registration_listList = cJSON_AddArrayToObject(item, "nwdafRegistrationList");
    if (nwdaf_registration_listList == NULL) {
        log_error("OpenAPI_nwdaf_registration_info_convertToJSON() failed [nwdaf_registration_list]");
        goto end;
    }
    OpenAPI_list_for_each(nwdaf_registration_info->nwdaf_registration_list, node) {
        cJSON *itemLocal = OpenAPI_nwdaf_registration_convertToJSON(node->data);
        if (itemLocal == NULL) {
            log_error("OpenAPI_nwdaf_registration_info_convertToJSON() failed [nwdaf_registration_list]");
            goto end;
        }
        cJSON_AddItemToArray(nwdaf_registration_listList, itemLocal);
    }

end:
    return item;
}

OpenAPI_nwdaf_registration_info_t *OpenAPI_nwdaf_registration_info_parseFromJSON(cJSON *nwdaf_registration_infoJSON)
{
    OpenAPI_nwdaf_registration_info_t *nwdaf_registration_info_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *nwdaf_registration_list = NULL;
    OpenAPI_list_t *nwdaf_registration_listList = NULL;
    nwdaf_registration_list = cJSON_GetObjectItemCaseSensitive(nwdaf_registration_infoJSON, "nwdafRegistrationList");
    if (!nwdaf_registration_list) {
        log_error("OpenAPI_nwdaf_registration_info_parseFromJSON() failed [nwdaf_registration_list]");
        goto end;
    }
        cJSON *nwdaf_registration_list_local = NULL;
        if (!cJSON_IsArray(nwdaf_registration_list)) {
            log_error("OpenAPI_nwdaf_registration_info_parseFromJSON() failed [nwdaf_registration_list]");
            goto end;
        }

        nwdaf_registration_listList = OpenAPI_list_create();

        cJSON_ArrayForEach(nwdaf_registration_list_local, nwdaf_registration_list) {
            if (!cJSON_IsObject(nwdaf_registration_list_local)) {
                log_error("OpenAPI_nwdaf_registration_info_parseFromJSON() failed [nwdaf_registration_list]");
                goto end;
            }
            OpenAPI_nwdaf_registration_t *nwdaf_registration_listItem = OpenAPI_nwdaf_registration_parseFromJSON(nwdaf_registration_list_local);
            if (!nwdaf_registration_listItem) {
                log_error("No nwdaf_registration_listItem");
                goto end;
            }
            OpenAPI_list_add(nwdaf_registration_listList, nwdaf_registration_listItem);
        }

    nwdaf_registration_info_local_var = OpenAPI_nwdaf_registration_info_create (
        nwdaf_registration_listList
    );

    return nwdaf_registration_info_local_var;
end:
    if (nwdaf_registration_listList) {
        OpenAPI_list_for_each(nwdaf_registration_listList, node) {
            OpenAPI_nwdaf_registration_free(node->data);
        }
        OpenAPI_list_free(nwdaf_registration_listList);
        nwdaf_registration_listList = NULL;
    }
    return NULL;
}

OpenAPI_nwdaf_registration_info_t *OpenAPI_nwdaf_registration_info_copy(OpenAPI_nwdaf_registration_info_t *dst, OpenAPI_nwdaf_registration_info_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_nwdaf_registration_info_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_nwdaf_registration_info_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        log_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        log_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_nwdaf_registration_info_free(dst);
    dst = OpenAPI_nwdaf_registration_info_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

