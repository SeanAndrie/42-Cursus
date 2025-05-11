#include <stdlib.h>

char *ft_strdup(char *src)
{
    char *dup;
    size_t len;

    len = 0;
    while (src[len]) len++;
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    dup[len] = '\0';
    while (len-- > 0)
        dup[len] = src[len];
    return (dup);
}
