/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:24:10 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/18 21:26:19 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(long n, int digit, int sign)
{
	const long max = 2147483647;
	const long min = -2147483648;

	if (n > (max / 10) || (n == (max / 10) && digit > 7))
	{
		if (sign == 1)
			return (max);
		else
			return (min);
	}
	return (1);
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
	while (*nptr != '\0' && ft_isdigit(*nptr))
	{
		check = check_overflow(res, *nptr - '0', sign);
		if (check != 1)
			return (check);
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)res * sign);
}
