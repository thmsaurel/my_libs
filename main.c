/*******************************************************************************
 *
 * file name         : main.c
 * creation date     : November 25th, 2014
 * created by        : Thomas AUREL
 * Last Change       : March  2th, 2015 at 23:13:38
 * Last Changed By   : Thomas Aurel
 * purpose           : description
 *
 *******************************************************************************/
#include <stdlib.h>
#include "my_libc.h"
#include "my_stdio.h"
#include "my_string.h"

int main(int argc, char **argv){
    my_printf("ceci est un test %d (-58) et %s\n", -58, "bonne nuit les petits");
    return 0;
}

