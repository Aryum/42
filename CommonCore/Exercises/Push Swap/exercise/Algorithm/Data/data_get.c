/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:11:56 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/20 13:07:44 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_list *get_lst_topush(t_data data, t_id pushto)
{
	if (pushto == a)
		return (data.b->lst);
	if (pushto == b)
		return (data.a->lst);
	print_f("GET LIST-> wrong char passed\n");
	return (NULL);
}

t_stack *get_stack(t_data stack, t_id id)
{
	if (id == a)
		return stack.a;
	else 
		return stack.b;
}

t_func get_func(t_id id)
{
	t_func ret;
	if (id == a)
	{
		ret.push = mv_pushto_b;
		ret.rot = mv_rotate_a;
		ret.rev_rot= mv_rotate_rev_a;
		ret.swap= mv_swap_a;
	}
	else
	{
		ret.push = mv_pushto_a;
		ret.rot = mv_rotate_b;
		ret.rev_rot = mv_rotate_rev_b;
		ret.swap= mv_swap_b;
	}
	return (ret);
}
