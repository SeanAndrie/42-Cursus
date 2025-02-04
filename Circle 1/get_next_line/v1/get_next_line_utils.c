/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@42.abudhabi.e>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:42:11 by sgadinga          #+#    #+#             */
/*   Updated: 2025/02/02 20:58:14 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

// char *ft_strdup(const char *s)
// {
//     size_t len;
//     char *dup;

//     if (!s)
//         return (NULL);
//     while (s[len])
//         len++;
//     dup = malloc(len + 1);
//     if (!dup)
//         return (NULL);
//     dup[len] = '\0';
//     while (len--)
//         dup[len] = s[len];
//     return (dup);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

t_list	*create_node(char *buffer)
{
	t_list	*node;

	if (!buffer)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->buffer[0] = '\0';
	node->bytes_read = ft_strlcat(node->buffer, buffer, BUFFER_SIZE);
	node->next = NULL;
	return (node);
}

void	append_node(t_list **head, char *buffer)
{
	t_list	*node;
	t_list	*last;

	node = create_node(buffer);
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

void	cleanup(t_list **head)
{
	char	*nl_pos;
	t_list	*curr;
	t_list	*temp;
	t_list	*remain;

	curr = *head;
	while (curr)
	{
		nl_pos = ft_strchr(curr->buffer, '\n');
		if (nl_pos && *(nl_pos + 1))
		{
			remain = create_node(nl_pos + 1);
			if (remain)
			{
				*head = remain;
				free(curr);
                return ;
			}
		}
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*head = NULL;
}
