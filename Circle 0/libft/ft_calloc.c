/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:40:23 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/19 11:41:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	res = malloc(total_size);
	if (!res)
		return (NULL);
	ft_bzero(res, total_size);
	return (res);
}
