/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:37:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/19 14:50:31 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk.h"

int	next_bigger(t_list *lst)
{
	return (lst->val.index + 1 == lst->next->val.index);
}

int	next_lower(t_list *lst)
{
	return (lst->val.index - 1 == lst->next->val.index);
}

int	is_sorted(t_stack stack)
{
	t_list *lst;
	
	lst = stack.lst;
	while (lst->next != NULL)
	{
		if(!next_bigger(lst))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_rev_sorted(t_stack stack)
{
	t_list *lst;

	lst = stack.lst;
	while (lst->next != NULL)
	{
		if(!next_lower(lst))
			return (0);
		lst = lst->next;
	}
	return (1);
}

