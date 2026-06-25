
openapi_sources = files('''
  src/list.c
  src/binary.c
  src/apiClient.c
  src/apiKey.c

  external/cJSON.c

  api/IndividualSubscriptionDocumentAPI.c
  api/SubscriptionsCollectionAPI.c

  model/any_type.c
  model/positioning_method_and_usage.c
  model/units_angular_velocity.c
  model/location_qo_s.c
  model/query_param_combination.c
  model/point_altitude_uncertainty.c
  model/civic_address.c
  model/ue_area_indication.c
  model/indoor_outdoor_ind.c
  model/local_area.c
  model/local2d_point_uncertainty_ellipse.c
  model/integrity_computing_entity.c
  model/point.c
  model/relative_cartesian_location.c
  model/access_token_err.c
  model/horizontal_with_vertical_velocity.c
  model/query_parameter.c
  model/high_accuracy_gnss_metrics.c
  model/no_profile_match_info.c
  model/uncertainty_ellipsoid.c
  model/model_3_d_relative_location.c
  model/periodic_event_info.c
  model/gnss_positioning_method_and_usage.c
  model/positioning_method.c
  model/velocity_estimate.c
  model/ellipsoid_arc.c
  model/recur_type.c
  model/accuracy_fulfilment_indicator.c
  model/lmf_data_exposure_sampling_data.c
  model/presence_state.c
  model/invalid_param.c
  model/point_uncertainty_ellipse.c
  model/patch_operation.c
  model/point_altitude.c
  model/supported_gad_shapes.c
  model/no_profile_match_reason.c
  model/local3d_point_uncertainty_ellipsoid.c
  model/valid_time_period.c
  model/patch_item.c
  model/object.c
  model/point_uncertainty_circle.c
  model/usage.c
  model/radial_velocity.c
  model/access_token_req.c
  model/location_data.c
  model/lmf_data_exposure_cause.c
  model/range_direction.c
  model/gnss_id.c
  model/nf_type.c
  model/positioning_mode.c
  model/gnb_id.c
  model/lmf_data_exposure_subscription.c
  model/vertical_direction.c
  model/snssai.c
  model/ml_model_inter_ind.c
  model/plmn_id.c
  model/global_ran_node_id.c
  model/ecgi.c
  model/horizontal_with_vertical_velocity_and_uncertainty.c
  model/plmn_id_nid.c
  model/local_origin.c
  model/geographical_coordinates.c
  model/angular_velocity.c
  model/model_2_d_relative_location.c
  model/geographic_area.c
  model/integrity_result.c
  model/ncgi.c
  model/redirect_response.c
  model/integrity_protection_level.c
  model/horizontal_velocity.c
  model/units_linear_velocity.c
  model/lcs_qos_class.c
  model/relative_velocity_with_uncertainty.c
  model/response_time.c
  model/uncertainty_ellipse.c
  model/loc_measurements.c
  model/tai.c
  model/los_nlos_measure_ind.c
  model/minor_location_qo_s.c
  model/polygon.c
  model/lmf_data_exposure_notification.c
  model/fix_type.c
  model/problem_details.c
  model/data_source_type.c
  model/presence_info.c
  model/horizontal_velocity_with_uncertainty.c
  model/recur_time.c
  model/gad_shape.c
  model/nwdaf_event.c
  model/lmf_data_exposure_report.c
'''.split())

libnlmf_data_exposure = library(
  'nlmf_data_exposure',
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

libnlmf_data_exposure_dep = declare_dependency(
  link_with: libnlmf_data_exposure,
  include_directories: include_directories(
    'include',
    'model',
    'api',
  ),
  dependencies: [curl_dep],
)
