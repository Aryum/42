/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:35:16 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/23 17:14:34 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	temp;

	if (lst != NULL && f != NULL)
	{
		temp = *lst;
		while (temp.next != NULL)
		{
			f(temp.content);
			temp = *(temp.next);
		}
		f(temp.content);
	}
}
