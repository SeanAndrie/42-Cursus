/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:01:20 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/28 03:24:45 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_actions(t_action *head)
{
	t_action	*next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head);
		head = next;
	}
}

int	count_actions(t_action *head)
{
	int			count;
	t_action	*curr;

	count = 0;
	curr = head;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

t_action	*create_action(char *name)
{
	t_action	*action;

	action = malloc(sizeof(t_action));
	if (!action)
		return (NULL);
	action->name = ft_strdup(name);
	if (!action->name)
		return (NULL);
	action->next = NULL;
	return (action);
}

void	add_action(t_action **head, char *name)
{
	t_action	*last;
	t_action	*new;

	new = create_action(name);
	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_action *copy_actions(t_action *src) {
    t_action *copy_head = NULL;
    t_action **copy_tail = &copy_head;  // Pointer to the current tail's next pointer
    t_action *curr = src;

    while (curr) {
        t_action *new_node = create_action(curr->name);
        if (!new_node) {
            free_actions(copy_head);
            return NULL;
        }
        
        *copy_tail = new_node;       // Link new node to list
        copy_tail = &(*copy_tail)->next;  // Move tail pointer
        curr = curr->next;
    }
    return copy_head;
}
