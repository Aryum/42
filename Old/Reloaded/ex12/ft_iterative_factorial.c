/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:00:43 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 11:13:53 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	long int	ret_val;

	ret_val = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		ret_val *= nb;
		nb--;
		if (ret_val > 2147483648)
		{
			return (0);
		}
	}
	return (ret_val);
}

/*
#include <stdio.h>
#include <time.h>
int main()
{
	printf("%d", ft_iterative_factorial(12));	
}
*/