/*******************************************************************************
 *
 * file name         : main.c
 * creation date     : November 25th, 2014
 * created by        : Thomas AUREL
 * Last Change       : March  2th, 2015 at 22:07:14
 * Last Changed By   : Thomas Aurel
 * purpose           : description
 *
 *******************************************************************************/
#include <stdlib.h>
#include "my_libc.h"
#include "my_stdio.h"
#include "my_string.h"

int main(int argc, char **argv){
    my_printf("ceci est un test '%3.12f' d'entier et '%10f' de floatant \n", 58.0, 3.1419);
    return 0;
}

