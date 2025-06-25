/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/25 12:17:53 by ricsanto         ###   ########.fr       */
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
	while (data->a->size > 3)
	{
		if(!rtp_push_multiple(*data, a, tar, is2ndpart) )
			break;
		update_chunk(data, data->chunk.max + 1);
		tar = data->chunk.max;
	}
	srt_three(*data, a);
}

/*
	store next on data
	if its better to do both then do it or swap both if needeed
	check the division count
*/
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
		rtp_push_single(*data, arr[0]);
		rtp_push_single(*data, arr[1]);
	}
	else
		rtp_push_single(*data, arr[0]);
	if (data->b->size > 0)
		pushback(data, arr);
	else
		free(arr);
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
