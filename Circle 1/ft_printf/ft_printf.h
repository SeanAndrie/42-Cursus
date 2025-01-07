/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:07:10 by sgadinga          #+#    #+#             */
/*   Updated: 2025/01/07 03:46:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_formatspec
{
	char	flags[5];
	int		width;
	int		precision;
	char	specifier;
}			t_formatspec;

int			ft_isflag(int c);
int			ft_isspec(int c);
void	ft_parse_flags(const char **format, t_formatspec *fs);
#endif
