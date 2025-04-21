/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:39:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/21 15:34:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*ret;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ret = ft_lstnew((*lst).content);
	if (ret != NULL)
	{
		temp = lst;
		while ((*temp).next != NULL)
		{
			current = ft_lstnew(f((*temp).content));
			if (current != NULL)
				ft_lstadd_back(&ret, current);
			else
			{
				ft_lstclear(&ret, del);
				return (NULL);
			}
			temp = ((*temp).next);
		}
	}
	return (ret);
}
