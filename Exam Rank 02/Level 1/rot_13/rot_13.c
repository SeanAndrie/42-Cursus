#include <unistd.h>
#include <stdio.h>

int main(int ac, char *av[])
{
    char *s;

    if (ac == 2)
    {
        s = av[1];
        while (*s)
        {
            if ((*s >= 'A' && *s <= 'M') || ((*s >= 'a' && *s <= 'm')))
                *s += 13;
            else if ((*s >= 'N' && *s <= 'Z') || (*s >= 'n' && *s <= 'z'))
                *s -= 13;
            write(1, s++, 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
