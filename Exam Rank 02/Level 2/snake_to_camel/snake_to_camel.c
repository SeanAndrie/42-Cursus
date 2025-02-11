#include <unistd.h>

int ft_toupper(int c)
{
    return ((c >= 'a' && c <= 'z') ? c -= 32 : c);
}

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        while (*av[1])
        {
            if (*av[1] == '_')
            {
                av[1]++;
                *av[1] = ft_toupper(*av[1]);
            }
            write(1, av[1]++, 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
