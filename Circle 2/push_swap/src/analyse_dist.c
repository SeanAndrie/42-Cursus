/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:41:10 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/28 00:36:07 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int ft_clamp(int val, int min, int max)
{
    if (val < min)
        return (min);
    if (val > max)
        return (max);
    return (val);
}

t_distribution distribution_init(t_stack *stack)
{
    t_distribution dist;
    
    dist.max = stack->head->data;
    dist.min = stack->head->data;
    dist.range = 0;
    dist.is_reverse_sorted = 1;
    return dist;
}

t_distribution analyse_distribution(t_stack *stack)
{
    int prev;
    t_node *curr;
    t_distribution dist;

    curr = stack->head;
    if (!curr)
        return ((t_distribution){0});
    dist = distribution_init(stack);
    prev = curr->data;
    curr = curr->next;
    while (curr)
    {
        dist.min = ft_min(dist.min, curr->data);
        dist.max = ft_max(dist.max, curr->data);
        if (prev < curr->data)
            dist.is_reverse_sorted = 0;
        prev = curr->data;
        curr = curr->next;
    }
    dist.range = dist.max - dist.min;
    return (dist);
}

int calculate_chunks(t_distribution dist, int stack_size)
{
    int chunks;

    if (stack_size <= 5)
        return (stack_size);
    if (dist.is_reverse_sorted)
        return (3);
    chunks = 5 + (stack_size / 25);
    if (dist.range < stack_size)
        chunks--;
    else if (dist.range > stack_size * 2)
        chunks++;
    return (ft_clamp(chunks, 3, 15));
}
