/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:24:15 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:17 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srt.h"

static int rotate(t_list *lst, char c)
{
	t_list	*lst_tmp;	
	t_nbr	nbr_tmp;

	if (lst == NULL)
		return (0);
	lst_tmp = lst;
	nbr_tmp = lst->content;
	while (lst_tmp->next != NULL)
	{
		lst_tmp->content = lst_tmp->next->content;
		lst_tmp = lst_tmp->next;
	}
	lst_tmp->content = nbr_tmp;
	srt_h_print("r", c);
	return (1);
}

void	srt_rotate_a(t_stacks *lsts)
{
	rotate(lsts->a, 'a');
}

void	srt_rotate_b(t_stacks *lsts)
{
	rotate(lsts->b, 'b');
}

void	srt_rotate_both(t_stacks *lsts)
{
	int	rot_a;
	int	rot_b;

	rot_a = rotate(lsts->a, '\0');
	rot_b = rotate(lsts->b, '\0');
	if(rot_a && rot_b)
		srt_h_print("r", 'r');
	else
	{
		if (rot_a)
			srt_h_print("r", 'a');
		else
			srt_h_print("r", 'b');
		print_f("Rotating both when you shouldn't\n");
	}
}
