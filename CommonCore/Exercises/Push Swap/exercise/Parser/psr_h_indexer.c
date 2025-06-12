/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_h_indexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:13:44 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:38 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psr.h"

void	swap_nbr(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	psr_h_indexer(t_list *tab)
{
	t_list	*lst_tmp;
	int		swapped;

	swapped = 0;
	while (tab != NULL)
	{
		lst_tmp = tab;
		while (lst_tmp != NULL)
		{
			if (lst_tmp->content.value > lst_tmp->next->content.value)
			{
				swap_nbr(&(lst_tmp->content.index), &(lst_tmp->next->content.index));
				swapped = 1;
			}
			lst_tmp = lst_tmp->next;
		}
		if (swapped == 0)
			break ;
		tab = tab->next;
	}
}


