/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:24:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 11:02:07 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_base_valid(char *str)
{
	int		i;
	int		j;

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

static int alloc_size(unsigned int nbr, int base_size)
{
	int	i;

	i = 1;
	while (nbr / base_size != 0)
	{
		nbr /= base_size;
		i++;
	}
	return (i);
}
#include <stdio.h>

char *uint_tobase(unsigned int nbr, char *base)
{
	char	*ret;
	int		ret_sz;
	int		base_sz;
	
	if(is_base_valid(base))
	{
		base_sz =  ft_strlen(base);
		ret_sz = alloc_size(nbr, base_sz);
		ret = ft_calloc(ret_sz + 1, sizeof(char));
		if(ret != NULL)
		{			
			ret_sz --;
			while(nbr / base_sz > 0)
			{
				ret[ret_sz] = base[nbr % base_sz];
				nbr /= base_sz;
				ret_sz--;
			}
			ret[ret_sz] = base[nbr % base_sz];
			return (ret);
		}
	}
	return (ft_calloc(0,0));
}

int main()
{
	printf("Test %s", int_tobase(2147483648,"0123456789abcdef"));
}