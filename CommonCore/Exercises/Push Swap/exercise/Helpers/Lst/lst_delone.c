/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:04:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 11:09:09 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static int isnot_null(t_list **node)
{
	return (node != NULL && *node != NULL);
}

void	lst_delone(t_list **start, t_list **node, void (*del)(void*))
{
	t_list *current;
	if (isnot_null(node) && isnot_null(start) && del != NULL)
	{
		current = *node;
		if(*start == *node)
			*start = (**start).next;
		if (current->last != NULL)
			current->last->next = current->next;
		else
			*node = current->next;
		if (current->next != NULL)
			current->next->last = current->last;
		del(current->content);
		free (current);
	}
}
