#include <stdio.h>

void ft_swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

char *ft_strrev(char *str)
{
    int start, end;

    if (!str || !*str)
        return (NULL);
        
    start = 0;
    end = 0;
    while (str[end]) end++;
    end--;
    while (start < end)
        ft_swap(&str[start++], &str[end--]);
    return (str);
}
