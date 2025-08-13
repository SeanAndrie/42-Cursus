#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);

#endif