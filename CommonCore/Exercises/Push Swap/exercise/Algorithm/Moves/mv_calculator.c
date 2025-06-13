/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_calculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:12:29 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/13 17:03:21 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mv.h"

int	mv_calculate_push(t_stack stack, int tar_index)
{
	t_list	*lst;
	int		counter;

	counter = 0;
	lst = stack.lst;
	while(lst != NULL)
	{
		if (tar_index == lst->content.index)
		{
			if (stack.size + 1 - counter > counter)
				return (1);
			else
				return (0);
		}
		counter++;
		lst = lst->next;
	}
	print_f("Tar index not found on the stack\n");
	return (-1);
}
