#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return ((c == '\0') ? (char *)s : NULL);
}

size_t ft_strspn(const char *s, const char *accept)
{
    size_t len;

    len = 0;
    while (*s)
    {
        if (!ft_strchr(accept, *s))
            break;
        len++;
        s++;
    }
    return (len);
}
