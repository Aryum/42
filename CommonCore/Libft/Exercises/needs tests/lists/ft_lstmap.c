/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:39:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/23 18:14:26 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int addnew(t_list **lst, t_list temp,void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;

	current = ft_lstnew(f((temp).content));
	if (current != NULL)
	{
		ft_lstadd_back(lst, current);
		return (1);
	}
	else
	{
		ft_lstclear(lst, del);
		return (0);
	}
}
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ret = ft_lstnew(f((*lst).content));
	if (ret != NULL)
	{
		temp = (*lst).next;
		while ((*temp).next != NULL)
		{
			if(!addnew(&ret,*temp,f,del))
				return (NULL);
			temp = ((*temp).next);
		}
		if(!addnew(&ret,*temp,f,del))
			return (NULL);
	}
	return (ret);
}
