/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:50:10 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/04 11:53:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
#include <stdio.h>
int main()
{
	int nbr1 = 2;
	int nbr2 = 3;
	printf("%d  %d\n", nbr1, nbr2);
	ft_swap(&nbr1,&nbr2);
	printf("%d %d", nbr1, nbr2);
}
*/