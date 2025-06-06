/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_try_add_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:28:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 10:07:25 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psr.h"

int psr_try_add_number(t_list **lst, int nbr)
{
	t_list	*current;
	
	current = lst;
	while(current != NULL)
	{
		if(*(int *)(current->content) == nbr)
		{
			lst_clear(lst);
			return (0);
		}
		current = current->next;
	}
	lst_add_back(&current,lst_new(&nbr));
	return (1);
}
