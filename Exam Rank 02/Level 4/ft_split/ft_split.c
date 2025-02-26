#include <stdlib.h>

int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

void *ft_calloc(size_t n, size_t size)
{
    size_t total_size = n * size;
    if (size != 0 && total_size / size != n)
        return (NULL);
    void *res = malloc(total_size);
    if (!res)
        return (NULL);
    unsigned char *b_res = (unsigned char *)res;
    while (total_size--)
        *b_res++ = 0;
    return (res);
}

int count_words(char *str)
{
    int count = 0, in_word = 0;
    while (*str)
    {
        if (!ft_isspace(*str) && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (ft_isspace(*str))
            in_word = 0;
        str++;
    }
    return (count);
}

char *alloc_word(char **str)
{
    char *start;
    while (**str && ft_isspace(**str)) str++;
    start = *str;
    int i = 0, len = 0;
    while (**str && !ft_isspace(**str))
    {
        len++;
        (*str)++;
    }
    char *word = ft_calloc(len + 1, sizeof(char));
    if (!word)
        return (NULL);
    while (i < len)
    {
        word[i] = start[i];
        i++;
    }
    return (word);
}

void *free_splits(char **splits, int i)
{
    while (i >= 0)
        free(splits[--i]);
    free(splits);
    return (NULL);
}

char **ft_split(char *str)
{
    if (!str)
        return (NULL);
    char **splits = ft_calloc(count_words(str) + 1, sizeof(char *));
    if (!splits)
        return (NULL);
    int i = 0;
    while (*str)
    {
        if (*str && ft_isspace(*str))
            str++;
        else
        {
            splits[i] = alloc_word(&str);
            if (!splits[i])
                return (free_splits(splits, i));
            i++;
        }
    }
    return (splits);
}

#include <stdio.h>

int main(void)
{
    char s[] = "the quick brown fox jumped over the lazy dog";
    char **splits = ft_split(s);
    for (int i = 0; i < count_words(s); i++)
    {
        printf("%s\n", splits[i]);
        free(splits[i]);
    }
    free(splits);
    return (0);
}
