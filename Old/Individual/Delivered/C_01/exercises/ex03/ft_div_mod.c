/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:47:34 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 09:57:39 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 10;
	int b = 3;
	int div = 1;
	int mod = 1;

	ft_div_mod(a, b, &div, &mod);
	printf("%d", div);
	printf("%d",mod);
}
*/