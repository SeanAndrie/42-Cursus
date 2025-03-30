/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:43:13 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/30 17:53:31 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	trial_sort(ps, 5);
	free_push_swap(ps);
	return (0);
}
