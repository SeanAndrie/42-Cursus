#include <unistd.h>

int main(int ac, char *av[])
{
    char *s;

    if (ac == 2)
    {
        s = av[1];
        while (*s)
        {
            if ((*s >= 'A' && *s <= 'Y') || (*s >= 'a' && *s <= 'y'))
                *s += 1;
            else if (*s == 'Z' || *s == 'z')
                *s -= 25;
            write(1, s++, 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
