/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_h_try_add_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:28:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/13 14:58:31 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psr.h"

int	psr_h_try_add_number(t_stack *stack, int nbr)
{
	t_list	*current;
	t_nbr	new;

	current = stack->lst;
	stack->size = 0;
	new.index = -1;
	new.value = nbr;
	while (current != NULL)
	{
		if ((current->content).value == nbr)
			return (lst_clear(&stack->lst), 0);
		stack->size++;
		current = current->next;
	}
	lst_add_back(&stack->lst, new);
	return (1);
}
