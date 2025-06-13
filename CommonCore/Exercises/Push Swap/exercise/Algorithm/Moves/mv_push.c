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

static void push_first(t_stack *lst_add, t_stack *lst_take, char c)
{
	if (lst_take->lst == NULL)
	{
		print_f("Trying to push from list %c that is empty\n", c);
		return ;
	}
	if(lst_add->lst != NULL)
		lst_add_front(&(lst_add->lst), lst_take->lst->content);
	else
		lst_add->lst = lst_new(lst_take->lst->content);
	lst_delone(&(lst_take->lst), lst_take->lst);
	lst_add->size++;
	lst_take->size--;
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