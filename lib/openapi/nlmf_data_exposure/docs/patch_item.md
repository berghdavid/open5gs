# patch_item_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**op** | [**patch_operation_t**](patch_operation.md) \* |  | 
**path** | **char \*** | contains a JSON pointer value (as defined in IETF RFC 6901) that references a location of a resource on which the patch operation shall be performed.  | 
**from** | **char \*** | indicates the path of the source JSON element (according to JSON Pointer syntax) being moved or copied to the location indicated by the \&quot;path\&quot; attribute.  | [optional] 
**value** | **any_type_t \*** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


