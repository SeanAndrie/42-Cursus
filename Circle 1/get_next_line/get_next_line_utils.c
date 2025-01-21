/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:52:32 by sgadinga          #+#    #+#             */
/*   Updated: 2025/01/21 12:58:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*create_node(char *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = ft_strdup(content);
	if (!node->content)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

void	append_node(t_node **head, t_node *node)
{
	t_node	*last;

	if (!node)
		return ;
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

void	cleanup_processed_nodes(t_node **head)
{
	t_node	*curr;
	char	*remain;
	int		i;

	curr = *head;
	while (curr && curr->content)
	{
		i = 0;
		while (curr->content[i] && curr->content[i] != '\n')
			i++;
		if (curr->content[i] == '\n' && curr->content[++i])
		{
			remain = ft_strdup(curr->content + i);
			free(curr->content);
			curr->content = remain;
			break ;
		}
		*head = curr->next;
		free(curr->content);
		free(curr);
		curr = *head;
	}
}

void	clear_list(t_node **head)
{
	t_node	*next;

	if (!*head)
		return ;
	while (*head)
	{
		next = (*head)->next;
		free((*head)->content);
		free(*head);
		*head = next;
	}
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*dup;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
