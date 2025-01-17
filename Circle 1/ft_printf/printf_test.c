/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:11:21 by sgadinga          #+#    #+#             */
/*   Updated: 2025/01/17 17:21:12 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	compare_out_int(char *format, void *ptr)
{
	int				my_len;
	int				og_len;
	unsigned long	value;

	value = (unsigned long)ptr;
	ft_printf("Format: %s\n", format);
	my_len = ft_printf(format, value);
	og_len = printf(format, value);
	if (my_len == og_len)
		ft_printf("\nMATCHED [/]\n\n");
	else
		ft_printf("\nNOT MATCHING [\\]\n\n");
	ft_printf("ft_printf (No. of Chars Printed): %d\n", my_len);
	ft_printf("printf (No. of Chars Printed): %d\n\n", og_len);
}

int	main(void)
{
	int	n;

	n = 42;
	compare_out_int("|%-15p|\n", &n);
	compare_out_int("|%15p|\n", &n);
	compare_out_int("|%-8p|\n", &n);
	compare_out_int("|%8p|\n", &n);
	return (0);
}
