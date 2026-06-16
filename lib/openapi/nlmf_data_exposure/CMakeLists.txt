cmake_minimum_required (VERSION 2.6...3.10.2)
project (CGenerator C)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=implicit-function-declaration")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=missing-declarations")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=int-conversion")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

find_package(OpenSSL)

if (OPENSSL_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DOPENSSL")
    if(CMAKE_VERSION VERSION_LESS 3.4)
        include_directories(${OPENSSL_INCLUDE_DIR})
        include_directories(${OPENSSL_INCLUDE_DIRS})
        link_directories(${OPENSSL_LIBRARIES})
    endif()
endif()

set(pkgName "nlmf_dataexposure")

# this default version can be overridden in PreTarget.cmake
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

if( (DEFINED CURL_INCLUDE_DIR) AND (DEFINED CURL_LIBRARIES))
    include_directories(${CURL_INCLUDE_DIR})
    set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else()
    find_package(CURL 7.58.0 REQUIRED)
    if(CURL_FOUND)
        include_directories(${CURL_INCLUDE_DIR})
        set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
    endif()
endif()

set(SRCS
    src/list.c
    src/apiKey.c
    src/apiClient.c
    src/binary.c
    external/cJSON.c
    model/object.c
    model/access_token_err.c
    model/access_token_req.c
    model/accuracy_fulfilment_indicator.c
    model/angular_velocity.c
    model/civic_address.c
    model/data_source_type.c
    model/ecgi.c
    model/ellipsoid_arc.c
    model/fix_type.c
    model/gad_shape.c
    model/geographic_area.c
    model/geographical_coordinates.c
    model/global_ran_node_id.c
    model/gnb_id.c
    model/gnss_id.c
    model/gnss_positioning_method_and_usage.c
    model/high_accuracy_gnss_metrics.c
    model/horizontal_velocity.c
    model/horizontal_velocity_with_uncertainty.c
    model/horizontal_with_vertical_velocity.c
    model/horizontal_with_vertical_velocity_and_uncertainty.c
    model/indoor_outdoor_ind.c
    model/integrity_computing_entity.c
    model/integrity_protection_level.c
    model/integrity_result.c
    model/invalid_param.c
    model/lcs_qos_class.c
    model/lmf_data_exposure_cause.c
    model/lmf_data_exposure_notification.c
    model/lmf_data_exposure_report.c
    model/lmf_data_exposure_sampling_data.c
    model/lmf_data_exposure_subscription.c
    model/loc_measurements.c
    model/local2d_point_uncertainty_ellipse.c
    model/local3d_point_uncertainty_ellipsoid.c
    model/local_area.c
    model/local_origin.c
    model/location_data.c
    model/location_qo_s.c
    model/los_nlos_measure_ind.c
    model/minor_location_qo_s.c
    model/ml_model_inter_ind.c
    model/model_2_d_relative_location.c
    model/model_3_d_relative_location.c
    model/ncgi.c
    model/nf_type.c
    model/no_profile_match_info.c
    model/no_profile_match_reason.c
    model/nwdaf_event.c
    model/patch_item.c
    model/patch_operation.c
    model/periodic_event_info.c
    model/plmn_id.c
    model/plmn_id_nid.c
    model/point.c
    model/point_altitude.c
    model/point_altitude_uncertainty.c
    model/point_uncertainty_circle.c
    model/point_uncertainty_ellipse.c
    model/polygon.c
    model/positioning_method.c
    model/positioning_method_and_usage.c
    model/positioning_mode.c
    model/presence_info.c
    model/presence_state.c
    model/problem_details.c
    model/query_param_combination.c
    model/query_parameter.c
    model/radial_velocity.c
    model/range_direction.c
    model/recur_time.c
    model/recur_type.c
    model/redirect_response.c
    model/relative_cartesian_location.c
    model/relative_velocity_with_uncertainty.c
    model/response_time.c
    model/snssai.c
    model/supported_gad_shapes.c
    model/tai.c
    model/ue_area_indication.c
    model/uncertainty_ellipse.c
    model/uncertainty_ellipsoid.c
    model/units_angular_velocity.c
    model/units_linear_velocity.c
    model/usage.c
    model/valid_time_period.c
    model/velocity_estimate.c
    model/vertical_direction.c
    api/IndividualSubscriptionDocumentAPI.c
    api/SubscriptionsCollectionAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/binary.h
    include/keyValuePair.h
    external/cJSON.h
    model/object.h
    model/any_type.h
    model/access_token_err.h
    model/access_token_req.h
    model/accuracy_fulfilment_indicator.h
    model/angular_velocity.h
    model/civic_address.h
    model/data_source_type.h
    model/ecgi.h
    model/ellipsoid_arc.h
    model/fix_type.h
    model/gad_shape.h
    model/geographic_area.h
    model/geographical_coordinates.h
    model/global_ran_node_id.h
    model/gnb_id.h
    model/gnss_id.h
    model/gnss_positioning_method_and_usage.h
    model/high_accuracy_gnss_metrics.h
    model/horizontal_velocity.h
    model/horizontal_velocity_with_uncertainty.h
    model/horizontal_with_vertical_velocity.h
    model/horizontal_with_vertical_velocity_and_uncertainty.h
    model/indoor_outdoor_ind.h
    model/integrity_computing_entity.h
    model/integrity_protection_level.h
    model/integrity_result.h
    model/invalid_param.h
    model/lcs_qos_class.h
    model/lmf_data_exposure_cause.h
    model/lmf_data_exposure_notification.h
    model/lmf_data_exposure_report.h
    model/lmf_data_exposure_sampling_data.h
    model/lmf_data_exposure_subscription.h
    model/loc_measurements.h
    model/local2d_point_uncertainty_ellipse.h
    model/local3d_point_uncertainty_ellipsoid.h
    model/local_area.h
    model/local_origin.h
    model/location_data.h
    model/location_qo_s.h
    model/los_nlos_measure_ind.h
    model/minor_location_qo_s.h
    model/ml_model_inter_ind.h
    model/model_2_d_relative_location.h
    model/model_3_d_relative_location.h
    model/ncgi.h
    model/nf_type.h
    model/no_profile_match_info.h
    model/no_profile_match_reason.h
    model/nwdaf_event.h
    model/patch_item.h
    model/patch_operation.h
    model/periodic_event_info.h
    model/plmn_id.h
    model/plmn_id_nid.h
    model/point.h
    model/point_altitude.h
    model/point_altitude_uncertainty.h
    model/point_uncertainty_circle.h
    model/point_uncertainty_ellipse.h
    model/polygon.h
    model/positioning_method.h
    model/positioning_method_and_usage.h
    model/positioning_mode.h
    model/presence_info.h
    model/presence_state.h
    model/problem_details.h
    model/query_param_combination.h
    model/query_parameter.h
    model/radial_velocity.h
    model/range_direction.h
    model/recur_time.h
    model/recur_type.h
    model/redirect_response.h
    model/relative_cartesian_location.h
    model/relative_velocity_with_uncertainty.h
    model/response_time.h
    model/snssai.h
    model/supported_gad_shapes.h
    model/tai.h
    model/ue_area_indication.h
    model/uncertainty_ellipse.h
    model/uncertainty_ellipsoid.h
    model/units_angular_velocity.h
    model/units_linear_velocity.h
    model/usage.h
    model/valid_time_period.h
    model/velocity_estimate.h
    model/vertical_direction.h
    api/IndividualSubscriptionDocumentAPI.h
    api/SubscriptionsCollectionAPI.h

)

include(PreTarget.cmake OPTIONAL)

set(PROJECT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Add library with project file with project name as library name
if(NOT BUILD_STATIC_LIBS)
  add_library(${pkgName} ${SRCS} ${HDRS})
else()
  add_library(${pkgName} STATIC ${SRCS} ${HDRS})
endif()
# Link dependent libraries
if(NOT CMAKE_VERSION VERSION_LESS 3.4)
    target_link_libraries(${pkgName} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
endif()
target_link_libraries(${pkgName} PUBLIC ${CURL_LIBRARIES} )
target_include_directories(
    ${pkgName} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

include(PostTarget.cmake OPTIONAL)

# installation of libraries, headers, and config files
if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in)
    install(TARGETS ${pkgName} DESTINATION lib)
else()
    include(GNUInstallDirs)
    install(TARGETS ${pkgName} DESTINATION lib EXPORT ${pkgName}Targets)

    foreach(HDR_FILE ${HDRS})
        get_filename_component(HDR_DIRECTORY ${HDR_FILE} DIRECTORY)
        get_filename_component(ABSOLUTE_HDR_DIRECTORY ${HDR_DIRECTORY} ABSOLUTE)
        file(RELATIVE_PATH RELATIVE_HDR_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${ABSOLUTE_HDR_DIRECTORY})
        install(FILES ${HDR_FILE} DESTINATION include/${pkgName}/${RELATIVE_HDR_PATH})
    endforeach()

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            VERSION "${PROJECT_VERSION_STRING}"
            COMPATIBILITY AnyNewerVersion
    )

    export(EXPORT ${pkgName}Targets
            FILE "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Targets.cmake"
            NAMESPACE ${pkgName}::
            )

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            @ONLY
            )

    set(ConfigPackageLocation lib/cmake/${pkgName})
    install(EXPORT ${pkgName}Targets
            FILE
            ${pkgName}Targets.cmake
            NAMESPACE
            ${pkgName}::
            DESTINATION
            ${ConfigPackageLocation}
            )
    install(
            FILES
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            DESTINATION
            ${ConfigPackageLocation}
    )
endif()

# make installation packages
include(Packing.cmake OPTIONAL)

# Setting file variables to null
set(SRCS "")
set(HDRS "")


## This section shows how to use the above compiled library to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-IndividualSubscriptionDocumentAPI.c
#    unit-tests/manual-SubscriptionsCollectionAPI.c
#)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable does not support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created library to executable and dependent library curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})
