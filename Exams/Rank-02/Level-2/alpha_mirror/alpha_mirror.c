#include <unistd.h>

int main(int ac, char *av[])
{
    unsigned int i;

    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                av[1][i] = 'Z' - av[1][i] + 'A';
            else if (av[1][i] >= 'a' && av[1][i] <= 'z')
                av[1][i] = 'z' - av[1][i] + 'a';
            write(1, &av[1][i++], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
