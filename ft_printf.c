#include "ft_printf.h"

int print(va_list lst, const char *x, int i)
{
    int ret;

    ret = 0;
    if (x[i + 1] && x[i + 1] == 'c')
        ret += print_char(va_arg(lst, int));
    else if (x[i + 1] && x[i + 1] == 's')
        ret += print_str(va_arg(lst, char*));
    else if (x[i + 1] && x[i + 1] == 'p')
        ret += print_ptr(va_arg(lst, void*));
    else if (x[i + 1] && (x[i + 1] == 'd' || x[i + 1] == 'i'))
        ret += print_num(va_arg(lst, int), 10, 0);
    else if (x[i + 1] && x[i + 1] == 'u')
        ret += print_num(va_arg(lst, unsigned int), 10, 0);
    else if (x[i + 1] && x[i + 1] == 'x')
        ret += print_num(va_arg(lst, int),16, 0);
    else if (x[i + 1] && x[i + 1] == 'X')
        ret += print_num(va_arg(lst, int),16, 1);
    else if (x[i + 1] && x[i + 1] == '%')
        ret += print_char('%');
    return (ret);
}


int ft_printf(const char *x, ...)
{
    va_list lst;
    va_start(lst, x);
    int i;
    int val;

    i = 0;
    val = 0;
    while(x[i])
    {
        if (x[i] == '%')
           {
            val += print(lst, x, i);
            i++;
           } 
        else
            val += write(1, &x[i], 1);
        i++;
    }

    va_end(lst);
    return (val);
}
