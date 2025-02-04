/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@42.abudhabi.e>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 01:06:04 by sgadinga          #+#    #+#             */
/*   Updated: 2025/02/04 10:31:07 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	clear_list(t_list **head)
{
	t_list	*next;

	while (*head)
	{
		next = (*head)->next;
		free((*head)->buffer);
		free(*head);
		*head = next;
	}
}

char	*ft_strdup(const char *s, size_t *len)
{
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
	*len = 0;
	while (s[*len])
		(*len)++;
	dup = malloc(*len + 1);
	if (!dup)
		return (NULL);
	dup[*len] = '\0';
	i = 0;
	while (i < *len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

void	append_node(t_list **head, char *buffer)
{
	t_list	*node;
	t_list	*last;
	size_t	len;

	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->buffer = ft_strdup(buffer, &len);
	if (!node->buffer)
	{
		free(node);
		return ;
	}
	node->length = len;
	node->next = NULL;
	if (!*head)
	{
		*head = node;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = node;
}

void	update_remainder(t_list **head)
{
	t_list	*next;
	char	*remain;
	size_t	len;

	while ((*head)->next)
	{
		next = (*head)->next;
		free((*head)->buffer);
		free(*head);
		*head = next;
	}
	remain = ft_strchr((*head)->buffer, '\n');
	if (remain)
	{
		remain = ft_strdup(remain + 1, &len);
		clear_list(head);
		if (remain[0] != '\0')
			append_node(head, remain);
		free(remain);
	}
	else
		clear_list(head);
}
