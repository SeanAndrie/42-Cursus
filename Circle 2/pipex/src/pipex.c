/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:11:16 by sgadinga          #+#    #+#             */
/*   Updated: 2025/04/15 14:46:38 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*px;

	if (ac < 5)
		error("Usage", "./pipex infile cmd1 cmd2 ... outfile", 1);
	px = init_pipex(ac, av);
	if (!px)
		return (1);
	run_pipex(px, envp);
	free_pipex(px);
	return (0);
}
