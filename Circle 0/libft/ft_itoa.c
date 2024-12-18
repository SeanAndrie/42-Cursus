/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:54:42 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/18 11:45:46 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		n_digits;

	if (n == 0)
		return (ft_strdup("0"));
	n_digits = count_digits(n);
	res = (char *)malloc(n_digits + 1);
	if (!res)
		return (NULL);
	res[n_digits] = '\0';
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
		n_digits--;
	}
	while (n > 0)
	{
		res[n_digits--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
