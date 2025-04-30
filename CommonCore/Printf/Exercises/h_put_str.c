/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_put_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:09:25 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/30 13:20:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

void	h_put_str(char *str, int *counter)
{
	int	i;

	i = 0;
	if(str != NULL)
	{
		while(str[i] != '\0')
		{
			h_put_char(str[i], counter);
			i++;
		}
	}
}