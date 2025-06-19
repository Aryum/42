/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:22:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/19 12:44:55 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srt.h"

void srt_three(t_data data, t_id id)
{
	t_stack	*stack;
	t_func	func;

	stack = get_stack(data, id);
	func = get_func(id);
	if (is_sorted(*stack))
		return ;
	if (is_rev_sorted(*stack))
	{
		while (stack->lst->val.index != stack->min)
			func.rev_rot(data);
	}
	//swap top

	//swap lower

	//has sequence
		//lwr is on bottom
		//bgr is on top

}

