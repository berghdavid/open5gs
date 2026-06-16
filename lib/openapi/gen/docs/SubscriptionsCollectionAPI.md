# SubscriptionsCollectionAPI

All URIs are relative to *https://example.com/nlmf-dataexposure/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SubscriptionsCollectionAPI_createSubscription**](SubscriptionsCollectionAPI.md#SubscriptionsCollectionAPI_createSubscription) | **POST** /subscriptions | Nlmf_Data Exposure Subscribe Service Operation


# **SubscriptionsCollectionAPI_createSubscription**
```c
// Nlmf_Data Exposure Subscribe Service Operation
//
lmf_data_exposure_subscription_t* SubscriptionsCollectionAPI_createSubscription(apiClient_t *apiClient, lmf_data_exposure_subscription_t *lmf_data_exposure_subscription);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**lmf_data_exposure_subscription** | **[lmf_data_exposure_subscription_t](lmf_data_exposure_subscription.md) \*** |  | 

### Return type

[lmf_data_exposure_subscription_t](lmf_data_exposure_subscription.md) *


### Authorization

[oAuth2ClientCredentials](../README.md#oAuth2ClientCredentials)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, application/problem+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

