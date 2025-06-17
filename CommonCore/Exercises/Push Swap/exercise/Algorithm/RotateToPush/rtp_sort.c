/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:17:17 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/17 16:55:28 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static void	swap(t_rtp *a, t_rtp *b)
{
	t_rtp	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void updatenegative(t_rtp *tab, int size)
{
	int	max;
	int	i;

	i = 0;
	max = -2147483648;
	while(i < size)
	{
		if (tab[i].tar_index > max)
			max = tab->tar_index;
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (tab[i].cost < 0)
			tab[i].cost = max + -1 * tab[i].cost;
		i++;
	}
}

void	rtp_sort(t_rtp *tab, int size)
{
	int	i;
	int	h;
	int	swapped;

	i = 0;
	h = 0;
	swapped = 1;
	updatenegative(tab, size);
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
