/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:17:40 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/28 02:27:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, int value)
{
	t_node	*curr;
	int		index;

	index = 0;
	if (!stack || !stack->head)
		return (-1);
	if (stack->head->data == value)
		return (0);
	if (stack->tail->data == value)
		return (stack->size - 1);
	curr = stack->head->next;
	while (curr && curr != stack->head)
	{
		if (curr->data == value)
			return (index + 1);
		curr = curr->next;
		index++;
	}
	return (-1);
}

char **stack_to_tokens(t_stack *stack)
{
	int i;
	t_node *curr;
	char **tokens;

	if (!stack || !stack->head)
		return (NULL);
	tokens = ft_calloc(stack->size + 1, sizeof(char *));
	if (!tokens)
		return (NULL);
	i = 0;
	curr = stack->head;
	while (curr)
	{
		tokens[i] = ft_itoa(curr->data);
		if (!tokens[i])
			return (free_tokens(tokens));
		curr = curr->next;
		i++;
	}
	return (tokens);
}

t_stack *stack_copy(t_stack *stack)
{
	t_stack *copy;
	char **tokens;

	tokens = stack_to_tokens(stack);
	if (!tokens)
		return (NULL);
	copy = create_stack(tokens, stack->name);
	if (!copy)
		return (NULL);
	return (copy);	
}

int	stack_max(t_stack *stack)
{
	int		max;
	t_node	*curr;

	max = INT_MIN;
	curr = stack->head;
	while (curr)
	{
		if (curr->data > max)
			max = curr->data;
		curr = curr->next;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int		min;
	t_node	*curr;

	min = INT_MAX;
	curr = stack->head;
	while (curr)
	{
		if (curr->data < min)
			min = curr->data;
		curr = curr->next;
	}
	return (min);
}
