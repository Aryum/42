/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_rest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:22:17 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/25 15:58:05 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srt.h"

static int	inchunk(int tar, int index)
{
	return (index <= tar);
}

static void divide (t_data *data)
{
	int	tar;

	tar = data->chunk_size * 2;
	while (data->a->size > 3)
	{
		if(!rtp_push_multiple(*data, a, tar, inchunk))
			break;
		update_chunk(data, data->chunk.max + 1);
		tar = data->chunk.max;
	}
}

static void pushback(t_data *data, t_rtp *arr)
{
	int	max;
	int	min;
	int	sucess;

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
		sucess = rtp_push_arr(*data,arr);
	else
		sucess = rtp_push_single(*data, arr[0]);
	if (sucess && data->b->size > 0)
		pushback(data, arr);
	else
		free(arr);
}

void srt_rest(t_data *data)
{
	divide(data);
	srt_three(*data, a);
	pushback(data, NULL);
}
