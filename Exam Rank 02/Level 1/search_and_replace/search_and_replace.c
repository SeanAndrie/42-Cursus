#include <unistd.h>

int ft_strlen(const char *s)
{
    int len = 0;
    while (s[len]) len++;
    return (len);
}

int main(int ac, char *av[])
{
    char *s;
    char *search;
    char *replace;

    if (ac == 4 && *av[1])
    {
        s = av[1];
        search = av[2];
        replace = av[3];
        
        if (ft_strlen(search) == 1 && ft_strlen(replace) == 1)
        {
            while (*s)
            {
                if (*s == *search)
                    *s = *replace;
                write(1, s++, 1);
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}
