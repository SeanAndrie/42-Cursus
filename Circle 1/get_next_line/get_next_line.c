/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:39:14 by sgadinga          #+#    #+#             */
/*   Updated: 2025/01/17 13:53:03 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list *lst;
	char *line;
	char *buffer;
	int bytes_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		
	}
}

int	main(void)
{
	t_list *head;
	t_list *node;
	int 	*val;

	char *splits[3] = {"hello", "world", "nigga"};

	head = NULL;
	for (int i = 0; i < 3; i++)
	{
		node = create_node(splits[i]);
		append_to_list(&head, node);
	}

	while (head)
	{
		printf("%s", head->content);
		head = head->next;
		if (head)
			printf(" -> ");
	}

	return (0);
}