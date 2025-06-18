/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:24:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 15:36:03 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg.h"

static void printContent(t_list *lst)
{
	if(lst != NULL)
		print_f("%d", lst->val.index);
}

void	dbg_print_stack(t_data data)
{
	t_list *a = data.a->lst;
	t_list *b = data.b->lst;

	print_f("\n\nA	|	B\n");
	print_f("____________________________\n");
	while (a != NULL || b != NULL)
	{
		printContent(a);
		print_f("	|	");
		printContent(b);
		print_f("\n");
		if(a != NULL)
			a = a->next;
		if(b != NULL)
			b = b->next;
	}
	print_f("____________________________\n");
	print_f(" %d	|	%d Total\n", data.a->size,data.b->size);
	print_f("____________________________\n\n");
}