#include <stdio.h>
#include "preprocessing/repeat.h"

#include "format.h"
#include "print.h"

#define variable(num) int x##num = num;
#define format(num) "%d "
#define param(num) x##num

int main(void) {
    NPP_REPEAT_127(variable)

    printf(NPP_REPEAT_MAX(format) "\n", NPP_REPEAT_SEP_MAX(param));

    _nio_print(4, nio_char('a'), nio_cstr(" boop! "), nio_int(7), nio_char('\n'));
    
    nio_print4(nio_char('a'), nio_cstr(" boop! "), nio_int(7), nio_char('\n'));
}
