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

static void push_first(t_stack *stk_add, t_stack *stk_take, char c)
{
	if (stk_take->lst == NULL)
	{
		print_f("Trying to push from list %c that is empty\n", c);
		return ;
	}
	if(stk_add->lst != NULL)
		lst_add_front(&(stk_add->lst), stk_take->lst->val);
	else
		stk_add->lst = lst_new(stk_take->lst->val);
	lst_delone(&(stk_take->lst), stk_take->lst);
	stk_add->size++;
	stk_take->size--;
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