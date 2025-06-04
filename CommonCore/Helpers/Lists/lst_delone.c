/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:04:09 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/04 17:15:56 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_delone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		(*(*lst).last).next = (*lst).next;
		(*(*lst).next).last = (*lst).last; 
		del((*lst).content);
		free (lst);
	}
}
