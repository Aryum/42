/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:14:19 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/17 17:22:16 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srt.h"

int	is_sorted(t_stack stack)
{
	t_list *lst;

	lst = stack.lst;
	while (lst->next != NULL)
	{
		if(lst->val.index + 1 !=  lst->next->val.index)
			return (0);
		lst = lst->next;
	}
	return (1);
}