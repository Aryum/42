/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_getcost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:40:27 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 20:57:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rot.h"

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

static t_list *get_lst(t_data data, char pushto)
{
	if (pushto == 'a')
		return (data.b);
	if (pushto == 'b')
		return (data.a);
	return (NULL);
}

/// @return indexes that needs to be pushed to b that me
t_rot	*rot_getrot(t_data data, char pushto, int nbr, int (*func)(int, int))
{	
	t_list	*lst;
	t_rot	*ret;
	int		len;
	int		i;

	i = 0;
	lst = get_lst(data, pushto);
	len = counter(lst, func); 
	ret = lib_calloc(sizeof(int), len + 1);
	if (ret != NULL)
	{
		while (lst != NULL)
		{
			if (func(nbr, lst->val.index))
				ret[i] = rot_create(data, pushto ,lst->val.index);
			i++;
			lst = lst->next;
		}
		ret[i].tar_index = -1;
		rot_sort(ret, len);
	}
	return (ret);
}
