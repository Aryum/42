/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/13 18:39:30 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_nbr *i)
{
	print_f("%d index	%d\n",i->index,i->value);
}

void printContent(t_list *lst)
{
	if(lst != NULL)
		print_f("%d", lst->content.index);
}

void	debug(t_list *lst)
{
	print_f("DEBUG STARTING LIST\n");
	print_f("____________________________\n");
	while(lst != NULL)
	{
		print_f("index %d nbr %d\n", lst->content.index,lst->content.value);
		lst = lst->next;
	}
	print_f("____________________________\n\n");
}
void	printlists(t_data stacks)
{
	t_list *a = stacks.a->lst;
	t_list *b = stacks.b->lst;

	print_f("A	|	B\n");
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
}

t_stack *ini_stack()
{
	t_stack *ret;
	ret = malloc(sizeof(t_stack));
	ret->lst = NULL;
	ret->size = 0;

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
	return (lst->content.index >= data.total_size);
}

int	is_div(t_data stacks)
{
	t_list	*temp;
	
	temp = stacks.a;
	while (temp != NULL)
	{
		if ( belongs_to2nd(temp, stacks) )
			return 0;
		temp = temp->next;
	}
	return 1;
}

t_list *get_lst(char c, t_data data)
{
	if(c = 'a')
		return (data.a);
	else if (c = 'b')
		return (data.b);
	print_f("Wtf u doing\n");
	return (NULL);
}




int rec(t_data stacks)
{
	t_list	*lst;

	lst = stacks.a;
	if(!is_div(stacks))
	{
		while (lst != NULL)
		{
			if (belongs_to2nd(lst,stacks))
			lst = lst->next;
		}
	}
}


int	main(int argc, char **argv)
{
	t_data stacks;

	stacks.a = ini_stack(); 
	stacks.b = ini_stack();
	psr_agrs(stacks.a, argc, argv);
	stacks.total_size = stacks.a->size;
	debug(stacks.a->lst);
	test_calc(stacks, 2);

	while (!is_div(stacks))
	{
		
	}
	//printlists(stacks);
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
