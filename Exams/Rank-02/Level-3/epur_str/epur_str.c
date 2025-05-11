#include <unistd.h>

int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

int main(int ac, char *av[])
{
    char *end;

    if (ac == 2)
    {
        end = av[1];
        while (*end) end++;
        while (end > av[1])
        {
            char *word_end = end;
            while (end > av[1] && !ft_isspace(*(end - 1))) end--;
            write(1, end, word_end - end);
            if (end != av[1])
                write(1, " ", 1);
            while (end > av[1] && ft_isspace(*(end - 1))) end--;
        }
    }
    write(1, "\n", 1);
    return (0);   
}