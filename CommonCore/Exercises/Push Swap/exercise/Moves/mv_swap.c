/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:15:22 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:23 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mv.h"

static int swap_top(t_list *lst, char c)
{
	t_nbr	temp;

	if (lst == NULL || lst->next == NULL)
		return (print_f("List %c is empty or just has 1 item"), 0);
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	mv_h_print("s", c);
	return (1);
}

void	mv_swap_a(t_stacks *lsts)
{
	swap_top(lsts->a, 'a');
}

void	mv_swap_b(t_stacks *lsts)
{
	swap_top(lsts->b, 'b');
}

void	mv_swap_both(t_stacks *lsts)
{
	int	swap_a;
	int	swap_b;

	swap_a = swap_top(lsts->a, '\0');
	swap_b = swap_top(lsts->b, '\0');
	if(swap_a && swap_b)
		mv_h_print("s", 's');
	else
	{
		if (swap_a)
			mv_h_print("s", 'a');
		else
			mv_h_print("s", 'b');
		print_f("Swaping both when you shouldn't\n");
	}
}
