/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@42.abudhabi.e>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:21:40 by sgadinga          #+#    #+#             */
/*   Updated: 2025/02/02 21:02:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_line(t_list **head)
{
	t_list	*curr;
	size_t	len;
	char	*line;
	char	*nl_pos;

	if (!head || !*head)
		return (NULL);
	len = 0;
	curr = *head;
	while (curr)
	{
		nl_pos = ft_strchr(curr->buffer, '\n');
		if (nl_pos)
		{
			len += (nl_pos - curr->buffer) + 1;
			break ;
		}
		len += curr->bytes_read;
		curr = curr->next;
	}
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	return (line);
}

char	*extract_line(t_list **head)
{
	size_t	i;
	char	*ptr;
	char	*line;

	line = alloc_line(head);
	if (!line)
		return (NULL);
	ptr = line;
	while (*head)
	{
		i = 0;
		while (i < (*head)->bytes_read)
		{
			*ptr = (*head)->buffer[i];
			if (*ptr == '\n')
				return (*++ptr = '\0', line);
			i++;
			ptr++;
		}
		*head = (*head)->next;
	}
	*ptr = '\0';
	return (line);
}

int	is_newline(t_list *head)
{
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (ft_strchr(head->buffer, '\n') != NULL);
}

void	read_line(t_list **head, int fd)
{
	char	*buffer;
	size_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while (!is_newline(*head))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		append_node(head, buffer);
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static t_list	*remain;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_line(&remain, fd);
	line = extract_line(&remain);
	if (!line)
	{
		cleanup(&remain);
		return (NULL);
	}
	cleanup(&remain);
	return (line);
}
