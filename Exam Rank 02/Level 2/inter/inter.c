#include <unistd.h>

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return ((c == '\0') ? (char *)s : NULL);
}

int main(int ac, char *av[])
{
    int seen[256] = {0};

    if (ac == 3)
    {
        while (*av[1])
        {
            if (ft_strchr(av[2], *av[1]) && !seen[(unsigned char)*av[1]])
            {
                write(1, av[1], 1);
                seen[(unsigned char)*av[1]] = 1;
            }
            av[1]++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
