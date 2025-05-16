#include <unistd.h>
#include <stdlib.h>

int ft_isspace(int c) { return ((c >= 9 && c <= 13) || c == 32); }

static int count_words(char *s)
{
    int in_word = 0, n_words = 0;
    while (*s)
    {
        if (!ft_isspace(*s) && !in_word)
            in_word = 1, n_words++;
        else if (ft_isspace(*s))
            in_word = 0;
        s++;
    }
    return (n_words);
}

static char *alloc_word(char **str)
{
    int len = 0, i = -1;
    while (**str && ft_isspace(**str)) (*str)++;
    char *start = *str, *word;
    while (**str && !ft_isspace(**str)) (*str)++, len++;
    word = malloc(len + 1);
    if (!word) return (NULL);
    while (++i < len)
        word[i] = start[i];
    word[i] = '\0';
    return (word);
}

void    *free_tokens(char **tokens, int i)
{
    while (--i >= 0)
        free(tokens[i]);
    free(tokens);
    return (NULL);
}

char **ft_split(char *str)
{
    int size = count_words(str), i = 0;
    char **tokens = malloc(sizeof(char *) * (size + 1));
    if (!tokens)
        return (NULL);
    while (*str)
    {
        while (*str && ft_isspace(*str)) str++;
        if (*str)
        {
            tokens[i] = alloc_word(&str);
            if (!tokens[i]) return (free_tokens(tokens, i));
            i++;
        }
    }
    tokens[i] = NULL;
    return (tokens);
}

void    ft_putstr(char *s)
{
    while (*s)
        write(1, s++, 1);
}

int main(int ac, char **av)
{
    int index, size;
    char **tokens;

    if (ac == 2)
    {
        index = size = count_words(av[1]);
        tokens = ft_split(av[1]);
        if (!tokens)
            return (1);
        while (index-- > 0)
        {
            ft_putstr(tokens[index]);
            if (index != 0)
                write(1, " ", 1);
        }
        free_tokens(tokens, size);
    }
    write(1, "\n", 1);
    return (0);
}
