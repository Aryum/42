/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:45:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/19 12:15:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static void rec(t_data data, t_list *lst, t_rtp rot, int print, int loops)
{
	if(loops > 4)
		return ;
	if (print)
		dbg_print_stack(data);
	if(lst->val.index == rot.tar_idx)
		rot.psh_info.push(data);
	else
	{
		rot.rotate(data);
		rec(data, lst, rot, print, loops + 1);
	}
}

static void update(t_data data,t_rtp *rots)
{
	int	i;

	i = 0;
	while(rots[i].tar_idx != -1)
	{
		rtp_setrot(data, &rots[i]);
		i++;
	}
	rtp_sort(rots);
}

void rtp_push_single(t_data data, t_psh p_info, t_rtp rot, int print)
{
	rec (data, rtp_get_lst(data,p_info.tolst), rot, print, 0);
}

int	rtp_push_multiple(t_data data, t_psh p_info, int nbr, int (*func)(int, int))
{
	t_rtp	*rots;
	int		i;

	rots = rtp_create_all(data, p_info, nbr, func);
	i = 0;
	if (rots != NULL)
	{
		while (rots[i].tar_idx != -1)
		{
			rtp_push_single(data, p_info, rots[i], 1);
			update(data, &rots[i + 1]);
			i++;
		}
		free(rots);
		return (1);
	}
	return (0);
}
