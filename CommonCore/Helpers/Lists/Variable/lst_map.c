/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:39:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 12:08:57 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*lst_map(t_list *lst, void *(*f)(void *))
{
	t_list	*ret;
	t_list	*cur_node;
	void	*cur_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = NULL;
	while (lst != NULL)
	{
		cur_content = f((*lst).content);
		cur_node = lst_new(cur_content);
		if (cur_node == NULL)
		{
			lst_clear(&ret);
			break ;
		}
		lst_add_back(&ret, cur_node);
		lst = ((*lst).next);
	}
	return (ret);
}
