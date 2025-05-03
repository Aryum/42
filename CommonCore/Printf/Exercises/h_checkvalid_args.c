/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_count_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:34:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/05/03 15:56:37 by ricsanto         ###   ########.fr       */
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

int h_checkvalid_agrs(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '%')
		{
			if(!isarg(str[i + 1]))
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}