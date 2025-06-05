/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:30:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 12:06:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_add_front(t_list **lst, int nbr)
{
	t_list	*new_node;

	if (lst != NULL)
	{
		new_node = lst_new(nbr);
		(*new_node).next = (*lst);
		(**lst).last = new_node; 
		*lst = new_node;
	}
}
