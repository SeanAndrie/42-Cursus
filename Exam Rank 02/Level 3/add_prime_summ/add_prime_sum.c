#include <unistd.h>
#include <limits.h>

int ft_atoi(const char *s)
{
    int res = 0, sign = 1;
    while ((*s >= 9 && *s <= 13) || *s == 32) s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign *= -1;
        s++;
    }
    while (*s && (*s >= '0' && *s <= '9'))
    {
        if (res > INT_MAX / 10 || res > INT_MAX / 10 && (*s - '0') > INT_MAX % 10)
            return ((sign == 1) ? INT_MAX : INT_MIN);
        res = res * 10 + (*s++ - '0');
    }
    return (res * sign);
}

int ft_isprime(int n)
{
    if (n == 2 | n == 3)
        return (1);
    if (n % 2 == 0 || n % 3 == 0)
        return (0);
    if (n < 2)
        return (0);

    int i = 0;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return (0);
        i += 6;
    }
    return (1);
}

void ft_putnbr(int n)
{
    char c;
    if (n > 9)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        int i = 0, sum = 0;
        while (i < ft_atoi(av[1]))
        {
            if (ft_isprime(i))
                sum += i;
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}


