/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@42.abudhabi.e>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:38:09 by sgadinga          #+#    #+#             */
/*   Updated: 2025/02/02 20:59:23 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf(line);
		free(line);
	}

	// printf("%s\n", get_next_line(fd));

	close(fd);
	return (0);
}
