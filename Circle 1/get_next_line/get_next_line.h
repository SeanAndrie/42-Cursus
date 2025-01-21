/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:54:23 by sgadinga          #+#    #+#             */
/*   Updated: 2025/01/21 12:23:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}					t_node;

char				*get_next_line(int fd);
t_node				*create_node(char *content);
void				append_node(t_node **head, t_node *node);
void				clear_list(t_node **head);
void				cleanup_processed_nodes(t_node **head);
char				*ft_strdup(char *s);

#endif
