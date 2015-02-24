/*******************************************************************************
 *
 * file name         : main.c
 * creation date     : November 25th, 2014
 * created by        : Thomas AUREL
 * Last Change       : February 24th, 2015 at 01:03:48
 * Last Changed By   : Thomas Aurel
 * purpose           : description
 *
 *******************************************************************************/
#include <stdlib.h>
#include "my_libc.h"
#include "my_stdio.h"
#include "my_string.h"

int main(int argc, char **argv){
   my_printf("ceci est un test %d d'entier et %f de floatant \n", 58, 3.1419);
   return 0;
}

