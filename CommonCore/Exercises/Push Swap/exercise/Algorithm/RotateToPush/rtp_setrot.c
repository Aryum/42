/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_setrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:44:33 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 16:16:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

void rtp_setrot(t_stack_data data, t_rtp *rtp)
{
	if (rtp->psh_info.tolst == 'a')
	{
		rtp->cost = mv_calculate_push(*data.b, rtp->tar_idx);
		if (rtp->cost >= 0)
			rtp->rotate = mv_rotate_b;
		else
			rtp->rotate = mv_rotate_rev_b;
	}
	else if (rtp->psh_info.tolst == 'b')
	{
		rtp->cost = mv_calculate_push(*data.a, rtp->tar_idx);
		if (rtp->cost >= 0)
			rtp->rotate = mv_rotate_a;
		else
			rtp->rotate = mv_rotate_rev_a;
	}
}
