/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_h_try_add_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:28:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/09 18:16:13 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/psr.h"

int	psr_h_try_add_number(t_list **lst, int nbr)
{
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		if ((current->content) == nbr)
		{
			lst_clear(lst);
			print_f("Multiple instances of the same number\n");
			return (0);
		}
		current = current->next;
	}
	lst_add_back(lst, nbr);
	return (1);
}
