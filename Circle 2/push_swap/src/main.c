/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:43:13 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/28 03:31:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void trial_sort(t_push_swap *ps, int n_trials)
// {
//     int i;
//     int min_ops;
//     int curr_ops;
//     int base_chunks;
//     t_push_swap *copy;
//     t_action *best_actions;

//     if (!ps || n_trials <= 0 || !ps->stack_a)
//         return;

//     // Initialize baseline
//     base_chunks = calculate_chunks(analyse_distribution(ps->stack_a), ps->stack_a->size);
// 	ft_printf("\nBase Chunks:\n\n", base_chunks);
//     sort(ps, base_chunks);
//     best_actions = copy_actions(ps->actions);
//     if (!best_actions)
//         return;
//     min_ops = count_actions(best_actions);

//     // Trial loop
//     for (i = 0; i < n_trials; i++)
//     {
//         copy = partial_copy_push_swap(ps);
//         if (!copy)
//         {
//             free_actions(best_actions);
//             return;
//         }

//         sort(copy, base_chunks + i);  // Test increasing chunk counts
//         curr_ops = count_actions(copy->actions);

//         // Update best solution if better found
//         if (curr_ops < min_ops || (curr_ops == min_ops && is_sorted(copy->stack_a)))
//         {
//             free_actions(best_actions);
//             best_actions = copy_actions(copy->actions);
//             if (!best_actions)
//             {
//                 free_push_swap(copy);
//                 return;
//             }
//             min_ops = curr_ops;

//             // Early exit if perfect sort found
//             if (is_sorted(copy->stack_a) && copy->stack_b->size == 0)
//             {
//                 free_push_swap(copy);
//                 break;
//             }
//         }
//         free_push_swap(copy);
//     }

//     // Apply best solution
//     free_actions(ps->actions);
//     ps->actions = best_actions;
//     print_actions(ps->actions);
// 	// print_stack(ps->stack_a);
//     ft_printf("\nOptimal Operations: %d\n", min_ops);
// }

int	main(int ac, char **av)
{
	t_push_swap	*ps;

	if (ac < 2)
		return (0);
	ps = create_push_swap(ac, av);
	if (!ps)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	sort(ps, 10);
	print_actions(ps->actions);
	if (is_sorted(ps->stack_a))
		ft_printf("\nSorting Successful.\n");
	ft_printf("\nNumber of Operations: %d\n\n", count_actions(ps->actions));
	print_stack(ps->stack_a);
	free_push_swap(ps);
	return (0);
}
