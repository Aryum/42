/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqc_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:37:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 14:06:04 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sqc.h"

int	is_sorted(t_stack stack)
{
	t_list *lst;
	
	lst = stack.lst;
	while (lst->next != NULL)
	{
		if(lst->val.index + 1 != lst->next->val.index)
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
		if(lst->val.index - 1 != lst->next->val.index)
			return (0);
		lst = lst->next;
	}
	return (1);
}