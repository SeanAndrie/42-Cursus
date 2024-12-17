
#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    while (*s)
        write(fd, s++, 1);
    write(1, "\n", 1);
}
