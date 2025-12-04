#include "microshell.h"

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s && s[len])
        len++;
    return (len);
}

size_t ft_putstr_fd(int fd, const char *s)
{
    if (!s)
        return 0;
    return write(fd, s, ft_strlen(s));
}

void fatal_error(void)
{
    ft_putstr_fd(STDERR_FILENO, "error: fatal\n");
    exit(1);
}

char **extract_cmd(size_t start, size_t end, char **av)
{
    size_t len = end - start + 1;
    size_t i = 0;
    char **cmd = malloc(sizeof(char *) * (len + 1));
    if (!cmd)
        fatal_error();
    while (i < len)
    {
        cmd[i] = av[start + i];
        i++;
    }
    cmd[len] = NULL;
    return cmd;
}

int do_cd(char **cmd)
{
    int count = 0;
    while (cmd[count])
        count++;
    if (count != 2)
    {
        ft_putstr_fd(STDERR_FILENO, "error: cd: bad arguments\n");
        return 1;
    }
    if (chdir(cmd[1]) == -1)
    {
        ft_putstr_fd(STDERR_FILENO, "error: cd: cannot change directory to ");
        ft_putstr_fd(STDERR_FILENO, cmd[1]);
        ft_putstr_fd(STDERR_FILENO, "\n");
        return 1;
    }
    return 0;
}

int exec_cmd(char **cmd, char **envp, int has_pipe)
{
    int pipefd[2];
    pid_t pid;
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
        ft_putstr_fd(STDERR_FILENO, "error: cannot execute ");
        ft_putstr_fd(STDERR_FILENO, cmd[0]);
        ft_putstr_fd(STDERR_FILENO, "\n");
        exit(1);
    }
    waitpid(pid, &status, 0);
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
        return 1;
    int i = 1;
    int status = 0;
    int saved_stdin = dup(STDIN_FILENO);
    if (saved_stdin < 0)
        fatal_error();
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
            if (dup2(saved_stdin, STDIN_FILENO) == -1)
                fatal_error();
        }
        if (i < ac)
            i++;
    }
    close(saved_stdin);
    return status;
}
