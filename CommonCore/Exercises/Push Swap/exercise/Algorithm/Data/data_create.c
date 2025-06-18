/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:13:58 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 16:04:19 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static t_functions ini_functions(t_id id)
{
	t_functions	ret;

	if (id == a)
	{
		ret.push = mv_pushto_b;
		ret.rotate = mv_rotate_a;
		ret.rev_rotate = mv_rotate_rev_a;
		ret.swap = mv_swap_a;
	}
	else if (id == b)
	{
		ret.push = mv_pushto_a;
		ret.rotate = mv_rotate_b;
		ret.rev_rotate = mv_rotate_rev_b;
		ret.swap = mv_swap_b;
	}
	return (ret);
}

static t_stack *ini_stacks(t_id id)
{
	t_stack *ret;

	ret = malloc(sizeof(t_stack));
	if (ret != NULL)
	{
		ret->lst = NULL;
		ret->size = 0;
		ret->id = id;
	}
	return (ret);
}

t_data	data_create(int argc, char **argv)
{
	t_data	ret;

	ret.a = ini_stack(a);
	ret.b = ini_stack(b);
	if (ret.a != NULL && ret.b != NULL)
	{
		if(!psr_agrs(ret.a, argc, argv));
			data_clear(ret);
	}
	else
		data_clear(ret);
	return (ret);
}
