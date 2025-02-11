#include <unistd.h>

int main(int ac, char *av[])
{
    char *s2;
    int i, len;

    if (ac == 3)
    {
        len = 0;
        while (av[1][len]) len++;
        i = 0;
        s2 = av[2];
        while (av[1][i] && *s2)
        {
            if (av[1][i] == *s2++)
                i++;
        }
        if (i == len)
            write(1, av[1], len);
    }
    write(1, "\n", 1);
    return (0);
}
