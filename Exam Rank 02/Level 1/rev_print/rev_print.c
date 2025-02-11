#include <unistd.h>

int main(int ac, char *av[])
{
    char *s;
    int len;

    if (ac == 2)
    {
        s = av[1];
        while (s[len]) len++;
        while (len > 0)
            write(1, &s[--len], 1);
    }
    write(1, "\n", 1);
    return (0);
}
