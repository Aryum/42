/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:34:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/10 13:12:20 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/srt.h"

static void push_first(t_list **lst_add, t_list **lst_take, char *str)
{
	if (lst_take == NULL || *lst_take == NULL)
		return ;
	lst_add_front(lst_add, (*lst_take)->content);
	lst_delone(lst_take, *lst_take);
	srt_h_print(str);
}

void srt_push_a(t_list **lst_a, t_list **lst_b)
{
	push_first(lst_a, lst_b, "pa");
}

void srt_push_a(t_list **lst_b, t_list **lst_a)
{
	push_first(lst_b, lst_a, "pb");
}