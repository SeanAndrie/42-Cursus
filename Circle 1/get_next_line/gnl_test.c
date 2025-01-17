#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	buffer[256];
	int		chars_read;

	fd = open("file.txt", O_RDONLY);
	while (chars_read = read(fd, buffer, 25))
	{
		buffer[chars_read] = '\0';
		printf("buffer->%s\n", buffer);
	}
	return (0);
}
