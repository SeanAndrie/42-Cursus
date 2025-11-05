#ifndef MICROSHELL_H
# define MICROSHELL_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdio.h> // REMOVE THIS

typedef struct s_cmd
{
    char            **argv;
    bool            pipe_after;
    struct s_cmd    *next;
}                   t_cmd;

void    free_commands(t_cmd **head);
void    free_argv(char **argv, int i);

char    *ft_strdup(const char *s);
char    **collect_argv(size_t start, size_t end, char **argv);

t_cmd   *parse_commands(int argc, char **argv);
t_cmd   *create_command(size_t start, size_t end, char **argv);

#endif 
