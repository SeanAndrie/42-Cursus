
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    char c;
    if (n == 0)
        write(fd, "0", 1);
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr_fd(n / 10, fd);
    c = n % 10 + '0';
    write(fd, &c, 1);
}
