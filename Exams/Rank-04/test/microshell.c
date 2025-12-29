#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len]) len++;
    return (len);
}

size_t ft_putstr_fd(int fd, const char *s)
{
    if (fd < 0 || !s)
        return (0);
    return (write(fd, s, ft_strlen(s)));
}

void fatal_error(void)
{
    ft_putstr_fd(STDERR_FILENO, "error: fatal\n");
    exit(1);
}

char **extract_cmd(size_t start, size_t end, char **av)
{
    if (!av || !*av || end < start)
        return (NULL);
    size_t len = (end - start) + 1, i = 0;
    char **cmd = malloc(sizeof(char *) * (len + 1));
    if (!cmd)
        return (NULL);
    while (i < len)
    {
        cmd[i] = av[start + i];
        i++;
    }
    cmd[i] = NULL;
    return (cmd);
}

int do_cd(char **cmd)
{
    int cnt = 0;
    while (cmd[cnt]) cnt++;
    if (cnt != 2)
    {
        ft_putstr_fd(STDERR_FILENO, "error: cd: bad arguments\n");
        return (1);
    }
    if (chdir(cmd[0]) == -1)
    {
        ft_putstr_fd(STDERR_FILENO, "error: cd: cannot change directory to ");
        ft_putstr_fd(STDERR_FILENO, cmd[0]);
        ft_putstr_fd(STDERR_FILENO, "\n");
        return (1);
    }
    return (0);
}

int exec_cmd(char **cmd, char **envp, int has_pipe)
{
    pid_t pid;
    int pipefd[2];
    int status = 0;

    if (has_pipe && pipe(pipefd) == -1)
        fatal_error();
    pid = fork();
    if (pid < 0)
        fatal_error();
    if (pid == 0)
    {
        if (has_pipe)
        {
            if (dup2(pipefd[1], STDOUT_FILENO) == -1)
                fatal_error();
            close(pipefd[0]);
            close(pipefd[1]);
        }
        execve(cmd[0], cmd, envp);
        ft_putstr_fd(STDERR_FILENO, "error cannot execute ");
        ft_putstr_fd(STDERR_FILENO, cmd[0]);
        ft_putstr_fd(STDERR_FILENO, "\n");
        exit(1);
    }
    if (has_pipe)
    {
        if (dup2(pipefd[0], STDIN_FILENO) == -1)
            fatal_error();
        close(pipefd[0]);
        close(pipefd[1]);
    }
    return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}

int main(int ac, char **av, char **envp)
{
    if (ac <= 1)
        return (1);
    int i = 1, status = 0;
    int save_stdin = dup(STDIN_FILENO);
    if (save_stdin == -1)
        return (1);
    while (i < ac)
    {
        int start = i;
        while (i < ac && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
            i++;
        int end = i - 1;
        char **cmd = extract_cmd(start, end, av);
        if (!cmd)
            fatal_error();
        int has_pipe = (i < ac && strcmp(av[i], "|") == 0);
        if (cmd[0] && strcmp(cmd[0], "cd") == 0)
            status = do_cd(cmd);
        else
            status = exec_cmd(cmd, envp, has_pipe);
        free(cmd);
        if (!has_pipe)
        {
            if (dup2(save_stdin, STDIN_FILENO) == -1)
                fatal_error();
        }
        if (i < ac)
            i++;
    }
    close(save_stdin);
    return (status);
}
