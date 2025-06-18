/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 09:34:10 by ricsanto         ###   ########.fr       */
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


t_stack *ini_stack(char c)
{
	t_stack *ret;

	ret = malloc(sizeof(t_stack));
	ret->lst = NULL;
	ret->size = 0;
	ret->id = c;
	ret->mid = 0;

	return ret;
}

void freeMem(t_data stacks)
{
	lst_clear(&(stacks.a->lst));
	lst_clear(&(stacks.b->lst));
	free(stacks.a);
	free(stacks.b);
}

int	is2ndpart(int middle, int index)
{
	return  index <= middle;
}


int	main(int argc, char **argv)
{
	t_data data;
	//t_psh push_a = rtp_psh_info('a', mv_pushto_a);
	t_psh push_b = rtp_psh_info('b', mv_pushto_b);
	data.a = ini_stack('a'); 
	data.b = ini_stack('b');
	psr_agrs(data.a, argc, argv);
	data.total_size = data.a->size;
	start_debug(data.a->lst);
	int halfsize = data.total_size / 2;
	data.a->mid = halfsize + halfsize / 2;
	data.b->mid = halfsize - halfsize / 2;
	
	rtp_push_multiple(data, push_b, halfsize, is2ndpart);
	dbg_print_stack(data);
	


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
	freeMem(data);
}
