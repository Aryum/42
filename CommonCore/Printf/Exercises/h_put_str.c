/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_put_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:09:25 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/04 13:05:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_str (char *str, int *counter)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		h_put_char(str[i], counter);
		i++;
	}
}
void	h_put_str(char *str, int *counter)
{
	if(str != NULL)
		print_str(str, counter);
	else
		print_str("(null)", counter);
}