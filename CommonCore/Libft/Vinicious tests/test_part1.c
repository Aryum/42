/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:04:41 by vloureir          #+#    #+#             */
/*   Updated: 2025/04/29 16:04:03 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>


// cc test_part1.c -L. -lft -I. libft.h -w -lbsd

int	main(void)
{

// ATOI

	int	i;
	int	diff;
	const char *test_atoi[] = {"0", "2147483647", "-2147483648", "  2147483647", " +42", " --42", "  +-42", NULL};

	i = 0;
	printf("\n\n	|---- ATOI ----|\n\n");
	while (test_atoi[i])
	{
		diff = ft_atoi(test_atoi[i]) - atoi(test_atoi[i]);
		printf("ft: %11d  |  og: %11d  |  diff: %d\n", ft_atoi(test_atoi[i]), atoi(test_atoi[i]), diff);
	//	printf("diff: %d\n", diff);
		i++;
	}

// BZERO

	int	bzero_max = 21;
	char test_bzero1[bzero_max];
	char test_bzero2[bzero_max];

	memset(test_bzero1, '*', bzero_max);
	memset(test_bzero2, '*', bzero_max);
	ft_bzero(test_bzero1, bzero_max - 1);
	bzero(test_bzero2, bzero_max - 1);
	i = 0;
	printf("\n\n	|---- BZERO ----|\n\n");
	while (i < bzero_max)
	{
		printf("ft: %5d   |   og: %5d   |\n", test_bzero1[i], test_bzero2[i]);
		i++;
	}

// MEMSET

	char test_memset1[bzero_max];
	char test_memset2[bzero_max];

	ft_bzero(test_memset1, bzero_max);
	bzero(test_memset2, bzero_max);
	memset(test_memset1, '*', bzero_max - 1);
	memset(test_memset2, '*', bzero_max - 1);

	i = 0;
	printf("\n\n	|---- MEMSET ----|\n\n");
	while (i < bzero_max)
	{
		printf("ft: %5d   |   og: %5d   |\n", test_memset1[i], test_memset2[i]);
		i++;
	}

// MEMMOVE

	char test0[] = { 0,  0,  0,  0,  0,  0,  0};
	char test1[] = {38, 39, 40, 41, 42, 0, 90};
	char test_cpy[] = {38, 39, 40, 41, 42, 0, 90};
	char res1[] = {40, 41, 40, 41, 42, 0, 90};
	char res2[] = {40, 40, 41, 41, 42, 0, 90};


	printf("\n\n	|---- MEMMOVE ----|\n\n");
	ft_memmove(test0, test1, 7);
	diff = memcmp(test1, test0, 7);
	printf("diff: %d\n", diff);
	ft_memmove(test1, test1 + 2, 0);
	diff = memcmp(test1, test_cpy, 7);
	printf("diff: %d\n", diff);
	ft_memmove(test1, test1 + 2, 2);
	diff = memcmp(test1, res1, 7);
	printf("diff: %d\n", diff);
	ft_memmove(res1 + 1, res1, 2);
	diff = memcmp(res1, res2, 7);
	printf("diff: %d\n", diff);
	printf("nil: %p", ft_memmove(NULL, NULL, 0));

//MEMCOPY

	printf("\n\n	|---- MEMMCPY ----|\n\n");
	char dest_ft[16];
	char dest_og[16];
	char new[16] = {'A', 'B', 'C', 'D', 'E', 'F', 0};

	dest_ft[15] = 0;
	memset(dest_ft, 'Z', 15);
	dest_og[15] = 0;
	memset(dest_og, 'Z', 15);
	printf("diff: %d\n", strcmp((char *)ft_memcpy(dest_ft, "42 school", 0), (char *)memcpy(dest_og, "42 school", 0)));
	printf("diff: %d\n", strcmp((char *)ft_memcpy(dest_ft, "42 school", 15), (char *)memcpy(dest_og, "42 school", 15)));
	printf("diff: %d\n", strcmp((char *)ft_memcpy(new, NULL, 0), (char *)memcpy(new, NULL, 0)));
	printf("nil: %p", ft_memcpy(NULL, NULL, 0));

// MEMCMP

	printf("\n\n	|---- MEMMCMP ----|\n\n");

	char cmp1[] = {38, 39, 40, 41, 42, 0, 128};
	char cmp2[] = {38, 39, 40, 41, 42, 0, 128, 200};
	char cmp3[] = {38, 39, 40, 41, 42, 1, 90};

	diff = ft_memcmp(cmp1, cmp3, 7) - memcmp(cmp1, cmp3, 7);
	printf("diff: %d\n", diff);
	diff = ft_memcmp(cmp1, cmp2, 7) - memcmp(cmp1, cmp2, 7);
	printf("diff: %d\n", diff);
	diff = ft_memcmp(cmp1, cmp3, 6) - memcmp(cmp1, cmp3, 6);
	printf("diff: %d\n", diff);
	printf("nil: %p", ft_memcmp(NULL, NULL, 0));

// MEMCHR

printf("\n\n	|---- MEMMCHR ----|\n\n");

char memchr1[16] = "prize!";

printf("diff: %d\n", strcmp((char *)ft_memchr(memchr1, 'p',  5), (char *)memchr(memchr1, 'p', 5)));
printf("diff: %d\n", strcmp((char *)ft_memchr(memchr1, '!',  6), (char *)memchr(memchr1, '!', 6)));
printf("diff: %d\n", strcmp((char *)ft_memchr(memchr1, 'i',  3), (char *)memchr(memchr1, 'i', 3)));
printf("diff: %d\n", strcmp((char *)ft_memchr(memchr1, 'i' + 256,  3), (char *)memchr(memchr1, 'i' + 256, 3)));
printf("nil: %p\n", (char *)ft_memchr(memchr1, 'p',  0));
printf("nil: %p\n", (char *)ft_memchr(memchr1, 'j',  7));
printf("nil: %p\n", (char *)ft_memchr(NULL, 'j',  0));

// STRCHR

printf("\n\n	|---- STRCHR ----|\n\n");

char test_strchr[] = "kawabanga!";

printf("diff: %d\n", strcmp(ft_strchr(test_strchr, 'k'), strchr(test_strchr, 'k')));
printf("diff: %d\n", strcmp(ft_strchr(test_strchr, 'g'), strchr(test_strchr, 'g')));
printf("diff: %d\n", strcmp(ft_strchr(test_strchr, 'k' + 256), strchr(test_strchr, 'k' + 256)));
printf("nil: %p %p\n", ft_strchr(test_strchr, 'h'), strchr(test_strchr, 'h'));
printf("\\0: %p %p\n", ft_strchr(test_strchr, '\0'), strchr(test_strchr, '\0'));

// STRRCHR

printf("\n\n	|---- STRRCHR ----|\n\n");

char strrchr1[] = "kawabanga!";
char strrchr2[] = "gkawabanga!g";
char empty[] = "";

printf("diff: %d\n", strcmp(ft_strrchr(strrchr1, 'k'), strrchr(strrchr1, 'k')));
printf("diff: %d\n", strcmp(ft_strrchr(strrchr1, 'k' + 256), strrchr(strrchr1, 'k' + 256)));
printf("diff: %d\n", strcmp(ft_strrchr(strrchr1, 'g'), strrchr(strrchr1, 'g')));
printf("diff: %d\n", strcmp(ft_strrchr(strrchr1, 'g'), strrchr(strrchr1, 'g')));
printf("nil: %p %p\n", ft_strchr(empty, 'V'), strchr(empty, 'V'));
printf("nil: %p %p\n", ft_strchr(strrchr1, 'V'), strchr(strrchr1, 'V'));
printf("\\0: %p %p\n", ft_strrchr(strrchr1, '\0'), strrchr(strrchr1, '\0'));

// STRNCMP

printf("\n\n	|---- STRNCMP ----|\n\n");

printf("\n(result == 0)\n");
printf("%d\n", (ft_strncmp("oi", "", 0)));
printf("%d\n", (ft_strncmp("1234", "1235", 3)));
printf("%d\n", (ft_strncmp("", "", 42)));
printf("%d\n", (ft_strncmp("kawabanga!", "kawabanga!", 42)));
printf("%d\n", (ft_strncmp("", "1", 0)));
printf("%d\n", (ft_strncmp("1", "", 0)));
printf("%d\n", (ft_strncmp("", "", 42)));
printf("%d\n", (ft_strncmp("", "", 1)));
printf("\n(result > 0)\n");
printf("%d\n", (ft_strncmp("1235", "1234", -1)));
printf("%d\n", (ft_strncmp("kawabanga!", "kawaBanga!", 42)));
printf("%d\n", (ft_strncmp("kawabanga!", "kawabanga", 42)));
printf("%d\n", (ft_strncmp("1", "", 1)));
printf("\n(result < 0)\n");
printf("%d\n", (ft_strncmp("1234", "1235", 4)));
printf("%d\n", (ft_strncmp("1234", "1235", -1)));
printf("%d\n", (ft_strncmp("Kawabanga!", "kawabanga!", 42)));
printf("%d\n", (ft_strncmp("kawabanga!", "kawabanga!X", 42)));
printf("%d\n", (ft_strncmp("", "1", 1)));

// STRNSTR

printf("\n\n	|---- STRNSTR ----|\n\n");

char big[30] = "aaabcabcd";
char little[10] = "aabc";

printf("diff: %d\n", strcmp(ft_strnstr(big, little, -1), big + 1));
printf("diff: %d\n", strcmp(ft_strnstr(big, "a", -1), big));
printf("diff: %d\n", strcmp(ft_strnstr(big, "c", -1), big + 4));
printf("diff: %d\n", strcmp(ft_strnstr(big, "aaabc", 5), big));
printf("diff: %d\n", strcmp(ft_strnstr(big, "abcd", 9), big + 5));
printf("diff: %d\n", strcmp(ft_strnstr(big, "a", 1), big));
printf("empty: %s \n", ft_strnstr(empty, "", 0));
printf("empty: %s \n", ft_strnstr(empty, "", -1));
printf("nil: %p \n", ft_strnstr(empty, "12345", 5));
printf("nil: %p \n", ft_strnstr(empty, "toto", -1));
printf("nil: %p \n", ft_strnstr(big, little, 0));
printf("nil: %p \n", ft_strnstr(big, "cd", 8));
printf("nil: %p \n", ft_strnstr("1", "a", 1));
printf("nil: %p \n", ft_strnstr("22", "c", 2));

// STRLCPY

printf("\n\n	|---- STRLCPY ----|\n\n");

char string[] = "Hello there, Venus";
char buffer[19];
int r;
int	size;

size = 19;
r = ft_strlcpy(buffer, string, size);
printf("Copied %d '%s' into '%s', length %d\n", size, string, buffer, r);
size = 18;
r = ft_strlcpy(buffer, string, size);
printf("Copied %d '%s' into '%s', length %d\n", size, string, buffer, r);
size = 10;
r = ft_strlcpy(buffer, string, size);
printf("Copied %d '%s' into '%s', length %d\n", size, string, buffer, r);
size = 1;
r = ft_strlcpy(buffer, string, size);
printf("Copied %d '%s' into '%s', length %d\n", size, string, buffer, r);
size = 0;
r = ft_strlcpy(buffer, string, size);
printf("Copied %d '%s' into '%s', length %d\n", size, string, buffer, r);
printf("nil: %d\n", ft_strlcpy(NULL, string, 0));
printf("nil: %d", strlcpy(NULL, string, 0));

// STRLCAT

printf("\n\n	|---- STRLCAT ----|\n\n");

char dest[30]; 
char * src = (char *)"AAAAAAAAA";

memset(dest, 0, 30);
dest[0] = 'B';

r = ft_strlcat(dest, src, 0);
printf("9 + 0:   %d   |   diff: %d\n", r, strcmp(dest, "B"));
r = ft_strlcat(dest, src, 1);
printf("9 + 1:  %d   |   diff: %d\n", r, strcmp(dest, "B"));
memset(dest, 'B', 4);
r = ft_strlcat(dest, src, 3);
printf("9 + 3:  %d   |   diff: %d\n", r, strcmp(dest, "BBBB"));
r = ft_strlcat(dest, src, 6);
printf("9 + 4:  %d   |   diff: %d\n", r, strcmp(dest, "BBBBA"));
memset(dest, 'C', 5);
r = ft_strlcat(dest, src, -1);
printf("9 + 5:  %d   |   diff: %d\n", r, strcmp(dest, "CCCCCAAAAAAAAA"));
memset(dest, 'C', 15);
r = ft_strlcat(dest, src, 17);
printf("9 + 15: %d   |   diff: %d\n", r, strcmp(dest, "CCCCCCCCCCCCCCCA"));
memset(dest, 0, 30);
r = ft_strlcat(dest, src, 1);
printf("9 + 0:   %d   |   diff: %d\n", r, strcmp(dest, ""));
memset(dest, 0, 30);
memset(dest, '1', 10);
r = ft_strlcat(dest, src, 5);
printf("9 + 5:  %d   |   diff: %d\n", r, strcmp(dest, "1111111111"));
memset(dest, 0, 30);
r = ft_strlcat(dest, "", 42);
printf("0 + 0:   %d   |   diff: %d\n", r, strcmp(dest, ""));
memset(dest, 0, 30);
r = ft_strlcat(dest, "", 0);
printf("0 + 0:   %d   |   diff: %d\n", r, strcmp(dest, ""));
r = ft_strlcat(dest, "123", 1);
printf("3 + 0:   %d   |   diff: %d\n", r, strcmp(dest, ""));
printf("nil: %p\n", ft_strlcat(NULL, dest, 0));

//printf("nil: %p\n", strlcat(NULL, dest, 0));
//printf("nil: %p\n", ft_strlcat(NULL, NULL, 0));
//printf("nil: %p\n", strlcat(NULL, NULL, 0));
//printf("nil: %p\n", strlcat(dest, NULL, 0));
}
