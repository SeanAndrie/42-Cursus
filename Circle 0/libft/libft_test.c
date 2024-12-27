/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:40:43 by sgadinga          #+#    #+#             */
/*   Updated: 2024/12/22 11:40:43 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
// #include <bsd/string.h>

void    log_message(const char *message)
{
    printf("\n[LOG] %s\n", message);
}

int     count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
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

void    char_check(const char *f_name, int (my_f)(int), int (og_f)(int))
{
    for (int c = 0; c < 256; c++) 
    {
        if (!!og_f(c) != !!my_f(c)) {
            printf("[x] %s failed for character 0x%02X (ASCII: %d)\n", f_name, c, c);
            return ;
        }
    }
    printf("[v] %s (ASCII Range)\n", f_name);
}

void memset_test(const char *test_case, int c, size_t n) {
    unsigned char buffer1[1000]; 
    unsigned char buffer2[1000];

    if (n > sizeof(buffer1)) {
        printf("[x] %s: Test case exceeds buffer size limit (%zu bytes).\n", test_case, sizeof(buffer1));
        return;
    }

    ft_memset(buffer1, c, n);
    memset(buffer2, c, n);

    for (size_t i = 0; i < n; i++) {
        if (buffer1[i] != buffer2[i]) {
            printf("[x] %s failed at index %zu.\n", test_case, i);
            printf("    Expected: 0x%02X, Got: 0x%02X\n", buffer2[i], buffer1[i]);
            return;
        }
    }
    printf("[v] %s passed.\n", test_case);
}


void    memcpy_test(const char *test_case, void *src, size_t n)
{
    unsigned char *dst1 = malloc(n);
    unsigned char *dst2 = malloc(n);
    
    memset(dst1, 'X', n);
    memset(dst2, 'X', n);

    ft_memcpy(dst1, src, n);
    memcpy(dst2, src, n);

    for (size_t i = 0; i < n; i++) 
    {
        if (dst1[i] != dst2[i]) 
        {
            printf("[x] ft_memcpy (%s) failed at byte %zu.\n", test_case, i);
            free(dst1);
            free(dst2);
            return;
        }
    }
    printf("[v] %s\n", test_case);

    free(dst1);
    free(dst2);
}

void    memmove_test(const char *test_case, char *buffer1, char *buffer2, 
                     size_t buffer_size, size_t src_offset, size_t dest_offset, size_t n) {

    memset(buffer1, 0, buffer_size);
    memset(buffer2, 0, buffer_size);
    
    strcpy(buffer1, "Hello, World!");
    strcpy(buffer2, "Hello, World!");
    
    ft_memmove(buffer1 + dest_offset, buffer1 + src_offset, n);
    memmove(buffer2 + dest_offset, buffer2 + src_offset, n);
    
    if (memcmp(buffer1, buffer2, sizeof(buffer1)) != 0)
        printf("[x] ft_memmove (%s) failed");
    else
        printf("[v] %s\n", test_case);
    printf("    Expected: %s | Got: %s\n\n", buffer2, buffer1);
}

// void    strlcpy_test(const char *test_case, char *dst1, char *dst2, const char *src, size_t size)
// {
//     size_t ret1;
//     size_t ret2;

//     ret1 = ft_strlcpy(dst1, src, size);
//     ret2 = strlcpy(dst2, src, size);  
//     if (strcmp(dst1, dst2) != 0 || ret1 != ret2)
//     {
//         printf("[x] ft_strlcat (%s) failed");
//         printf("Expected %s (ret=%zu), Got %s (ret=%zu)", dst2, ret2, dst1, ret1);
//         return ;
//     }
//     printf("[v] ft_strlcat (%s)\n", test_case);
// }

// void    ft_strlcpy_tests()
// {
//     char dst1[50];
//     char dst2[50];

//     log_message("Starting ft_strlcat tests...");
//     strlcpy_test("Normal copy", dst1, dst2, "Hello, World!", sizeof(dst1));
// }

void    case_convert_test(const char *f_name, int (og_f)(int), int (my_f)(int))
{
    for (int c = 0; c < 256; c++)
    {
        if (og_f(c) != my_f(c))
        {
            printf("[x] ft_toupper failed with value %c (%d)\n", (char)c, c);
            printf("    Expected: %c | Got: %c", og_f(c), my_f(c));
            return ;
        }
    }
    printf("[v] %s (ASCII Range)\n", f_name);
}

void   str_search_test(const char *f_name, const char *test_case, const char *s, 
                          int c, char *(og_f)(const char *, int), char *(my_f)(const char *, int))
{
    if (og_f(s, c) != my_f(s,c ))
    {
        printf("[x] %s (%s) failed\n");
        printf("    Expected %s | Got: %s\n", og_f(s, c), my_f(s, c));
    }
    printf("[v] %s (%s)\n", f_name, test_case);
} 

void    run_str_search_tests()
{
    log_message("Starting string search tests...");
    log_message("ft_strchr :\n");
    str_search_test("ft_strchr", "Character found", "Hello, World!", 'o', strchr, ft_strchr);
    str_search_test("ft_strchr", "Character not found", "Hello, World!", 'z', strchr, ft_strchr);
    str_search_test("ft_strchr", "Null character at start", "\0Hello, World!", '\0', strchr, ft_strchr);
    str_search_test("ft_strchr", "Null character at end", "Hello, World!", '\0', strchr, ft_strchr);
    log_message("ft_strrchr :\n");
    str_search_test("ft_strrchr", "Character found", "Hello, World!", 'o', strrchr, ft_strrchr);
    str_search_test("ft_strrchr", "Character not found", "Hello, World!", 'z', strrchr, ft_strrchr);
    str_search_test("ft_strrchr", "Null character at start", "\0Hello, World!", '\0', strrchr, ft_strrchr);
    str_search_test("ft_strrchr", "Null character at end", "Hello, World!", '\0', strrchr, ft_strrchr);
}

void    run_case_conversion_tests()
{
    log_message("Starting case converstion tests...\n");
    case_convert_test("ft_toupper", toupper, ft_toupper);
    case_convert_test("ft_tolower", tolower, ft_tolower);
}

void    run_memmove_tests()
{
    size_t buffer_size = 100;
    char buffer1[buffer_size];
    char buffer2[buffer_size];

    log_message("Starting ft_memmove tests...\n");
    memmove_test("Normal copy (No Overlap)", buffer1, buffer2, buffer_size, 0, 20, 13);
    memmove_test("Overlapping (Source before Dest)", buffer1, buffer2, buffer_size, 7, 0, 6);
    memmove_test("Overlapping (Dest before Source)", buffer1, buffer2, buffer_size, 0, 7, 6); 
    memmove_test("Copy zero bytes", buffer1, buffer2, buffer_size, 0, 0, 0);
    memmove_test("Copy entire buffer", buffer1, buffer2, buffer_size, 0, 0, sizeof(buffer1));
}

void    run_memcpy_tests()
{
    log_message("Starting ft_memcpy tests...\n");
    memcpy_test("Normal copy", "Hello, World!", 13);
    memcpy_test("Copy zero bytes", "No change here", 0);
    memcpy_test("Copy single byte", "A", 1);
    memcpy_test("Copy part of buffer", "Partial buffer copy", 7);
}

void    run_memset_tests()
{
    log_message("Starting ft_memset tests...\n");
    memset_test("Fill with A", 'A', 10);
    memset_test("Fill with 0", '0', 0);
    memset_test("Fill with 255", 255, 1);
    memset_test("Fill zero bytes", 'X', 0);
    memset_test("Fill large buffer", 'Z', 1000);
}

void run_strlen_tests(const char *strs) {
    log_message("Starting ft_strlen tests...\n");

    char **splits = ft_split(strs, ',');
    int word_count = count_words(strs, ',');

    for (int i = 0; i < word_count; i++) {
        size_t expected = strlen(splits[i]);
        size_t result = ft_strlen(splits[i]);

        if (expected != result) 
        {
            printf("[x] ft_strlen failed for string: '%s'\n", splits[i]);
            printf("    Expected: %zu, Got: %zu\n", expected, result);
        } 
        else 
            printf("[v] Passed for string: '%s' (Length: %zu)\n", splits[i], result);
    }
}


void    run_char_checks()
{
    log_message("Starting character check tests...\n");
    char_check("ft_isalpha", ft_isalpha, isalpha);
    char_check("ft_isdigit", ft_isdigit, isdigit);
    char_check("ft_isalnum", ft_isalnum, isalnum);
    char_check("ft_isascii", ft_isascii, isascii);
    char_check("ft_isprint", ft_isprint, isprint);
}

int main(void)
{
    run_char_checks();
    run_strlen_tests(" ,hello,12345,test case,A long string for testing,abc\0efg");
    run_memset_tests();
    run_memcpy_tests();
    run_memmove_tests();
    run_case_conversion_tests();
    run_str_search_tests();
    return (0);
}
