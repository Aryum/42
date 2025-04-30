/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_printstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:31:14 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/30 12:20:00 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

void	h_print_str(char *str, int *counter)
{
	size_t	i;

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