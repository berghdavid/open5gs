# IndividualSubscriptionDocumentAPI

All URIs are relative to *https://example.com/nlmf-dataexposure/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**IndividualSubscriptionDocumentAPI_deleteSubscription**](IndividualSubscriptionDocumentAPI.md#IndividualSubscriptionDocumentAPI_deleteSubscription) | **DELETE** /subscriptions/{subscriptionId} | Nlmf_DataExposure Unsubscribe service Operation
[**IndividualSubscriptionDocumentAPI_modifySubscription**](IndividualSubscriptionDocumentAPI.md#IndividualSubscriptionDocumentAPI_modifySubscription) | **PATCH** /subscriptions/{subscriptionId} | Nlmf_DataExposure Subscribe Modify service Operation


# **IndividualSubscriptionDocumentAPI_deleteSubscription**
```c
// Nlmf_DataExposure Unsubscribe service Operation
//
void IndividualSubscriptionDocumentAPI_deleteSubscription(apiClient_t *apiClient, char *subscriptionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**subscriptionId** | **char \*** | Deletion of Subscription | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **IndividualSubscriptionDocumentAPI_modifySubscription**
```c
// Nlmf_DataExposure Subscribe Modify service Operation
//
void IndividualSubscriptionDocumentAPI_modifySubscription(apiClient_t *apiClient, char *subscriptionId, list_t *patch_item);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**subscriptionId** | **char \*** | Unique ID of the subscription to be modified | 
**patch_item** | **[list_t](patch_item.md) \*** |  | 

### Return type

void

### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json-patch+json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

