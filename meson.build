project('psm_encryptor', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14', 'default_library=static'],)


cpp = meson.get_compiler('cpp')
dirbase = meson.current_source_dir()

cargs = ['-D_PSM_SIGNTOOL_BUILD']
largs = []
if target_machine.system() == 'darwin'
    cargs += ['-arch', 'arm64', '-arch', 'x86_64']
    largs += ['-arch', 'arm64', '-arch', 'x86_64']
    libdir = join_paths(dirbase, 'lib/darwin')
    inc = include_directories('include/darwin')
else
libdir = join_paths(dirbase, 'lib/unix')
inc = include_directories('include/unix')
endif

libcrypto_dep = cpp.find_library('crypto', dirs : libdir, static: true)
libssl_dep = cpp.find_library('ssl', dirs : libdir, static: true)

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
        cpp_args : cargs,
        link_args: largs)

libpsm_encryptor_dep = declare_dependency(include_directories: inc, link_with: libpsm_encryptor)
