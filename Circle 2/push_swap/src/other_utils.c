/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:47:15 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/23 08:43:38 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_arr(t_stack *stack)
{
	t_node	*curr;
	int		*arr;
	int		i;

	arr = ft_calloc(stack->size, sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	curr = stack->head;
	while (curr)
	{
		arr[i++] = curr->data;
		curr = curr->next;
	}
	if (stack->tail && stack->tail->data != arr[stack->size - 1])
		ft_printf("Warning: Tail mismatch!\n");
	return (arr);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

long	ft_atol(const char *s)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s && ft_isdigit(*s))
		res = res * 10 + *s++ - '0';
	return (sign * res);
}
