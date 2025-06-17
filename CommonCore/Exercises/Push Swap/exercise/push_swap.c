/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 20:46:11 by ricsanto         ###   ########.fr       */
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

void	debug(t_list *lst)
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




void	printlists(t_data stacks)
{
	t_list *a = stacks.a->lst;
	t_list *b = stacks.b->lst;

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
	print_f("%d	|	%d\n", stacks.a->size,stacks.b->size);
	print_f("____________________________\n\n");

}

t_stack *ini_stack(char c)
{
	t_stack *ret;

	ret = malloc(sizeof(t_stack));
	ret->lst = NULL;
	ret->size = 0;
	ret->id = c;
	return ret;
}

void freeMem(t_data stacks)
{
	lst_clear(&(stacks.a->lst));
	lst_clear(&(stacks.b->lst));
	free(stacks.a);
	free(stacks.b);
}



void test_calc(t_data stacks, int tar)
{
	int result = mv_calculate_push(*stacks.a, tar);
	if(result == 1)
		print_f("tar %d ->Easier to normal rotate\n", tar);
	else if (result == 0)
		print_f("tar %d ->Easier to rev rotate\n", tar);
	print_f("\n");
}

int belongs_to2nd(t_list *lst,t_data data)
{
	return (lst->val.index >= data.total_size);
}


int checkbigger(t_list *lst)
{
	return lst->val.index > lst->next->val.index; 
}



void dividestacks(t_data stacks)
{
	int		to_push;
	t_rot	rot;
	
	to_push = 0;
	//to_push = chk_stackindex(stacks);
	printlists(stacks);
	if (to_push)
	{
		rot = rot_create(stacks,'b', to_push);
		rot_push(stacks,rot);
		dividestacks(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_data stacks;

	stacks.a = ini_stack('a'); 
	stacks.b = ini_stack('b');
	psr_agrs(stacks.a, argc, argv);
	stacks.total_size = stacks.a->size;
	debug(stacks.a->lst);

	dividestacks(stacks);
	printlists(stacks);
	
	/*
	t_rot rot = rot_create(stacks,'b', lst_last(stacks.a->lst)->val.index);
	rot_toPush(stacks,rot);
	*/


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
	freeMem(stacks);
}
