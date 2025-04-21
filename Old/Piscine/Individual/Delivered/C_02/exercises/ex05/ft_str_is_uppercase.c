/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:28:35 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 11:28:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_cpt_ltr(char input)
{
	return (input >= 'A' && input <= 'Z');
}

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (!is_cpt_ltr(*str))
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
	char c[5] = "WWW";

	if(ft_str_is_uppercase(c))
	{
		printf("Its only Upper");
	}
	else
	{
		printf("has other types");
	}
}
*/