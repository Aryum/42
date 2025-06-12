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

static void push_first(t_list **lst_add, t_list **lst_take, char c)
{
	if (lst_take == NULL || *lst_take == NULL)
	{
		print_f("Trying to push from list %c that is empty\n", c);
		return ;
	}
	if(*lst_add != NULL)
		lst_add_front(lst_add, (*lst_take)->content);
	else
		*lst_add = lst_new((*lst_take)->content);
	lst_delone(lst_take, *lst_take);
	mv_h_print("p", c);
}
 
void mv_push_a(t_stacks *lsts)
{
	push_first(&(lsts->a), &(lsts->b), 'a'); 
}

void mv_push_b(t_stacks *lsts)
{
	push_first(&(lsts->b), &(lsts->a), 'b');
}