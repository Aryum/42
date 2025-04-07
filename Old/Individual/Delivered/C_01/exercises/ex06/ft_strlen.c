/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:06:38 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 10:06:42 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str ++;
	}
	return (counter);
}
/*
#include<stdio.h>
int	main(void)
{
	char	*c = "Hello";
	int		count = ft_strlen(c);
	printf("%d", count);
	return 0;
}
*/