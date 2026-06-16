
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_measurement_req.h"

OpenAPI_loc_measurement_req_t *OpenAPI_loc_measurement_req_create(
    OpenAPI_ncgi_t *ncgi,
    OpenAPI_ecgi_t *ecgi,
    OpenAPI_geographic_area_t *pre_calcu_loc_estimate,
    char *timestamp_of_pre_calcu_loc_estimate,
    OpenAPI_list_t *time_windows,
    OpenAPI_time_windows_nrppa_t *time_windows_nrppa,
    OpenAPI_positioning_method_t *method,
    OpenAPI_list_t *trp_parameters
)
{
    OpenAPI_loc_measurement_req_t *loc_measurement_req_local_var = ogs_malloc(sizeof(OpenAPI_loc_measurement_req_t));
    ogs_assert(loc_measurement_req_local_var);

    loc_measurement_req_local_var->ncgi = ncgi;
    loc_measurement_req_local_var->ecgi = ecgi;
    loc_measurement_req_local_var->pre_calcu_loc_estimate = pre_calcu_loc_estimate;
    loc_measurement_req_local_var->timestamp_of_pre_calcu_loc_estimate = timestamp_of_pre_calcu_loc_estimate;
    loc_measurement_req_local_var->time_windows = time_windows;
    loc_measurement_req_local_var->time_windows_nrppa = time_windows_nrppa;
    loc_measurement_req_local_var->method = method;
    loc_measurement_req_local_var->trp_parameters = trp_parameters;

    return loc_measurement_req_local_var;
}

void OpenAPI_loc_measurement_req_free(OpenAPI_loc_measurement_req_t *loc_measurement_req)
{
    if (NULL == loc_measurement_req) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_ncgi_free(loc_measurement_req->ncgi);
    OpenAPI_ecgi_free(loc_measurement_req->ecgi);
    OpenAPI_geographic_area_free(loc_measurement_req->pre_calcu_loc_estimate);
    ogs_free(loc_measurement_req->timestamp_of_pre_calcu_loc_estimate);
    OpenAPI_list_for_each(loc_measurement_req->time_windows, node) {
        ogs_free(node->data);
    }
    OpenAPI_list_free(loc_measurement_req->time_windows);
    OpenAPI_time_windows_nrppa_free(loc_measurement_req->time_windows_nrppa);
    OpenAPI_positioning_method_free(loc_measurement_req->method);
    OpenAPI_list_for_each(loc_measurement_req->trp_parameters, node) {
        OpenAPI_trp_parameter_free(node->data);
    }
    OpenAPI_list_free(loc_measurement_req->trp_parameters);
    ogs_free(loc_measurement_req);
}

