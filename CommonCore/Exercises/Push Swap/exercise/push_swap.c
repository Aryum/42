/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/19 15:48:10 by ricsanto         ###   ########.fr       */
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


int	is2ndpart(int middle, int index)
{
	return  index <= middle;
}


int	main(int argc, char **argv)
{
	t_data data;
	data = data_ini();
	if (psr_agrs(&data, argc, argv))
	{
		//t_psh push_b = rtp_psh_info('b', mv_pushto_b);
		start_debug(data.a->lst);
		
		if (data.total_size == 3)
			srt_three(data, a);
		else
			print_f("More than 3 args");
		//rtp_push_multiple(data, push_b, data.total_size / 2, is2ndpart);
		dbg_print_stack(data);
	}
	data_clear(data);
	
	//t_psh push_a = rtp_psh_info('a', mv_pushto_a);
	
	


	/*
	srt_push_b(&stacks);
	printlists(stacks, "Push b");

	srt_push_a(&stacks);
	printlists(stacks, "Push b");

	srt_rotate_rev_a(&stacks);
	printlists(stacks, "rev rotate a");
	
	srt_rotate_a(&stacks);
	printlists(stacks, "rotate a");
	
	srt_swap_a(&stacks);
	printlists(stacks, "Swap a");
	*/
}
