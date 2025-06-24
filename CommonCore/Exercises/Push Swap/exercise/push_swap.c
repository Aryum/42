/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/24 11:36:04 by ricsanto         ###   ########.fr       */
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


int	is2ndpart(int tar, int index)
{
	return  index <= tar;
}

//with 2 divs it breaks
void divide (t_data *data)
{
	int	tar = data->chunk_size * 2;
	print_f("Div size %d\n", data->chunk_size);	
	while (data->a->size > 3)
	{
		if(!rtp_push_multiple(*data, a, tar, is2ndpart) || data->a->size == 3)
			break;
		dbg_print_stack(*data);
		update_chunk(data, data->chunk.max + 1);
		tar = data->chunk.max;
	}
	srt_three(*data, a);
}


void pushback(t_data *data, t_rtp *arr)
{
	int	max;
	int	min;

	max = data->a->min - 1;
	min = data->a->min - 2;
	if (arr == NULL)
	{
		arr = malloc(sizeof(t_rtp) * 3);
		arr[2] = rtp_create(*data, b, -1);
	}
	arr[0] = rtp_create(*data, b, max);
	arr[1] = rtp_create(*data, b, min);
	rtp_sort(arr);
	if (min == arr[0].tar_idx)
	{
		rtp_push_single(*data, arr[0], 0);
		rtp_push_single(*data, arr[1], 0);
		mv_swap_a(*data);
	}
	else
		rtp_push_single(*data, arr[0], 0);
	if (data->b->size > 0)
		pushback(data, arr);
}
/*
	do an array with 2 elements
	when one is pushed search next one


*/
int	main(int argc, char **argv)
{
	t_data data;
	data = data_ini();
	if (psr_agrs(&data, argc, argv))
	{
		dbg_print_stack(data);
		//start_debug(data.a->lst);
		if (!is_sorted(*data.a))
		{
			if(is_rev_sorted(*data.a))
			{
				while (data.a->size > 3)
					mv_pushfrom_a(data);
				srt_three(data, a);
				//dbg_print_stack(data);
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
				update_data(&data, 6);
				divide(&data);
				pushback(&data, NULL);
			}
		}
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
