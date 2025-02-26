#include <stdlib.h>

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int *ft_range(int start, int end)
{
    int size = ft_abs(end - start) + 1, i = 0;
    int *range = (int *)malloc(sizeof(int) * size);
    if (!size)
        return (NULL);
    while (i < size)
    {
        if (start < end)
           range[i] = start++;
        else
            range[i] = start--;
        i++;
    }
    return (range);
}

#include <stdio.h>

int main(void)
{
    int *range = ft_range(0, 0);
    for (int i = 0; i < ft_abs(0 - 3) + 1; i++)
        printf("%d\n", range[i]);
    free(range);
    return (0);
}

