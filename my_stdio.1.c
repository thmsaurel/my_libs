/*******************************************************************************
 *
 * File Name         : my_stdio.1.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 18th, 2015
 * Last Change       : March  1th, 2015 at 23:24:00
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions (second file)
 *
 *******************************************************************************/
/**
 * This is documentation for my_printf function.
 *
 * PRINTF Constructor :
 * %[flags][width][.precision][length]specifier
 *
 * flags :
 *    DONE: +, #
 *    TODO: -, ' ', 0
 *
 * width :
 *    TODO: \w, *
 *
 * precision :
 *    TODO: .\w, .*
 *
 *
 * specifier :
 *    DONE: c, s, %, d, i, o, x, X, f, F
 *    TODO: u, e, E, g, G, p, a, A, n
 *
 **/
#include "my_stdio.h"
#include "my_string.h"
#include "error.h"
#include <stdarg.h>

int G_flags_size = 5;
char G_flags[5] = {
    '-', '+', ' ', '#', '0'
};

int G_width_size = 11;
char G_width[11] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*'
};

int G_precision_size = 11;
char G_precision[11] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*'
};

int G_specifier_size = 10;
char G_specifier[11] = {
    'c', 's', '%', 'd', 'i', 'o', 'x', 'X', 'f', 'F'
};

int print_flag(char c){
    /*if (c == '+')*/
    return 0;
}

int print_specifier(char c, va_list ap, char f, int w){
    if (c == '%'){
        my_putchar('%');
    } else if(c == 's'){
        my_puts(va_arg(ap, char*));
    } else if(c == 'c'){
        my_putchar((char) va_arg(ap, int));
    } else if(c == 'i' || c == 'd'){
        my_putnbr(va_arg(ap, int), f);
    } else if(c == 'o'){
        my_putnbr_base(va_arg(ap, int), 8, 0, f);
    } else if(c == 'x'){
        my_putnbr_base(va_arg(ap, int), 16, 0, f);
    } else if(c == 'X'){
        my_putnbr_base(va_arg(ap, int), 16, 1, f);
    } else if(c == 'f' ){
        my_putfloat((float) va_arg(ap, double) , 0, f);
    } else if(c == 'F'){
        my_putfloat((float) va_arg(ap, double) , 1, f);
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
    char flag = '1';
    int width = 0;
        va_start(ap, format);
    /*Function Body*/
    for(int i=0; i<text_size; i++){
        if (format[i] == '%'){
            i += 1;
            if(verify_char_tab(format[i], G_flags, G_flags_size)){
                flag = format[i];
                i += 1;
            }
            if(verify_char_tab(format[i], G_width, G_width_size)){
                do{
                    width = width*10 + (format[i] - '0');
                    i += 1;
                }while('0' <= format[i] <= '9');
            }
            if(verify_char_tab(format[i], G_specifier, G_specifier_size)){
                print_specifier(format[i], ap, flag, width);
            }
        } else {
            my_putchar(format[i]);
        }
    }
    /*End*/
    va_end(ap);
    return 0;
}
