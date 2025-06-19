/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:34:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:07 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mv.h"

static void update_stack(t_stack *stk, t_nbr val)
{
	if (stk->size == 0)
	{
		stk->max = -1;
		stk->min = -1;
	}
	else if(val.index >= stk->max || val.index <= stk->min)
		mv_h_update(stk);
	else if (stk->max == -1 || stk->min == -1)
		mv_h_update(stk);
}

static void push_first(t_stack *stk_add, t_stack *stk_take, char c)
{
	t_nbr val;

	if (stk_take->lst == NULL)
	{
		print_f("Trying to push from list %c that is empty\n", c);
		return ;
	}
	val = stk_take->lst->val;
	if(stk_add->lst != NULL)
		lst_add_front(&(stk_add->lst), val);
	else
		stk_add->lst = lst_new(val);
	lst_delone(&(stk_take->lst), stk_take->lst);
	stk_add->size++;
	stk_take->size--;
	update_stack(stk_add, val);
	update_stack(stk_take, val);
	mv_h_print("p", c);
}
 
void mv_pushto_a(t_data data)
{
	push_first(data.a, data.b, 'a'); 
}

void mv_pushto_b(t_data data)
{
	push_first(data.b, data.a, 'b');
}