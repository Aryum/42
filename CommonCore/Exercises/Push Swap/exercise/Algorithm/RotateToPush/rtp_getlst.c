/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_getlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:59:37 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/19 12:15:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

t_list *rtp_get_lst(t_data data, char pushto)
{
	if (pushto == 'a')
		return (data.b->lst);
	if (pushto == 'b')
		return (data.a->lst);
	print_f("GET LIST-> wrong char passed\n");
	return (NULL);
}