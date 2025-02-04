/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@42.abudhabi.e>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:21:49 by sgadinga          #+#    #+#             */
/*   Updated: 2025/02/02 20:58:32 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// FOR TESTING
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			buffer[BUFFER_SIZE];
	size_t			bytes_read;
	struct s_list	*next;
}					t_list;

size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				append_node(t_list **head, char *buffer);
char				*ft_strchr(const char *s, int c);
void				cleanup(t_list **head);

char				*get_next_line(int fd);

#endif
