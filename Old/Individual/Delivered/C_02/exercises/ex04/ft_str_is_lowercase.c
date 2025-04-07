/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:39:57 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 11:28:58 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lwr_ltr(char input)
{
	return (input >= 'a' && input <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (!is_lwr_ltr(*str))
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
	char c[5] = "wwww";

	if(ft_str_is_lowercase(c))
	{
		printf("Its only lower");
	}
	else
	{
		printf("has other types");
	}
}
*/