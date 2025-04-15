/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:42:48 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/15 15:13:41 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int ft_atoi(const char *nptr)
{
	unsigned int i;
	int sign;
	int retval;

	sign = 1;
	retval = 0;
	i = 0;
	if(nptr[0] == '-' || nptr[0] == '+')
	{
		if (nptr[0] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		retval += nptr[i] - '0';
		if(ft_isdigit(nptr[i + 1]))
			retval *= 10;
		i++;
	}
	return (retval * sign);
}
