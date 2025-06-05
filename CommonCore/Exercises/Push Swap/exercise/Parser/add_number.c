/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:28:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/05 11:57:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Helpers/Lst/lst.h"

int try_add_number(t_list *lst, int nbr)
{
	while(lst != NULL)
	{
		if(*(int *)(lst->content) == nbr)
			return (0);
		lst = lst->next;
	}
	lst_add_back(&lst,lst_new(&nbr));
}