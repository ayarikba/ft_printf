#include "ft_printf.h"

int print_char(char c)
{
    return (write(1, &c, 1));
}

int print_num(long i, int base, int st)
{
    static int ret;

    ret = 0;
    if (i < 0)
    {
        i *= -1;
        ret += print_char('-'); 
    }
    if (i >= base)
        print_num(i/base, base, st);
    if (st)
    ret += write(1, &UPPER[i % base], 1);
    else if (!st)
    ret += write(1, &LOWER[i % base], 1);
    return (ret);
}

 int print_str(char *str)
{
    if (!str)
        return (0);
    int i;
    int ret;

    i = -1;
    ret = 0;
    while(str[++i])
        ret += print_char(str[i]);

    return (ret);        
}

 int print_ptr(void *ptr)
{
    int ret;

    ret = 0;
    if (!ptr)
    {
        ret +=print_str("null");
        return (ret);
    }
    else 
    {
        ret += print_str("0x");
        ret += print_num((long)ptr, 16, 0);
    }
    return (ret);
}