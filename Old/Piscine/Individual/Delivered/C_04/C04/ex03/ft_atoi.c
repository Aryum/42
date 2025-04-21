/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:30:44 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/30 12:30:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_nbr(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_whitespace(char c)
{
	return (c == ' ' || (c >= '\b' && c <= '\r'));
}

int	is_simbol(char c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(char *str)
{
	int	simbol;
	int	nbr;
	int	i;

	nbr = 0;
	simbol = 1;
	i = 0;
	while (is_whitespace(str[i]))
		i++;
	while (is_simbol(str[i]))
	{
		if (str[i] == '-')
			simbol *= -1;
		i++;
	}
	while (is_nbr(str[i]))
	{
		nbr += str[i] - '0';
		if (str[i + 1] != '\0' && is_nbr(str[i + 1]))
			nbr *= 10;
		i++;
	}
	return (simbol * nbr);
}

/*
#include <stdio.h>
int main ()
{
	char *c = "     \f\n\r\t\v---123\f\n\r\t\v4--a4ab567";

	printf("%d", ft_atoi(c));

	return 0;	
}
*/