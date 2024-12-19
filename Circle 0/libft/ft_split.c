/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:16:51 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/18 19:21:29 by sgadinga         ###   ########.fr       */
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
		if (*s != c && in_word == 0)
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

static char *alloc_word(const char **s, char c)
{
	const char *start;
	int len;
	char *word;

	len = 0;
	while (**s == c && **s)
		(*s)++;
	start = *s;
	while (**s && **s != c)
	{
		(*s)++;
		len++;
	}
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

static void	 *free_splits(char **splits, int i)
{
	while (--i >= 0)
		free(splits[i]);
	free(splits);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char		**splits;
	int			i;

	if (!s)
		return (NULL);
	splits = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!splits)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			splits[i] = alloc_word(&s, c);
			if (!splits[i])
				return (free_splits(splits, i - 1));
			i++;
		}
	}
	splits[i] = NULL;
	return (splits);
}

#include <stdio.h>

int main(void)
{
	char **splits = ft_split("the quick brown", ' ');
	for (int i = 0; i < 3; i++)
		printf("%s\n", splits[i]);
	return (0);
}
