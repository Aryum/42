/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:20:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mv.h"

static int rev_rotate(t_list *lst, char c)
{
	t_list *lst_tmp;
	t_nbr	nbr_tmp;
	
	if (lst == NULL)
	{
		print_f("Trying to rotate list %c that is empty\n", c);
		return (0);
	}
	lst_tmp = lst_last(lst);
	nbr_tmp = lst_tmp->content;
	while (lst_tmp->last != NULL)
	{
		lst_tmp->content = lst_tmp->last->content;
		lst_tmp = lst_tmp->last;
	}
	lst_tmp->content = nbr_tmp;
	mv_h_print("rr", c);
	return (1);
}

void	mv_rotate_rev_a(t_stacks *lsts)
{
	rev_rotate(lsts->a, 'a');
}

void	mv_rotate_rev_b(t_stacks *lsts)
{
	rev_rotate(lsts->b, 'b');
}

void	mv_rotate_rev_both(t_stacks *lsts)
{
	int	rot_a;
	int	rot_b;

	rot_a = rev_rotate(lsts->a, '\0');
	rot_b = rev_rotate(lsts->b, '\0');
	if(rot_a && rot_b)
		mv_h_print("rr", 'r');
	else
	{
		if (rot_a)
			mv_h_print("rr", 'a');
		else
			mv_h_print("rr", 'b');
		print_f("Rotating both when you shouldn't\n");
	}
}
