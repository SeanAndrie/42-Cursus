/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:28:21 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/18 14:25:38 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(const char *set, int c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*end;
	char		*res;
	size_t		len;

	start = s1;
	while (*start && in_set(set, *start))
		start++;
	end = s1 + ft_strlen((char *)s1) - 1;
	while (end > start && in_set(set, *end))
		end--;
	len = end - start + 1;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	while (len--)
		res[len] = start[len];
	return (res);
}
