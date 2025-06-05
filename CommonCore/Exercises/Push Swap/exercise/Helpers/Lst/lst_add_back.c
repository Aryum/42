/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:30:04 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 12:25:10 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_add_back(t_list **lst, int nbr)
{
	t_list	*new_node;
	t_list	*last_node;

	if (lst == NULL)
		return ;
	new_node = lst_new(nbr);
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		last_node = lst_last(*lst);
		(*last_node).next = new_node;
		(*new_node).last = last_node;
	}
}
