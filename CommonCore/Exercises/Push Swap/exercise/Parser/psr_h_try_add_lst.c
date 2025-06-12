/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_h_try_add_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:28:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:13:38 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psr.h"

int	psr_h_try_add_number(t_list **lst, int nbr, int *last_index)
{
	t_list	*current;
	t_nbr	new;
	
	current = *lst;
	new.index = (*last_index) + 1;
	new.value = nbr;
	while (current != NULL)
	{
		if ((current->content).value == nbr)
			return (lst_clear(lst), 0);
		current = current->next;
	}
	(*last_index)++;
	lst_add_back(lst, new);
	return (1);
}
