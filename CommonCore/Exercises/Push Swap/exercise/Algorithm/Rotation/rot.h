/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:31:24 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/16 20:57:16 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTINFO_H
# define ROTINFO_H

#include "../Headers/alg.h"

typedef struct s_rot
{
	t_list	*lst;
	void	(*push)(t_data);
	void	(*rotate)(t_data);
	int		tar_index;
	int		cost;
} t_rot;

t_rot	rot_create(t_data data, char pushto, int tar_index);

t_rot	*rot_getrot(t_data data, char pushto, int nbr, int (*func)(int, int));

void	rot_sort(t_rot *tab, int size);

#endif