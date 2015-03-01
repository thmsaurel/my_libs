/*******************************************************************************
 *
 * File Name         : my_stdio.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 15th, 2015
 * Last Change       : March  1th, 2015 at 22:20:16
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
 *          int u, 1 if upper, 0 else
 *          char f, the flag character
 * return:  0 on success, else -1
 **/
int my_putnbr_base(int i, int b, int u, char f){
    int result = verify_inf_size(b, 37);
    if(result != 0){
        return -1;
    }
    if(i<0){
        my_putchar('-');
        i = my_abs(i);
    } else if (f == '+'){
        my_putchar('+');
    }
    if (f == '#'){
        if (b == 8){
            my_putchar('0');
        }else if (b == 16){
            if ( u == 1){
                my_puts("0X");
            }else{
                my_puts("0x");
            }
        }
    }
        if (i > b){
            result = my_putnbr_base((i / b), b, u, '1');
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
    int my_putnbr(int i, char f){
        return my_putnbr_base(i, 10, 0, f);
    }
