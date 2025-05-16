#include <stdio.h>
#include <stdlib.h>

void    print_fprime(int n)
{
    if (n < 2)
    {
        printf("%d", n < 0 ? 0 : n);
        return ;
    }
    while (n % 2 == 0)
        printf("2*"), n /= 2;
    int i = 3;
    while (i * i <= n)
    {
        while (n % i == 0)
            printf("%d*", i), n /= i;
        i += 2;
    }
    if (n > 1)
        printf("%d", n);
}

int main(int ac, char **av)
{
    int n;

    if (ac == 2)
    {
        n = atoi(av[1]);
        print_fprime(n);
    }
    printf("\n");
    return (0);
}
