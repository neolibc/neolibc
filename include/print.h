#ifndef _NIO_PRINT_H
#define _NIO_PRINT_H

#include "format.h"
#include "preprocessing/repeat.h"

void _nio_print(long n, ...);

#define _nio_param(n) NioFormatter val##n
#define _nio_arg(n) val##n
#define _nio_func(n) \
    static inline void nio_print##n(NPP_REPEAT_SEP_N(n, _nio_param)) { \
        _nio_print(n, NPP_REPEAT_SEP_N(n, _nio_arg)); \
    }

/*
// Example of an application of the _nio_func macro.

static inline void nio_print4(NPP_REPEAT_SEP_4(_nio_param)) {
    _nio_print(4, NPP_REPEAT_SEP_4(_nio_arg));
}

// This then becomes:

static inline void nio_print4(NioFormatter val4,
                              NioFormatter val3,
                              NioFormatter val2,
                              NioFormatter val1) {
    _nio_print(4, val4, val3, val2, val1);
}

*/

NPP_REPEAT_MAX(_nio_func)

#undef _nio_param
#undef _nio_arg
#undef _nio_func

#endif
