/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:12:22 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/02 12:12:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calculate_is_prime(int target, int last)
{
	if (target <= 1)
		return (0);
	else
	{
		if (target != last)
		{
			if (target % last == 0)
				return (0);
			else
				return (calculate_is_prime(target, last + 1));
		}
		else
			return (1);
	}
}

int	ft_is_prime(int nb)
{
	if (nb == 0 || nb == 1)
		return (0);
	return (calculate_is_prime(nb, 2));
}
/*
#include <stdio.h>

int main()
{
	int	nbr = 9;
	printf("Is prime %d is %s", nbr, ft_is_prime(nbr) ? "yes" : "no" );
	return 0;
}
*/