/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_print_nbrbase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:31:47 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/30 12:22:23 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "prtf.h"

static int	is_base_valid(char *str)
{
	size_t	i;
	size_t	j;

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

void	h_print_nbrbase(unsigned long int nbr, char *base, int *counter)
{
	size_t	base_sz;
	
	if(is_base_valid(base))
	{
		base_sz =  ft_strlen(base);
		while(nbr / base_sz > 0)
		{
			h_putchar(base[nbr % base_sz], counter);
			nbr /= base_sz;
		}
		h_putchar(base[nbr % base_sz], counter);
	}
}
