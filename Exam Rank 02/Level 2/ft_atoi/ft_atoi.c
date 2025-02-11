#include <stdio.h>

int ft_atoi(const char *str)
{
    long res = 0;
    int sign = 1;

    while ((*str >= 9 && *str <= 13) || *str == 32) str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str && (*str >= '0' && *str <= '9'))
        res = res * 10 + *str++ - '0';
    return (res * sign);
}
