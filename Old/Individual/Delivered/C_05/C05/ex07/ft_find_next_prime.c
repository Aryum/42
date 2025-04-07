/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:08:10 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/02 13:08:12 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calculate_is_prime(int target, int last)
{
	if (target <= 1)
		return (0);
	else 
	{
		if(target != 2147483647)
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
		else
			return (1);
	}
}

int	ft_find_next_prime(int nb)
{
	while (!calculate_is_prime(nb, 2))
	{
		nb++;
	}
	return (nb);
}

#include <stdio.h>

int main()
{
	int	nbr = 2147483645;
	printf("\nThe next prime of %d is %d",  nbr, ft_find_next_prime(nbr));
	return 0;
}
