/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:10:55 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/21 16:00:09 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear(t_list **current, t_list **start, void (*del)(void*))
{
	if ((**current).next != NULL)
		clear(&((**current).next), start, del);
	ft_lstdelone(*current, del);
	if (current == start)
		free(start);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
		clear(lst, lst, del);
}
