#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int ft_putstr(char *s)
{
    int len = 0;
    if (!s)
        return (write(1, "(null)", 6));
    while (s[len]) len++;
    return (write(1, s, len));
}

int ft_putnbr(int n)
{
    char buffer[12];
    int i = 0, len = 0;
    
    if (n == 0)
        return (write(1, "0", 1));
    if (n == INT_MIN)
        return (ft_putstr("-2147483648"));
    if (n < 0)
    {
        len += write(1, "-", 1);
        n = -n;
    }
    while (n > 0)
        buffer[i++] = (n % 10) + '0', n /= 10;
    while (i--)
        len += write(1, &buffer[i], 1);
    return (len);
}

int ft_puthex(unsigned int n)
{
    char *base = "0123456789abcdef";
    int i = 0, len = 0;
    char buffer[16];

    if (n == 0)
        return (write(1, "0", 1));
    while (n > 0)
        buffer[i++] = base[n % 16], n /= 16;
    while (i--)
        len += write(1, &buffer[i], 1);
    return (len);
}

int ft_printf(const char *format, ...)
{
    int len = 0;
    va_list args;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 's')
                len += ft_putstr(va_arg(args, char *));
            else if (*format == 'd')
                len += ft_putnbr(va_arg(args, int));
            else if (*format == 'x')
                len += ft_puthex(va_arg(args, unsigned int));
            else
                len += write(1, format, 1);
        }
        else
            len += write(1, format, 1);
        format++;
    }
    va_end(args);
    return (len);
}

int main(void)
{
    ft_printf("something%\nsomething");
    return (0);
}
