/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:20:13 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/19 11:27:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	// To keep track of current node
	t_list	*curr;

	// Goes to second-to-last node
	while (*lst != NULL)
	{
		// Keep track of curr node
		curr = *lst;
		
		// Move to next node
		*lst = (*lst)->next;

		// Delete current node
		ft_lstdelone(curr, del);
	}
}
