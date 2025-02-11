#include <unistd.h>

int ft_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

int ft_tolower(int c)
{
    return ((ft_isupper(c)) ? c += 32 : c, c);
}

int main(int ac, char *av[])
{
    unsigned int i;

    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            if (ft_isupper(av[1][i]))
            {
                av[1][i] = ft_tolower(av[1][i]);
                write(1, "_", 1);
            }
            write(1, &av[1][i++], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
