#include "microshell.h"

void    free_argv(char **argv, int i)
{
    if (i > 0)
    {
        while (--i > 0)
            free(argv[i]);
    }
    else if (i < 0)
    {
        i = 0;
        while (argv[i])
        {
            free(argv[i]);
            i++;
        }
    }
    free(argv);
}

size_t  ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len]) len++;
    return (len);
}

size_t  ft_putstr_fd(int fd, const char *s)
{
    size_t  len = ft_strlen(s);
    return (write(fd, s, len));
}

char    *ft_strdup(const char *s)
{
    if (!s)
        return (NULL);
    size_t len = ft_strlen(s), i = 0;
    char *dup = malloc(sizeof(char) * (len + 1));
    if (!dup) return (NULL);
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char    **collect_argv(size_t start, size_t end, char **argv)
{
    if (end < start)
        return (NULL);
    size_t total_size = (end - start) + 1, i = 0;
    char **sub = malloc(sizeof(char *) * (total_size + 1));
    if (!sub)
        return (NULL);
    while (i < total_size)
    {
        sub[i] = ft_strdup(argv[start + i]);
        if (!sub[i])
            return (free_argv(sub, i), NULL);
        i++;
    }
    sub[total_size] = NULL;
    return (sub);
}

void    close_pipes(int **pipes, size_t size)
{
    if (!pipes || !*pipes)
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
    int *block = (int *)(pipes + size);
    size_t i = 0;
    while (i < size)
    {
        pipes[i] = &block[i * 2];
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

void    fatal_error(void)
{
    ft_putstr_fd(STDERR_FILENO, "error: fatal\n");
    exit(1);
}

int exec_pipeline_group(t_cmd *head, char **envp)
{
    if (!head || !envp)
        return (1);
    size_t  size = 0;
    t_cmd   *curr = head;
    while (curr)
    {
        size++;
        if (!curr->pipe_after)
            break;
        curr = curr->next;
    }
    int **pipes = NULL;
    if (size > 1)
    {
        pipes = create_pipes(size - 1);
        if (!pipes)
            fatal_error();
    }
    pid_t  *pids = malloc(sizeof(pid_t) * size);
    if (!pids)
    {
        close_pipes(pipes, size - 1);
        free(pipes);
        fatal_error();
    }
    curr = head;
    size_t i = 0;
    while (curr && i < size)
    {
        pids[i] = fork();
        if (pids[i] == -1)
            fatal_error();

        if (pids[i] == 0)
        {
            if (i > 0 && dup2(pipes[i - 1][0], STDIN_FILENO) == -1)
                fatal_error();
            if (i < size - 1 && dup2(pipes[i][1], STDOUT_FILENO) == -1)
                fatal_error();
            close_pipes(pipes, size - 1);
            execve(curr->argv[0], curr->argv, envp);
            ft_putstr_fd(STDERR_FILENO, "error: cannot execute ");
            ft_putstr_fd(STDERR_FILENO, curr->argv[0]);
            ft_putstr_fd(STDERR_FILENO, "\n");
            exit(1);
        }
        curr = curr->next;
        i++;
    }
    close_pipes(pipes, size - 1);
    free(pipes);
    size_t j = 0;
    int status = 0;
    int last_status = 0;
    while (j < size)
    {
        if (waitpid(pids[j], &status, 0) == -1)
            fatal_error();
        if (j == size - 1)
            last_status = WIFEXITED(status) ? WEXITSTATUS(status) : 1;
        j++;
    }
    free(pids);
    return (last_status);
}

int main(int argc, char **argv, char **envp)
{
    t_cmd *head = parse_commands(argc, argv);
    if (!head)
        fatal_error();
    t_cmd *curr = head;
    while (curr)
    {
        if (curr->argv && strcmp(curr->argv[0], "cd") == 0)
        {
            if (!curr->argv[1] || curr->argv[2])
            {
                ft_putstr_fd(STDERR_FILENO, "error: cd: bad arguments\n");
                break;
            }
            else if (chdir(curr->argv[1]) == -1)
            {
                ft_putstr_fd(STDERR_FILENO, "error: cd: cannot change directory to ");
                ft_putstr_fd(STDERR_FILENO, curr->argv[1]);
                ft_putstr_fd(STDERR_FILENO, "\n");
                break;
            }
        }
        else
            exec_pipeline_group(curr, envp);
        while (curr && curr->pipe_after)
            curr = curr->next;
        if (curr)
            curr = curr->next;
    }
    free_commands(&head);
    return (0);
}
