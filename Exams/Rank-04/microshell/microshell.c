#include "microshell.h"

void    free_av(char **av, int n)
{
    if (n > 0)
    {
        while (--n >= 0)
            free(av[n]);
    }
    else if (n < 0)
    {
        n = 0;
        while (av[n])
        {
            free(av[n]);
            n++;
        }
    }
    free(av);
}

void    free_cmds(t_cmd **head)
{
    if (!head || !*head)
        return ;
    t_cmd *next;
    while (*head)
    {
        next = (*head)->next;
        if ((*head)->av)
            free_av((*head)->av, -1);
        free(*head);
        *head = next;
    }
}

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len]) len++;
    return (len);
}

size_t ft_putstr_fd(int fd, const char *s)
{
    if (!s)
        return (0);
    size_t len = ft_strlen(s);
    size_t ret = write(fd, s, len);
    return (ret > 0) ? ret : 0;
}

char *ft_strdup(const char *s)
{
    if (!s)
        return (NULL);
    size_t len = ft_strlen(s), i = 0;
    char *dup = malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

void fatal_error(void)
{
    ft_putstr_fd(STDERR_FILENO, "error: fatal\n");
    exit(1);
}

char **collect_av(size_t start, size_t end, char **av)
{
    if (!av || !*av || end < start)
        return (NULL);
    size_t len = (end - start) + 1, i = 0;
    char **sub = malloc(sizeof(char *) * (len + 1));
    if (!sub)
        return (NULL);
    while (i < len)
    {
        sub[i] = ft_strdup(av[start + i]);
        if (!sub[i])
            return (free_av(sub, i), NULL);
        i++;
    }
    sub[i] = NULL;
    return (sub);
}

t_cmd *create_cmd(size_t start, size_t end, char **av)
{
    if (!av || !*av || end < start)
        return (NULL);
    t_cmd *cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (NULL);
    cmd->av = collect_av(start, end, av);
    if (!cmd->av)
    {
        free(cmd);
        return (NULL);
    }
    cmd->next = NULL;
    return (cmd);
}

void    append_cmd(t_cmd **head, t_cmd *cmd)
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

t_cmd *parse_cmds(int ac, char **av)
{
    if (ac == 1 || !av || !*av)
        return (NULL);
    t_cmd *head = NULL;
    int i = 1, start = 1;
    while (i < ac)
    {
        while (i < ac && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
            i++;
        t_cmd *cmd = create_cmd(start, i - 1, av);
        if (!cmd)
        {
            free_cmds(&head);
            return (NULL);
        }
        cmd->pipe_after = (i < ac && strcmp(av[i], "|") == 0);
        append_cmd(&head, cmd);
        if (i < ac && (strcmp(av[i], "|") == 0 || strcmp(av[i], ";") == 0))
            i++;
        start = i;
    }
    return (head);
}

void    close_pipes(int **pipes, size_t size)
{
    if (!pipes || size == 0)
        return ;
    size_t i = 0;
    while (i < size)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
        i++;
    }
}

int **create_pipes(size_t size)
{
    if (size == 0)
        return (NULL);
    int **pipes = malloc((sizeof(int *) * size) + (sizeof(int) * 2 * size));
    if (!pipes)
        return (NULL);
    int *fds = (int *)(pipes + size);
    size_t i = 0;
    while (i < size)
    {
        pipes[i] = &fds[i * 2];
        if (pipe(pipes[i]) == -1)
        {
            close_pipes(pipes, i);
            free(pipes);
            return (NULL);
        }
        i++;
    }
    return (pipes);
}

int exec_pipeline(t_cmd *head, char **env)
{
    if (!head || !env)
        return (1);
    size_t n_cmds = 0;
    t_cmd *curr = head;
    while (curr)
    {
        n_cmds++;
        if (!curr->pipe_after)
            break;
        curr = curr->next;
    }
    int **pipes = NULL;
    if (n_cmds > 1)
    {
        pipes = create_pipes(n_cmds - 1);
        if (!pipes)
            return (1);
    }
    pid_t *pids = malloc(sizeof(pid_t) * n_cmds);
    if (!pids)
    {
        if (pipes)
        {
            close_pipes(pipes, n_cmds - 1);
            free(pipes);
        }
        return (1);
    }
    size_t i = 0;
    curr = head;
    while (curr && i < n_cmds)
    {
        pids[i] = fork();
        if (pids[i] == -1)
            fatal_error();
        if (pids[i] == 0)
        {
            if (i > 0 && dup2(pipes[i - 1][0], STDIN_FILENO) == -1)
                fatal_error();
            if (i < n_cmds - 1 && dup2(pipes[i][1], STDOUT_FILENO) == -1)
                fatal_error();
            close_pipes(pipes, n_cmds - 1);
            execve(curr->av[0], curr->av, env);
            ft_putstr_fd(STDERR_FILENO, "error: cannot execute ");
            ft_putstr_fd(STDERR_FILENO, curr->av[0]);
            ft_putstr_fd(STDERR_FILENO, "\n");
            exit(1);
        }
        i++;
        curr = curr->next;
    }
    close_pipes(pipes, n_cmds - 1);
    free(pipes);
    size_t j = 0;
    int status = 0;
    int last_status = 0;
    while (j < n_cmds)
    {
        if (waitpid(pids[j], &status, 0) == -1)
            fatal_error();
        if (j == n_cmds - 1)
            last_status = (WIFEXITED(status)) ? WEXITSTATUS(status) : 1;
        j++;
    }
    free(pids);
    return (last_status);
}

int main(int ac, char **av, char **env)
{
    int status = 0;
    t_cmd *head = parse_cmds(ac, av);
    if (!head)
        return (0);
    t_cmd *curr = head;
    while (curr)
    {
        if (curr->av && strcmp(curr->av[0], "cd") == 0)
        {
            if (!curr->av[1] || curr->av[2])
                ft_putstr_fd(STDERR_FILENO, "error: cd: bad arguments\n");
            else if (chdir(curr->av[1]) == -1)
            {
            ft_putstr_fd(STDERR_FILENO, "error: cd: cannot change directory to ");
            ft_putstr_fd(STDERR_FILENO, curr->av[1]);
            ft_putstr_fd(STDERR_FILENO, "\n");
        }
        }
        else
        status = exec_pipeline(curr, env);
        while (curr && curr->pipe_after)
            curr = curr->next;
        if (curr)
            curr = curr->next;
    }
    free_cmds(&head);
    return (status);
}
