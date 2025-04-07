/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:30:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/03 14:30:41 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	str_comp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1 ++;
		s2 ++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	sort_tab(char **tab, int size)
{
	int	i;
	int	h;
	int	swapped;

	i = 0;
	h = 1;
	swapped = 1;
	while (i < size)
	{
		while (h < size - i - 1)
		{
			if (str_comp(tab[h], tab[h + 1]) > 0)
			{
				swap(&(tab[h]), &(tab[h + 1]));
				swapped = 0;
			}
			h++;
		}
		if (swapped == 1)
			break ;
		h = 1;
		i++;
	}
}

int	main(int agrc, char **argv)
{
	int	i;

	i = 1;
	sort_tab(argv, agrc);
	while (i < agrc)
	{
		print_str(argv[i]);
		i++;
	}
	return (0);
}
