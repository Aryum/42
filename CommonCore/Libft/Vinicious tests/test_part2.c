/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:44:43 by vloureir          #+#    #+#             */
/*   Updated: 2025/04/22 11:59:04 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>


// ccw test_part2.c -L. -lft -I. libft.h

void	ft_iteri(unsigned int i, char *c);
char	ft_mapi(unsigned int i, char c);

int	main(void)
{
	// CALLOC

	printf("\n\n	|---- CALLOC ----|\n\n");

	void * p = ft_calloc(2, 2);
	if (p)
	{
		free(p);
		printf("ok\n");
	}
	else
		printf("error\n");
	p = ft_calloc(0, 0);
	if (p)
	{
		free(p);
		printf("ok\n");
	}
	else
		printf("error\n");
	p = ft_calloc(-5, 0);
	if (p)
	{
		free(p);
		printf("ok\n");
	}
	else
		printf("error\n");
	p = ft_calloc(0, -5);
	if (p)
	{			
		free(p);
		printf("ok\n");		
	}
	else
		printf("error\n");
	p = ft_calloc(5, 0);
	if (p)
	{
		free(p);
		printf("ok\n");
	}
	else
		printf("error\n");
	p = ft_calloc(0, 5);
	if (p)
	{
		free(p);
		printf("ok\n");
	}
	else
		printf("error");
	printf("nil: %p\n", ft_calloc(INT_MAX, INT_MAX));
	printf("nil: %p\n", ft_calloc(INT_MIN, INT_MIN));
	printf("nil: %p\n", ft_calloc(-3, -3));
	printf("nil: %p\n", ft_calloc(-3, 5));
	printf("nil: %p\n", ft_calloc(5, -3));

	// STRDUP

	printf("\n\n	|---- STRDUP ----|\n\n");

	char * dup = ft_strdup((char*)"hello 42");
	printf("diff: %d  |  %p\n",  strcmp(dup, "hello 42"), dup);
	free(dup);
	dup = ft_strdup((char*)"");
	printf("diff: %d  |  %p\n",  strcmp(dup, ""), dup);
	free(dup);
	dup = ft_strjoin(NULL, NULL);
	printf("nil: %p\n", dup);
	free(dup);

	// SUBSTR

	printf("\n\n	|---- SUBSTR ----|\n\n");


	char * sub = ft_substr("kawabanga", 0, 42000);
	char * sub2 = strdup("1");
	printf("diff: %d\n",  strcmp(sub, "kawabanga"));
	free(sub);
	sub = ft_substr("kawabanga", 1, 1);
	printf("diff: %d\n",  strcmp(sub, "a"));
	free(sub);
	sub = ft_substr("kawabanga", 100, 1);
	printf("diff: %d\n",  strcmp(sub, ""));
	free(sub);
	sub = ft_substr(sub2, 42, 42000000);
	printf("diff: %d\n",  strcmp(sub, ""));
	free(sub);
	free(sub2);
	sub2 = strdup("0123456789");
	sub = ft_substr(sub2, 9, 10);
	printf("diff: %d\n",  strcmp(sub, "9"));
	free(sub);
	free(sub2);
	sub = ft_substr("test", 1, 2);
	printf("diff: %d\n",  strcmp(sub, "es"));
	free(sub);
	sub = ft_substr(NULL, 1, 2);
	printf("nil: %p\n", sub);
	free(sub);

	// STRJOIN

	printf("\n\n	|---- STRJOIN ----|\n\n");

	char * join = ft_strjoin("welcome to ", "42");
	printf("diff: %d\n", strcmp(join, "welcome to 42"));
	free(join);
	join = ft_strjoin("", "42");
	printf("diff: %d\n", strcmp(join, "42"));
	free(join);
	join = ft_strjoin("42", "");
	printf("diff: %d\n", strcmp(join, "42"));
	free(join);
	join = ft_strjoin("", "");
	printf("diff: %d\n", strcmp(join, ""));
	free(join);
	join = ft_strjoin(NULL, NULL);
	printf("nil: %p\n", join);
	free(join);

	// STRTRIM

	printf("\n\n	|---- STRTRIM ----|\n\n");

	char * trim = ft_strtrim("   xxxkawabanga", " x");
	printf("diff: %d\n", strcmp(trim, "kawabanga"));
	free(trim);
	trim = ft_strtrim("kawabanga    xxx", " x");
	printf("diff: %d\n", strcmp(trim, "kawabanga"));
	free(trim);
	trim = ft_strtrim("   xxxkawabanga    xxx", " x");
	printf("diff: %d\n", strcmp(trim, "kawabanga"));
	free(trim);
	trim = ft_strtrim("   xxx    xxx", " x");
	printf("diff: %d\n", strcmp(trim, ""));
	free(trim);
	trim = ft_strtrim("123456", "");
	printf("diff: %d\n", strcmp(trim, "123456"));
	free(trim);
	trim = ft_strtrim("", "123456");
	printf("diff: %d\n", strcmp(trim, ""));
	free(trim);
	trim = ft_strtrim("", "");
	printf("diff: %d\n", strcmp(trim, ""));
	free(trim);
	trim = ft_strtrim("abcdba", "acb");
	printf("diff: %d\n", strcmp(trim, "d"));
	free(trim);
	trim = ft_strtrim(NULL, NULL);
	printf("nil: %p\n", trim);
	free(trim);

	// SPLIT

	printf("\n\n	|---- SPLIT ----|\n\n");

	int	i;
	char	split1[] = "This will be splitted";
	char	split2[] = "This.should.not.be.splitted";
	char	*empty = "";
	char	**av;

	i = -1;
	av = ft_split(split1, ' ');
	if (av)
	{	
		while (av[++i])
		{
			printf("%s\n", av[i]);
			free(av[i]);
		}
	}
	else
		printf("%p\n", av);
	free(av);
	printf("\n");
	i = -1;
	av = ft_split(split2, ' ');
	if (av)
	{	
		while (av[++i])
		{
			printf("%s\n", av[i]);
			free(av[i]);
		}
	}
	else
		printf("%p\n", av);
	free(av);
	printf("\n");
	i = -1;
	av = ft_split(empty, ' ');
	if (av)
	{	
		while (av[++i])
		{
			printf("%s\n", av[i]);
			free(av[i]);
		}
	}
	else
		printf("%p\n", av);
	free(av);
	i = -1;
	av = ft_split(NULL, ' ');
	if (av)
	{	
		while (av[++i])
		{
			printf("%s\n", av[i]);
			free(av[i]);
		}
	}
	else
		printf("%p\n", av);
	free(av);

	// ITOA

	printf("\n\n	|---- ITOA ----|\n\n");

	char *iitoa = ft_itoa(INT_MAX);
	printf("diff: %d\n", strcmp(iitoa, "2147483647"));
	free(iitoa);
	iitoa = ft_itoa(INT_MIN);
	printf("diff: %d\n", strcmp(iitoa, "-2147483648"));
	free(iitoa);
	iitoa = ft_itoa(0);
	printf("diff: %d\n", strcmp(iitoa, "0"));
	free(iitoa);
	iitoa = ft_itoa(1);
	printf("diff: %d\n", strcmp(iitoa, "1"));
	free(iitoa);
	iitoa = ft_itoa(-1);
	printf("diff: %d\n", strcmp(iitoa, "-1"));
	free(iitoa);
	
	// STRMAPI

	printf("\n\n	|---- STRMAPI ----|\n\n");


	char * mapi = ft_strmapi("1234", ft_mapi);
	printf("diff: %d\n", strcmp(mapi, "1357"));
	free(mapi);
	mapi = ft_strmapi("", ft_mapi);
	printf("diff: %d\n", strcmp(mapi, ""));
	free(mapi);
	mapi = ft_strmapi(NULL, ft_mapi);
	printf("nil: %p\n", mapi);
	free(mapi);
	mapi = ft_strmapi("hello", NULL);
	printf("nil: %p\n", mapi);
	free(mapi);


	// STRITERI

	printf("\n\n	|---- STRITERI ----|\n\n");

	char iteri[] = "";
	ft_striteri(iteri, ft_iteri);
	printf("diff: %d\n", strcmp(iteri, ""));
	char iteri2[] = "0";
	ft_striteri(iteri2, ft_iteri);
	printf("diff: %d\n", strcmp(iteri2, "0"));
	char iteri3[] = "0000000000";
	ft_striteri(iteri3, ft_iteri);
	printf("diff: %d\n", strcmp(iteri3, "0123456789"));
	ft_striteri(iteri3, NULL);
	ft_striteri(NULL, ft_iteri);
}

char	ft_mapi(unsigned int i, char c)
{
	return (c + i);
}

void	ft_iteri(unsigned int i, char *c)
{
	*c = *c + i;
}
