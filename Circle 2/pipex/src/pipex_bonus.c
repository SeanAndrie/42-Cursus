/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:57:27 by sgadinga          #+#    #+#             */
/*   Updated: 2025/04/15 14:44:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	process_heredoc(char *limiter)
{
	int		fd[2];
	char	*line;
	size_t	limit_len;

	if (pipe(fd) == -1)
		return (error("here_doc", "pipe creation failed."), -1);
	limit_len = ft_strlen(limiter);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_strncmp(line, limiter, limit_len) && line[limit_len] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
	close(fd[1]);
	return (fd[0]);
}

void	heredoc_params(t_pipex *px, int *ac, char ***av)
{
	px->infile = process_heredoc((*av)[2]);
	px->outfile = open((*av)[*ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	(*ac)--;
	(*av)++;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*px;

	if (ac < 5)
	{
		error("pipex", "usage: ./pipex infile cmd1 cmd2 ... outfile or\n");
		exit(1);
	}
	px = init_pipex(ac, av);
	if (!px)
		return (1);
	run_pipex(px, envp);
	free_pipex(px);
	exit(0);
}
