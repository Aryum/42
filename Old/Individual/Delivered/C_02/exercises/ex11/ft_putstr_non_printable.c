/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:14:14 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 17:14:19 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_prt(char input)
{
	return (input > 31);
}

void	print_non_printable(char c)
{
	char	hex_1st;
	char	hex_2nd;
	char	*hex_values;

	hex_values = "0123456789abcdef";
	hex_1st = hex_values[c / 16];
	hex_2nd = hex_values[c % 16];
	write(1, "\\", 1);
	write(1, &hex_1st, 1);
	write(1, &hex_2nd, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (!is_prt(*str))
		{
			print_non_printable(*str);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
/*
int	main()
{
	ft_putstr_non_printable("Ola\nesta bem?");
	return (0);
}
*/