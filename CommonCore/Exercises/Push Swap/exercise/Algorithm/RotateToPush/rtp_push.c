/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:45:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/17 16:55:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

static void rec(t_data data, t_list *lst, t_rtp rot, int print)
{
	if (print)
		dbg_print_stack(data);
	if(lst->val.index == rot.tar_index)
	{
		rot.push(data);
		if(rot.on_end != NULL)
			rot.on_end(data);
	}
	else
	{
		rot.rotate(data);
		rec(data, lst, rot, print);
	}
}

void rtp_push_single(t_data data, char pushto, t_rtp rot, int print)
{
	rec (data, rtp_get_lst(data,pushto), rot, print);
}

int	rtp_push_multiple(t_data data, char pushto, int nbr, int (*func)(int, int))
{
	t_rtp	*rots;
	int		i;

	rots = rtp_create_all(data, pushto, nbr, func);
	i = 0;
	if (rots != NULL)
	{
		while (rots[i].tar_index != -1)
		{
			rtp_push_single(data, pushto, rots[i], 1);
			i++;
		}
		free(rots);
		return (1);
	}
	return (0);
}
