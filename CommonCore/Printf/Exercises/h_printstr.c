/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_printstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:31:14 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/29 12:37:51 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prtf.h"

void	h_print_str(char *str, int *counter)
{
	int	i;

	i = 0;
	if(str != NULL)
	{
		while(str[i] != NULL)
		{
			write(1,&str[i],1);
			(*counter)++;
		}
	}
}