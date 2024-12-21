/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:54:03 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/20 22:54:03 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int check_overflow(int n, char digit, int sign)
{
    if (n == (2147483647 / 10) || (n == (2147483647 / 10) && digit > 7))
    {
        if (sign == 1)
            return (-1);
        else
            return (0);
    }
    return (1);
}

int ft_atoi(const char *nptr)
{
    long res;
    int sign;
    int check;
    
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
    while (ft_isdigit(*nptr))
    {
        check = check_overflow(res, *nptr, sign);
        if (!check)
            return (check);
        res = res * 10 + *nptr - '0';
        nptr++;
    }
    return ((int)res * sign);
}
