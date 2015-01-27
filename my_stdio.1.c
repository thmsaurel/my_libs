/*******************************************************************************
 *
 * File Name         : my_stdio.1.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 18th, 2015
 * Last Change       : January 18th, 2015 at 23:27:31
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions (second file)
 *
 *******************************************************************************/
#include "my_stdio.h"
#include "my_string.h"
#include <stdarg.h>

char G_specifier[8] = {
    'c', 's', '%', 'd', 'i', 'o', 'x', 'X',
    /* 'u', 'f', 'F',*/
    /*'e', 'E', 'g', 'G',*/
    /*'p', 'a', 'A', 'n', */
};
/*char G_flags[5] = {'-', '+', ' ', '#', '0',};*/

int print_specifier(char c, va_list ap){
    if (c == '%'){
        my_putchar('%');
    } else if(c == 's'){
        my_puts(va_arg(ap, char*));
    } else if(c == 'c'){
        my_putchar((char) va_arg(ap, int));
    } else if(c == 'i' || c == 'd'){
        my_putnbr(va_arg(ap, int));
    } else if(c == 'o'){
        my_putnbr_base(va_arg(ap, int), 8);
    } else if(c == 'x' || c == 'X'){
        my_putnbr_base(va_arg(ap, int), 16);
    }
    return 0;
}

/**
 * This is the main function for printf
 **/
int my_printf(char *format, ...){
    /*Variable Declarations*/
    int text_size = my_strlen(format);
    va_list ap;
    va_start(ap, format);
    /*Function Body*/
    for(int i=0; i<text_size; i++){
        if (format[i] == '%'){
            i += 1;
            print_specifier(format[i], ap);
        } else {
            my_putchar(format[i]);
        }
    }
    /*End*/
    va_end(ap);
    return 0;
}
