/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_getcost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:40:27 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 17:40:28 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk.h"

static int	counter(t_list *lst, int (*func)(int))
{
	int	ret;
	while (lst != NULL)
	{
		//lst->val.index <= max_idx
		if (func(lst->val.index))
			ret	++;
		lst = lst->next;
	}
	return (ret);
}

static t_cost create_cost(t_stack stack, int index)
{
	t_cost ret;

	ret.cost = mv_calculate_push(stack, index);
	ret.idx = index;
	return ret;
}
/// @return indexes that needs to be pushed to b
t_cost	*chk_stackindex(t_stack stack, int (*func)(int))
{
	t_list *lst;
	t_cost	*ret;
	int		len;
	int		i;

	i = 0;
	lst = stack.lst;
	len = counter(lst, func); 
	ret = lib_calloc(sizeof(int), len + 1);
	if (ret != NULL)
	{
		ret[len].idx = -1;
		while (lst != NULL)
		{
			if (func(lst->val.index))
				ret[i] = create_cost(stack, lst->val.index);
			i++;
			lst = lst->next;
		}
	}
	
	return (ret);
}
