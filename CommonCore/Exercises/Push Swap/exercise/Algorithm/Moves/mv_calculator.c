/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_calculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:12:29 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 17:37:34 by ricsanto         ###   ########.fr       */
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
		if (tar_index == lst->val.index)
		{
			if (stack.size - counter > counter)
				return (counter);
			else
				return (-(stack.size - counter));
		}
		counter++;
		lst = lst->next;
	}
	print_f("%d Tar index not found on the stack %c\n", tar_index, stack.id);
	return (0);
}
