/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatspec_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:17:31 by sgadinga          #+#    #+#             */
/*   Updated: 2025/01/07 03:46:48 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(int c)
{
	return (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#');
}

int	ft_isspec(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

static void ft_apply_precedence(t_formatspec *fs, int high, int low)
{
	char *pos;
	
	while (ft_strchr(fs->flags, high) && ft_strchr(fs->flags, low))
	{
		pos = ft_strchr(fs->flags, low);
		while (*pos)
		{
			*pos = *(pos + 1);
			pos++;
		}
	}
}

void	ft_parse_flags(const char **format, t_formatspec *fs)
{
	size_t i;

	i = 0;
	while (**format && ft_isflag(**format))
	{
		if (!ft_strchr(fs->flags, **format))
			fs->flags[i++] = **format;
		(*format)++;
	}
	fs->flags[i] = '\0';
	ft_apply_precedence(fs, '-', '0');
	ft_apply_precedence(fs, '+', ' ');
}
