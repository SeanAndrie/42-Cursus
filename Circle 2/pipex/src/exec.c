/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:12:14 by sgadinga          #+#    #+#             */
/*   Updated: 2025/04/11 13:45:02 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_for_children(int n_cmds)
{
	int	i;

	i = 0;
	while (i < n_cmds)
	{
		wait(NULL);
		i++;
	}
}

void	execute_w_execve(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	if (!cmd || !envp)
		return ;
	args = ft_split(cmd, ' ');
	if (!args)
		return ;
	cmd_path = find_cmd_path(args[0], envp);
	if (!cmd_path)
	{
		free_array(args);
		return ;
	}
	execve(cmd_path, args, envp);
	free(cmd_path);
	free_array(args);
}

void	execute_w_shell(char *cmd, char **envp)
{
	char	*args[4];

	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = cmd;
	args[3] = NULL;
	execve("/bin/sh", args, envp);
	exit(EXIT_FAILURE);
}

void	child_process(t_pipex *px, t_command *node, char **envp, int i)
{
	if (i == 0)
		dup2(px->infile, STDIN_FILENO);
	else
		dup2(px->pipes[i - 1][0], STDIN_FILENO);
	if (i < px->n_cmds - 1)
		dup2(px->pipes[i][1], STDOUT_FILENO);
	else
		dup2(px->outfile, STDOUT_FILENO);
	close_pipes(px->pipes, px->n_cmds);
	if (requires_shell_parsing(node->cmd))
		execute_w_shell(node->cmd, envp);
	else
		execute_w_execve(node->cmd, envp);
}

void	run_pipex(t_pipex *px, char **envp)
{
	int			i;
	pid_t		pid;
	t_command	*curr;

	i = 0;
	curr = px->head;
	while (curr)
	{
		pid = fork();
		if (pid < 0)
			return ;
		else if (pid == 0)
			child_process(px, curr, envp, i);
		curr = curr->next;
		i++;
	}
	close_pipes(px->pipes, px->n_cmds);
	wait_for_children(px->n_cmds);
}
