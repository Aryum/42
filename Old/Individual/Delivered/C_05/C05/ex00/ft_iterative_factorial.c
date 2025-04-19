/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:19:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/01 14:19:42 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret_val;

	if (nb > 0)
	{
		ret_val = nb;
		while (nb > 1)
		{
			nb --;
			ret_val *= nb;
		}
	}
	else if (nb == 0)
		ret_val = 1;
	else
		ret_val = 0;
	return (ret_val);
}
/*
#include <stdio.h>
int	main()
{
	int i = -1;
	printf("Factorial of %d is %d", i, ft_iterative_factorial(i));

	return 0;
}
*/