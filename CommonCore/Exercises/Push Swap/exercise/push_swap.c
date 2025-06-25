/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/25 15:35:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_nbr *i)
{
	print_f("%d index	%d\n",i->index,i->nbr);
}

void printContent(t_list *lst)
{
	if(lst != NULL)
		print_f("%d", lst->val.index);
}

void	start_debug(t_list *lst)
{
	print_f("DEBUG STARTING LIST\n");
	print_f("____________________________\n");
	while(lst != NULL)
	{
		print_f("index %d nbr %d\n", lst->val.index,lst->val.nbr);
		lst = lst->next;
	}
	print_f("____________________________\n\n");
}


int	main(int argc, char **argv)
{
	t_data data;
	int div;

	div = 0;
	data = data_ini();

	if (psr_agrs(&data, argc, argv))
	{
		if (!is_sorted(*data.a))
		{
			if(data.a->size == 2)
			{
				if (next_lower(data.a->lst))
					mv_swap_a(data);
			}
			else if(is_rev_sorted(*data.a))
			{
				while (data.a->size > 3)
					mv_pushfrom_a(data);
				srt_three(data, a);
				while(data.b->size > 0)
				{
					mv_rotate_rev_b(data);
					mv_pushfrom_b(data);
				}
				while (data.a->min != data.a->lst->val.index)
					mv_rotate_rev_a(data);
			}
			else
			{
				if (data.total_size == 3)
					srt_three(data, a);
				else
				{
					if (data.total_size < 100)
						div = 4 + (data.total_size > 10) * 2 + (data.total_size > 50) * 2;
					else
						div = 8 + ((data.total_size / 100) - (data.total_size % 100 == 0)) * 2;
					update_data(&data, div);
					divide(&data);
					pushback(&data, NULL);
				}
			}
		}
	}
	if(!is_sorted(*data.a))
		dbg_print_stack(data);
	data_clear(data);
	
}
