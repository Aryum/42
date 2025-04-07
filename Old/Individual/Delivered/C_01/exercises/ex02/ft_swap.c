/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:41:00 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 09:54:41 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 1;
	int b = 2;

	ft_swap(&a, &b);
	printf("%d",a);
	printf("%d",b);
}
*/