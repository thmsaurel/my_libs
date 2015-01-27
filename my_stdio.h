/*******************************************************************************
*
* File Name         : my_stdio.h
* Created By        : Thomas Aurel
* Creation Date     : January 15th, 2015
* Last Change       : January 18th, 2015 at 23:27:56
* Last Changed By   : Thomas Aurel
* Purpose           : standard input/output library functions
*
*******************************************************************************/
#include <stdarg.h>
/* my_stdio.c */
int my_putchar(char c);
int my_putnbr(int i);
int my_putnbr_base(int i, int b);
int my_puts(char *str);

/* my_stdio.1.c */
int my_printf(char *format, ...);
int print_specifier(char c, va_list ap);
