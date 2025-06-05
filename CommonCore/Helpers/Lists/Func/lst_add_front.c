/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:30:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 11:07:54 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_add_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		(*new).next = (*lst);
		(**lst).last = new; 
		*lst = new;
	}
}
