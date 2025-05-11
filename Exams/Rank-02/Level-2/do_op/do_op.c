#include <stdio.h>
#include <stdlib.h>

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return ((c == '\0') ? (char *)s : NULL);
}

int main(int ac, char *av[])
{
    if (ac == 4)
    {
        if (ft_strchr("+-*/%%", *av[2]))
        {
            if (*av[2] == '+')
                printf("%d", atoi(av[1]) + atoi(av[3]));
            else if (*av[2] == '-')
                printf("%d", atoi(av[1]) - atoi(av[3]));
            else if (*av[2] == '*')
                printf("%d", atoi(av[1]) * atoi(av[3]));
            else if (*av[2] == '/')
                printf("%d", atoi(av[1]) / atoi(av[3]));
            else if (*av[2] == '%')
                printf("%d", atoi(av[1]) % atoi(av[3]));
        }
    }
    printf("\n");
    return (0);
}
