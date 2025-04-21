/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:09:50 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 10:21:59 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	first_nbr;
	int	last_nbr;

	i = 0;
	first_nbr = 0;
	last_nbr = 0;
	while (i < (size / 2))
	{
		first_nbr = tab[i];
		last_nbr = tab[size - 1 - i];
		tab[i] = last_nbr;
		tab[size - 1 - i] = first_nbr;
		i++;
	}
}
/*
#include<stdio.h>
int	main(void)
{
	int arr[7] = {1,2,3,4,5,6,7};
	int	counter = 0;
	ft_rev_int_tab(arr, 7);

	while(counter < 7)
	{
		printf("%d", arr[counter]);
		counter++;
	}
	return 0;
}
*/