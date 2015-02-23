/*******************************************************************************
 *
 * File Name         : my_stdio.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 15th, 2015
 * Last Change       : January 31th, 2015 at 19:23:29
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions
 *
 *******************************************************************************/
#include <unistd.h>
#include "error.h"
#include "my_string.h"
#include "my_stdio.h"
#include "my_libc.h"
/**
 * output a character or word to a stream
 *
 * param:   char c, the character to write
 * return:  return 1 on success
 **/
int my_putchar(char c){
    return return_verification_int(write(1, &c, sizeof(char)), 1);
}

/**
 * output a line to a stream
 *
 * param:   char *str, the line to write
 * return:  0 on success
 **/
int my_puts(char *str){
    for(int i = 0; i < my_strlen(str); i++){
        my_putchar(str[i]);
    }
    return 0;
}

/**
 * output a number on a base
 *
 * param:   int i, the integer to write
 *          int b, the base to the character
 * return:  0 on success, else -1
 **/
int my_putnbr_base(int i, int b){
    int result = verify_inf_size(b, 37);
    if(i<0){
        my_putchar('-');
        i = my_abs(i);
    }
    if (i > b){
        result = my_putnbr_base((i / b), b);
    }
    if((i % b) < 10){
        my_putchar('0' + (i % b));
    } else if((i % b) < 37){
        my_putchar('A' + ((i % b) - 10));
    }
    return 0;
}

/**
 * output a number on base 10
 *
 * param:   int i, the integer to write
 * return:  0 on success, else -1
 **/
int my_putnbr(int i){return my_putnbr_base(i, 10);}
