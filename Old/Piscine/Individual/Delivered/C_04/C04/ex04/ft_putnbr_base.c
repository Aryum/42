/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:30:23 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/30 12:30:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_rules(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			return (0);
		}
		j = 1;
		while (str[i + j] != '\0')
		{
			if (str[i] == str[i + j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
	int nbr = 1234
	char *base = "0123456789ABCDEF"
	
	int basesize = strlen(base);

	char c1 = base[1234 % basesize];
	c1 = 2;

	nbr / basesize > 0
	1234 / 16 = 77
	char c2 = base[77 % basesize];
	c2 = D

	nbr / basesize > 0
	77 / 16 = 4
	char c3 = base[4 % basesize];
	c3 = 4;

	nbr / basesize > 0



*/
void	convert(long int nbr, char *base, int base_size)
{
	int	div;
	int	remainder;

	div = nbr / base_size;
	remainder = nbr % base_size;
	if (div != 0)
	{
		convert(div, base, base_size);
	}
	write(1, &base[remainder], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_size;
	long int	nbr_conv;

	base_size = str_size(base);
	nbr_conv = nbr;
	if (base_size > 1 && check_rules(base))
	{
		if (nbr_conv < 0)
		{
			nbr_conv *= -1;
			write(1, "-", 1);
		}
		convert(nbr_conv, base, base_size);
	}
}

/*
#include <stdio.h>
int main()
{
	ft_putnbr_base(-12, "01");
}
*/
