/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:10:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/24 15:51:28 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear(t_list **current, void (*del)(void*))
{
	if ((**current).next != NULL)
		clear(&((**current).next), del);
	ft_lstdelone(*current, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		if(*lst != NULL)
			clear(lst, del);
		*lst = NULL;
	}
}
