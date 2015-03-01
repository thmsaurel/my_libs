/*******************************************************************************
*
* File Name         : my_stdio.h
* Created By        : Thomas Aurel
* Creation Date     : January 15th, 2015
* Last Change       : March  1th, 2015 at 23:06:52
* Last Changed By   : Thomas Aurel
* Purpose           : standard input/output library functions
*
*******************************************************************************/
#include <stdarg.h>

/* my_stdio.c */
int my_putchar(char c);
int my_putnbr(int i, char f);
int my_putnbr_base(int i, int b, int u, char f);
int my_puts(char *str);

/* my_stdio.1.c */
int my_printf(char *format, ...);
int print_specifier(char c, va_list ap, char f, int w);
int print_flag(char c);

/* my_stdio.2.c */
int my_putfloat(float f, int u, char flag);
int my_putfloat_base(float f, int b, int u, char flag);
