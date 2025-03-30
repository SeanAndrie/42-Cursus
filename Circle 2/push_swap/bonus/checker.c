/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:12:16 by sgadinga          #+#    #+#             */
/*   Updated: 2025/03/27 13:41:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  main(int ac, char **av)
{
    t_push_swap *ps;
    
    if (ac < 2)
        return (0);
    ps = create_push_swap(ac, av);
    if (!ps)
    {
        ft_putendl_fd("Error", 2);
        return (1);
    }
    print_stack(ps->stack_a);
    return (0);
}
