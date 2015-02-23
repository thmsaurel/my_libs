/*******************************************************************************
*
* File Name         : my_stdio.h
* Created By        : Thomas Aurel
* Creation Date     : January 15th, 2015
* Last Change       : February 24th, 2015 at 00:33:14
* Last Changed By   : Thomas Aurel
* Purpose           : standard input/output library functions
*
*******************************************************************************/
#include <stdarg.h>

/* my_stdio.c */
int my_putchar(char c);
int my_putnbr(int i);
int my_putnbr_base(int i, int b);
int my_putnbr_base_upper(int i, int b);
int my_puts(char *str);

/* my_stdio.1.c */
int my_printf(char *format, ...);
int print_specifier(char c, va_list ap);
int my_putfloat(float f);
int my_putfloat_base(float f, int b);
