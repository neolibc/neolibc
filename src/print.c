#include "print.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static void unreachable() {
    fputs("An invariant has been breached. This is a bug in NeoLibC. "
          "Please file an issue.", stderr);
    abort();
}

// TODO: cover every case.
// Avoid printf using custom rendering routines.
// Return the number of characters printed (?)

void _nio_print(long n, ...) {
    va_list ap;

    va_start(ap, n);

    for (long i = 0; i < n; ++i) {
        NioFormatter fmt = va_arg(ap, NioFormatter);

        switch (fmt.kind) {
            case NIO_FORMATTER_CHAR:
                printf("%c", fmt.as_char);
                break;
            case NIO_FORMATTER_INT:
                printf("%d", fmt.as_int);
                break;
            case NIO_FORMATTER_CSTR:
                printf("%s", fmt.as_cstr);
                break;
            default:
                unreachable();
        }
    }

    va_end(ap);
}
