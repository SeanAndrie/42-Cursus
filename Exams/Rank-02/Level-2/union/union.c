#include <unistd.h>

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *b_s;

    b_s = (unsigned char *)s;
    while (n--)
        *b_s++ = c;
    return (s);
}

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
    int seen[256];

    if (ac == 3)
    {
        ft_memset(seen, 0, sizeof(seen));
        while (*av[1])
        {
            if (!seen[(unsigned char)*av[1]])
            {
                write(1, av[1], 1);
                seen[(unsigned char)*av[1]] = 1;
            }
            av[1]++;
        }
        
        while (*av[2])
        {
            if (!seen[(unsigned char)*av[2]])
            {
                write(1, av[2], 1);
                seen[(unsigned char)*av[2]] = 1;
            }
            av[2]++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
