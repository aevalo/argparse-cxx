project('argparse-cxx', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

lib_version_major = '0'
lib_version_minor = '1'
lib_version_patch = '0'
lib_version = '@0@.@1@.@2@'.format(lib_version_major, lib_version_minor,lib_version_patch)
lib_soversion = lib_version_major

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_ARGPARSE_CXX']

# Hiding symbols that are not explicitly marked as exported
# requires a compiler flag on all compilers except VS.
cpp = meson.get_compiler('cpp')
if cpp.get_id() != 'msvc'
  lib_args += ['-fvisibility=hidden']
endif

includes = include_directories('include/argparse-cxx')

lib_src = ['src/argparse-cxx.cpp']

if get_option('shared_lib')
  shlib = shared_library('argparse-cxx', lib_src,
    version: lib_version,
    soversion: lib_soversion,
    install : true,
    cpp_args : lib_args,
    include_directories : includes
  )
else
  shlib = static_library('argparse-cxx', lib_src,
    cpp_args : lib_args,
    include_directories : includes,
    pic: true,
    install: true
  )
endif

gtest_dep = dependency('gtest', version: '>=1.8.0', fallback: ['gtest', 'gmock_dep'])
unittest_src = ['tsrc/argparse-cxx-unit.cpp', 'tsrc/argparse-cxx-unit-main.cpp']
unittest = executable('argparse-cxx-unit', unittest_src,
  include_directories : includes,
  link_with : shlib,
  dependencies : gtest_dep)
test('argparse-cxx unit tests', unittest)

# Make this library usable as a Meson subproject.
argparse_cxx_dep = declare_dependency(link_with : shlib)

# Make this library usable from the system's
# package manager.
install_headers('include/argparse-cxx/argparse-cxx.hpp', subdir : 'argparse-cxx')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'argparse-cxx',
  filebase : 'argparse-cxx',
  description : 'Meson sample project.',
  subdirs : 'argparse-cxx',
  libraries : shlib,
  version : '0.1.0'
)
