/*******************************************************************************
 *
 * File Name         : my_stdio.1.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 18th, 2015
 * Last Change       : February 21th, 2015 at 18:58:39
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions (second file)
 *
 *******************************************************************************/
/**
 * This is documentation for my_printf function.
 *
 * this is a list of main argument for my_printf specifier (after '%')
 *    DONE:
 *       c, s, %, d, i, o, x, X
 *    TODO: u, f, F, e, E, g, G, p, a, A, n
 *
 * this is a list of flags to complete my_printf instruction
 *    TODO: -, +, #, 0
 *
 **/
#include "my_stdio.h"
#include "my_string.h"
#include <stdarg.h>

char G_specifier[8] = {
   'c', 's', '%', 'd', 'i', 'o', 'x', 'X',
};

int print_specifier(char c, va_list ap){
   if (c == '%'){
      my_putchar('%');
   } else if(c == 's'){
      my_puts(va_arg(ap, char*));
   } else if(c == 'c'){
      my_putchar((char) va_arg(ap, int));
   } else if(c == 'i' || c == 'd'){
      my_putnbr(va_arg(ap, int));
   } else if(c == 'o'){
      my_putnbr_base(va_arg(ap, int), 8);
   } else if(c == 'x' || c == 'X'){
      my_putnbr_base(va_arg(ap, int), 16);
   }
   return 0;
}

/**
 * This is the main function for printf
 **/
int my_printf(char *format, ...){
   /*Variable Declarations*/
   int text_size = my_strlen(format);
   va_list ap;
   va_start(ap, format);
   /*Function Body*/
   for(int i=0; i<text_size; i++){
      if (format[i] == '%'){
         i += 1;
         if(verify_char_tab(format[i], G_specifier)){
            print_specifier(format[i], ap);
         }
      } else {
         my_putchar(format[i]);
      }
   }
   /*End*/
   va_end(ap);
   return 0;
}
