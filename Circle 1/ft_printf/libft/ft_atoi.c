/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:54:03 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/26 17:33:37 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(int n, char digit, int sign)
{
	if (n == (2147483647 / 10) || (n == (2147483647 / 10) && (digit - '0') > 7))
	{
		if (sign == 1)
			return (2147483647);
		else
			return (-2147483648);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;
	int		check;

	res = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		check = check_overflow(res, *nptr, sign);
		if (check != 0)
			return (check);
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)(res * sign));
}
