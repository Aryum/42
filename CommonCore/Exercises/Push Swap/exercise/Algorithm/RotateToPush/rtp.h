/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:31:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/20 12:55:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTINFO_H
# define ROTINFO_H

#include "../_Headers/alg.h"


typedef struct s_rtp
{
	void	(*rotate)(t_data);
	void	(*push)(t_data);
	t_id 	tar_id;
	int		tar_idx;
	int		cost;
} t_rtp;

void	rtp_updaterot(t_data data, t_rtp *rtp);

t_rtp	*rtp_create_all(t_data data, t_id id, int nbr, int (*func)(int, int));

t_rtp rtp_create(t_data data,  t_id id, int tar_idx);

void	rtp_push_single(t_data data, t_rtp rot, int print);

int		rtp_push_multiple(t_data data,  t_id id, int nbr, int (*func)(int, int));

void	rtp_sort(t_rtp *tab);

#endif