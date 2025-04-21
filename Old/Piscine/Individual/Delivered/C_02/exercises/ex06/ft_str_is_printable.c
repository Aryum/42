/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:34:23 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 11:34:25 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prt(char input)
{
	return (input > 31);
}

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!is_prt(*str))
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
	char c[] = "teste";

	if(ft_str_is_printable(c))
	{
		printf("Its only printable");
	}
	else
	{
		printf("has other types");
	}
}
*/