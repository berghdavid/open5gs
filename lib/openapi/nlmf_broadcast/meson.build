
curl_dep = dependency('libcurl')

openapi_cc_flags = []
if cc.get_id() == 'gcc' or cc.get_id() == 'clang'
    openapi_cc_flags += cc.get_supported_arguments([
                    '-Wno-strict-prototypes',
                    '-Wno-error=strict-prototypes',
                    '-Wno-missing-prototypes',
                    '-Wno-missing-declarations',
                    '-Wno-unused-variable',
                    '-Wno-unused-label',
                    '-Wno-float-equal',
    ])
endif

openapi_sources = files('''
	src/list.c
	src/binary.c
	src/apiClient.c
	src/apiKey.c

	external/cJSON.c

	api/RequestCipheringKeyDataAPI.c

	model/query_param_combination.c
	model/access_token_err.c
	model/ciphering_key_response.c
	model/query_parameter.c
	model/storage_outcome.c
	model/no_profile_match_info.c
	model/ciphering_data_set.c
	model/data_availability.c
	model/ciphering_key_info.c
	model/invalid_param.c
	model/cipher_request_data.c
	model/no_profile_match_reason.c
	model/object.c
	model/access_token_req.c
	model/nf_type.c
	model/cipher_response_data.c
	model/snssai.c
	model/ml_model_inter_ind.c
	model/plmn_id.c
	model/plmn_id_nid.c
	model/ciphering_set_report.c
	model/redirect_response.c
	model/problem_details.c
	model/nwdaf_event.c
'''.split())

libnlmf_broadcast = library(
  'nlmf_openapi',
  sources: openapi_sources,
  c_args: openapi_cc_flags,
  include_directories: include_directories(
    'include',
    'model',
    'api'
  ),
  dependencies: [curl_dep],
  install: true,
)

libnlmf_broadcast_dep = declare_dependency(
  link_with: libnlmf_broadcast,
  include_directories: include_directories(
    'include',
    'model',
    'api',
  ),
  dependencies: [curl_dep],
)
