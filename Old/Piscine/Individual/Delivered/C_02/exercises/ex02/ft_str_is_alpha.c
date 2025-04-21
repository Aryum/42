/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:17:35 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 11:29:21 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lwr_ltr(char input)
{
	return (input >= 'a' && input <= 'z');
}

int	is_cpt_ltr(char input)
{
	return (input >= 'A' && input <= 'Z');
}

int	is_ltr(char input)
{
	return (is_lwr_ltr(input) || is_cpt_ltr(input));
}

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (!is_ltr(*str))
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
	char c[5] = "w_ww";
	if(ft_str_is_alpha(c))
	{
		printf("Its only letters");
		
	}
	else
	{
		printf("Has other chars");
	}
}
*/