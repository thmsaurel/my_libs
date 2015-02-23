/*******************************************************************************
 *
 * File Name         : my_stdio.1.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 18th, 2015
 * Last Change       : February 24th, 2015 at 00:53:09
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions (second file)
 *
 *******************************************************************************/
/**
 * This is documentation for my_printf function.
 *
 * this is a list of main argument for my_printf specifier (after '%')
 *    DONE: c, s, %, d, i, o, x, X
 *    TODO: u, f, F, e, E, g, G, p, a, A, n
 *
 * this is a list of flags to complete my_printf instruction
 *    TODO: -, +, #, 0
 *
 **/
#include "my_stdio.h"
#include "my_string.h"
#include "error.h"
#include <stdarg.h>

char G_specifier[9] = {
   'c', 's', '%', 'd', 'i', 'o', 'x', 'X', 'f'
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
   } else if(c == 'x'){
      my_putnbr_base(va_arg(ap, int), 16);
   } else if(c == 'X'){
      my_putnbr_base_upper(va_arg(ap, int), 16);
   } else if(c == 'f'){
      my_putfloat(va_arg(ap, double));
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

/**
 *
 **/
int my_putfloat_base(float f, int b){
   int i = f;
  f = (f - i) * b;
   my_putnbr_base(i, b);
   my_putchar('.');
   do{
      i = f;
      f = (f - i) * b;
      my_putnbr_base(i, b);
   }while(f != 0);
   return 0;
}

/**
 *
 **/
int my_putfloat(float f){
   return my_putfloat_base(f, 10);
}
