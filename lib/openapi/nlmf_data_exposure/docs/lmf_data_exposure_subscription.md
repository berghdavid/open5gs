# lmf_data_exposure_subscription_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**notification_uri** | **char \*** | String providing an URI formatted according to RFC 3986. | 
**notify_correlation_id** | **char \*** | LCS Correlation ID. | 
**aoi** | [**presence_info_t**](presence_info.md) \* |  | 
**recur_time** | [**recur_time_t**](recur_time.md) \* |  | [optional] 
**num_of_samples** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**data_sources** | [**list_t**](data_source_type.md) \* |  | [optional] 
**quality_threshold** | [**location_qo_s_t**](location_qo_s.md) \* |  | [optional] 
**ml_model_id** | **int** | Unsigned Integer, i.e. only value 0 and integers above 0 are permissible. | [optional] 
**expiry_time** | **char \*** | string with format &#39;date-time&#39; as defined in OpenAPI. | [optional] 
**pru_indication** | **int** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


