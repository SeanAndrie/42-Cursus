#include <unistd.h>

int ft_tolower(int c)
{
    return ((c >= 'A' && c <= 'Z') ? c += 32 : c, c);
}

int ft_toupper(int c)
{
    return ((c >= 'a' && c <= 'z') ? c -= 32 : c, c);
}

int main(int ac, char *av[])
{
    unsigned int i;

    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            if ((av[1][i] >= 'A' && av[1][i] <= 'Z'))
                av[1][i] = ft_tolower(av[1][i]);
            else if ((av[1][i] >= 'a' && av[1][i] <= 'z'))
                av[1][i] = ft_toupper(av[1][i]);
            write(1, &av[1][i++], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
