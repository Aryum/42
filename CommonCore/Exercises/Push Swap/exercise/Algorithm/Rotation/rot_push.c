/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:45:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/17 10:55:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rot.h"

static void dividestacks(t_data stacks)
{
	int		to_push;
	t_rot	rot;
	
	to_push = 0;
	//to_push = chk_stackindex(stacks);
	printlists(stacks);
	if (to_push)
	{
		rot = rot_create(stacks,'b', to_push);
		rot_push(stacks,rot);
		dividestacks(stacks);
	}
}


int	rot_push(t_data data, char pushto, int nbr, int (*func)(int, int))
{
	t_rot	*rots;
	int		i;

	rots = rot_getrot(data, pushto, nbr, func);
	i = 0;
	if (rots != NULL)
	{
		while (rots[i].tar_index != -1)
		{
			
			i++;
		}
		return (1);
	}
	return (0);
}