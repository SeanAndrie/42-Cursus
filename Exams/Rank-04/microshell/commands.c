#include "microshell.h"

void    free_commands(t_cmd **head)
{
    if (!head || !*head)
        return ;
    while (*head)
    {
        t_cmd *next = (*head)->next;
        if ((*head)->argv)
            free_argv((*head)->argv, -1);
        free(*head);
        *head = next;
    }
    *head = NULL;
}

t_cmd   *create_command(size_t start, size_t end, char **argv)
{
    if (!argv || !*argv)
        return (NULL);
    t_cmd *cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (NULL);
    cmd->argv = collect_argv(start, end, argv);
    if (!cmd->argv)
        return (free(cmd), NULL);
    cmd->next = NULL;
    return (cmd);
}

void    append_command(t_cmd **head, t_cmd *cmd)
{
    if (!cmd)
        return ;
    if (!*head)
    {
        *head = cmd;
        return ;
    }
    t_cmd *last = *head;
    while (last->next)
        last = last->next;
    last->next = cmd;
}

t_cmd   *parse_commands(int argc, char **argv)
{
    if (argc == 1 || !argv || !*argv)
        return (NULL);
    t_cmd *head = NULL;
    int i = 1, start = 1;
    while (i < argc)
    {
        while (i < argc && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
            i++;
        t_cmd *cmd = create_command(start, i - 1, argv);
        if (!cmd)
            return (free_commands(&head), NULL);
        cmd->pipe_after = (i < argc && strcmp(argv[i], "|") == 0);
        append_command(&head, cmd);
        if (i < argc && (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0))
            i++;
        start = i;
    }
    return (head);
}

