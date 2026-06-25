# 3GPP TS 38.455 v19.1.0

nrppa_sources = run_command('sh', '-c', 'ls -1 *.c', check: true).stdout().strip().split('\n')

libnrppa_inc = include_directories('.')

libnrppa = library('asn1c-nrppa',
    sources : nrppa_sources,
    version : genlib_version,
    c_args : libasn1c_common_cc_flags,
    include_directories : libnrppa_inc,
    dependencies : [libasn1c_common_dep, libasn1c_util_dep],
    install : true,
)

libnrppa_dep = declare_dependency(
    link_with : libnrppa,
    include_directories : libnrppa_inc,
    dependencies : [libasn1c_common_dep, libasn1c_util_dep],
)
