/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:41:10 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/30 17:09:49 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_clamp(int val, int min, int max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

t_distribution	analyse_distribution(t_stack *stack)
{
	t_distribution	dist;
	t_node			*curr;
	int				prev;
	int				gap;

	ft_memset(&dist, 0, sizeof(t_distribution));
	curr = stack->head;
	if (!curr || !curr->next)
		return (dist);
	dist.is_reverse_sorted = 1;
	dist.max_gap = 0;
	prev = curr->data;
	curr = curr->next;
	while (curr)
	{
		gap = curr->data - prev;
		if (gap != -1)
			dist.is_reverse_sorted = 0;
		dist.max_gap = ft_max(ft_abs(gap), dist.max_gap);
		prev = curr->data;
		curr = curr->next;
	}
	return (dist);
}

int	calculate_base_chunk(t_distribution dist, int stack_size)
{
	int	chunks;

	if (stack_size <= 5)
		return (stack_size);
	if (dist.is_reverse_sorted)
		return (3);
	chunks = 5 + (stack_size / 20);
	if (dist.max_gap <= stack_size / 4)
		chunks--;
	else if (dist.max_gap > stack_size / 2)
		chunks++;
	return (ft_clamp(chunks, 3, 15));
}

int	*create_chunks(t_stack *stack, int base_chunk, int margin, int *size)
{
	int	i;
	int	end;
	int	start;
	int	*chunks;

	if (!stack || margin <= 0)
		return (NULL);
	*size = 0;
	start = ft_max(3, base_chunk - margin);
	end = ft_min(base_chunk + margin, stack->size);
	if (start > end)
		return (NULL);
	chunks = ft_calloc((end - start + 1), sizeof(int));
	if (!chunks)
		return (NULL);
	i = 0;
	while (i < (end - start + 1))
	{
		chunks[i] = start + i;
		chunks[i] = ft_clamp(chunks[i], 3, stack->size);
		(*size)++;
		i++;
	}
	return (chunks);
}
