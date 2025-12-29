#ifndef MICROSHELL_H
# define MICROSHELL_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>

#include <stdio.h> // remove later

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

typedef struct s_cmd
{
    char            **av;
    struct s_cmd    *next;
    bool            pipe_after;
}                   t_cmd;

#endif