cJSON *OpenAPI_loc_measurement_req_convertToJSON(OpenAPI_loc_measurement_req_t *loc_measurement_req)
{
    cJSON *item = NULL;

    if (loc_measurement_req == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [LocMeasurementReq]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (loc_measurement_req->ncgi) {
    cJSON *ncgi_local_JSON = OpenAPI_ncgi_convertToJSON(loc_measurement_req->ncgi);
    if (ncgi_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [ncgi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [ncgi]");
        goto end;
    }
    }

    if (loc_measurement_req->ecgi) {
    cJSON *ecgi_local_JSON = OpenAPI_ecgi_convertToJSON(loc_measurement_req->ecgi);
    if (ecgi_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [ecgi]");
        goto end;
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [ecgi]");
        goto end;
    }
    }

    if (loc_measurement_req->pre_calcu_loc_estimate) {
    cJSON *pre_calcu_loc_estimate_local_JSON = OpenAPI_geographic_area_convertToJSON(loc_measurement_req->pre_calcu_loc_estimate);
    if (pre_calcu_loc_estimate_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [pre_calcu_loc_estimate]");
        goto end;
    }
    cJSON_AddItemToObject(item, "preCalcuLocEstimate", pre_calcu_loc_estimate_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [pre_calcu_loc_estimate]");
        goto end;
    }
    }

    if (loc_measurement_req->timestamp_of_pre_calcu_loc_estimate) {
    if (cJSON_AddStringToObject(item, "timestampOfPreCalcuLocEstimate", loc_measurement_req->timestamp_of_pre_calcu_loc_estimate) == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [timestamp_of_pre_calcu_loc_estimate]");
        goto end;
    }
    }

    if (loc_measurement_req->time_windows) {
    cJSON *time_windows = cJSON_AddArrayToObject(item, "timeWindows");
    if (time_windows == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [time_windows]");
        goto end;
    }

    OpenAPI_lnode_t *time_windows_node;
    OpenAPI_list_for_each(loc_measurement_req->time_windows, time_windows_node)  {
                    }
    }

    if (loc_measurement_req->time_windows_nrppa) {
    cJSON *time_windows_nrppa_local_JSON = OpenAPI_time_windows_nrppa_convertToJSON(loc_measurement_req->time_windows_nrppa);
    if (time_windows_nrppa_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [time_windows_nrppa]");
        goto end;
    }
    cJSON_AddItemToObject(item, "timeWindowsNrppa", time_windows_nrppa_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [time_windows_nrppa]");
        goto end;
    }
    }

    if (loc_measurement_req->method) {
    cJSON *method_local_JSON = OpenAPI_positioning_method_convertToJSON(loc_measurement_req->method);
    if (method_local_JSON == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [method]");
        goto end;
    }
    cJSON_AddItemToObject(item, "method", method_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [method]");
        goto end;
    }
    }

    if (loc_measurement_req->trp_parameters) {
    cJSON *trp_parametersList = cJSON_AddArrayToObject(item, "trpParameters");
    if (trp_parametersList == NULL) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [trp_parameters]");
        goto end;
    }

    OpenAPI_lnode_t *trp_parameters_node;
    if (loc_measurement_req->trp_parameters) {
        OpenAPI_list_for_each(loc_measurement_req->trp_parameters, trp_parameters_node) {
            cJSON *itemLocal = OpenAPI_trp_parameter_convertToJSON(trp_parameters_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed [trp_parameters]");
                goto end;
            }
            cJSON_AddItemToArray(trp_parametersList, itemLocal);
        }
    }
    }

end:
    return item;
}

OpenAPI_loc_measurement_req_t *OpenAPI_loc_measurement_req_parseFromJSON(cJSON *loc_measurement_reqJSON)
{
    OpenAPI_loc_measurement_req_t *loc_measurement_req_local_var = NULL;
    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "ncgi");

    OpenAPI_ncgi_t *ncgi_local_nonprim = NULL;
    if (ncgi) {
    ncgi_local_nonprim = OpenAPI_ncgi_parseFromJSON(ncgi);
    }

    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "ecgi");

    OpenAPI_ecgi_t *ecgi_local_nonprim = NULL;
    if (ecgi) {
    ecgi_local_nonprim = OpenAPI_ecgi_parseFromJSON(ecgi);
    }

    cJSON *pre_calcu_loc_estimate = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "preCalcuLocEstimate");

    OpenAPI_geographic_area_t *pre_calcu_loc_estimate_local_nonprim = NULL;
    if (pre_calcu_loc_estimate) {
    pre_calcu_loc_estimate_local_nonprim = OpenAPI_geographic_area_parseFromJSON(pre_calcu_loc_estimate);
    }

    cJSON *timestamp_of_pre_calcu_loc_estimate = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "timestampOfPreCalcuLocEstimate");

    if (timestamp_of_pre_calcu_loc_estimate) {
    if (!cJSON_IsString(timestamp_of_pre_calcu_loc_estimate)) {
        ogs_error("OpenAPI_loc_measurement_req_parseFromJSON() failed [timestamp_of_pre_calcu_loc_estimate]");
        goto end;
    }
    }

    cJSON *time_windows = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "timeWindows");

    OpenAPI_list_t *time_windowsList;
    if (time_windows) {
    cJSON *time_windows_local;
    if (!cJSON_IsArray(time_windows)) {
        ogs_error("OpenAPI_loc_measurement_req_parseFromJSON() failed [time_windows]");
        goto end;
    }
    time_windowsList = OpenAPI_list_create();

    cJSON_ArrayForEach(time_windows_local, time_windows) {
    }
    }

    cJSON *time_windows_nrppa = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "timeWindowsNrppa");

    OpenAPI_time_windows_nrppa_t *time_windows_nrppa_local_nonprim = NULL;
    if (time_windows_nrppa) {
    time_windows_nrppa_local_nonprim = OpenAPI_time_windows_nrppa_parseFromJSON(time_windows_nrppa);
    }

    cJSON *method = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "method");

    OpenAPI_positioning_method_t *method_local_nonprim = NULL;
    if (method) {
    method_local_nonprim = OpenAPI_positioning_method_parseFromJSON(method);
    }

    cJSON *trp_parameters = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "trpParameters");

    OpenAPI_list_t *trp_parametersList;
    if (trp_parameters) {
    cJSON *trp_parameters_local_nonprimitive;
    if (!cJSON_IsArray(trp_parameters)){
        ogs_error("OpenAPI_loc_measurement_req_parseFromJSON() failed [trp_parameters]");
        goto end;
    }

    trp_parametersList = OpenAPI_list_create();

    cJSON_ArrayForEach(trp_parameters_local_nonprimitive, trp_parameters ) {
        if (!cJSON_IsObject(trp_parameters_local_nonprimitive)) {
            ogs_error("OpenAPI_loc_measurement_req_parseFromJSON() failed [trp_parameters]");
            goto end;
        }
        OpenAPI_trp_parameter_t *trp_parametersItem = OpenAPI_trp_parameter_parseFromJSON(trp_parameters_local_nonprimitive);

        if (!trp_parametersItem) {
            ogs_error("No trp_parametersItem");
            OpenAPI_list_free(trp_parametersList);
            goto end;
        }

        OpenAPI_list_add(trp_parametersList, trp_parametersItem);
    }
    }

    loc_measurement_req_local_var = OpenAPI_loc_measurement_req_create (
        ncgi ? ncgi_local_nonprim : NULL,
        ecgi ? ecgi_local_nonprim : NULL,
        pre_calcu_loc_estimate ? pre_calcu_loc_estimate_local_nonprim : NULL,
        timestamp_of_pre_calcu_loc_estimate ? ogs_strdup(timestamp_of_pre_calcu_loc_estimate->valuestring) : NULL,
        time_windows ? time_windowsList : NULL,
        time_windows_nrppa ? time_windows_nrppa_local_nonprim : NULL,
        method ? method_local_nonprim : NULL,
        trp_parameters ? trp_parametersList : NULL
    );

    return loc_measurement_req_local_var;
end:
    return NULL;
}

OpenAPI_loc_measurement_req_t *OpenAPI_loc_measurement_req_copy(OpenAPI_loc_measurement_req_t *dst, OpenAPI_loc_measurement_req_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_loc_measurement_req_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_loc_measurement_req_convertToJSON() failed");
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

    OpenAPI_loc_measurement_req_free(dst);
    dst = OpenAPI_loc_measurement_req_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

