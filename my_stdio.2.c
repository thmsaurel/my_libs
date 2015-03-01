/*******************************************************************************
 *
 * File Name         : my_stdio.2.c
 * Created By        : Thomas Aurel
 * Creation Date     : February 28th, 2015
 * Last Change       : March  1th, 2015 at 22:34:26
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions
 *
 * Filetype          : vim: filetype=c
 *
 *******************************************************************************/
#include "my_stdio.h"
/**
 *
 **/
int my_putfloat_base(float f, int b, int u, char flag){
    int i = f;
    f = (f - i) * b;
    my_putnbr_base(i, b, u, flag);
    if (f != 0.0 || flag == '#'){
        my_putchar('.');
        do{
            i = f;
            f = (f - i) * b;
            my_putnbr_base(i, b, u, '1');
        }while(f != 0.0);
    }
    return 0;
}

/**
 *
 **/
int my_putfloat(float f, int u, char flag){
    return my_putfloat_base(f, 10, u, flag);
}
