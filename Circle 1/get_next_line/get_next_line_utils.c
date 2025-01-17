/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:41:46 by sgadinga          #+#    #+#             */
/*   Updated: 2025/01/17 13:28:04 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*create_node(char *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = ft_strdup(content);
	if (!node->content)
	{
		free(node->content);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

void	append_to_list(t_list **head, t_list *node)
{
	t_list	*last;

	if (!*head)
	{
		*head = node;
		return ;
	}
	if (!node)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = node;
}

void    clear_list(t_list **head)
{
    t_list *next_node;
    if (!head)
        return ;
    while (*head)
    {
        next_node = (*head)->next;
        free((*head)->content);
        free(*head);
        *head = next_node;
    }
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0')
		return ((char *)s);
	return (NULL);
}

// int main(void)
// {
//     char *s = "Hello, World!";
//     printf("%s\n", ft_strchr(s, ' '));
//     return (0);
// }
