/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:32:18 by ricsanto          #+#    #+#             */
/*   Updated: 2025/01/28 10:25:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_nbr(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	h;
	int	swapped;

	i = 0;
	h = 0;
	swapped = 1;
	while (i < size)
	{
		while (h < size - i - 1)
		{
			if (tab[h] > tab[h + 1])
			{
				swap_nbr(&tab[h], &tab[h + 1]);
				swapped = 0;
			}
			h++;
		}
		if (swapped == 1)
		{
			break ;
		}
		h = 0;
		i++;
	}
}
/*
#include<stdio.h>
int main()
{
    int arr[6] = { 6, 5, 3, 9, 2, 1};
    ft_sort_int_tab(arr,6);

	int counter = 0;

    while(counter < 6 )
    {
        printf("%d", arr[counter]);
        counter ++;
    }

}
*/