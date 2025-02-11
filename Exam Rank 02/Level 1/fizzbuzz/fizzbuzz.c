#include <unistd.h>

void ft_putnbr(int n)
{
    char c;

    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

void ft_putstr(const char *s)
{
    while (*s)
        write(1, s++, 1);
}

int main(void)
{
    unsigned int i = 1;

    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            ft_putstr("fizzbuzz");
        else if (i % 3 == 0)
            ft_putstr("fizz");
        else if (i % 5 == 0)
            ft_putstr("buzz");
        else
            ft_putnbr(i);
        i++;
        write(1, "\n", 1);
    }
    return (0);
}
