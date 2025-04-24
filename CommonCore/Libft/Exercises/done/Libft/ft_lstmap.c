/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:39:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/24 17:27:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*current;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ret = NULL;
	while (lst != NULL)
	{
		current = ft_lstnew(f((*lst).content));
		if (current != NULL)
			ft_lstadd_back(&ret, current);
		else
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		lst = ((*lst).next);
	}
	return (ret);
}
