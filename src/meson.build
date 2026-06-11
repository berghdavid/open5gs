srcinc = include_directories('.')

package_version = 'v' + meson.project_version()
if git.found()
    git_version = run_command('git', ['describe', '--abbrev=7', '--dirty=+'], check: false)
    if git_version.returncode() == 0
        package_version = git_version.stdout().strip()
    endif
endif

version_conf = configuration_data()
version_conf.set_quoted('LMF_VERSION', package_version)
configure_file(output : 'version.h', configuration : version_conf)

subdir('lmf')
