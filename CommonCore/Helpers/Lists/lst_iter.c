/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:35:16 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/04 17:15:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_iter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL && f != NULL)
	{
		while (lst != NULL)
		{
			f((*lst).content);
			lst = (*lst).next;
		}
	}
}
