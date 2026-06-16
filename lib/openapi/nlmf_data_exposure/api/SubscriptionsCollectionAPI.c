#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "SubscriptionsCollectionAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Nlmf_Data Exposure Subscribe Service Operation
//
lmf_data_exposure_subscription_t*
SubscriptionsCollectionAPI_createSubscription(apiClient_t *apiClient, lmf_data_exposure_subscription_t *lmf_data_exposure_subscription)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/subscriptions");





    // Body Param
    cJSON *localVarSingleItemJSON_lmf_data_exposure_subscription = NULL;
    if (lmf_data_exposure_subscription != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_lmf_data_exposure_subscription = lmf_data_exposure_subscription_convertToJSON(lmf_data_exposure_subscription);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_lmf_data_exposure_subscription);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/problem+json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Subscription Created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 307) {
    //    printf("%s\n","Temporary Redirect");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 308) {
    //    printf("%s\n","Permanent Redirect");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 411) {
    //    printf("%s\n","Length Required");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 413) {
    //    printf("%s\n","Content Too Large");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 415) {
    //    printf("%s\n","Unsupported Media Type");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 429) {
    //    printf("%s\n","Too Many Requests");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 501) {
    //    printf("%s\n","Not Implemented");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 502) {
    //    printf("%s\n","Bad Gateway");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 503) {
    //    printf("%s\n","Service Unavailable");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","Generic Error");
    //}
    //nonprimitive not container
    lmf_data_exposure_subscription_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *SubscriptionsCollectionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = lmf_data_exposure_subscription_parseFromJSON(SubscriptionsCollectionAPIlocalVarJSON);
        cJSON_Delete(SubscriptionsCollectionAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_lmf_data_exposure_subscription) {
        cJSON_Delete(localVarSingleItemJSON_lmf_data_exposure_subscription);
        localVarSingleItemJSON_lmf_data_exposure_subscription = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

