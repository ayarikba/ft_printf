#ifndef FT_PRINFT_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

#ifndef UPPER
#define UPPER "0123456789ABCDEF"
#endif

#ifndef LOWER
#define LOWER "0123456789abcdef"
#endif

 int print_char(char c);
 int print_num(long long i, int base, int st);
 int print_str(char *str);
 int print_ptr(unsigned long long ptr);
int ft_printf(const char *x, ...);
 int print(va_list lst, const char *x, int i);
int	ft_hex_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format);
 int write_ptr(unsigned long long i, unsigned int base, int st);


#endif