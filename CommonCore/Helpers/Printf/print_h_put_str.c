/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_h_put_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:09:25 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 11:53:07 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	print_str(char *str, int *counter)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		print_h_put_char(str[i], counter);
		i++;
	}
}

void	print_h_put_str(char *str, int *counter)
{
	if (str != NULL)
		print_str(str, counter);
	else
		print_str("(null)", counter);
}
