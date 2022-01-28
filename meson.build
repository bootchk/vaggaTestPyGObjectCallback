project('testCallback', 'c')

glib_dep = dependency('glib-2.0')

# create meson var 'lib' for the library target
lib = library(
  'testCallback',       # name
  ['testCallback.c','testCallbackPersistent.c'],  # sources
  dependencies : glib_dep,  # uses GLib
  install: true
  )

# use meson's gnome module
gnome = import('gnome')

# command to generate gir
# Some args may not be necessary.
# The scanner doesn't seem to be smart enough to find the .h files
testCallback_gir = gnome.generate_gir(
  lib,                               # ref the library target
  sources: ['testCallback.c', 'testCallback.h', 'testCallbackPersistent.c', 'testCallbackPersistent.h'],
  namespace: 'TestCallback',
  nsversion: '1.0',                # required argument to g-ir-scanner
  identifier_prefix: 'TestCallback',
  symbol_prefix: 'testcallback',     # g-ir-scanner demands lower case
  export_packages: 'testcallback',
  includes: [ 'GObject-2.0', ],
  header: 'testCallback.h',
  install: true,
  extra_args: ['--verbose',]
)
