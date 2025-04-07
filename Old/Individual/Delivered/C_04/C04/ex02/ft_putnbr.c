/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:31:04 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/10 10:54:42 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		current_char;
	int		correction;

	correction = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			correction = 1;
		}
		write(1, "-", 1);
		nb = -(nb + correction);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	current_char = (nb % 10) + ('0' + correction);
	write(1, &current_char, 1);
}
/*
int	main(void)
{
	ft_putnbr(2147483647);
	return (0);
}

*/