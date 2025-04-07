/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:34:04 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 11:29:28 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_nbr(char input)
{
	return (input >= '0' && input <= '9');
}

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!is_nbr(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	char c[5] = "222";

	if(ft_str_is_numeric(c))
	{
		printf("Its only numbers");
	}
	else
	{

		printf("Has other chars");
	}
}
*/