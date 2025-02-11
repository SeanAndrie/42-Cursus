#include <stdlib.h>
#include <stdio.h>

static char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == c)
            return ((char *)s);
        s++;
    }
    if (*s == c)
        return ((char *)s);
    return (NULL);
}

size_t ft_strcpsn(const char *s, const char *reject)
{
    size_t len;

    len = 0;
    while (*s)
    {
        if (ft_strchr(reject, *s))
            break;
        len++;    
        s++;
    }
    return (len);
}

int main(void)
{
    printf("%ld\n", ft_strcpsn("Hello, World!", ""));
    return (0);
}
