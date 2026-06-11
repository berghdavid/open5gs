conf_data = configuration_data()

conf_data.set('sysconfdir', sysconfdir)

gen = configure_file(
  input : 'lmf.yaml.in',
  output : 'lmf.yaml',
  configuration : conf_data,
)
meson.add_install_script(
  python3_exe,
  '-c',
  install_conf.format(gen, sysconfdir),
)
