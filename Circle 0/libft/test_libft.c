/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:59:10 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/20 23:59:10 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void	assertion_failure(char *func_name, const char *args, int expected, int actual)
{
	printf("---------------------------------\n");
    printf("Assertion failed in %s:\n", func_name);
    printf("Arguments: %s\n", args);
    printf("Expected: %d, Got: %d\n", expected, actual);
    printf("---------------------------------\n");
	printf("%s\t:\tFAIL\n", func_name);
}

void	char_check(char *name, int (og_f)(int), int (my_f)(int))
{
	char str[2];
	for (int c = -128; c <= 127; c++){
		str[0] = c;
		str[1] = '\0';
		if (!!og_f(c) != !!my_f(c))
		{
			assertion_failure(name, str, !!og_f(c), !!my_f(c));
			return ;
		}
	}
	printf("%s\t(Signed & Unsigned Chars)\t:\tPASS\n", name);
}

void	test_strlen(char **strs)
{
	for (int i = 0; i < 5; i++)
	{
		if (ft_strlen(strs[i]) != strlen(strs[i]))
		{
			assertion_failure("ft_strlen", strs[i], strlen(strs[i]), ft_strlen(strs[i]));
			return ;
		}
	}
	printf("ft_strlen\t(Selected Strings)\t\t:\tPASS\n");
}

void	test_strchr(char *str)
{
	for (int c = -128; c <= 127; c++)
	{
		if (ft_strchr(str, c) != strchr(str, c))
		{
			assertion_failure("ft_strchr", str, strchr(str, c) != NULL, ft_strchr(str, c) != NULL);
			return ;
		}
	}
	printf("ft_strchr\t(Signed & Unsigned Chars)\t:\tPASS\n");
}

void	test_strrchr(char *str)
{
	for (int c = -128; c <= 127; c++)
	{
		if (ft_strrchr(str, c) != strrchr(str, c))
		{
			assertion_failure("ft_strchr", str, strrchr(str, c) != NULL, ft_strrchr(str, c) != NULL);
			return ;
		}
	}
	printf("ft_strchr\t(Signed & Unsigned Chars)\t:\tPASS\n");
}

void test_strncmp(char *case_name, const char *s1, const char *s2, size_t n) 
{
    int expected = strncmp(s1, s2, n);
    int actual = ft_strncmp(s1, s2, n);
    if (expected != actual) 
	{
        assertion_failure("ft_strncmp", case_name, expected, actual);
		return ;
    }
    printf("ft_strncmp (%s)\t: PASS\n", case_name);
}

void test_memset() {
    char b1[10];
    char b2[10];

    for (int c = 0; c < 256; c++) 
	{
        memset(b1, c, 10);
        ft_memset(b2, c, 10);
        if (memcmp(b1, b2, 10) != 0) 
		{
            assertion_failure("ft_memset", "b1, b2", 0, 1);
			return ;
        }
    }
    printf("ft_memset\t:\tPASS\n");
}

void test_memcpy(char *case_name, const char *src) {
    char dst1[20] = "";
    char dst2[20] = "";

    ft_memcpy(dst1, src, 20);
    memcpy(dst2, src, 20);
    if (memcmp(dst1, dst2, 20) != 0) 
	{
        assertion_failure("ft_memcpy", src, 0, 1);
		return ;
    }

    printf("ft_memcpy (%s):\tPASS\n", case_name);
}

void test_memmove(char *case_name, char *src, char *dst1, char *dst2, size_t n) {
    ft_memmove(dst1, src, n);
    memmove(dst2, src, n);
    if (memcmp(dst1, dst2, n) != 0) 
	{
        assertion_failure("ft_memmove (%s)", "src: Hello, World!, dst1: uninitialized, dst2: uninitialized", 0, 1);
		return ;
	}

    printf("ft_memmove (%s)\t:\tPASS\n", case_name);
}

void	character_checks() 
{
    char_check("ft_isalpha", isalpha, ft_isalpha);
    char_check("ft_isdigit", isdigit, ft_isdigit);
    char_check("ft_isalnum", isalnum, ft_isalnum);
    char_check("ft_isascii", isascii, ft_isascii);
    char_check("ft_isprint", isprint, ft_isprint);
}

int main(void)
{
	char *src = "Hello, World!";
	char dst1[10];
	char dst2[10];

	char *strs[] = {"", "hello", "12345", "test case", "A long string for testing!", "abc\0efg"};
	printf("---------------------------------\n");
	character_checks();
	test_strlen(strs);
	test_strchr("HelloWorld");
	test_strrchr("HelloWorld");
	
	test_memset();
	test_memmove("Normaly Copy", src, dst1, dst2, 10);
	test_memcpy("Normal Copy", "Hello, World!");
	test_memcpy("Zero Bytes to Copy", "Hello, World!");
	printf("---------------------------------\n");

	return (0);
}
