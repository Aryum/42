/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:24:23 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 12:24:25 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_cpt_ltr(char input)
{
	return (input >= 'A' && input <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (is_cpt_ltr(str[counter]))
		{
			str[counter] += 32;
		}
		counter++;
	}
	return (str);
}
/*
#include<stdio.h>
int	main(void)
{
	char	c[10] = "ABC!";
	ft_strlowcase(c);
	printf("%s", c);
}
*/