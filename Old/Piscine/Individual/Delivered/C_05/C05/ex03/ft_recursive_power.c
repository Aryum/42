/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:10:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/01 15:10:25 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power > 0)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	else if (power < 0)
	{
		return (0);
	}
	return (1);
}
/*
#include <stdio.h>
int	main()
{
	int nbr = 2;
	int pwr = 3;

	printf("%d powered to %d is %d", nbr, pwr, ft_recursive_power(nbr,pwr));

	return 0;
}
*/