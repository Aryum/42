/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtp_getlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:59:37 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/18 16:16:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtp.h"

t_list *rtp_get_lst(t_stack_data data, char pushto)
{
	if (pushto == 'a')
		return (data.b->lst);
	if (pushto == 'b')
		return (data.a->lst);
	print_f("GET LIST-> wrong char passed\n");
	return (NULL);
}