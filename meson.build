project(
    'neolibc-interface',
    'c',
    default_options: ['default_library=static', 'c_std=c11'],
    license: 'MIT'
)

compiler = meson.get_compiler('c').get_id()

incdir = include_directories('include')

sources = files([
    'src/print.c',
    'src/test.c'
])

binary_args = {
    'include_directories': incdir,
}

if compiler == 'gcc'
    message('Using GNU C11 standard.')
    binary_args += {'override_options': 'c_std=gnu11'}
endif

executable('tester', sources, kwargs: binary_args)
