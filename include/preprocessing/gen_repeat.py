#!/bin/python3

# I am a utility script to generate repeat.h.
# This is here only for reference and the end user need not run it,
# since a finished repeat.h file is included in the Git repository.

MAX_REPEAT = 127

def write_macros(f, name, sep):
    # Output base macro.
    f.write('#define %s_1(expr) expr(1)\n' % name)

    # Output chaining macros.
    for i in range(2, MAX_REPEAT + 1):
        f.write('#define %s_%d(expr) expr(%d)%s %s_%d(expr)\n' \
                % (name, i, i, sep, name, i - 1))

    # Output maximum repeater alias.
    f.write('\n#define %s_MAX %s_%d\n' % (name, name, MAX_REPEAT))

    # Output variable repeater convenience macro.
    f.write('#define %s_N(n, expr) %s_##n(expr)\n' % (name, name))

with open('repeat.h', 'w') as f:
    # Output opening include guard
    f.write('#ifndef _NPP_REPEAT_H\n')
    f.write('#define _NPP_REPEAT_H\n')

    # Output comments
    f.write('\n// This is a machine-generated file.\n')
    f.write('// See gen_repeat.py to see how this file was made.\n')

    # Output macros for NPP_REPEAT_*
    f.write('\n\n')
    write_macros(f, 'NPP_REPEAT', '')

    # Output macros for NPP_REPEAT_SEP_*
    f.write('\n\n')
    write_macros(f, 'NPP_REPEAT_SEP', ',')

    # Output closing include guard
    f.write('\n#endif')
