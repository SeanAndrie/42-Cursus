#include <unistd.h>

int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

int main(int ac, char *av[])
{
    unsigned int start;

    if (ac == 2)
    {
        start = 0;
        while (av[1][start]) start++;
        if (start == 0)
        {
            write(1, "\n", 1);
            return (0);
        }
        start--;
        while (start > 0 && ft_isspace(av[1][start])) start--;
        while (start > 0 && !ft_isspace(av[1][start])) start--;
        start++;
        while (av[1][start] && !ft_isspace(av[1][start]))
            write(1, &av[1][start++], 1);
    }
    write(1, "\n", 1);
    return (0);
}