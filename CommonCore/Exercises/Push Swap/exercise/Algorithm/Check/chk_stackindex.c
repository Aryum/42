/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_stackindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:37:35 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 14:58:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk.h"

/// @brief 
/// @return index that needs to be pushed to b
int	chk_stackindex(t_data data)
{
	t_list *lst;
	int		max_idx;
	
	lst = data.a->lst;
	max_idx = data.total_size / 2;
	while (lst != NULL)
	{
		print_f("testing %d\n", lst->val.index);
		if (lst->val.index <= max_idx)
			return (lst->val.index);
		lst = lst->next;
	}
	return (0);
}