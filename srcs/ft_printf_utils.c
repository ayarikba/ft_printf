#include "ft_printf.h"
#include <ulimit.h>
int print_char(char c)
{
    return (write(1, &c, 1));
}

int print_num( long long i, int base, int st)
{
    int ret = 0;

    if (i < 0)
    {
        ret += write(1, "-", 1);
        ret += print_num((unsigned long long)(-i), base, st);
        return ret;
    }

    if (i >= base)
        ret += print_num(i / base, base, st);

    if (st)
        ret += write(1, &UPPER[i % base], 1);
    else
        ret += write(1, &LOWER[i % base], 1);

    return ret;
}

 int print_str(char *str)
{
       if (str == NULL)
        str = "(null)";
    int i;
    int ret;

    i = -1;
    ret = 0;


    while(str[++i])
        ret += print_char(str[i]);

    return (ret);        
}

 int write_ptr(unsigned long long i, unsigned int base, int st)
{
    int ret = 0;

   

    if (i >= base)
        ret += write_ptr(i / base, base, st);

    if (st)
        ret += write(1, &UPPER[i % base], 1);
    else
        ret += write(1, &LOWER[i % base], 1);

    return ret;
}
 
 int print_ptr(unsigned long long ptr)
{
    int ret;
    ret = 0;
    if (!ptr)
    {
        ret +=print_str("(nil)");
        return (ret);
    }
    else 
    {
        ret += print_str("0x");
            ret += write_ptr(ptr, 16, 0);
    }
    return (ret);
}

