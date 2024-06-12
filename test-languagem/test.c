#include <stdio.h>
#include <stdarg.h>

void logInt(int x, ...){
    va_list vaList;

    va_start(vaList, x);

    for(int i = 0; i < x; i++){
        printf("%i\n", x);
    }

    va_end(vaList);
}   