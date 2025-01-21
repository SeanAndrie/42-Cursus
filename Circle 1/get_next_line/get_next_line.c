/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:44:42 by sgadinga          #+#    #+#             */
/*   Updated: 2025/01/21 15:04:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*alloc_line(t_node *head)
{
	int		i;
	int		len;
	char	*line;
	t_node	*temp;

	len = 0;
	temp = head;
	while (temp)
	{
		i = 0;
		while (temp->content[i] && temp->content[i] != '\n')
			i++;
		len += i;
		if (temp->content[i] == '\n')
		{
			len++;
			break ;
		}
		temp = temp->next;
	}
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	return (line);
}

static char	*extract_line(t_node **head)
{
	int		i;
	int		j;
	char	*line;
	t_node	*temp;

	line = alloc_line(*head);
	if (!line)
		return (NULL);
	j = 0;
	temp = *head;
	while (temp)
	{
		i = 0;
		while (temp->content[i] && temp->content[i] != '\n')
			line[j++] = temp->content[i++];
		if (temp->content[i] == '\n')
		{
			line[j++] = '\n';
			break ;
		}
		temp = temp->next;
	}
	line[j] = '\0';
	return (line);
}

static int	has_newline(t_node *head)
{
	char	*content;

	while (head)
	{
		content = head->content;
		while (*content)
		{
			if (*content == '\n')
				return (1);
			content++;
		}
		head = head->next;
	}
	return (0);
}

static void	read_line(t_node **head, int fd)
{
	char	*buffer;
	int		bytes_read;
	t_node	*node;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while (!has_newline(*head))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		node = create_node(buffer);
		if (!node)
		{
			free(buffer);
			return ;
		}
		append_node(head, node);
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static t_node	*head;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_line(&head, fd);
	if (!head)
		return (NULL);
	line = extract_line(&head);
	if (!line)
	{
		clear_list(&head);
		return (NULL);
	}
	cleanup_processed_nodes(&head);
	if (!head)
		clear_list(&head);
	return (line);
}
