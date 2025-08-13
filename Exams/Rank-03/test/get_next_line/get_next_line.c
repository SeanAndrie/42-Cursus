#include "get_next_line.h"

size_t ft_strlen(char *s)
{
    size_t len = 0;
    while (s[len]) len++;
    return (len);
}

char *join_line(char *line, char *chunk, size_t chunk_len)
{
    size_t i = 0, j = 0;
    if (!chunk)
        return (NULL);
    size_t line_len = (line) ? ft_strlen(line) : 0;
    size_t size = line_len + chunk_len + 1;
    if (size < line_len || size < chunk_len)
        return (NULL);
    char *join = malloc(size);
    if (!join)
        return (NULL);
    if (line)
    {
        while (i < line_len)
        {
            join[i] = line[i];
            i++;
        }
        free(line);
    }
    while (j < chunk_len)
    {
        join[line_len + j] = chunk[j];
        j++;
    }
    join[line_len + chunk_len] = '\0';
    return (join);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static size_t bytes_read = 0;
    static size_t pos = 0;
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    while (1)
    {
        if (pos >= bytes_read)
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            pos = 0;
            if (bytes_read == -1)
                return (free(line), NULL);
            if (bytes_read == 0)
                return (pos = bytes_read = 0, line);
        }
        size_t chunk_len = 0;
        while (pos + chunk_len < bytes_read && buffer[pos + chunk_len] != '\n')
            chunk_len++;
        int include_newline = (pos + chunk_len < bytes_read && buffer[pos + chunk_len] == '\n');
        char *joined_line = join_line(line, buffer + pos, chunk_len + include_newline);
        if (!joined_line)
            return (free(line), NULL);
        line = joined_line;
        pos += chunk_len + include_newline;
        if (include_newline)
            break;
    }
    return (line);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("sample.txt", O_RDONLY);
    if (fd < 0)
        return (perror("fd error: "), 1);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
