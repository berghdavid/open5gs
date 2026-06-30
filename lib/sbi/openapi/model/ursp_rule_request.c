
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ursp_rule_request.h"

OpenAPI_ursp_rule_request_t *OpenAPI_ursp_rule_request_create(
    OpenAPI_traffic_descriptor_components_t *traffic_desc,
    bool is_relat_precedence,
    int relat_precedence,
    OpenAPI_list_t *route_sel_param_sets
)
{
    OpenAPI_ursp_rule_request_t *ursp_rule_request_local_var = ogs_malloc(sizeof(OpenAPI_ursp_rule_request_t));
    log_assert(ursp_rule_request_local_var);

    ursp_rule_request_local_var->traffic_desc = traffic_desc;
    ursp_rule_request_local_var->is_relat_precedence = is_relat_precedence;
    ursp_rule_request_local_var->relat_precedence = relat_precedence;
    ursp_rule_request_local_var->route_sel_param_sets = route_sel_param_sets;

    return ursp_rule_request_local_var;
}

void OpenAPI_ursp_rule_request_free(OpenAPI_ursp_rule_request_t *ursp_rule_request)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == ursp_rule_request) {
        return;
    }
    if (ursp_rule_request->traffic_desc) {
        OpenAPI_traffic_descriptor_components_free(ursp_rule_request->traffic_desc);
        ursp_rule_request->traffic_desc = NULL;
    }
    if (ursp_rule_request->route_sel_param_sets) {
        OpenAPI_list_for_each(ursp_rule_request->route_sel_param_sets, node) {
            OpenAPI_route_selection_parameter_set_free(node->data);
        }
        OpenAPI_list_free(ursp_rule_request->route_sel_param_sets);
        ursp_rule_request->route_sel_param_sets = NULL;
    }
    ogs_free(ursp_rule_request);
}

cJSON *OpenAPI_ursp_rule_request_convertToJSON(OpenAPI_ursp_rule_request_t *ursp_rule_request)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (ursp_rule_request == NULL) {
        log_error("OpenAPI_ursp_rule_request_convertToJSON() failed [UrspRuleRequest]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (ursp_rule_request->traffic_desc) {
    cJSON *traffic_desc_local_JSON = OpenAPI_traffic_descriptor_components_convertToJSON(ursp_rule_request->traffic_desc);
    if (traffic_desc_local_JSON == NULL) {
        log_error("OpenAPI_ursp_rule_request_convertToJSON() failed [traffic_desc]");
        goto end;
    }
    cJSON_AddItemToObject(item, "trafficDesc", traffic_desc_local_JSON);
    if (item->child == NULL) {
        log_error("OpenAPI_ursp_rule_request_convertToJSON() failed [traffic_desc]");
        goto end;
    }
    }

    if (ursp_rule_request->is_relat_precedence) {
    if (cJSON_AddNumberToObject(item, "relatPrecedence", ursp_rule_request->relat_precedence) == NULL) {
        log_error("OpenAPI_ursp_rule_request_convertToJSON() failed [relat_precedence]");
        goto end;
    }
    }

    if (ursp_rule_request->route_sel_param_sets) {
    cJSON *route_sel_param_setsList = cJSON_AddArrayToObject(item, "routeSelParamSets");
    if (route_sel_param_setsList == NULL) {
        log_error("OpenAPI_ursp_rule_request_convertToJSON() failed [route_sel_param_sets]");
        goto end;
    }
    OpenAPI_list_for_each(ursp_rule_request->route_sel_param_sets, node) {
        cJSON *itemLocal = OpenAPI_route_selection_parameter_set_convertToJSON(node->data);
        if (itemLocal == NULL) {
            log_error("OpenAPI_ursp_rule_request_convertToJSON() failed [route_sel_param_sets]");
            goto end;
        }
        cJSON_AddItemToArray(route_sel_param_setsList, itemLocal);
    }
    }

end:
    return item;
}

