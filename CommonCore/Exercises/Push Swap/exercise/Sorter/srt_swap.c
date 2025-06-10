/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:15:22 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/10 17:17:40 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/srt.h"

static int swap_top(t_list *lst, char c)
{
	int	temp;

	if (lst == NULL || lst->next == NULL)
		return (print_f("List %c is empty or just has 1 item"), 0);
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	srt_h_print("s", c);
	return (1);
}

void	srt_swap_a(t_stacks *lsts)
{
	swap_top(lsts->a, 'a');
}

void	srt_swap_b(t_stacks *lsts)
{
	swap_top(lsts->b, 'b');
}

void	srt_swap_both(t_stacks *lsts)
{

	int	swap_a;
	int	swap_b;

	swap_a = swap_top(lsts->a, '\0');
	swap_b = swap_top(lsts->b, '\0');
	if(swap_a && swap_b)
		srt_h_print("s", 's');
	else
	{
		if (swap_a)
			srt_h_print("s", 'a');
		else
			srt_h_print("s", 'b');
		print_f("Swaping both when you shouldn't\n");
	}
}
