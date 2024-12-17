/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:16:51 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/17 21:18:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (!(*s == c) && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_substr(const char *start, int len)
{
	int		i;
	char	*substr;

	i = 0;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = start[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	handle_substr_error(char **splits, int idx)
{
	int	i;

	i = 0;
	if (!splits[idx])
	{
		while (i < idx)
			free(splits[i++]);
		free(splits);
		return (1);
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int			i;
	int			n_words;
	char		**splits;
	const char	*start;

	i = 0;
	n_words = count_words(s, c);
	splits = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!splits)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		start = s;
		while (*s && !(*s == c))
			s++;
		splits[i] = get_substr(start, s - start);
		if (handle_substr_error(splits, i))
			return (NULL);
		i++;
	}
	splits[i] = NULL;
	return (splits);
}
