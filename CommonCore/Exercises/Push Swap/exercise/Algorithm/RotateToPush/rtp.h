/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:31:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/20 17:27:03 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTINFO_H
# define ROTINFO_H

#include "../_Headers/alg.h"

typedef struct s_rtp
{
	void	(*push)(t_data);
	void	(*rotate)(t_data);
	t_id	from;
	int		tar_idx;
	int		cost;
} t_rtp;

void	rtp_updaterot(t_data data, t_rtp *rtp);

t_rtp	*rtp_create_all(t_data data, t_id push, int nbr, int (*func)(int, int));

t_rtp rtp_create(t_data data,  t_id push, int tar_idx);

void	rtp_push_single(t_data data, t_rtp rot, int print);

int		rtp_push_multiple(t_data data, t_id push, int nbr, int (*func)(int, int));

void	rtp_sort(t_rtp *tab);

#endif