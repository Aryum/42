/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:19:15 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/08 12:38:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x1;
	int	x2;

	x1 = nb / 2;
	x2 = (x1 + nb) / 2;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	while (x2 < x1)
	{
		x1 = x2;
		x2 = (x1 + nb / x1) / 2;
		x1++;
	}
	if (x1 * x1 == nb)
		return (x1);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%d", ft_sqrt(1));
}
*/