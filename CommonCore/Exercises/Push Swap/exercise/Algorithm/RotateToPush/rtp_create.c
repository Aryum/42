/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:40:27 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/19 12:15:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static int	counter(t_list *lst, int tar,int (*func)(int, int))
{
	int	ret;

	ret = 0;
	while (lst != NULL)
	{
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
	ret.push = func;
	return (ret);
}

t_rtp rtp_create(t_data data, t_psh p_info, int tar_idx)
{
	t_rtp	ret;

	ret.tar_idx = tar_idx;
	ret.psh_info = p_info;
	rtp_setrot(data, &ret);
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
		ret[len].tar_idx = -1;
		rtp_sort(ret);
	}
	return (ret);
}
