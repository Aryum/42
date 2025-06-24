/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:31:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/24 17:13:59 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTINFO_H
# define ROTINFO_H

#include "../_Headers/alg.h"

typedef struct s_rtp
{
	int		(*push)(t_data);
	void	(*rotate)(t_data);
	t_id	from;
	t_dir	type;
	int		tar_idx;
	int		cost;
} t_rtp;

void	rtp_updaterot(t_data data, t_rtp *rtp);

t_rtp	*rtp_create_all(t_data data, t_id push, int nbr, int (*func)(int, int));

t_rtp	rtp_create(t_data data,  t_id push, int tar_idx);

int		rtp_push_single(t_data data, t_rtp rot);

int		rtp_push_multiple(t_data data, t_id push, int nbr, int (*func)(int, int));

void	rtp_sort(t_rtp *tab);

#endif