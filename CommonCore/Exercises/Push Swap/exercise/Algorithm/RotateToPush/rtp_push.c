/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:45:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/25 15:47:16 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static int rec(t_data data, t_list **lst, t_rtp rot)
{
	if((*lst)->val.index == rot.tar_idx)
		return (rot.push(data));
	else
	{
		rot.rotate(data);
		return (rec(data, lst, rot));
	}
}

static void update(t_data data, t_rtp *rots)
{
	int	i;

	i = 0;
	if(rots[i].tar_idx != -1)
	{
		while(rots[i].tar_idx != -1)
		{
			rtp_updaterot(data, &rots[i]);
			i++;
		}
		rtp_sort(rots);
	}
}

int rtp_push_single(t_data data, t_rtp rot)
{
	return (rec (data, get_lst_topush(data, rot.from), rot));
}

int	rtp_push_multiple(t_data data, t_id id, int nbr, int (*func)(int, int))
{
	t_rtp	*rots;
	int		ret;
	
	rots = rtp_create_all(data, id, nbr, func);
	if (rots != NULL)
	{
		ret = rtp_push_arr(data, rots);
		free(rots);
		return (ret);
	}
	return (0);
}

int	rtp_push_arr(t_data data, t_rtp *rots)
{
	int	ret;
	int	i;

	i = 0;
	while (rots[i].type != none)
	{
		data.next_rot = rots[i + 1].type; 
		ret = rtp_push_single(data,rots[i]);
		if(!ret)
			break ;
		update(data, &(rots[i + 1]));
		i++;
	}
	return (ret);
}