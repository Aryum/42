/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:30:38 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/17 10:41:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rot.h"

t_rot rot_create(t_data data, char pushto, int tar_index)
{
	t_rot	ret;

	ret.tar_index = tar_index;
	if (pushto == 'a')
	{
		ret.push = mv_pushto_a;
		ret.lst = data.b->lst;
		ret.cost = mv_calculate_push(*data.b, tar_index);
		if (ret.cost >= 0)
			ret.rotate = mv_rotate_b;
		else
			ret.rotate = mv_rotate_rev_b;
	}
	else if (pushto == 'b')
	{
		ret.push = mv_pushto_b;
		ret.lst = data.a->lst;
		ret.cost = mv_calculate_push(*data.a, tar_index);
		if (ret.cost >= 0)
			ret.rotate = mv_rotate_a;
		else
			ret.rotate = mv_rotate_rev_a;
	}
	print_f("ROT CREATE-> Cost to move index %d -> %d\n",tar_index,ret.cost);
	return ret;
}
