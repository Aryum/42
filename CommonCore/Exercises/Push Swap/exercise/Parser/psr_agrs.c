/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_agrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:35:36 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 10:30:16 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psr.h"

int	psr_agrs(t_list **lst, int argc, char **argv)
{
	int		i;
	int		h;
	long	current;
	char 	**nbr_str;
	
	i = 0;
	current = 0;
	while (i < argc)
	{
		h = 0;
		nbr_str = lib_split(argv[i], ' ');
		while (nbr_str[h] != NULL)
		{
			if (psr_try_get_number(argv[i], &current))
			{
				if(!psr_try_add_number(lst,current))
					return (0);
			}
			h++;
		}
		i++;
	}
	return (1);
}
