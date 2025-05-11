#include <unistd.h>

int ft_tolower(int c)
{
    return ((c >= 'A' && c <= 'Z') ? c += 32 : c, c);
}

int ft_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int n_repeats(int c)
{
    int idx;
    char lwr_c;
    char *alpha;

    idx = 0;
    lwr_c = ft_tolower(c);
    alpha = "abcdefghijklmnopqrstuvwxyz";

    while (alpha[idx])
    {
        if (alpha[idx] == lwr_c)
            return (idx + 1);
        idx++;
    }
    return (-1);
}

int main(int ac, char *av[])
{
    char *s;
    int n;
        
    if (ac == 2)
    {
        s = av[1];
        while (*s)
        {
            if (!ft_isalpha(*s))
                write(1, s, 1);
            else
            {
                n = n_repeats(*s);
                while (n-- > 0)
                    write(1, s, 1);
            }
            s++;
        }
    }
    write(1, "\n", 1);

    return (0);
}
