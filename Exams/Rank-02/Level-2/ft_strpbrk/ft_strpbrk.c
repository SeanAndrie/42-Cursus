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

char *ft_strpbrk(const char *s1, const char *s2)
{
    if (!*s2)
        return (NULL);
    while (*s1)
    {
        if (ft_strchr(s2, *s1))
            return ((char *)s1);
        s1++;
    }
    return (NULL);
}
