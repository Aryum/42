/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:51:48 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 09:59:50 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (*b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 10;
	int b = 3;

	ft_ultimate_div_mod(&a, &b);
	printf("%d", a);
	printf("%d",b);
}
*/