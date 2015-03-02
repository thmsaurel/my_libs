/*******************************************************************************
 *
 * File Name         : my_stdio.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 15th, 2015
 * Last Change       : March  2th, 2015 at 23:00:01
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions
 *
 *******************************************************************************/
#include <unistd.h>
#include <stdlib.h>
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
char * my_putnbr_base(int i, int b, int u, char f, int w){
    char *nbr = malloc((w != 0 ? w : 10) * sizeof(char));
    char c1;
    verify_inf_size(b, 37);
    if(i < 0 || f == '+'){
        char sign = ( i < 0 ? '-' : '+');
        i = my_abs(i);
        nbr = my_strcat(nbr, &sign);
    }
    hashspace_flag(f, b, u);
    if (i > b)
        nbr = my_strcat(nbr, my_putnbr_base((i / b), b, u, '1', 0));
    if((i % b) < 10){
        c1 = ('0' + (i % b));
    } else if((i % b) < 37){
        c1 = (( u == 1 ? 'A' : 'a') + ((i % b) - 10));
    }
    nbr = my_strcat(nbr, &c1);
    return nbr;
}

/**
 * output a number on base 10
 *
 * param:   int i, the integer to write
 * return:  0 on success, else -1
 **/
char* my_putnbr(int i, char f, int w){
    return my_putnbr_base(i, 10, 0, f, w);
}

int hashspace_flag(char f, int b, int u){
    if (f == '#' && (b == 8 || b == 16)){
        my_putchar('0');
        if (b == 16){
            my_putchar((u == 1? 'X': 'x'));
        }
    }
    if (f == ' '){
        my_putchar(' ');
    }
    return 0;
}
