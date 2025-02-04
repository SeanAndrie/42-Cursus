/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@42.abudhabi.e>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 01:03:59 by sgadinga          #+#    #+#             */
/*   Updated: 2025/02/04 01:13:18 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// FOR TESTING
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_MAX 1024

typedef struct s_list
{
	char			*buffer;
	size_t			length;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*ft_strchr(const char *s, int c);
t_list				*create_node(char *buffer);
void				append_node(t_list **head, char *buffer);
void				update_remainder(t_list **head);
void				clear_list(t_list **head);
#endif