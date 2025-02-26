int is_valid_char(char c, int base)
{
    if (c >= '0' && c <= '9')
        return (c - '0' < base);
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10 < base);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10 < base);
    return (0);
}

int char_to_val(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int res = 0, sign = 1;
    while ((*str >= 9 && *str <= 13) || *str == 32) str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str && is_valid_char(*str, str_base))
        res = res * str_base + char_to_val(*str++);
    return (res * sign);
}

#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_atoi_base("-42", 10));
    return (0);
}

