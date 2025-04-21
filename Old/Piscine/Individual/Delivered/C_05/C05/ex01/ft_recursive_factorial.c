/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:34:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/02/01 14:34:10 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 0)
	{
		if (nb - 1 > 0)
			nb *= ft_recursive_factorial(nb - 1);
		return (nb);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main()
{
	int i = 0;
	printf("Factorial of %d is %d", i, ft_recursive_factorial(i));

	return 0;
}
*/