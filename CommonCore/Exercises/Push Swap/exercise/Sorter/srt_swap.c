/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:15:22 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/10 13:12:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/srt.h"

static void swap_top(t_list *lst, char *str)
{
	int	temp;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	if (str != NULL)
		srt_h_print(str);
}

void	srt_swap_a(t_list *lst_a)
{
	swap_top(lst_a, "sa");
}

void	srt_swap_b(t_list *lst_b)
{
	swap_top(lst_b, "sb");
}

void	srt_swap_ss(t_list *lst_a, t_list *lst_b)
{
	swap_top(lst_a, NULL);
	swap_top(lst_b, NULL);
	print_f("ss\n");
}