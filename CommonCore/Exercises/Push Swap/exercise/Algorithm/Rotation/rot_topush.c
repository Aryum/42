/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_topush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:39:14 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/13 18:43:25 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rot.h"

void rot_toPush(t_data data, t_rot rot_info)
{
	if (rot_info.lst->content.index == rot_info.tar_index)
		rot_info.push(data);
	else
	{
		rot_info.rotate(data);
		rot_toPush(data, rot_info);
	}
}
