#include <stdlib.h>

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int *ft_rrange(int start, int end)
{
    int size = ft_abs(end - start) + 1, i = 0;
    int *range = (int *)malloc(sizeof(int) * size);
    if (!range)
        return (NULL);
    while (i < size)
    {
        if (end < start)
            range[i] = end++;
        else
            range[i] = end--;
        i++;
    }
    return (range);
}

#include <stdio.h>

int main(void)
{
    int start = -1, end = 3;
    int *range = ft_rrange(start, end);
    for (int i = 0; i < ft_abs(end - start) + 1; i++)
        printf("%d\n", range[i]);
    free(range);
    return (0);
}
