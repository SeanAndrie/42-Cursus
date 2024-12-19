/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:22:32 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/19 11:10:02 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t 	s_len;
	char	*substr;

	// Null check
	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);

	// Check if start index > source len
	if (start >= s_len)
		return (ft_strdup(""));
	
	// Adjust len if it exceeds substr bounds
	if (len >= s_len - start)
		len = s_len - start;
	i = 0;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	
	// Copy substr from source
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}
