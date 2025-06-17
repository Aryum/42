/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:31:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/17 17:00:23 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTINFO_H
# define ROTINFO_H

#include "../_Headers/alg.h"

typedef struct s_psh
{
	char	tolst;
	void	(*on_push)(t_data);
} t_psh;

typedef struct s_rtp
{
	void	(*on_end)(t_data);
	void	(*push)(t_data);
	void	(*rotate)(t_data);
	int		tar_index;
	int		cost;
} t_rtp;

t_rtp	rtp_create(t_data data, char pushto, int tar_index);

t_rtp	*rtp_create_all(t_data data, char pushto, int nbr, int (*func)(int, int));

void	rtp_push_single(t_data data, char pushto, t_rtp rot, int print);

int		rtp_push_multiple(t_data data, char pushto, int nbr, int (*func)(int, int));

void	rtp_sort(t_rtp *tab, int size);

t_list	*rtp_get_lst(t_data data, char pushto);

#endif