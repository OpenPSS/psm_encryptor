project('psm_encryptor', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'],)


cpp = meson.get_compiler('cpp')
dirbase = meson.current_source_dir()

if build_machine.system() == 'darwin'
libdir = join_paths(dirbase, 'lib/darwin64')
inc = include_directories('include/darwin64')
else
libdir = join_paths(dirbase, 'lib/unix')
inc = include_directories('include/unix')
endif

libcrypto_dep = cpp.find_library('libcrypto', dirs : libdir, static: true)
libssl_dep = cpp.find_library('libssl', dirs : libdir, static: true)

libpsm_encryptor = static_library('psm_encryptor',
        'HexKey.cpp',
        'PsmEdata.cpp',
        'PsmKeys.cpp',
        'OpenSSL.cpp',
        'psm_encryptor.cpp',
        include_directories : inc,
        install : true,
        dependencies : [
          libcrypto_dep,
          libssl_dep
        ],
        cpp_args : '-D_PSM_SIGNTOOL_BUILD')

libpsm_encryptor_dep = declare_dependency(include_directories: inc, link_with: libpsm_encryptor)