OpenAPI_ursp_rule_request_t *OpenAPI_ursp_rule_request_parseFromJSON(cJSON *ursp_rule_requestJSON)
{
    OpenAPI_ursp_rule_request_t *ursp_rule_request_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *traffic_desc = NULL;
    OpenAPI_traffic_descriptor_components_t *traffic_desc_local_nonprim = NULL;
    cJSON *relat_precedence = NULL;
    cJSON *route_sel_param_sets = NULL;
    OpenAPI_list_t *route_sel_param_setsList = NULL;
    traffic_desc = cJSON_GetObjectItemCaseSensitive(ursp_rule_requestJSON, "trafficDesc");
    if (traffic_desc) {
    traffic_desc_local_nonprim = OpenAPI_traffic_descriptor_components_parseFromJSON(traffic_desc);
    if (!traffic_desc_local_nonprim) {
        log_error("OpenAPI_traffic_descriptor_components_parseFromJSON failed [traffic_desc]");
        goto end;
    }
    }

    relat_precedence = cJSON_GetObjectItemCaseSensitive(ursp_rule_requestJSON, "relatPrecedence");
    if (relat_precedence) {
    if (!cJSON_IsNumber(relat_precedence)) {
        log_error("OpenAPI_ursp_rule_request_parseFromJSON() failed [relat_precedence]");
        goto end;
    }
    }

    route_sel_param_sets = cJSON_GetObjectItemCaseSensitive(ursp_rule_requestJSON, "routeSelParamSets");
    if (route_sel_param_sets) {
        cJSON *route_sel_param_sets_local = NULL;
        if (!cJSON_IsArray(route_sel_param_sets)) {
            log_error("OpenAPI_ursp_rule_request_parseFromJSON() failed [route_sel_param_sets]");
            goto end;
        }

        route_sel_param_setsList = OpenAPI_list_create();

        cJSON_ArrayForEach(route_sel_param_sets_local, route_sel_param_sets) {
            if (!cJSON_IsObject(route_sel_param_sets_local)) {
                log_error("OpenAPI_ursp_rule_request_parseFromJSON() failed [route_sel_param_sets]");
                goto end;
            }
            OpenAPI_route_selection_parameter_set_t *route_sel_param_setsItem = OpenAPI_route_selection_parameter_set_parseFromJSON(route_sel_param_sets_local);
            if (!route_sel_param_setsItem) {
                log_error("No route_sel_param_setsItem");
                goto end;
            }
            OpenAPI_list_add(route_sel_param_setsList, route_sel_param_setsItem);
        }
    }

    ursp_rule_request_local_var = OpenAPI_ursp_rule_request_create (
        traffic_desc ? traffic_desc_local_nonprim : NULL,
        relat_precedence ? true : false,
        relat_precedence ? relat_precedence->valuedouble : 0,
        route_sel_param_sets ? route_sel_param_setsList : NULL
    );

    return ursp_rule_request_local_var;
end:
    if (traffic_desc_local_nonprim) {
        OpenAPI_traffic_descriptor_components_free(traffic_desc_local_nonprim);
        traffic_desc_local_nonprim = NULL;
    }
    if (route_sel_param_setsList) {
        OpenAPI_list_for_each(route_sel_param_setsList, node) {
            OpenAPI_route_selection_parameter_set_free(node->data);
        }
        OpenAPI_list_free(route_sel_param_setsList);
        route_sel_param_setsList = NULL;
    }
    return NULL;
}

OpenAPI_ursp_rule_request_t *OpenAPI_ursp_rule_request_copy(OpenAPI_ursp_rule_request_t *dst, OpenAPI_ursp_rule_request_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_ursp_rule_request_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_ursp_rule_request_convertToJSON() failed");
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

    OpenAPI_ursp_rule_request_free(dst);
    dst = OpenAPI_ursp_rule_request_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

