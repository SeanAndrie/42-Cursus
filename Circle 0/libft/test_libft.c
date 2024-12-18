/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:49:36 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/18 18:47:15 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int arr_size(char **arr)
{
	int count = 0;
	while (arr[count] != NULL)
		count++;
	return (count);
}

void	char_checks(char *name, int (og_f)(int), int (my_f)(int))
{
	for (int c = -128; c <= 127; c++)
		assert(og_f(c) == my_f(c));
	printf("%s\t: PASS\n", name);
}

void	test_strlen(char **strs)
{
	for (int i = 0; i < 5; i++)
		assert(strlen(strs[i]) == ft_strlen(strs[i]));
	printf("ft_strlen\t: PASS\n");
}

void	test_strchr(char *str)
{
	for (int c = 0; c <= 127; c++)
		assert(strchr(str, c) == ft_strchr(str, c));
	printf("ft_strchr\t: PASS\n");
}

void	test_strrchr(char *str)
{
	for (int c = 0; c <= 127; c++)
		assert(strrchr(str, c) == ft_strrchr(str, c));
	printf("ft_strrchr\t: PASS\n");
}

void	test_strncmp(char *case_name, const char *s1, const char *s2, size_t n)
{
	assert(strncmp(s1, s2, n) == ft_strncmp(s1, s2, n));
	printf("ft_strncmp (%s)\t: PASS\n", case_name);
}

void	test_memset()
{
	char b1[10];
	char b2[10];

	for (int c = 0; c < 256; c++)
	{
		memset(b1, c, 10);
		ft_memset(b2, c, 10);
		assert(memcmp(b1, b2, 10) == 0);
	}
}

void	test_bzero()
{
	char b1[10];
	char b2[10];
	bzero(b1, 10);
	ft_bzero(b2, 10);
	assert(memcmp(b1, b2, 10) == 0);
}

int	main(void)
{
	char *strs[] = {"", "hello", "12345", "test case", "A long string for testing!"};
	printf("\nCharacter Checks\n");
	char_checks("ft_isalpha", isalpha, ft_isalpha);
	char_checks("ft_isdigit", isdigit, ft_isdigit);
	char_checks("ft_isalnum", isalnum, ft_isalnum);
	char_checks("ft_isascii", isascii, ft_isascii);
	char_checks("ft_isprint", isprint, ft_isprint);

	printf("\nString Manipulation\n");
	test_strlen(strs);

	test_strchr("HelloWorld");
	test_strrchr("HelloWorld");

	test_strncmp("Identical Matching", "abc", "abc", 3);
	test_strncmp("Same Prefix #1", "hello", "helloworld", 5);
	test_strncmp("Same Prefix #2", "helloworld", "hello", 5);
	test_strncmp("Equal Strings", "hello", "hello", 5);
	test_strncmp("Boundary Testing", "hello", "world", 0);
	test_strncmp("Empty Strings", "", "hello", 5);

	test_memset();
	test_bzero();

	printf("\nPassed all tests!\n\n");

	return (0);
}
