/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_count_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:34:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/03 12:23:30 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int isarg(char c)
{
	char	*args;
	int		i;

	i = 0;
	args = "cspdiuxX%";
	while (args[i] != '\0')
	{
		if(c == args[i])
			return (1);
	}
	return (0);
}

int h_count_args(const char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '%' && isarg(str[i + 1]))
		{
			counter++;
			i++;
		}
		else
			return (-1);
		i++;
	}
	return (counter);
}