/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:43:48 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 11:43:50 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lwr_ltr(char input)
{
	return (input >= 'a' && input <= 'z');
}

char	*ft_strupcase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (is_lwr_ltr(str[counter]))
		{
			str[counter] -= 32;
		}
		counter++;
	}
	return (str);
}
/*
#include<stdio.h>
int	main(void)
{
	char	c[10] = "Abc!";
	ft_strupcase(c);
	printf("%s", c);
}
*/