/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_sequence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:17:00 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 14:13:52 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk.h"

/// @brief 
/// @return index where sequence starts
int	chk_sequence(t_stack *stack)
{
	t_list	*lst;
	int		index;

	lst = stack->lst;
	index = -1;
	while (lst->next != NULL)
	{
		if (lst->val.index + 1 == lst->next->val.index && index == -1)
			index =  lst->val.index;
		if (index != -1 && lst->val.index + 1 != lst->next->val.index)
			return (0);
		lst = lst->next;
	}
	return (index);
}
