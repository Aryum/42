/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:45:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/20 18:42:12 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static void rec(t_data data, t_list *lst, t_rtp rot, int print)
{
	if(lst->val.index == rot.tar_idx)
		rot.push(data);
	else
	{
		rot.rotate(data);
		rec(data, lst, rot, print);
	}
}

static void update(t_data data, t_rtp *rots)
{
	int	i;

	i = 0;
	while(rots[i].tar_idx != -1)
	{
		rtp_updaterot(data, &rots[i]);
		i++;
	}
	rtp_sort(rots);
}

void rtp_push_single(t_data data, t_rtp rot, int print)
{
	rec (data, get_lst_topush(data, rot.from), rot, print);
}

int	rtp_push_multiple(t_data data, t_id id, int nbr, int (*func)(int, int))
{
	t_rtp	*rots;
	int		i;

	rots = rtp_create_all(data, id, nbr, func);
	i = 0;
	if (rots != NULL)
	{
		while (rots[i].tar_idx != -1)
		{
			rtp_push_single(data,rots[i], 1);
			update(data, &rots[i + 1]);
			i++;
		}
		free(rots);
		return (1);
	}
	return (0);
}
