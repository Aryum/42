/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:17:17 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 20:44:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rot.h"

static void	swap(t_rot *a, t_rot *b)
{
	t_rot	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	rot_sort(t_rot *tab, int size)
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
			if (tab[h].cost > tab[h + 1].cost)
			{
				swap(&tab[h], &tab[h + 1]);
				swapped = 0;
			}
			h++;
		}
		if (swapped == 1)
			break ;
		h = 0;
		i++;
	}
}
