/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_put_nbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:31:47 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/07 10:52:14 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_base_valid(char *str)
{
	int	i;
	int	j;

	if (str == NULL)
		return (0);
	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		j = 1;
		while (str[i + j] != '\0')
		{
			if (str[i] == str[i + j])
				return (0);
			if ((str[i] > 8 && str[i] <= '\r') || str[i] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void print_base(unsigned long nbr, char *base, int sz, int *c)
{
	if (nbr / sz != 0)
		print_ulong (nbr / sz, base, sz, c);
	h_put_char(base[nbr % sz], c);
}

void	h_put_ulongbase(unsigned long nbr, char *base, int *counter)
{
	int	base_sz;
	
	if(is_base_valid(base))
	{
		base_sz =  h_strlen(base);
		print_base(nbr, base, base_sz,counter);
	}
}


void	h_put_uintbase(unsigned int nbr, char *base, int *counter)
{
	int	base_sz;
	
	if(is_base_valid(base))
	{
		base_sz =  h_strlen(base);
		print_base(nbr, base, base_sz,counter);
	}
}


/*
	base -> string sem chars repetidos
	01 binario -> 2
	012345679 decimal -> 10
	013456789abcdef hexa -> 16
	
	1
	0123456789abcdef
	base size 16
	nbr 78
	
	index de 1st char
	78 / basesize = 78 % 16 = 14
	1st char = base[14] = e 

	78 / 16 = 64

	char c;

	c = base[nbr % basesize]
*/