#ifndef FT_PRINFT_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef UPPER
#define UPPER "0123456789ABCDEF"
#endif

#ifndef LOWER
#define LOWER "0123456789abcdef"
#endif

 int print_char(char c);
 int print_num(long i, int base, int st);
 int print_str(char *str);
 int print_ptr(void *ptr);
int ft_printf(const char *x, ...);
 int print(va_list lst, const char *x, int i);



#endif