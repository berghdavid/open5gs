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
openapi_cc_flags += cc.get_supported_arguments([
    '-w', '-std=c99',
])

subdir('nlmf_broadcast')
subdir('nlmf_data_exposure')
subdir('nlmf_location')

libapi_inc = include_directories('.')

libgnutls_dep = dependency('gnutls', required : true)
libssl_dep = dependency('libssl', required : true)
libcrypto_dep = dependency('libcrypto', required : true)
libnghttp2_dep = dependency('libnghttp2', version: '>=1.18.1')
libmicrohttpd_dep = dependency('libmicrohttpd', version: '>=0.9.40')
libcurl_dep = dependency('libcurl', version: '>=7.52.1')

libapi = library('ogssbi',
    sources : libsbi_sources,
    version : genlib_version,
    c_args : sbi_cc_flags,
    include_directories : [libapi_inc, libinc],
    dependencies : [
        libcrypt_dep,
        libapp_dep,
        libsbi_openapi_dep,
        libgnutls_dep,
        libssl_dep,
        libcrypto_dep,
        libnghttp2_dep,
        libmicrohttpd_dep,
        libcurl_dep,
    ],
    install_rpath : libdir,
    install : true)

libapi_dep = declare_dependency(
    link_with : libapi,
    include_directories : [libapi_inc, libinc],
    dependencies : [
        libcrypt_dep,
        libapp_dep,
        libgnutls_dep,
        libnlmf_broadcast_dep,
        libnlmf_data_exposure_dep,
        libnlmf_location_dep,
        libssl_dep,
        libcrypto_dep,
        libnghttp2_dep,
        libmicrohttpd_dep,
        libcurl_dep,
    ])
