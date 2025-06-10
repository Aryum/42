/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:24:15 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/10 13:18:54 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/srt.h"

static void rotate(t_list *lst, char *str)
{
	t_list *lst_tmp;	
	int	nbr_tmp;
	
	lst_tmp = lst;
	while (lst_tmp->next != NULL)
	{
		nbr_tmp = lst_tmp->content;
		lst_tmp->content = lst_tmp->next->content;
		lst_tmp = lst_tmp->next;
	}
	lst->content = nbr_tmp;
	if (str != NULL)
		srt_h_print(str);
}

void	srt_rotate_a(t_list *lst_a)
{
	rotate(lst_a, "ra");
}

void	srt_rotate_b(t_list *lst_b)
{
	rotate(lst_b, "ra");
}

void	srt_rotate_rr(t_list *lst_a, t_list *lst_b)
{
	rotate(lst_a, NULL);
	rotate(lst_b, NULL);
	srt_h_print("rr");
}