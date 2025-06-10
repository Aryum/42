/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:20:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/10 13:27:53 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/srt.h"

static void rev_rotate(t_list *lst, char *str)
{
	t_list *lst_tmp;	
	int	nbr_tmp;
	
	lst_tmp = lst;
	nbr_tmp = lst->content;
	while (lst_tmp->next != NULL)
	{
		lst_tmp->next->content = lst_tmp->content;
		lst_tmp = lst_tmp->next;
	}
	lst_tmp->content = nbr_tmp;
	if (str != NULL)
		srt_h_print(str);
}

void	srt_rev_rotate_a(t_list *lst_a)
{
	rev_rotate(lst_a, "rra");
}

void	srt_rev_rotate_b(t_list *lst_b)
{
	rev_rotate(lst_b, "rra");
}

void	srt_rotate_rr(t_list *lst_a, t_list *lst_b)
{
	rev_rotate(lst_a, NULL);
	rev_rotate(lst_b, NULL);
	srt_h_print("rrr");
}