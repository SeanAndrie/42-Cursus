/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:02:28 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/28 02:56:46 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *token)
{
	if (*token == '-' || *token == '+')
		token++;
	while (*token)
	{
		if (!ft_isdigit(*token))
			return (0);
		token++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->head || stack->size <= 1)
		return (1);
	curr = stack->head;
	while (curr->next)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_node		*curr;
	t_hashmap	*entry;
	t_hashmap	*map[HASH_SIZE];

	if (!stack || !stack->head)
		return (0);
	curr = stack->head;
	ft_memset(map, 0, sizeof(t_hashmap *) * HASH_SIZE);
	while (curr)
	{
		entry = search(map, curr->data);
		if (entry)
		{
			free_map(map);
			return (1);
		}
		insert(map, curr->data, 0);
		curr = curr->next;
	}
	free_map(map);
	return (0);
}
