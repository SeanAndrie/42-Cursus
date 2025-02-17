#include <unistd.h>

int ft_tolower(int c)
{
    return ((c >= 'A' && c <= 'Z') ? c += 32 : c);
}

int get_alpha_idx(int c, char *alpha)
{
    int idx = 0;
    int lwr_c = ft_tolower(c);

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
    char *alpha = "abcdefghijklmnopqrstuvwxyz";

    if (ac == 2)
    {
                
    }
    write(1, "\n", 1);
    return (0);
}
