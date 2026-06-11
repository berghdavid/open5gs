conf_data = configuration_data()

conf_data.set('sysconfdir', sysconfdir)

file = 'lmf.yaml'

configure_file(
  input : file + '.in',
  output : file,
  configuration : conf_data,
)
meson.add_install_script(
  python3_exe,
  '-c',
  install_conf.format(file, sysconfdir),
)
