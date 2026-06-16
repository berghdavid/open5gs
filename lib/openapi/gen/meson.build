
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

	api/DetermineLocationAPI.c
	api/UPSubscribeAPI.c
	api/CancelLocationAPI.c
	api/LocationContextTransferAPI.c
	api/IndividualSubscriptionDocumentAPI.c
	api/RequestCipheringKeyDataAPI.c
	api/SubscriptionsCollectionAPI.c
	api/UPConfigureAPI.c
	api/UPUnsubscribeAPI.c
	api/LocationMeasureAPI.c

	model/positioning_method_and_usage.c
	model/units_angular_velocity.c
	model/event_class.c
	model/occurrence_info.c
	model/location_qo_s.c
	model/external_client_type.c
	model/add_location_context.c
	model/related_ue.c
	model/related_ue_type.c
	model/query_param_combination.c
	model/alert_limit.c
	model/point_altitude_uncertainty.c
	model/civic_address.c
	model/trp_parameter.c
	model/ue_area_indication.c
	model/add_event_notify_datas.c
	model/indoor_outdoor_ind.c
	model/local_area.c
	model/event_report_message.c
	model/local2d_point_uncertainty_ellipse.c
	model/integrity_computing_entity.c
	model/point.c
	model/mapped_location_qo_s_eps.c
	model/relative_cartesian_location.c
	model/access_token_err.c
	model/reporting_area.c
	model/any_type.c
	model/ciphering_key_response.c
	model/horizontal_with_vertical_velocity.c
	model/query_parameter.c
	model/storage_outcome.c
	model/loc_measurement_req.c
	model/high_accuracy_gnss_metrics.c
	model/loc_context_data.c
	model/no_profile_match_info.c
	model/motion_event_info.c
	model/uncertainty_ellipsoid.c
	model/model_3_d_relative_location.c
	model/periodic_event_info.c
	model/ciphering_data_set.c
	model/event_reporting_status.c
	model/gnss_positioning_method_and_usage.c
	model/positioning_method.c
	model/velocity_estimate.c
	model/time_windows_nrppa.c
	model/data_availability.c
	model/location_data_ext.c
	model/ellipsoid_arc.c
	model/recur_type.c
	model/accuracy_fulfilment_indicator.c
	model/reporting_access_type.c
	model/lmf_data_exposure_sampling_data.c
	model/presence_state.c
	model/ciphering_key_info.c
	model/invalid_param.c
	model/up_connection_status.c
	model/point_uncertainty_ellipse.c
	model/ranging_sl_result.c
	model/patch_operation.c
	model/access_type.c
	model/termination_cause.c
	model/up_cum_evt_rpt_criteria.c
	model/sl_positioning_capability.c
	model/guami.c
	model/point_altitude.c
	model/cipher_request_data.c
	model/up_notify_data.c
	model/supported_gad_shapes.c
	model/no_profile_match_reason.c
	model/cm_state.c
	model/local3d_point_uncertainty_ellipsoid.c
	model/area_event_info.c
	model/valid_time_period.c
	model/patch_item.c
	model/object.c
	model/point_uncertainty_circle.c
	model/usage.c
	model/radial_velocity.c
	model/ue_connectivity_state.c
	model/access_token_req.c
	model/ldr_type.c
	model/ue_up_positioning_capabilities.c
	model/location_data.c
	model/lmf_data_exposure_cause.c
	model/lcs_up_connection_ind.c
	model/range_direction.c
	model/gnss_id.c
	model/ue_lcs_capability.c
	model/nf_type.c
	model/cipher_response_data.c
	model/integrity_requirements.c
	model/positioning_mode.c
	model/mbsr_info.c
	model/gnb_id.c
	model/lmf_data_exposure_subscription.c
	model/vertical_direction.c
	model/lcs_priority.c
	model/snssai.c
	model/event_notify_data_ext.c
	model/ue_location_info.c
	model/ml_model_inter_ind.c
	model/determine_location_request.c
	model/plmn_id.c
	model/input_data.c
	model/global_ran_node_id.c
	model/ecgi.c
	model/up_loc_rep_addr_af.c
	model/horizontal_with_vertical_velocity_and_uncertainty.c
	model/ue_location_service_ind.c
	model/plmn_id_nid.c
	model/ciphering_set_report.c
	model/local_origin.c
	model/geographical_coordinates.c
	model/lp_hap_type.c
	model/angular_velocity.c
	model/add_location_datas.c
	model/model_2_d_relative_location.c
	model/geographic_area.c
	model/velocity_requested.c
	model/integrity_result.c
	model/reporting_ind.c
	model/ncgi.c
	model/redirect_response.c
	model/integrity_protection_level.c
	model/twap_id.c
	model/up_config.c
	model/cancel_loc_data.c
	model/horizontal_velocity.c
	model/units_linear_velocity.c
	model/ipv6_addr.c
	model/lcs_qos_class.c
	model/relative_velocity_with_uncertainty.c
	model/response_time.c
	model/additional_ue_info.c
	model/uncertainty_ellipse.c
	model/loc_measurements.c
	model/ref_to_binary_data.c
	model/tai.c
	model/up_subscription.c
	model/los_nlos_measure_ind.c
	model/tnap_id.c
	model/loc_measurement_resp.c
	model/minor_location_qo_s.c
	model/event_notify_data.c
	model/polygon.c
	model/lmf_data_exposure_notification.c
	model/lcs_broadcast_assistance_types_data.c
	model/fix_type.c
	model/problem_details.c
	model/data_source_type.c
	model/presence_info.c
	model/horizontal_velocity_with_uncertainty.c
	model/recur_time.c
	model/gad_shape.c
	model/reporting_area_type.c
	model/nwdaf_event.c
	model/lmf_data_exposure_report.c
	model/reported_event_type.c
'''.split())

openapi_lib = library(
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

openapi_dep = declare_dependency(
  link_with: openapi_lib,
  include_directories: include_directories(
    'include',
    'model',
    'api',
  ),
  dependencies: [curl_dep],
)
