#include <unistd.h>

int main(int ac, char *av[])
{
    size_t i;
    size_t len;

    if (ac == 3)
    {
        len = 0;
        while (av[1][len]) len++;
        i = 0;
        while (av[1][i] && *av[2])
        {
            if (av[1][i] == *av[2]++)
                i++;
        }
        if (i == len)
            write(1, av[1], len);
    }
    write(1, "\n", 1);
    return (0);
}
