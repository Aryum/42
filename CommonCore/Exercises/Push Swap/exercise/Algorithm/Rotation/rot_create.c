/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:30:38 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/13 18:45:28 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rot.h"

t_rot rot_create(t_data data, char pushto, int tar_index)
{
	t_rot	ret;

	ret.tar_index = tar_index;
	if (pushto == 'a')
	{
		ret.rotate = mv_rotate_a;
		ret.push = mv_pushto_b;
		ret.lst = data.a->lst;
		ret.dir = mv_calculate_push(*data.a, tar_index);
	}
	else if (pushto == 'b')
	{
		ret.rotate =mv_rotate_b;
		ret.push = mv_pushto_a;
		ret.lst = data.b->lst;
		ret.dir = mv_calculate_push(*data.b, tar_index);
	}
	return ret;
}
