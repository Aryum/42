/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:31:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 10:09:12 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTINFO_H
# define ROTINFO_H

#include "../_Headers/alg.h"

typedef struct s_psh
{
	char	tolst;
	void	(*push)(t_data);
} t_psh;

typedef struct s_rtp
{
	void	(*rotate)(t_data);
	t_psh	psh_info;
	int		tar_idx;
	int		cost;
} t_rtp;

t_psh rtp_psh_info(char c, void (*func)(t_data));

t_rtp	*rtp_create_all(t_data data, t_psh p_info, int nbr, int (*func)(int, int));

t_rtp rtp_create(t_data data, t_psh p_info, int tar_idx);

void	rtp_push_single(t_data data, t_psh p_info, t_rtp rot, int print);

int		rtp_push_multiple(t_data data, t_psh p_info, int nbr, int (*func)(int, int));

void	rtp_sort(t_rtp *tab);

t_list	*rtp_get_lst(t_data data, char pushto);

void	rtp_setrot(t_data data, t_rtp *rtp);

#endif