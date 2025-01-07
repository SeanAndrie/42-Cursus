/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatspec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:00:45 by sgadinga          #+#    #+#             */
/*   Updated: 2025/01/07 03:43:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_formatspec	*ft_init_fs(void)
{
	t_formatspec	*fs;

	fs = malloc(sizeof(t_formatspec));
	if (!fs)
		return (NULL);
	fs->width = 0;
	fs->precision = -1;
	fs->specifier = '\0';
	ft_bzero(fs->flags, 5);
	return (fs);
}

t_formatspec	*ft_create_fs(const char *format)
{
	size_t			i;
	t_formatspec	*fs;

	i = 0;
	fs = ft_init_fs();
	format++;
	ft_parse_flags(&format, fs);
	while (ft_isdigit(*format))
		fs->width = fs->width * 10 + *format++ - '0';
	if (*format == '.')
	{
		format++;
		fs->precision = 0;
		while (ft_isdigit(*format))
			fs->precision = fs->precision * 10 + *format++ - '0';
	}
	if (ft_isspec(*format))
		fs->specifier = *format;
	return (fs);
}

#include <stdio.h>

int	main(void)
{
	t_formatspec	*fs;

	fs = ft_create_fs("%-010.5d");
	printf("%s\n", fs->flags);
	return (0);
}
