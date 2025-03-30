/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trial_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:38:18 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/30 15:43:36 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push_swap *ps, int n_chunks)
{
	chunk_partitions(ps, n_chunks);
	merge_chunks(ps);
}

void	validate_and_save(t_push_swap *copy, t_action **best_actions,
		int *min_ops)
{
	int	curr_ops;

	curr_ops = count_actions(copy->actions);
	if (is_sorted(copy->stack_a) && curr_ops < *min_ops)
	{
		*min_ops = curr_ops;
		if (*best_actions)
			free_actions(*best_actions);
		*best_actions = copy_actions(copy->actions);
	}
}

t_action	*find_optimal_actions(t_push_swap *ps, int *chunks, int n_trials)
{
	int			i;
	int			min_ops;
	t_push_swap	*copy;
	t_action	*best_actions;

	min_ops = INT_MAX;
	best_actions = NULL;
	i = 0;
	while (i < n_trials)
	{
		copy = copy_init_state(ps);
		if (!copy)
		{
			free_actions(best_actions);
			break ;
		}
		sort(copy, chunks[i]);
		validate_and_save(copy, &best_actions, &min_ops);
		free(copy->stack_a->name);
		free_push_swap(copy);
		i++;
	}
	return (best_actions);
}

void	trial_sort(t_push_swap *ps, int margin)
{
	int			*chunks;
	int			n_trials;
	int			base_chunk;
	t_action	*optimal_actions;

	base_chunk = calculate_base_chunk(analyse_distribution(ps->stack_a),
			ps->stack_a->size);
	chunks = create_chunks(ps->stack_a, base_chunk, margin, &n_trials);
	if (!chunks)
		return ;
	optimal_actions = find_optimal_actions(ps, chunks, n_trials);
	if (optimal_actions)
	{
		ps->actions = optimal_actions;
		print_actions(ps->actions);
		ft_printf("\nNumber of Operations: %d\n", count_actions(ps->actions));
	}
	free(chunks);
}
