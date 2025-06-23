/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:45:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/23 14:17:39 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static int rec(t_data data, t_list *lst, t_rtp rot, int print)
{
	if (print)
		dbg_print_stack(data);
	if(lst->val.index == rot.tar_idx)
		return (rot.push(data));
	else
	{
		rot.rotate(data);
		return (rec(data, lst, rot, print));
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

int rtp_push_single(t_data data, t_rtp rot, int print)
{
	return (rec (data, get_lst_topush(data, rot.from), rot, print));
}

int	rtp_push_multiple(t_data data, t_id id, int nbr, int (*func)(int, int))
{
	t_rtp	*rots;
	int		i;
	int		ret;
	
	rots = rtp_create_all(data, id, nbr, func);
	i = 0;
	if (rots != NULL)
	{
		while (rots[i].tar_idx != -1)
		{
			ret = rtp_push_single(data,rots[i], 0); 
			if(!ret)
				break ;
			update(data, &rots[i + 1]);
			i++;
		}
		free(rots);
		return (ret);
	}
	return (0);
}
