/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:35:04 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/11 12:45:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_str(char *c)
{
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
}

void	print_nbr(int nb)
{
	int		current_char;
	int		correction;

	correction = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			correction = 1;
		}
		write(1, "-", 1);
		nb = -(nb + correction);
	}
	if (nb > 9)
	{
		print_nbr(nb / 10);
	}
	current_char = (nb % 10) + ('0' + correction);
	write(1, &current_char, 1);
}

int	cmp_str(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1 ++;
		s2 ++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	if (par != (void *)0)
	{
		while (cmp_str(par[i].str, "0"))
		{
			print_str(par[i].str);
			write(1, "\n", 1);
			print_nbr(par[i].size);
			write(1, "\n", 1);
			print_str(par[i].copy);
			write(1, "\n", 1);
			i++;
		}
	}
}
/*
int main()
{
	
	char c1[] = "hello";
	char c2[] = "goodbye";
	char c3[] = "is this working";
	char *arr[] = {c1, c2, c3}; 
	int sz = 3;
	struct s_stock_str *test = ft_strs_to_tab(3,arr);
	test =  (void *)0;
	c1[0] = 'w';
	c2[0] = 'v';
	c3[0] = 'l';
	ft_show_tab(test);
	return 0;
}
*/