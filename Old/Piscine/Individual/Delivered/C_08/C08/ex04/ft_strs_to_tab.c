/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:53:04 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/12 13:45:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	str_len(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	str_to_struct(char *av, struct s_stock_str *var)
{
	int		i;

	i = 0;
	(*var).size = str_len(av);
	(*var).copy = malloc((*var).size + 1);
	if ((*var).copy != (void *)0)
	{
		while (av[i] != '\0')
		{
			(*var).copy[i] = av[i];
			i++;
		}
		(*var).copy[i] = '\0';
		(*var).str = av;
		return (1);
	}
	else
		return (0);
}

void	*free_arr(struct s_stock_str **arr, int last)
{
	int	i;

	i = 0;
	while (i < last)
	{
		free((*arr)[i].copy);
		i++;
	}
	free(*arr);
	return ((void *)0);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ret_val;
	int					i;
	int					sucess;

	i = 0;
	sucess = 1;
	ret_val = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (ret_val == ((void *)0))
		return (((void *)0));
	while (i < ac)
	{
		if (!str_to_struct(av[i], &(ret_val[i])))
			sucess = 0;
		i++;
	}
	ret_val[i].str = ((void *)0);
	if (sucess)
		return (ret_val);
	else
		return (free_arr(&ret_val, i));
}
/*
#include <stdio.h>
int main()
{
	char c1[] = "hello";
	char c2[] = "goodbye";
	char c3[] = "is this working";
	char *arr[] = {c1, c2, c3}; 
	int sz = 3;
	struct s_stock_str *test = ft_strs_to_tab(3,arr);
	c1[0] = 'w';
	c2[0] = 'v';
	c3[0] = 'l';
	int i = 0;
	while (test[i].str != (void *)0)
	{
		printf("%d index\n",i);
		printf("Structure:\n");
		printf("Copy: %s\n",test[i].copy);
		printf("Copy Adress: %p\n", test[i].copy);
		printf("Size: %d\n",test[i].size);
		printf("Str Adress: %p\n", test[i].str);
		printf("Str value: %s\n", test[i].str);

		printf("\n");
		
		printf("Origin:\n");
		printf("String: %s\n", arr[i]);
		printf("Adress: %p\n", arr[i]);
		printf("Size: %d\n", str_len(arr[i]));
		printf("\n");
		printf("\n");

		i++;
	}
	free_arr(&test, i);
}
*/