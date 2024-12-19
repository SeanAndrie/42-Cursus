/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:08:17 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/19 11:36:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	// Allocate memory for new node
	new = malloc(sizeof(t_list));

	// Assign node content and next pointer to NULL
	new->content = content;
	new->next = NULL;
	return (new);
}
