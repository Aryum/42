/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:40:27 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/17 18:17:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static int	counter(t_list *lst, int tar,int (*func)(int, int))
{
	int	ret;

	ret = 0;
	while (lst != NULL)
	{
		//lst->val.index <= max_idx
		if (func(tar, lst->val.index))
			ret	++;
		lst = lst->next;
	}
	return (ret);
}

static t_list *get_lst(t_data data, char pushto)
{
	if (pushto == 'a')
		return (data.b->lst);
	if (pushto == 'b')
		return (data.a->lst);
	return (NULL);
}

t_psh rtp_psh_info(char c, void (*func)(t_data))
{
	t_psh	ret;

	ret.tolst = c;
	ret.on_push = func;
	return (ret);
}

t_rtp rtp_create(t_data data, t_psh p_info, int tar_idx)
{
	t_rtp	ret;

	ret.tar_index = tar_idx;
	ret.on_end = p_info.on_push;
	if (p_info.tolst == 'a')
	{
		ret.push = mv_pushto_a;
		ret.cost = mv_calculate_push(*data.b, tar_idx);
		if (ret.cost >= 0)
			ret.rotate = mv_rotate_b;
		else
			ret.rotate = mv_rotate_rev_b;
	}
	else if (p_info.tolst == 'b')
	{
		ret.push = mv_pushto_b;
		ret.cost = mv_calculate_push(*data.a, tar_idx);
		if (ret.cost >= 0)
			ret.rotate = mv_rotate_a;
		else
			ret.rotate = mv_rotate_rev_a;
	}
	print_f("ROT CREATE-> Cost to move index %d -> %d\n",tar_idx,ret.cost);
	return ret;
}

/// @return indexes that needs to be pushed to b that me
t_rtp	*rtp_create_all(t_data data, t_psh p_info, int nbr, int (*func)(int, int))
{	
	t_list	*lst;
	t_rtp	*ret;
	int		len;
	int		i;

	i = 0;
	lst = get_lst(data, p_info.tolst);
	len = counter(lst, nbr, func); 
	ret = lib_calloc(sizeof(t_rtp), len + 1);
	if (ret != NULL)
	{
		while (lst != NULL)
		{
			if (func(nbr, lst->val.index))
			{
				ret[i] = rtp_create(data, p_info, lst->val.index);
				i++;
			}
			lst = lst->next;
		}
		rtp_sort(ret, len);
		ret[len].tar_index = -1;
	}
	return (ret);
}
