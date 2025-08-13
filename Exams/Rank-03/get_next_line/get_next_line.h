#ifndef GNL_H
#define GNL_H

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);

#endif