#include <unistd.h>

int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

int main(int ac, char *av[])
{
    char *s;

    if (ac == 2)
    {
        s = av[1];
        while (ft_isspace(*s)) s++;
        while (*s && !ft_isspace(*s))
            write(1, s++, 1);
    }
    write(1, "\n", 1);
    return (0);
}
